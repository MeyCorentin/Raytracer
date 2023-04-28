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
            int image_height;
            int image_width;
            Camera(Math::Point3D *_origin, Shape::Rectangle3D *_screen) : origin(_origin), screen(_screen) {}
            // Camera(int _image_width, double _aspect_ratio, double _viewport_height) {
            //     const double aspect_ratio = 16.0 / 9.0;
            //     const int image_width = 400;
            //     const int image_height = static_cast<int>(image_width / aspect_ratio);

            //     double viewport_height = 2.0;
            //     double viewport_width = aspect_ratio * viewport_height;
            //     ath::Point3D origin = Math::Point3D(0, 0, 0);
            //     ath::Point3D horizontal = Math::Point3D(viewport_width, 0, 0);
            //     ath::Point3D vertical = Math::Point3D(0, viewport_height, 0);
            //     Shape::Rectangle3D *rect = new Shape::Rectangle3D(&origin , &vertical, &horizontal);
            //     this->origin = &origin;
            //     this->screen =rect;
            // }
            Camera() {};
            Ray *ray(double u, double v) {
                return (new Ray(*origin, screen->pointAt(u, v)));
            }
            void setup(double aspect_ratio, int image_width, double viewport_height)
            {
                this->origin = new Math::Point3D(0, 0, 0);
                this->image_width = image_width;
                this->image_height = static_cast<int>(image_width / aspect_ratio);
                double viewport_width = aspect_ratio * viewport_height;
                Math::Point3D horizontal = Math::Point3D(viewport_width, 0, 0);
                Math::Point3D vertical = Math::Point3D(0, viewport_height, 0);
                screen = new Shape::Rectangle3D(origin , &vertical, &horizontal);

            }
        protected:
        private:
    };
#endif /* !Camera */
