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
#include "Parser/PDecorator.hpp"
#include "Parser/PCamera.hpp"

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

    const std::string h = "--help";
    if (ac != 2) return 84;
    else if (h.compare(av[1]) == 0) {
        help();
        return 0;
    }
    cfg.readFile(av[1]);
    SceneBuilder *sceneBuilder = new SceneBuilder();
    PCamera camera(cfg, sceneBuilder, &cam, &rect, &origin, &horizontal, &vertical);

    PDecorator *decorator = new PDecorator(cfg);
    PShape shape(cfg, sceneBuilder, decorator, sceneBuilder->getScene());
    PLight light(cfg, sceneBuilder);
    sceneBuilder->build();
    return 0;
}
