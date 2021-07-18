output: main.o Room.o Student.o ZoomSys.o Messeges.o LazyStudent.o RespansibleStudent.o DiligentStudent.o
	g++ main.o Room.o Student.o ZoomSys.o Messeges.o LazyStudent.o RespansibleStudent.o DiligentStudent.o -o output

DiligentStudent.o: DiligentStudent.cpp DiligentStudent.h Student.h Messeges.h 
	g++ -c DiligentStudent.cpp
 	
LazyStudent.o: LazyStudent.cpp LazyStudent.h Student.h Messeges.h 
	g++ -c LazyStudent.cpp
	
main.o: main.cpp Student.h Messeges.h LazyStudent.h DiligentStudent.h Room.h Error.h ZoomSys.h RespansibleStudent.h 
	g++ -c main.cpp
	
Messeges.o: Messeges.cpp Messeges.h
	g++ -c Messeges.cpp
	
RespansibleStudent.o: RespansibleStudent.cpp RespansibleStudent.h Student.h Messeges.h 
	g++ -c RespansibleStudent.cpp
	
Room.o: Room.cpp Room.h Messeges.h Student.h Error.h 
	g++ -c Room.cpp
	
Student.o: Student.cpp Student.h Messeges.h 
	g++ -c Student.cpp
	
ZoomSys.o: ZoomSys.cpp ZoomSys.h Student.h Messeges.h Room.h Error.h LazyStudent.h DiligentStudent.h RespansibleStudent.h 
	g++ -c ZoomSys.cpp
	
clean:
	rm -f *.o

