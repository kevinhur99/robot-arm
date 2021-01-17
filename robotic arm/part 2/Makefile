RoboticArm: RoboticArm.o WiimoteBtns.o WiimoteAccel.o main.o
	g++ RoboticArm.o WiimoteBtns.o WiimoteAccel.o  main.o -o RoboticArm

RoboticArm.o: RoboticArm.h RoboticArm.cpp
	g++ -c RoboticArm.cpp

WiimoteAccel.o: WiimoteAccel.h WiimoteAccel.cpp
	g++ -c WiimoteAccel.cpp

WiimoteBtns.o: WiimoteBtns.h WiimoteBtns.cpp
	g++ -c WiimoteBtns.cpp

main.o: RoboticArm.h WiimoteAccel.h WiimoteBtns.h main.cpp
	g++ -c main.cpp

clean:
	rm RoboticArm RoboticArm.o WiimoteBtns.o WiimoteAccel.o main.o 
