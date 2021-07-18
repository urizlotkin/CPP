
#include "DiligentStudent.h"








DiligentStudent::DiligentStudent(const string firstName, const string lastName , const int id , const float avg): Student(firstName, lastName, id, avg){};

DiligentStudent::~DiligentStudent() {
	this->msg.~Messeges();
}

