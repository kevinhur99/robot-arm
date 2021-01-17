RoboticArm: RoboticArm.o main.o
	g++ RoboticArm.o main.o -o RoboticArm

RoboticArm.o: RoboticArm.h RoboticArm.cpp
	g++ -c RoboticArm.cpp

main.o: RoboticArm.h main.cpp
	g++ -c main.cpp

clean:
	rm RoboticArm RoboticArm.o main.o
