#include "./../includes/interfaces/Camera.hpp"
#include "./../includes/interfaces/Ray.hpp"
#include "./../includes/interfaces/Point3D.hpp"
#include "./../includes/interfaces/Rectangle3D.hpp"
#include "./../includes/interfaces/Sphere.hpp"
#include "./../includes/interfaces/Vector3D.hpp"
#include <memory>

void ppm_output(std::ostream &out, Math::Vector3D pixel_color) {
    // Write the translated [0,255] value of each color component.
    if ((pixel_color.x_coords) >= 0 && ( pixel_color.y_coords) >= 0 && (pixel_color.z_coords) >= 0)
    {
        std::cout
            << static_cast<int>(255.999 * pixel_color.x_coords) << ' '
            << static_cast<int>(255.999 * pixel_color.y_coords) << ' '
            << static_cast<int>(255.999 * pixel_color.z_coords) << '\n';
    }
}

int main() {
    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

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

    object_list.push_back(std::make_shared<Raytracer::Sphere>(sphere));
    object_list.push_back(std::make_shared<Raytracer::Sphere>(sphere2));
    object_list.push_back(std::make_shared<Raytracer::Sphere>(sphere3));

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            auto u = static_cast<double>(i) / (image_width - 1);
            auto v = static_cast<double>(j) / (image_height - 1);
            Ray *r = cam.ray(u, v);
            double t_min = 0.00001;
            double t_max = INFINITY;
            for (auto & object : object_list) {
                if (object->hits(*r, t_min, t_max, *rec))
                {
                    t_max = rec->t;
                }
            }
            if (rec->t != INFINITY)
            {
                ppm_output(std::cout, Math::Vector3D(rec->normal.x_coords, rec->normal.y_coords, rec->normal.z_coords));
            }
            else
            {
                ppm_output(std::cout, Math::Vector3D(0,0,0));
            }
            rec->t = INFINITY;
        }
    }

    return 0;
}