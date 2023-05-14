/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cylinder
*/
#include "Camera/Ray.hpp"
#include "interface/IShape.hpp"
#include "Materials/Material.hpp"
#include "Materials/Metal.hpp"
#include "Materials/Mate.hpp"

#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_

class Cylinder: public IShape {
    public:
        Cylinder() {};
        Cylinder(Math::Point3D *origin, double radius, double height, std::shared_ptr<Material> mat_value)
        {

            this->origin = origin;
            this->radius = radius;
            this->mat = mat_value;
            this->height = height;
        };
        ~Cylinder() {};
        bool hits(const Ray& r, double t_min, double t_max, hit_record& rec) {
            Math::Vector3D temp_1 = PointToVec(*r.origin);
            Math::Vector3D temp_2 = PointToVec(*origin);
            Math::Vector3D oc = temp_1 - temp_2;
            double a = dot(*r.direction, *r.direction);
            double b = 2.0 * dot(oc, *r.direction);
            double c = dot(oc, oc) - radius * radius;
            double discriminant = b*b - 4*a*c;

            if (discriminant >= 0) {
                double t1 = (-b - sqrt(discriminant)) / (2 * a);
                double t2 = (-b + sqrt(discriminant)) / (2 * a);

                if (t1 < t_max && t1 > t_min) {
                    rec.t = t1;
                    rec.intersection = r.at(t1);
                    Math::Point3D normal = (rec.intersection - *origin) / radius;
                    Math::Point3D shading_color = 0.5 * (normal + Math::Vector3D(1,1,1));
                    rec.normal =  Math::VecToPoint(this->mat->getValue()) * shading_color;
                    rec.mat = this->mat;
                    return true;
                } else if (t2 < t_max && t2 > t_min) {
                    rec.t = t2;
                    rec.intersection = r.at(t2);
                    Math::Point3D normal = (rec.intersection - *origin) / radius;
                    Math::Point3D shading_color = 0.5 * (normal + Math::Vector3D(1,1,1));
                    rec.normal =  Math::VecToPoint(this->mat->getValue()) * shading_color;
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
        std::string mat_name;
        std::shared_ptr<Material> mat;
        Math::Point3D *origin;
        double radius;
        double height;

    protected:
    private:
};

#endif /* !CYLINDER_HPP_ */
