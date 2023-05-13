/*
** EPITECH PROJECT, 2023
** IShape
** File description:
** IShape
*/

#pragma once

#include "Camera/Ray.hpp"
#include "Objects/Shapes/hit_record.hpp"
#include "interface/IObject.hpp"

class IShape: public IObject {
    public:
        virtual ~IShape() = default;
        virtual bool hits(const Ray& r, double t_min, double t_max,  hit_record &rec) = 0;
        virtual std::shared_ptr<Material> getMat() = 0;
        virtual Math::Point3D *getOrigin() = 0;
        virtual Math::Vector3D *getNormal() = 0;
        virtual void setNormal(Math::Vector3D n_rotate) = 0;
        std::shared_ptr<Material> mat;
        Math::Point3D *origin;
        Math::Vector3D normal;

    protected:
    private:
};

