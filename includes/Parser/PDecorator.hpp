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
#include "Objects/ObjectDecorator/Translate.hpp"
#include "Objects/ObjectDecorator/Rotate.hpp"

class PDecorator{
        protected:
        private:
            const libconfig::Config& _cfg;
            const std::string transfo = "transformations";

            struct Translation {
                double x, y, z;
            } _trans;
            struct Rot {
                double x, y, z;
            } _rot;

            template<class T>
            void setTranslation(const std::string name, Scene *scene)
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
            template<class T>
            void setRotation(const std::string name, Scene *scene)
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
        public:
            template<class T>
            void setDecorator(const std::string name, Scene *scene)
            {
                setRotation<T>(name, scene);
                setTranslation<T>(name, scene);
            }
            PDecorator(const libconfig::Config& cfg): _cfg(cfg){}
            Translation getTranslation()const{return _trans;}
            Rot getRotation()const{return _rot;}
};

#endif /* !PTRANSFORMATION_HPP_ */
