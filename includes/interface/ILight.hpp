/*
** EPITECH PROJECT, 2023
** ILight
** File description:
** ILight
*/

#pragma once
#include "IObject.hpp"
class ILight {
    public:
        ~ILight() = default;
        virtual bool computeLight(
                hit_record &temp_rec,
                const std::shared_ptr<IObject>& object,
                std::vector<std::shared_ptr<IObject>> object_list) = 0;

    protected:
    private:
};

