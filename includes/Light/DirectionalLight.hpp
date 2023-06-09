/*
** EPITECH PROJECT, 2023
** DirectionalLight
** File description:
** DirectionalLight
*/



#pragma once
#include "interface/ILight.hpp"
#include "Camera/Ray.hpp"
#include "Scene/Scene.hpp"
#include "main.hpp"
#include <algorithm>

class DLight: public ILight {
    public:
        DLight(Math::Vector3D *direction, Math::Vector3D color, double intensity) {
            this->direction = direction;
            this->color = color;
            this->intensity = intensity;
        }
        ~DLight() {};
        bool computeLight(
            Scene scene,
            const Ray& r,
            hit_record &temp_rec,
            const std::shared_ptr<IObject>& object,
            std::vector<std::shared_ptr<IObject>> object_list
            )
        {
            Math::Vector3D mat_value = object.get()->getMat().get()->getValue();
            Math::Point3D hit_point = *r.origin + (Math::VecToPoint(*r.direction) * temp_rec.t);
            Math::Vector3D normal = Math::PointToVec(hit_point - *(object.get()->getOrigin())).unit_vector();
            Math::Vector3D direction_light = -(direction->unit_vector());

            if (dot(normal, direction_light) < 0) {
                normal = -normal;
            }
            if (scene.hit_global(Ray(&hit_point, &direction_light),  0.0000001, INFINITY,  temp_rec, true))
            {
                temp_rec.light_result = Math::Point3D(0,0,0);
                return true;
            }
            double light_power = std::max(dot(normal, direction_light), 0.0) * this->intensity;
            Math::Vector3D light_reflected = mat_value / M_PI;
            Math::Vector3D temp_result = mat_value * this->color  * light_power;
            Math::Vector3D result =  temp_result * light_reflected;
            temp_rec.light_result = Math::VecToPoint(result);
            return true;
        }
        Math::Vector3D *direction;
        Math::Vector3D color;
        double intensity;


    protected:
    private:
};

