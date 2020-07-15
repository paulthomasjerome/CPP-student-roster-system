#include "student.h"

class SoftwareStudent : public Student {
public:
	SoftwareStudent();

	SoftwareStudent(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int* daysToCompleteTerm,
		Degree degreeProgram
	);

	Degree getDegreeProgram() override;

	void print() override;

	~SoftwareStudent();
};