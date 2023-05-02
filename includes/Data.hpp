/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** to_parse
*/

#ifndef DATA_HPP_
#define DATA_HPP_
#include <iostream>
#include <string>
#include <vector>
#include <libconfig.h++>

class Get {
    private:
    public:
        libconfig::Config cfg;
        Get(const char* filename) {cfg.readFile(filename);}

        class Camera {
            private:
                const std::string cam = "camera";
                const std::string pos = cam + ".position";
                const std::string res = cam + ".resolution";
                const std::string rot = cam + ".rotation";
                Get& info;
            public:
                Camera(Get& _info) : info(_info){}
                struct Res {
                    int width, height;
                } _res;
                void setRes()
                {
                    _res.width = info.cfg.lookup(res + ".width");
                    _res.height = info.cfg.lookup(res + ".height");
                }
                struct Pos {
                    double x, y, z;
                } _pos;
                void setPos()
                {
                    _pos.x = info.cfg.lookup(pos + ".x");
                    _pos.y = info.cfg.lookup(pos + ".y");
                    _pos.z = info.cfg.lookup(pos + ".z");
                }
                struct Rot {
                    double x, y, z;
                } _rot;
                void setRot()
                {
                    _rot.x = info.cfg.lookup(rot + ".x");
                    _rot.y = info.cfg.lookup(rot + ".y");
                    _rot.z = info.cfg.lookup(rot + ".z");
                }
                struct FieldOfView {
                    double value;
                } _fov;
                void setFov(){_fov.value = info.cfg.lookup(cam + ".fieldOfView");}
        };
        class Primitives {
            private:
                Get& info;
                const std::string prim = "primitives";
                const std::string spheres = prim + ".spheres";
                const std::string planes = prim + ".planes";
                struct MySphere {
                    double x, y, z, ra;
                    int r, g, b;
                } mySphere;
                struct MyPlane {
                    std::string axis;
                    double pos;
                    int r, g, b;
                } myPlane;
            public:
                Primitives(Get& _info) : info(_info){}
                std::vector<MySphere> setSpheres() {
                    for (libconfig::SettingIterator it = info.cfg.lookup(spheres).begin();it != info.cfg.lookup(spheres).end();it++, vec_spheres.emplace_back(mySphere)) {
                        mySphere.x = (*it).lookup(".x"), mySphere.y = (*it).lookup(".y"), mySphere.z = (*it).lookup(".z");
                        mySphere.ra = (*it).lookup(".r");
                        mySphere.r = (*it).lookup(".color.r"),mySphere.g = (*it).lookup(".color.g"),mySphere.b = (*it).lookup(".color.b");
                    }
                    return vec_spheres;
                }
                std::vector<MyPlane> setPlanes() {
                    for (libconfig::SettingIterator it = info.cfg.lookup(planes).begin();it != info.cfg.lookup(planes).end();it++, vec_planes.emplace_back(myPlane)) {
                        myPlane.axis = (std::string)((*it).lookup(".axis")), myPlane.pos = (*it).lookup(".position");
                        myPlane.r = (*it).lookup(".color.r"),myPlane.g = (*it).lookup(".color.g"),myPlane.b = (*it).lookup(".color.b");
                    }
                    return vec_planes;
                }
                std::vector<MySphere> vec_spheres;
                std::vector<MyPlane> vec_planes;
                void display_spheres() {
                    for (size_t i = 0; i < vec_spheres.size(); i++) std::cout << "sphere[" << i + 1 << "] :: { x=[" <<
                    vec_spheres[i].x << "] y=[" << vec_spheres[i].y << "] z=[" << vec_spheres[i].z <<
                    "] ra=[" << vec_spheres[i].ra << "] r=[" << vec_spheres[i].r << "] g=[" << vec_spheres[i].g
                    << "] b=[" << vec_spheres[i].b << "] }" <<std::endl;
                }
                void display_planes() {
                    for (size_t i = 0; i < vec_planes.size(); i++) std::cout << "plane[" << i + 1 << "] :: { axis=[" <<
                    vec_planes[i].axis << "] position=[" << vec_planes[i].pos << "] r=[" << vec_planes[i].r <<
                    "] g=[" << vec_planes[i].g << "] b=[" << vec_planes[i].b << "] }" <<std::endl;
                }
        };
        class Lights {
            private:
                Get& info;
                const std::string li = "lights";
                const std::string ambient = li + ".ambient";
                const std::string diffuse = li + ".diffuse";
                const std::string point = li + ".point";
                const std::string directional = li + ".directional";
                struct MyPoint {
                    double x, y, z;
                } myPoint;
                struct MyDirection {
                } myDirection;
            public:
                Lights(Get& _info) : info(_info){};
                struct Ambient {
                    double value;
                } _ambient;
                struct Diffuse {
                    double value;
                } _diffuse;
                void setAmbient() {_ambient.value = info.cfg.lookup(ambient);}
                void setDiffuse() {_diffuse.value = info.cfg.lookup(diffuse);}
                std::vector<MyPoint> setPoints() {
                    libconfig::Config& cfg = info.cfg;
                    for (libconfig::SettingIterator it = cfg.lookup(point).begin();it != cfg.lookup(point).end();it++, vec_point.emplace_back(myPoint))
                        myPoint.x = (*it).lookup(".x"), myPoint.y = (*it).lookup(".y"), myPoint.z = (*it).lookup(".z");
                    return vec_point;
                }
                // std::vector<MyDirection> setDirectional(Lights& li) {
                // }
                std::vector<MyPoint> vec_point;
                std::vector<MyDirection> vec_direction;
                void display_point() {
                    for (size_t i = 0; i < vec_point.size(); i++) std::cout << "plane[" << i + 1 << "] :: { x=[" <<
                    vec_point[i].x << "] y=[" << vec_point[i].y << "] z=[" << vec_point[i].z << "] }" << std::endl;
                }
        };
};

namespace primitives
{
}


namespace light
{
};
#endif /* !DATA_HPP_ */
