/*
** EPITECH PROJECT, 2023
** Translate
** File description:
** Translate
*/

#pragma once

#include "interface/ITransform.hpp"

class Translate: public ITransform {
    public:
        Translate() {};
        template<class T>
        Translate(T object, Math::Vector3D value)
        {
            this->object = std::make_shared<T>(object);
            this->value = value;
        }
        ~Translate() {};
        bool hits(const Ray& r, double t_min, double t_max,  hit_record &rec)
        {
            Math::Point3D save = *r.origin;
            *r.origin = *r.origin - Math::VecToPoint(value);
            bool result = object.get()->hits(r, t_min, t_max, rec);
            *r.origin = save;
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

