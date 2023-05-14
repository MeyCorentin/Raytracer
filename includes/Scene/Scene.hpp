/*
** EPITECH PROJECT, 2023
** Scene
** File description:
** Scene
*/


#pragma once

#include <vector>
#include <memory>
#include "interface/IObject.hpp"
#include "interface/ILight.hpp"
#include "Objects/Shapes/Sphere.hpp"
#include "Objects/Shapes/hit_record.hpp"
#include <map>
#include "Camera/Camera.hpp"
#include "interface/IObjectDecorator.hpp"

class Scene {
    public:
        Scene() {};
        ~Scene() {};
        bool hit_global(const Ray& r, double t_min, double t_max, hit_record& rec, bool shadow_cast) {
            hit_record temp_rec;
            bool _hit = false;

            for (const std::shared_ptr<IObject>& object : object_list)
            {
                if (object->hits(r, t_min, t_max, temp_rec)) {
                    if (shadow_cast)
                        return true;
                    _hit = true;
                    t_max = temp_rec.t;
                    Math::Point3D temp_color(0, 0, 0);
                    for (const std::shared_ptr<ILight>& light: light_list)
                    {
                        light->computeLight(*this, r, temp_rec, object, object_list);
                        temp_color += temp_rec.light_result;
                    }
                    temp_rec.light_result = temp_color;
                    rec = temp_rec;
                }
            }

            return _hit;
        }
        Camera *getCam()
        {
            return this->cam;
        }
        std::map<const std::string, std::shared_ptr<Material>> material_list;
        std::map<const std::string, Math::Vector3D> decorator_list;
        std::vector<std::shared_ptr<IObject>> object_list;
        std::vector<std::shared_ptr<ILight>> light_list;
        Camera *cam;

    protected:
    private:
};
