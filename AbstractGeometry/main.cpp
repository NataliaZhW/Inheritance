#define _USE_MATH_DEFINES
#include<iostream>
#include "Rectangle.h"
#include "Triangle.h"
#include "EquilateralTriangle.h"
#include "IsoscelesTriangle.h"
#include "RightTriangle.h"
#include "Circle.h"
#include "Square.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Geometry::Square square1(50, 3000, 5000, 500, Geometry::Color::RGB_BLUE);//
	square1.info();
	cout << delimiter << endl;

	Geometry::Rectangle rectangle1(150, 80, 50, 250, 3, Geometry::Color::RGB_BLUE);//
	rectangle1.info();
	cout << delimiter << endl;

	Geometry::Circle circle1(150, 500, 500, 70, Geometry::Color::RGB_ELLOW);//
	circle1.info();
	cout << delimiter << endl;

	Geometry::EquilateralTriangle e_triangle(120, 400, 50, 2, Geometry::Color::RGB_GREEN);
	e_triangle.info();//
	cout << delimiter << endl;

	Geometry::IsoscelesTriangle i_triangle(150, 120, 550, 50, 2, Geometry::Color::RGB_DARK_BLUE);//
	i_triangle.info();
	cout << delimiter << endl;

	Geometry::RightTriangle r_triangle(200, 150, 700, 50, 2, Geometry::Color::RGB_BLUE);
	r_triangle.info();//
	cout << delimiter << endl;

	cout << "Количество фигур: " << e_triangle.get_count() << endl;
	cout << "Количество фигур: " << Geometry::Shape::get_count() << endl;//
	//system("pause"); 
}