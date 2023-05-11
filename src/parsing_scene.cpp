/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** parsing_scene
*/

#include <libconfig.h++>
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include "../includes/Data.hpp"

int main()
{
    try {
        Get get("my.cfg");
        Get::Camera camera(get);
        std::cout << "----------------------FROM CAMERA CLASS--------------------\n";
        std::cout << "RESOLUTION ::  |Width: " << camera.getResolution().width << std::endl;
        std::cout << "               |Height: " << camera.getResolution().height << std::endl;
        std::cout << "\nPOSITION ::    |X: " << camera.getPosition().x << std::endl;
        std::cout << "               |Y: " << camera.getPosition().y << std::endl;
        std::cout << "               |Z: " << camera.getPosition().z << std::endl;
        std::cout << "\nROTATION ::    |X: " << camera.getRotation().x << std::endl;
        std::cout << "               |Y: " << camera.getRotation().y << std::endl;
        std::cout << "               |Z: " << camera.getRotation().z << std::endl;
        std::cout << "\nFIELDOFVIEW :: |FOV: " << camera.getFOV().value << std::endl;

        Get::Primitives prim(get);
        std::cout << "----------------------FROM PRIMITIVES CLASS--------------------\n";
        prim.display_spheres();
        prim.display_planes();
        Get::Lights li(get);
        std::cout << "----------------------FROM LIGHTS CLASS--------------------\n";
        std::cout << "Ambient: " << li.getAmbient().value << std::endl;
        std::cout << "Diffuse: " << li.getDiffuse().value << std::endl;
        li.display_point();
    } catch (const libconfig::ParseException& e) {
        std::cerr << "Error parsing config file: " << e.what() << " : " << e.getLine() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

