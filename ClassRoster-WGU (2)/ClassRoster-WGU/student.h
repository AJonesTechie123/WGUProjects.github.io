#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student
{
public:
	const static int daysInCourseArraySize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int days[daysInCourseArraySize];
	DegreeProgram degreeProgram;
public:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram);
	~Student();

	string getstudentID();
	string getfirstName();
	string getlastName();
	string getemailAddress();
	int getage();
	int* getdays();// NOT IN AN ARRAY FORMAT CAN BE POINTER//
	DegreeProgram getDegreeProgram();

	void setstudentID(string studentID);
	void setfirstName(string firstName);
	void setlastName(string lastName);
	void setemailAddress(string emailAddress);
	void setage(int Age);
	void setdays(int days[]);
	void setDegreeProgram(DegreeProgram dp);

	static void printHeader();

	void print();
};
