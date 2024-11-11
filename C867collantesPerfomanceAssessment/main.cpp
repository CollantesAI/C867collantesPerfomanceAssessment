#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main()
{
    const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                                   "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                   "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                   "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                                   "A5,Miguel,Collantes,mcolla14@wgu.edu,28,31,32,33,SOFTWARE" };

    const string courseTitle = "Course: C867 Scripting and Programming - Applications";
    const string progLangUsed = "Programming Language Used: C++";
    const string WGUStuID = "Student ID: 012434679";
    const string WGUStuName = "Student Name: Miguel Collantes";

    cout << courseTitle << endl
         << progLangUsed << endl
         << WGUStuID << endl
         << WGUStuName << endl
         << endl;

    // parsing provided studentData
    Roster* classRoster = new Roster(5);
    for (int i = 0; i < 5; i++)
    {
        classRoster->parse(studentData[i]);
    }

    // displaying provided data
    classRoster->printAll();
    
    // displaying invalid emails
    classRoster->printInvalidEmails();

    return 0;
}