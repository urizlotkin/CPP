#include "Student.h"
#include "LazyStudent.h"
#include "DiligentStudent.h"
#include "Room.h"
#include "Messeges.h"
#include "ZoomSys.h"
#include "ZoomSys.h"
#include "Error.h"
int main(int argc, char*argv[]) {
	ZoomSys* zoomSys = new ZoomSys(argv[1]);
	char menuOption='y';
	int id;
	int idR;
	while(menuOption!='0')
	{
		cout<< "1. Add Student" << endl;
		cout<< "2. Remove Student" << endl;
		cout<< "3. Assign Student" << endl;
		cout<< "4. Add Room" << endl;
		cout<< "5. Split Room" << endl;
		cout<< "6. Remove Room" << endl;
		cout<< "7. Work" << endl;
		cout<< "8. Send Message" << endl;
		cout<< "9. Print Rooms" << endl;
		cout<< "p. Print Students" << endl;
		cout<< "d. Print Student details" << endl;
		cout<< "0. Exit" << endl;
		cin >> menuOption;
		switch(menuOption){
			case '1':
			{
				cout << "---Create Student---"<<endl;
				cout<< "First name:"<<endl;
				string firstN = "";
				cin >> firstN;
				cout<< "Last name:"<<endl;
				string lastN = "";
				cin >> lastN;
				cout << "ID:"<<endl;
				cin >> id;
				cout<< "avg:"<<endl;
				float avg;
				cin>>avg;
				cout<< "Worker(W) or Lazy(L) or Responsible(R) Student?"<<endl;
				char type;
				cin >> type;
				try
				{
					zoomSys->addStudent(firstN, lastN, id, avg, type);
				}
				catch(exception& e)
				{
					cout << e.what();
					break;
				}
				catch(int x)
				{
					delete zoomSys;
				}
				break;
			}

			case '2':
			{
				cout << "---Remove Student---"<<endl;
				cout << "Enter the id:"<<endl;
				id=0;
				cin >> id;
				try
				{
					zoomSys->removeStudent(id);
				}
				catch(exception& e)
				{
					cout << e.what();
					break;
				}
				catch(int x)
				{
					delete zoomSys;
				}
				break;
			}


			case '3':
			{
				cout << "---Assign Student---"<<endl;
				cout << "Enter student id:"<<endl;
				cin >> id;
				cout << "Enter room id:"<<endl;
				cin >> idR;
				try
				{
					zoomSys->assignStudent(id, idR);
				}
				catch(exception& e)
				{
					cout << e.what();
					break;
				}
				catch(int x)
				{
					delete zoomSys;
				}
				break;
			}


			case '4':
			{
				try{
				zoomSys->addRoom();
				}
				catch(exception& e)
				{
					cout << e.what();
					break;
				}
				catch(int x)
				{
					delete zoomSys;
				}
				cout<<"New room created"<<endl;
				break;
			}



			case '5':
			{
				cout << "---Split Room---"<<endl;
				cout << "Room id:"<<endl;
				cin >> idR;
				IdException e =IdException();
				SplitBefore e2 =SplitBefore();
				if(zoomSys->searchRoom(idR) == nullptr){
					cout << e.what();
					break;
				}
				if(zoomSys->searchRoom(idR)->isSpiltd())
				{
					cout << e2.what();
					break;
				}
				cout << "1.Character split"<<endl;
				cout << "2.Size split"<< endl;
				int type2;
				cin >> type2;
				try
				{
					zoomSys->splitRoom(idR, type2);
				}
				catch(exception& e)
				{
					cout << e.what();
					break;
				}
				catch(int x)
				{
					delete zoomSys;
				}
				break;
			}



			case '6':
			{
				cout << "---Remove Room---"<<endl;
				cout << "Enter room id:"<<endl;
				cin >> idR;
				try
				{
					zoomSys->removeRoom(idR,0);
				}
				catch(exception& e)
				{
					cout << e.what();
					break;
				}
				catch(int x)
				{
					delete zoomSys;
				}
				break;
			}


			case '7':
			{
				cout << "Enter the room you want to work:"<<endl;
				cin >> idR;
				try
				{
					zoomSys->work(idR);
				}
				catch(exception& e)
				{
					cout << e.what();
					break;
				}
				catch(int x)
				{
					delete zoomSys;
				}
				break;
			}


			case '8':
			{
				cout << "Enter the id:"<<endl;
				cin >> id;
				IdException e =IdException();
				if(zoomSys->isExist(id) == nullptr){
					cout << e.what();
					break;
				}
				cout << "Enter the message:"<<endl;
				string msg;
				cin >> msg;
				try
				{
					zoomSys->sendMessage(id,msg);
				}
				catch(exception& e)
				{
					cout << e.what();
					break;
				}
				catch(int x)
				{
					delete zoomSys;
				}

				break;
			}


			case '9':
			{
				zoomSys->printRooms();
				break;
			}



			case 'p':
			{
				zoomSys->printStudents();
				break;
			}




			case 'd':
			{
				cout << "Enter student id:"<<endl;
				cin >> id;
				try
				{
					zoomSys->printStudentDetails(id);
				}
				catch(exception& e)
				{
					cout << e.what();
					break;
				}
				catch(int x)
				{
					delete zoomSys;
				}
				break;
			}

			case '0':
			{
				cout<<"Bye.."<<endl;
				delete zoomSys;
				break;
			}
		}
	}


	return 0;
}






