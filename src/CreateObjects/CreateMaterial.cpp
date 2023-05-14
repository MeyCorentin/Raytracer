/*
** EPITECH PROJECT, 2023
** raytracer.cpp
** File description:
** CreateMaterial
*/

#include "../includes/Factory/Material/FMaterial.hpp"

void FMaterial::createMetal(const std::string name, Scene *scene)
{
    data._metal.r = _cfg.lookup(data.mat + "." + name + ".r");
    data._metal.g = _cfg.lookup(data.mat + "." + name + ".g");
    data._metal.b = _cfg.lookup(data.mat + "." + name + ".b");
    Math::Vector3D mV = Math::Vector3D(data._metal.r, data._metal.g, data._metal.b);
    scene->material_list.insert(std::pair<const std::string, std::shared_ptr<Material>>(name, std::make_shared<Metal>(mV)));
}

void FMaterial::createMate(const std::string name, Scene *scene)
{
    data._mate.r = _cfg.lookup(data.mat + "." + name + ".r");
    data._mate.g = _cfg.lookup(data.mat + "." + name + ".g");
    data._mate.b = _cfg.lookup(data.mat + "." + name + ".b");
    Math::Vector3D mV = Math::Vector3D(data._mate.r, data._mate.g, data._mate.b);
    scene->material_list.insert(std::pair<const std::string, std::shared_ptr<Material>>(name, std::make_shared<Mate>(mV)));
}
