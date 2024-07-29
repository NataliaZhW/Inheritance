#pragma once

#include"Triangle.h"

namespace Geometry
{
	class EquilateralTriangle :public Triangle //Равносторонний треугольник
	{
		double side;
	public:
		EquilateralTriangle(double side, SHAPE_TAKE_PARAMETERS);
		~EquilateralTriangle();

		double get_side()const;
		void set_side(double side);
		double get_height()const override;
		double get_area()const override;
		double get_perimeter()const override;
		void info()const override;
		void draw()const override;
	};
}