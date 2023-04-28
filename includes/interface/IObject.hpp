/*
** EPITECH PROJECT, 2023
** IObject
** File description:
** IObject
*/

#ifndef IObject_HPP
    #define IObject_HPP

namespace Shape
{
class hit_record;
}
class Ray;

class IObject {
    public:
        virtual ~IObject() = default;
        virtual bool hits(const Ray& r, double t_min, double t_max, Shape::hit_record& rec) = 0;

    protected:
    private:
};

#endif /* !IObject */
