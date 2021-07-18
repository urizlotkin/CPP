
#ifndef MESSEGES_H_
#define MESSEGES_H_
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Messeges {
	vector<string>  msg;
public:
	Messeges();
	void printMsg();
	void addMsg(const string firstNameOfSend ,const string lastNameOfSend, const string msg);
	virtual ~Messeges();
};

#endif /* MESSEGES_H_ */
