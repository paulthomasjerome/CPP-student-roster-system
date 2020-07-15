#include "student.h"

class SecurityStudent : public Student {
	public:
		SecurityStudent();

		SecurityStudent(
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

	~SecurityStudent();
};