/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CreateLights
*/

#include "../includes/Factory/Lights/FLights.hpp"

void FLight::createDirectionals()
{
    for (libconfig::SettingIterator it = _cfg.lookup(data.direction).begin();it != _cfg.lookup(data.direction).end();it++, data.vec_direction.emplace_back(data.myDirection)) {
        data.myDirection.x = (*it).lookup(".direction.x"), data.myDirection.y = (*it).lookup(".direction.y"), data.myDirection.z = (*it).lookup(".direction.z");
        data.myDirection.r = (*it).lookup(".color.r"), data.myDirection.g = (*it).lookup(".color.g"), data.myDirection.b = (*it).lookup(".color.b");
        data.myDirection.i = (*it).lookup(".i");
    }
}

void FLight::createAmbient()
{
    data.myAmbient.r = _cfg.lookup(data.ambient + ".r");
    data.myAmbient.g = _cfg.lookup(data.ambient + ".g");
    data.myAmbient.b = _cfg.lookup(data.ambient + ".b");
    data.myAmbient.i = _cfg.lookup(data.ambient + ".i");
}

void FLight::addLights()
{
    for (size_t i = 0; i < data.vec_direction.size(); i++)
        _sceneBuilder->add_light(DLight(new Math::Vector3D(data.vec_direction[i].x, data.vec_direction[i].y, data.vec_direction[i].z), Math::Vector3D(data.vec_direction[i].r, data.vec_direction[i].g, data.vec_direction[i].b), data.vec_direction[i].i));
    _sceneBuilder->add_light(ALight(Math::Vector3D(data.myAmbient.r, data.myAmbient.g, data.myAmbient.b), data.myAmbient.i));
}
