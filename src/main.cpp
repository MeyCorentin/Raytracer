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
#include "Light/DirectionalLight.hpp"
#include "Light/AmbientLight.hpp"
#include "Objects/ObjectDecorator/Translate.hpp"
#include "Factory/Material/FMaterial.hpp"
#include "Factory/Decorator/FDecorator.hpp"
#include "Factory/Lights/FLights.hpp"
#include "Factory/Shape/SetShape.hpp"
#include "Factory/PCamera.hpp"

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
    SetShape shape(cfg, sceneBuilder, sceneBuilder->getScene());
    FLight light(cfg, sceneBuilder);
    sceneBuilder->build();
    return 0;
}
