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

    class Camera {
        private:
            const libconfig::Config& _cfg;
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
            Camera(const libconfig::Config& cfg): _cfg(cfg)
            {
                _res.width = _cfg.lookup(res + ".width");
                _res.height = _cfg.lookup(res + ".height");
                _rot.x = _cfg.lookup(rot + ".x");
                _rot.y = _cfg.lookup(rot + ".y");
                _rot.z = _cfg.lookup(rot + ".z");
                _pos.x = _cfg.lookup(pos + ".x");
                _pos.y = _cfg.lookup(pos + ".y");
                _pos.z = _cfg.lookup(pos + ".z");
                _fov.value = _cfg.lookup(cam + ".fieldOfView");
            }
            Res getResolution()const{return _res;}
            Pos getPosition()const{return _pos;}
            Rot getRotation()const{return _rot;}
            FieldOfView getFOV()const{return _fov;}
    };
    class Primitives {
        private:
            const libconfig::Config& _cfg;
            const std::string prim = "primitives";
            const std::string spheres = prim + ".spheres";
            const std::string planes = prim + ".planes";
            const std::string cones = prim + ".cones";
            const std::string cylinder = prim + ".cylinders";
            struct MySphere {
                double x, y, z, ra;
                int r, g, b;
            } mySphere;
            std::vector<MySphere> vec_spheres;
            struct MyCone {
                double x, y, z, ra, h;
                int r, g, b;
            } myCone;
            std::vector<MyCone> vec_cones;
            struct MyCylinder {
                double x, y, z, ra, h;
                int r, g, b;
            } myCylinder;
            std::vector<MyCylinder> vec_cylinders;
            struct MyPlane {
                std::string axis;
                double pos;
                int r, g, b;
            } myPlane;
            std::vector<MyPlane> vec_planes;
        public:
            Primitives(const libconfig::Config& cfg): _cfg(cfg)
            {
                for (libconfig::SettingIterator it = _cfg.lookup(spheres).begin();it != _cfg.lookup(spheres).end();it++, vec_spheres.emplace_back(mySphere)) {
                    mySphere.x = (*it).lookup(".x"), mySphere.y = (*it).lookup(".y"), mySphere.z = (*it).lookup(".z");
                    mySphere.ra = (*it).lookup(".r");
                    mySphere.r = (*it).lookup(".color.r"),mySphere.g = (*it).lookup(".color.g"),mySphere.b = (*it).lookup(".color.b");
                }
                for (libconfig::SettingIterator it = _cfg.lookup(cones).begin();it != _cfg.lookup(cones).end();it++, vec_cones.emplace_back(myCone)) {
                    myCone.x = (*it).lookup(".x"), myCone.y = (*it).lookup(".y"), myCone.z = (*it).lookup(".z");
                    myCone.ra = (*it).lookup(".r"), myCone.h = (*it).lookup(".h");
                    myCone.r = (*it).lookup(".color.r"),myCone.g = (*it).lookup(".color.g"), myCone.b = (*it).lookup(".color.b");
                }
                for (libconfig::SettingIterator it = _cfg.lookup(cylinder).begin();it != _cfg.lookup(cylinder).end();it++, vec_cylinders.emplace_back(myCylinder)) {
                    myCylinder.x = (*it).lookup(".x"), myCylinder.y = (*it).lookup(".y"), myCylinder.z = (*it).lookup(".z");
                    myCylinder.ra = (*it).lookup(".r"), myCylinder.h = (*it).lookup(".h");
                    myCylinder.r = (*it).lookup(".color.r"),myCylinder.g = (*it).lookup(".color.g"), myCylinder.b = (*it).lookup(".color.b");
                }
                for (libconfig::SettingIterator it = _cfg.lookup(planes).begin();it != _cfg.lookup(planes).end();it++, vec_planes.emplace_back(myPlane)) {
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
            void display_cones() const {
                for (size_t i = 0; i < vec_cones.size(); i++) std::cout << "cone[" << i + 1 << "] :: { x=[" <<
                vec_cones[i].x << "] y=[" << vec_cones[i].y << "] z=[" << vec_cones[i].z <<
                "] ra=[" << vec_cones[i].ra << "] h=[" << vec_cones[i].h << "] r= [" << vec_cones[i].r << "] g=[" << vec_cones[i].g
                << "] b=[" << vec_cones[i].b << "] }" <<std::endl;
            }
            void display_cylinders() const {
                for (size_t i = 0; i < vec_cylinders.size(); i++) std::cout << "cylinder[" << i + 1 << "] :: { x=[" <<
                vec_cylinders[i].x << "] y=[" << vec_cylinders[i].y << "] z=[" << vec_cylinders[i].z <<
                "] ra=[" << vec_cylinders[i].ra << "] h=[" << vec_cylinders[i].h << "] r= [" << vec_cylinders[i].r << "] g=[" << vec_cylinders[i].g
                << "] b=[" << vec_cylinders[i].b << "] }" <<std::endl;
            }
            void display_planes() const {
                for (size_t i = 0; i < vec_planes.size(); i++) std::cout << "plane[" << i + 1 << "] :: { axis=[" <<
                vec_planes[i].axis << "] position=[" << vec_planes[i].pos << "] r=[" << vec_planes[i].r <<
                "] g=[" << vec_planes[i].g << "] b=[" << vec_planes[i].b << "] }" <<std::endl;
            }
            std::vector<MySphere> getSpheres() const{return vec_spheres;}
            std::vector<MyCone> getCones() const{return vec_cones;}
            std::vector<MyCylinder> getCylinders() const{return vec_cylinders;}
            std::vector<MyPlane> getPlanes() const{return vec_planes;}
    };
    class Lights {
        private:
            const libconfig::Config& _cfg;
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
                double vector;
                double size;
            } myDirection;
            std::vector<MyDirection> vec_direction;
            struct Ambient {
                double value;
            } _ambient;
            struct Diffuse {
                double value;
            } _diffuse;
        public:
            Lights(const libconfig::Config& cfg): _cfg(cfg)
            {
                _ambient.value = _cfg.lookup(ambient);
                _diffuse.value = _cfg.lookup(diffuse);
                for (libconfig::SettingIterator it = _cfg.lookup(point).begin();it != _cfg.lookup(point).end();it++, vec_point.emplace_back(myPoint))
                    myPoint.x = (*it).lookup(".x"), myPoint.y = (*it).lookup(".y"), myPoint.z = (*it).lookup(".z");
            };
            Ambient getAmbient()const{return _ambient;}
            Diffuse getDiffuse()const{return _diffuse;}
            std::vector<MyPoint> getPoints() const {return vec_point;}
            std::vector<MyDirection> getDirections() const {return vec_direction;}
            // std::vector<MyDirection> setDirectional(Lights& li) {
            // }
            void display_point() const {
                for (size_t i = 0; i < vec_point.size(); i++) std::cout << "plane[" << i + 1 << "] :: { x=[" <<
                vec_point[i].x << "] y=[" << vec_point[i].y << "] z=[" << vec_point[i].z << "] }" << std::endl;
            }
    };
    class Transformations {
        private:
            const libconfig::Config& _cfg;
            const std::string transfo = "transformations";
            const std::string trans = transfo + ".translation";
            const std::string rot = transfo + ".rotation";

            struct Translation {
                double x, y, z;
            } _trans;
            struct Rot {
                double x, y, z;
            } _rot;
        public:
            Transformations(const libconfig::Config& cfg): _cfg(cfg)
            {
                _trans.x = _cfg.lookup(trans + ".x");
                _trans.y = _cfg.lookup(trans + ".y");
                _trans.z = _cfg.lookup(trans + ".z");
                _rot.x = _cfg.lookup(rot + ".x");
                _rot.y = _cfg.lookup(rot + ".y");
                _rot.z = _cfg.lookup(rot + ".z");
            }
            Translation getTranslation()const{return _trans;}
            Rot getRotation()const{return _rot;}
    };
    class Materials {
        private:
            const libconfig::Config& _cfg;
            const std::string mat = "materials";
            const std::string flat = mat + ".flat";

            struct Flat {
                int r, g, b;
            } _flat;
        public:
            Materials(const libconfig::Config& cfg): _cfg(cfg)
            {
                _flat.r = _cfg.lookup(flat + ".r");
                _flat.g = _cfg.lookup(flat + ".g");
                _flat.b = _cfg.lookup(flat + ".b");
            }
            Flat getFlat()const{return _flat;}
    };

#endif /* !DATA_HPP_ */
