#pragma once
#include "student.h"

class Roster {
private:
	int lastIndex = -1;
	const static int numStudents = 5;
	
	Student* classRosterArray[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };

public:
	Roster(const string studentData[]);

	Student** getStudents();

	void add(string stdID, string stdFirstName, string stdLastName, string stdEmail, int stdAge, int days1, int days2, int days3, DegreeProgram degProg);

	void printAll();
	void printByDegreeProgram(DegreeProgram degProg);
	void printAverageDaysInCourse(string stdID);
	void printInvalidEmails();
	void remove(string stdID);

	~Roster();



};
