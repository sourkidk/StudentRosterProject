#include <iostream>
#include "roster.h"

int main() {

    cout << "----------------------------------------------" << std::endl;
    cout << "C867 Scripting & Programming Applications" << std::endl;
    cout << "Built using C++ 14 Standard " << std::endl;
    cout << "By Keith Fletcher" << std::endl;
    cout << "ID: 009224586  Program: BS Comp-Sci (5/1/22)" << std::endl;
    cout << "----------------------------------------------" << std::endl;

    //Array containing strings of student information.
    const string studentData[5] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Keith,Fletcher,kflet87@wgu.edu,32,21,4,9,SOFTWARE" };

    const int numStudents = 5;
    //Instantiates a Roster object and student objects from studentData
    Roster classRoster(studentData);
    cout << "\n";

    cout << "Displaying all students:" << endl;
    classRoster.printAll();

    
    classRoster.printInvalidEmails();
    
    //iterate through each student in the classRosterArray and call printAverageDaysInCourse for each
    for (int i = 0; i < numStudents; i++) {
        classRoster.printAverageDaysInCourse(classRoster.getStudents()[i]->getID());
    }
    cout << "\n";
    
    cout << "Displaying students in the Software degree program:" << "\n";
    //iterate through the student objects and print any that match this degree program
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");


    return 0;
}