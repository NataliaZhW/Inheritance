﻿#include <iostream>
#include <math.h>
#include <cmath>
#include <Windows.h>

using namespace std;

#define _USE_MATH_DEFINES //файлик с константами типа Пи - M_PI можно использовать

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
		RGB_RED = (0x00ff0000), //Добавляем RGB цвета
		RGB_GREEN = (0x0000ff00),
		RGB_BLUE = (0x00ffff00),
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
		static const int MAX_X = 1920;
		static const int MAX_Y = 1050;
		Color color;
		unsigned int start_x;
		unsigned int start_y;
		unsigned int line_width;	//толщина линии
	public:
		Shape(SHAPE_TAKE_PARAMETERS) : color(color) { set_start_x(start_x);	set_start_y(start_y); set_line_width(line_width); };
		virtual ~Shape() {};
		virtual double get_area()  const = 0;
		virtual double get_perimeter()  const = 0;
		virtual void draw()  const = 0;

		Color get_Color()const { return color; }
		void set_Color(Color color) { this->color = color; }
		unsigned int get_start_x()const { return start_x; }
		unsigned int get_start_y()const { return start_y; }
		unsigned int get_line_width()const { return line_width; }
		void set_start_x(unsigned int start_x) { this->start_x = start_x; }
		void set_start_y(unsigned int start_y) { this->start_y = start_y; }
		void set_line_width(unsigned int line_width) { this->line_width = line_width; }

		virtual void info()const
		{
			cout << "Площадь фигуры:  " << get_area() << endl;
			cout << "Периметр фигуры: " << get_perimeter() << endl;
			draw();
		}
	};

	//class Square : public Shape
	//{
	//private:
	//	double side;
	//public:
	//	Square(double side, Color color) : Shape(color) { set_side(side); }
	//	virtual ~Square() {};

	//	double get_area()  const override { return side * side; };
	//	void set_side(double side) { this->side = side; }

	//	double get_perimeter()  const override { return side * 4; }
	//	void draw()const override
	//	{
	//		HANDLE  hConcole = GetStdHandle(STD_OUTPUT_HANDLE);
	//		SetConsoleTextAttribute(hConcole, get_Color());
	//		for (int i = 0; i < side; i++)
	//		{
	//			for (int i = 0; i < side; i++)
	//			{
	//				cout << "* ";
	//			}
	//			cout << endl;
	//		}
	//		SetConsoleTextAttribute(hConcole, Color::CONSOLE_DEFAULT);
	//	}
	//	double get_side()const
	//	{
	//		return side;
	//	}
	//	virtual void info()const
	//	{
	//		cout << typeid(*this).name() << endl;
	//		cout << "Длина стороны: " << side << endl;
	//		Shape::info();
	//	}
	//};

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
		virtual ~Rectangle() {};

		double get_area()  const override { return width * height; };
		void set_width(double width) { this->width = width; }
		void set_height(double height) { this->height = height; }

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
		/*void draw1()const
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
		}*/
		double get_width()const { return width; }
		double get_height()const { return height; }
		//void set_width(double width) { this->width = width; }
		//void set_height(double height) { this->height = height; }
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина: " << width << endl;
			cout << "Ширина: " << height << endl;
			Shape::info();
		}
	};
	class Circle : public Shape //производный класс Круг
	{
	private:
		double radius; //Ширина, здесь радиус
	public:
		// коонструктор, +вызывает конструктор базового класса для унаследованных полей
		Circle(int radius, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS) { set_radius(radius); }
		~Circle() {}
		// Геттеры и сеттеры
		void set_radius(int radius) { this->radius = radius; }
		double get_radius()const { return this->radius; }

		// Методы
		void info()const override { Shape::info(); cout << " Circle radius = " << radius << " adres: " << this << "\n"; }
		double get_area()const override { return get_radius() * get_radius() * PI; }
		virtual double get_perimeter()const { return get_radius() * PI * 2; }
		void draw()const override
		{
			//system("CLS");// очистка экрана консоли
			HWND hwnd = GetConsoleWindow();//Handler to Window(обработчик или дескриптор окна)			
			HDC hdc = GetDC(hwnd); // выделяем память  потом надо сделать ReleaseDC(hwnd, hdc);
			int line = line_width > radius ? radius : line_width;
			//HPEN hPen = CreatePen(PS_SOLID, line, get_Color());
			HPEN hPen = CreatePen(PS_SOLID, line, get_Color());

			//HBRUSH hBrush = CreateSolidBrush(get_Color()); //Закрашеный
			HBRUSH hBrush = CreateSolidBrush(Geometry::Color::RGB_GREEN); //Закрасить зеленым
			//HBRUSH hBrush = CreateSolidBrush(Geometry::Color::CONSOLE_DEFAULT); //Только границы

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			if (start_x + 2 * radius - line > MAX_X || start_y + 2 * radius - line > MAX_Y)
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
						::Ellipse(hdc, MAX_X - 2 * radius - line, MAX_Y - 2 * radius - line, 1920, 1050);
						break;
					}
				}
				SetConsoleTextAttribute(hConcole, 0x07);
			}

			DeleteObject(hPen);
			DeleteObject(hBrush);
			
			ReleaseDC(hwnd, hdc);
		}
	};
	//class Triangle : public Shape
	//{
	//public:
	//	Triangle : public Shape();
	//	~Triangle : public Shape();

	//private:

	//};

	//Triangle : public Shape::Triangle : public Shape()
	//{
	//}

	//Triangle : public Shape::~Triangle : public Shape()
	//{
	//}


}
int main()
{
	setlocale(LC_ALL, "Russian");
	//Geometry::Square square1(5, Geometry::Color::CONSOLE_GREEN);
	////cout << "Длина стороны : " << square1.get_side() << endl;
	////cout << "Площадь квадрата:  " << square1.get_area() << endl;
	////cout << "Периметр квадрата: " << square1.get_perimeter() << endl;
	////square1.draw();
	//square1.info();

	Geometry::Rectangle rectangle1(150, 80, 50, 250, 3, Geometry::Color::RGB_BLUE);
	rectangle1.info();

	Geometry::Circle circle1(100, 200, 1050, 70, Geometry::Color::RGB_ELLOW);
	circle1.info();
	//system("pause"); 
}