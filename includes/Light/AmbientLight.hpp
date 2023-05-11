/*
** EPITECH PROJECT, 2023
** AmbientLight
** File description:
** AmbientLight
*/


#pragma once
#include "interface/ILight.hpp"

class ALight: public ILight {
    //Ambient Light
    public:
        ALight();
        ~ALight();
        bool computeLight(hit_record &temp_rec, const std::shared_ptr<IObject>& object, std::vector<std::shared_ptr<IObject>> object_list)
        {
            return true;
        }
    protected:
    private:
};

