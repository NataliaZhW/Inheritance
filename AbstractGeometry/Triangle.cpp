#include"AbstractGeometry.h"
//#include"Shape_.cpp"
//namespace Geometry
//{
	class Triangle :public Shape
	{
	public:
		Triangle(SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS) {}
		~Triangle() {}
		virtual double get_height()const = 0;
		void info() const override
		{
			cout << "Высота треугольника: " << get_height() << "\n";
			Shape::info();
		}
	};
//}