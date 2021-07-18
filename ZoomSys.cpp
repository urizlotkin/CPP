
#include "ZoomSys.h"


	vector<string> split(string line)
	{
		string s="";
		vector<string> vec;
		int count = line.length();
		int len = line.length() - count;
		while(count > 0)
		{
			if(line[len] == ' ' || line[len] == '\t'|| line[len] == '\r'|| line[len] == '\n')
			{
				vec.push_back(s);
				s = "";
				count--;
				len++;
			}
			else
			{
				s = s + line[len++];
				count--;
			}

		}
		if(s!= "")
			vec.push_back(s);
		return vec;
	}

	ZoomSys::ZoomSys(char * conFile)
	{
		string line;
		vector<string> result;
		// Read from the text file
		if(conFile == nullptr)
		{
			return;
		}
		ifstream MyReadFile(conFile);

		// Use a while loop together with the getline() function to read the file line by line
		while (getline (MyReadFile, line))
		{
		   result = split(line);
		   int id = stoi(result[2]);
		   float avg =stof(result[3]);
		   char c = result[4][0];
		   ZoomSys::addStudent(result[0], result[1], id, avg, c);
		}

		// Close the file
		MyReadFile.close();
		result.clear();
	}

	void ZoomSys::addStudent(string firstName, string lastName, int id, float avg, char type)
	{
		if(ZoomSys::isExist(id) != nullptr)
		{
			throw InvalidDetails();
		}
		if(avg > 100 || avg < 0)
		{
			throw InvalidDetails();
		}
		if(type != 'R' && type != 'W' && type != 'L')
		{
			throw InvalidDetails();
		}
		Student * s;
		if(type == 'W'){
			s = new DiligentStudent(firstName, lastName, id, avg);
			if(s == nullptr)
				throw 1;
		}
		else if(type == 'L'){
			s = new LazyStudent(firstName, lastName, id, avg);
			if(s == nullptr)
				throw 1;
		}
		else{
			s = new RespansibleStudent(firstName, lastName, id, avg);
			if(s == nullptr)
				throw 1;
		}
		this->stud.push_back(s);
	}

	void ZoomSys::removeStudent(int id)
	{
		Student * s =nullptr;
		if(ZoomSys::isExist(id) == nullptr)
			{
				throw IdException();
			}
		int romNum;
		int j = 0;
		for(j = 0; j < ((int)this->stud.size()); j++)
			{
			if(this->stud[j]->getId() == id)
			{
				s = (*(this->stud.begin()+j));
				romNum = this->stud[j]->getRoomNumber();
				this->stud.erase(this->stud.begin() + j);
				//delete(s);
			}
			}
		if(romNum == -1 || this->rooms.size() == 0)
		{
			delete(s);
			return;
		}
		int i = 0;
		for(i = 0; i < ((int)this->rooms.size()); i++)
		{
			if(this->rooms[i]->deleteStudent(id))
			{
				break;
			}
		}
		delete(s);
		s= nullptr;
	}


	void ZoomSys::assignStudent(int id, int roomId)
	{
		if((ZoomSys::isExist(id) == nullptr))
		{
			throw IdException();
		}
		Student * s = ZoomSys::isExist(id);
		if(roomId == -1)
		{
			if(s->getRoomNumber() == -1)
				return;
			int rId = s->getRoomNumber();
			Room * r = ZoomSys::searchRoom(rId);
			int j =0;
			for(j=0 ; j< r->getAmount();j++)
			{
				if(r->getStud()[j]->getId() == id)
				{
					r->getStud().erase(r->getStud().begin() + j);
					break;
				}
			}
			s->setRoomNumber(-1);
		}
		if(s->getRoomNumber() == roomId)
			return;
		int j = 0;
		int flag = 0;
		for(j = 0; j < ((int)this->rooms.size());j++)
		{
			if(roomId == this->rooms[j]->getId())
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			throw IdException();
		}
		int rId = s->getRoomNumber();
		if(rId != -1)
		{
			Room * r = ZoomSys::searchRoom(rId);
			int j2 =0;
			for(j2=0 ; j< r->getAmount();j2++)
			{
				if(r->getStud()[j2]->getId() == id)
				{
					r->getStud().erase(r->getStud().begin() + j2);
					break;
				}
			}
		}
		Room& room = *(this->rooms[j]);

		for(j = 0; j < ((int)this->stud.size()); j++)
		{
			if(this->stud[j]->getId() == id)
			{
				room.addStudent(*(this->stud[j]));
				break;
			}
		}
	}




	void ZoomSys::addRoom()
	{
		Room * room = new Room();
		if(room == nullptr)
			throw 1;
		this->rooms.push_back(room);
		room = nullptr;
	}

	void ZoomSys::splitRoom(int roomId, int type)
	{
		int j = 0;
		int flag = 0;
		for(j = 0; j < ((int)this->rooms.size());j++)
		{
			if(roomId == this->rooms[j]->getId())
			{
				flag = 1;
				this->rooms[j]->splitRoom(type);
				this->rooms.push_back(this->rooms[j]->getLeft());
				this->rooms.push_back(this->rooms[j]->getRight());
				break;
			}
		}
		if(flag == 0)
		{
			throw IdException();
		}
	}

	void ZoomSys::recMove(Room * room, int numOfRoom, Room * Dad, int flag)
	{
		if(room == nullptr)
			return;
		else
		{
			vector<Student*>& vec= room->getStud();
			if(room->getLeft()!= nullptr)
			{
				recMove(room->getLeft(), numOfRoom, room,flag);
				room->setLeft(nullptr);
			}

			if(room->getRight() != nullptr)
			{
				recMove(room->getRight(), numOfRoom, room,flag);
				room->setRight(nullptr);
			}
			if(room->getRight() == nullptr && room->getLeft() == nullptr)
			{
				if(Dad != nullptr)
				{
					auto i = vec.begin();
					while(i != vec.end())
					{

						if((((Student*)(*i)))->isLazy() && flag == 0)
							cout << (((Student*)(*i)))->getFullName() << " is crying" << endl;
						Dad->addStudent(*((Student *)(*i)));
						vec.erase(i);
					}
					int j =0;
					for(j=0;j<((int)this->rooms.size());j++)
					{
						if(this->rooms[j]->getId() == room->getId())
						{
							this->rooms.erase(this->rooms.begin() + j);
							break;
						}
					}
					delete(room);
					return;
				}
				else
				{
					auto i = vec.begin();
					while(i != vec.end())
					{
						if((((Student*)(*i)))->isLazy() && flag == 0)
							cout << (((Student*)(*i)))->getFullName() << " is crying" << endl;
						(((Student*)(*i)))->setRoomNumber(-1);
						vec.erase(vec.begin());
						i = vec.begin();
					}
					int j =0;
					for(j=0;j<((int)this->rooms.size());j++)
					{
						if(this->rooms[j]->getId() == room->getId())
						{
							this->rooms.erase(this->rooms.begin() + j);
							break;
						}
					}
					delete(room);
					return;
				}
			}
		}
	}

	void ZoomSys::removeRoom(int roomId , int flag)
	{

		int i = 0;
		Room * room = nullptr;
		if(this->rooms.size() == 0)
			return;
		for(i=0;i<((int)this->rooms.size());i++)
		{
			if(this->rooms[i]->getId() == roomId)
			{
				room = this->rooms[i];
				break;
			}
		}
		if(room == nullptr)
			return;
		Room * Dad = room->getDad();
		if(Dad != nullptr)
		{
			if(Dad->getLeft() == room)
				Dad->setLeft(nullptr);
			if(Dad->getRight() == room)
				Dad->setRight(nullptr);
		}
		if(Dad == nullptr)
		{
			recMove(room->getLeft(), -1, room,flag);
			room->setLeft(nullptr);
			recMove(room->getRight(), -1, room,flag);
			room->setRight(nullptr);
			recMove(room,-1,Dad,flag);
		}
		else
		{
			recMove(room->getLeft(), room->getId(), room,flag);
			room->setLeft(nullptr);
			recMove(room->getRight(), room->getId(), room,flag);
			room->setRight(nullptr);
			recMove(room,room->getDad()->getId(),Dad,flag);
		}
	}
	void ZoomSys::work(int roomId)
	{
		Room * room = this->searchRoom(roomId);
		if(room == nullptr)
			throw IdException();
		int i =0;
		for(i=0;i<((int)room->getStud().size());i++)
		{
			if(room->getStud()[i]->isDiligent())
				cout << room->getStud()[i]->getFullName()<< " is working" << endl;
		}
	}
	void ZoomSys::sendMessage(int id, string msg)
	{
		Student * st = ZoomSys::isExist(id);
		if(st == nullptr)
			throw IdException();
		if(!(st->isResponsible()))
			throw StudentPermissions();
		if(st->getRoomNumber() == -1)
			return;
		Room * room = ZoomSys::searchRoom(st->getRoomNumber());
		vector<Student *>& vec = room->getStud();
		int i = 0;
		for(i=0;i<((int)vec.size());i++)
		{
			vec[i]->getMsg().addMsg(st->getFirstName(), st->getLastName(), msg);
		}
	}
	void ZoomSys::printRooms()
	{
		int i=0;
		for(i=0;i<((int)this->rooms.size());i++)
		{
			cout << "room id:" << this->rooms[i]->getId() << ", " << "students:" << this->rooms[i]->getStud().size() << endl;
		}
	}
	void ZoomSys::printStudents()
	{
		cout << "First name, Last Name, ID, Avg, Room ID" << endl;
		int i =0;
		for(i=0;i<((int)this->stud.size());i++)
		{
			cout << this->stud[i]->getFullName() << " "<< this->stud[i]->getId()<<" "<<this->stud[i]->getAvg()<<" "<< this->stud[i]->getRoomNumber()<<endl;
		}
	}
	void ZoomSys::printStudentDetails(int id)
	{
		Student * st = ZoomSys::isExist(id);
		if(st == nullptr)
			throw IdException();
		st->printStudentDetails();
	}
	ZoomSys::~ZoomSys()
	{
		int i =0;
		while(this->rooms.size()> 0)
		{
			ZoomSys::removeRoom(this->rooms[0]->getId(),1);
		}
		for(i=0;i<((int)this->stud.size());i++)
		{
			delete(this->stud[i]);
		}
		i =0;
		this->stud.clear();
		this->rooms.clear();
	}

	Student * ZoomSys::isExist(int id)
	{
		int i;
		for(i = 0; i < ((int)this->stud.size()); i++)
		{
			if(this->stud[i]->getId() == id)
				return this->stud[i];
		}
		return nullptr;
	}
	Room * ZoomSys::searchRoom(int id)
	{
		int i = 0;
		for(i=0;i<((int)this->rooms.size());i++)
		{
			if(this->rooms[i]->getId() == id)
			{
				return this->rooms[i];
			}
		}
		return nullptr;
	}







