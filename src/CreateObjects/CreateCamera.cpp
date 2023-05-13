/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CreateCamera
*/

#include "../includes/Parser/PCamera.hpp"

void PCamera::SettingsCamera(const libconfig::Config& cfg)
{
    _res.width = _cfg.lookup(res + ".width");
    _res.height = _cfg.lookup(res + ".height");
    _rot.x = _cfg.lookup(rot + ".x");
    _rot.y = _cfg.lookup(rot + ".y");
    _rot.z = _cfg.lookup(rot + ".z");

    _pos.x = _cfg.lookup(pos + ".x");
    _pos.y = _cfg.lookup(pos + ".y");
    _pos.z = _cfg.lookup(pos + ".z");
    _fov.value = _cfg.lookup(cam + ".fieldOfView");
}

void PCamera::CreateCamera()
{
    // sceneBuilder->setCamera(_res.width, _res.height, (16.0 / 9.0), 2.0);
}