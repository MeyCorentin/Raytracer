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
#include "Objects/Transforms/Translate.hpp"
#include "Parser/PShape.hpp"

class PTransformation {
        protected:
            SceneBuilder *_sceneBuilder;
            PShape *_pshape;
            Scene *_scene;

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
            void setTranslation()
            {
                _trans.x = _cfg.lookup(trans + ".x");
                _trans.y = _cfg.lookup(trans + ".y");
                _trans.z = _cfg.lookup(trans + ".z");
            }
            void setRotation()
            {
                _rot.x = _cfg.lookup(rot + ".x");
                _rot.y = _cfg.lookup(rot + ".y");
                _rot.z = _cfg.lookup(rot + ".z");
            }
            void SpTransfo()
            {
                _sceneBuilder->add_object(Translate(Sphere(new Math::Point3D(_pshape->getSpheres()[0].x, _pshape->getSpheres()[0].y, _pshape->getSpheres()[0].z), _pshape->getSpheres()[0].ra, _scene->material_list[_pshape->getSpheres()[0].mat]), Math::Vector3D(_trans.x, _trans.y, _trans.z)));
            }
            void CoTransfo()
            {
                _sceneBuilder->add_object(Translate(Cone(new Math::Point3D(_pshape->getCones()[0].x, _pshape->getCones()[0].y, _pshape->getCones()[0].z), _pshape->getCones()[0].ra, _scene->material_list[_pshape->getCones()[0].mat]), Math::Vector3D(_trans.x, _trans.y, _trans.z)));
            }
            void PlTransfo()
            {
                // _sceneBuilder->add_object(Translate(Plane(new Math::Point3D(_pshape->getPlanes()[0].x, _pshape->getPlanes()[0].y, _pshape->getPlanes()[0].z), _pshape->getPlanes()[0].ra, _scene->material_list[_pshape->getPlanes()[0].mat]), Math::Vector3D(_trans.x, _trans.y, _trans.z)));
            }
        public:
            PTransformation(const libconfig::Config& cfg, SceneBuilder *sceneBuilder, PShape *pshape, Scene *scene): _cfg(cfg)
            {
                _scene = scene;
                _sceneBuilder = sceneBuilder;
                _pshape = pshape;
                setTranslation();
                setRotation();
            }

            template <class T>
            void addTranslation()
            {
                if (std::is_same<T, Sphere>::value) SpTransfo();
                if (std::is_same<T, Cone>::value) CoTransfo();
                if (std::is_same<T, Plane>::value) PlTransfo();
                // sceneBuilder->add_object(Translate(Sphere(new Math::Point3D(0.0, 0.0, 0.0), 0.5, mate), Math::Vector3D(0,0,-2)));
            }
            Translation getTranslation()const{return _trans;}
            Rot getRotation()const{return _rot;}
};

#endif /* !PTRANSFORMATION_HPP_ */
