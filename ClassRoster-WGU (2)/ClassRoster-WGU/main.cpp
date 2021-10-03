#include "roster.h"
//using std::endl;
int main()
{
	cout << "C867/-Scripting & Programming: Application" << '\n';
	cout << "Language: C++" << '\n';
	cout << "Student ID: 000817242" << '\n';
	cout << "Name: Antoinette Thomas" << '\n';
	cout << '\n';


	const string studentdata[] =
	{

		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Antoinette,Thomas,atho596@wgu.edu,32,24,35,60,SOFTWARE"
	};

	const int numStudents = 5;
	Roster roster;
	
	for (int i = 0; i < numStudents; i++) roster.parse(studentdata[i]);
	cout << "Displaying all students:" << std::endl;
	roster.printAll();
	cout << std::endl;


	cout << "Displaying invalid emails:" << std::endl;
	roster.printInvalidEmails();
	cout << std::endl;

	cout << "Displaying average days in course: " << std::endl;
	for (int i = 0; i < numStudents; i++)
	roster.printAverageDaysInCourse(roster.classRosterArray[i]->getstudentID()); //classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID())//

	for (int i = 0; i < 3; i++)
	{
		cout << "Displaying by degree type: " << degreeProgramStrings[i] << std::endl;
		roster.printByDegreeProgram((DegreeProgram)i);
	}

	cout << "Removing A3:" << std::endl;
	roster.removeStudentByID("A3");

	system("pause");
	return 0;
}


