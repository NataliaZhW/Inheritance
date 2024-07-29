#pragma once

#include"Triangle.h"

namespace Geometry
{
	class IsoscelesTriangle :public Triangle //Равносторонний треугольник
	{
		double side1;
		double side2; //Основание
	public:
		IsoscelesTriangle(double side1, double side2, SHAPE_TAKE_PARAMETERS);
		~IsoscelesTriangle();

		double get_side1()const;
		double get_side2()const;
		void set_side1(double side1);
		void set_side2(double side2);
		double get_height()const override;
		double get_area()const override;
		double get_perimeter()const override;
		void info()const override;
		void draw()const override;
	};
}