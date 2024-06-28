// Academy
#include<iostream>
#include <fstream>
#include <string>

using namespace std;

#define delimiter "\n----------------------------------------------\n\n"

#define HUMAN_TAKE_PARAMETRS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETRS last_name, first_name, age
#define STUDENT_TAKE_PARAMETRS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETRS speciality, group, rating, attendance
#define TEACHER_TAKE_PARAMETRS const std::string& speciality, unsigned int experience
#define TEACHER_GIVE_PARAMETRS speciality, experience
#define GRADUATE_TAKE_PARAMETRS const std::string& diplom_name, unsigned int ball
#define GRADUATE_GIVE_PARAMETRS diplom_name, ball

class Human
{
private:
	static const int TYPE_WIDTH = 10;
	static const int LAST_NAME_WIDTH = 15;
	static const int FIRST_NAME_WIDTH = 15;
	static const int AGE_WIDTH = 5;
	std::string last_name{ "" };
	std::string first_name{ "" };
	unsigned int age{ 0 };
public:
	const std::string& get_last_name() const { return last_name; }
	const std::string& get_first_name() const { return first_name; }
	const unsigned int get_age()const { return age; }
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name) { this->first_name = first_name; }
	void set_age(unsigned int age) { this->age = age; }

	//Constructor
	Human()
	{
		cout << "0_HConstructor:\t" << this << "\n";
	};
	Human(HUMAN_TAKE_PARAMETRS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << "\n";
	};
	Human(Human& obg)
	{
		cout << "\nЗапустился контруктор присваивания\n";
		last_name = obg.last_name;
		first_name = obg.first_name;
		age = obg.age;
	}
	//Human(Human&& obg)
	//{
	//	cout << "\nЗапустился контруктор присваивания\n";
	//	last_name = obg.last_name;
	//	first_name = obg.first_name;
	//	age = obg.age;
	//}
	virtual ~Human() { cout << "HDestructor:\t" << this << "\n"; };

	Human& operator= (const Human& obg)
	{
		cout << "\nЗапустился оператор копирования\n";
		if (this == &obg) return *this;
		this->set_last_name(obg.get_last_name());
		this->set_first_name(obg.get_first_name());
		this->set_age(obg.get_age());
		return *this;
	}
	//Human& operator= (Human&& obg)
	//{
	//	cout << "\nЗапустился оператор присваивания\n";
	//	if (this == &obg) return *this;
	//	this->last_name = obg.last_name;
	//	this->first_name = obg.first_name;
	//	this->age = obg.age;
	//	return *this;
	//}

	virtual void info()const { cout << last_name << " " << first_name << " " << age << " y/o\n"; }

	virtual std::ostream& info(std::ostream& os)const
	{
		return os << last_name << " * " << first_name << " * " << age;
	}
	virtual std::ofstream& info(std::ofstream& ofs)const
	{
		//ofs << strchr(typeid (*this).name(), ' ') + 1 << " * " << last_name << " * " << first_name << " * " << age;
		ofs.width(TYPE_WIDTH); ofs << left << (std::string)(strchr((typeid (*this).name() ), ' ') + 1)+":";
		ofs.width(LAST_NAME_WIDTH); ofs << left << last_name;
		ofs.width(FIRST_NAME_WIDTH); ofs << left << first_name;
		ofs.width(AGE_WIDTH); ofs << left << age;
		return ofs;
	}
};

//dynamic_cast<>()
std::ostream& operator<<(std::ostream& os, const Human& obg) { return obg.info(os); }
std::ofstream& operator<<(std::ofstream& os, const Human& obg) { return obg.info(os); }

class Student :public Human
{
private:
	static const int SPECIALITY_WIDTH = 25;
	static const int GROUP_WIDTH = 8;
	static const int RATING_WIDTH = 8;
	static const int ATTENDANCE_WIDTH = 8;
	std::string speciality{ "" };
	std::string group{ "" };
	double rating{ 0 };
	double attendance{ 0 };
public:
	const std::string& get_speciality() const { return speciality; }
	const std::string& get_group() const { return group; }
	double get_rating()const { return rating; }
	double get_attendance()const { return attendance; }
	void set_speciality(const std::string& speciality) { this->speciality = speciality; }
	void set_group(const std::string& group) { this->group = group; }
	void set_rating(unsigned int rating) { this->rating = rating; }
	void set_attendance(unsigned int attendance) { this->attendance = attendance; }

