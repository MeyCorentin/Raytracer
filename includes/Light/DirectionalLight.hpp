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
        //DirectionalLight
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
            double light_intensity = 0.0;
            Math::Vector3D mat_value = object.get()->getMat().get()->getValue();
            Math::Point3D hit_point = *r.origin + (Math::VecToPoint(*r.direction) * temp_rec.t);
            Math::Vector3D normal = Math::PointToVec(hit_point - *(object.get()->getOrigin())).unit_vector();
            Math::Vector3D direction_light = -(direction->unit_vector());
            Ray shadow_ray = Ray {&hit_point, &direction_light};
            if (!scene.hit_global(shadow_ray,  0.001, INFINITY,  temp_rec, true))
                    light_intensity = static_cast<double>(this->intensity);
            double light_power = std::max(dot(normal, direction_light), 0.0) * light_intensity;
            Math::Vector3D light_reflected = mat_value / M_PI;
            Math::Vector3D temp_result = mat_value * this->color  * light_power;
            Math::Vector3D result =  temp_result * light_reflected;
            Math::Point3D temp = Math::VecToPoint(normal);
            temp_rec.light_result = Math::VecToPoint(result) * random_in_hemisphere(temp);
            temp_rec.light_result = Math::Point3D(  clamp(temp_rec.light_result.x_coords, 0.0 , 1.0),
                                                    clamp(temp_rec.light_result.y_coords, 0.0 , 1.0),
                                                    clamp(temp_rec.light_result.z_coords, 0.0 , 1.0));
            return true;

        }
        Math::Vector3D *direction;
        Math::Vector3D color;
        double intensity;


    protected:
    private:
};

