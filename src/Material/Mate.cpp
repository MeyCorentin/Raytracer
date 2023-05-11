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
    Math::Point3D scatter_direction = hit.normal + random_in_hemisphere(hit.normal).unit_vector();

    if (scatter_direction.x_coords < 1e-8 && scatter_direction.y_coords < 1e-8 && scatter_direction.z_coords < 1e-8)
        scatter_direction = Math::Point3D(hit.normal.x_coords, hit.normal.y_coords, hit.normal.z_coords);

    reflection = Ray(&hit.p, new Math::Vector3D(scatter_direction.x_coords, scatter_direction.y_coords, scatter_direction.z_coords));
    attenuation = this->value;
    return true;
};

