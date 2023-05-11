
#include "Objects/Shapes/Sphere.hpp"
#include "Camera/Camera.hpp"
#include "Camera/Ray.hpp"
#include "interface/IObject.hpp"
#include "Objects/Shapes/Rectangle3D.hpp"
#include "Objects/Shapes/Triangle3D.hpp"
#include "Objects/Shapes/Plane.hpp"
#include "Scene.hpp"
#include "Camera/Camera.hpp"

double clamp(double x, double min, double max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

double random_double(double min, double max) {
    return min + (max-min)*(rand() / (RAND_MAX + 1.0));
}

Math::Point3D random_in_unit_sphere() {
    while (true) {
        auto p = Math::Point3D(random_double(-1,1), random_double(-1,1), random_double(-1,1));
        if (p.length() >= 1) continue;
        return p;
    }
}

Math::Point3D random_in_hemisphere(Math::Point3D& normal) {
    Math::Point3D in_unit_sphere = random_in_unit_sphere();
    if (in_unit_sphere.dot_p(&normal) > 0.0)
        return in_unit_sphere;
    else
        return -in_unit_sphere;
}

void ppm_output(std::ostream &out, Math::Vector3D pixel_color, int antialisaing) {
    if ((pixel_color.x_coords) >= 0 && ( pixel_color.y_coords) >= 0 && (pixel_color.z_coords) >= 0)
    {
        auto r = pixel_color.x_coords;
        auto g = pixel_color.y_coords;
        auto b = pixel_color.z_coords;

        // Divide the color by the number of samples and gamma-correct for gamma=2.0.
        auto scale = 1.0 / antialisaing;
        r = sqrt(scale * r);
        g = sqrt(scale * g);
        b = sqrt(scale * b);

        // Write the translated [0,255] value of each color component.
        std::cout << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
            << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
            << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
    }
}

Math::Point3D generate_color(Ray* r, hit_record* rec, Scene* scene, int maxDepth) {
    if (maxDepth <= 0) {
        return Math::Point3D(0, 0, 0);
    }

    if (scene->hit_global(*r, 0.001, INFINITY, *rec)) {
        Ray reflection;
        Math::Vector3D attenuation;
        if (rec->mat->rebound(*r, *rec, reflection, attenuation)) {
            Ray *temp = &reflection;
            return Math::Point3D{attenuation.x_coords, attenuation.y_coords, attenuation.z_coords} *  generate_color(temp, rec, scene, maxDepth - 1);
        } else {
            return Math::Point3D(0, 0, 0);
        }
    } else {
        Math::Point3D unit_direction = Math::Point3D(r->direction->x_coords, r->direction->y_coords, r->direction->z_coords).unit_vector();
        auto t = 0.5 * (unit_direction.y_coords + 1.0);
        return (1.0 - t) * Math::Point3D(1.0, 1.0, 1.0) + t * Math::Point3D(0.5, 0.7, 1.0);
    }
}

void raytracer(Camera cam, Scene *scene, int image_width, int image_height, int antialisaing, int maxDepth)
{
    Math::Point3D color_gen = Math::Point3D {0, 0, 0};
    hit_record *rec = new  hit_record();
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i)
        {
            color_gen = Math::Point3D {0, 0, 0};
            for (int s = 0; s < antialisaing; ++s) {
                auto u = (static_cast<double>(i) + rand() / RAND_MAX) / (image_width - 1);
                auto v = (static_cast<double>(j) + rand() / RAND_MAX) / (image_height - 1);
                Ray *r = cam.ray(u, v);
                color_gen += generate_color(r, rec, scene, maxDepth);
            }
            ppm_output(std::cout, Math::Vector3D(color_gen.x_coords, color_gen.y_coords, color_gen.z_coords), antialisaing);
            rec->t = INFINITY;
        }
    }
}

int main() {
    // TODO: Move to Camera Class
    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    Math::Point3D origin = Math::Point3D(0, 0, 0);
    Math::Point3D horizontal = Math::Point3D(viewport_width, 0, 0);
    Math::Point3D vertical = Math::Point3D(0, viewport_height, 0);
     Rectangle3D *rect = new  Rectangle3D(&origin , &vertical, &horizontal);
    Camera cam = Camera(&origin, rect);

    Scene *scene = new Scene();
    auto metal = std::make_shared<Metal>(Math::Vector3D(0.8, 0.8, 0.8), 5.0,  0.8, 0.2, 10.0);
    auto mate = std::make_shared<Mate>(Math::Vector3D(0.7, 0.3, 0.3), 5.0,  0.2, 0.1, 10.0);
    auto mate_1 = std::make_shared<Mate>(Math::Vector3D(0.5, 0.6, 0.3), 5.0,  0.2, 0.1, 10.0);
    auto mate_2 = std::make_shared<Mate>(Math::Vector3D(0.6, 0.3, 0.6), 5.0,  0.2, 0.1, 10.0);
    auto floor = std::make_shared<Mate>(Math::Vector3D(0.8, 0.8, 0.0), 5.0,  0.5, 0.2, 10.0);
    scene->add_sphere( Sphere(new Math::Point3D(0.5, -100.5, -1.0), 100.0,floor));
    scene->add_sphere( Sphere(new Math::Point3D(0.0, 0.0, -2.0), 0.5, mate));
    scene->add_sphere( Sphere(new Math::Point3D(-2.0, 0.0, -2.0), 0.5, mate_1));
    scene->add_sphere( Sphere(new Math::Point3D(-1.0, 0.0, -2.0), 0.5, mate_2));
    scene->add_sphere( Sphere(new Math::Point3D(0.0, 0.0, -2.0), 0.5, mate));
    scene->add_sphere( Sphere(new Math::Point3D(2.0, 0.0, -2.0), 0.5, mate_1));
    scene->add_sphere( Sphere(new Math::Point3D(1.0, 0.0, -2.0), 0.5, mate_2));


    //! Marche pas
    int antialisaing = 100;
    int maxDepth = 50;

    raytracer(cam, scene, image_width, image_height, antialisaing, maxDepth);
    return 0;
}