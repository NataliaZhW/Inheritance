#include "Circle.h"

Geometry::Circle::Circle(int radius, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS) { set_radius(radius); }

Geometry::Circle::~Circle() {}

void Geometry::Circle::set_radius(int radius) { this->radius = filter_size(radius); }

double Geometry::Circle::get_radius() const { return this->radius; }

double Geometry::Circle::get_area() const { return get_radius() * get_radius() * PI; }

double Geometry::Circle::get_diameter() const { return 2 * radius; }

double Geometry::Circle::get_perimeter() const { return get_radius() * PI * 2; }

void Geometry::Circle::info()const
{
	std::cout << typeid(*this).name() << endl;
	Shape::info();
	std::cout << " Circle radius = " << radius << " adres: " << this << "\n";
}

void Geometry::Circle::draw()const 
{
	HWND hwnd = GetConsoleWindow();		
	HDC hdc = GetDC(hwnd); 
	int line = line_width > radius ? radius : line_width;
	HPEN hPen = CreatePen(PS_SOLID, line, get_Color());

	HBRUSH hBrush = CreateSolidBrush(Geometry::Color::RGB_GREEN); //Закрасить зеленым 

	SelectObject(hdc, hPen);
	SelectObject(hdc, hBrush);

	::Ellipse(hdc, start_x, start_y, start_x + get_diameter(), start_y + get_diameter());

	DeleteObject(hPen);
	DeleteObject(hBrush);

	ReleaseDC(hwnd, hdc);
}