	//Constructor
	Student() :Human() { cout << "0_SConstructor:\t" << this << "\n"; }
	Student(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS) :Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << "\n";
	};
	Student(Student& obg) :Human(obg.get_last_name(), obg.get_first_name(), obg.get_age())
	{
		cout << "\nЗапустился контруктор присваивания Student\n";
		this->speciality = obg.speciality;
		this->group = obg.group;
		this->rating = obg.rating;
		this->attendance = obg.attendance;
	}
	~Student() override { cout << "SDestructor:\t" << this << "\n"; };

	Student& operator= (const Student& obg)
	{
		cout << "\nЗапустился оператор копирования Student\n";
		if (this == &obg) return *this;

		this->set_last_name(obg.get_last_name());
		this->set_first_name(obg.get_first_name());
		this->set_age(obg.get_age());

		this->speciality = obg.speciality;
		this->group = obg.group;
		this->rating = obg.rating;
		this->attendance = obg.attendance;
		return *this;
	}

	void info()const override //переопределяем
	{
		Human::info();
		cout << " " << speciality << " " << group << " " << rating << " " << attendance << "\n";
	}
	std::ostream& info(std::ostream& os)const override //переопределяем
	{
		return Human::info(os) << " * " << speciality << " * " << group << " * " << rating << " * " << attendance;
	}
	std::ofstream& info(std::ofstream& ofs)const override //переопределяем
	{
		Human::info(ofs);
		ofs.width(SPECIALITY_WIDTH); ofs << left << speciality;
		ofs.width(GROUP_WIDTH); ofs << left << group;
		ofs.width(RATING_WIDTH); ofs << left << rating;
		ofs.width(ATTENDANCE_WIDTH); ofs << left << attendance;
		return ofs;		
	}
};

class Teacher :public Human
{
private:
	static const int SPECIALITY_WIDTH = 25;
	static const int GROUP_WIDTH = 5;
	std::string speciality{ "" };
	unsigned int experience{ 0 };
public:
	const std::string& get_speciality() const { return speciality; }
	unsigned int get_experience()const { return experience; }
	void set_speciality(const std::string& speciality) { this->speciality = speciality; }
	void set_experiensce(unsigned int experience) { this->experience = experience; }

	//Constructor
	Teacher() :Human() { cout << "0_TConstructor:\t" << this << "\n"; }

	Teacher(HUMAN_TAKE_PARAMETRS, TEACHER_TAKE_PARAMETRS) :Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_experiensce(experience);
		cout << "TConstructor:\t" << this << "\n";
	};
	Teacher(Teacher& obg) :Human(obg.get_last_name(), obg.get_first_name(), obg.get_age())
	{
		cout << "\nЗапустился контруктор присваивания Student\n";
		this->speciality = obg.speciality;
		this->experience = obg.experience;
	}
	~Teacher() override { cout << "TDestructor:\t" << this << "\n"; };

	Teacher& operator= (const Teacher& obg)
	{
		if (this == &obg) return *this;

		this->set_last_name(obg.get_last_name());
		this->set_first_name(obg.get_first_name());
		this->set_age(obg.get_age());

		this->speciality = obg.speciality;
		this->experience = obg.experience;
		cout << "\nЗапустился оператор копирования Student\n";
		return *this;
	}
	void info()const override
	{
		Human::info();
		cout << " " << speciality << " " << experience << " years" << "\n";
	}
	std::ostream& info(std::ostream& os)const
	{
		return Human::info(os) << " * " << speciality << " * " << experience;
	}
	std::ofstream& info(std::ofstream& ofs)const override //переопределяем
	{
		Human::info(ofs);
	
		ofs.width(SPECIALITY_WIDTH); ofs << left << speciality;
		ofs.width(GROUP_WIDTH); ofs << left << experience;
		
		return ofs;		
	}
};

class Graduate :public Student
{
private:
	std::string diplom_name{ "" };
	unsigned int ball{ 0 };
public:
	const std::string& get_diplom_name() const { return diplom_name; }
	unsigned int get_ball()const { return ball; }
	void set_diplom_name(const std::string& diplom_name) { this->diplom_name = diplom_name; }
	void set_ball(unsigned int ball) { this->ball = ball; }

