/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** main
*/

#include <iostream>
#include "Objects/Shapes/Sphere.hpp"
#include "Camera/Camera.hpp"
#include "Camera/Ray.hpp"
#include "interface/IObject.hpp"
#include "Objects/Shapes/Rectangle3D.hpp"
#include "Objects/Shapes/Triangle3D.hpp"
#include "Objects/Shapes/Plane.hpp"
#include "Objects/Shapes/Cone.hpp"
#include "Objects/Shapes/Plane.hpp"
#include "Scene/SceneBuilder.hpp"
#include "Camera/Camera.hpp"
#include "Light/DirectionalLight.hpp"
#include "Light/AmbientLight.hpp"
#include "Objects/ObjectDecorator/Translate.hpp"
#include "Parser/PShape.hpp"
#include "Parser/PMaterial.hpp"
#include "Parser/PLight.hpp"
#include "Parser/PTransformation.hpp"

void help()
{
    std::cout << "USAGE: ./raytracer <SCENE_FILE>\n\tSCENE_FILE: scene configuration\n";
}

int main(int ac, char **av) {
    libconfig::Config cfg;
    Camera cam;
    Rectangle3D rect;
    Math::Point3D origin;
    Math::Point3D horizontal;
    Math::Point3D vertical;

    double aspect_ratio = 16.0 / 9.0;
    int image_width = 400;
    double viewport_height = 2.0;
    int antialisaing = 100;
    int maxDepth = 50;

    const std::string h = "--help";
    if (ac != 2)
        return 84;
    else if (h.compare(av[1]) == 0) {
        help();
        return 0;
    }

    cfg.readFile(av[1]);
    SceneBuilder *sceneBuilder = new SceneBuilder();
    sceneBuilder->createNewScene();
    sceneBuilder->setCamera(image_width, aspect_ratio, viewport_height, antialisaing, maxDepth, &cam, &rect, &origin, &horizontal, &vertical);

    auto metal = std::make_shared<Metal>(Math::Vector3D(0.8, 0.8, 0.8));
    auto mate = std::make_shared<Mate>(Math::Vector3D(0.7, 0.3, 0.3));
    PShape *shape = new PShape(cfg, sceneBuilder, sceneBuilder->getScene());
    shape->addShape<Sphere>();
    shape->addShape<Cone>();
    shape->addShape<Plane>();
    PTransformation transfo(cfg, sceneBuilder, shape, sceneBuilder->getScene());
    PLight light(cfg, sceneBuilder);
    sceneBuilder->build();
    return 0;
}