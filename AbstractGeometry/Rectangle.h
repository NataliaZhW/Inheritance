#pragma once
#include"Shape.h"

namespace Geometry
{
	class Rectangle : public Shape
	{
	private:
		double width;
		double height;
	public:
		Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS);
		~Rectangle();

		double get_width()const;
		double get_height()const;
		void set_width(double width);
		void set_height(double height);
		double get_area()  const override;
		double get_perimeter()  const override;

		void draw()const override;
		void info()const override;
	};
}