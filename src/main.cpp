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
    const std::string h = "--help";
    if (ac != 2)
        return 84;
    else if (h.compare(av[1]) == 0) {
        help();
        return 0;
    }

    libconfig::Config cfg;
    cfg.readFile(av[1]);
    // TODO: Move to Camera Class
    Scene *scene = new Scene();
    int antialisaing = 100;
    int maxDepth = 50;
    SceneBuilder *sceneBuilder = new SceneBuilder();
    sceneBuilder->createNewScene();

    double aspect_ratio = 16.0 / 9.0;
    int image_width = 400;
    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;

    Math::Point3D origin = Math::Point3D(0, 0, 0);
    Math::Point3D horizontal = Math::Point3D(viewport_width, 0, 0);
    Math::Point3D vertical = Math::Point3D(0, viewport_height, 0);
    Rectangle3D *rect = new Rectangle3D(&origin , &vertical, &horizontal);
    Camera *cam = new Camera(&origin, rect);
    sceneBuilder->setCamera(cam);
    sceneBuilder->getCamera()->setResolution(image_width, (image_width / aspect_ratio));

    auto metal = std::make_shared<Metal>(Math::Vector3D(0.8, 0.8, 0.8));
    auto mate = std::make_shared<Mate>(Math::Vector3D(0.7, 0.3, 0.3));
    PShape *shape = new PShape(cfg, sceneBuilder, scene);
    shape->addShape<Sphere>();
    shape->addShape<Cone>();
    shape->addShape<Plane>();
    PTransformation transfo(cfg, sceneBuilder, shape, scene);
    PLight light(cfg, sceneBuilder);

    raytracer(  *sceneBuilder->getCamera(),
                sceneBuilder->getScene(),
                sceneBuilder->getCamera()->getWidth(),
                sceneBuilder->getCamera()->getHeight(),
                antialisaing,
                maxDepth);
    return 0;
}