#include "softwareStudent.h"
#include "degree.h"
#include <iostream>
#include <string>
using std::string;

SoftwareStudent::SoftwareStudent() {

	this->degreeProgram = Degree::SOFTWARE;
}

SoftwareStudent::SoftwareStudent(
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

Degree SoftwareStudent::getDegreeProgram() {

	return this->degreeProgram;
}

void SoftwareStudent::print() {

	Student::print();

	std::cout << "\t Student Degree Program: SOFTWARE" << std::endl;
}


SoftwareStudent::~SoftwareStudent() {

}


