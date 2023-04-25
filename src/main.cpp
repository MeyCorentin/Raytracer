#include "./../includes/interfaces/Camera.hpp"
#include "./../includes/interfaces/Ray.hpp"
#include "./../includes/interfaces/Point3D.hpp"
#include "./../includes/interfaces/Rectangle3D.hpp"
#include "./../includes/interfaces/Sphere.hpp"
#include "./../includes/interfaces/Vector3D.hpp"

int main() {
    Raytracer::Camera cam;
    Raytracer::Sphere sphere(new Math::Point3D(0, 0, -1) , 2);

    // Loop through image plane
    for (int y = 1; y < 1080; y++) {
        for (int x = 1; x < 1080; x++) {
            // Compute ray direction
            double u = (x + 0.5) / 1080.0;
            double v = (y + 0.5) / 1080.0;
            const Ray *_ray =  cam.ray(u, v);
            if (sphere.hits(_ray))
            {
                std::cout << "O";
            } else
            {
                std::cout << "X";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
