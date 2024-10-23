#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include<string>
#include"student.h"
#include"degreeChosen.h"

class Roster {
public: 
	Roster(int maxSize); //Constructor 
	~Roster();			 //Destructor

	void addStudent(Student* student); //Adds a student 
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int DaysInCourse3, Degree degreeProgram);
	void add(string studentData); //overload add function
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID); 
	void printInvalidEmails(); 
private: 
	Student** classRosterArray; 
	int maxSize; 
	int currentSize; 
};

#endif //Roster_H