#include"AbstractGeometry.h"
//#include"Shape_.cpp"

//namespace Geometry
//{
	class Circle : public Shape //����������� ����� ����
	{
	private:
		double radius; //������, ����� ������
	public:
		// ������������, +�������� ����������� �������� ������ ��� �������������� �����
		Circle(int radius, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS) { set_radius(radius); }
		~Circle() {}
		// ������� � �������
		void set_radius(int radius) { this->radius = filter_size(radius); }
		double get_radius()const { return this->radius; }
		double get_area()const override { return get_radius() * get_radius() * PI; }
		double get_diameter()const { return 2 * radius; }
		double get_perimeter()const { return get_radius() * PI * 2; }

		// ������
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			Shape::info();
			cout << " Circle radius = " << radius << " adres: " << this << "\n";
		}
		void draw()const override
		{
			//system("CLS");// ������� ������ �������
			HWND hwnd = GetConsoleWindow();//Handler to Window(���������� ��� ���������� ����)			
			HDC hdc = GetDC(hwnd); // �������� ������  ����� ���� ������� ReleaseDC(hwnd, hdc);
			int line = line_width > radius ? radius : line_width;
			//HPEN hPen = CreatePen(PS_SOLID, line, get_Color());
			HPEN hPen = CreatePen(PS_SOLID, line, get_Color());

			//HBRUSH hBrush = CreateSolidBrush(get_Color()); //����������
			HBRUSH hBrush = CreateSolidBrush(Color::RGB_GREEN); //��������� ������� //Geometry::
			//HBRUSH hBrush = CreateSolidBrush(Geometry::Color::CONSOLE_DEFAULT); //������ �������

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			/*		if (start_x + 2 * radius - line > MAX_X || start_y + 2 * radius - line > MAX_Y)
					{
						HANDLE hConcole = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hConcole, CONSOLE_RED);
						cout << "������ ������� �� ������� ������\n ���������� � �������� ������ � ����� ������ ����?";
						while (true)
						{
							char key;
							cin >> key;
							if (key == 'n' || key == 'N')
							{
								::Ellipse(hdc, start_x, start_y, start_x + 2 * radius - line, start_y + 2 * radius - line);
								break;
							}
							else if (key == 'y' || key == 'Y')
							{
								::Ellipse(hdc, MAX_X - 2 * radius - line, MAX_Y - 2 * radius - line, MAX_X, MAX_Y);
								break;
							}
						}
						SetConsoleTextAttribute(hConcole, 0x07);
					}
					else
					{
						::Ellipse(hdc, start_x, start_y, start_x + 2 * radius - line, start_y + 2 * radius - line);
					}*/

			::Ellipse(hdc, start_x, start_y, start_x + get_diameter(), start_y + get_diameter());

			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}
	};
//}