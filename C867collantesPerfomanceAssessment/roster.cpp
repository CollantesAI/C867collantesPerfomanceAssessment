#include <iostream>
#include <string>

#include "roster.h"

using namespace std;

// constructor
Roster::Roster(int numStudents)
{
	this->numStudents = numStudents;
	this->rosterIndex = 0; // establishes array index
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
		else if (program == "NETWORK")
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

		// increment array index
		rosterIndex++;
	}
}

// add student object to roster 
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 }; // repackage into array
	classRosterArray[numStudents] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

// print functions
void Roster::printAll()
{
	cout << "Displaying all students:" << endl << endl
		 << "StuID\tFirst\tLast\tAge\tDays Left\tDegree" << endl << endl;
	for (int i = 0; i < numStudents; i++)
	{
		if (classRosterArray == nullptr)
		{
			continue;
		}
		else
		{
			classRosterArray[i]->print();
		}
	}
	cout << endl << endl;
}

// print students that match specified degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	cout << "Showing Students in degree program:";
	int studentsWithDegree = 0;
	for (int i = 0; i < numStudents; i++)
	{
		if (classRosterArray[i]->getStudentDegreeProgram() == degreeProgram)
		{
			classRosterArray[i]->print();
			++studentsWithDegree;
		}
		if (studentsWithDegree == 0)
		{
			cout << "ERROR" << endl;
		}
	}
}

// print invalid emails
void Roster::printInvalidEmails()
{
	cout << "Displaying invalid emails:" << endl;

	bool anyInvalidEmails = false;
	for (int i = 0; i < numStudents; i++)
	{
		string eAddress = (classRosterArray[i]->getStudentEmail());
		if ((eAddress.find("@") == string::npos) || (eAddress.find(".") == string::npos) || (eAddress.find(" ") != string::npos))
		{
			anyInvalidEmails = true;
			cout << classRosterArray[i]->getStudentEmail() << " - is invalid" << endl;
		}
	}
	if (!anyInvalidEmails)
	{
		cout << "NONE DETECTED" << endl;
	}
}

// print average days in courses for each student
void Roster::printAverageDaysInCourse(string studentID)
{
	int numClassesPerStudent = 3;
	cout << "Average days in course:" << endl;
	for (int i = 0; i < numStudents; i++)
	{
		if (studentID == classRosterArray[i]->getStudentID())
		{
			cout << "Student ID: " << studentID << ", average days in course is: "
				 << ((classRosterArray[i]->getStudentDaysToComplete()[0] +
				      classRosterArray[i]->getStudentDaysToComplete()[1] +
					  classRosterArray[i]->getStudentDaysToComplete()[2]) / numClassesPerStudent)
				 << endl;
		}
	}
	cout << endl;
}

// remove student from roster
void Roster::remove(string studentID)
{
	bool studentExists = false;
	cout << "Removing student with ID: " << studentID << "." << endl << endl;
	for (int i = 0; i < numStudents; i++)
	{
		if (classRosterArray[i] == nullptr)
		{
			continue;
		}
		else if (studentID == classRosterArray[i]->getStudentID())
		{
			classRosterArray[i] = nullptr;
			studentExists = true;
			break;
		}
	}
	if (studentExists == false)
	{
		cout << "The student with the ID: " << studentID << ", was not found." << endl;
	}
	else
	{
		cout << "The student with the ID: " << studentID << ", has been removed." << endl << endl;
		this->printAll();
	}
}

// deconstructor function
Roster::~Roster()
{
	for (int i = 0; i < numStudents; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}