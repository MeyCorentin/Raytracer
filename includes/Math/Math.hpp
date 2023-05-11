/*
** EPITECH PROJECT, 2023
** Math
** File description:
** Math
*/

#ifndef MATh_HPP_
    #define MATh_HPP_

#pragma once

#include "Math/Point3D.hpp"

namespace Math
{
    double dot(const Vector3D* u, const Vector3D* v);
    Point3D operator*(const Math::Point3D &v, double t);
    Point3D operator*(const Point3D &u, const Point3D &v);
    Point3D operator*(double t, const Point3D &v);
    Point3D operator/(Point3D v, double t);
    Point3D operator+(const Vector3D &u, const Vector3D &v);
    Point3D operator+(const Point3D &u, const Point3D &v);
    Point3D operator+(const Point3D &u, const Vector3D &v);
    Point3D operator-(const Point3D &u, const Point3D &v);
    Point3D operator-(Math::Point3D *const u, const Math::Point3D v);
    Point3D operator-(Math::Point3D u,  Math::Point3D *v);
    Vector3D operator*(double scalar, const Vector3D& v);
    Vector3D operator-(const Vector3D &u, Vector3D &v);
    Vector3D operator-(Vector3D &u, Vector3D &v);
}

#endif /* !MAIN_HPP_ */
