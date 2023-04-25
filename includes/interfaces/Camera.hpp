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
            Camera() : origin(new Math::Point3D(0,0,0)), screen(new Rectangle3D()) {};
            Camera(Math::Point3D *_origin, Rectangle3D *_screen) : origin(_origin), screen(_screen) {}
            const Ray *ray(double u, double v) {
                Math::Point3D screen_point = this->screen->pointAt(u, v);
                Math::Vector3D *direction_vector = new Math::Vector3D(screen_point.x_coords, screen_point.y_coords, screen_point.z_coords);
                const Ray *_ray = new Ray(origin, direction_vector);
                return _ray;
            }
        protected:
        private:
    };
}

#endif /* !Camera_hpp */
