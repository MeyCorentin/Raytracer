/*
** EPITECH PROJECT, 2023
** AmbientLight
** File description:
** AmbientLight
*/


#pragma once
#include "interface/ILight.hpp"
#include "Scene/Scene.hpp"
#include <algorithm>
#include "main.hpp"

class ALight: public ILight {
    //Ambient Light
    public:
        ALight( Math::Vector3D color, double intensity) {
            this->color = color;
            this->intensity = intensity;
        };
        ~ALight(){};
        Math::Vector3D normal_direction(hit_record &temp_rec){
            Math::Vector3D vec_normal = Math::PointToVec(temp_rec.normal);
            Math::Vector3D cross_unit = Math::Vector3D(0.0, 0.5, 0.0).cross(vec_normal).unit_vector().unit_vector();
            Math::Vector3D v = cross_unit.cross(vec_normal);
            Math::Point3D  random_normal = random_in_hemisphere(temp_rec.normal);
            Math::Vector3D result = cross_unit * random_normal.x_coords + v * random_normal.y_coords + vec_normal * random_normal.z_coords;
            return result.unit_vector();

        }
        bool computeLight(
            Scene scene,
            const Ray& r,
            hit_record &temp_rec,
            const std::shared_ptr<IObject>& object,
            std::vector<std::shared_ptr<IObject>> object_list)
        {
            Math::Vector3D direction_light = -*r.direction;
            Math::Point3D hit_point = *r.origin + (Math::VecToPoint(*r.direction) * temp_rec.t);
            double light_intensity = 0.0;
            Math::Vector3D mat_value = object.get()->getMat().get()->getValue();
            Math::Vector3D temp_direction = normal_direction(temp_rec);
            Ray temp_ray = Ray{&hit_point, &temp_direction};
            if (!scene.hit_global(temp_ray,  0.001, INFINITY,  temp_rec, true))
                    light_intensity = static_cast<double>(this->intensity);
            Math::Vector3D result = mat_value * this->color  * light_intensity;
            temp_rec.light_result = Math::VecToPoint(result);
            return true;
        }
        Math::Vector3D color;
        double intensity;
    protected:
    private:
};

