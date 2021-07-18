
#ifndef STUDENT_H_
#define STUDENT_H_
#include <cstring>
#include <string>
#include <iostream>
#include "Messeges.h"
using namespace std;

class Student {
protected:
	string firstName;
	string lastName;
	int id;
	float avg;
	Messeges msg;
	int room;

public:
	Student(const string firstName, const string lastName , const int id , const float avg);
	void printStudentDetails();
	int getId();
	virtual bool isLazy()const = 0;
	virtual bool isDiligent()const = 0;
	virtual bool isResponsible()const = 0;
	void setRoomNumber(int roomNumber);
	string getFullName();
	string getFirstName();
	string getLastName();
	int getRoomNumber();
	Messeges& getMsg();
	int getAvg();
	virtual ~Student();
};

#endif /* STUDENT_H_ */
