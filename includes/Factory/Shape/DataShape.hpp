/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DataShape
*/

#ifndef DATASHAPE_HPP_
#define DATASHAPE_HPP_

#include <iostream>
#include <vector>

class DataShape {
    public:
        struct MySphere {
            double x, y, z, ra;
            std::string mat, rot, trans;
        } mySphere;
        std::vector<MySphere> vec_spheres;
        struct MyCone {
            double x, y, z, ra, h;
            std::string mat, rot, trans;
        } myCone;
        std::vector<MyCone> vec_cones;
        struct MyCylinder {
            double x, y, z, ra;
            std::string mat, rot, trans;
        } myCylinder;
        std::vector<MyCylinder> vec_cylinders;
        struct MyPlane {
            double vx,vy,vz;
            double px,py,pz;
            std::string mat, rot, trans;
        } myPlane;
        std::vector<MyPlane> vec_planes;
        const std::string prim = "primitives";
        const std::string spheres = prim + ".spheres";
        const std::string planes = prim + ".planes";
        const std::string cones = prim + ".cones";
        const std::string cylinder = prim + ".cylinders";
};

#endif /* !DATASHAPE_HPP_ */
