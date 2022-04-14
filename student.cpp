#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;



//Constructor
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->days[0] = 0;
	this->days[1] = 0;
	this->days[2] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->days[0] = days[0];
	this->days[1] = days[1];
	this->days[2] = days[2];
	this->degreeProgram = degreeProgram;
}

//Deconstructor
Student::~Student()
{
}



//Accessor
string Student::getStudentID()
{
	return this->studentID;
}
string Student::getFirstName()
{
	return this->firstName;
}
string Student::getLastName()
{
	return this->lastName;
}
string Student::getEmailAddress()
{
	return this->emailAddress;
}
int Student::getAge()
{
	return this->age;
}
int* Student::getDays()
{
	return this->days;
}
DegreeProgram Student::getDegreeProgram()
{
	return this->degreeProgram;
}

//Mutator
void Student::setStudentID(string studentID)
{
	this->studentID = studentID;
}
void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}
void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}
void Student::setAge(int age)
{
	this->age = age;
}
void Student::setDays(int days[courseDays])
{
	this->days[0] = days[0];
	this->days[1] = days[1];
	this->days[2] = days[2];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
	this->degreeProgram = degreeProgram;
}



//Print Student
void Student::print()
{
	cout << getStudentID() << '\t';
	cout << getFirstName() << '\t';
	cout << getLastName() << '\t';
	cout << getEmailAddress() << '\t';
	cout << getAge() << '\t';
	cout << getDays()[0] << ',';
	cout << getDays()[1] << ',';
	cout << getDays()[2] << '\t';
	cout << degreeProgramStrings[getDegreeProgram()] << endl;
}
