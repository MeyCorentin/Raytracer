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
#include "../interface/ILight.hpp"

class PLight : public ILight {
        private:
            const libconfig::Config& _cfg;
            const std::string li = "lights";
            const std::string ambient = li + ".ambient";
            const std::string diffuse = li + ".diffuse";
            const std::string point = li + ".point";
            const std::string directional = li + ".directional";
            struct MyPoint {
                double x, y, z;
            } myPoint;
            std::vector<MyPoint> vec_point;
            struct MyDirection {
                double vector;
                double size;
            } myDirection;
            std::vector<MyDirection> vec_direction;
            struct Ambient {
                double value;
            } _ambient;
            struct Diffuse {
                double value;
            } _diffuse;
        public:
            PLight(const libconfig::Config& cfg): _cfg(cfg)
            {
                _ambient.value = _cfg.lookup(ambient);
                _diffuse.value = _cfg.lookup(diffuse);
                for (libconfig::SettingIterator it = _cfg.lookup(point).begin();it != _cfg.lookup(point).end();it++, vec_point.emplace_back(myPoint))
                    myPoint.x = (*it).lookup(".x"), myPoint.y = (*it).lookup(".y"), myPoint.z = (*it).lookup(".z");
            };
            Ambient getAmbient()const{return _ambient;}
            Diffuse getDiffuse()const{return _diffuse;}
            std::vector<MyPoint> getPoints() const {return vec_point;}
            std::vector<MyDirection> getDirections() const {return vec_direction;}
            // std::vector<MyDirection> setDirectional(Lights& li) {
            // }
            void display_point() const {
                for (size_t i = 0; i < vec_point.size(); i++) std::cout << "plane[" << i + 1 << "] :: { x=[" <<
                vec_point[i].x << "] y=[" << vec_point[i].y << "] z=[" << vec_point[i].z << "] }" << std::endl;
            }
};

#endif /* !PLIGHT_HPP_ */
