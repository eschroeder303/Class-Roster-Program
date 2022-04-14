#pragma once
#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"



int main()
{
	//Personal Info
	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "C++" << endl;
	cout << "ID#9478943" << endl;
	cout << "Edward Schroeder" << endl;
	cout << endl;

	//Student Data Table
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Edward,Schroeder,eschr34@wgu.edu,30,15,20,25,SOFTWARE"
	};



	//Parse And Add
	Roster classRoster;
	const int numStudents = 5;
	for (int i = 0; i < numStudents; i++)
		classRoster.parseAndAdd(studentData[i]);

	//Print All
	cout << "Displaying all students: " << endl;
	cout << "ID# | First Name | Last Name | Email Address | Age | Days In Courses | Degree Program" << endl;
	classRoster.printAll();
	cout << endl;

	//Print Invalid Emails
	cout << "Displaying invalid emails: " << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	//Print Average Days Per Course
	cout << "Average days per course for each student: " << endl;
	for (int i = 0; i < numStudents; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << endl;

	//Print Degree Program
	cout << "Displaying students in degree program: SOFTWARE " << endl;
	cout << "ID# | First Name | Last Name | Email Address | Age | Days In Courses | Degree Program" << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	//Remove Student
	cout << "Removing student A3: " << endl;
	classRoster.remove("A3");
	cout << endl;

	//Print All
	cout << "Displaying all students: " << endl;
	cout << "ID# | First Name | Last Name | Email Address | Age | Days In Courses | Degree Program" << endl;
	classRoster.printAll();
	cout << endl;

	//Remove Student
	cout << "Removing student A3 again: " << endl;
	classRoster.remove("A3");
	cout << endl;



	return 0;
}
