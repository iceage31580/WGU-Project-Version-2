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
//not working right now beacuse header file needs to be created

//D.2 Accessors 
string Student::getStudentID() const { return studentID;  }
string Student::getFirstName() const {
	return firstName; 
}
string Student::getLastName() const{
	return lastName; 
}
string Student::getEmailAddress() const {
	return emailAddress; 
}
int Student::getAge() const {
	return age; 
}
int* Student::getDaysInCourse() {
	return daysInCourse; 
}
Degree Student::getDegree() const {
	return degree;
}

//d.2 mutator 

void Student::setStudentID(const string& studentID) {
	this->studentID = studentID; 
}
void Student::setFirstName(const string& firstName) {
	this->firstName = firstName;
}
void Student::setLastName(const string&
	lastName) {
	this->lastName = lastName; 
}
void Student::setEmailAddress(const string&
	emailAddress) {
	this->emailAddress = emailAddress; 
}

void Student::setAge(int age) 
	{ this->age = age;}

void Student::setDaysInCourse(const int daysInCourse[])
{
	for (int i = 0; i < 3; i++)
	{
		this->daysInCourse[i] = daysInCourse[i]; 
	}
}

void Student::setDegree(Degree degree)
{
	this->degree = degree;
}

void Student::print() const
{
	cout << "Student ID: " << studentID << "\t"
		<< "First Name: " << firstName << "\t"
		<< "Last Name:  " << lastName << "\t"
		<< "Age:        " << age << "\t"
		<< "Days in Course: " << daysInCourse[0]
		<< ", " << daysInCourse[1]
		<< ", " << daysInCourse[2]
		<< "\t" << "Degree Program : "
		<< static_cast<int>(degree) << endl; 
}


