#pragma once
#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"

using namespace std;



//Constructor
Roster::Roster()
{
}

//Deconstructor
Roster::~Roster()
{
	cout << "Destructing..." << endl;
	for (int i = 0; i < numStudents; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
	cout << "Done." << endl;
}



//Add
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int days1, int days2, int days3, DegreeProgram degreeProgram)
{
	int days[3] = { days1, days2, days3 };
	classRosterArray[++lastStudent] = new Student(studentID, firstName, lastName, email, age, days, degreeProgram);
}

//Remove
void Roster::remove(string studentID)
{
	bool found = false;
	for (int i = 0; i <= Roster::lastStudent; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			if (i < (numStudents - 1))
			{
				Student* hold = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = hold;
			}
			Roster::lastStudent--;
		}
	}
	if (found)
	{
		cout << studentID << " removed." << endl;
	}
	else
	{
		cout << studentID << " not found." << endl;
	}
}

//Print All
void Roster::printAll()
{
	for (int i = 0; i <= lastStudent; i++)
	{
		classRosterArray[i]->print();
	}
}

//Print Average Days Per Course
void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastStudent; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			cout << "ID# " << classRosterArray[i]->getStudentID() << " averages " << (classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1]
				+ classRosterArray[i]->getDays()[2]) / 3 << " days per course." << endl;
		}
	}
}

//Print Invalid Emails
void Roster::printInvalidEmails()
{
	bool invalidEmail = false;
	for (int i = 0; i <= lastStudent; i++)
	{
		string emailAddress = classRosterArray[i]->getEmailAddress();
		if ((emailAddress.find('@') == string::npos || emailAddress.find('.') == string::npos) || emailAddress.find(' ') != string::npos)
		{
			invalidEmail = true;
			cout << emailAddress << endl;
		}
	}
	if (!invalidEmail)
	{
		cout << "All emails are valid." << endl;
	}
}

//Print Degree Program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i <= Roster::lastStudent; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
}



//Parse And Add
void Roster::parseAndAdd(string studentData)
{
	//Student ID
	int rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	//First Name
	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(rhs) - lhs);

	//Last Name
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(rhs) - lhs);

	//Email Address
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(rhs) - lhs);

	//Age
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stod(studentData.substr(lhs, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(rhs) - lhs));

	//Course Days 1
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int days1 = stod(studentData.substr(lhs, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(rhs) - lhs));

	//Course Days 2
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int days2 = stod(studentData.substr(lhs, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(rhs) - lhs));

	//Course Days 3
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int days3 = stod(studentData.substr(lhs, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(rhs) - lhs));

	//Degree Program
	DegreeProgram degreeProgram = SECURITY;
	if (studentData.back() == 'Y') degreeProgram = SECURITY;
	else if (studentData.back() == 'K') degreeProgram = NETWORK;
	else if (studentData.back() == 'E') degreeProgram = SOFTWARE;



	//Add
	add(studentID, firstName, lastName, emailAddress, age, days1, days2, days3, degreeProgram);
}
