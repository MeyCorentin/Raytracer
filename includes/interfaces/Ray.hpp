/*
** EPITECH PROJECT, 2023
** Ray
** File description:
** Ray
*/

#ifndef Raytracer
    #define Raytracer


#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace Raytracer
{
    class Ray {
        public:
            // Default constructor
            Ray() {};
            // Init constructor
            Ray(Math::Point3D *origin, Math::Vector3D *direction)
            {
                this->origin = origin;
                this->direction = direction;
            };
            Ray(Math::Point3D origin, Math::Point3D direction)
            {
                Math::Vector3D *d = new Math::Vector3D(direction.x_coords, direction.y_coords, direction.z_coords);
                this->origin = &origin;
                this->direction = d;
            };
            // Move constructor
            Ray(Ray &other)
            {
                this->origin  = other.origin;
                this->direction = other.direction;
            }
            // Copy constructor
            Ray(const Ray &obj)
            {
                origin = new Math::Point3D;
                direction = new Math::Vector3D;
                *origin = *obj.origin;
                *direction = *obj.direction;
            }
            // Copy operator
            Ray& operator=(Ray other)
            {
                origin = other.origin;
                direction = other.direction;
                return *this;
            }
            // Move Operator
            Ray& operator=(Ray&& other)
            {
                origin = std::move(other.origin);
                direction = std::move(other.direction);
                return *this;
            }
            Math::Point3D at(double t) const {
                return *origin + t*(Math::Point3D(direction->x_coords, direction->y_coords, direction->z_coords));
            }
            ~Ray() {};
            Math::Point3D *origin;
            Math::Vector3D *direction;

        protected:
        private:
    };
} // namespace Raytracer


#endif /* !Ray */
