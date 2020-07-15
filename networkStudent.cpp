#include "networkStudent.h"
#include "degree.h"
#include <iostream>
#include <string>
using std::string;

NetworkStudent::NetworkStudent() {

	this->degreeProgram = Degree::NETWORK;
}

NetworkStudent::NetworkStudent(
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

Degree NetworkStudent::getDegreeProgram() {

	return this->degreeProgram;
}

void NetworkStudent::print() {

	Student::print();

	std::cout << "\t Student Degree Program: NETWORK" << std::endl;
}


NetworkStudent::~NetworkStudent() {

}


