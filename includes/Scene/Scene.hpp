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
#include"Objects/Shapes/Sphere.hpp"
#include "Objects/Shapes/hit_record.hpp"
#include "Camera/Camera.hpp"
#include <map>

class Scene {
    public:
        Scene() {};
        ~Scene() {};
        bool hit_global(const Ray& r, double t_min, double t_max, hit_record& rec) {
            hit_record temp_rec;
            bool hit_anything = false;
            double temp_t_max = t_max;

            for (const std::shared_ptr<IObject>& object : object_list) {
                if (object->hits(r, t_min, temp_t_max, temp_rec)) {
                    hit_anything = true;
                    temp_t_max = temp_rec.t;
                    rec = temp_rec;
                }
            }

            return hit_anything;
        }
        std::map<const std::string, std::shared_ptr<Material>> material_list;
        std::vector<std::shared_ptr<IObject>> object_list;
        Camera cam;

    protected:
    private:
};

