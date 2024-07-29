#pragma once
#include"Shape.h"

namespace Geometry
{
	class Circle : public Shape //производный класс Круг
	{
	private:
		double radius; //Ширина, здесь радиус
	public:
		// коонструктор, +вызывает конструктор базового класса для унаследованных полей
		Circle(int radius, SHAPE_TAKE_PARAMETERS);
		~Circle();
		// Геттеры и сеттеры
		void set_radius(int radius);
		double get_radius()const;
		double get_area()const override;
		double get_diameter()const;
		double get_perimeter()const;

		// Методы
		void info()const override;
		void draw()const override;
	};
}