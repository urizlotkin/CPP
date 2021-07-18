
#ifndef ZOOMSYS_H_
#define ZOOMSYS_H_
#include "Student.h"
#include "Room.h"
#include "LazyStudent.h"
#include "DiligentStudent.h"
#include "RespansibleStudent.h"
#include "Error.h"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

//#include <boost/algorithm/string>
class ZoomSys {

private:
	vector<Student*> stud;
	vector<Room*> rooms;

	void recDelete(Room * room);




public:
	ZoomSys(char *);
	void addStudent(string firstName, string lastName, int id, float avg, char type);
	void removeStudent(int id);
	void assignStudent(int id, int roomId);
	void addRoom();
	void splitRoom(int roomId, int type);
	void removeRoom(int roomId, int flag);
	void recMove(Room * room, int numOfRoom, Room * Dad, int flag);
	void work(int roomId);
	void sendMessage(int id, string msg);
	void printRooms();
	void printStudents();
	void printStudentDetails(int id);
	Room * searchRoom(int id);
	Student * isExist(int id);

	virtual ~ZoomSys();
};

#endif /* ZOOMSYS_H_ */
