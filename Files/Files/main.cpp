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

	if (fin.eof())
		cout << "Ошибка открытия файла!\n";
	else
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

	//std::string path1 = "myFile1.txt";
	//std::string path2 = "myFile2.txt";
	//// запись в файл
	//std::ofstream fout2;
	//fout2.open(path2);
	//if (!fout2.is_open())
	//	cout << "Ошибка открытия файла!\n";
	//else
	//{
	//	std::string temp = "333";
	//	fout2 << " " << temp << "\n";
	//	fout2.write((char*)&temp, sizeof(std::string));	//Запись в файл 
	//	fout2.close();
	//};
	////cout << "\n";


	//std::string temp1;
	//std::string temp2;

	//// Чтение из файла
	//std::ifstream fin2;
	//fin2.open(path2);
	//if (!fin2.is_open())
	//	cout << "Ошибка открытия файла!\n";
	//else
	//{
	//	fin2 >> temp1;
	//	fin2.read((char*)&temp2, sizeof(std::string));//Чтение из файла 
	//	cout << temp1 << " " << temp2 << " " << "\n";
	//	fin2.close();
	//	//cout << delimiter;
	//}

}