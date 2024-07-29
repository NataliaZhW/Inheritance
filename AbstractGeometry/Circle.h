#pragma once
#include"Shape.h"

namespace Geometry
{
	class Circle : public Shape //����������� ����� ����
	{
	private:
		double radius; //������, ����� ������
	public:
		// ������������, +�������� ����������� �������� ������ ��� �������������� �����
		Circle(int radius, SHAPE_TAKE_PARAMETERS);
		~Circle();
		// ������� � �������
		void set_radius(int radius);
		double get_radius()const;
		double get_area()const override;
		double get_diameter()const;
		double get_perimeter()const;

		// ������
		void info()const override;
		void draw()const override;
	};
}