/*
** EPITECH PROJECT, 2023
** IShape
** File description:
** IShape
*/

#ifndef IShape_HPP
    #define IShape_HPP

namespace Shape
{
    class hit_record;
}
class IObject;
class Ray;

class IShape: public IObject {
    public:
        virtual ~IShape() = default;
        virtual bool hits(const Ray& r, double t_min, double t_max, Shape::hit_record& rec) = 0;

    protected:
    private:
};

#endif /* !IShape */
