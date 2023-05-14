/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** FLights
*/

#include "DataLights.hpp"
#include <libconfig.h++>
#include "Scene/SceneBuilder.hpp"
class FLight {
    protected:
        SceneBuilder *_sceneBuilder;
        const libconfig::Config& _cfg;
        DataLights data;
    private:
        void createDirectionals();
        void createAmbient();
        void addLights();

    public:
        FLight(const libconfig::Config& cfg, SceneBuilder *sceneBuilder): _cfg(cfg)
        {
            _sceneBuilder = sceneBuilder;
            createDirectionals();
            createAmbient();
            addLights();
        }

};