/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PShape
*/

#include "../includes/Parser/PShape.hpp"

void PShape::createSpheres(const libconfig::Config& cfg, PMaterial *pmaterial, PDecorator *decorator, Scene *scene)
{
    for (libconfig::SettingIterator it = _cfg.lookup(spheres).begin();it != _cfg.lookup(spheres).end();it++, vec_spheres.emplace_back(mySphere)) {
        mySphere.x = (*it).lookup(".x"), mySphere.y = (*it).lookup(".y"), mySphere.z = (*it).lookup(".z");
        mySphere.ra = (*it).lookup(".r");
        mySphere.mat = (const std::string)(*it).lookup(".mat");
        mySphere.trans = (const std::string)(*it).lookup(".trans");
        mySphere.rot = (const std::string)(*it).lookup(".rot");
        pmaterial->setMaterial(mySphere.mat, scene);
        if (mySphere.rot.compare("none") == 0) decorator->setDecorator<Sphere>("none", scene); else decorator->setDecorator<Sphere>(mySphere.rot, scene);
        if (mySphere.trans.compare("none") == 0) decorator->setDecorator<Sphere>("none", scene); else decorator->setDecorator<Sphere>(mySphere.trans, scene);
    }
}

void PShape::createCones(const libconfig::Config& cfg, PMaterial *pmaterial, PDecorator *decorator, Scene *scene)
{
    for (libconfig::SettingIterator it = _cfg.lookup(cones).begin();it != _cfg.lookup(cones).end();it++, vec_cones.emplace_back(myCone)) {
        myCone.x = (*it).lookup(".x"), myCone.y = (*it).lookup(".y"), myCone.z = (*it).lookup(".z");
        myCone.ra = (*it).lookup(".r"), myCone.h = (*it).lookup(".h");
        myCone.mat = (const std::string)(*it).lookup(".mat");
        myCone.trans = (const std::string)(*it).lookup(".trans");
        myCone.rot = (const std::string)(*it).lookup(".rot");
        pmaterial->setMaterial(myCone.mat, scene);
        if (myCone.rot.compare("none") == 0) decorator->setDecorator<Cone>("none", scene); else decorator->setDecorator<Cone>(myCone.rot, scene);
        if (myCone.trans.compare("none") == 0) decorator->setDecorator<Cone>("none", scene); else decorator->setDecorator<Cone>(myCone.trans, scene);
    }
}

void PShape::createCylinders(const libconfig::Config& cfg, PMaterial *pmaterial, PDecorator *decorator, Scene *scene)
{
    for (libconfig::SettingIterator it = _cfg.lookup(cylinder).begin();it != _cfg.lookup(cylinder).end();it++, vec_cylinders.emplace_back(myCylinder)) {
        myCylinder.x = (*it).lookup(".x"), myCylinder.y = (*it).lookup(".y"), myCylinder.z = (*it).lookup(".z");
        myCylinder.ra = (*it).lookup(".r");
        myCylinder.mat = (const std::string)(*it).lookup(".mat");
        myCylinder.trans = (const std::string)(*it).lookup(".trans");
        myCylinder.rot = (const std::string)(*it).lookup(".rot");
        pmaterial->setMaterial(myCylinder.mat, scene);
        if (myCylinder.rot.compare("none") == 0) decorator->setDecorator<Cylinder>("none", scene); else decorator->setDecorator<Cylinder>(myCylinder.rot, scene);
        if (myCylinder.trans.compare("none") == 0) decorator->setDecorator<Cylinder>("none", scene); else decorator->setDecorator<Cylinder>(myCylinder.trans, scene);
    }
}

void PShape::createPlanes(const libconfig::Config& cfg, PMaterial *pmaterial, PDecorator *decorator, Scene *scene)
{
    for (libconfig::SettingIterator it = _cfg.lookup(planes).begin();it != _cfg.lookup(planes).end();it++, vec_planes.emplace_back(myPlane)) {
        myPlane.vx = (*it).lookup(".vector.x"),myPlane.vy = (*it).lookup(".vector.y"),myPlane.vz = (*it).lookup(".vector.z");
        myPlane.px = (*it).lookup(".position.z"),myPlane.py = (*it).lookup(".position.y"),myPlane.pz = (*it).lookup(".position.z");
        myPlane.mat = (const std::string)(*it).lookup(".mat");
        myPlane.trans = (const std::string)(*it).lookup(".trans");
        myPlane.rot = (const std::string)(*it).lookup(".rot");
        pmaterial->setMaterial(myPlane.mat, scene);
        if (myPlane.rot.compare("none") == 0) decorator->setDecorator<Cone>("none", scene); else decorator->setDecorator<Cone>(myCone.rot, scene);
        if (myPlane.trans.compare("none") == 0) decorator->setDecorator<Cone>("none", scene); else decorator->setDecorator<Cone>(myCone.trans, scene);
    }
}

