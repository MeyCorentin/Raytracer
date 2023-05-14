/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** FDecorator
*/

#include "DataDecorator.hpp"
#include <libconfig.h++>
#include "Scene/Scene.hpp"

class FDecorator {
    protected:
        DataDecorator data;
        const libconfig::Config& _cfg;
    private:
        void setTranslation(const std::string name, Scene *scene);
        void setRotation(const std::string name, Scene *scene);
    public:
        FDecorator(const libconfig::Config& cfg, const std::string name, Scene *scene): _cfg(cfg)
        {
            setRotation(name, scene);
            setTranslation(name, scene);
        }

};