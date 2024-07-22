#include"AbstractGeometry.h"
//#include"Shape_.cpp"
//#include"Rectangle_.cpp"
namespace Geometry
{
	class Square_ :public Rectangle_
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) :Rectangle_(side, side, SHAPE_GIVE_PARAMETERS) {}
		~Square() {}
	};
}