#include"AbstractGeometry.h"
//#include"Shape_.cpp"

//namespace Geometry
//{

	class Rectangle_ : public Shape
	{
	private:
		double width;
		double height;
	public:
		Rectangle_(double width, double height, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_width(width);
			set_height(height);
		}
		~Rectangle_() {};

		double get_width()const { return width; }
		double get_height()const { return height; }
		void set_width(double width) { this->width = filter_size(width); }
		void set_height(double height) { this->height = filter_size(height); }
		double get_area()  const override { return width * height; };
		double get_perimeter()  const override { return (width + height) * 2; }

		void draw()const override
		{
			HWND hwnd = GetConsoleWindow(); //1)Получаем дескриптор окна консоли. Переменная в которой хранится описание чего-то.
			//description 
			//HWND - Handler to Window(обработчик или дескриптор окна)
			HDC hdc = GetDC(hwnd); //2) получаем контекст устройства (Device context) окна консоли
			//DC - это то на чем мы будем рисовать
			// выделяем память  потом надо сделать ReleaseDC(hwnd, hdc);
			HPEN hPen = CreatePen(PS_SOLID, 5, get_Color());
			//3) Создаем карандаш, Pen рисует контур фигуры
			//PS_SOLID - сплошная линия
			//5-толщина линии в пикселях
			// 4) cоздаем кисточку
			HBRUSH hBrush = CreateSolidBrush(get_Color());
			//5) Выбираем чем и на чем рисовать
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			//6) Рисуем прямоугольник:
			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);
			//чтобы показать что это глобальная функция надо поставить двойное двоеточие без операнда слева.
			//  координаты верхнего левого угла, координаты нижнего правого угла.

			//7) Освобождаем ресурсы:
			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина: " << width << endl;
			cout << "Ширина: " << height << endl;
			Shape::info();
		}
	};
//}