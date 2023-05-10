/*
** EPITECH PROJECT, 2023
** Sphere
** File description:
** Sphere
*/

#ifndef Sphere_HPP
#define Sphere_HPP

class Ray;
class IShape;
class Point3D;
class Vector3D;

namespace Shape
{

    class hit_record {
        public:
        hit_record() {}
        Math::Point3D p;
        Math::Point3D normal;
        double t;
    };
    class Sphere: public IShape {
        public:
            Sphere() {};
            Sphere(Math::Point3D *origin, double radius)
            {
                this->origin = origin;
                this->radius = radius;
            };
            ~Sphere() {};
            bool hits(const Ray& r, double t_min, double t_max, hit_record& rec) {
                Math::Point3D sphere_color(0.8, 0.8, 0.0);
                Math::Vector3D oc = Math::Vector3D(r.origin->x_coords, r.origin->y_coords, r.origin->z_coords) - Math::Vector3D(origin->x_coords, origin->y_coords, origin->z_coords);
                double a = dot(r.direction, r.direction);
                double b = 2.0 * dot(oc, r.direction);
                double c = dot(oc, oc) - radius * radius;
                double discriminant = b*b - 4*a*c;

                if (discriminant >= 0) {
                    double t1 = (-b - sqrt(discriminant)) / (2 * a);
                    double t2 = (-b + sqrt(discriminant)) / (2 * a);

                    if (t1 < t_max && t1 > t_min) {
                        rec.t = t1;
                        Math::Point3D intersection_point = r.at(t1);
                        Math::Point3D normal = (intersection_point - origin) / radius;
                        Math::Point3D shading_color = 0.5 * (normal + Math::Vector3D(1,1,1));
                        rec.normal =  sphere_color * shading_color;
                        return true;
                    } else if (t2 < t_max && t2 > t_min) {
                        rec.t = t2;
                        Math::Point3D intersection_point = r.at(t2);
                        Math::Point3D normal = (intersection_point - origin) / radius;
                        Math::Point3D shading_color = 0.5 * (normal + Math::Vector3D(1,1,1));
                        rec.normal =  sphere_color * shading_color;
                        return true;
                    }
                }
                return false;
            }
            Math::Point3D *origin;
            double radius;

        protected:
        private:
    };

    class Cone : public IShape {
        public:
            Cone() {};
            Cone(Math::Point3D *origin, double radius)
            {
                this->origin = origin;
                this->radius = radius;
            };
            ~Cone() {};

            bool hits(const Ray& r, double t_min, double t_max, hit_record& rec) {
                double height = 7.0;
                Math::Point3D sphere_color(0.8, 0.8, 0.0);
                Math::Vector3D oc = Math::Vector3D(r.origin->x_coords, r.origin->y_coords, r.origin->z_coords) - Math::Vector3D(origin->x_coords, origin->y_coords, origin->z_coords);
                double k = radius / height;
                k = k * k;
                double a = r.direction->x_coords * r.direction->x_coords + r.direction->z_coords * r.direction->z_coords - k * r.direction->y_coords * r.direction->y_coords;
                double b = 2 * (oc.x_coords * r.direction->x_coords + oc.z_coords * r.direction->z_coords - k * oc.y_coords * r.direction->y_coords);
                double c = oc.x_coords * oc.x_coords + oc.z_coords * oc.z_coords - k * oc.y_coords * oc.y_coords;
                double discriminant = b * b - 4 * a * c;
                if (discriminant >= 0) {
                    double t1 = (-b - sqrt(discriminant)) / (2 * a);
                    if (t1 < t_max && t1 > t_min && t1 < a) {
                        Math::Point3D intersection_point = r.at(t1);
                        if (intersection_point.y_coords < origin->y_coords) {
                            rec.t = t1;
                            // Math::Point3D normal = Math::Point3D(intersection_point.x_coords - origin->x_coords, -radius / height, intersection_point.z_coords - origin->z_coords);
                            Math::Point3D normal = (intersection_point - origin) / radius;
                            Math::Point3D shading_color = 0.5 * (normal + Math::Vector3D(1, 1, 1));
                            rec.normal =  sphere_color * shading_color;
                            return true;
                        }
                    }
                }
                return false;
            }
            Math::Point3D *origin;
            double radius;
};

