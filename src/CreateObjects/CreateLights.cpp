/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CreateLights
*/

#include "../includes/Parser/PLight.hpp"

void PLight::createDirectionals()
{
    for (libconfig::SettingIterator it = _cfg.lookup(direction).begin();it != _cfg.lookup(direction).end();it++, vec_direction.emplace_back(myDirection)) {
        myDirection.x = (*it).lookup(".direction.x"), myDirection.y = (*it).lookup(".direction.y"), myDirection.z = (*it).lookup(".direction.z");
        myDirection.r = (*it).lookup(".color.r"), myDirection.g = (*it).lookup(".color.g"), myDirection.b = (*it).lookup(".color.b");
        myDirection.i = (*it).lookup(".i");
    }
}

void PLight::createAmbient()
{
    myAmbient.r = _cfg.lookup(ambient + ".r");
    myAmbient.g = _cfg.lookup(ambient + ".g");
    myAmbient.b = _cfg.lookup(ambient + ".b");
    myAmbient.i = _cfg.lookup(ambient + ".i");
}

void PLight::addLights()
{
    for (size_t i = 0; i < vec_direction.size(); i++)
        _sceneBuilder->add_light(DLight(new Math::Vector3D(vec_direction[i].x, vec_direction[i].y, vec_direction[i].z), Math::Vector3D(vec_direction[i].r, vec_direction[i].g, vec_direction[i].b), vec_direction[i].i));
    _sceneBuilder->add_light(ALight(Math::Vector3D(myAmbient.r, myAmbient.g, myAmbient.b), myAmbient.i));
}
