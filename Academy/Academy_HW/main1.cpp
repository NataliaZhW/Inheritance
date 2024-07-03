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
	static const int AGE_WIDTH = 3;
	std::string last_name{ "" };
	std::string first_name{ "" };
	unsigned int age{ 0 };
public:
	const std::string& get_last_name() const { return last_name; }
	const std::string& get_first_name() const { return first_name; }
	const unsigned int get_age()const { return age; }
	void set_last_name(const std::string& last_name) { this->last_name = last_name; }
	void set_first_name(const std::string& first_name) { this->first_name = first_name; }
	void set_age(unsigned int age) { this->age = age; }

	//Constructor
	Human()
	{
		//this->first_name = "";
		//this->last_name = "";
		//this->age = 0; 
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
	Human(Human&& obg)
	{
		cout << "\nЗапустился контруктор присваивания\n";
		last_name = obg.last_name;
		first_name = obg.first_name;
		age = obg.age;
	}
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
	Human& operator= (Human&& obg)
	{
		cout << "\nЗапустился оператор присваивания\n";
		if (this == &obg) return *this;
		this->last_name = obg.last_name;
		this->first_name = obg.first_name;
		this->age = obg.age;
		return *this;
	}

	virtual void info()const { cout << last_name << " " << first_name << " " << age << " y/o\n"; }

	virtual std::ostream& info(std::ostream& os)const { return os << last_name << " | " << first_name << " | " << age; }
	virtual std::ofstream& write(std::ofstream& ofs)const
	{
		//ofs << last_name << " * " << first_name << " * " << age;

		//ofs << strchr(typeid (*this).name(), ' ') + 1 << " * " << last_name << " * " << first_name << " * " << age;

		ofs.width(TYPE_WIDTH); ofs << right << std::string(strchr(typeid (*this).name(), ' ') + 1) + " |"; //Название класса
		ofs.width(LAST_NAME_WIDTH); ofs << right << (last_name + " |");
		ofs.width(FIRST_NAME_WIDTH); ofs << right << first_name + " |";
		ofs.width(AGE_WIDTH); ofs << right << age;
		ofs << "|";
		return ofs;
	}
	virtual std::ifstream& read_l(std::ifstream& ifs)
	{
		while (std::getline(ifs, last_name, '|'));
		while (std::getline(ifs, first_name, '|'));
		ifs >> age;
		//std::getline(ifs, , '|'); 
		return ifs;
	}
};

//dynamic_cast<>()
std::ostream& operator<<(std::ostream& os, const Human& obg) { return obg.info(os); }
std::ofstream& operator<<(std::ofstream& ofs, const Human& obg) { return obg.write(ofs); }
std::ifstream& operator>>(std::ifstream& ifs, Human& obg)
{
	return obg.read_l(ifs);
}

class Student :public Human
{
private:
	static const int SPECIALITY_WIDTH = 25;
	static const int GROUP_WIDTH = 8;
	static const int RATING_WIDTH = 2;
	static const int ATTENDANCE_WIDTH = 2;
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
		return Human::info(os) << " | " << speciality << " | " << group << " | " << rating << " | " << attendance;
	}
	std::ofstream& write(std::ofstream& ofs)const override //переопределяем
	{
		Human::write(ofs);
		//ofs << " * " << speciality << " * " << group << " * " << rating << " * " << attendance;
		ofs.width(SPECIALITY_WIDTH); ofs << right << speciality << " | ";
		ofs.width(GROUP_WIDTH); ofs << right << group << " | ";
		ofs.width(RATING_WIDTH); ofs << right << rating << " | ";
		ofs.width(ATTENDANCE_WIDTH); ofs << right << attendance << " | ";

		return ofs;
	}
	std::ifstream& read_l(std::ifstream& ifs) override
	{
		Human::read_l(ifs);
		while (std::getline(ifs, speciality, '|'));
		while (std::getline(ifs, group, '|'));
		ifs >> rating >> attendance;
		return ifs;
		//std::getline(ifs, , '|'); 
		//std::getline(ifs, , '|'); 
	}
};

class Teacher :public Human
{
private:
	static const int SPECIALITY_WIDTH = 25;
	static const int GROUP_WIDTH = 8;
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
		return Human::info(os) << " | " << speciality << " | " << experience;
	}
	std::ofstream& write(std::ofstream& ofs)const override //переопределяем
	{
		Human::write(ofs);
		//ofs << " * " << speciality << " * " << experience;

		ofs.width(SPECIALITY_WIDTH); ofs << right << speciality << " | ";
		ofs.width(GROUP_WIDTH); ofs << right << experience << " | ";

		return ofs;
	}
	std::ifstream& read_l(std::ifstream& ifs) override
	{
		Human::read_l(ifs);
		while (std::getline(ifs, speciality, '|'));
		ifs >> experience;
		return ifs;
		//std::getline(ifs, , '|'); 
	}
};

