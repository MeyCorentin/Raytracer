/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CreateCamera
*/

#include "../includes/Parser/PCamera.hpp"

void PCamera::SettingsCamera()
{
    _res.width = _cfg.lookup(res + ".width");
    _res.height = _cfg.lookup(res + ".height");
    _ratio.value = (double)_cfg.lookup(ratio + ".value") / (double)_cfg.lookup(ratio + ".divider");
    _depth.value = _cfg.lookup(cam + ".depth");
    _anti.value = _cfg.lookup(cam + ".antialisaing");
    _fov.value = _cfg.lookup(cam + ".fieldOfView");
}

void PCamera::SetCamera(Camera *cam, Rectangle3D *rect, Math::Point3D *origin, Math::Point3D *horizontal, Math::Point3D *vertical)
{
    _sceneBuilder->createNewScene();
    _sceneBuilder->setCamera(_res.width, _ratio.value, _fov.value, _anti.value, _depth.value, cam, rect, origin, horizontal, vertical);
}