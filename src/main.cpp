
#include "./../includes/interface/IObject.hpp"
#include "./../includes/interface/IShape.hpp"
#include "./../includes/Camera/Camera.hpp"
#include "./../includes/Camera/Ray.hpp"
#include "./../includes/Math/Point3D.hpp"
#include "./../includes/Math/Vector3D.hpp"
#include "./../includes/Objects/Shapes/Rectangle3D.hpp"
#include "./../includes/Objects/Shapes/Triangle3D.hpp"
#include "./../includes/Objects/Shapes/Plane.hpp"
#include "./../includes/Objects/Shapes/Sphere.hpp"
#include "./../includes/Scene.hpp"
#include "./../includes/Camera/Camera.hpp"
#include <memory>

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
        if (p.length_squared() >= 1) continue;
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
        auto scale = 1.0 / antialisaing;
        double r = sqrt(scale * pixel_color.x_coords);
        double g = sqrt(scale * pixel_color.y_coords);
        double b = sqrt(scale * pixel_color.z_coords);
        out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
            << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
            << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
    }
}

Math::Point3D  generate_color(Ray *r, Shape::hit_record *rec,  Scene * scene, int maxDepth)
{
    if (maxDepth <= 0)
        return Math::Point3D(0,0,0);

    if (scene->hit_global(*r, 0.001, INFINITY, *rec)) {
        Math::Point3D target = rec->p + random_in_hemisphere(rec->normal);
        Ray ray = Ray(rec->p, target-rec->p);
        return 0.5 * generate_color(&ray, rec, scene, maxDepth-1);
    }

    Math::Point3D unit_direction = Math::Point3D(r->direction->x_coords, r->direction->y_coords, r->direction->z_coords).unit_vector();
    auto t = 0.5*(unit_direction.y_coords + 1.0);
    if (rec->t != INFINITY)
        return (1.0-t)*rec->normal;
    return Math::Point3D{0, 0, 0};
}

int main() {

    // TODO: Move to Camera Class
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto origin = Math::Point3D(0, 0, 0);
    auto horizontal = Math::Point3D(viewport_width, 0, 0);
    auto vertical = Math::Point3D(0, viewport_height, 0);
    Shape::Rectangle3D *rect = new Shape::Rectangle3D(&origin , &vertical, &horizontal);
    Camera cam = Camera(&origin, rect);


    Shape::hit_record *rec = new Shape::hit_record();
    Scene *scene = new Scene();
    scene->add_sphere(Shape::Sphere(new Math::Point3D(1.4, 0, -0.5), 1));
    scene->add_sphere(Shape::Sphere(new Math::Point3D(0, -103.5, -1),100));
    scene->add_sphere(Shape::Sphere(new Math::Point3D(-0.2, 0, -1), 0.5));


    //! Marche pas
    int antialisaing = 100;
    int maxDepth = 50;

    Math::Point3D color_gen = Math::Point3D {0, 0, 0};
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i)
        {
            color_gen = Math::Point3D {0, 0, 0};
            for (int s = 0; s < antialisaing; ++s) {
                auto u = (static_cast<double>(i) + (rand() / (RAND_MAX + 1.0))) / (image_width - 1);
                auto v = (static_cast<double>(j) + (rand() / (RAND_MAX + 1.0))) / (image_height - 1);
                Ray *r = cam.ray(u, v);
                color_gen += generate_color(r, rec, scene, maxDepth);
            }
            ppm_output(std::cout, Math::Vector3D(color_gen.x_coords, color_gen.y_coords, color_gen.z_coords), antialisaing);
            rec->t = INFINITY;
        }
    }

    return 0;
}