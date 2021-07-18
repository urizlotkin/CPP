
#ifndef ROOM_H_
#define ROOM_H_
#include <cstring>
#include <string>
#include <iostream>
#include "Messeges.h"
#include "Student.h"
#include <vector>
#include "Error.h"
using namespace std;



class Room {

protected:
	int id;
	vector<Student*> stud;
	static int num_of_rooms;
	Room * Dad = nullptr;
	Room * LeftSplit = nullptr;
	Room * RightSplit = nullptr;
	bool isSpillted = false;

public:
	Room();
	Room(string type);
	void addStudent(Student& std);
	bool deleteStudent(const int id);
	void deleteRoom();
	void recMove(Room * room, int numOfRoom, Room * Dad);
	void splitRoom(const int type);
	vector<Student*>& getStud();
	void printRoom();
	int getId();
	void setLeft(Room *);
	void setRight(Room *);
	Room * getDad();
	Room * getLeft();
	Room * getRight();
	bool isSpiltd();
	int getAmount();



	virtual ~Room();
};

#endif /* ROOM_H_ */
