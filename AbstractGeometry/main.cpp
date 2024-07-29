//#include"AbstractGeometry.h"
#pragma once

#define _USE_MATH_DEFINES //файлик с константами типа Пи - M_PI можно использовать
#include <iostream>
#include <Windows.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <winuser.h>
using namespace std;
//
//#include"main.cpp"
//#include"Shape_.cpp"
//#include"Rectangle_.cpp"
//#include"Square_.cpp"
//#include"Circle.cpp"
//#include"Triangle.cpp"
//#include"EquilateralTriangle.cpp"
//#include"IsoscelesTriangle.cpp"
//#include"RightTriangle.cpp"

#define delimiter "\n----------------------------------------------\n\n"
#define PI 3.14
namespace Geometry
{
	enum Color
	{
		CONSOLE_BLUE = 0x09,
		CONSOLE_GREEN = 0xAA,
		CONSOLE_RED = 0x04,
		CONSOLE_DEFAULT = 0x07,

		RGB_DEFAULT = (0xff000000),
		RGB_RED = (0x000000ff), //Добавляем RGB цвета
		RGB_GREEN = (0x0000ff00),
		RGB_BLUE = (0x00ffff00),
		RGB_DARK_BLUE = (0x00ff0000),
		RGB_WHITE = (0x00ffffff),
		RGB_ELLOW = (0x0000ffff),
		RGB_ELLOW_0 = (0x0000b3fd),
		RGB_ELLOW_1 = (0x0002f0eb)
	};

#define SHAPE_TAKE_PARAMETERS	unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color
#define SHAPE_GIVE_PARAMETERS	start_x, start_y, line_width, color

	class Shape
	{
	private:
	protected://Защищенные поля, доступны только внутри класса, и внутри его дочерних классов, к этим полям можно будет обращаться напрямую в дочерних классах (без get/set-методов)	
		//static const int MAX_X = 1800; //1920
		//static const int MAX_Y = 900; //1050
		Color color;
		unsigned int start_x;
		unsigned int start_y;
		unsigned int line_width;	//толщина линии
		////////////////////////////////////////////////////
		static const int MIN_START_X = 100;
		static const int MAX_START_X = 1000;
		static const int MIN_START_Y = 100;
		static const int MAX_START_Y = 500;
		static const int MIN_LINE_WIDTH = 1;
		static const int MAX_LINE_WIDTH = 32;
		static const int MIN_SIZE = 50;
		static const int MAX_SIZE = 550;
		static int count;
	public:
		Shape(SHAPE_TAKE_PARAMETERS) : color(color) { set_start_x(start_x);	set_start_y(start_y); set_line_width(line_width); count++; };
		virtual ~Shape() { count--; }
		virtual double get_area()  const = 0;
		virtual double get_perimeter()  const = 0;
		virtual void draw()  const = 0;

