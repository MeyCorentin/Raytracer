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
        std::cout << "\nPOSITION ::  |X: " << camera.getPosition().x << std::endl;
        std::cout << "               |Y: " << camera.getPosition().y << std::endl;
        std::cout << "               |Z: " << camera.getPosition().z << std::endl;
        std::cout << "\nROTATION ::  |X: " << camera.getRotation().x << std::endl;
        std::cout << "               |Y: " << camera.getRotation().y << std::endl;
        std::cout << "               |Z: " << camera.getRotation().z << std::endl;
        std::cout << "\nFIELDOFVIEW :: |FOV: " << camera.getFOV().value << std::endl;

        Get::Primitives prim(get);
        std::cout << "----------------------FROM PRIMITIVES CLASS--------------------\n";
        prim.display_spheres();
        std::cout << std::endl;
        prim.display_planes();
        std::cout << std::endl;
        prim.display_cones();
        std::cout << std::endl;
        prim.display_cylinders();
        std::cout << std::endl;
        Get::Lights li(get);
        std::cout << "----------------------FROM LIGHTS CLASS--------------------\n";
        std::cout << "Ambient: " << li.getAmbient().value << std::endl;
        std::cout << "Diffuse: " << li.getDiffuse().value << std::endl;
        li.display_point();

        Get::Transformations transfo(get);
        std::cout << "----------------------FROM Transformations CLASS--------------------\n";
        std::cout << "TRANSLATION :: |X: " << transfo.getTranslation().x << std::endl;
        std::cout << "               |Y: " << transfo.getTranslation().y << std::endl;
        std::cout << "               |Z: " << transfo.getTranslation().z << std::endl;
        std::cout << "\nROTATION :: |X: " << transfo.getRotation().x << std::endl;
        std::cout << "            |Y: " << transfo.getRotation().y << std::endl;
        std::cout << "            |Z: " << transfo.getRotation().z << std::endl;
        Get::Materials material(get);
        std::cout << "----------------------FROM Materials CLASS--------------------\n";
        std::cout << "FLAT COLOR :: R: " << material.getFlat().r << std::endl;
        std::cout << "              G: " << material.getFlat().g << std::endl;
        std::cout << "              B: " << material.getFlat().b << std::endl;
    } catch (const libconfig::ParseException& e) {
        std::cerr << "Error parsing config file: " << e.what() << " : " << e.getLine() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

