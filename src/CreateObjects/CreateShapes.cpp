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
        mySphere.mat = (const std::string)(*it).lookup(".mat");
        pmaterial->setMaterial(mySphere.mat, scene);
    }
}

void PShape::createCones(const libconfig::Config& cfg, PMaterial *pmaterial, Scene *scene)
{
    for (libconfig::SettingIterator it = _cfg.lookup(cones).begin();it != _cfg.lookup(cones).end();it++, vec_cones.emplace_back(myCone)) {
        myCone.x = (*it).lookup(".x"), myCone.y = (*it).lookup(".y"), myCone.z = (*it).lookup(".z");
        myCone.ra = (*it).lookup(".r"), myCone.h = (*it).lookup(".h");
        myCone.mat = (const std::string)(*it).lookup(".mat");
        pmaterial->setMaterial(myCone.mat, scene);
    }
}

void PShape::createCylinders(const libconfig::Config& cfg, PMaterial *pmaterial, Scene *scene)
{
    for (libconfig::SettingIterator it = _cfg.lookup(cylinder).begin();it != _cfg.lookup(cylinder).end();it++, vec_cylinders.emplace_back(myCylinder)) {
        myCylinder.x = (*it).lookup(".x"), myCylinder.y = (*it).lookup(".y"), myCylinder.z = (*it).lookup(".z");
        myCylinder.ra = (*it).lookup(".r"), myCylinder.h = (*it).lookup(".h");
        myCylinder.mat = (const std::string)(*it).lookup(".mat");
        pmaterial->setMaterial(myCylinder.mat, scene);
    }
}

void PShape::createPlanes(const libconfig::Config& cfg, PMaterial *pmaterial, Scene *scene)
{
    for (libconfig::SettingIterator it = _cfg.lookup(planes).begin();it != _cfg.lookup(planes).end();it++, vec_planes.emplace_back(myPlane)) {
        myPlane.vx = (*it).lookup(".vector.x"),myPlane.vy = (*it).lookup(".vector.y"),myPlane.vz = (*it).lookup(".vector.z");
        myPlane.px = (*it).lookup(".position.z"),myPlane.py = (*it).lookup(".position.y"),myPlane.pz = (*it).lookup(".position.z");
        myPlane.mat = (const std::string)(*it).lookup(".mat");
        pmaterial->setMaterial(myPlane.mat, scene);
    }
}

void PShape::addSpheres()
{
    for (size_t i = 0; i < vec_spheres.size(); i++)
        _sceneBuilder->add_object(Sphere(new Math::Point3D(vec_spheres[i].x,vec_spheres[i].y, vec_spheres[i].z), vec_spheres[i].ra, _scene->material_list[vec_spheres[i].mat]));
}
void PShape::addCones()
{
    for (size_t i = 0; i < vec_cones.size(); i++)
        _sceneBuilder->add_object(Cone(new Math::Point3D(vec_cones[i].x,vec_cones[i].y, vec_cones[i].z), vec_cones[i].ra, _scene->material_list[vec_cones[i].mat]));
}
void PShape::addPlanes()
{
    for (size_t i = 0; i < vec_planes.size(); i++)
        _sceneBuilder->add_object(Plane(Math::Vector3D(vec_planes[i].vx,vec_planes[i].vy, vec_planes[i].vz), Math::Point3D(vec_planes[i].px,vec_planes[i].py, vec_planes[i].pz), _scene->material_list[vec_planes[i].mat]));
}
