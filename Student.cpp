
#include "Student.h"

Student::Student(string firstName, string lastName , int id , float avg)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->id = id;
	this->avg = avg;
	this->room = -1;
}

void Student::printStudentDetails()
{
	cout << this->firstName << " " << this->lastName << " " << this->id << " " << this->avg << " "<< this->room << endl;
	cout << "---" << "Messages" << "---" << endl;
	this->msg.printMsg();
}

void Student::setRoomNumber(int roomNumber)
{
	this->room = roomNumber;
}

string Student::getFullName()
{
	return this->firstName + " " + this->lastName;
}

int Student::getId()
{
	return this->id;
}

int Student::getRoomNumber()
{
	return this->room;
}

Messeges& Student::getMsg()
{
	return this->msg;
}
string Student::getFirstName()
{
	return this->firstName;
}
string Student::getLastName()
{
	return this->lastName;
}

int Student::getAvg()
{
	return this->avg;
}

Student::~Student() {
	this->msg.~Messeges();
}


