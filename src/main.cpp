
#include "Objects/Shapes/Sphere.hpp"
#include "Camera/Camera.hpp"
#include "Camera/Ray.hpp"
#include "interface/IObject.hpp"
#include "Objects/Shapes/Rectangle3D.hpp"
#include "Objects/Shapes/Triangle3D.hpp"
#include "Objects/Shapes/Cone.hpp"
#include "Objects/Shapes/Plane.hpp"
#include "Scene/SceneBuilder.hpp"
#include "Camera/Camera.hpp"

double clamp(double x, double min, double max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}


double random_gen() {
    // Returns a random real in [0,1).
    return rand() / (RAND_MAX + 1.0);
}


double random_double(double min, double max) {
    return min + (max-min)*(rand() / (RAND_MAX + 1.0));
}

Math::Point3D random_in_unit_sphere() {
    while (true) {
        Math::Point3D p = Math::Point3D(random_double(-1,1), random_double(-1,1), random_double(-1,1));
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
        double r = pixel_color.x_coords;
        double g = pixel_color.y_coords;
        double b = pixel_color.z_coords;
        double scale = 1.0 / antialisaing;
        r = sqrt(scale * r);
        g = sqrt(scale * g);
        b = sqrt(scale * b);
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
        double t = 0.5 * (unit_direction.y_coords + 1.0);
        return (1.0 - t) * Math::Point3D(1.0, 1.0, 1.0) + t * Math::Point3D(0.5, 0.7, 1.0);
    }
}

void raytracer(Camera cam, Scene *scene, int image_width, int image_height, int antialisaing, int maxDepth)
{
    Math::Point3D color_gen = Math::Point3D {0, 0, 0};
    hit_record *rec = new  hit_record();
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
    for (double j = image_height - 1; j >= 0; --j) {
        for (double i = 0; i < image_width; ++i)
        {
            color_gen = Math::Point3D {0, 0, 0};
            for (int s = 0; s < antialisaing; ++s) {
                double u = (i + random_gen()) / (image_width - 1);
                double v = (j + random_gen()) / (image_height - 1);
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
    SceneBuilder *sceneBuilder = new SceneBuilder();
    sceneBuilder->createNewScene();

    double aspect_ratio = 16.0 / 9.0;
    int image_width = 400;
    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    sceneBuilder->setCamera(image_width, static_cast<int>(image_width / aspect_ratio), aspect_ratio,  viewport_height);
    Math::Point3D origin = Math::Point3D(0, 0, 0);
    Math::Point3D horizontal = Math::Point3D(viewport_width, 0, 0);
    Math::Point3D vertical = Math::Point3D(0, viewport_height, 0);
    Rectangle3D *rect = new Rectangle3D(&origin , &vertical, &horizontal);
    Camera cam = Camera(&origin, rect);
    cam.setResolution(image_width, static_cast<int>(image_width / aspect_ratio));
    sceneBuilder->setCamera(cam);

    auto metal = std::make_shared<Metal>(Math::Vector3D(0.8, 0.8, 0.8), 5.0,  0.8, 0.2, 10.0);
    auto mate = std::make_shared<Mate>(Math::Vector3D(0.7, 0.3, 0.3), 5.0,  0.2, 0.1, 10.0);
    auto mate_1 = std::make_shared<Mate>(Math::Vector3D(0.5, 0.6, 0.3), 5.0,  0.2, 0.1, 10.0);
    auto mate_2 = std::make_shared<Mate>(Math::Vector3D(0.6, 0.3, 0.6), 5.0,  0.2, 0.1, 10.0);
    auto mate_3 = std::make_shared<Mate>(Math::Vector3D(0.3, 0.3, 0.8), 5.0,  0.2, 0.1, 10.0);
    auto floor = std::make_shared<Mate>(Math::Vector3D(0.8, 0.8, 0.0), 5.0,  0.5, 0.2, 10.0);

    sceneBuilder->add_object(Sphere(new Math::Point3D(-2.0, 0.0, -2.0), 0.5, mate_1));
    sceneBuilder->add_object(Sphere(new Math::Point3D(-1.0, 0.0, -2.0), 0.5, mate_2));
    sceneBuilder->add_object(Sphere(new Math::Point3D(0.0, 0.0, -2.0), 0.5, mate));
    sceneBuilder->add_object(Sphere(new Math::Point3D(2.0, 0.0, -2.0), 0.5, mate_1));
    sceneBuilder->add_object(Sphere(new Math::Point3D(1.0, 0.0, -2.0), 0.5, mate_2));
    sceneBuilder->add_object(Cone(new Math::Point3D(0.3, 0.0, -0.7), 3, mate_3));
    sceneBuilder->add_object(Cone(new Math::Point3D(-0.3, 0.0, -0.7), 3, mate_3));


    //! Marche pas
    int antialisaing = 100;
    int maxDepth = 50;

    raytracer(  sceneBuilder->getCamera(),
                sceneBuilder->getScene(),
                sceneBuilder->getCamera().getWidth(),
                sceneBuilder->getCamera().getHeight(),
                antialisaing,
                maxDepth);
    return 0;
}