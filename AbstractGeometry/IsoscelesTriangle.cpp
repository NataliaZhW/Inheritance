#include "IsoscelesTriangle.h"

Geometry::IsoscelesTriangle::IsoscelesTriangle(double side1, double side2, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS) {
	set_side1(side1); set_side2(side2);
}

Geometry::IsoscelesTriangle::~IsoscelesTriangle() {}

double Geometry::IsoscelesTriangle::get_side1() const { return side1; }

double Geometry::IsoscelesTriangle::get_side2() const { return side2; }

void Geometry::IsoscelesTriangle::set_side1(double side1) { this->side1 = filter_size(side1); }

void Geometry::IsoscelesTriangle::set_side2(double side2) { this->side2 = filter_size(side2); }

double Geometry::IsoscelesTriangle::get_height() const { return sqrt(side1 * side1 - side2 / 2 * side2 / 2); }

double Geometry::IsoscelesTriangle::get_area() const { return side2 / 2 * get_height(); }

double Geometry::IsoscelesTriangle::get_perimeter() const { return side1 * 2 + side2; }

void Geometry::IsoscelesTriangle::info() const
{
	cout << typeid(*this).name() << endl;
	cout << "Равнобедренная сторона: " << side1 << endl;
	cout << "Основание: " << side2 << endl;
	Shape::info();
}

void Geometry::IsoscelesTriangle::draw() const
{
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);

	HPEN hPen = CreatePen(PS_SOLID, line_width, color);
	HBRUSH hBrush = CreateSolidBrush(color);

	SelectObject(hdc, hPen);
	SelectObject(hdc, hBrush);

	//определяем массив точек треугольника
	POINT point[] =
	{
		{start_x, get_height() + start_y},
		{side2 + start_x, get_height() + start_y},
		{side2 / 2 + start_x, start_y}
	};
	// Рисуем треугольник:
	Polygon(hdc, point, 3);

	DeleteObject(hBrush);
	DeleteObject(hPen);

	ReleaseDC(hwnd, hdc);
}
