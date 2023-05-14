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
#include "Scene/Scene.hpp"

class DataMaterial {

};

class MaterialFactory {

};

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
            void setMetal(const std::string name, Scene *scene);
            void setMate(const std::string name, Scene *scene);
        public:
            void setMaterial(const std::string name, Scene *scene)
            {
                if ((const std::string)_cfg.lookup(mat + "." + name + ".type") == "mate") setMate(name, scene);
                if ((const std::string)_cfg.lookup(mat + "." + name + ".type") == "metal") setMetal(name, scene);
            }
            PMaterial(const libconfig::Config& cfg): _cfg(cfg){}

};

#endif /* !PMATERIAL_HPP_ */
