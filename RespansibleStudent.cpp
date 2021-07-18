/*
 * RespansibleStudent.cpp
 *
 *  Created on: Dec 29, 2020
 *      Author: ise
 */

#include "RespansibleStudent.h"

RespansibleStudent::RespansibleStudent(const string firstName, const string lastName , const int id , const float avg): Student(firstName, lastName, id, avg){};

RespansibleStudent::~RespansibleStudent() {
	this->msg.~Messeges();
}

