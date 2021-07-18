

#ifndef RESPANSIBLESTUDENT_H_
#define RESPANSIBLESTUDENT_H_
#include "Student.h"

class RespansibleStudent: public Student
{
public:
	RespansibleStudent(const string firstName, const string lastName , const int id , const float avg);
	virtual bool isLazy()const {return false;}
	virtual bool isDiligent()const {return false;}
	virtual bool isResponsible()const{return true;}
	virtual ~RespansibleStudent();
};

#endif /* RESPANSIBLESTUDENT_H_ */
