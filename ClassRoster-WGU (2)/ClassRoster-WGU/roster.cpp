#include "roster.h"
void Roster::parse(string studentdata)
{
	DegreeProgram dp =SECURITY;
	if (studentdata.back() == 'Y') dp =SECURITY; //USE DEGREE PROGRAM with. back//
	else if (studentdata.back() == 'E') dp = SOFTWARE;
	else if (studentdata.back() == 'K') dp = NETWORK;

	int rhs = studentdata.find(",");
	string sID = studentdata.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string fn = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string ln = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string em = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int age = stoi(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int cd1 = stoi(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int cd2 = stoi(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int cd3 = stoi(studentdata.substr(lhs, rhs - lhs));

	add(sID, fn, ln, em, age, cd1, cd2, cd3, dp);
}

void Roster::add(string StudentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, DegreeProgram dp)// string email address before age//
{
	int parr[3] = { days1, days2, days3 };

	classRosterArray[++lastIndex] = new Student(StudentID, firstName, lastName, emailAddress, age, parr, dp); //email address before age//
}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		cout << classRosterArray[i]->getstudentID(); cout << '\t';
		cout << classRosterArray[i]->getfirstName(); cout << '\t';
		cout << classRosterArray[i]->getlastName(); cout << '\t';
		//cout << classRosterArray[i]->getemailAddress(); cout << '\t';//
		cout << classRosterArray[i]->getage(); cout << '\t';
		cout << classRosterArray[i]->getdays()[0]; cout << '\t';
		cout << classRosterArray[i]->getdays()[1]; cout << '\t';
		cout << classRosterArray[i]->getdays()[2]; cout << '\t';
		cout << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << std::endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram dp)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == dp) classRosterArray[i]->print();
	}
	cout << std::endl;
}

void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string em = (classRosterArray[i]->getemailAddress());
		if (em.find(' ') == string::npos || (em.find('@') == string::npos && em.find('.') == string::npos))
		{
			any = true;
			cout << em << "-" << classRosterArray[i]->getfirstName() << std::endl;
		}
	}
	if (!any) cout << "NONE" << std::endl;
	
}

void Roster::printAverageDaysInCourse(string StudentID) // classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());//
	
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getstudentID() == StudentID)
		{
			success = true;
			cout << classRosterArray[i]->getstudentID() << ":";
			cout << (classRosterArray[i]->getdays()[0]
				+ classRosterArray[i]->getdays()[1]
				+ classRosterArray[i]->getdays()[2] / 3) << std::endl; // ERROR//

		}
			
			
	}
	cout << std::endl;
}

void Roster::removeStudentByID(string StudentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getstudentID() == StudentID)
		{
			success = true;
		if (i < numStudents - 1)
		{
			Student* temp = classRosterArray[i];
			classRosterArray[i] = classRosterArray[numStudents - 1];
			classRosterArray[numStudents - 1] = temp;
		}
		Roster::lastIndex--;
	}
}
if (success)
{
	cout << StudentID << "removed from roster." << std::endl << std::endl;
	this->printAll();
}
else cout << StudentID << "student ID not found." << std::endl << std::endl;

}

Roster::~Roster()
{
	cout << "DESTRUCTOR CALLED!!!" << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying studentID #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}