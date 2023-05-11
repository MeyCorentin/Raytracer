/*
** EPITECH PROJECT, 2023
** PointLight
** File description:
** PointLight
*/


#pragma once
#include "Scene/Scene.hpp"
#include "interface/ILight.hpp"
class PLight: public ILight {
    public:
        PLight();
        ~PLight();

        bool computeLight(
            Scene scene,
            const Ray& r,
            hit_record &temp_rec,
            const std::shared_ptr<IObject>& object,
            std::vector<std::shared_ptr<IObject>> object_list
            )
        {
            return true;
        }
    protected:
    private:
};

