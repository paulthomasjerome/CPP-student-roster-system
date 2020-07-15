#pragma once
#include "degree.h"
#include <string>
using std::string;

class Student {
    protected:
        string studentId;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int* daysToCompleteCourse;
        Degree degreeProgram;

    public:
        Student();

        Student(
            string studentId,
            string firstName,
            string lastName,
            string emailAddress,
            int age,
            int daysToCompleteCourse[]
        );

    string getStudentId() const;

    void setStudentId(string studentID);

    string getFirstName() const;

    void setFirstName(string firstName);

    string getLastName() const;

    void setLastName(string lastName);

    string getEmailAddress() const;

    void setEmailAddress(string emailAddress);

    int getAge() const;

    void setAge(int age);

    int* getDaysToCompleteCourse();

    void setDaysToCompleteCourse(int daysToCompleteCourse[]);

    virtual void print() = 0;

    ~Student();

    virtual Degree getDegreeProgram() = 0;
};

