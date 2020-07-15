#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

class Roster {
public:
	int sumStudentsInRoster = 0;

	Roster();

	Student *classRosterArray[5];

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);

	void remove(string studentId);

	void printAll();

	void printAverageDaysInCourse(string studentId);

	void printInvalidEmails();

	void printByDegreeProgram(Degree degreeProgram);

	~Roster();
};

