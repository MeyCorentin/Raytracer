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
#include "Scene/Scene.hpp"



template <class T>
class DecoratorFactory {

};

class PDecorator {
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
            void setTranslation(const std::string name, Scene *scene);
            void setRotation(const std::string name, Scene *scene);
        public:
            void setDecorator(const std::string name, Scene *scene)
            {
                setRotation(name, scene);
                setTranslation(name, scene);
            }
            PDecorator(const libconfig::Config& cfg): _cfg(cfg){}
            Translation getTranslation()const{return _trans;}
            Rot getRotation()const{return _rot;}
};

#endif /* !PTRANSFORMATION_HPP_ */
