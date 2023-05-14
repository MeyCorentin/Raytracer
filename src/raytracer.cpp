/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** raytracer
*/

#include <iostream>
#include "Objects/Shapes/Sphere.hpp"
#include "Camera/Camera.hpp"
#include "Camera/Ray.hpp"
#include "interface/IObject.hpp"
#include "Objects/Shapes/Rectangle3D.hpp"
#include "Objects/Shapes/Triangle3D.hpp"
#include "Objects/Shapes/Plane.hpp"
#include "Objects/Shapes/Cone.hpp"
#include "Objects/Shapes/Plane.hpp"
#include "Scene/SceneBuilder.hpp"
#include "Camera/Camera.hpp"
#include "Light/DirectionalLight.hpp"
#include "Light/AmbientLight.hpp"
#include "Objects/ObjectDecorator/Translate.hpp"


double clamp(double x, double min, double max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}


double random_gen() {
    return rand() / (RAND_MAX + 1.0);
}


double random_double(double min, double max) {
    return min + (max-min)*(rand() / (RAND_MAX + 1.0));
}

Math::Point3D random_in_unit_sphere() {
    while (true) {
        Math::Point3D p = Math::Point3D(random_double(-1,1), random_double(-1,1), random_double(-1,1));
        if (p.length() < 1)
            return p;
    }
}

Math::Point3D random_in_hemisphere(Math::Point3D& normal) {
    Math::Point3D in_unit_sphere = random_in_unit_sphere();
    if (in_unit_sphere.dot_p(&normal) > 0.0)
        return in_unit_sphere;
    return -in_unit_sphere;
}


void ppm_output(std::ostream &out, Math::Vector3D pixel_color, int antialisaing) {
    std::cout << static_cast<int>(256 * clamp(sqrt(1.0 / antialisaing * pixel_color.x_coords), 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(sqrt(1.0 / antialisaing * pixel_color.y_coords), 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(sqrt(1.0 / antialisaing * pixel_color.z_coords), 0.0, 0.999)) << '\n';
}

Math::Point3D generate_color(Ray* r, hit_record* rec, Scene* scene) {

    Ray reflection;
    Math::Vector3D attenuation;
    Math::Point3D unit_direction;

    if (!scene->hit_global(*r, 0.001, INFINITY, *rec, false))
    {
        unit_direction = Math::VecToPoint(*r->direction).unit_vector();
        double t = 0.5 * (unit_direction.y_coords + 1.0);
        return (1.0 - t) * Math::Point3D(1.0, 1.0, 1.0) + t * Math::Point3D(0.5, 0.7, 1.0);
    }
    if (!rec->mat->rebound(*r, *rec, reflection, attenuation))
        return Math::Point3D(0, 0, 0);
    return rec->light_result;

}

void raytracer(Scene *scene)
{
    hit_record *rec = new hit_record();
    Math::Point3D color_gen;
    Ray *r;
    Camera* cam = scene->getCam();
    double u;
    double v;
    int width = cam->getWidth();
    int height = cam->getHeight();
    int antialiasing = cam->getAntialiasing();


    std::cout << "P3\n" << width << " " << height<< "\n255\n";
    for (double j = height - 1; j >= 0; --j) {
        for (double i = 0; i < width; ++i)
        {
            color_gen = Math::Point3D {0, 0, 0};
            for (int s = 0; s < antialiasing; ++s) {
                u = (i + random_gen()) / (width - 1);
                v = (j + random_gen()) / (height - 1);
                r = cam->ray(u, v);
                color_gen += generate_color(r, rec, scene);
            }
            ppm_output(std::cout, Math::Vector3D(color_gen.x_coords, color_gen.y_coords, color_gen.z_coords), width);
            rec->t = INFINITY;
        }
    }
}
