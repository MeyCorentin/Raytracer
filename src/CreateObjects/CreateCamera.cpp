/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CreateCamera
*/

#include "../includes/Factory/PCamera.hpp"

void PCamera::SettingsCamera()
{
    data._res.width = _cfg.lookup(data.res + ".width");
    data._res.height = _cfg.lookup(data.res + ".height");
    data._ratio.value = (double)_cfg.lookup(data.ratio + ".value") / (double)_cfg.lookup(data.ratio + ".divider");
    data._depth.value = _cfg.lookup(data.cam + ".depth");
    data._anti.value = _cfg.lookup(data.cam + ".antialisaing");
    data._fov.value = _cfg.lookup(data.cam + ".fieldOfView");
}

void PCamera::SetCamera(Camera *cam, Rectangle3D *rect, Math::Point3D *origin, Math::Point3D *horizontal, Math::Point3D *vertical)
{
    _sceneBuilder->createNewScene();
    _sceneBuilder->setCamera(data._res.width, data._ratio.value, data._fov.value, data._anti.value, data._depth.value, cam, rect, origin, horizontal, vertical);
}