		static int get_count() { return count; }
		Color get_Color()const { return color; }
		void set_Color(Color color) { this->color = color; }
		unsigned int get_start_x()const { return start_x; }
		unsigned int get_start_y()const { return start_y; }
		unsigned int get_line_width()const { return line_width; }
		void set_start_x(unsigned int start_x)
		{
			if (start_x < MIN_START_X)start_x = MIN_START_X;
			if (start_x > MAX_START_X)start_x = MAX_START_X;
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_y < MIN_START_Y)start_y = MIN_START_Y;
			if (start_y > MAX_START_Y)start_y = MAX_START_Y;
			this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			if (line_width < MIN_LINE_WIDTH)line_width = MIN_LINE_WIDTH;
			if (line_width > MAX_LINE_WIDTH)line_width = MAX_LINE_WIDTH;
			this->line_width = line_width;
		}
		double filter_size(double size)
		{
			if (size < MIN_SIZE)size = MIN_SIZE;
			if (size > MAX_SIZE)size = MAX_SIZE;
			return size;
		}
		virtual void info()const
		{
			std::cout << "Площадь фигуры:  " << get_area() << endl;
			std::cout << "Периметр фигуры: " << get_perimeter() << endl;
			draw();
		}
	};
	int Shape::count = 0;

	class Circle : public Shape //производный класс Круг
	{
	private:
		double radius; //Ширина, здесь радиус
	public:
		// коонструктор, +вызывает конструктор базового класса для унаследованных полей
		Circle(int radius, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS) { set_radius(radius); }
		~Circle() {}
		// Геттеры и сеттеры
		void set_radius(int radius) { this->radius = filter_size(radius); }
		double get_radius()const { return this->radius; }
		double get_area()const override { return get_radius() * get_radius() * PI; }
		double get_diameter()const { return 2 * radius; }
		double get_perimeter()const { return get_radius() * PI * 2; }

		// Методы
		void info()const override
		{
			std::cout << typeid(*this).name() << endl;
			Shape::info();
			std::cout << " Circle radius = " << radius << " adres: " << this << "\n";
		}
		void draw()const override
		{
			//system("CLS");// очистка экрана консоли
			HWND hwnd = GetConsoleWindow();//Handler to Window(обработчик или дескриптор окна)			
			HDC hdc = GetDC(hwnd); // выделяем память  потом надо сделать ReleaseDC(hwnd, hdc);
			int line = line_width > radius ? radius : line_width;
			//HPEN hPen = CreatePen(PS_SOLID, line, get_Color());
			HPEN hPen = CreatePen(PS_SOLID, line, get_Color());

			//HBRUSH hBrush = CreateSolidBrush(get_Color()); //Закрашеный
			HBRUSH hBrush = CreateSolidBrush(Color::RGB_GREEN); //Закрасить зеленым //Geometry::
			//HBRUSH hBrush = CreateSolidBrush(Geometry::Color::CONSOLE_DEFAULT); //Только границы

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			/*		if (start_x + 2 * radius - line > MAX_X || start_y + 2 * radius - line > MAX_Y)
					{
						HANDLE hConcole = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hConcole, CONSOLE_RED);
						cout << "Фигура выходит за пределы экрана\n Нарисовать в пределах экрана в левом нижнем углу?";
						while (true)
						{
							char key;
							cin >> key;
							if (key == 'n' || key == 'N')
							{
								::Ellipse(hdc, start_x, start_y, start_x + 2 * radius - line, start_y + 2 * radius - line);
								break;
							}
							else if (key == 'y' || key == 'Y')
							{
								::Ellipse(hdc, MAX_X - 2 * radius - line, MAX_Y - 2 * radius - line, MAX_X, MAX_Y);
								break;
							}
						}
						SetConsoleTextAttribute(hConcole, 0x07);
					}
					else
					{
						::Ellipse(hdc, start_x, start_y, start_x + 2 * radius - line, start_y + 2 * radius - line);
					}*/

			::Ellipse(hdc, start_x, start_y, start_x + get_diameter(), start_y + get_diameter());

			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}
	};

	class Rectangle : public Shape
	{
	private:
		double width;
		double height;
	public:
		Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_width(width);
			set_height(height);
		}
		~Rectangle() {};

		double get_width()const { return width; }
		double get_height()const { return height; }
		void set_width(double width) { this->width = filter_size(width); }
		void set_height(double height) { this->height = filter_size(height); }
		double get_area()  const override { return width * height; };
		double get_perimeter()  const override { return (width + height) * 2; }

		void draw()const override
		{
			HWND hwnd = GetConsoleWindow(); //1)Получаем дескриптор окна консоли. Переменная в которой хранится описание чего-то.
			//description 
			//HWND - Handler to Window(обработчик или дескриптор окна)
			HDC hdc = GetDC(hwnd); //2) получаем контекст устройства (Device context) окна консоли
			//DC - это то на чем мы будем рисовать
			// выделяем память  потом надо сделать ReleaseDC(hwnd, hdc);
			HPEN hPen = CreatePen(PS_SOLID, 5, get_Color());
			//3) Создаем карандаш, Pen рисует контур фигуры
			//PS_SOLID - сплошная линия
			//5-толщина линии в пикселях
			// 4) cоздаем кисточку
			HBRUSH hBrush = CreateSolidBrush(get_Color());
			//5) Выбираем чем и на чем рисовать
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			//6) Рисуем прямоугольник:
			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);
			//чтобы показать что это глобальная функция надо поставить двойное двоеточие без операнда слева.
			//  координаты верхнего левого угла, координаты нижнего правого угла.

			//7) Освобождаем ресурсы:
			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина: " << width << endl;
			cout << "Ширина: " << height << endl;
			Shape::info();
		}
	};
	
		class Square :public Rectangle
		{
		public:
			Square(double side, SHAPE_TAKE_PARAMETERS) :Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {}
			~Square() {}
		};

		class Triangle :public Shape
		{
		public:
			Triangle(SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS) {}
			~Triangle() {}
			virtual double get_height()const = 0;
			void info() const override
			{
				cout << "Высота треугольника: " << get_height() << "\n";
				Shape::info();
			}
		};

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

		class IsoscelesTriangle :public Triangle //Равносторонний треугольник
		{
			double side1;
			double side2; //Основание
		public:
			IsoscelesTriangle(double side1, double side2, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS) {
				set_side1(side1); set_side2(side2);
			}
			~IsoscelesTriangle() {};

			double get_side1()const { return side1; }
			double get_side2()const { return side2; }
			void set_side1(double side1) { this->side1 = filter_size(side1); }
			void set_side2(double side2) { this->side2 = filter_size(side2); }
			double get_height()const override { return sqrt(side1 * side1 - side2 / 2 * side2 / 2); }
			double get_area()const override { return side2 / 2 * get_height(); }
			double get_perimeter()const override { return side1 * 2 + side2; }
			void info()const override
			{
				cout << typeid(*this).name() << endl;
				cout << "Равнобедренная сторона: " << side1 << endl;
				cout << "Основание: " << side2 << endl;
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
					{side2 + start_x, get_height() + start_y},
					{side2 / 2 + start_x, start_y}
				};
				// Рисуем треугольник:
				Polygon(hdc, point, 3);

				DeleteObject(hBrush);
				DeleteObject(hPen);

				ReleaseDC(hwnd, hdc);
			}
		};

		class RightTriangle :public Triangle //Равносторонний треугольник
		{
			double side1; //Катеты вертикальный
			double side2; //Катеты горизонтальный
		public:
			RightTriangle(double side1, double side2, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS) {
				set_side1(side1); set_side2(side2);
			}
			~RightTriangle() {};

			double get_side1()const { return side1; }
			double get_side2()const { return side2; }
			void set_side1(double side1) { this->side1 = side1; }
			void set_side2(double side2) { this->side2 = side2; }
			double get_height()const override { return side1; }
			double get_hypotenuse()const { return sqrt(side1 * side1 + side2 * side2); }
			double get_area()const override { return side1 * side2; }
			double get_perimeter()const override { return side1 + side2 + get_hypotenuse(); }
			void info()const override
			{
				cout << typeid(*this).name() << endl;
				cout << "вертикальный катет: " << side1 << endl;
				cout << "горизонтальный катет : " << side2 << endl;
				cout << "Основание: " << get_hypotenuse() << endl;
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
					{start_x, start_y},
					{start_x, side1 + start_y},
					{side2 + start_x, side1 + start_y}
				};
				// Рисуем треугольник:
				Polygon(hdc, point, 3);

				DeleteObject(hBrush);
				DeleteObject(hPen);

				ReleaseDC(hwnd, hdc);
			}
		};

	}




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