/*
** EPITECH PROJECT, 2023
** Scene
** File description:
** Scene
*/

#ifndef Scene_HPP
    #define Scene_HPP

#include <vector>
#include <memory>
#include "interface/IObject.hpp"

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
        bool hit_global(const Ray& r, double t_min, double t_max, Shape::hit_record& rec) {
            Shape::hit_record temp_rec;
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
        void add_sphere(Shape::Sphere new_object)
        {
            object_list.push_back(std::make_shared<Shape::Sphere>(new_object));
        }
        void add_triangle(Shape::Triangle3D new_object)
        {
            object_list.push_back(std::make_shared<Shape::Triangle3D>(new_object));
        }
        void add_cone(Shape::Cone new_object)
        {
            object_list.push_back(std::make_shared<Shape::Cone>(new_object));
        }
        std::vector<std::shared_ptr<IObject>> object_list;

    protected:
    private:
};

#endif /* !Scene */
