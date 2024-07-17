
#include <iostream>
#include <math.h>
#include <cmath>
#include <Windows.h>

using namespace std;
void draw();
void ColorText();

int main()
{
	draw();
	ColorText();
}
void draw()
{
	HWND hwnd = GetConsoleWindow(); //1)�������� ���������� ���� �������. ���������� � ������� �������� �������� ����-��.
	//description 
	//HWND - Handler to Window(���������� ��� ���������� ����)
	HDC hdc = GetDC(hwnd); //2) �������� �������� ���������� (Device context) ���� �������
	//DC - ��� �� �� ��� �� ����� ��������
	for (int i = 0x00000000; i <= 0xffffffff; i++)
	{


		HPEN hPen = CreatePen(PS_SOLID, 5, i);
		//3) ������� ��������, Pen ������ ������ ������
		//PS_SOLID - �������� �����
		//5-������� ����� � ��������
		// 4) c������ ��������
		HBRUSH hBrush = CreateSolidBrush(i);
		//5) �������� ��� � �� ��� ��������
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		//6) ������ �������������:
		::Rectangle(hdc, 200, 200, 100, 30);
		printf("\t%X", i);
		cout << " * " << i << " ";
		//����� �������� ��� ��� ���������� ������� ���� ��������� ������� ��������� ��� �������� �����.
		//7) ����������� �������:
		DeleteObject(hPen);
		DeleteObject(hBrush);

	}
}
void ColorText()
{
	HANDLE hConcole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 00000; i <= 40000; i++)
	{
		printf("\t%X", i);
		SetConsoleTextAttribute(hConcole, i);
		cout << "*";
		SetConsoleTextAttribute(hConcole, 0x07);
		cout << i;
	}
}