/*
** EPITECH PROJECT, 2023
** Vector3D
** File description:
** Vector3D
*/

#ifndef Vector
    #define Vector

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include "Point3D.hpp"

namespace Math
{
    class Vector3D {
        public:
            Vector3D()
                {
                    this->x_coords = 0;
                    this->y_coords = 0;
                    this->z_coords = 0;
                };
                // Init constructor
                Vector3D(double x, double y, double z)
                {
                    this->x_coords = x;
                    this->y_coords = y;
                    this->z_coords = z;
                }
                //Move constructor
                Vector3D(Vector3D &other)
                {
                    this->x_coords = other.x_coords;
                    this->y_coords = other.y_coords;
                    this->z_coords = other.z_coords;
                }
                // Copy constructor
                Vector3D(const Vector3D &obj)
                {
                    x_coords = obj.x_coords;
                    y_coords = obj.y_coords;
                    z_coords = obj.z_coords;
                }
                ~Vector3D() {};
                // Copy operator
                Vector3D& operator=(Vector3D other)
                {
                    x_coords = other.x_coords;
                    y_coords = other.y_coords;
                    z_coords = other.z_coords;
                    return *this;
                }
                // Move Operator
                Vector3D& operator=(Vector3D&& other)
                {
                    x_coords = std::move(other.x_coords);
                    y_coords = std::move(other.y_coords);
                    z_coords = std::move(other.z_coords);
                    return *this;
                }
                // sub operator
                Vector3D operator-(Vector3D const &v1)
                {
                    return Vector3D(this->x_coords - v1.x_coords, this->y_coords - v1.y_coords, this->z_coords - v1.z_coords);
                }
                // Return he length of the vector
                double length()
                {
                    return sqrt(((x_coords) * (x_coords)) + ((y_coords) * (y_coords)) + ((z_coords) * (z_coords)));
                }
                // Return the dot of two vector
                double dot_v(Vector3D *other)
                {
                    return (((x_coords) * (other->x_coords)) + ((y_coords) * (other->y_coords)) + ((z_coords) * (other->z_coords)));
                }
                double x_coords;
                double y_coords;
                double z_coords;

        protected:
        private:
    };
}

#endif /* !Vector3D */
