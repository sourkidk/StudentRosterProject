#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using std::string;
using std::cout;
using std::endl;
using std::left;
using std::setw;

class Student {
public:
	const static int numberOfClasses = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysToComplete[numberOfClasses];
	DegreeProgram degreeProgram;

public:
	Student();

	Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], DegreeProgram degreeProgram);

	~Student();

	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysToComplete();
	DegreeProgram getDegreeProgram();

	void setID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysToComplete(int daysToComplete[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	static void printHeader();

	void print();
};
