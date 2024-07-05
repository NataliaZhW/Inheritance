//AbstractBaseClass
#include<iostream>
using namespace std;

class Animal
{
private:
public:
	Animal() {};
	~Animal() {};
	virtual void sound() = 0;
};
class Cat : public Animal { private:public:	Cat() {};	~Cat() {}; };
class Tiger : public Cat 
{ 
private:
public: 
	void sound() override { cout << "RRRRRR" << endl; }
	Tiger() {};
	~Tiger() {};
};

class HomeCat : public Cat
{
private:
public:
	void sound() override { cout << "Miau-Miau" << endl; }
	HomeCat() {};
	~HomeCat() {};
};

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Hello AbstractBaseClasses\n\n";
	Tiger tiger;
	tiger.sound();

	HomeCat Tom;
	Tom.sound();
	return 0;
}
