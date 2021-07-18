#ifndef ERROR_H_
#define ERROR_H_
#include <exception>
#include <iostream>
using namespace std;

class IdException: public exception
{
public:
	virtual const char * what() const throw(){
		return "id doesn't exists\n";
	}
};

class StudentPermissions: public exception
{
public:
	virtual const char * what() const throw(){
		return "this student don't have permission\n";
	}
};

class SplitBefore: public exception
{
public:
	virtual const char * what() const throw(){
		return "This room was split before\n";
	}
};

class InvalidDetails: public exception
{
public:
	virtual const char * what() const throw(){
		return "Please enter valid details\n";
	}
};






















#endif
