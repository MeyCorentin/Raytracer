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

class DataCamera {
    public:
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
};

class PCamera {
        protected:
            SceneBuilder *_sceneBuilder;
            DataCamera data;
        private:
            const libconfig::Config& _cfg;
            void SettingsCamera();
            void SetCamera(Camera*, Rectangle3D*, Math::Point3D*, Math::Point3D*, Math::Point3D*);
        public:
            PCamera(const libconfig::Config& cfg, SceneBuilder *sceneBuilder, Camera *cam, Rectangle3D *rect, Math::Point3D *origin, Math::Point3D *horizontal, Math::Point3D *vertical): _cfg(cfg)
            {
                _sceneBuilder = sceneBuilder;
                SettingsCamera();
                SetCamera(cam, rect, origin, horizontal, vertical);
            }
    };

#endif /* !PCAMERA_HPP_ */
