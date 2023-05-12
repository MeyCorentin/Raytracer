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
        bool computeLight(
            Scene scene,
            const Ray& r,
            hit_record &temp_rec,
            const std::shared_ptr<IObject>& object,
            std::vector<std::shared_ptr<IObject>> object_list)
        {
            Math::Vector3D mat_value = object.get()->getMat().get()->getValue();
            Math::Vector3D result = mat_value * this->color  * this->intensity;
            temp_rec.light_result = Math::VecToPoint(result);
            temp_rec.light_result = Math::Point3D(  clamp(temp_rec.light_result.x_coords, 0.0 , 1.0),
                                                    clamp(temp_rec.light_result.y_coords, 0.0 , 1.0),
                                                    clamp(temp_rec.light_result.z_coords, 0.0 , 1.0));
            return true;
        }
        Math::Vector3D color;
        double intensity;
    protected:
    private:
};

