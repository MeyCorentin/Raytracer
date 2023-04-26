/*
** EPITECH PROJECT, 2023
** Sphere
** File description:
** Sphere
*/

#ifndef Sphere_HPP
    #define Sphere_HPP

#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Ray.hpp"

namespace Raytracer
{
    class hit_record {
        public:
        hit_record() {}
        Math::Point3D p;
        Math::Point3D normal;
        double t;
    };

    class Sphere {
        public:
            Sphere() {};
            Sphere(Math::Point3D *origin, double radius)
            {
                this->origin = origin;
                this->radius = radius;
            };
            ~Sphere() {};
            bool hits(const Ray& r, double t_min, double t_max, hit_record& rec) {
                Math::Point3D sphere_color(0.8, 0.8, 0.0);
                Math::Vector3D oc = Math::Vector3D(r.origin->x_coords, r.origin->y_coords, r.origin->z_coords) - Math::Vector3D(origin->x_coords, origin->y_coords, origin->z_coords);
                double a = dot(r.direction, r.direction);
                double b = 2.0 * dot(oc, r.direction);
                double c = dot(oc, oc) - radius * radius;
                double discriminant = b*b - 4*a*c;

                if (discriminant >= 0) {
                    double t1 = (-b - sqrt(discriminant)) / (2 * a);
                    double t2 = (-b + sqrt(discriminant)) / (2 * a);

                    if (t1 < t_max && t1 > t_min) {
                        rec.t = t1;
                        Math::Point3D intersection_point = r.at(t1);
                        Math::Point3D normal = (intersection_point - origin) / radius;
                        Math::Point3D shading_color = 0.5 * (normal + Math::Vector3D(1,1,1));
                        rec.normal =  sphere_color * shading_color;
                        return true;
                    } else if (t2 < t_max && t2 > t_min) {
                        rec.t = t2;
                        Math::Point3D intersection_point = r.at(t2);
                        Math::Point3D normal = (intersection_point - origin) / radius;
                        Math::Point3D shading_color = 0.5 * (normal + Math::Vector3D(1,1,1));
                        rec.normal =  sphere_color * shading_color;
                        return true;
                    }
                }
                return false;
            }
            Math::Point3D *origin;
            double radius;

        protected:
        private:
    };
}

#endif /* !Sphere */
