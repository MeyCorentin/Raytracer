/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** CreateDecorator
*/


#include "../includes/Factory/Decorator/FDecorator.hpp"


void FDecorator::setTranslation(const std::string name, Scene *scene)
{
    if (name.compare("none") == 0) {
        data._trans.x = 0;
        data._trans.y = 0;
        data._trans.z = 0;
    } else {
        data._trans.x = _cfg.lookup(data.transfo + "." + name + ".x");
        data._trans.y = _cfg.lookup(data.transfo + "." + name + ".y");
        data._trans.z = _cfg.lookup(data.transfo + "." + name + ".z");
    }
    Math::Vector3D mV = Math::Vector3D(data._trans.x, data._trans.y, data._trans.z);
    scene->decorator_list.insert(std::pair<const std::string, Math::Vector3D>(name, mV));
}

void FDecorator::setRotation(const std::string name, Scene *scene)
{
    if (name.compare("none") == 0) {
        data._rot.x = 0;
        data._rot.y = 0;
        data._rot.z = 0;
    } else {
        data._rot.x = _cfg.lookup(data.transfo + "." + name + ".x");
        data._rot.y = _cfg.lookup(data.transfo + "." + name + ".y");
        data._rot.z = _cfg.lookup(data.transfo + "." + name + ".z");
    }
    Math::Vector3D mV = Math::Vector3D(data._rot.x, data._rot.y, data._rot.z);
    scene->decorator_list.insert(std::pair<const std::string, Math::Vector3D>(name, mV));
}
