#   description: This is the makefile used to compile determinant.cpp,
#   readMatrix,cpp, main.cpp (and corresponding header files) into the 
#    executable file 'lab1' and runs valgrind.  The clean target 
#   removes all object files as well as the executable.  
#    *********************************************************************/

langtonAnt: main.o ant.o board.o iVal.o menu.o
	g++ main.o ant.o board.o iVal.o menu.o  -o langtonAnt
	valgrind langtonAnt

main.o: main.cpp
	g++ -c main.cpp

ant.o: ant.cpp ant.hpp
	g++ -c ant.cpp

board.o: board.cpp board.hpp
	g++ -c board.cpp

iVal.o: iVal.cpp iVal.hpp
	g++ -std=c++11 iVal.cpp -c

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp


clean:
	rm *.o langtonAnt


