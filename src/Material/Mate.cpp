/*
** EPITECH PROJECT, 2023
** Mate
** File description:
** Mate
*/

#include "Materials/Mate.hpp"
#include "main.hpp"

Mate::~Mate() {};
Mate::Mate(Math::Vector3D value, double kd, double ks, double ka, double n) {
    this->value = value;
    this->kd = kd;
    this->ks = ks;
    this->ka = ka;
    this->n = n;
}
Mate::Mate(Math::Vector3D value) {
    this->value = value;
}


bool Mate::rebound(Ray ray,  hit_record hit, Ray &reflection ,Math::Vector3D &attenuation) {
    Math::Point3D temp = hit.normal + random_in_unit_sphere();
    Math::Vector3D scatter_direction = Math::Vector3D(temp.x_coords, temp.y_coords, temp.z_coords);

    if (scatter_direction.x_coords < 1e-8 && scatter_direction.y_coords < 1e-8 && scatter_direction.z_coords < 1e-8)
        scatter_direction = Math::Vector3D(hit.normal.x_coords, hit.normal.y_coords, hit.normal.z_coords);

    reflection = Ray(&hit.p, &scatter_direction);
    attenuation = this->value;
    return true;
};

