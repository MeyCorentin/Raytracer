/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PTransformation
*/

#ifndef PTRANSFORMATION_HPP_
#define PTRANSFORMATION_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <libconfig.h++>

class PTransformation {
        private:
            const libconfig::Config& _cfg;
            const std::string transfo = "transformations";
            const std::string trans = transfo + ".translation";
            const std::string rot = transfo + ".rotation";

            struct Translation {
                double x, y, z;
            } _trans;
            struct Rot {
                double x, y, z;
            } _rot;
        public:
            PTransformation(const libconfig::Config& cfg): _cfg(cfg)
            {
                _trans.x = _cfg.lookup(trans + ".x");
                _trans.y = _cfg.lookup(trans + ".y");
                _trans.z = _cfg.lookup(trans + ".z");
                _rot.x = _cfg.lookup(rot + ".x");
                _rot.y = _cfg.lookup(rot + ".y");
                _rot.z = _cfg.lookup(rot + ".z");
            }
            Translation getTranslation()const{return _trans;}
            Rot getRotation()const{return _rot;}
};

#endif /* !PTRANSFORMATION_HPP_ */
