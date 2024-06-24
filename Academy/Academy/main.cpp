// Academy
#include<iostream>

using namespace std;

#define delimiter "\n----------------------------------------------\n\n"

#define HUMAN_TAKE_PARAMETRS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETRS last_name, first_name, age
#define STUDENT_TAKE_PARAMETRS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETRS speciality, group, rating, attendance
#define TEACHER_TAKE_PARAMETRS const std::string& speciality, unsigned int experiensce
#define TEACHER_GIVE_PARAMETRS speciality, experiensce
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
};

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
};

class Teacher :public Human
{
private:
	std::string speciality;
	unsigned int experiensce;
public:
	const std::string& get_speciality() const { return speciality; }
	unsigned int get_experiensce()const { return experiensce; }
	void set_speciality(const std::string& speciality) { this->speciality = speciality; }
	void set_experiensce(unsigned int experiensce) { this->experiensce = experiensce; }

	//Constructor
	Teacher(HUMAN_TAKE_PARAMETRS, TEACHER_TAKE_PARAMETRS) :Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_experiensce(experiensce);
		cout << "TConstructor:\t" << this << "\n";
	};
	~Teacher() override { cout << "TDestructor:\t" << this << "\n"; };

	void info()const override
	{
		Human::info();
		cout << " " << speciality << " " << experiensce << "\n";
	}
};

class Graduate :public Student
{
private:
	std::string diplom_name;
	unsigned int ball;
public:
	const std::string& get_diplom_name() const { return diplom_name; }
	unsigned int get_balle()const { return ball; }
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
};

std::ostream& operator << (std::ostream& os, const Human& obg)
{
	//os << obg.get_last_name() << " " << obg.get_first_name() << " " << obg.get_age() << " y/o\n"; 
	obg.info();
	return os;
}
//std::istream& operator >> (std::istream& is, Human& obg){}

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
		new Graduate("Vercetty", "Tommy", 30,"Theft", "Vice", 97, 98, "Vice", 4)
	};
	cout << delimiter;

	//cout << sizeof(group) << " " << sizeof(group[0]) << "\n";
	//cout << delimiter;
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		//cout << i << " " << sizeof(group[i]) << "\n";
		//group[i]->info();
		cout << *group[i] << "\n";
		cout << delimiter;
	}

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i]; //group[i]->~Human();			
		cout << delimiter;
	}
}