#ifndef STUDENTCLASS_H
#define STUDENTCLASS_H

#include <iostream>
#include <iomanip>
#include "degree.h"

using namespace std;

class Student	// declare student class
{
public: // establishied courses to complete
	const static int classesToComplete = 3;

private:
	// establish required student variables
	string studentID;
	string studentFirstName;
	string studentLastName;
	string studentEmail;
	int studentAge;
	int studentDaysToComplete[classesToComplete];
	DegreeProgram studentDegreeProgram;

public: // declare class functions; operations a class user can perform on object

	// setter functions
	void setStuID(string stuID);						// sets student's ID
	void setFirstName(string firstName);				// sets student's first name
	void setLastName(string lastName);					// sets student's last name
	void setEmail(string email);						// sets student's email
	void setAge(int age);								// sets student's age
	void setDaysToComplete(int class1, int class2, int class3);// sets student's days to complete each course
	void setDegreeProgram(DegreeProgram degreeProgram);	// sets student's degree program

	// getter functions
	string getStudentID();								// returns student's ID
	string getStudentFirstName();						// returns student's first name
	string getStudentLastName();						// returns student's last name
	string getStudentEmail();							// returns student's email
	int getStudentAge();								// returns student's age
	int* getStudentDaysToComplete();					// returns student's days to complete
	DegreeProgram getStudentDegreeProgram();			// returns student's degree program

	// print functions
	void printStudentID();								// prints student's ID
	void printStudentFirstName();						// prints student's first name
	void printStudentLastName();						// prints student's last name
	void printStudentEmail();							// prints student's email
	void printStudentAge();								// prints student's age
	void printStudentDaysToComplete();					// prints student's days to complete each course
	void printStudentDegreePrograms();					// prints student's degree program
	void print();										// prints 'this' student's data

	static void printHeader();							// displays header for data table

	// default constructor
	Student();								

	// parameter constructor
	Student(string studentID, string studentFirstName, string studentLastName, string studentEmail, int studentAge, int studentDaysToComplete[],DegreeProgram studentDegreeProgram);

	// destructor
	~Student();
};


#endif