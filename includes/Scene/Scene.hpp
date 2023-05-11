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
#include"Objects/Shapes/Sphere.hpp"
#include "Objects/Shapes/hit_record.hpp"

namespace Shape
{
    class Sphere;
    class Triangle3D;
    class Cone;
    // class Plane;
}

class Scene {
    public:
        Scene() {};
        ~Scene() {};
        bool hit_global(const Ray& r, double t_min, double t_max, hit_record& rec, bool shadow_cast) {
            hit_record temp_rec;
            bool hit_anything = false;
            double temp_t_max = t_max;

            for (const std::shared_ptr<IObject>& object : object_list)
            {
                if (object->hits(r, t_min, temp_t_max, temp_rec)) {
                    hit_anything = true;
                    temp_t_max = temp_rec.t;
                    if (shadow_cast)
                        return true;
                    for (const std::shared_ptr<ILight>& light: light_list)
                        light->computeLight(*this, r, temp_rec, object, object_list);
                    rec = temp_rec;
                }
            }

            return hit_anything;
        }
        std::vector<std::shared_ptr<IObject>> object_list;
        std::vector<std::shared_ptr<ILight>> light_list;
        Camera cam;

    protected:
    private:
};

