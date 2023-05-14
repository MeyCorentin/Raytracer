/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** FMaterial
*/

#include "DataMaterial.hpp"
#include <libconfig.h++>
#include "Scene/Scene.hpp"

class FMaterial {
    protected:
        DataMaterial data;
        const libconfig::Config& _cfg;
    private:
        void createMetal(const std::string name, Scene *scene);
        void createMate(const std::string name, Scene *scene);
        void setMaterial(const std::string name, Scene *scene)
        {
            if ((const std::string)_cfg.lookup(data.mat + "." + name + ".type") == "mate") createMate(name, scene);
            if ((const std::string)_cfg.lookup(data.mat + "." + name + ".type") == "metal") createMetal(name, scene);
        }
    public:
        FMaterial(const libconfig::Config& cfg, const std::string name, Scene *scene): _cfg(cfg)
        {
            setMaterial(name, scene);
        }
};