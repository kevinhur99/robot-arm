/* Walter Reuss & Kevin Hur Lab 4*/
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "WiimoteBtns.h"
using namespace std;

//constructor for WiimoteBtns
WiimoteBtns::WiimoteBtns()
{
	//initiates variable to store map
	fd = open("/dev/input/event2", O_RDONLY | O_NONBLOCK);
	//make sure map location works
	if (fd == -1)
	{
		//print error and exit if map fails
		cerr << "Error could not open event file- forgot sudo?\n";
		exit(1);
	}
}

//wiimotebtns deconstructor closes file
WiimoteBtns::~WiimoteBtns()
{
	close(fd);
}

//Function that listens for button inputs on the wiimote
void WiimoteBtns::Listen()
{
	//while (true) {
	// Read a packet of 32 bytes from Wiimote
	char buffer[32];
	read(fd, buffer, 32);

	// Extract code (byte 10) and value (byte 12) from packet
	int code = buffer[10];
	int value = buffer[12];

	//call function to print values read
	ButtonEvent(code, value);
	//}
}

//prints code and value integers passed
void WiimoteBtns::ButtonEvent(int code, int value)
{
	cout << "Code = " << code << ", value = " << value << '\n';
}
