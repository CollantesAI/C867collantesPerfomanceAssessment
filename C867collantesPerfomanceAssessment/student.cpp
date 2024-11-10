#include <iostream>
#include <string>
#include "student.h"

using namespace std;

// setter function definitions
void Student::setStuID(string stuID) 
{
	this->studentID = stuID;
}

void Student::setFirstName(string firstName)
{
	this->studentFirstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->studentLastName = lastName;
}

void Student::setEmail(string email)
{
	this->studentEmail = email;
}

void Student::setAge(int age)
{
	this->studentAge = age;
}

void Student::setDaysToComplete(int class1, int class2, int class3)
{
	for (int i = 0; i < classesToComplete; i++)
	{
		this->studentDaysToComplete[0] = class1;
		this->studentDaysToComplete[1] = class2;
		this->studentDaysToComplete[2] = class3;
	}
}

void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
	this->studentDegreeProgram = degreeProgram;
}

// getter function definitions
string Student::getStudentID()
{
	return this->studentID;
}

string Student::getStudentFirstName()
{
	return this->studentFirstName;
}

string Student::getStudentLastName()
{
	return this->studentLastName;
}

string Student::getStudentEmail()
{
	return this->studentEmail;
}

int Student::getStudentAge()
{
	return this->studentAge;
}

int* Student::getStudentDaysToComplete()
{
	return this->studentDaysToComplete;
}

DegreeProgram Student::getStudentDegreeProgram()
{
	return this->studentDegreeProgram;
}

// print function definitions
void Student::printStudentID()
{
	cout << this->getStudentID() << endl;
}

void Student::printStudentFirstName()
{
	cout << this->getStudentFirstName() << endl;
}

void Student::printStudentLastName()
{
	cout << this->getStudentLastName() << endl;
}

void Student::printStudentEmail()
{
	cout << this->getStudentEmail() << endl;
}

void Student::printStudentAge()
{
	cout << this->getStudentAge() << endl;
}

void Student::printStudentDaysToComplete()
{
	cout << this->getStudentDaysToComplete()[0] << ", ";
	cout << this->getStudentDaysToComplete()[1] << ", ";
	cout << this->getStudentDaysToComplete()[2] << endl;
}

void Student::printStudentDegreePrograms()
{
	cout << degreeProgramStrings[this->getStudentDegreeProgram()] << endl;
}

void Student::print()
{
	cout << this->getStudentID() << "\t";
	cout << this->getStudentFirstName() << "\t";
	cout << this->getStudentLastName() << "\t";
//	cout << this->getStudentEmail() << "\t";	// n/a
	cout << this->getStudentAge() << "\t";
	cout << this->getStudentDaysToComplete()[0] << ", ";
	cout << this->getStudentDaysToComplete()[1] << ", ";
	cout << this->getStudentDaysToComplete()[2] << "\t";
	cout << degreeProgramStrings[this->getStudentDegreeProgram()] << endl;
}

// default constructor function
Student::Student()
{
	this->studentID = "";
	this->studentFirstName = "";
	this->studentLastName = "";
	this->studentEmail = "";
	this->studentAge = 0;
	this->studentDaysToComplete[0] = 0;
	this->studentDaysToComplete[1] = 0;
	this->studentDaysToComplete[2] = 0;
	this->studentDegreeProgram;
}

// parameter contructor function
Student::Student(string studentID, string studentFirstName, string studentLastName, string studentEmail, int studentAge, int studentDaysToComplete[], DegreeProgram studentDegreeProgram)
{
	this->studentID = studentID;
	this->studentFirstName = studentFirstName;
	this->studentLastName = studentLastName;
	this->studentEmail = studentEmail;
	this->studentAge = studentAge;
	this->studentDaysToComplete[0] = studentDaysToComplete[0];
	this->studentDaysToComplete[1] = studentDaysToComplete[1];
	this->studentDaysToComplete[2] = studentDaysToComplete[2];
	this->studentDegreeProgram = studentDegreeProgram;
}

// destructot (not used; does nothing)
Student::~Student() {}