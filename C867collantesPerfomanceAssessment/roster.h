#ifndef ROSTERCLASS_H
#define ROSTERCLASS_H

#include <string>
#include "student.h"


class Roster
{
private:
	int lastIndex = -1;										// establishes array index
	const static int rosterArraySize = 5;
	Student* classRosterArray[rosterArraySize];					// array of pointers to hold data provided in "studentData Table."

public:

	void parse(string studentData);								// extracts data individually via comma delimited strings
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);

	// print declarations
	void printAll();										// call print() from Student class
	void printByDegreeProgram(DegreeProgram degreeProgram); // adds in degreeProgram
	void printInvalidEmails();								// prints invalid email
	void printAverageDaysInCourse(string studentID);		// prints average days in course

	// constructor & friends
	Roster(int numStudents);
	int numStudents;
	int rosterIndex;

	// deconstructor
	~Roster();
};


#endif
