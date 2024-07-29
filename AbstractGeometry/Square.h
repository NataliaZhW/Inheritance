#pragma once
#include"Rectangle.h"

namespace Geometry
{
	class Square :public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS);
		~Square();
	};
}