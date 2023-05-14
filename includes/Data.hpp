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
                struct Res {
                    int width, height;
                } _res;
                struct Pos {
                    double x, y, z;
                } _pos;
                struct Rot {
                    double x, y, z;
                } _rot;
                struct FieldOfView {
                    double value;
                } _fov;
            public:
                Camera(Get& _info)
                {
                    _res.width = _info.cfg.lookup(res + ".width");
                    _res.height = _info.cfg.lookup(res + ".height");
                    _rot.x = _info.cfg.lookup(rot + ".x");
                    _rot.y = _info.cfg.lookup(rot + ".y");
                    _rot.z = _info.cfg.lookup(rot + ".z");
                    _pos.x = _info.cfg.lookup(pos + ".x");
                    _pos.y = _info.cfg.lookup(pos + ".y");
                    _pos.z = _info.cfg.lookup(pos + ".z");
                    _fov.value = _info.cfg.lookup(cam + ".fieldOfView");
                }
                Res getResolution()const{return _res;}
                Pos getPosition()const{return _pos;}
                Rot getRotation()const{return _rot;}
                FieldOfView getFOV()const{return _fov;}
        };
        class Primitives {
            private:
                const std::string prim = "primitives";
                const std::string spheres = prim + ".spheres";
                const std::string planes = prim + ".planes";
                struct MySphere {
                    double x, y, z, ra;
                    int r, g, b;
                } mySphere;
                std::vector<MySphere> vec_spheres;
                struct MyPlane {
                    std::string axis;
                    double pos;
                    int r, g, b;
                } myPlane;
                std::vector<MyPlane> vec_planes;
            public:
                Primitives(Get& _info)
                {
                    for (libconfig::SettingIterator it = _info.cfg.lookup(spheres).begin();it != _info.cfg.lookup(spheres).end();it++, vec_spheres.emplace_back(mySphere)) {
                        mySphere.x = (*it).lookup(".x"), mySphere.y = (*it).lookup(".y"), mySphere.z = (*it).lookup(".z");
                        mySphere.ra = (*it).lookup(".r");
                        mySphere.r = (*it).lookup(".color.r"),mySphere.g = (*it).lookup(".color.g"),mySphere.b = (*it).lookup(".color.b");
                    }
                    for (libconfig::SettingIterator it = _info.cfg.lookup(planes).begin();it != _info.cfg.lookup(planes).end();it++, vec_planes.emplace_back(myPlane)) {
                        myPlane.axis = (std::string)((*it).lookup(".axis")), myPlane.pos = (*it).lookup(".position");
                        myPlane.r = (*it).lookup(".color.r"),myPlane.g = (*it).lookup(".color.g"),myPlane.b = (*it).lookup(".color.b");
                    }
                }
                void display_spheres() const {
                    for (size_t i = 0; i < vec_spheres.size(); i++) std::cout << "sphere[" << i + 1 << "] :: { x=[" <<
                    vec_spheres[i].x << "] y=[" << vec_spheres[i].y << "] z=[" << vec_spheres[i].z <<
                    "] ra=[" << vec_spheres[i].ra << "] r=[" << vec_spheres[i].r << "] g=[" << vec_spheres[i].g
                    << "] b=[" << vec_spheres[i].b << "] }" <<std::endl;
                }
                void display_planes() const {
                    for (size_t i = 0; i < vec_planes.size(); i++) std::cout << "plane[" << i + 1 << "] :: { axis=[" <<
                    vec_planes[i].axis << "] position=[" << vec_planes[i].pos << "] r=[" << vec_planes[i].r <<
                    "] g=[" << vec_planes[i].g << "] b=[" << vec_planes[i].b << "] }" <<std::endl;
                }
                std::vector<MySphere> getSpheres() const{return vec_spheres;}
                std::vector<MyPlane> getPlanes() const{return vec_planes;}
        };
        class Lights {
            private:
                const std::string li = "lights";
                const std::string ambient = li + ".ambient";
                const std::string diffuse = li + ".diffuse";
                const std::string point = li + ".point";
                const std::string directional = li + ".directional";
                struct MyPoint {
                    double x, y, z;
                } myPoint;
                std::vector<MyPoint> vec_point;
                struct MyDirection {
                } myDirection;
                std::vector<MyDirection> vec_direction;
                struct Ambient {
                    double value;
                } _ambient;
                struct Diffuse {
                    double value;
                } _diffuse;
            public:
                Lights(Get& _info)
                {
                    _ambient.value = _info.cfg.lookup(ambient);
                    _diffuse.value = _info.cfg.lookup(diffuse);
                    for (libconfig::SettingIterator it = _info.cfg.lookup(point).begin();it != _info.cfg.lookup(point).end();it++, vec_point.emplace_back(myPoint))
                        myPoint.x = (*it).lookup(".x"), myPoint.y = (*it).lookup(".y"), myPoint.z = (*it).lookup(".z");
                };
                Ambient getAmbient()const{return _ambient;}
                Diffuse getDiffuse()const{return _diffuse;}
                std::vector<MyPoint> getPoints() const {return vec_point;}
                std::vector<MyDirection> getDirections() const {return vec_direction;}
                void display_point() const {
                    for (size_t i = 0; i < vec_point.size(); i++) std::cout << "plane[" << i + 1 << "] :: { x=[" <<
                    vec_point[i].x << "] y=[" << vec_point[i].y << "] z=[" << vec_point[i].z << "] }" << std::endl;
                }
        };
};

#endif /* !DATA_HPP_ */
