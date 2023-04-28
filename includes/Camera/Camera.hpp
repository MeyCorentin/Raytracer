/*
** EPITECH PROJECT, 2023
** Camera
** File description:
** Camera
*/

#ifndef Camera_HPP
    #define Camera_HPP

#include "../Math/Point3D.hpp"
#include "../Objects/Shapes/Rectangle3D.hpp"
#include "Ray.hpp"

class Camera {
        public:
            Math::Point3D *origin;
            Shape::Rectangle3D *screen;
            Camera(Math::Point3D *_origin, Shape::Rectangle3D *_screen) : origin(_origin), screen(_screen) {}
            Ray *ray(double u, double v) {
                return (new Ray(*origin, screen->pointAt(u, v)));
            }
        protected:
        private:
    };
#endif /* !Camera */
