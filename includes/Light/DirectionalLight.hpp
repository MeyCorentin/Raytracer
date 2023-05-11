/*
** EPITECH PROJECT, 2023
** DirectionalLight
** File description:
** DirectionalLight
*/



#pragma once
#include "interface/ILight.hpp"

class DLight: public ILight {
    public:
        //DirectionalLight
        DLight(Math::Vector3D *location, Math::Vector3D *color, double intensity) {
            this->location = location;
            this->color = color;
            this->intensity = intensity;
        }
        ~DLight() {};
        bool computeLight(hit_record &temp_rec, const std::shared_ptr<IObject>& object, std::vector<std::shared_ptr<IObject>> object_list)
        {
            return true;
        }
        Math::Vector3D *location;
        Math::Vector3D *color;
        double intensity;


    protected:
    private:
};

