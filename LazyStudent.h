
#ifndef LAZYSTUDENT_H_
#define LAZYSTUDENT_H_
#include "Student.h"

class LazyStudent: public Student
{
public:
	LazyStudent(const string firstName, const string lastName , const int id , const float avg);
	virtual bool isLazy()const {return true;}
	virtual bool isDiligent()const {return false;}
	virtual bool isResponsible()const{return false;}
	virtual ~LazyStudent();
};

#endif /* LAZYSTUDENT_H_ */
