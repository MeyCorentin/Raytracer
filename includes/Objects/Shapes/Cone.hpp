/*
** EPITECH PROJECT, 2023
** Cone
** File description:
** Cone
*/

#pragma once

#include "Camera/Ray.hpp"
#include "interface/IShape.hpp"
#include "Materials/Material.hpp"
#include "Materials/Metal.hpp"
#include "Materials/Mate.hpp"

#include <memory>

class Cone : public IShape {
    public:
        Cone() {};
        Cone(Math::Point3D *origin, double radius, double height, std::shared_ptr<Material> mat_value)
        {
            this->mat = mat_value;
            this->origin = origin;
            this->radius = radius;
            this->height = height;
        };
        ~Cone() {};

        bool hits(const Ray& r, double t_min, double t_max, hit_record& rec) {
            Math::Point3D sphere_color(0.8, 0.8, 0.0);
            Math::Vector3D temp_1 =  Math::Vector3D(r.origin->x_coords, r.origin->y_coords, r.origin->z_coords);
            Math::Vector3D temp_2 =  Math::Vector3D(origin->x_coords, origin->y_coords, origin->z_coords);
            Math::Vector3D oc = temp_1 - temp_2;
            double k = radius / height;
            k = k * k;
            double a = r.direction->x_coords * r.direction->x_coords + r.direction->z_coords * r.direction->z_coords - k * r.direction->y_coords * r.direction->y_coords;
            double b = 2 * (oc.x_coords * r.direction->x_coords + oc.z_coords * r.direction->z_coords - k * oc.y_coords * r.direction->y_coords);
            double c = oc.x_coords * oc.x_coords + oc.z_coords * oc.z_coords - k * oc.y_coords * oc.y_coords;
            double discriminant = b * b - 4 * a * c;
            if (discriminant >= 0) {
                double t1 = (-b - sqrt(discriminant)) / (2 * a);
                if (t1 < t_max && t1 > t_min && t1 < a) {
                    Math::Point3D intersection_point = r.at(t1);
                    if (intersection_point.y_coords < origin->y_coords) {
                        rec.t = t1;
                        rec.intersection = intersection_point;
                        Math::Point3D normal = (intersection_point - *origin) / radius;
                        rec.normal =  (intersection_point - *origin) / radius;
                        rec.mat = this->mat;
                        return true;
                    }
                }
            }
            return false;
        }
        Math::Point3D *origin;
        double radius;
        double height;
        std::shared_ptr<Material> getMat()
        {
            return mat;
        }
        Math::Point3D *getOrigin()
        {
            return origin;
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
};