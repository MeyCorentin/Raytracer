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
        bool hit_global(const Ray& r, double t_min, double t_max, hit_record& rec) {
            hit_record temp_rec;
            bool hit_anything = false;
            double temp_t_max = t_max;

            for (const auto& object : object_list) {
                if (object->hits(r, t_min, temp_t_max, temp_rec)) {
                    hit_anything = true;
                    temp_t_max = temp_rec.t;
                    rec = temp_rec;
                }
            }

            return hit_anything;
        }
        void add_sphere( Sphere new_object)
        {
            object_list.push_back(std::make_shared< Sphere>(new_object));
        }
        void add_triangle(Triangle3D new_object)
        {
            object_list.push_back(std::make_shared<Triangle3D>(new_object));
        }
        void add_cone(Cone new_object)
        {
            object_list.push_back(std::make_shared<Cone>(new_object));
        }
        std::vector<std::shared_ptr<IObject>> object_list;

    protected:
    private:
};

