#pragma once

#include"Shape.h"

namespace Geometry
{
	class Triangle :public Shape
	{
	public:
		Triangle(SHAPE_TAKE_PARAMETERS);
		~Triangle();
		virtual double get_height()const = 0;
		void info() const override;
	};
}
