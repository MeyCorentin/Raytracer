/*
** EPITECH PROJECT, 2023
** Vector3D
** File description:
** Vector3D
*/

#ifndef Vector3D_HPP
#define Vector3D_HPP


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
                Vector3D operator-() const {
                    return Vector3D(-x_coords, -y_coords, -z_coords);
                }
                Vector3D& operator+(Vector3D&& other)
                {
                    x_coords += other.x_coords;
                    y_coords += other.y_coords;
                    z_coords += other.z_coords;
                    return *this;
                }
                Vector3D& operator*=(const double t) {
                    x_coords *= t;
                    y_coords *= t;
                    z_coords *= t;
                    return *this;
                }

                Vector3D operator*(double t) {
                    return Vector3D(t*this->x_coords, t*this->y_coords, t*this->z_coords);
                }
                // Return he length of the vector
                double length()
                {
                    return sqrt(((this->x_coords) * (this->x_coords)) + ((this->y_coords) * (this->y_coords)) + ((this->z_coords) * (this->z_coords)));
                }
                Vector3D cross(Vector3D other)
                {
                    return Vector3D(this->y_coords * other.z_coords - this->z_coords * other.y_coords, this->z_coords * other.x_coords - this->x_coords * other.z_coords, this->x_coords * other.y_coords - this->y_coords * other.x_coords);
                }
                Vector3D operator/(int value)
                {
                    return Vector3D(this->x_coords / value, this->y_coords / value, this->z_coords / value);
                }
                Vector3D unit_vector()
                {
                    return Vector3D(this->x_coords / this->length(), this->y_coords / this->length(), this->z_coords / this->length());
                }
                // Return the dot of two vector
                double dot_v(Vector3D *other)
                {
                    return this->x_coords * other->x_coords + this->y_coords * other->y_coords + this->z_coords * other->z_coords;
                }
                double x_coords;
                double y_coords;
                double z_coords;

        protected:
        private:
    };
    double dot(const Vector3D u, const Vector3D* v) {
        return u.x_coords * v->x_coords + u.y_coords * v->y_coords + u.z_coords * v->z_coords;
    }
    double dot(const Vector3D* u, const Vector3D* v) {
        return u->x_coords * v->x_coords + u->y_coords * v->y_coords + u->z_coords * v->z_coords;
    }
    double dot(const Vector3D &u, const Vector3D &v) {
        return u.x_coords * v.x_coords + u.y_coords * v.y_coords + u.z_coords * v.z_coords;
    }
    double dot(Vector3D &u, Vector3D &v) {
        return u.x_coords * v.x_coords + u.y_coords * v.y_coords + u.z_coords * v.z_coords;
    }
    Vector3D operator+(const Vector3D &u, const Vector3D &v) {
        return Vector3D(u.x_coords + v.x_coords, u.y_coords + v.y_coords, u.z_coords + v.z_coords);
    }
    Vector3D operator*(double scalar, const Vector3D& v) {
        return Vector3D(v.x_coords * scalar, v.y_coords * scalar, v.z_coords * scalar);
    }

    Vector3D operator-(const Vector3D &u, const Vector3D &v) {
        return Vector3D(u.x_coords - v.x_coords, u.y_coords - v.y_coords, u.z_coords - v.z_coords);
    }
}


#endif /* !Vector3D */
