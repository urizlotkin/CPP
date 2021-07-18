
#include "LazyStudent.h"



LazyStudent::LazyStudent(const string firstName, const string lastName , const int id , const float avg): Student(firstName, lastName, id, avg){};


LazyStudent::~LazyStudent() {
	this->msg.~Messeges();
}


