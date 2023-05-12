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
#include "Camera/Camera.hpp"

class PCamera {
        protected:
            SceneBuilder *sceneBuilder;
        private:
            const libconfig::Config& _cfg;
            const std::string cam = "camera";
            const std::string pos = cam + ".position";
            const std::string res = cam + ".resolution";
            const std::string rot = cam + ".rotation";
            struct Res {
                int width, height;
            } _res;
            struct Pos {
                double x, y, z;
            } _pos;
            struct Rot {
                double x, y, z;
            } _rot;
            struct FieldOfView {
                double value;
            } _fov;
        public:
            void SettingsCamera(const libconfig::Config& cfg);
            void CreateCamera();
            PCamera(const libconfig::Config& cfg): _cfg(cfg)
            {
                SettingsCamera(cfg);
                CreateCamera();
            }
            Res getResolution()const{return _res;}
            Pos getPosition()const{return _pos;}
            Rot getRotation()const{return _rot;}

            FieldOfView getFOV()const{return _fov;}
    };

#endif /* !PCAMERA_HPP_ */
