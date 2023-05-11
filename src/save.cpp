#include "./../includes/interfaces/Camera.hpp"
#include "./../includes/interfaces/Ray.hpp"
#include "./../includes/interfaces/Point3D.hpp"
#include "./../includes/interfaces/Rectangle3D.hpp"
#include "./../includes/interfaces/Sphere.hpp"
#include "./../includes/interfaces/Vector3D.hpp"
#include <memory>

inline double clamp(double x, double min, double max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
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
        b = sqrt(scale * b)

        // Write the translated [0,255] value of each color component.
        out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
            << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
            << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
    }
}


double random_double() {
    // Returns a random real in [0,1).
    return rand() / (RAND_MAX + 1.0);
}

double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_double();
}

Math::Point3D  generate_diffuse()
{
    while(true)
    {
        Math::Point3D p = Math::Point3D{random_double(-1,1), random_double(-1,1), random_double(-1,1)};
        if (p.length_squared() < 1)
            return p;
    }
}

Math::Point3D  generate_color(Ray *r, double t_min, double t_max, Raytracer::hit_record *rec,  std::vector<std::shared_ptr<Raytracer::Sphere>> object_list, int maxDepth)
{
    bool isHit = false;
    if (maxDepth <= 0)
        return Math::Point3D{0, 0, 0};
    for (const auto& object : object_list) {
        if (object->hits(*r, t_min, t_max, *rec)) {
            isHit = true;
            t_max = rec->t;
        }
    }
    if (isHit)
    {
        Math::Point3D t = rec->normal + rec->p + generate_diffuse();
        Ray ray = Ray(rec->p, t-rec->p);
        return 0.5 * generate_color(&ray, t_min, rec->t, rec, object_list, maxDepth -1);
    }
    Math::Point3D unit = Math::Point3D(r->direction->unit_vector().x_coords, r->direction->unit_vector().y_coords, r->direction->unit_vector().z_coords).unit_vector();
    float t = 0.5 *(unit.y_coords + 1.0);
    return (1.0-t)*rec->normal;
}



int main() {
    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 1080;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    int antialisaing = 10;
    int maxDepth = 50;

    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto origin = Math::Point3D(0, 0, 0);
    auto horizontal = Math::Point3D(viewport_width, 0, 0);
    auto vertical = Math::Point3D(0, viewport_height, 0);
    Raytracer::hit_record *rec = new hit_record();
    Rectangle3D *rect = new Rectangle3D(&origin , &vertical, &horizontal);
    Camera cam = Camera(&origin, rect);
    std::vector<std::shared_ptr<Raytracer::Sphere>> object_list;
    Raytracer::Sphere sphere(new Math::Point3D(1.4, 0, -0.5), 1);
    Raytracer::Sphere sphere2(new Math::Point3D(0, -103.5, -1),100);
    Raytracer::Sphere sphere3(new Math::Point3D(-0.2, 0, -1), 0.5);

    object_list.push_back(std::make_shared<Raytracer::Sphere>(sphere3));
    object_list.push_back(std::make_shared<Raytracer::Sphere>(sphere));
    object_list.push_back(std::make_shared<Raytracer::Sphere>(sphere2));
    Math::Point3D color_gen = Math::Point3D {0, 0, 0};
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i)
        {
            double t_min = 0.00001;
            double t_max = INFINITY;
            color_gen = Math::Point3D {0, 0, 0};
            for (int s = 0; s < antialisaing; ++s) {
                auto u = (static_cast<double>(i) + random_double()) / (image_width - 1);
                auto v = (static_cast<double>(j) + random_double()) / (image_height - 1);
                Ray *r = cam.ray(u, v);
                color_gen += generate_color(r, t_min, t_max, rec, object_list, maxDepth);
            }
            if (rec->t != INFINITY)
            {
                ppm_output(std::cout, Math::Vector3D(color_gen.x_coords, color_gen.y_coords, color_gen.z_coords), antialisaing);
            }
            else
            {
                ppm_output(std::cout, Math::Vector3D(0,0,0), antialisaing);
            }
            rec->t = INFINITY;
        }
    }

    return 0;
}