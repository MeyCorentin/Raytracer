/*
** EPITECH PROJECT, 2023
** Metal
** File description:
** Metal
*/

#include "Materials/Metal.hpp"

Metal::~Metal() {};

Metal::Metal(Math::Vector3D value) {
    this->value = value;
}

bool Metal::rebound(Ray ray,  hit_record hit, Ray &reflection ,Math::Vector3D &attenuation) {
    Math::Vector3D unit_direction = ray.direction->unit_vector();
    Math::Vector3D temp_vector =  Math::PointToVec(hit.normal);
    Math::Vector3D reflected = reflect(&unit_direction, temp_vector);
    reflection = Ray(&hit.normal, &reflected);
    attenuation = this->value;
    if (dot(*reflection.direction, temp_vector) < 0)
        return true;
    return false;
};

Math::Vector3D  Metal::reflect(const Math::Vector3D *v, const Math::Vector3D n) {
    Math::Vector3D temp = 2*dot(*v,n)*(n);
    Math::Vector3D _v =*v;
    return _v - temp;
}

Math::Vector3D Metal::getValue()
{
    return this->value;
}
