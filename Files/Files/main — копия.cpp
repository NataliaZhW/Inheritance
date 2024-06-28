//Files
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<ctime>

using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
#define READ_TO_FILE

void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE
	std::ofstream fout; //создать поток
	fout.open("File.txt", std::ios_base::app);// открыть поток для дозаписи
	fout << "HelloWorld" << endl; //записать в файл
	time_t now = time(NULL);
	fout << ctime(&now) << endl; //записать в файл
	fout.close(); //закрыть поток
	//system("notepad File.txt");//открвает окошко блокнота
#endif // WRITE_TO_FILE

#ifdef READ_TO_FILE
	std::ifstream fin("File.txt");

	if (!fin.eof())		
	{
		const int SIZE = 256;
		char buffer[SIZE];
		while (!fin.eof())
		{
			//fin >>buffer;
			fin.getline (buffer,SIZE);
			cout << buffer << "\n";
		}
		fin.close();
	};

#endif // READ_TO_FILE

}