/*
** EPITECH PROJECT, 2023
** Material
** File description:
** Material
*/

#pragma once

#include "Camera/Ray.hpp"

class hit_record;

class Material {
    public:
        virtual ~Material() = default;
        virtual bool rebound(Ray ray,  hit_record hit, Ray &reflection ,Math::Vector3D &attenuation) = 0;
        virtual Math::Vector3D getValue() = 0;
        Math::Vector3D value;

    protected:
    private:
};
