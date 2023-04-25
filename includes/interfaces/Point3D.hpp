/*
** EPITECH PROJECT, 2023
** Point3D
** File description:
** Point3D
*/

#ifndef Point
    #define Point

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include "Vector3D.hpp"

namespace Math
{
    class Point3D {
        public:
            // Default constructor
            Point3D()
            {
                this->x_coords = 0;
                this->y_coords = 0;
                this->z_coords = 0;
            };
            // Init constructor
            Point3D(double x, double y, double z)
            {
                this->x_coords = x;
                this->y_coords = y;
                this->z_coords = z;
            }
            //Move constructor
            Point3D(Point3D &other)
            {
                this->x_coords = other.x_coords;
                this->y_coords = other.y_coords;
                this->z_coords = other.z_coords;
            }
            // Copy constructor
            Point3D(const Point3D &obj)
            {
                x_coords = obj.x_coords;
                y_coords = obj.y_coords;
                z_coords = obj.z_coords;
            }
            ~Point3D() {};
            // Copy operator
            Point3D& operator=(Point3D other)
            {
                x_coords = other.x_coords;
                y_coords = other.y_coords;
                z_coords = other.z_coords;
                return *this;
            }
            // Move Operator
            Point3D& operator=(Point3D&& other)
            {
                x_coords = std::move(other.x_coords);
                y_coords = std::move(other.y_coords);
                z_coords = std::move(other.z_coords);
                return *this;
            }
            // Sub operator
            Point3D operator-(const Point3D& other) const {
                return Point3D(x_coords - other.x_coords, y_coords - other.y_coords, z_coords - other.z_coords);
            }
            // Return the dot of two vector
            double dot_v(Vector3D *other)
            {
                return (((x_coords) * (other->x_coords)) + ((y_coords) * (other->y_coords)) + ((z_coords) * (other->z_coords)));
            }
            double dot_p(Point3D *other)
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

#endif /* !Point3D */
