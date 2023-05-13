/*
** EPITECH PROJECT, 2023
** Camera
** File description:
** Camera
*/


#pragma once

#include "Objects/Shapes/Rectangle3D.hpp"
#include "Ray.hpp"


class Camera {
    public:
        Math::Point3D *origin;
         Rectangle3D *screen;
        int image_height;
        int image_width;
        int maxDepth;
        int antialiasing;
        Camera(Math::Point3D *_origin,  Rectangle3D *_screen) : origin(_origin), screen(_screen) {}
        void setResolution(int width, int height)
        {
            this->image_width = width;
            this->image_height = height;
        }
        int getWidth()
        {
            return this->image_width;
        }
        int getHeight()
        {
            return this->image_height;
        }
        int getAntialiasing()
        {
            return this->antialiasing;
        }
        int getMaxDepth()
        {
            return this->maxDepth;
        }

        void setAntialiasing(int antialiasing)
        {
            this->antialiasing = antialiasing;
        }
        void setMaxDepth(int maxDepth)
        {
            this->maxDepth = maxDepth;
        }
        Camera() {};
        Ray *ray(double u, double v) {
            return (new Ray(*origin, screen->pointAt(u, v)));
        }
    protected:
    private:
};