	//Constructor
	Graduate() :Student() { cout << "0_GConstructor:\t" << this << "\n"; }

	Graduate(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS, GRADUATE_TAKE_PARAMETRS) :Student(HUMAN_GIVE_PARAMETRS, STUDENT_GIVE_PARAMETRS)
	{
		set_diplom_name(diplom_name);
		set_ball(ball);
		cout << "GConstructor:\t" << this << "\n";
	};
	Graduate(Graduate& obg) :Student(obg.get_last_name(), obg.get_first_name(), obg.get_age(), obg.get_speciality(), obg.get_group(), obg.get_rating(), obg.get_attendance())
	{
		cout << "\nЗапустился контруктор присваивания Graduate\n";
		set_diplom_name(obg.get_diplom_name());
		set_ball(obg.get_ball());
	}
	~Graduate() override { cout << "GDestructor:\t" << this << "\n"; };

	Graduate& operator= (const Graduate& obg)
	{
		cout << "\nЗапустился оператор копирования Graduate\n";
		if (this == &obg) return *this;

		this->set_last_name(obg.get_last_name());
		this->set_first_name(obg.get_first_name());
		this->set_age(obg.get_age());

		this->set_speciality(obg.get_speciality());
		this->set_group(obg.get_group());
		this->set_rating(obg.get_rating());
		this->set_attendance(obg.get_attendance());

		set_diplom_name(obg.get_diplom_name());
		set_ball(obg.get_ball());

		//this->diplom_name = obg.diplom_name();
		//this->ball = obg.ball();
		return *this;
	}
	void info()const override
	{
		Student::info();
		cout << " " << diplom_name << " " << ball << "\n";
	}
	std::ostream& info(std::ostream& os)const override
	{
		return Student::info(os) << " * " << diplom_name << " * " << ball;
	}
	std::ofstream& info(std::ofstream& ofs)const override //переопределяем
	{
		Student::info(ofs);
		ofs << " * " << diplom_name << " * ";
		ofs << ball;
		return ofs;
	}
};

//std::istream& operator >> (std::istream& is, Human& obg){}

