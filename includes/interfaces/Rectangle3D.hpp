/*
** EPITECH PROJECT, 2023
** Rectangle_hpp
** File description:
** Rectangle_hpp
*/

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Ray.hpp"

class Rectangle3D {
    public:
        Rectangle3D() : origin(new Math::Point3D (0, 0, 0)), bottom_side(new Math::Vector3D(0, 1, 0)), left_side(new Math::Vector3D(1, 0, 0)) {}
        Rectangle3D(Math::Point3D *_origin, Math::Vector3D *_bottom_side, Math::Vector3D *_left_side)
            : origin(_origin), bottom_side(_bottom_side), left_side(_left_side) {}
        ~Rectangle3D(){};
        Math::Point3D pointAt(double u, double v)
        {
            double x = (this->origin->x_coords) + u * (this->bottom_side->x_coords) + v * (this->left_side->x_coords);
            double y = (this->origin->y_coords) + u * (this->bottom_side->y_coords) + v * (this->left_side->y_coords);
            double z = (this->origin->z_coords) + u * (this->bottom_side->z_coords) + v * (this->left_side->z_coords);

            return Math::Point3D(x, y, z);
        }
        Math::Point3D *origin;
        Math::Vector3D *bottom_side;
        Math::Vector3D *left_side;
    protected:
    private:
};
#endif /* !Rectangle_hpp */
