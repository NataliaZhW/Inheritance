
#include"AbstractGeometry.h"
//namespace Geometry
//{
	class Shape
	{
	private:
	protected://«ащищенные пол€, доступны только внутри класса, и внутри его дочерних классов, к этим пол€м можно будет обращатьс€ напр€мую в дочерних классах (без get/set-методов)	
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
			cout << "ѕлощадь фигуры:  " << get_area() << endl;
			cout << "ѕериметр фигуры: " << get_perimeter() << endl;
			draw();
		}
	};
	int Shape::count = 0;

//}