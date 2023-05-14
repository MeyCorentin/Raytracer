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
        Cylinder(Math::Point3D *origin, double radius, std::shared_ptr<Material> mat_value)
        {
            this->origin = origin;
            this->radius = radius;
            this->mat = mat_value;
        };
        ~Cylinder() {};
        bool hits(const Ray& r, double t_min, double t_max, hit_record& rec) {
            Math::Vector3D axis = Math::Vector3D(0,1,0);
            Math::Vector3D temp_1 = Math::PointToVec(*r.origin);
            Math::Vector3D temp_2 = Math::PointToVec(*origin);
            Math::Vector3D oc = temp_1 - temp_2;
            double a = dot(*r.direction - axis * dot(*r.direction, axis), *r.direction - axis * dot(*r.direction, axis));
            double b = 2.0 * dot(oc - axis * dot(oc, axis), *r.direction - axis * dot(*r.direction, axis));
            double c = dot(oc - axis * dot(oc, axis), oc - axis * dot(oc, axis)) - radius * radius;
            double discriminant = b * b - 4 * a * c;
            if (discriminant >= 0) {
                double t1 = (-b - sqrt(discriminant)) / (2 * a);
                double t2 = (-b + sqrt(discriminant)) / (2 * a);
                double t = t1;
                if (t < t_min || t > t_max) {
                    t = t2;
                }
                if (t >= t_min && t <= t_max) {
                    rec.t = t;
                    rec.intersection = r.at(t);
                    Math::Vector3D n = (Math::PointToVec(rec.intersection) - Math::PointToVec(*origin) - axis * dot(Math::PointToVec(rec.intersection) - Math::PointToVec(*origin), axis)) / radius;
                    rec.normal = Math::VecToPoint(n - axis * dot(n, axis));
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

    protected:
    private:
};

#endif /* !CYLINDER_HPP_ */