void PShape::addSpheres()
{
    for (size_t i = 0; i < vec_spheres.size(); i++) {
        rV = Math::Vector3D(_scene->decorator_list[vec_spheres[i].rot].x_coords, _scene->decorator_list[vec_spheres[i].rot].y_coords,_scene->decorator_list[vec_spheres[i].rot].z_coords);
        tV = Math::Vector3D(_scene->decorator_list[vec_spheres[i].trans].x_coords, _scene->decorator_list[vec_spheres[i].trans].y_coords, _scene->decorator_list[vec_spheres[i].trans].z_coords);
        oV = new Math::Point3D(vec_spheres[i].x,vec_spheres[i].y, vec_spheres[i].z);
        _sceneBuilder->add_object(Rotate(Translate(Sphere(oV, vec_spheres[i].ra, _scene->material_list[vec_spheres[i].mat]), tV), rV));
    }
}
void PShape::addCones()
{
    for (size_t i = 0; i < vec_cones.size(); i++) {
        rV = Math::Vector3D(_scene->decorator_list[vec_cones[i].rot].x_coords, _scene->decorator_list[vec_cones[i].rot].y_coords,_scene->decorator_list[vec_cones[i].rot].z_coords);
        tV = Math::Vector3D(_scene->decorator_list[vec_cones[i].trans].x_coords, _scene->decorator_list[vec_cones[i].trans].y_coords, _scene->decorator_list[vec_cones[i].trans].z_coords);
        oV = new Math::Point3D(vec_cones[i].x,vec_cones[i].y, vec_cones[i].z);
        _sceneBuilder->add_object(Rotate(Translate(Cone(oV, vec_cones[i].ra, vec_cones[i].h, _scene->material_list[vec_cones[i].mat]), tV), rV));
    }
}
void PShape::addPlanes()
{
    Math::Vector3D vV;
    Math::Point3D pV;
    for (size_t i = 0; i < vec_planes.size(); i++) {
        vV = Math::Vector3D(vec_planes[i].vx,vec_planes[i].vy, vec_planes[i].vz);
        pV = Math::Point3D(vec_planes[i].px,vec_planes[i].py, vec_planes[i].pz);
        rV = Math::Vector3D(_scene->decorator_list[vec_planes[i].rot].x_coords, _scene->decorator_list[vec_planes[i].rot].y_coords,_scene->decorator_list[vec_planes[i].rot].z_coords);
        tV = Math::Vector3D(_scene->decorator_list[vec_planes[i].trans].x_coords, _scene->decorator_list[vec_planes[i].trans].y_coords, _scene->decorator_list[vec_planes[i].trans].z_coords);
        _sceneBuilder->add_object(Rotate(Translate(Plane(vV, pV, _scene->material_list[vec_planes[i].mat]), tV), rV));
    }
}

void PShape::addCylinders()
{
    for (size_t i = 0; i < vec_cylinders.size(); i++) {
        rV = Math::Vector3D(_scene->decorator_list[vec_cylinders[i].rot].x_coords, _scene->decorator_list[vec_cylinders[i].rot].y_coords,_scene->decorator_list[vec_cylinders[i].rot].z_coords);
        tV = Math::Vector3D(_scene->decorator_list[vec_cylinders[i].trans].x_coords, _scene->decorator_list[vec_cylinders[i].trans].y_coords, _scene->decorator_list[vec_cylinders[i].trans].z_coords);
        oV = new Math::Point3D(vec_cylinders[i].x,vec_cylinders[i].y, vec_cylinders[i].z);
        _sceneBuilder->add_object(Rotate(Translate(Cylinder(oV, vec_cylinders[i].ra, _scene->material_list[vec_cylinders[i].mat]), tV), rV));
    }
}
