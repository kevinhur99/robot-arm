#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#ifndef WIIMOTEACCEL_H
#define WIIMOTEACCEL_H

//initialize class
class WiimoteAccel {
private:	
	int fd;
public:
	//declare functions
	WiimoteAccel();
	~WiimoteAccel();
	void Listen();
	//virtual function must be redefined in child class
	virtual void AccelerationEvent(int code, int acceleration);
};
#endif
