#include "WiimoteAccel.h"
#include <iostream>

//initialze constructor
WiimoteAccel::WiimoteAccel()
{
	//initialize storage variable for map
	fd = open("/dev/input/event0", O_RDONLY);
	//make sure map opens properly
	if (fd == -1)
	{
		std::cerr << "Error: Could not open event file - forgot sudo?\n";
		exit(1);
	}
}

//deconstructor closes file
WiimoteAccel::~WiimoteAccel()
{
	close(fd);
}

//listen fuction reads values from wiimote and calls accelevent fn
void WiimoteAccel::Listen()
{
	//while (true) {
	// Read a packet of 16 bytes from Wiimote
	char buffer[16];
	read(fd, buffer, 16);

	// Extract code (byte 10) and value (byte 12) from packet
	int code = buffer[10];
	short acceleration = *(short *)(buffer + 12);

	//call function
	AccelerationEvent(code, acceleration);
	//}
}

//accelerationevent function initialization
void WiimoteAccel::AccelerationEvent(int code, int acceleration)
{
	// Print them
	std::cout << "Code = " << code << ", acceleration = " << acceleration << '\n';
}
