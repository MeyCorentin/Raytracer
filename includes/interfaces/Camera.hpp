/*
** EPITECH PROJECT, 2023
** Camera_hpp
** File description:
** Camera_hpp
*/

#ifndef Camera_hpp
#define Camera_hpp

#include "Point3D.hpp"
#include "Rectangle3D.hpp"
#include "Vector3D.hpp"
#include "Ray.hpp"

namespace Raytracer
{
    class Camera {
        public:
            Math::Point3D *origin;
            Rectangle3D *screen;
            Camera(Math::Point3D *_origin, Rectangle3D *_screen) : origin(_origin), screen(_screen) {}
            Ray *ray(double u, double v) {
                return (new Ray(*origin, screen->pointAt(u, v)));
            }
        protected:
        private:
    };
}

#endif /* !Camera_hpp */
