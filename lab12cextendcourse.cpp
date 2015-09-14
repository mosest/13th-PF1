//Tara Moses
//April 6, 2015
//Lab 12c: Extending the Course Class

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Student
{
public:
   Student();
   Student(const Student & student);
   ~Student();

   void Set(const int uaid, const string name, const float gpa);
   void Get(int & uaid, string & name, float & gpa) const;
   void Print() const;
   void Read();

private:
   int Uaid;
   string Name;
   float Gpa;
};

Student::Student()
{
   Uaid = 0;
   Name = "none";
   Gpa = 0;
}

Student::Student(const Student & student)
{
   Uaid = student.Uaid;
   Name = student.Name;
   Gpa = student.Gpa;
}

Student::~Student()
{
}

void Student::Set(const int uaid, const string name, const float gpa)
{
   Uaid = uaid;
   Name = name;
   Gpa = gpa;
   if (Gpa < 0.0) Gpa = 0.0;
   else if (Gpa > 4.0) Gpa = 4.0;
}

void Student::Get(int &uaid, string & name, float &gpa) const
{
   uaid = Uaid;
   name = Name;
   gpa = Gpa;
}

void Student::Print() const
{
   cout << Uaid << " " << Name << " " << Gpa << endl;
}

void Student::Read()
{
   cin >> Uaid >> Name >> Gpa;
   if (Gpa < 0.0) Gpa = 0.0;
   else if (Gpa > 4.0) Gpa = 4.0;
}

class Course
{
public:
   Course(const int count=0);
   Course(const Course & course);
   ~Course();

   void Print() const;
   void Read();
   void TopStudents(float n);

private:
   static const int MAX_STUDENTS = 100;
   Student students[MAX_STUDENTS];
   int num_students;
};

Course::Course(const int c) {
	cout << "Constructor\n";
	num_students=c;
}

Course::Course(const Course &c) {
	cout << "Copy constructor\n";
	for (int i=0;i<num_students;i++) {
		Student s;
		students[i]=s;
	}
}

Course::~Course() {
	cout << "Destructor\n";
}

void Course::Print() const {
	cout << "Print\n";
	for (int i=0;i<num_students;i++) {
		students[i].Print();
	}
}

void Course::Read() {
	cout << "Read\n";
	for (int i=0;i<num_students;i++) {
		students[i].Read();
	}
}

void Course::TopStudents(float n) {
	cout << "TopStudents\n";
	
	float currentGPA;
	int a;
	string b;
	
	students[0].Get(a, b, currentGPA);
	for (int i=0;i<num_students;i++) {
		students[i].Get(a,b,currentGPA);
		if (currentGPA>=n) students[i].Print();
	}
}

int main()
{
   cout << "Testing Student class\n";
   Student student1;
   student1.Set(1234, "John", 2.5);
   student1.Print();

   cout << "Testing Course class\n";
   Course course(5);
   course.Print();
   course.Read();
   course.Print();
   
   course.TopStudents(3.5);
   return 0;
}
