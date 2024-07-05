// Figure

#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

#define delimiter "\n----------------------------------------------\n\n"
#define PI 3.14


class Figure //базовый класс виртуальный
{
private:
	int width; //Ширина
protected:
	static int colich; //Считает сколько раз вызывалась функция подсчета площади
	static void setColich() { colich++; }
public:
	Figure(int width) { setWidth(width); }//конструктор
	~Figure() {}//деструктор    
	// Геттеры и сеттеры    
	static int getColich() { return colich; }
	void setWidth(int width) { this->width = width; }
	int getWidth()const { return this->width; }
	// Методы
	virtual void info()const { cout << " width " << width; }
	virtual double Area()const = 0; //Виртуальная функция Площадь
	virtual double Perimetr()const = 0; //Виртуальная функция Периметр
	virtual void Picture()const = 0; //Виртуальная функция Рисунок
};
int Figure::colich = 0;

class Circle : public Figure //производный класс Круг
{
private:
public:
	// коонструктор, +вызывает конструктор базового класса для унаследованных полей
	Circle(int width) : Figure(width) {}
	~Circle() {}
	// Геттеры и сеттеры
	static int getColich() { return colich; }
	void setWidth(int width) { Figure::setWidth(width); }
	int getWidth()const { return Figure::getWidth(); }

	// Методы
	void info()const override { Figure::info(); cout << " Circle " << this; }
	double Area()const override
	{
		cout << "\nфункция Площадь круга!\n";
		setColich();
		return getWidth() * getWidth() * PI;
	}
	virtual double Perimetr()const
	{
		cout << "\nфункция Периметр круга!\n";
		return getWidth() * PI * 2;
	}
	virtual void Picture()const
	{
		cout << "\nфункция Рисунок круга!\n";
		for (int i = 0; i < getWidth() + 2; i++)
		{
			for (int j = 0; j < getWidth() + 2; j++)
			{
				if ((i - (getWidth() / 2 + 1)) * (i - (getWidth() / 2 + 1)) + (j - (getWidth() / 2 + 1)) * (j - (getWidth() / 2 + 1)) <= (getWidth() - (getWidth() / 2 + 1)) * (getWidth() - (getWidth() / 2 + 1)))
				{
					cout << " *";
				}
				else
				{
					cout << "  ";
				}
			}
			cout << endl;
		}
	}
};

class Square : public Figure //производный класс Квадрат
{
private:
public:
	// коонструктор, +вызывает конструктор базового класса для унаследованных полей
	Square(int width) : Figure(width) {}
	~Square() {}
	// Геттеры и сеттеры
	static int getColich() { return colich; }
	void setWidth(int width) { Figure::setWidth(width); }
	int getWidth()const { return Figure::getWidth(); }

	// Методы
	void info()const override { Figure::info(); cout << " Square " << this; }
	double Area()const override
	{
		cout << "\nфункция Площадь квадрата!\n";
		setColich();
		return getWidth() * getWidth();
	}
	virtual double Perimetr()const
	{
		cout << "\nфункция Периметр квадрата!\n";
		return getWidth() * 4;
	}
	virtual void Picture()const
	{
		cout << "\nфункция Рисунок квадрата!\n";
		for (int i = 0; i < getWidth(); i++)
		{
			for (int j = 0; j < getWidth(); j++)
			{
				cout << " *";
			}
			cout << endl;
		}
	}
};

class Poligon : public Figure //производный класс Многоугольник виртуальный
{
private:
	int height; //Высота
protected:
public:
	//коонструктор, +вызывает конструктор базового класса для унаследованных полей
	Poligon(int width, int height) : Figure(width) { setHeight(height); }//this->height = height;
	~Poligon() {}
	//Геттеры и сеттеры 
	static int getColich() { return colich; }
	void setWidth(int width) { Figure::setWidth(width); }
	int getWidth()const { return Figure::getWidth(); }
	void setHeight(int height) { this->height = height; }
	int getHeight()const { return this->height; }
};

