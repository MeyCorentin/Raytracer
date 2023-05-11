/*
** EPITECH PROJECT, 2023
** SpotLight
** File description:
** SpotLight
*/


#pragma once
#include "interface/ILight.hpp"

class Slight: public ILight {
    //Spot Light
    public:
        Slight();
        ~Slight();

        bool computeLight(hit_record &temp_rec, const std::shared_ptr<IObject>& object, std::vector<std::shared_ptr<IObject>> object_list)
        {

        }
    protected:
    private:
};

