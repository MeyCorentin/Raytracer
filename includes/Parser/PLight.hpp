/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PLight
*/

#ifndef PLIGHT_HPP_
#define PLIGHT_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <libconfig.h++>
#include "Scene/SceneBuilder.hpp"
#include "Light/DirectionalLight.hpp"
#include "Light/AmbientLight.hpp"

class DataLights {

};

class LightFactory {

};

class PLight {
        private:
            const libconfig::Config& _cfg;
            const std::string li = "lights";
            const std::string ambient = li + ".ambient";
            const std::string point = li + ".point";
            const std::string direction = li + ".directional";
            SceneBuilder *_sceneBuilder;

            struct MyPoint {
                double x, y, z;
            } myPoint;
            std::vector<MyPoint> vec_point;
            struct MyDirection {
                double x, y, z;
                double r, g, b;
                double i;
            } myDirection;
            std::vector<MyDirection> vec_direction;
            struct Ambient {
                double r, g, b, i;
            } myAmbient;
            void createDirectionals();
            void createAmbient();
            void addLights();
        public:
            PLight(const libconfig::Config& cfg, SceneBuilder *sceneBuilder): _cfg(cfg)
            {
                _sceneBuilder = sceneBuilder;
                createDirectionals();
                createAmbient();
                addLights();
            };
            std::vector<MyPoint> getPoints() const {return vec_point;}
            std::vector<MyDirection> getDirections() const {return vec_direction;}
            Ambient getAmbient()const{return myAmbient;}
};

#endif /* !PLIGHT_HPP_ */
