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
    Math::Vector3D temp_normal = Math::PointToVec(hit.normal);
    reflection = Ray(&hit.p, &temp_normal);
    attenuation = this->value;
    return true;
};

