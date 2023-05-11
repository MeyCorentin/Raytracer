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
        template<class T>
        void add_object(T object)
        {
            scene->object_list.push_back(std::make_shared<T>(object));
        }

    protected:
    private:
};
