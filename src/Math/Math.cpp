/*
** EPITECH PROJECT, 2023
** math
** File description:
** math
*/

#include "Math/Math.hpp"

double Math::dot(const Math::Vector3D* u, const Math::Vector3D* v) {
    return u->x_coords * v->x_coords + u->y_coords * v->y_coords + u->z_coords * v->z_coords;
}
Math::Point3D Math::operator*(const Math::Point3D &u, const Math::Point3D &v) {
        return Math::Point3D(u.x_coords * v.x_coords, u.y_coords * v.y_coords, u.z_coords * v.z_coords);
}
Math::Point3D Math::operator*(double t, const Math::Point3D &v) {
    return Math::Point3D(t*v.x_coords, t*v.y_coords, t*v.z_coords);
}
Math::Point3D Math::operator*(const Math::Point3D &v, double t) {
    return t * v;
}
Math::Point3D Math::operator/(Math::Point3D v, double t) {
    return (1/t) * v;
}
Math::Point3D Math::operator+(const Math::Point3D &u, const Math::Point3D &v) {
    return Math::Point3D(u.x_coords + v.x_coords, u.y_coords + v.y_coords, u.z_coords + v.z_coords);
}
Math::Point3D Math::operator+(const Math::Point3D &u, const Math::Vector3D &v) {
    return Math::Point3D(u.x_coords + v.x_coords, u.y_coords + v.y_coords, u.z_coords + v.z_coords);
}
Math::Point3D Math::operator-(const Math::Point3D &u, const Math::Point3D &v) {
    return Math::Point3D(u.x_coords - v.x_coords, u.y_coords - v.y_coords, u.z_coords - v.z_coords);
}
Math::Point3D Math::operator-(Math::Point3D *const u, const Math::Point3D v) {
    return Math::Point3D(u->x_coords - v.x_coords, u->y_coords - v.y_coords, u->z_coords - v.z_coords);
}
Math::Point3D Math::operator-(Math::Point3D u,  Math::Point3D *v) {
    return Math::Point3D(u.x_coords - v->x_coords, u.y_coords - v->y_coords, u.z_coords - v->z_coords);
}
Math::Vector3D Math::operator*(double scalar, const Math::Vector3D& v) {
    return Math::Vector3D(v.x_coords * scalar, v.y_coords * scalar, v.z_coords * scalar);
}
Math::Vector3D Math::operator-(const Math::Vector3D &u, Math::Vector3D &v) {
    return Math::Vector3D(u.x_coords - v.x_coords, u.y_coords - v.y_coords, u.z_coords - v.z_coords);
}
Math::Vector3D Math::operator-(Math::Vector3D &u, Math::Vector3D &v) {
    return Math::Vector3D(u.x_coords - v.x_coords, u.y_coords - v.y_coords, u.z_coords - v.z_coords);
}