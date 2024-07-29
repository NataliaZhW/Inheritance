#pragma once

#include"Triangle.h"

namespace Geometry
{
	class RightTriangle :public Triangle //�������������� �����������
	{
		double side1; //������ ������������
		double side2; //������ ��������������
	public:
		RightTriangle(double side1, double side2, SHAPE_TAKE_PARAMETERS);
		~RightTriangle() ;

		double get_side1()const;
		double get_side2()const;
		void set_side1(double side1);
		void set_side2(double side2);
		double get_height()const override;
		double get_hypotenuse()const;
		double get_area()const override;
		double get_perimeter()const override;
		void info()const override;

		void draw()const override;
	};
}