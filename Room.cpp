
#include "Room.h"
int Room::num_of_rooms = 0;
Room::Room() {
	this->id = Room::num_of_rooms;
	Room::num_of_rooms++;
}
void Room::addStudent(Student& std)
{
	this->stud.push_back(&(std));
	std.setRoomNumber(this->id);

}
bool Room::deleteStudent(int id)
{
	int index = 0;
	int counter = 0;
	for( auto i = this->stud.begin() ; i != this->stud.end() ; i++)
	{
		if(	((Student*)*i)->getId() == id)
		{
			Student * s = ((Student*)(*i));
			s->setRoomNumber(-1);
			index = counter;
			this->stud.erase(this->stud.begin() + index);
			return true;
		}
		counter++;
	}
	return false;
}

void Room::printRoom()
{
	cout <<"room id:" << this->id <<", " << "students:" << this->stud.size() << endl;
}

void Room::splitRoom(int type)
{
	if(this->isSpillted)
	{
		throw SplitBefore();
	}

	if(type != 1 && type != 2)
	{
		throw InvalidDetails();
	}
	if(type == 2)
	{
		Room * left, * right;
		left = new Room();
		if(left == nullptr)
			throw 1;
		right = new Room();
		if(right == nullptr)
			throw 1;
		left->Dad = this;
		right->Dad = this;

		int counter = 0;
		int numberofstudentinA = int(this->stud.size() / 2);
		for( auto i = this->stud.begin() ; i != this->stud.end() ; i++)
		{
			if(counter < numberofstudentinA){
				Student& s = *(*i);
				left->addStudent(s);
			}
			else{
				Student& s = *(*i);
				right->addStudent(s);
			}
			counter++;
		}
		this->LeftSplit = left;
		this->RightSplit = right;
		this->isSpillted = true;
		this->stud.clear();
	}
	else
	{
		Room * left, * right;

		left = new Room();
		if(left == nullptr)
			throw 1;
		right = new Room();
		if(right == nullptr)
			throw 1;
		left->Dad = this;
		right->Dad = this;
		auto i = this->stud.begin();
		while( i != this->stud.end())
		{
			if (((Student*)(*i))->isLazy())
			{
				Student& s = *(*i);
				right->addStudent(s);
				this->stud.erase(i);
				i = this->stud.begin();
				continue;
			}
			if (((Student*)(*i))->isDiligent())
			{
				Student& s = *(*i);
				left->addStudent(s);
				this->stud.erase(i);
				i = this->stud.begin();
				continue;
			}
			i++;
		}
		this->LeftSplit = left;
		this->RightSplit = right;
		this->isSpillted = true;
	}
}




void Room::recMove(Room * room, int numOfRoom, Room * Dad)
{
	if(room == nullptr)
		return;
	else
	{
		if(room->LeftSplit != nullptr)
		{
			recMove(room->LeftSplit, numOfRoom, Dad);
			room->LeftSplit = nullptr;
		}

		if(room->RightSplit != nullptr)
		{
			recMove(room->RightSplit, numOfRoom, Dad);
			room->RightSplit = nullptr;
		}
		if(room->RightSplit == nullptr && room->LeftSplit == nullptr)
		{
			if(Dad != nullptr)
			{
				for(auto i = room->stud.begin() ; i != room->stud.end() ; i++)
				{
					if((((Student*)(*i)))->isLazy())
						cout << (*((Student*)&(*i))).getFullName() << " is crying" << endl;
					Dad->addStudent(*((Student *)(*i)));
					room->stud.erase(room->stud.begin());
				}
				delete(room);
				return;
			}
			else
			{
				auto i = room->stud.begin();
				while(i != room->stud.end())
				{
					if((((Student*)(*i)))->isLazy())
						cout << (((Student*)(*i)))->getFullName() << " is crying" << endl;
					(((Student*)(*i)))->setRoomNumber(-1);
					room->stud.erase(room->stud.begin());
					i = room->stud.begin();
				}
				delete(room);
				return;
			}
		}
	}
}

void Room::deleteRoom()
{
	Room * Dad = this->Dad;
	if(Dad != nullptr)
	{
		if(Dad->getLeft() == this)
			Dad->setLeft(nullptr);
		if(Dad->getRight() == this)
			Dad->setRight(nullptr);
	}
	if(Dad == nullptr)
	{
		recMove(this->LeftSplit, -1, Dad);
		this->LeftSplit = nullptr;
		recMove(this->RightSplit, -1, Dad);
		this->RightSplit = nullptr;
		recMove(this,-1,Dad);
	}
	else
	{
		recMove(this->LeftSplit, this->Dad->id, Dad);
		this->LeftSplit = nullptr;
		recMove(this->RightSplit, this->Dad->id, Dad);
		this->RightSplit = nullptr;
		recMove(this,this->Dad->id,Dad);
	}
}

vector<Student*>& Room::getStud()
	{
		return this->stud;
	}
int Room::getId()
{
	return this->id;
}

Room * Room::getLeft()
{
	return this->LeftSplit;
}
Room * Room::getRight()
{
	return this->RightSplit;
}

void Room::setLeft(Room * room)
{
	this->LeftSplit = room;
}
void Room::setRight(Room * room)
{
	this->RightSplit = room;
}
Room * Room::getDad()
{
	return this->Dad;
}

bool Room::isSpiltd()
{
	return this->isSpillted;
}

int Room::getAmount()
{
	return ((int)this->stud.size());
}

Room::~Room()
{
	this->stud.clear();
}







