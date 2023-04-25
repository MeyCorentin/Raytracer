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
    class Sphere {
        public:
            Sphere() {};
            Sphere(Math::Point3D *origin, double radius)
            {
                this->origin = origin;
                this->radius = radius;
            };
            ~Sphere() {};
            bool hits(const Ray *_ray) {
                Math::Point3D oc = *(_ray->origin) - *(this->origin);
                double a = _ray->direction->dot_v(_ray->direction);
                double b = 2.0 * oc.dot_v(_ray->direction);
                double c = oc.dot_p(&oc) - pow(this->radius, 2);
                double discriminant = pow(b, 2) - (4 * a * c);
                if (discriminant < 0) {
                    return false;
                }
                double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
                double t2 = (-b + sqrt(discriminant)) / (2.0 * a);
                if (t1 <= 0 && t2 <= 0) {
                    return false;
                }
                return true;
            }
            Math::Point3D *origin;
            double radius;

        protected:
        private:
    };
}

#endif /* !Sphere */
