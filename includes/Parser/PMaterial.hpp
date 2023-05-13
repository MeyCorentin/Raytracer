/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PMaterial
*/

#ifndef PMATERIAL_HPP_
#define PMATERIAL_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <libconfig.h++>
#include "Materials/Material.hpp"
#include "Materials/Mate.hpp"
#include "Materials/Metal.hpp"

class PMaterial {
        private:
            const libconfig::Config& _cfg;
            const std::string mat = "materials";

            struct MyMate {
                double r, g, b;
            } _mate;
            struct MyMetal {
                double r, g, b;
            } _metal;
            void setMetal(const std::string name, Scene *scene)
            {
                _metal.r = _cfg.lookup(mat + "." + name + ".r");
                _metal.g = _cfg.lookup(mat + "." + name + ".g");
                _metal.b = _cfg.lookup(mat + "." + name + ".b");
                scene->material_list.insert(std::pair<const std::string, std::shared_ptr<Material>>(name, std::make_shared<Metal>(Math::Vector3D(_metal.r, _metal.g, _metal.b))));
            }
            void setMate(const std::string name, Scene *scene)
            {
                _mate.r = _cfg.lookup(mat + "." + name + ".r");
                _mate.g = _cfg.lookup(mat + "." + name + ".g");
                _mate.b = _cfg.lookup(mat + "." + name + ".b");
                scene->material_list.insert(std::pair<const std::string, std::shared_ptr<Material>>(name, std::make_shared<Mate>(Math::Vector3D(_mate.r, _mate.g, _mate.b))));
            }
        public:
            void setMaterial(const std::string name, Scene *scene)
            {
                if ((const std::string)_cfg.lookup(mat + "." + name + ".type") == "mate") setMate(name, scene);
                if ((const std::string)_cfg.lookup(mat + "." + name + ".type") == "metal") setMetal(name, scene);
            }
            PMaterial(const libconfig::Config& cfg): _cfg(cfg){}

};

#endif /* !PMATERIAL_HPP_ */
