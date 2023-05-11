/*
** EPITECH PROJECT, 2023
** Mate
** File description:
** Mate
*/

#pragma once

#include "Materials/Material.hpp"
#include "Objects/Shapes/hit_record.hpp"

class hit_record;

class Mate: public Material {
    public:
        ~Mate();
        Mate(Math::Vector3D value);
        Mate(Math::Vector3D value, double kd, double ks, double ka, double n);
        bool rebound(Ray ray,  hit_record hit, Ray &reflection ,Math::Vector3D &attenuation);
        Math::Vector3D  reflect(const Math::Vector3D *v, const Math::Vector3D n);
        Math::Vector3D value;
        double kd;
        double ks;
        double ka;
        double n;

    protected:
    private:
};