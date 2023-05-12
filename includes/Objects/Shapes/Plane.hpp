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
        bool hits(const Ray& r, double t_min, double t_max, hit_record& rec) {
            double value = dot(normal, *r.direction);
            double epsilon = 0.0001;
            if (abs(value) > epsilon) {
                Math::Point3D v = origin - *r.origin;
                double distance = dot(Math::PointToVec(v) ,normal) / value;
                if (distance >= 0.0 && distance > t_min && distance < t_max) {
                    rec.t = distance;
                    rec.intersection = r.at(distance);
                    rec.normal =  Math::VecToPoint(normal);
                    rec.mat = this->mat;
                    return true;
                }
            }
            return false;
        }
        std::shared_ptr<Material> getMat()
        {
            return mat;
        }
        Math::Point3D *getOrigin()
        {
            return &origin;
        }
        std::shared_ptr<Material> mat;
        Math::Vector3D normal;
        Math::Point3D origin;

    protected:
    private:
};
