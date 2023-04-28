/*
** EPITECH PROJECT, 2023
** Rectangle3D
** File description:
** Rectangle3D
*/

#ifndef Rectangle3D_HPP
#define Rectangle3D_HPP

class Ray;
class IShape;
class Point3D;
class Vector3D;

namespace Shape
{
    class Rectangle3D {
    public:
        Math::Point3D *origin;
        Math::Point3D *bottom_side;
        Math::Point3D *left_side;
        Rectangle3D(Math::Point3D *_origin, Math::Point3D *_bottom_side, Math::Point3D *_left_side)
            : origin(_origin), bottom_side(_bottom_side), left_side(_left_side) {}
        ~Rectangle3D(){};
        Math::Point3D pointAt(double u, double v)
        {
            Math::Point3D p = (*origin - *left_side/2 - *bottom_side/2 - Math::Point3D(0, 0, 1)) + u * (*left_side) + v * (*bottom_side) - (*origin);
            return p.unit_vector();
        }
    protected:
    private:
};
}
#endif /* !Rectangle3D */
