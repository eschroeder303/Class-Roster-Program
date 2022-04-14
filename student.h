#pragma once
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

//Student Class
class Student
{
public:

	const static int courseDays = 3;

	string studentID;             // Student ID
	string firstName;             // First Name
	string lastName;              // Last Name
	string emailAddress;          // Email Address
	int age;                      // Age
	int days[courseDays];         // Number of Days to Complete Course
	DegreeProgram degreeProgram;  // Enumerated Degree Program

	//Constructor
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram);

	//Deconstructor
	~Student();

	//Accessor
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDays();
	DegreeProgram getDegreeProgram();

	//Mutator
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDays(int days[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//Print Student
	void print();
};
