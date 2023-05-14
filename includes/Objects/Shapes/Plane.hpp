/*
** EPITECH PROJECT, 2023
** Plane
** File description:
** Plane
*/


#pragma once

#include "interface/IShape.hpp"
#include "Camera/Ray.hpp"
#include <stdlib.h>

class Plane: public IShape {
    public:
        Plane(Math::Vector3D normal, Math::Point3D origin, std::shared_ptr<Material> mat_value) {
            this->normal = normal.unit_vector();
            this->origin = origin;
            this->mat = mat_value;
        };
        ~Plane() {};
        bool hits(const Ray& r, double t_min, double t_max, hit_record& rec) override {
            double t = dot(Math::PointToVec(origin) - Math::PointToVec(*r.origin), normal) / (dot(*r.direction ,normal));

            if (t > 0.00001 &&  t < t_max && t  > t_min) {
                rec.t = t;
                rec.intersection = *r.origin + Math::VecToPoint(*r.direction * t);
                rec.normal = Math::VecToPoint(normal);
                rec.mat = mat;
                return (true);
            }

            return(false);
        }
        std::shared_ptr<Material> getMat()
        {
            return mat;
        }
        Math::Point3D *getOrigin()
        {
            return &origin;
        }
        Math::Vector3D *getNormal()
        {
            return &this->normal;
        }
        void setNormal(Math::Vector3D n_rotate)
        {
            normal = n_rotate;
        }
        Math::Vector3D normal;
        std::shared_ptr<Material> mat;
        Math::Point3D origin;

    protected:
    private:
};
