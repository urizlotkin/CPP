/*
 * Messeges.cpp
 *
 *  Created on: Dec 29, 2020
 *      Author: ise
 */

#include "Messeges.h"

Messeges::Messeges() {}
void Messeges::printMsg()
{
	for( auto i = this->msg.begin(); i != this->msg.end() ; i++)
	{
		cout << *i << endl;
	}
}
void Messeges::addMsg(string firstNameOfSend ,string lastNameOfSend, string msg) // firstname last name:message

{
	string s = firstNameOfSend +" " + lastNameOfSend + ":" + msg;
	this->msg.push_back(s);
}

Messeges::~Messeges() {
	this->msg.clear();
}

