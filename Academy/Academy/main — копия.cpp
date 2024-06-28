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
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name() const { return last_name; }
	const std::string& get_first_name() const { return first_name; }
	const unsigned int get_age()const { return age; }
	void set_last_name(const std::string& last_name) { this->last_name = last_name; }
	void set_first_name(const std::string& first_name) { this->first_name = first_name; }
	void set_age(unsigned int age) { this->age = age; }

	//Constructor
	Human(HUMAN_TAKE_PARAMETRS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << "\n";
	};
	virtual ~Human() { cout << "HDestructor:\t" << this << "\n"; };

	virtual void info()const { cout << last_name << " " << first_name << " " << age << " y/o\n"; }

	virtual std::ostream& info(std::ostream& os)const
	{
		return os << last_name << " " << first_name << " " << age << " y/o";
	}

};

//dynamic_cast<>()
std::ostream& operator<<(std::ostream& os, const Human& obg) { return obg.info(os); }

class Student :public Human
{
private:
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
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
	Student(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS) :Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << "\n";
	};
	~Student() override { cout << "SDestructor:\t" << this << "\n"; };

	void info()const override //переопределяем
	{
		Human::info();
		cout << " " << speciality << " " << group << " " << rating << " " << attendance << "\n";
	}
	std::ostream& info(std::ostream& os)const override //переопределяем
	{
		return Human::info(os) << " "
			<< speciality << " " << group << " " << rating << " " << attendance;
	}
};

class Teacher :public Human
{
private:
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality() const { return speciality; }
	unsigned int get_experience()const { return experience; }
	void set_speciality(const std::string& speciality) { this->speciality = speciality; }
	void set_experiensce(unsigned int experience) { this->experience = experience; }

	//Constructor
	Teacher(HUMAN_TAKE_PARAMETRS, TEACHER_TAKE_PARAMETRS) :Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_experiensce(experience);
		cout << "TConstructor:\t" << this << "\n";
	};
	~Teacher() override { cout << "TDestructor:\t" << this << "\n"; };

	void info()const override
	{
		Human::info();
		cout << " " << speciality << " " << experience << " years" << "\n";
	}
	std::ostream& info(std::ostream& os)const
	{
		return Human::info(os) << " " << speciality << " " << experience << " years";
	}
};

class Graduate :public Student
{
private:
	std::string diplom_name;
	unsigned int ball;
public:
	const std::string& get_diplom_name() const { return diplom_name; }
	unsigned int get_ball()const { return ball; }
	void set_diplom_name(const std::string& diplom_name) { this->diplom_name = diplom_name; }
	void set_ball(unsigned int ball) { this->ball = ball; }

	//Constructor
	Graduate(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS, GRADUATE_TAKE_PARAMETRS) :Student(HUMAN_GIVE_PARAMETRS, STUDENT_GIVE_PARAMETRS)
	{
		set_diplom_name(diplom_name);
		set_ball(ball);
		cout << "GConstructor:\t" << this << "\n";
	};
	~Graduate() override { cout << "GDestructor:\t" << this << "\n"; };

	void info()const override
	{
		Student::info();
		cout << " " << diplom_name << " " << ball << "\n";
	}
	std::ostream& info(std::ostream& os)const override
	{
		return Student::info(os) << " " << diplom_name << " " << ball;
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
	std::ofstream fout(filename);
	for (int i = 0; i < n; i++)
	{
		fout << *group[i] << endl;	
	}
	fout.close();
	std::string cmd = "notepad " + filename;
	system(cmd.c_str());
}
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
		new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 97, 98)
	};
	//cout << delimiter;

	Print(group, sizeof(group) / sizeof(group[0]));
	Save(group, sizeof(group) / sizeof(group[0]), "group.txt");
	Clear(group, sizeof(group) / sizeof(group[0]));	

}