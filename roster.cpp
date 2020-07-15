#include <string>
#include <iostream>
#include <sstream>
#include "roster.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
using std::string;
using std::getline;
using std::stoi;

Roster::Roster() {
	
}

void Roster::add(
	string studentId, 
	string firstName, 
	string lastName, 
	string emailAddress, 
	int age, 
	int daysToCompleteCourse1, 
	int daysToCompleteCourse2, 
	int daysToCompleteCourse3, 
	Degree degreeProgram) {
		
	int daysToCompleteCourse[] = { 
		daysToCompleteCourse1, 
		daysToCompleteCourse2, 
		daysToCompleteCourse3 
	};
	

	if (degreeProgram == Degree::NETWORK) {

		this->classRosterArray[sumStudentsInRoster] = new NetworkStudent(studentId, firstName, lastName, emailAddress, age, daysToCompleteCourse, degreeProgram);
		sumStudentsInRoster += 1;
	}
	else if (degreeProgram == Degree::SECURITY) {

		this->classRosterArray[sumStudentsInRoster] = new SecurityStudent(studentId, firstName, lastName, emailAddress, age, daysToCompleteCourse, degreeProgram);
		sumStudentsInRoster += 1;
	}
	else if (degreeProgram == Degree::SOFTWARE) {

		this->classRosterArray[sumStudentsInRoster] = new SoftwareStudent(studentId, firstName, lastName, emailAddress, age, daysToCompleteCourse, degreeProgram);
		sumStudentsInRoster += 1;
	}
}

void Roster::remove(string studentId) {

	bool flag = false;

	for (int index = 0; index < 5; ++index) {

		if (classRosterArray[index] != NULL) {

			if (studentId == classRosterArray[index]->getStudentId()) {

				classRosterArray[index] = nullptr;

				flag = true;

				std::cout << "Student ID: " << studentId << " has been removed." << std::endl << "\n";
			}
		}
	}

	if (flag) {

		std::cout << "ERROR Student ID: " << studentId << " not found." << std::endl << "\n";
	}
}

void Roster::printAll() {

	std::cout << "All Student Information: " << std::endl << "\n";

	for (int index = 0; index < 5; ++index) {

		(*classRosterArray[index]).print();
		std::cout << std::endl;
	}
	
}

void Roster::printAverageDaysInCourse(string studentId) {

	for (int index = 0; index < 5; ++index)
	{

		if ((*classRosterArray[index]).getStudentId() == studentId) {

			int averageDays = 0;

			averageDays = ((*classRosterArray[index]).getDaysToCompleteCourse()[0] + (*classRosterArray[index]).getDaysToCompleteCourse()[1] + (*classRosterArray[index]).getDaysToCompleteCourse()[2]) / 3;

			std::cout << "Student: " << studentId << " has an average of " << averageDays << " days left in their courses." << std::endl;
		}
	}
}

void Roster::printInvalidEmails() {

	for (int index = 0; index < 5; ++index) {

		string emailAddress = "";

		emailAddress = (*classRosterArray[index]).getEmailAddress();

		if (emailAddress.find('.') == string::npos || emailAddress.find(' ') != string::npos || emailAddress.find('@') == string::npos) {

			std::cout << emailAddress << " is not a valid email address, please update" << std::endl << "\nS";

		}
	}
}

void Roster::printByDegreeProgram(Degree degreeProgram) {

	for (int index = 0; index < 5; ++index) {

		if (degreeProgram == (*classRosterArray[index]).getDegreeProgram()) {

			(*classRosterArray[index]).print();

			std::cout << "\n";
		}
	}

	std::cout << std::endl;
}

Roster::~Roster() {

}

int main() {

	std::cout << "COURSE TITLE: Scripting And Programming Applications (C867)" << std::endl;

	std::cout << "PROGRAMMING LANGUAGE: C++" << std::endl;

	std::cout << "STUDENT ID: #001055583" << std::endl;

	std::cout << "NAME: Paul Jerome" << std::endl << "\n";

	Roster classRoster;

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Paul,Jerome,pjerom4@wgu.edu,25,3,5,11,SOFTWARE"
	};

	//for each student data record in the student data table
	for (int index = 0; index < 5; ++index) {

		//prepare to temporarily store and replace individual data fields
		string data;

		//prepare storage for collection of data fields used to fill each slot in roster
		string parsedDataFields[9];

		//prepare storage for tracking which item we are adding to parsedDataFields
		int dataFieldIndex = 0;

		//temporarily store the current record to be parsed
		string studentDataRecord = studentData[index];

		//prepare the stored recorded to be parsed
		std::istringstream inputStringStream(studentDataRecord);

		//while there are still characters in the current student record
		while (getline(inputStringStream, data, ',')) {

			//store the current field at its appropriate index
			parsedDataFields[dataFieldIndex] = data;

			//increment
			dataFieldIndex += 1;
		}

		//prepare all data to be added to Roster element
		string studentId = parsedDataFields[0];
		
		string firstName = parsedDataFields[1];

		string lastName = parsedDataFields[2];

		string emailAddress = parsedDataFields[3];

		int age = std::stoi(parsedDataFields[4]);

		int daysToCompleteCourse1 = std::stoi(parsedDataFields[5]);

		int daysToCompleteCourse2 = std::stoi(parsedDataFields[6]);

		int daysToCompleteCourse3 = std::stoi(parsedDataFields[7]);

		string degreeProgramAsString = parsedDataFields[8];

		Degree degreeProgram;

		if (degreeProgramAsString == "SOFTWARE") {
			degreeProgram = SOFTWARE;
		}
		else if (degreeProgramAsString == "SECURITY") {
			degreeProgram = SECURITY;
		}
		else if (degreeProgramAsString == "NETWORK") {
			degreeProgram = NETWORK;
		}

		classRoster.add(
			studentId,
			firstName,
			lastName,
			emailAddress,
			age,
			daysToCompleteCourse1,
			daysToCompleteCourse2,
			daysToCompleteCourse3,
			degreeProgram
		);
	}

	classRoster.printAll();

	classRoster.printInvalidEmails();

	for (int i = 0; i < 5; ++i) {

		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
		std::cout << "\n";
	}

	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.remove("A3");

	classRoster.remove("A3");

	classRoster.~Roster();

	return 0;
}