/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** main
*/

#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <iostream>
#include "Scene/Scene.hpp"
#include "Camera/Camera.hpp"

double clamp(double x, double min, double max);
double random_double(double min, double max);
Math::Point3D random_in_hemisphere(Math::Point3D& normal);
void raytracer(Camera cam, Scene *scene, int image_width, int image_height, int antialisaing, int maxDepth);

#endif /* !MAIN_HPP_ */
