/*
** EPITECH PROJECT, 2023
** Point3D
** File description:
** Point3D
*/

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include "Math/Vector3D.hpp"

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
            Point3D operator-() const {
                return Point3D(-x_coords, -y_coords, -z_coords);
            }
            Point3D& operator-(Vector3D&& other)
            {
                x_coords -= other.x_coords;
                y_coords -= other.y_coords;
                z_coords -= other.z_coords;
                return *this;
            }
            // Return the dot of two vector
            double dot_v(Vector3D *other)
            {
                return x_coords * other->x_coords + y_coords * other->y_coords + z_coords * other->z_coords;
            }
            double dot_p(Point3D *other)
            {
                return x_coords * other->x_coords + y_coords * other->y_coords + z_coords * other->z_coords;
            }
            Point3D& operator*=(const double t) {
                x_coords *= t;
                y_coords *= t;
                z_coords *= t;
                return *this;
            }

            Point3D& operator+=(const Point3D &v) {
                x_coords += v.x_coords;
                y_coords += v.y_coords;
                z_coords += v.z_coords;
                return *this;
            }
            Point3D operator/=(double t) {
                return *this *= 1/t;
            }

            double length() const {
                return x_coords*x_coords + y_coords*y_coords + z_coords*z_coords;
            }
            Point3D unit_vector()
            {
                return Point3D(this->x_coords / sqrt(this->length()), this->y_coords / sqrt(this->length()), this->z_coords / sqrt(this->length()));
            }
            double x_coords;
            double y_coords;
            double z_coords;

        protected:
        private:
    };
}