    class Triangle3D : public IShape {

        public:
            Math::Point3D *_origin;
            Math::Point3D *_bottom_side;
            Math::Point3D *_left_side;
            Triangle3D() {};
            Triangle3D(Math::Point3D *origin, Math::Point3D *bottom_side, Math::Point3D *left_side)
                : _origin(origin), _bottom_side(bottom_side), _left_side(left_side) {}
            ~Triangle3D(){};
            Math::Point3D pointAt(double u, double v) {
                //P = uA + vB + wC
                double w = 1 - u - v;
                Math::Point3D p = w * (*_origin) + u * (*_bottom_side) + v * (*_left_side);
                return p;
            }
            bool hits(const Ray &r, double t_min, double t_max, hit_record &rec) {
                Math::Point3D triangle_color(0.8, 0.8, 0.0);
                // Möller-Trumbore algo
                const float EPSILON = 0.0000001;
                // makes 3 vectors out of triangle vertices
                // pas ouf de construire comme ça
                Math::Vector3D AB = Math::Vector3D(_bottom_side->x_coords - _origin->x_coords, _bottom_side->y_coords - _origin->y_coords, _bottom_side->z_coords - _origin->z_coords);
                Math::Vector3D BC = Math::Vector3D(_left_side->x_coords - _bottom_side->x_coords, _left_side->y_coords - _bottom_side->y_coords, _left_side->z_coords - _bottom_side->z_coords);
                Math::Vector3D CA = Math::Vector3D(_origin->x_coords - _left_side->x_coords, _origin->y_coords - _left_side->y_coords, _origin->z_coords - _left_side->z_coords);
                // new vectors to make pvec which will be used to calculate the determinant
                Math::Vector3D dirRef(*r.direction);//surement nul
                Math::Vector3D oRef(r.origin->x_coords, r.origin->y_coords, r.origin->z_coords); 
                Math::Vector3D V1 = BC - AB;
                Math::Vector3D V2 = CA - AB;
                Math::Vector3D pvec = dirRef.cross(V2);
                double det = dot(V1, pvec);
                // si parallèle a determinant false
                if (det > -EPSILON && det < EPSILON)
                    return false;
                double invDet = 1 / det;
                Math::Vector3D tvec(oRef.x_coords - _origin->x_coords, oRef.y_coords - _origin->y_coords, oRef.z_coords - _origin->z_coords);
                double u = dot(tvec, pvec) * invDet;
                //check intersection
                if (u < 0 || u > 1)
                    return false;
                Math::Vector3D qvec = tvec.cross(V1);
                double v = dot(dirRef, qvec) * invDet;
                // check si intersection dans le triangle
                if (v < 0.0 || u + v > 1.0)
                    return false;
                double t = dot(V2, qvec) * invDet;
                // if (t > EPSILON) {
                    rec.t = t;
                    Math::Point3D p = r.at(t);
                    Math::Point3D normal = p - _origin;
                    Math::Point3D shading_color = 0.5 * (normal + Math::Vector3D(1, 1, 1));
                    rec.normal = triangle_color * shading_color;
                    return true;
                // }
                Math::Vector3D normalv = V1.cross(V2);
                Math::Vector3D denom = normalv.cross(normalv);
                double ndotRayDir = dot(normalv, dirRef);
                // check par rapport a normal si parallele
                if (fabs(ndotRayDir) < EPSILON)
                    return false;
                return false;
            }
        protected:
        private:
    };
}

#endif /* !Sphere */
