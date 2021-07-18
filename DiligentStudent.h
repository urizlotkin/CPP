
#ifndef DILIGENTSTUDENT_H_
#define DILIGENTSTUDENT_H_
#include "Student.h"


class DiligentStudent: public Student
{
public:
	DiligentStudent(const string firstName, const string lastName , const int id , const float avg);
	virtual bool isLazy()const {return false;}
	virtual bool isDiligent()const {return true;}
	virtual bool isResponsible()const{return false;}
	virtual ~DiligentStudent();
};

#endif /* DILIGENTSTUDENT_H_ */
