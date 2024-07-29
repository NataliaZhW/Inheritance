#include "Triangle.h"

Geometry::Triangle::Triangle(SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS) {}

Geometry::Triangle::~Triangle() {}

void Geometry::Triangle::info() const 
{
	cout << "Высота треугольника: " << get_height() << "\n";
	Shape::info();
}