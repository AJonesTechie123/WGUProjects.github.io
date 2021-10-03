#pragma once
#include "student.h"
class Roster
{
private:
	int lastIndex = -1;
	const static int numStudents = 5;
	//Student* classRosterArray[numStudents];//

public:
	Student* classRosterArray[numStudents];
	void parse(string studentData);

	void add(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeprogram);

	void printAll();
	void printByDegreeProgram(DegreeProgram bp);
	void printInvalidEmails();//A valid email should include an at sign ('@') and period ('.') and should not include a space (' ')//
	void printAverageDaysInCourse(string StudentID); //void printAverageDaysInCourse(string studentID)//
	void removeStudentByID(string studentID);
	~Roster();
};
