/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DataLights
*/

#include <iostream>
#include <vector>
#include "Light/DirectionalLight.hpp"
#include "Light/AmbientLight.hpp"

class DataLights {
    public:
        const std::string li = "lights";
        const std::string ambient = li + ".ambient";
        const std::string point = li + ".point";
        const std::string direction = li + ".directional";

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
};