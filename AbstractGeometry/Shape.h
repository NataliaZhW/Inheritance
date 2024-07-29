#pragma once
#define _USE_MATH_DEFINES //файлик с константами типа Пи - M_PI можно использовать
#include <iostream>
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
	protected:
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
		Shape(SHAPE_TAKE_PARAMETERS);
		virtual ~Shape();
		virtual double get_area()  const = 0;
		virtual double get_perimeter()  const = 0;
		virtual void draw()  const = 0;

		static int get_count();
		Color get_Color()const;
		void set_Color(Color color);
		unsigned int get_start_x()const;
		unsigned int get_start_y()const;
		unsigned int get_line_width()const;
		void set_start_x(unsigned int start_x);
		void set_start_y(unsigned int start_y);
		void set_line_width(unsigned int line_width);
		double filter_size(double size);
		virtual void info()const;
	};
}
	