#include "student.h"

class NetworkStudent : public Student {
public:
	NetworkStudent();

	NetworkStudent(
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

	~NetworkStudent();
};