#include <iostream>
#include <sstream>
#include "roster.h"
#include "student.h"
using namespace std; 

//initialize maxSize, set to 0 & and allocate memory for an array of student pointers

Roster::Roster(int maxSize)
{
	this->maxSize = maxSize; 
	this->currentSize = 0; 
	classRosterArray = new Student * [maxSize]; 
}

//Destructor that deletes objects in classRoster array, free memory 

Roster::~Roster() {
	for (int i = 0; i < currentSize; i++) {
		delete classRosterArray[i];
	}
	delete[] classRosterArray;
}


//adds a student object to the classRosterArray
//creates error message if there is no space
void Roster::addStudent(Student* student)
{
	if (currentSize < maxSize)
	{
		classRosterArray[currentSize++] = student;
	}
	else
	{
		cout << "Roster is  full. Cannot add more students." << endl; 
	}
}

//creates a new student object adds it to classRosterArray by calling addStudent

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse, int daysInCourse2, int daysInCourse3, Degree degreeProgram)
{
	int daysInCourseArray[3] = { daysInCourse, daysInCourse2, daysInCourse3 };

	Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseArray, degreeProgram); 

	addStudent(newStudent); 
}

//Void Roster::add Overload 
void Roster::add(string studentData)
{
	istringstream ss(studentData); 
	string token; 
	string studentID, firstName, lastName, emailAddress, degreeString; 
	int age, daysInCourse[3]; 
	Degree degree; 

	getline(ss, studentID, ',');
	getline(ss, firstName, ',');
	getline(ss, lastName,  ',');
	getline(ss, emailAddress, ',');
	ss >> age; 
	ss.ignore(); 
	ss >> daysInCourse[0]; 
	ss.ignore(); 
	ss >> daysInCourse[1]; 
	ss.ignore(); 
	ss >> daysInCourse[2]; 
	ss.ignore(); 
	getline(ss, degreeString, ',');

	if (degreeString == "Security")
	{
		degree = Degree::Security; 
	}
	else if (degreeString == "Network")
	{
		degree = Degree::Network; 
	}
	else
	{
		degree = Degree::Software; 
	}

	classRosterArray[currentSize++] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degree); 

}

//Removes the student with the given ID from classRosterArray
//Shifts remaining elements left, prints not found or error message
void Roster::remove(string studentID) {
	bool found = false; 
	for(int i = 0; i < currentSize; i++)
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			delete classRosterArray[i]; 
			for (int j = i; j < currentSize - 1; j++)
			{
				classRosterArray[j] = classRosterArray[j + 1]; 
				}
			currentSize--; 
			found = true; 
			cout << "Student " << studentID << " removed from roster: " << endl;
			break; 
		}
	    if (!found)
	    {
			cout << "Error: Student ID " << studentID << " not found." << endl; 
		}
}
//Error C4700, forgot i = 0


//prints classRosterArray student details 
void::Roster::printAll()
{
	for (int i = 0; i < currentSize; i++)
	{
		classRosterArray[i]->print(); 
	}
}

//takes student ID and calculates the average number of days spent in courses

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < currentSize; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			int* days = classRosterArray[i]->getDaysInCourse();  // Assuming getDaysInCourse() returns an array
			int average = (days[0] + days[1] + days[2]) / 3;
			cout << "Average days in course for student " << studentID << ": " << average << endl;
			return;
		}
	}
}


void Roster::printInvalidEmails()
{
	for (int i = 0; i < currentSize; i++)
	{
		string email = classRosterArray[i]->getEmailAddress();  // Move the email declaration outside the loop

		// Check for invalid email conditions
		if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos)
		{
			cout << "Invalid email: " << email << endl;
		}
	}
}


/*
void Roster::printInvalidEmails()
{
	for (int i = 0; i < currentSize; i++)
	{
		for (int i = 0; i < currentSize; i++)
			string email = classRosterArray[i]->getEmailAddress(); 
		if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos)
		{
			cout << "Invalid email: " << email << endl; 
		}
	}
}
*/