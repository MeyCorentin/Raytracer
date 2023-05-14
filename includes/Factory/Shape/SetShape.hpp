/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SetShape
*/

#ifndef SETSHAPE_HPP_
#define SETSHAPE_HPP_

#include "FShape.hpp"
#include <libconfig.h++>
#include "Scene/Scene.hpp"
#include "Scene/SceneBuilder.hpp"

class SetShape {
        protected:
            SceneBuilder *_sceneBuilder;
            Scene *_scene;
            const libconfig::Config& _cfg;
        private:
            void addShape()
            {
                FShape<Sphere> sphereShape(_cfg, _sceneBuilder, _scene);
                FShape<Cone> coneShape(_cfg, _sceneBuilder, _scene);
                FShape<Plane> planeShape(_cfg, _sceneBuilder, _scene);
                FShape<Cylinder> cylinderShape(_cfg, _sceneBuilder, _scene);
            }
        public:

            SetShape(const libconfig::Config& cfg, SceneBuilder *sceneBuilder, Scene *scene): _cfg(cfg)
            {
                _sceneBuilder = sceneBuilder;
                _scene = scene;
                addShape();
            }
};

#endif /* !SETSHAPE_HPP_ */
