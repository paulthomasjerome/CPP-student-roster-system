#include "securityStudent.h"
#include "degree.h"
#include <iostream>
#include <string>
using std::string;

SecurityStudent::SecurityStudent() {

	this->degreeProgram = Degree::SECURITY;
}

SecurityStudent::SecurityStudent(
	string studentId,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int *daysToCompleteCourse,
	Degree degreeProgram) {
	    
		this->studentId = studentId;

		this->firstName = firstName;

        this->lastName = lastName;

        this->emailAddress = emailAddress;

        this->age = age;

        this->daysToCompleteCourse = new int[3];

        this->daysToCompleteCourse[0] = daysToCompleteCourse[0];

        this->daysToCompleteCourse[1] = daysToCompleteCourse[1];

        this->daysToCompleteCourse[2] = daysToCompleteCourse[2];

		this->degreeProgram = degreeProgram;
}

Degree SecurityStudent::getDegreeProgram() {

	return this->degreeProgram;
}

void SecurityStudent::print() {

	Student::print();

	std::cout << "\t Student Degree Program: SECURITY" << std::endl;
}


SecurityStudent::~SecurityStudent() {

}


