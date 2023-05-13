/*
** EPITECH PROJECT, 2023
** IObject
** File description:
** IObject
*/

#pragma once

#include "Objects/Shapes/hit_record.hpp"
#include "Camera/Ray.hpp"

class IObject {
    public:
        virtual ~IObject() = default;
        virtual bool hits(const Ray& r, double t_min, double t_max,  hit_record &rec) = 0;
        virtual std::shared_ptr<Material> getMat() = 0;
        virtual Math::Point3D *getOrigin() = 0;
        virtual Math::Vector3D *getNormal() = 0;
        virtual void setNormal(Math::Vector3D n_rotate) = 0;

    protected:
    private:
};
