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
		CONSOLE_BLUE = 0x09,
		CONSOLE_GREEN = 0xAA,
		CONSOLE_RED = 0xCC,
		CONSOLE_DEFAULT = 0x07,
		//RGB_RED = (0xFF0000), //��������� RGB �����
		//RGB_GREEN = (0x00FF00),
		//RGB_BLUE = (0xFFFF00),
		//RGB_WHITE = (0xFFFFFF)
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
			cout << "������� ������:  " << get_area() << endl;
			cout << "�������� ������: " << get_perimeter() << endl;
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
			cout << "����� �������: " << side << endl;
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
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow(); //1)�������� ���������� ���� �������. ���������� � ������� �������� �������� ����-��.
			//description 
			//HWND - Handler to Window(���������� ��� ���������� ����)
			HDC hdc = GetDC(hwnd); //2) �������� �������� ���������� (Device context) ���� �������
			//DC - ��� �� �� ��� �� ����� ��������
			HPEN hPen = CreatePen(PS_SOLID, 5, get_Color());
			//3) ������� ��������, Pen ������ ������ ������
			//PS_SOLID - �������� �����
			//5-������� ����� � ��������
			// 4) c������ ��������
			HBRUSH hBrush = CreateSolidBrush(get_Color());
			//5) �������� ��� � �� ��� ��������
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			//6) ������ �������������:
			::Rectangle(hdc, 250, 50, 400, 150);
			//����� �������� ��� ��� ���������� ������� ���� ��������� ������� ��������� ��� �������� �����.
			//7) ����������� �������:
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
		virtual void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "������: " << width << endl;
			cout << "������: " << height << endl;
			Shape::info();
		}
	};
	class Circle : public Shape //����������� ����� ����
	{
	private:
		int width{ 10 }; //������, ����� ������
	public:
		// ������������, +�������� ����������� �������� ������ ��� �������������� �����
		Circle(int width, Color color) : Shape(color) {}
		~Circle() {}
		// ������� � �������
		void setWidth(int width) { this->width = width; }
		int getWidth()const { return width; }

		// ������
		void info()const override { Shape::info(); cout << " Circle " << this<< "\n"; }
		double get_area()const override
		{
			return getWidth() * getWidth() * PI;
		}
		virtual double get_perimeter()const
		{
			return getWidth() * PI * 2;
		}		
		void draw()const override
		{
			//system("CLS");
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 9, get_Color());
			HBRUSH hBrush = CreateSolidBrush(Geometry::Color::CONSOLE_DEFAULT);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			::Ellipse(hdc, 100, 100, 30 * width, 30 * width);

			DeleteObject(hPen);
			DeleteObject(hBrush); 

			ReleaseDC(hwnd, hdc);
		}
	};


}
int main()
{
	setlocale(LC_ALL, "Russian");
	Geometry::Square square1(5, Geometry::Color::CONSOLE_GREEN);
	//cout << "����� ������� : " << square1.get_side() << endl;
	//cout << "������� ��������:  " << square1.get_area() << endl;
	//cout << "�������� ��������: " << square1.get_perimeter() << endl;
	//square1.draw();
	square1.info();

	Geometry::Rectangle rectangle1(15, 8, Geometry::Color::CONSOLE_GREEN);
	rectangle1.info();

	Geometry::Circle circle1(50, Geometry::Color::CONSOLE_RED);
	circle1.info();
	//system("pause"); 
}