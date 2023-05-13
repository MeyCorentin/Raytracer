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
#include <type_traits>
#include <cstdint>
#include "PMaterial.hpp"

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
            struct MySphere {
                double x, y, z, ra;
                std::string mat;
            } mySphere;
            std::vector<MySphere> vec_spheres;
            struct MyCone {
                double x, y, z, ra, h;
                std::string mat;
            } myCone;
            std::vector<MyCone> vec_cones;
            struct MyCylinder {
                double x, y, z, ra, h;
                std::string mat;
            } myCylinder;
            std::vector<MyCylinder> vec_cylinders;
            struct MyPlane {
                double vx,vy,vz;
                double px,py,pz;
                std::string mat;
            } myPlane;
            std::vector<MyPlane> vec_planes;
            void addSpheres();
            void addCones();
            void addPlanes();
            void addCylinders();
            void createSpheres(const libconfig::Config& cfg, PMaterial *pmaterial, Scene *scene);
            void createCones(const libconfig::Config& cfg, PMaterial *pmaterial, Scene *scene);
            void createCylinders(const libconfig::Config& cfg, PMaterial *pmaterial, Scene *scene);
            void createPlanes(const libconfig::Config& cfg, PMaterial *pmaterial, Scene *scene);
        public:

            PShape(const libconfig::Config& cfg, SceneBuilder *sceneBuilder, Scene *scene): _cfg(cfg)
            {
                _sceneBuilder = sceneBuilder;
                _pmaterial = new PMaterial(cfg);
                _scene = scene;
                createSpheres(cfg, _pmaterial, scene);
                createCones(cfg, _pmaterial, scene);
                createCylinders(cfg, _pmaterial, scene);
                createPlanes(cfg, _pmaterial, scene);
            }

            template<class T>
            void addShape()
            {
                if (std::is_same<T, Sphere>::value) addSpheres();
                if (std::is_same<T, Cone>::value) addCones();
                if (std::is_same<T, Plane>::value) addPlanes();
            }
            std::vector<MySphere> getSpheres() const{return vec_spheres;}
            std::vector<MyCone> getCones() const{return vec_cones;}
            std::vector<MyCylinder> getCylinders() const{return vec_cylinders;}
            std::vector<MyPlane> getPlanes() const{return vec_planes;}
};
#endif /* !PSHAPE_HPP_ */
