/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PShape
*/

#include "Factory/Shape/FShape.hpp"
#include "Objects/ObjectDecorator/Rotate.hpp"
#include "Objects/ObjectDecorator/Translate.hpp"
#include "Objects/Shapes/Cylinder.hpp"
#include "Objects/Shapes/Sphere.hpp"
#include "Objects/Shapes/Plane.hpp"
#include "Objects/Shapes/Cone.hpp"
#include "Objects/Shapes/Plane.hpp"
#include "Factory/Decorator/FDecorator.hpp"
#include "Factory/Material/FMaterial.hpp"
template<>

void FShape<Sphere>::createSpheres()
{
    for (libconfig::SettingIterator it = _cfg.lookup(data.spheres).begin();it != _cfg.lookup(data.spheres).end();it++, data.vec_spheres.emplace_back(data.mySphere)) {
        data.mySphere.x = (*it).lookup(".x"), data.mySphere.y = (*it).lookup(".y"), data.mySphere.z = (*it).lookup(".z");
        data.mySphere.ra = (*it).lookup(".r");
        data.mySphere.mat = (const std::string)(*it).lookup(".mat");
        data.mySphere.trans = (const std::string)(*it).lookup(".trans");
        data.mySphere.rot = (const std::string)(*it).lookup(".rot");
        FMaterial material(_cfg, data.mySphere.mat, _scene);
        if (data.mySphere.rot.compare("none") == 0) FDecorator(_cfg, "none", _scene); else FDecorator(_cfg, data.mySphere.rot, _scene);
        if (data.mySphere.trans.compare("none") == 0) FDecorator(_cfg, "none", _scene); else FDecorator(_cfg, data.mySphere.trans, _scene);
    }
}

template<>
void FShape<Cone>::createCones()
{
    for (libconfig::SettingIterator it = _cfg.lookup(data.cones).begin();it != _cfg.lookup(data.cones).end();it++, data.vec_cones.emplace_back(data.myCone)) {
        data.myCone.x = (*it).lookup(".x"), data.myCone.y = (*it).lookup(".y"), data.myCone.z = (*it).lookup(".z");
        data.myCone.ra = (*it).lookup(".r"), data.myCone.h = (*it).lookup(".h");
        data.myCone.mat = (const std::string)(*it).lookup(".mat");
        data.myCone.trans = (const std::string)(*it).lookup(".trans");
        data.myCone.rot = (const std::string)(*it).lookup(".rot");
        FMaterial material(_cfg, data.myCone.mat, _scene);
        if (data.myCone.rot.compare("none") == 0) FDecorator(_cfg, "none", _scene); else FDecorator(_cfg, data.myCone.rot, _scene);
        if (data.myCone.trans.compare("none") == 0) FDecorator(_cfg, "none", _scene); else FDecorator(_cfg, data.myCone.trans, _scene);
    }
}

template<>
void FShape<Cylinder>::createCylinders()
{
    for (libconfig::SettingIterator it = _cfg.lookup(data.cylinder).begin();it != _cfg.lookup(data.cylinder).end();it++, data.vec_cylinders.emplace_back(data.myCylinder)) {
        data.myCylinder.x = (*it).lookup(".x"), data.myCylinder.y = (*it).lookup(".y"), data.myCylinder.z = (*it).lookup(".z");
        data.myCylinder.ra = (*it).lookup(".r");
        data.myCylinder.mat = (const std::string)(*it).lookup(".mat");
        data.myCylinder.trans = (const std::string)(*it).lookup(".trans");
        data.myCylinder.rot = (const std::string)(*it).lookup(".rot");
        FMaterial material(_cfg, data.myCylinder.mat, _scene);
        if (data.myCylinder.rot.compare("none") == 0) FDecorator(_cfg, "none", _scene); else FDecorator(_cfg, data.myCylinder.rot, _scene);
        if (data.myCylinder.trans.compare("none") == 0) FDecorator(_cfg, "none", _scene); else FDecorator(_cfg, data.myCylinder.trans, _scene);
    }
}

template<>
void FShape<Plane>::createPlanes()
{
    for (libconfig::SettingIterator it = _cfg.lookup(data.planes).begin();it != _cfg.lookup(data.planes).end();it++, data.vec_planes.emplace_back(data.myPlane)) {
        data.myPlane.vx = (*it).lookup(".vector.x"),data.myPlane.vy = (*it).lookup(".vector.y"),data.myPlane.vz = (*it).lookup(".vector.z");
        data.myPlane.px = (*it).lookup(".position.z"),data.myPlane.py = (*it).lookup(".position.y"),data.myPlane.pz = (*it).lookup(".position.z");
        data.myPlane.mat = (const std::string)(*it).lookup(".mat");
        data.myPlane.trans = (const std::string)(*it).lookup(".trans");
        data.myPlane.rot = (const std::string)(*it).lookup(".rot");
        FMaterial material(_cfg, data.myPlane.mat, _scene);
        if (data.myPlane.rot.compare("none") == 0) FDecorator(_cfg, "none", _scene); else FDecorator(_cfg, data.myPlane.rot, _scene);
        if (data.myPlane.trans.compare("none") == 0) FDecorator(_cfg, "none", _scene); else FDecorator(_cfg, data.myPlane.trans, _scene);
    }
}

