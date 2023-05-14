/*
** EPITECH PROJECT, 2023
** raytracer.cpp
** File description:
** CreateMaterial
*/

#include "../includes/Parser/PMaterial.hpp"

void PMaterial::setMetal(const std::string name, Scene *scene)
{
    _metal.r = _cfg.lookup(mat + "." + name + ".r");
    _metal.g = _cfg.lookup(mat + "." + name + ".g");
    _metal.b = _cfg.lookup(mat + "." + name + ".b");
    scene->material_list.insert(std::pair<const std::string, std::shared_ptr<Material>>(name, std::make_shared<Metal>(Math::Vector3D(_metal.r, _metal.g, _metal.b))));
}

void PMaterial::setMate(const std::string name, Scene *scene)
{
    _mate.r = _cfg.lookup(mat + "." + name + ".r");
    _mate.g = _cfg.lookup(mat + "." + name + ".g");
    _mate.b = _cfg.lookup(mat + "." + name + ".b");
    scene->material_list.insert(std::pair<const std::string, std::shared_ptr<Material>>(name, std::make_shared<Mate>(Math::Vector3D(_mate.r, _mate.g, _mate.b))));
}
