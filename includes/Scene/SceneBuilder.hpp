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
#include "main.hpp"

class SceneBuilder {

    public:
        Scene *scene;
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
        void build()
        {
            raytracer(this->scene);
        }
        void setCamera(Camera *cam)
        {
            scene->cam = cam;
        }
        void setCamera(
                int image_width,
                double aspect_ratio,
                double viewport_height,
                int antialisaing,
                int maxDepth,
                Camera *cam,
                Rectangle3D *rect,
                Math::Point3D *origin,
                Math::Point3D *horizontal,
                Math::Point3D *vertical
        ) {
            int image_height = image_width / aspect_ratio;
            double viewport_width = aspect_ratio * viewport_height;
            origin = new Math::Point3D(0, 0, 0);
            horizontal = new Math::Point3D(viewport_width, 0, 0);
            vertical = new  Math::Point3D(0, viewport_height, 0);
            rect = new Rectangle3D(origin , vertical, horizontal);
            *cam = Camera(origin, rect);
            cam->setResolution(image_width, image_height);
            cam->setAntialiasing(antialisaing);
            cam->setMaxDepth(maxDepth);
            scene->cam = cam;
        }
        Camera *getCamera()
        {
            return scene->getCam();
        }
        template<class T>
        void add_object(T object)
        {
            scene->object_list.push_back(std::make_shared<T>(object));
        }
        template<class T>
        void add_light(T object)
        {
            scene->light_list.push_back(std::make_shared<T>(object));
        }

    protected:
    private:
};
