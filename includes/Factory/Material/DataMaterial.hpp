/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DataMaterial
*/

#include <iostream>

class DataMaterial {
    public:
        struct MyMate {
            double r, g, b;
        } _mate;
        struct MyMetal {
            double r, g, b;
        } _metal;
        const std::string mat = "materials";
};
