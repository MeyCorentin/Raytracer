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
        Cone(Math::Point3D *origin, double radius, std::shared_ptr<Material> mat_value)
        {
            this->mat = mat_value;
            this->origin = origin;
            this->radius = radius;
        };
        ~Cone() {};

        bool hits(const Ray& r, double t_min, double t_max, hit_record& rec) {
            double height = 7.0;
            Math::Point3D sphere_color(0.8, 0.8, 0.0);
            Math::Vector3D oc = Math::Vector3D(r.origin->x_coords, r.origin->y_coords, r.origin->z_coords) - Math::Vector3D(origin->x_coords, origin->y_coords, origin->z_coords);
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
                        // Math::Point3D normal = Math::Point3D(intersection_point.x_coords - origin->x_coords, -radius / height, intersection_point.z_coords - origin->z_coords);
                        Math::Point3D normal = (intersection_point - origin) / radius;
                        Math::Point3D shading_color = 0.5 * (normal + Math::Vector3D(1, 1, 1));
                        rec.normal =  sphere_color * shading_color;
                        rec.mat = this->mat;
                        return true;
                    }
                }
            }
            return false;
        }
        Math::Point3D *origin;
        double radius;
        std::shared_ptr<Material> mat;
};