class Graduate :public Student
{
private:
	static const int DIPLOM_NAME_WIDTH = 25;
	static const int BALL_WIDTH = 2;
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
		return Student::info(os) << " | " << diplom_name << " | " << ball;
	}
	std::ofstream& write(std::ofstream& ofs)const override //переопределяем
	{
		Student::write(ofs);
		//ofs << " * " << diplom_name << " * " << ball;

		ofs.width(DIPLOM_NAME_WIDTH); ofs << right << diplom_name << " | ";
		ofs.width(BALL_WIDTH); ofs << right << ball << " | ";
		return ofs;
	}
	std::ifstream& read_l(std::ifstream& ifs) override
	{
		Student::read_l(ifs);
		while (std::getline(ifs, diplom_name, '|'));
		ifs >> ball;
		return ifs;
		//std::getline(ifs, , '|'); 
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
	//std::ofstream fout1("size_" + filename);
	//fout1 << n << endl;
	//for (int i = 0; i < n; i++)
	//{
	//	fout1 << typeid(*group[i]).name() << endl;
	//}
	//fout1.close();
	//std::string cmd = "notepad " + ("size_" + filename);
	//system(cmd.c_str());

	std::ofstream fout(filename);
	fout << n << endl;

	for (int i = 0; i < n; i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	std::string cmd1 = "notepad " + filename;
	system(cmd1.c_str());//метод c_str() возвращает содержимое объекта string в виде обычной C-string (NULL terminated line)
}
int ReadSize(const std::string& filename)
{
	int temp_size{};
	std::ifstream fin1;
	fin1.open(filename);//"size_" + 
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

Human* HumanFactory(const std::string& type)
{
	Human* human = nullptr;
	if (type == "Human") human = new Human();
	if (type == "Student") human = new Student;
	if (type == "Teacher") human = new Teacher;
	if (type == "Graduate") human = new Graduate;
	return human;
}

Human** Load(const std::string& filename, int& n)
{
	Human** group = nullptr;
	std::ifstream fin(filename);
	if (!fin.is_open())
		std::cout << "Ошибка открытия файла!\n";
	else
	{
		n = 0;
		while (!fin.eof())
		{
			//Считаем количество объектов, оно точно соответсвует количеству непустых строк в файле:

			// //const int SIZE = 256;
			//char buffer[SIZE]{};	//NULL-Terminated Line
			//fin.getline(buffer, SIZE);	//for NULL-Terminated Lines (C-Strings - char arrays)

			std::string buffer;
			std::getline(fin, buffer);		//for std::string global function std::getline(stream, string) used.
			if (buffer.size() < 16)continue;
			n++;
		}
		cout << n << endl;
		group = new Human * [n] {};//создаем только указатели, не сами объекты Выделяем память под массив:

		// Возвращаемся в начало файла:
		cout << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		cout << fin.tellg() << endl;

		for (int i = 0; i < n; i++)// Выпоняем чтение объектов:
		{
			std::string type;
			fin >> type;
			group[i] = HumanFactory(type);
			if (group[i]) fin >> *group[i];
			else continue;
		}

		fin.close();
	}
	return group;
}

//string& read_temp_text(std::string& temp_text)
//{
//	fin1 >> temp_text;	
//}

Human** Read(const std::string& filename, int& n)//
{
	Human** group1 = nullptr;
	// Чтение из файла
	std::ifstream fin1;
	fin1.open(filename);
	if (!fin1.is_open())
		std::cout << "Ошибка открытия файла!\n";
	else
	{
		int temp_size;
		fin1 >> temp_size;
		cout << temp_size << " temp_size\n";//
		group1 = new Human * [temp_size] {};//создаем только указатели, не сами объекты

		string temp_text;

		for (int i = 0; i < temp_size; i++)
		{
			string temp_class;
			while(temp_class=="") fin1 >> temp_class;
			cout << temp_class << " temp_class\n";//

			//std::string type;
			//fin >> type;
			//group[i] = HumanFactory(temp_class);
			//if (group[i]) fin1 >> *group[i];
			//else continue;

			//group[i] = HumanFactory(temp_class);

			Human* Temp1 = nullptr;
			Student* Temp2 = nullptr;
			//fin1 >> *group[i];
			//group1[i] = Temp2; ///
			//group1[i]->info();

			string last_name = "";
			string first_name = "";
			unsigned int age = 0;

			string speciality{ "" };
			string group{ "" };
			double rating{ 0 };
			double attendance{ 0 };

			//std::string speciality{ "" };
			unsigned int experience{ 0 };

			std::string diplom_name{ "" };
			unsigned int ball{ 0 };

			bool flag = 0;
			while (true)
			{
				fin1 >> temp_text;
				//cout << temp_text << "\n";
				if (flag&& last_name!="") last_name += " ";
				if (temp_text == "|" && last_name != "") { flag = 0; break; }
				if (temp_text != "|"&& temp_text != " ")last_name += temp_text;
				flag = 1;
			}
			while (true)
			{
				fin1 >> temp_text;
				//cout << temp_text << "\n";
				if (flag) first_name += " ";
				if (temp_text == "|"&& first_name!="") { flag = 0; break; }
				first_name += temp_text;
				flag = 1;
			}
			fin1 >> age >> temp_text;

			if (temp_class == "Human")
			{
				//cout << temp_age << " " << temp_text << "\n";
				//Human Temp1(temp_last_name, temp_first_name, temp_age);
				group1[i] = new Human(HUMAN_GIVE_PARAMETRS);
				group1[i]->info();

				//group1[i] = Temp1;
				//cout << group1[i];
			}
			if (temp_class == "Student" || temp_class == "Graduate")
			{
				//flag = 0;

				while (true) //speciality
				{
					fin1 >> temp_text;
					//cout << temp_text << "\n";
					if (flag) speciality += " ";
					if (temp_text == "|") { flag = 0; break; }
					speciality += temp_text;
					flag = 1;
				}
				while (true) //group
				{
					fin1 >> temp_text;
					//cout << temp_text << "\n";
					if (flag) group += " ";
					if (temp_text == "|") { flag = 0; break; }
					group += temp_text;
					flag = 1;
				}
				fin1 >> rating >> temp_text;
				fin1 >> attendance >> temp_text;

				if (temp_class == "Student")
				{
					//cout << temp_age << " " << temp_text << "\n";
					group1[i] = new Student(HUMAN_GIVE_PARAMETRS, STUDENT_GIVE_PARAMETRS);
					group1[i]->info();
					//group1[i] = Temp1;
					//group1[i]->info();
					//cout << *group1[i];
				}
			}
			if (temp_class == "Teacher")
			{
				//flag = 0;				

				while (true) //speciality
				{
					fin1 >> temp_text;
					//cout << temp_text << "\n";
					if (flag) speciality += " ";
					if (temp_text == "|") { flag = 0; break; }
					speciality += temp_text;
					flag = 1;
				}
				fin1 >> experience >> temp_text;

				//cout << temp_age << " " << temp_text << "\n";
				group1[i] = new Teacher(HUMAN_GIVE_PARAMETRS, TEACHER_GIVE_PARAMETRS);
				group1[i]->info();
				//group1[i] = Temp1;
				//group1[i]->info();
			}
			if (temp_class == "Graduate")
			{

				//flag = 0;

				while (true) //diplom_name
				{
					fin1 >> temp_text;
					//cout << temp_text << "\n";
					if (flag) diplom_name += " ";
					if (temp_text == "|") { flag = 0; break; }
					diplom_name += temp_text;
					flag = 1;
				}
				fin1 >> ball >> temp_text;

				//cout << temp_age << " " << temp_text << "\n";
				group1[i] = new Graduate(HUMAN_GIVE_PARAMETRS, STUDENT_GIVE_PARAMETRS, GRADUATE_GIVE_PARAMETRS);
				group1[i]->info();

				//cout << *group1[i];
			}

			////////std::string type;
			////////fin >> type;
			//////group[i] = HumanFactory(temp_class);
			//////if (group[i]) fin >> *group[i];
			//////else continue;
			
			//group1[i] = HumanFactory(temp_class);
			//group1[i] = Temp1;
			
			Temp1 = nullptr;
		}
		fin1.close();
	}
	//delete Temp1;
	return group1;
};

//#define INHERITANCE_CHECK
//#define POLYMORPHISM

void main()
{
	setlocale(LC_ALL, "");
	std::string path1 = "group.txt";

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

#ifdef POLYMORPHISM
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

	//Print(group, sizeof(group) / sizeof(group[0]));
	Save(group, sizeof(group) / sizeof(group[0]), path1);
	Clear(group, sizeof(group) / sizeof(group[0]));

	//Read(group, sizeof(group) / sizeof(group[0]), "group.txt");
	const int SIZE0 = 0;
	Human* group1 = new Human[ReadSize(path1) + 1];

	//Read(&group1, ReadSize(path1) + 1, path1);
	//Print(&group1, ReadSize(path1) + 1);
#endif // POLYMORPHISM

	int n = ReadSize(path1);
	Human** group2 = Read(path1, n);
	////Human** group2 = Load(path1,n);
	Print(group2, n);
	Clear(group2, n);
}
