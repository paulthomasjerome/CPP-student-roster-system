#include "student.h"
#include <iostream>

Student::Student() {
   
}

Student::Student(
    string studentId, 
    string firstName, 
    string lastName, 
    string emailAddress, 
    int age, 
    int *daysToCompleteCourse) { 

        this->studentId = studentId;

        this->firstName = firstName;

        this->lastName = lastName;

        this->emailAddress = emailAddress;

        this->age = age;

        this->daysToCompleteCourse[0] = daysToCompleteCourse[0];

        this->daysToCompleteCourse[1] = daysToCompleteCourse[1];

        this->daysToCompleteCourse[2] = daysToCompleteCourse[2];
}

string Student::getStudentId() const {

    return this->studentId;
}

void Student::setStudentId(string studentId) {

    this->studentId = studentId;
}

string Student::getFirstName() const {

    return this->firstName;
}

void Student::setFirstName(string firstName) {

    this->firstName = firstName;
}

string Student::getLastName() const {

    return this->lastName;
}

void Student::setLastName(string lastName) {

    this->lastName = lastName;
}

string Student::getEmailAddress() const {

    return this->emailAddress;
}

void Student::setEmailAddress(string emailAddress) {

    this->emailAddress = emailAddress;
}

int Student::getAge() const {

    return this->age;
}

void Student::setAge(int age) {


    this->age = age;
}

int* Student::getDaysToCompleteCourse() {

    return this->daysToCompleteCourse;
}

void Student::setDaysToCompleteCourse(int daysToCompleteCourse[]) {

    this->daysToCompleteCourse[0] = daysToCompleteCourse[0];
    this->daysToCompleteCourse[1] = daysToCompleteCourse[1];
    this->daysToCompleteCourse[2] = daysToCompleteCourse[2];
}

void Student::print() {
    std::cout << "\t Student ID: " << getStudentId();

    std::cout << "\t Student First Name: " << getFirstName();

    std::cout << "\t Student Last Name: " << getLastName();

    std::cout << "\t Student Email Address: " << getEmailAddress();

    std::cout << "\t Student Age: " << getAge();

    std::cout << "\t Days left in each course: " << getDaysToCompleteCourse()[0] << ", " << getDaysToCompleteCourse()[1] << ", " << getDaysToCompleteCourse()[2];
}


Student::~Student() {
    if (daysToCompleteCourse != nullptr) {
        daysToCompleteCourse = nullptr;
    }

    delete[] daysToCompleteCourse;
}