class Rectangle : public Poligon //производный класс Прямоугольник
{
private:
public:
	// коонструктор, +вызывает конструктор базового класса для унаследованных полей
	Rectangle(int width, int height) : Poligon(width, height) {}
	~Rectangle() {}
	// Геттеры и сеттеры
	static int getColich() { return colich; }
	void setWidth(int width) { Poligon::setWidth(width); }
	int getWidth()const { return Poligon::getWidth(); }
	//void setHeight(int height) { Poligon::setHeight(height); }
	//int getHeight()const { Poligon::getHeight(); } //Почему!??? выдает ошибку

	// Методы
	void info()const override { Poligon::info(); cout << " " << Poligon::getHeight() << " Rectangle " << this; }
	double Area()const override
	{
		cout << "\nфункция Площадь прямоугольника!\n";
		setColich();
		return getWidth() * getHeight();
	}
	virtual double Perimetr()const
	{
		cout << "\nфункция Периметр прямоугольника!\n";
		return (getWidth() + getHeight()) * 2;
	}
	virtual void Picture()const
	{
		cout << "\nфункция Рисунок прямоугольника!\n";
		for (int i = 0; i < getWidth(); i++)
		{
			for (int j = 0; j < getHeight(); j++)
			{
				cout << " *";
			}
			cout << endl;
		}
	}
};

class Triangle : public Poligon //производный класс Треугольник
{
private:
public:
	// коонструктор, +вызывает конструктор базового класса для унаследованных полей
	Triangle(int width, int height) : Poligon(width, height) {}
	~Triangle() {}
	// Геттеры и сеттеры
	static int getColich() { return colich; }
	void setWidth(int width) { Poligon::setWidth(width); }
	int getWidth()const { return Poligon::getWidth(); }
	//void setHeight(int height) { Poligon::setHeight(height); }
	//int getHeight()const { Poligon::getHeight(); } //Почему!??? выдает ошибку

	// Методы
	void info()const override { Poligon::info(); cout << " " << Poligon::getHeight() << " Rectangle " << this; }
	double Area()const override
	{
		cout << "\nфункция Площадь треугольника!\n";
		setColich();
		return getWidth() * getHeight() / 2;
	}
	virtual double Perimetr()const
	{
		cout << "\nфункция Периметр треугольника, если он равнобедренный!\n";
		return 2 * sqrt(pow(getWidth(), 2) + pow(getHeight(), 2)) + 2 * getWidth();
	}
	virtual void Picture()const
	{
		cout << "\nфункция Рисунок треугольника!\n";
		for (int i = 0; i < getHeight() + 3; i++)
		{
			for (int j = 0; j < getWidth() + 3; j++)
			{
				if (j >= (getWidth()  - i * getWidth() / (getHeight() + .5) - .1) / 2 && j <= (getWidth() + .1 + i *( getWidth()+ .1 ) / (getHeight()+.5) ) / 2)
				{
					cout << " *";
				}
				else
				{
					cout << "  ";
				}
			}
			cout << endl;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Circle circle1(15);
	circle1.info();
	/*int f = circle1.getWidth();
	cout << circle1.getWidth() << "\n" << f << "\n";*/ //Почему!?????? выводит только f
	cout << circle1.Area() << "\n";
	cout << circle1.Perimetr() << "\n";
	circle1.Picture();
	cout << "\nфункция Площадь вызвалась " << Figure::getColich() << " раз\n";
	cout << delimiter;

	Square square1(3);
	square1.info();
	cout << square1.Area() << "\n";
	cout << square1.Perimetr() << "\n";
	square1.Picture();
	cout << "\nфункция Площадь вызвалась " << Figure::getColich() << " раз\n";
	cout << delimiter;


	Rectangle rectangle1(3, 4);
	rectangle1.info();
	cout << rectangle1.Area() << "\n";
	cout << rectangle1.Perimetr() << "\n";
	rectangle1.Picture();
	cout << "\nфункция Площадь вызвалась " << Figure::getColich() << " раз\n";
	cout << delimiter;


	Triangle triangle1(16, 10);
	triangle1.info();
	cout << triangle1.Area() << "\n";
	cout << triangle1.Perimetr() << "\n";
	triangle1.Picture();
	cout << "\nфункция Площадь вызвалась " << Figure::getColich() << " раз\n";
	cout << delimiter;

};

