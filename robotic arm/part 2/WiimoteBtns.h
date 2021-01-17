/* Walter Reuss & Kevin Hur Lab 4*/
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#ifndef WIIMOTEBTNS_H
#define WIIMOTEBTNS_H

//Class for wiimotebtns
class WiimoteBtns {
private:	
	//private integer for map storage
	int fd;
public:
	//declare helper functions
	WiimoteBtns();
	~WiimoteBtns();
	void Listen();
	virtual void ButtonEvent(int code, int value) = 0;
};

#endif
