/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PShape
*/

#ifndef PSHAPE_HPP_
#define PSHAPE_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <libconfig.h++>
#include "../Math/Point3D.hpp"
#include "Scene/SceneBuilder.hpp"
#include "Objects/Shapes/Sphere.hpp"
#include "Objects/Shapes/Cone.hpp"
#include "Objects/Shapes/Plane.hpp"
#include "Objects/Shapes/Cylinder.hpp"
#include <type_traits>
#include <cstdint>
#include "PMaterial.hpp"
#include "PDecorator.hpp"


class ShapeData {
    public:
        struct MySphere {
            double x, y, z, ra;
            std::string mat, rot, trans;
        } mySphere;
        std::vector<MySphere> vec_spheres;
        struct MyCone {
            double x, y, z, ra, h;
            std::string mat, rot, trans;
        } myCone;
        std::vector<MyCone> vec_cones;
        struct MyCylinder {
            double x, y, z, ra;
            std::string mat, rot, trans;
        } myCylinder;
        std::vector<MyCylinder> vec_cylinders;
        struct MyPlane {
            double vx,vy,vz;
            double px,py,pz;
            std::string mat, rot, trans;
        } myPlane;
        std::vector<MyPlane> vec_planes;
        const std::string prim = "primitives";
        const std::string spheres = prim + ".spheres";
        const std::string planes = prim + ".planes";
        const std::string cones = prim + ".cones";
        const std::string cylinder = prim + ".cylinders";
};

template <class T>
class ShapeFactory {
    protected:
        SceneBuilder *_sceneBuilder;
        PMaterial *_pmaterial;
        Scene *_scene;
        PDecorator *_decorator;
        const libconfig::Config& _cfg;
        ShapeData data;
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
        ShapeFactory(const libconfig::Config& cfg, SceneBuilder *sceneBuilder, PDecorator *decorator, Scene *scene): _cfg(cfg)
        {
            _pmaterial = new PMaterial(cfg);
            _sceneBuilder = sceneBuilder, _decorator = decorator, _scene = scene;
            createShape();
        }
};

class PShape {
        protected:
            SceneBuilder *_sceneBuilder;
            PMaterial *_pmaterial;
            Scene *_scene;
            PDecorator *_decorator;
            const libconfig::Config& _cfg;
        private:
            void addShape()
            {
                ShapeFactory<Sphere> sphereShape(_cfg, _sceneBuilder, _decorator, _scene);
                ShapeFactory<Cone> coneShape(_cfg, _sceneBuilder, _decorator, _scene);
                ShapeFactory<Plane> planeShape(_cfg, _sceneBuilder, _decorator, _scene);
                ShapeFactory<Cylinder> cylinderShape(_cfg, _sceneBuilder, _decorator, _scene);
            }
        public:

            PShape(const libconfig::Config& cfg, SceneBuilder *sceneBuilder, PDecorator *decorator, Scene *scene): _cfg(cfg)
            {
                _sceneBuilder = sceneBuilder;
                _scene = scene;
                _decorator = decorator;
                addShape();
            }
};
#endif /* !PSHAPE_HPP_ */
