/*
** EPITECH PROJECT, 2023
** Rotate
** File description:
** Rotate
*/

#pragma once

#include "interface/IObjectDecorator.hpp"

class Rotate: public IObjectDecorator {
    public:
        Rotate() {};
        template<class T>
        Rotate(T object, Math::Vector3D value)
        {
            this->object = std::make_shared<T>(object);
            this->value = value;
        }
        ~Rotate() {};
        bool hits(const Ray& r, double t_min, double t_max,  hit_record &rec)
        {
            double cosA = cos(45.0 * 3.14159 / 180.0);
            double sinA = sin(45.0 * 3.14159 / 180.0);
            Math::Vector3D v = value;
            double vx = v.x_coords;
            double vy = v.y_coords;
            double vz = v.z_coords;

            std::vector<std::vector<double>> rotationMatrix(3, std::vector<double>(3));
            rotationMatrix[0][0] = cosA + (1 - cosA) * vx * vx;
            rotationMatrix[0][1] = (1 - cosA) * vx * vy - sinA * vz;
            rotationMatrix[0][2] = (1 - cosA) * vx * vz + sinA * vy;
            rotationMatrix[1][0] = (1 - cosA) * vy * vx + sinA * vz;
            rotationMatrix[1][1] = cosA + (1 - cosA) * vy * vy;
            rotationMatrix[1][2] = (1 - cosA) * vy * vz - sinA * vx;
            rotationMatrix[2][0] = (1 - cosA) * vz * vx - sinA * vy;
            rotationMatrix[2][1] = (1 - cosA) * vz * vy + sinA * vx;
            rotationMatrix[2][2] = cosA + (1 - cosA) * vz * vz;
            Math::Vector3D temp_norm = *object.get()->getNormal();
            Math::Vector3D rotated_vec;
            rotated_vec.x_coords = rotationMatrix[0][0]* temp_norm.x_coords  + rotationMatrix[0][1]*temp_norm.y_coords + rotationMatrix[0][0]*temp_norm.z_coords;
            rotated_vec.y_coords = rotationMatrix[1][0]* temp_norm.x_coords  + rotationMatrix[1][1]*temp_norm.y_coords + rotationMatrix[1][1]*temp_norm.z_coords;
            rotated_vec.z_coords = rotationMatrix[2][0]* temp_norm.x_coords  + rotationMatrix[2][1]*temp_norm.y_coords + rotationMatrix[2][2]*temp_norm.z_coords;
            object.get()->setNormal(rotated_vec);
            bool result = object.get()->hits(r, t_min, t_max, rec);
            object.get()->setNormal(temp_norm);
            return result;
        };
        std::shared_ptr<Material> getMat()
        {
            return object.get()->getMat();
        }
        Math::Point3D *getOrigin()
        {
            return object.get()->getOrigin();
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
        std::shared_ptr<IObject> object;
        Math::Vector3D value;

    protected:
    private:
};

