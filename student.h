#pragma once
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include "degreeChosen.h"
#include <string>
#include <iostream>

class Student {
	public:
		Student(const std::string& studentID, const std::string& firstName,
			const std::string& lastName,
			const std::string& emailAddress,
			int age,
			const int daysInCourse[],
			Degree degree); 

		std::string getStudentID() const;
		std::string getFirstName() const; 
		std::string getLastName() const; 
		std::string getEmailAddress() const; 
		int getAge() const; 
		int* getDaysInCourse(); 
		Degree getDegree() const; 

		void setStudentID(const std::string& studentID);
		void setFirstName(const std::string& firstName);
		void setLastName(const std::string&
			lastName);
		void setEmailAddress(const std::string& emailAddress); 
		void setAge(int age); 
		void setDaysInCourse(const int daysInCourse[]); 
		void setDegree(Degree degree); 

		void print() const; 

	private:
		std::string studentID; 
		std::string firstName; 
		std::string lastName; 
		std::string emailAddress; 
		int age; 
		int daysInCourse[3]; //tracks day in course
		Degree degree; 

};

#endif //STUDENT_H_INCLUDED