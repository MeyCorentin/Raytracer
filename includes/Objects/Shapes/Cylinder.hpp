/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Cylinder.hpp
*/

#pragma once

#include "Camera/Ray.hpp"
#include "interface/IShape.hpp"
#include "Materials/Material.hpp"
#include "Materials/Metal.hpp"
#include "Materials/Mate.hpp"
#include <memory>

class Cylinder: public IShape {
    public:
        Cylinder() {};
        Cylinder(Math::Point3D origin, double radius, double height, std::shared_ptr<Material> mat_value)
        {
            this->origin = origin;
            this->radius = radius;
            this->height = height;
            this->mat = mat_value;
        };
        ~Cylinder() {};
        bool hits(const Ray& r, double t_min, double t_max, hit_record& rec) {
            Math::Vector3D temp_1 = PointToVec(*r.origin);
            Math::Vector3D temp_2 = PointToVec(origin);
            Math::Vector3D oc = temp_1 - temp_2;
            double a = (*r.direction).x_coords * (*r.direction).x_coords + (*r.direction).z_coords * (*r.direction).z_coords;
            double b = 2.0 * (r.origin->x_coords * r.direction->x_coords + r.origin->z_coords * r.direction->z_coords);
            double c = (r.origin->x_coords * r.direction->x_coords + r.origin->z_coords * r.direction->z_coords) - radius * radius;
            double discriminant = b * b - 4 * a * c;

            if (discriminant >= 0) {
                double t1 = (-b - sqrt(discriminant)) / (2 * a);
                double t2 = (-b + sqrt(discriminant)) / (2 * a);
                if (t1 < t_max && t1 > t_min) {
                    double y = (r.origin->y_coords + t1 * r.direction->y_coords);
                    if (y >= origin.y_coords && y <= origin.y_coords + height) {
                    rec.t = t1;
                    rec.intersection = r.at(t1);
                    Math::Vector3D normal = Math::Vector3D(rec.intersection.x_coords - origin.x_coords, 0, rec.intersection.z_coords - origin.z_coords);
                    double length = std::sqrt(normal.x_coords * normal.x_coords + normal.y_coords * normal.y_coords + normal.z_coords * normal.z_coords);
                    normal.x_coords /= length;
                    normal.y_coords /= length;
                    normal.z_coords /= length;
                    rec.normal = Math::Point3D(normal.x_coords, normal.y_coords, normal.z_coords);
                    rec.mat = this->mat;
                    return true;
                    }
                }
                if (t2 < t_max && t2 > t_min) {
                    double y = (r.origin->y_coords + t2 * r.direction->y_coords);
                    if (y >= origin.y_coords && y <= origin.y_coords + height) {
                    rec.t = t2;
                    rec.intersection = r.at(t2);
                    Math::Vector3D normal = Math::Vector3D(rec.intersection.x_coords - origin.x_coords, 0, rec.intersection.z_coords - origin.z_coords);
                    double length = std::sqrt(normal.x_coords * normal.x_coords + normal.y_coords * normal.y_coords + normal.z_coords * normal.z_coords);
                    normal.x_coords /= length;
                    normal.y_coords /= length;
                    normal.z_coords /= length;
                    rec.normal = Math::Point3D(normal.x_coords, normal.y_coords, normal.z_coords);
                    rec.mat = this->mat;
                    return true;
                    }
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
        Math::Vector3D *getNormal()
        {
            return &this->normal;
        }
        void setNormal(Math::Vector3D n_rotate)
        {
            normal = n_rotate;
        }
        Math::Vector3D normal;
        Math::Point3D origin;
        double radius;
        double height;
        std::shared_ptr<Material> mat;
    protected:
    private:
};