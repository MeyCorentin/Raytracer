/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PShape
*/

#include "../includes/Parser/PShape.hpp"

void PShape::createSpheres(const libconfig::Config& cfg, PMaterial *pmaterial, Scene *scene)
{
    for (libconfig::SettingIterator it = _cfg.lookup(spheres).begin();it != _cfg.lookup(spheres).end();it++, vec_spheres.emplace_back(mySphere)) {
        mySphere.x = (*it).lookup(".x"), mySphere.y = (*it).lookup(".y"), mySphere.z = (*it).lookup(".z");
        mySphere.ra = (*it).lookup(".r");
        mySphere.r = (*it).lookup(".color.r"),mySphere.g = (*it).lookup(".color.g"),mySphere.b = (*it).lookup(".color.b");
        mySphere.mat = (const std::string)(*it).lookup(".mat");
        pmaterial->setMaterial(mySphere.mat, scene);
    }
}

void PShape::createCones(const libconfig::Config& cfg, PMaterial *pmaterial, Scene *scene)
{
    for (libconfig::SettingIterator it = _cfg.lookup(cones).begin();it != _cfg.lookup(cones).end();it++, vec_cones.emplace_back(myCone)) {
        myCone.x = (*it).lookup(".x"), myCone.y = (*it).lookup(".y"), myCone.z = (*it).lookup(".z");
        myCone.ra = (*it).lookup(".r"), myCone.h = (*it).lookup(".h");
        myCone.r = (*it).lookup(".color.r"),myCone.g = (*it).lookup(".color.g"), myCone.b = (*it).lookup(".color.b");
        myCone.mat = (const std::string)(*it).lookup(".mat");
        pmaterial->setMaterial(myCone.mat, scene);
    }
}

void PShape::createCylinders(const libconfig::Config& cfg, PMaterial *pmaterial, Scene *scene)
{
    for (libconfig::SettingIterator it = _cfg.lookup(cylinder).begin();it != _cfg.lookup(cylinder).end();it++, vec_cylinders.emplace_back(myCylinder)) {
        myCylinder.x = (*it).lookup(".x"), myCylinder.y = (*it).lookup(".y"), myCylinder.z = (*it).lookup(".z");
        myCylinder.ra = (*it).lookup(".r"), myCylinder.h = (*it).lookup(".h");
        myCylinder.r = (*it).lookup(".color.r"),myCylinder.g = (*it).lookup(".color.g"), myCylinder.b = (*it).lookup(".color.b");
        myCylinder.mat = (const std::string)(*it).lookup(".mat");
        pmaterial->setMaterial(myCylinder.mat, scene);
    }
}

void PShape::createPlanes(const libconfig::Config& cfg, PMaterial *pmaterial, Scene *scene)
{
    for (libconfig::SettingIterator it = _cfg.lookup(planes).begin();it != _cfg.lookup(planes).end();it++, vec_planes.emplace_back(myPlane)) {
        myPlane.axis = (std::string)((*it).lookup(".axis")), myPlane.pos = (*it).lookup(".position");
        myPlane.r = (*it).lookup(".color.r"),myPlane.g = (*it).lookup(".color.g"),myPlane.b = (*it).lookup(".color.b");
        myPlane.mat = (const std::string)(*it).lookup(".mat");
        pmaterial->setMaterial(myCone.mat, scene);
    }
}

void PShape::addSpheres()
{
    for (size_t i = 0; i < vec_spheres.size(); i++) {
        auto mate = std::make_shared<Mate>(Math::Vector3D(0.3, 0.3, 0.8), 5.0,  0.2, 0.1, 10.0);
        _sceneBuilder->add_object(Sphere(new Math::Point3D(vec_spheres[i].x,vec_spheres[i].y, vec_spheres[i].z), vec_spheres[i].ra, _scene->material_list[vec_spheres[i].mat]));
    }
}
void PShape::addCones()
{
    auto mate = std::make_shared<Mate>(Math::Vector3D(0.3, 0.3, 0.8), 5.0,  0.2, 0.1, 10.0);
    for (size_t i = 0; i < vec_cones.size(); i++)
        _sceneBuilder->add_object(Cone(new Math::Point3D(vec_cones[i].x,vec_cones[i].y, vec_cones[i].z), vec_cones[i].ra, _scene->material_list[vec_cones[i].mat]));
}
void PShape::addPlanes()
{
    // for (size_t i = 0; i < vec_planes.size(); i++) {
    //     sceneBuilder->add_object(Sphere(new Math::Point3D(vec_planes[i].x,vec_planes[i].y, vec_planes[i].z), vec_planes[i].ra, mate));
    // }
}