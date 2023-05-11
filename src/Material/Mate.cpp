/*
** EPITECH PROJECT, 2023
** Mate
** File description:
** Mate
*/

#include "Materials/Mate.hpp"
#include "main.hpp"

Mate::~Mate() {};
Mate::Mate(Math::Vector3D value) {
    this->value = value;
}

Math::Vector3D Mate::getValue()
{
    return this->value;
}

bool Mate::rebound(Ray ray,  hit_record hit, Ray &reflection ,Math::Vector3D &attenuation) {
    reflection = Ray(&hit.p, new Math::Vector3D(hit.normal.x_coords, hit.normal.y_coords, hit.normal.z_coords));
    attenuation = this->value;
    return true;
};

