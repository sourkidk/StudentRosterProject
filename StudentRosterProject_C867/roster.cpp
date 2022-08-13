#include "roster.h"

Roster::Roster(const string studentData[]) {
	/*Parse out the different attributes of each student object, by finding commas and then 
	slicing the strings based on the location of the commas*/
	for (int i = 0; i < numStudents; i++) {
		string studentString = studentData[i];

		DegreeProgram degProg = DegreeProgram::SOFTWARE;
		if (studentString.back() == 'K') degProg = DegreeProgram::NETWORK;
		else if (studentString.back() == 'Y') degProg = DegreeProgram::SECURITY;
		else degProg = DegreeProgram::SOFTWARE;

		int rightIndex = studentString.find(",");
		string stdID = studentString.substr(0, rightIndex);
		
		int leftIndex = rightIndex + 1;
		rightIndex = studentString.find(",", leftIndex);
		string stdFirstName = studentString.substr(leftIndex, rightIndex - leftIndex);

		leftIndex = rightIndex + 1;
		rightIndex = studentString.find(",", leftIndex);
		string stdLastName = studentString.substr(leftIndex, rightIndex - leftIndex);

		leftIndex = rightIndex + 1;
		rightIndex = studentString.find(",", leftIndex);
		string stdEmail = studentString.substr(leftIndex, rightIndex - leftIndex);

		leftIndex = rightIndex + 1;
		rightIndex = studentString.find(",", leftIndex);
		int stdAge = stoi(studentString.substr(leftIndex, rightIndex - leftIndex));

		int dIC[3];

		for (int i = 0; i < 3; i++) {
			leftIndex = rightIndex + 1;
			rightIndex = studentString.find(",", leftIndex);
			dIC[i] = stoi(studentString.substr(leftIndex, rightIndex - leftIndex));
		}

		add(stdID, stdFirstName, stdLastName, stdEmail, stdAge, dIC[0], dIC[1], dIC[2], degProg);

	}
}

//Method to add a student object to the classRosterArray
void Roster::add(string stdID, string stdFirstName, string stdLastName, string stdEmail, int stdAge, int days1, int days2,int days3, DegreeProgram degProg) {
	int daysArray[3] = { days1, days2, days3 };
	classRosterArray[++lastIndex] = new Student(stdID, stdFirstName, stdLastName, stdEmail,stdAge, daysArray, degProg);
	cout << "Student added to class Roster at row " << lastIndex + 1 << endl;
	return;

}

//Prints all the student objects in the classRoster Array
void Roster::printAll() {
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
	cout << "\n";
	return;
}

//Iterates through the classRosterArray and prints any students matching the input degree program enum.
void Roster::printByDegreeProgram(DegreeProgram degProg) {

	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degProg) classRosterArray[i]->print();
	}
	cout << "\n";
	return;
}

//Iterates through the students and checks the email attribute for the presence of the '@' symbol and period and no spaces.
void Roster::printInvalidEmails() {

	for (int i = 0; i <= Roster::lastIndex; i++) {
		string email = classRosterArray[i]->getEmail();
		if (email.find(' ') != string::npos || email.find('@') == string::npos || email.find('.') == string::npos)
			cout << email << " is invalid" << endl;
	}
		cout << "\n";
		return;
}
//returns the classRosterArray to external calls
Student** Roster::getStudents() {
	return this->classRosterArray;
}

//For the given student, calculates and prints the average number of days accross the classes completed.
void Roster::printAverageDaysInCourse(string stdID) {

	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getID() == stdID) {

			cout << stdID << ":";
			cout << (classRosterArray[i]->getDaysToComplete()[0] +
				classRosterArray[i]->getDaysToComplete()[1] +
				classRosterArray[i]->getDaysToComplete()[2]) / 3.0 << endl;
		}
	}
	return;

}

//Removes a student object from the Roster Array
void Roster::remove(string stdID) {
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getID() == stdID) {
			success = true;
			Student* temp = classRosterArray[i];
			classRosterArray[i] = classRosterArray[numStudents - 1];
			classRosterArray[numStudents - 1] = temp;
			Roster::lastIndex--;
		}
	}
	if (success) {

		cout << "Student " << stdID << " removed." << endl;
		//printAll();
	}
	else cout << "Student " << stdID << " not found." << endl;
	cout << "\n";
	return;
}

//Class destructor.  
Roster::~Roster() {

	for (int i = 0; i < numStudents; i++) {
		cout << "Destructor called for " << classRosterArray[i]->getID() << endl;
		classRosterArray[i] == nullptr;
	}
	return;
}






















