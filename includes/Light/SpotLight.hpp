/*
** EPITECH PROJECT, 2023
** SpotLight
** File description:
** SpotLight
*/


#pragma once
#include "interface/ILight.hpp"
#include "Scene/Scene.hpp"

class Slight: public ILight {
    public:
        Slight();
        ~Slight();

        bool computeLight(
            Scene &scene,
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

