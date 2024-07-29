#include "Rectangle.h"

Geometry::Rectangle::Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS)
{
	set_width(width);
	set_height(height);
}
Geometry::Rectangle::~Rectangle() {}

double Geometry::Rectangle::get_width() const { return width; }

double Geometry::Rectangle::get_height() const { return height; }

void Geometry::Rectangle::set_width(double width) { this->width = filter_size(width); }

void Geometry::Rectangle::set_height(double height) { this->height = filter_size(height); }

double Geometry::Rectangle::get_area() const { return width * height; }

double Geometry::Rectangle::get_perimeter() const { return (width + height) * 2; }

void Geometry::Rectangle::draw() const
{
	HWND hwnd = GetConsoleWindow(); 
	HDC hdc = GetDC(hwnd); 
	HPEN hPen = CreatePen(PS_SOLID, 5, get_Color());
	HBRUSH hBrush = CreateSolidBrush(get_Color());
	SelectObject(hdc, hPen);
	SelectObject(hdc, hBrush);
	::Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);
	DeleteObject(hPen);
	DeleteObject(hBrush);

	ReleaseDC(hwnd, hdc);
}
void Geometry::Rectangle::info()const
{
	cout << typeid(*this).name() << endl;
	cout << "Ширина: " << width << endl;
	cout << "Ширина: " << height << endl;
	Shape::info();
}