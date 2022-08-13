#include "student.h"

//Student::Student() {
//	this->studentID = "";
//	this->firstName = "";
//	this->lastName = "";
//
//	for (int i = 0; i < numberOfClasses; i++) this->daysToComplete[i] = 0;
//
//	this->degreeProgram = DegreeProgram::SECURITY;
//}

//Constructor for Student Object
Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], DegreeProgram degreeProgram) {

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	
	for (int i = 0; i < numberOfClasses; i++) this->daysToComplete[i] = daysToComplete[i];

	this->degreeProgram = degreeProgram;
}

//Destructor for the student object
Student::~Student() {}

// Getters for the student attributes
string Student::getID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
int* Student::getDaysToComplete() { return this->daysToComplete; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//Setters for the student attributes
void Student::setID(string studentID) { this->studentID = studentID; return; }
void Student::setFirstName(string firstName) { this->firstName = firstName; return; }
void Student::setLastName(string lastName) { this->lastName = lastName; return; }
void Student::setEmail(string email) { this->email = email; return; }

//Setter for daysToComplete Array
void Student::setDaysToComplete(int daysToComplete[]) {
	for (int i = 0; i < numberOfClasses; i++) this->daysToComplete[i] = daysToComplete[i];
	return;
}

//Sets the DegreeProgram attribute for the student object
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; return; }

//prints the header for the "table"
void Student::printHeader() {
	cout << "ID\t";
	cout << "First\t";
	cout << "Last\t";
	cout << "Email\t";
	cout << "Class 1\t";
	cout << "Class 2\t";
	cout << "Class 3\t";
	cout << "Program\t";
	cout << endl;
	return;
}
//Prints the attributes of the student object
void Student::print() {
	cout << this->studentID << "\t";
	cout << this->firstName << "\t";
	cout << this->lastName << "\t";
	cout << this->email << "\t";
	cout << this->daysToComplete[0] << "\t";
	cout << this->daysToComplete[1] << "\t";
	cout << this->daysToComplete[2] << "\t";
	cout << degreeProgramStrings[(int)this->degreeProgram];
	cout << endl;
	return;
	
}
