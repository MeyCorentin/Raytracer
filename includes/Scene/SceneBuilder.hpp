/*
** EPITECH PROJECT, 2023
** SceneBuilder
** File description:
** SceneBuilder
*/

#pragma once

#include <vector>
#include <memory>
#include "Scene/Scene.hpp"
#include "Objects/Shapes/Rectangle3D.hpp"
#include "Camera/Camera.hpp"
namespace Shape
{
    class Sphere;
    class Triangle3D;
    class Cone;
    // class Plane;
}

class SceneBuilder {
    protected:
        Scene *scene;

    public:
        SceneBuilder() {};
        ~SceneBuilder() {};
        Scene *getScene()
        {
            return scene;
        }
        void createNewScene()
        {
            scene = new Scene();
        }
        void setCamera(int image_width, int image_height, double aspect_ratio, double viewport_height)
        {
            double viewport_width = aspect_ratio * viewport_height;
            Math::Point3D origin = Math::Point3D(0, 0, 0);
            Math::Point3D horizontal = Math::Point3D(viewport_width, 0, 0);
            Math::Point3D vertical = Math::Point3D(0, viewport_height, 0);
            Rectangle3D *rect = new Rectangle3D(&origin , &vertical, &horizontal);
            scene->cam = Camera(&origin, rect);
            scene->cam.setResolution(image_width, image_height);
        }
        Camera getCamera()
        {
            return scene->cam;
        }
        template<class T>
        void add_object(T object)
        {
            scene->object_list.push_back(std::make_shared<T>(object));
        }

    protected:
    private:
};
