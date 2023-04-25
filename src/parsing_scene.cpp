/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** parsing_scene
*/

#include <libconfig.h++>
#include <iostream>
#include <cstdlib>

int main()
{
    libconfig::Config config;

    try {
        config.readFile("file.cfg");
    } catch (libconfig::FileIOException &e) {
        std::cerr << "FileIOException occurred. Could not read \"file.cfg\"!!" << std::endl;
        exit(EXIT_FAILURE);
    } catch (libconfig::ParseException&e) {
        std::cerr << "Parse error at " << e.getFile() << ":" << e.getLine() << "-" << e.getError() << std::endl;
        exit(EXIT_FAILURE);
    }
    try{
        /*get the window setting from the configuration file*/
        libconfig::Setting& window = config.lookup("camera");
        /*delete the pos setting from window*/
        /*write the configuration to file*/
        config.writeFile("update.cfg");
    } catch (libconfig::SettingNotFoundException& e){
        /*setting not found exception*/
        std::cout << e.what();
    } catch (libconfig::SettingTypeException& e){
        /*setting type exception*/
        std::cout << e.what();
    }
    return 0;
}

