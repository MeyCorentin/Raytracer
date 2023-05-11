/*
** EPITECH PROJECT, 2023
** hit_record
** File description:
** hit_record
*/


#pragma once

#include <memory>
#include "Camera/Ray.hpp"

class Material;

class hit_record {
    public:
        hit_record();
        ~hit_record();
        Math::Point3D p;
        Math::Point3D normal;
        double t;
        std::shared_ptr<Material> mat;
    protected:
    private:
};