void Print(Human* group[], const int n)
{
	cout << delimiter << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *group[i] << "\n";//
		cout << delimiter << endl;
	}
}
void Clear(Human* group[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		delete group[i]; //group[i]->~Human();			
		cout << delimiter;
	}
}
void Save(Human* group[], const int n, const std::string& filename)
{
	std::ofstream fout1("size_" + filename);
	fout1 << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout1 << typeid(*group[i]).name() << endl;
	}
	fout1.close();
	std::string cmd = "notepad " + ("size_" + filename);
	system(cmd.c_str());

	std::ofstream fout(filename);
	for (int i = 0; i < n; i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	std::string cmd1 = "notepad " + filename;
	system(cmd1.c_str());
}
int ReadSize(const std::string& filename)
{
	int temp_size{};
	std::ifstream fin1;
	fin1.open("size_" + filename);
	if (!fin1.is_open())
	{
		std::cout << "Ошибка открытия файла!\n";
		return 1;
	}
	else
	{
		fin1 >> temp_size;
		//cout << temp_size << " read temp_size\n";
		return temp_size;
		fin1.close();
	}
}
void Read(Human* group1[], const int n, const std::string& filename)//(sizeof(group) / sizeof(group[0])
{
	int temp_size;
	string temp_text;
	// Чтение из файла
	std::ifstream fin2;
	std::ifstream fin1;
	fin1.open(filename);
	fin2.open("size_" + filename);
	if (!fin1.is_open() || !fin2.is_open())
		std::cout << "Ошибка открытия файла!\n";
	else
	{
		fin2 >> temp_size;
		//cout << temp_size << " temp_size\n";
		for (int i = 0; i < temp_size; i++)
		{
			fin2 >> temp_text >> temp_text;
			cout << temp_text << " temp_text\n";
			if (temp_text == "Human")
			{
				string temp_last_name = "";
				string temp_first_name = "";
				unsigned int temp_age = 0;
				bool flag = 0;
				while (true)
				{
					fin1 >> temp_text;
					//cout << temp_text << "\n";
					if (flag) temp_last_name += " ";
					if (temp_text == "*") { flag = 0; break; }
					temp_last_name += temp_text;
					flag = 1;
				}
				while (true)
				{
					fin1 >> temp_text;
					//cout << temp_text << "\n";
					if (flag) temp_first_name += " ";
					if (temp_text == "*") { flag = 0; break; }
					temp_first_name += temp_text;
					flag = 1;
				}
				fin1 >> temp_age;
				//cout << temp_age << " " << temp_text << "\n";
				Human Temp1(temp_last_name, temp_first_name, temp_age);
				Temp1.info();
				*group1[i] = Temp1;
				cout << group1[i];
			}
			if (temp_text == "Student")
			{
				string last_name = "";
				string first_name = "";
				unsigned int age = 0;

				string speciality{ "" };
				string group{ "" };
				double rating{ 0 };
				double attendance{ 0 };

				bool flag = 0;
				while (true) //last_name
				{
					fin1 >> temp_text;
					//cout << temp_text << "\n";
					if (flag) last_name += " ";
					if (temp_text == "*") { flag = 0; break; }
					last_name += temp_text;
					flag = 1;
				}
				while (true) //first_name
				{
					fin1 >> temp_text;
					//cout << temp_text << "\n";
					if (flag) first_name += " ";
					if (temp_text == "*") { flag = 0; break; }
					first_name += temp_text;
					flag = 1;
				}
				fin1 >> age >> temp_text;

				while (true) //speciality
				{
					fin1 >> temp_text;
					//cout << temp_text << "\n";
					if (flag) speciality += " ";
					if (temp_text == "*") { flag = 0; break; }
					speciality += temp_text;
					flag = 1;
				}
				while (true) //group
				{
					fin1 >> temp_text;
					//cout << temp_text << "\n";
					if (flag) group += " ";
					if (temp_text == "*") { flag = 0; break; }
					group += temp_text;
					flag = 1;
				}
				fin1 >> rating >> temp_text;
				fin1 >> attendance;

				//cout << temp_age << " " << temp_text << "\n";
				Student Temp1(HUMAN_GIVE_PARAMETRS, STUDENT_GIVE_PARAMETRS);
				Temp1.info();
				group1[i] = &Temp1;
				group1[i]->info();
				//cout << *group1[i];
			}
			if (temp_text == "Teacher")
			{
				string last_name = "";
				string first_name = "";
				unsigned int age = 0;

				std::string speciality{ "" };
				unsigned int experience{ 0 };

				bool flag = 0;
				while (true) //last_name
				{
					fin1 >> temp_text;
					//cout << temp_text << "\n";
					if (flag) last_name += " ";
					if (temp_text == "*") { flag = 0; break; }
					last_name += temp_text;
					flag = 1;
				}
				while (true) //first_name
				{
					fin1 >> temp_text;
					//cout << temp_text << "\n";
					if (flag) first_name += " ";
					if (temp_text == "*") { flag = 0; break; }
					first_name += temp_text;
					flag = 1;
				}
				fin1 >> age >> temp_text;

				while (true) //speciality
				{
					fin1 >> temp_text;
					//cout << temp_text << "\n";
					if (flag) speciality += " ";
					if (temp_text == "*") { flag = 0; break; }
					speciality += temp_text;
					flag = 1;
				}
				fin1 >> experience;

				//cout << temp_age << " " << temp_text << "\n";
				Teacher Temp2(HUMAN_GIVE_PARAMETRS, TEACHER_GIVE_PARAMETRS);
				Temp2.info();
				//group1[i] = &Temp2;
				//group1[i]->info();
			}
			if (temp_text == "Graduate")
			{
				string last_name = "";
				string first_name = "";
				unsigned int age = 0;

				string speciality{ "" };
				string group{ "" };
				double rating{ 0 };
				double attendance{ 0 };

				std::string diplom_name{ "" };
				unsigned int ball{ 0 };

				bool flag = 0;
				while (true) //last_name
				{
					fin1 >> temp_text;
					//cout << temp_text << "\n";
					if (flag) last_name += " ";
					if (temp_text == "*") { flag = 0; break; }
					last_name += temp_text;
					flag = 1;
				}
				while (true) //first_name
				{
					fin1 >> temp_text;
					//cout << temp_text << "\n";
					if (flag) first_name += " ";
					if (temp_text == "*") { flag = 0; break; }
					first_name += temp_text;
					flag = 1;
				}
				fin1 >> age >> temp_text;

				while (true) //speciality
				{
					fin1 >> temp_text;
					//cout << temp_text << "\n";
					if (flag) speciality += " ";
					if (temp_text == "*") { flag = 0; break; }
					speciality += temp_text;
					flag = 1;
				}
				while (true) //group
				{
					fin1 >> temp_text;
					cout << temp_text << "\n";
					if (flag) group += " ";
					if (temp_text == "*") { flag = 0; break; }
					group += temp_text;
					flag = 1;
				}
				fin1 >> rating >> temp_text;
				fin1 >> attendance >> temp_text;

				while (true) //diplom_name
				{
					fin1 >> temp_text;
					//cout << temp_text << "\n";
					if (flag) diplom_name += " ";
					if (temp_text == "*") { flag = 0; break; }
					diplom_name += temp_text;
					flag = 1;
				}
				fin1 >> ball;


				//cout << temp_age << " " << temp_text << "\n";
				Graduate Temp1(HUMAN_GIVE_PARAMETRS, STUDENT_GIVE_PARAMETRS, GRADUATE_GIVE_PARAMETRS);
				Temp1.info();
				//*group1[i] = Temp1;
				//cout << *group1[i];
			}

		}
		fin1.close();
		fin2.close();
	}

};
//#define INHERITANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE_CHECK
	Human human("Vercetty", "Tommy", 30);
	human.info();

	Student student("Pinkman", "Jessy", 22, "Chemistry", "WW_220", 70, 97);
	student.info();

	Teacher teacher("White", "Wolter", 50, "Chemistry", 25);
	teacher.info();

	Graduate graduate("Vercetty", "Tommy", 30, "Theft", "Vice", 97, 98, "Vice", 9);
	graduate.info();
	cout << graduate << "\n";

