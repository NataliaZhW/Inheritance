
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
	HWND hwnd = GetConsoleWindow(); //1)Получаем дескриптор окна консоли. Переменная в которой хранится описание чего-то.
	//description 
	//HWND - Handler to Window(обработчик или дескриптор окна)
	HDC hdc = GetDC(hwnd); //2) получаем контекст устройства (Device context) окна консоли
	//DC - это то на чем мы будем рисовать
	for (int i = 0x00000000; i <= 0xffffffff; i++)
	{


		HPEN hPen = CreatePen(PS_SOLID, 5, i);
		//3) Создаем карандаш, Pen рисует контур фигуры
		//PS_SOLID - сплошная линия
		//5-толщина линии в пикселях
		// 4) cоздаем кисточку
		HBRUSH hBrush = CreateSolidBrush(i);
		//5) Выбираем чем и на чем рисовать
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		//6) Рисуем прямоугольник:
		::Rectangle(hdc, 200, 200, 100, 30);
		printf("\t%X", i);
		cout << " * " << i << " ";
		//чтобы показать что это глобальная функция надо поставить двойное двоеточие без операнда слева.
		//7) Освобождаем ресурсы:
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