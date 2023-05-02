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
        Get my_get("my.cfg");
        Get::Camera my_camera(my_get);
        std::cout << "----------------------FROM CAMERA CLASS--------------------\n";
        my_camera.setRes();
        my_camera.setPos();
        my_camera.setRot();
        my_camera.setFov();
        std::cout << "RESOLUTION :: " << " Width: " << my_camera._res.width << std::endl;
        std::cout << "RESOLUTION :: " << " Height: " << my_camera._res.height << std::endl;
        std::cout << "POSITION :: " << " X: " << my_camera._pos.x << std::endl;
        std::cout << "POSITION :: " << " Y: " << my_camera._pos.y << std::endl;
        std::cout << "POSITION :: " << " Z: " << my_camera._pos.z << std::endl;
        std::cout << "ROTATION :: " << " X: " << my_camera._rot.x << std::endl;
        std::cout << "ROTATION :: " << " Y: " << my_camera._rot.y << std::endl;
        std::cout << "ROTATION :: " << " Z: " << my_camera._rot.z << std::endl;
        std::cout << "FIELD OF VIEW :: "<< "FOV: " << my_camera._fov.value << std::endl;

        Get::Primitives my_prim(my_get);
        std::cout << "----------------------FROM PRIMITIVES CLASS--------------------\n";
        my_prim.setSpheres();
        my_prim.setPlanes();
        my_prim.display_spheres();
        my_prim.display_planes();
        Get::Lights my_li(my_get);
        std::cout << "----------------------FROM LIGHTS CLASS--------------------\n";
        my_li.setAmbient();
        my_li.setDiffuse();
        my_li.setPoints();
        std::cout << "Ambient: " << my_li._ambient.value << std::endl;
        std::cout << "Diffuse: " << my_li._diffuse.value << std::endl;
        my_li.display_point();
    } catch (const libconfig::ParseException& e) {
        std::cerr << "Error parsing config file: " << e.what() << " : " << e.getLine() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

