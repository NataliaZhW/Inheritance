#include"Shape.h"

Geometry::Shape::Shape(SHAPE_TAKE_PARAMETERS) : color(color)
{
	set_start_x(start_x);
	set_start_y(start_y);
	set_line_width(line_width);
	count++;
}
Geometry::Shape::~Shape() { count--; }

int Geometry::Shape::get_count() { return count; }

Geometry::Color Geometry::Shape::get_Color() const { return color; }

void Geometry::Shape::set_Color(Color color) { this->color = color; }

unsigned int Geometry::Shape::get_start_x() const { return start_x; }

unsigned int Geometry::Shape::get_start_y() const { return start_y; }

unsigned int Geometry::Shape::get_line_width() const { return line_width; }

void Geometry::Shape::set_start_x(unsigned int start_x)
{
	if (start_x < MIN_START_X)start_x = MIN_START_X;
	if (start_x > MAX_START_X)start_x = MAX_START_X;
	this->start_x = start_x;
}

void Geometry::Shape::set_start_y(unsigned int start_y)
{
	if (start_y < MIN_START_Y)start_y = MIN_START_Y;
	if (start_y > MAX_START_Y)start_y = MAX_START_Y;
	this->start_y = start_y;
}

void Geometry::Shape::set_line_width(unsigned int line_width)
{
	if (line_width < MIN_LINE_WIDTH)line_width = MIN_LINE_WIDTH;
	if (line_width > MAX_LINE_WIDTH)line_width = MAX_LINE_WIDTH;
	this->line_width = line_width;
}

double Geometry::Shape::filter_size(double size)
{
	if (size < MIN_SIZE)size = MIN_SIZE;
	if (size > MAX_SIZE)size = MAX_SIZE;
	return size;
}

void Geometry::Shape::info() const
{
	std::cout << "Площадь фигуры:  " << get_area() << endl;
	std::cout << "Периметр фигуры: " << get_perimeter() << endl;
	draw();
}

int Geometry::Shape::count = 0;
