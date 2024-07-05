#include <iostream>
#include <math.h>
#include <cmath>
#include <Windows.h>

using namespace std;

#define delimiter "\n----------------------------------------------\n\n"
#define PI 3.14

namespace Geometry
{
	enum Color
	{
		CONSOLE_BLUE = 0x15,
		CONSOLE_GREEN = 0xAA,
		CONSOLE_RED = 0xCC,
		CONSOLE_DEFAULT = 0x07
	};

	class Shape
	{
	private:
		Color color;
	public:
		Shape(Color color) : color(color) {};
		virtual ~Shape() {};
		virtual double get_area()  const = 0;
		virtual double get_perimeter()  const = 0;
		virtual void draw()  const = 0;

		Color get_Color()const { return color; }
		void set_Color(Color color) { this->color = color; }
		virtual void info()const
		{
			cout << "Площадь фигуры:  " << get_area() << endl;
			cout << "Периметр фигуры: " << get_perimeter() << endl;
			draw();
		}
	};

	class Square : public Shape
	{
	private:
		double side;
	public:
		Square(double side, Color color) : Shape(color) { set_side(side); }
		virtual ~Square() {};

		double get_area()  const override { return side * side; };
		void set_side(double side) { this->side = side; }

		double get_perimeter()  const override { return side * 4; }
		void draw()const override
		{
			HANDLE  hConcole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConcole, get_Color());
			for (int i = 0; i < side; i++)
			{
				for (int i = 0; i < side; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConcole, Color::CONSOLE_DEFAULT);
		}
		double get_side()const
		{
			return side;
		}
		virtual void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << side << endl;
			Shape::info();
		}

	};

	class Rectangle : public Shape
	{
	private:
		double width;
		double height;
	public:
		Rectangle(double width, double height, Color color) : Shape(color)
		{
			set_width(width);
			set_height(height);
		}
		virtual ~Rectangle() {};

		double get_area()  const override { return width * height; };
		void set_width(double width) { this->width = width; }
		void set_height(double height) { this->height = height; }

		double get_perimeter()  const override { return (width + height) * 2; }
		void draw()const  override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 5, get_Color());
			HBRUSH hBrush = CreateSolidBrush(get_Color());
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Rectangle(hdc, 100, 50, 800, 350);

			DeleteObject(hPen);
			DeleteObject(hBrush);
		}
		void draw1()const 
		{
			HANDLE hConcole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConcole, get_Color());
			for (int i = 0; i < height; i++)
			{
				for (int i = 0; i < width; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConcole, Color::CONSOLE_DEFAULT);
		}
		double get_width()const { return width; }
		double get_height()const { return height; }
		virtual void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина: " << width << endl;
			cout << "Ширина: " << height << endl;
			Shape::info();
		}
	};

}
int main()
{
	setlocale(LC_ALL, "Russian");
	Geometry::Square square1(5, Geometry::Color::CONSOLE_GREEN);
	//cout << "Длина стороны : " << square1.get_side() << endl;
	//cout << "Площадь квадрата:  " << square1.get_area() << endl;
	//cout << "Периметр квадрата: " << square1.get_perimeter() << endl;
	//square1.draw();
	square1.info();

	Geometry::Rectangle rectangle1(15,8, Geometry::Color::CONSOLE_BLUE);
	rectangle1.info();
}