template<>
void FShape<Sphere>::addSpheres()
{
    for (size_t i = 0; i < data.vec_spheres.size(); i++) {
        rV = Math::Vector3D(_scene->decorator_list[data.vec_spheres[i].rot].x_coords, _scene->decorator_list[data.vec_spheres[i].rot].y_coords,_scene->decorator_list[data.vec_spheres[i].rot].z_coords);
        tV = Math::Vector3D(_scene->decorator_list[data.vec_spheres[i].trans].x_coords, _scene->decorator_list[data.vec_spheres[i].trans].y_coords, _scene->decorator_list[data.vec_spheres[i].trans].z_coords);
        oV = new Math::Point3D(data.vec_spheres[i].x,data.vec_spheres[i].y, data.vec_spheres[i].z);
        _sceneBuilder->add_object(Rotate(Translate(Sphere(oV, data.vec_spheres[i].ra, _scene->material_list[data.vec_spheres[i].mat]), tV), rV));
    }
}
template<>
void FShape<Cone>::addCones()
{
    for (size_t i = 0; i < data.vec_cones.size(); i++) {
        rV = Math::Vector3D(_scene->decorator_list[data.vec_cones[i].rot].x_coords, _scene->decorator_list[data.vec_cones[i].rot].y_coords,_scene->decorator_list[data.vec_cones[i].rot].z_coords);
        tV = Math::Vector3D(_scene->decorator_list[data.vec_cones[i].trans].x_coords, _scene->decorator_list[data.vec_cones[i].trans].y_coords, _scene->decorator_list[data.vec_cones[i].trans].z_coords);
        oV = new Math::Point3D(data.vec_cones[i].x,data.vec_cones[i].y, data.vec_cones[i].z);
        _sceneBuilder->add_object(Rotate(Translate(Cone(oV, data.vec_cones[i].ra, data.vec_cones[i].h, _scene->material_list[data.vec_cones[i].mat]), tV), rV));
    }
}
template<>
void FShape<Plane>::addPlanes()
{
    Math::Vector3D vV;
    Math::Point3D pV;
    for (size_t i = 0; i < data.vec_planes.size(); i++) {
        vV = Math::Vector3D(data.vec_planes[i].vx,data.vec_planes[i].vy, data.vec_planes[i].vz);
        pV = Math::Point3D(data.vec_planes[i].px,data.vec_planes[i].py, data.vec_planes[i].pz);
        rV = Math::Vector3D(_scene->decorator_list[data.vec_planes[i].rot].x_coords, _scene->decorator_list[data.vec_planes[i].rot].y_coords,_scene->decorator_list[data.vec_planes[i].rot].z_coords);
        tV = Math::Vector3D(_scene->decorator_list[data.vec_planes[i].trans].x_coords, _scene->decorator_list[data.vec_planes[i].trans].y_coords, _scene->decorator_list[data.vec_planes[i].trans].z_coords);
        _sceneBuilder->add_object(Rotate(Translate(Plane(vV, pV, _scene->material_list[data.vec_planes[i].mat]), tV), rV));
    }
}

template<>
void FShape<Cylinder>::addCylinders()
{
    for (size_t i = 0; i < data.vec_cylinders.size(); i++) {
        rV = Math::Vector3D(_scene->decorator_list[data.vec_cylinders[i].rot].x_coords, _scene->decorator_list[data.vec_cylinders[i].rot].y_coords,_scene->decorator_list[data.vec_cylinders[i].rot].z_coords);
        tV = Math::Vector3D(_scene->decorator_list[data.vec_cylinders[i].trans].x_coords, _scene->decorator_list[data.vec_cylinders[i].trans].y_coords, _scene->decorator_list[data.vec_cylinders[i].trans].z_coords);
        oV = new Math::Point3D(data.vec_cylinders[i].x,data.vec_cylinders[i].y, data.vec_cylinders[i].z);
        _sceneBuilder->add_object(Rotate(Translate(Cylinder(oV, data.vec_cylinders[i].ra, _scene->material_list[data.vec_cylinders[i].mat]), tV), rV));
    }
}
