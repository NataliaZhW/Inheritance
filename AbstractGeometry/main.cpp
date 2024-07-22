#include"AbstractGeometry.h"


//namespace Geometry
//{

//}

int main()
{
	setlocale(LC_ALL, "Russian");
	Square_ square1(50, 3000, 5000, 500, Color::RGB_BLUE);//Geometry::Geometry::
	square1.info();
	cout << delimiter << endl;

	Rectangle_ rectangle1(150, 80, 50, 250, 3, Color::RGB_BLUE);//Geometry::Geometry::
	rectangle1.info();
	cout << delimiter << endl;

	Circle circle1(150, 500, 500, 70, Color::RGB_ELLOW);//Geometry::Geometry::
	circle1.info();
	cout << delimiter << endl;

	EquilateralTriangle e_triangle(120, 400, 50, 2, Color::RGB_GREEN);
	e_triangle.info();//Geometry::Geometry::
	cout << delimiter << endl;

	IsoscelesTriangle i_triangle(150, 120, 550, 50, 2, Color::RGB_DARK_BLUE);//Geometry::Geometry::
	i_triangle.info();
	cout << delimiter << endl;

	RightTriangle r_triangle(200, 150, 700, 50, 2, Color::RGB_BLUE);
	r_triangle.info();//Geometry::Geometry::
	cout << delimiter << endl;

	cout << "Количество фигур: " << e_triangle.get_count() << endl;
	cout << "Количество фигур: " << Shape::get_count() << endl;//Geometry::
	//system("pause"); 
}