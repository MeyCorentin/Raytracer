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

class PShape {
        protected:
            SceneBuilder *_sceneBuilder;
            PMaterial *_pmaterial;
            Scene *_scene;
        private:
            const libconfig::Config& _cfg;
            const std::string prim = "primitives";
            const std::string spheres = prim + ".spheres";
            const std::string planes = prim + ".planes";
            const std::string cones = prim + ".cones";
            const std::string cylinder = prim + ".cylinders";
            Math::Vector3D tV, rV;
            Math::Point3D *oV;
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
                double x, y, z, ra, h;
                std::string mat, rot, trans;
            } myCylinder;
            std::vector<MyCylinder> vec_cylinders;
            struct MyPlane {
                double vx,vy,vz;
                double px,py,pz;
                std::string mat, rot, trans;
            } myPlane;
            std::vector<MyPlane> vec_planes;
            void addSpheres();
            void addCones();
            void addPlanes();
            void addCylinders();
            void createSpheres(const libconfig::Config& cfg, PMaterial *pmaterial, PDecorator *decorator, Scene *scene);
            void createCones(const libconfig::Config& cfg, PMaterial *pmaterial, PDecorator *decorator, Scene *scene);
            void createCylinders(const libconfig::Config& cfg, PMaterial *pmaterial, PDecorator *decorator, Scene *scene);
            void createPlanes(const libconfig::Config& cfg, PMaterial *pmaterial, PDecorator *decorator, Scene *scene);
            template<class T>
            void addShape()
            {
                if (std::is_same<T, Sphere>::value) addSpheres();
                if (std::is_same<T, Cone>::value) addCones();
                if (std::is_same<T, Plane>::value) addPlanes();
            }
        public:

            PShape(const libconfig::Config& cfg, SceneBuilder *sceneBuilder, PDecorator *decorator, Scene *scene): _cfg(cfg)
            {
                _sceneBuilder = sceneBuilder;
                _pmaterial = new PMaterial(cfg);
                _scene = scene;
                createSpheres(cfg, _pmaterial, decorator, scene);
                createCones(cfg, _pmaterial, decorator, scene);
                createCylinders(cfg, _pmaterial, decorator, scene);
                createPlanes(cfg, _pmaterial, decorator, scene);
                addShape<Sphere>();
                addShape<Cone>();
                addShape<Plane>();
                addShape<Cylinder>();

            }

            std::vector<MySphere> getSpheres() const{return vec_spheres;}
            std::vector<MyCone> getCones() const{return vec_cones;}
            std::vector<MyCylinder> getCylinders() const{return vec_cylinders;}
            std::vector<MyPlane> getPlanes() const{return vec_planes;}
};
#endif /* !PSHAPE_HPP_ */
