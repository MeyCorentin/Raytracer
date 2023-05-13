/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PCamera
*/

#ifndef PCAMERA_HPP_
#define PCAMERA_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <libconfig.h++>
#include "Scene/SceneBuilder.hpp"
#include "Objects/Shapes/Rectangle3D.hpp"

class PCamera {
        protected:
            SceneBuilder *_sceneBuilder;
        private:
            const libconfig::Config& _cfg;
            const std::string cam = "camera";
            const std::string res = cam + ".resolution";
            const std::string ratio = cam + ".ratio";
            struct Res {
                int width, height;
            } _res;
            struct Antialisaing {
                int value;
            } _anti;
            struct Ratio {
                double value;
            } _ratio;
            struct Depth {
                int value;
            } _depth;
            struct FieldOfView {
                double value;
            } _fov;
            void SettingsCamera();
            void CreateCamera(Camera*, Rectangle3D*, Math::Point3D*, Math::Point3D*, Math::Point3D*);
        public:
            PCamera(const libconfig::Config& cfg, SceneBuilder *sceneBuilder, Camera *cam, Rectangle3D *rect, Math::Point3D *origin, Math::Point3D *horizontal, Math::Point3D *vertical): _cfg(cfg)
            {
                _sceneBuilder = sceneBuilder;
                SettingsCamera();
                CreateCamera(cam, rect, origin, horizontal, vertical);
            }
            Res getResolution()const{return _res;}
            Antialisaing getAntialisaing()const{return _anti;}
            Ratio getRation()const{return _ratio;}
            Depth getDepth()const{return _depth;}

            FieldOfView getFOV()const{return _fov;}
    };

#endif /* !PCAMERA_HPP_ */
