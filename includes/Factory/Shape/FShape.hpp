/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** FShape
*/

#ifndef FSHAPE_HPP_
#define FSHAPE_HPP_

#include "DataShape.hpp"
#include <libconfig.h++>
#include "Scene/Scene.hpp"
#include "Objects/Shapes/Cylinder.hpp"
#include "Objects/Shapes/Sphere.hpp"
#include "Objects/Shapes/Plane.hpp"
#include "Objects/Shapes/Cone.hpp"
#include "Objects/Shapes/Plane.hpp"
#include "Scene/SceneBuilder.hpp"

template <class T>
class FShape {
    protected:
        SceneBuilder *_sceneBuilder;
        Scene *_scene;
        const libconfig::Config& _cfg;
        DataShape data;
    private:
        Math::Vector3D tV, rV;
        Math::Point3D *oV;
        void createSpheres();
        void createCones();
        void createCylinders();
        void createPlanes();
        void addSpheres();
        void addCones();
        void addPlanes();
        void addCylinders();
        void createShape()
        {
            if (std::is_same<T, Sphere>::value) createSpheres(), addSpheres();
            if (std::is_same<T, Cone>::value) createCones(), addCones();
            if (std::is_same<T, Plane>::value) createPlanes(), addPlanes();
            if (std::is_same<T, Cylinder>::value) createCylinders(), addCylinders();
        }
    public:
        FShape(const libconfig::Config& cfg, SceneBuilder *sceneBuilder, Scene *scene): _cfg(cfg)
        {
            _sceneBuilder = sceneBuilder, _scene = scene;
            createShape();
        }
};

#endif /* !FSHAPE_HPP_ */
