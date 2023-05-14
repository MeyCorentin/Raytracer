/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DataDecorator
*/

#include <iostream>

class DataDecorator {
    public:
        const std::string transfo = "transformations";

        struct Translation {
            double x, y, z;
        } _trans;
        struct Rot {
            double x, y, z;
        } _rot;
};
