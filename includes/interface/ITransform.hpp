/*
** EPITECH PROJECT, 2023
** ITransform
** File description:
** ITransform
*/

#pragma once

#include "Camera/Ray.hpp"
#include "Objects/Shapes/hit_record.hpp"
#include "interface/IObject.hpp"

class ITransform : public IObject {
    public:
        virtual ~ITransform() = default;
        virtual bool hits(const Ray& r, double t_min, double t_max, hit_record &rec) = 0;
        virtual std::shared_ptr<Material> getMat() = 0;
        virtual Math::Point3D *getOrigin() = 0;
        std::shared_ptr<Material> mat;
        Math::Point3D *origin;
    protected:
    private:
};