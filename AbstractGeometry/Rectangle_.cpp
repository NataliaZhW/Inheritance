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
			HWND hwnd = GetConsoleWindow(); //1)�������� ���������� ���� �������. ���������� � ������� �������� �������� ����-��.
			//description 
			//HWND - Handler to Window(���������� ��� ���������� ����)
			HDC hdc = GetDC(hwnd); //2) �������� �������� ���������� (Device context) ���� �������
			//DC - ��� �� �� ��� �� ����� ��������
			// �������� ������  ����� ���� ������� ReleaseDC(hwnd, hdc);
			HPEN hPen = CreatePen(PS_SOLID, 5, get_Color());
			//3) ������� ��������, Pen ������ ������ ������
			//PS_SOLID - �������� �����
			//5-������� ����� � ��������
			// 4) c������ ��������
			HBRUSH hBrush = CreateSolidBrush(get_Color());
			//5) �������� ��� � �� ��� ��������
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			//6) ������ �������������:
			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);
			//����� �������� ��� ��� ���������� ������� ���� ��������� ������� ��������� ��� �������� �����.
			//  ���������� �������� ������ ����, ���������� ������� ������� ����.

			//7) ����������� �������:
			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "������: " << width << endl;
			cout << "������: " << height << endl;
			Shape::info();
		}
	};
//}