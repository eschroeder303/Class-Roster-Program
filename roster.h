#pragma once
#include <iostream>
#include <string>
#include "student.h"

using namespace std;

//Roster Class
class Roster
{
public:

	//Constructor
	Roster();
	//Deconstructor
	~Roster();

	//Pointer Array
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];
	int lastStudent = -1;

	//Function
	void add(string studentID, string firstName, string lastName, string email, int age, int days1, int days2, int days3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void parseAndAdd(string row);
};
