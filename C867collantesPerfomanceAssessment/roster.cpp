#include <iostream>
#include <string>

#include "roster.h"

using namespace std;

// constructor
Roster::Roster(int numStudents)
{
	this->numStudents = numStudents;
	this->rosterIndex = 0;
	for (int i = 0; i < numStudents; i++)
	{
		this->classRosterArray[i] = new Student;
	}
	return;
}

void Roster::parse(string studentData)
{

	if (rosterIndex < numStudents)
	{
		// Student ID
		int rhs = studentData.find(",");
		string sID = studentData.substr(0, rhs);
		classRosterArray[rosterIndex]->setStuID(sID);

		// First Name
		int lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string fName = studentData.substr(lhs, rhs - lhs);
		classRosterArray[rosterIndex]->setFirstName(fName);

		// Last Name
		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string lName = studentData.substr(lhs, rhs - lhs);
		classRosterArray[rosterIndex]->setLastName(lName);

		// Email Address
		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string eAddress = studentData.substr(lhs, rhs - lhs);
		classRosterArray[rosterIndex]->setEmail(eAddress);

		// Age
		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int yOld = stoi(studentData.substr(lhs, rhs - lhs));
		classRosterArray[rosterIndex]->setAge(yOld);

		// Days in Course 1
		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

		// Days in Course 2
		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

		// Days in Course 3
		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));
		classRosterArray[rosterIndex]->setDaysToComplete(daysInCourse1, daysInCourse2, daysInCourse3);

		// Degree Program
		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string program = studentData.substr(lhs, rhs - lhs);
		if (program == "SECURITY")
		{
			classRosterArray[rosterIndex]->setDegreeProgram(SECURITY);
		}
		else if (program == "NEWTORK")
		{
			classRosterArray[rosterIndex]->setDegreeProgram(NETWORK);
		}
		else if (program == "SOFTWARE")
		{
			classRosterArray[rosterIndex]->setDegreeProgram(SOFTWARE);
		}
		else
		{
			cout << "Degree program not found" << endl;
		}

		// increment roterIndex
		rosterIndex++;
	}
	return;	
}


void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);


void remove(string studentID);

// print functions
void printAll();	


void printByDegreeProgram(DegreeProgram degreeProgram);


void printInvalidEmails();


void printAverageDaysInCourse(string studentID);



// deconstructor function
Roster::~Roster()
{

}
