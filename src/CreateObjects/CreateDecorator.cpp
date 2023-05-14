/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CreateDecorator
*/


#include "../includes/Parser/PDecorator.hpp"


void PDecorator::setTranslation(const std::string name, Scene *scene)
{
    if (name.compare("none") == 0) {
        _trans.x = 0;
        _trans.y = 0;
        _trans.z = 0;
    } else {
        _trans.x = _cfg.lookup(transfo + "." + name + ".x");
        _trans.y = _cfg.lookup(transfo + "." + name + ".y");
        _trans.z = _cfg.lookup(transfo + "." + name + ".z");
    }
    scene->decorator_list.insert(std::pair<const std::string, Math::Vector3D>(name, Math::Vector3D(_rot.x, _rot.y, _rot.z)));
}

void PDecorator::setRotation(const std::string name, Scene *scene)
{
    if (name.compare("none") == 0) {
        _rot.x = 0;
        _rot.y = 0;
        _rot.z = 0;
    } else {
        _rot.x = _cfg.lookup(transfo + "." + name + ".x");
        _rot.y = _cfg.lookup(transfo + "." + name + ".y");
        _rot.z = _cfg.lookup(transfo + "." + name + ".z");
    }
    scene->decorator_list.insert(std::pair<const std::string, Math::Vector3D>(name, Math::Vector3D(_rot.x, _rot.y, _rot.z)));
}
