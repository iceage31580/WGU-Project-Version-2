#include <iostream>
#include "student.h"
using namespace std;

//Student constructor 
Student::Student(const string& studentID, const string& firstName, const string& lastName, const string& emailAddress, int age, const int daysInCourse[], Degree degree) :
	studentID(studentID), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age), degree(degree)
{
	for (int i = 0; i < 3; i++)
	{
		this->daysInCourse[i] = daysInCourse[i]; 
	}
	cout << "Student Object Created!" << endl; 
}
//