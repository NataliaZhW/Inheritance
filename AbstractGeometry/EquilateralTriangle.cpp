#include"AbstractGeometry.h"
//#include"Shape_.cpp"
//#include"Triangle.cpp"
//namespace Geometry
//{
	class EquilateralTriangle :public Triangle //Равносторонний треугольник
	{
		double side;
	public:
		EquilateralTriangle(double side, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS) { set_side(side); }
		~EquilateralTriangle() {};

		double get_side()const { return side; }
		void set_side(double side) { this->side = filter_size(side); }
		double get_height()const override { return sqrt(side * side - side / 2 * side / 2); }
		double get_area()const override { return side / 2 * get_height(); }
		double get_perimeter()const override { return side * 3; }
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Сторона: " << side << endl;
			Shape::info();
		}
		void draw()const override
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
				{side + start_x, get_height() + start_y},
				{side / 2 + start_x, start_y}
			};
			// Рисуем треугольник:
			Polygon(hdc, point, 3);

			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);
		}
	};
//}