#endif // INHERITANCE_CHECK

	// Generalization:
	Human* group[] =
	{
		new Student("Pinkman", "Jessy", 22, "Chemistry", "WW_220", 70, 97),
		new Teacher("White", "Wolter", 50, "Chemistry", 25),
		new Graduate("Shreder", "Hank", 40, "Criminalistic", "OBN",80, 90, "Hou to catch Heisenberg", 5),
		new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 97, 98),
		new Teacher("Diaz", "Ricardo", 50, "Weapons Distribution", 20)

	};
	//cout << delimiter;
	std::string path1 = "group.txt";

	Print(group, sizeof(group) / sizeof(group[0]));
	Save(group, sizeof(group) / sizeof(group[0]), path1);
	Clear(group, sizeof(group) / sizeof(group[0]));

	//Read(group, sizeof(group) / sizeof(group[0]), "group.txt");
	const int SIZE0 = 0;
	Human* group1 = new Human[ReadSize(path1)];

	Read(&group1, ReadSize(path1), path1);

	//for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	//{
	//	cout << typeid(*group[i]).name() << ":\t";
	//	if (typeid(*group[i]) == typeid(Student))cout << *dynamic_cast<Student*>(group[i]) << endl;
	//	if (typeid(*group[i]) == typeid(Teacher))cout << *dynamic_cast<Teacher*>(group[i]) << endl;
	//	if (typeid(*group[i]) == typeid(Graduate))cout << *dynamic_cast<Graduate*>(group[i]) << endl;
	//	cout << delimiter << endl;		
	//}

	//cout << sizeof(group) << " " << sizeof(group[0]) << "\n";
	//cout << delimiter;




	//string path1 = "myFile1.txt";
	//string path2 = "myFile2.txt";
	//// запись в файл
	//ofstream fout2;
	//fout2.open(path2);
	//if (!fout2.is_open())
	//	cout << "Ошибка открытия файла!\n";
	//else
	//{
	//	string temp = "333";
	//	fout2 << " " << temp << "\n";
	//	fout2.write((char*)&temp, sizeof(string));	//Запись в файл 
	//	fout2.close();
	//};
	////cout << "\n";


	//string temp1;
	//string temp2;

	//// Чтение из файла
	//ifstream fin2;
	//fin2.open(path2);
	//if (!fin2.is_open())
	//	cout << "Ошибка открытия файла!\n";
	//else
	//{
	//	fin2 >> temp2;
	//	fin2.read((char*)&temp1, sizeof(string));//Чтение из файла 
	//	cout << temp1 <<" " << "\n";
	//	fin2.close();
	//	cout << delimiter;
	//}



}