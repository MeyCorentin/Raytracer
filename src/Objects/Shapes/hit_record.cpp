/*
** EPITECH PROJECT, 2023
** hit_record
** File description:
** hit_record
*/


#include "Objects/Shapes/hit_record.hpp"
#include "Materials/Metal.hpp"
#include "Materials/Mate.hpp"

hit_record::~hit_record()
{
};

hit_record::hit_record() {
    light_result = Math::Point3D(0.0, 0.0, 0.0);
};
