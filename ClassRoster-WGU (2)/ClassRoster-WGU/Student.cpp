#include "student.h"
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysInCourseArraySize; i++) this->days[i] = 0;
	this->degreeProgram = DegreeProgram:: SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysInCourseArraySize; i++) this->days[i] = days[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student(){}

string Student::getstudentID() { return this->studentID; }
string Student::getfirstName() { return this->firstName; }
string Student::getlastName() { return this->lastName; }
string Student::getemailAddress() { return this->emailAddress;}
int Student::getage() { return this->age; }
int* Student::getdays() { return this->days;}
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram;}

void Student::setstudentID(string studentID) { this->studentID = studentID;}
void Student::setfirstName(string firstName) { this->firstName = firstName;}
void Student::setlastName(string lastName) { this->lastName = lastName;}
void Student::setemailAddress(string emailAddress) { this->emailAddress = emailAddress;}
void Student::setage(int age) { this->age = age;}
void Student::setdays(int days[])
{
	for (int i = 0; i < daysInCourseArraySize; i++) this->days[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }

void Student::printHeader()
{
cout << "Student ID|First Name|Last Name|Age|Days in Course|Degree Program\n";
}

void Student::print()
{
	cout << this->getstudentID() << '\t';
	cout << this->getfirstName() << '\t';
	cout << this->getlastName() << '\t';
	cout << this->getemailAddress() << '\t';
	cout << this->getage() << '\t';
	cout << this->getdays()[0] << ',';
	cout << this->getdays()[1] << ',';
	cout << this->getdays()[2] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}

