#include "RoboticArm.h"
#include "WiimoteAccel.h"
#include "WiimoteBtns.h"
#include <unistd.h>
#include <iostream>

using namespace std;

// a subclass for WiimoteBtns
class WiimoteButtonRobot : public WiimoteBtns
{

	// A private class that has fields
private:
	// The robotic arm pointer
	RoboticArm *robotic_arm;

	// The angle of the wrist
	int wristAngle;

	// The angle of the elbow
	int elbowAngle;

public:
	// The constructor for the subclass
	WiimoteButtonRobot(RoboticArm *arm)
	{
		// The arm fields will be the arm, and the default angle for wrist and elbow is 90
		robotic_arm = arm;
		wristAngle = 90;
		elbowAngle = 90;
	}

	// ButtonEvent override
	void ButtonEvent(int code, int value)
	{
		// If the 1 button is pushed, it will close the clamps
		if (code == 1 && value == 1)
		{
			robotic_arm->MoveServo(4, 0, 1000);
		}

		// If the 2 button is pushed, it will open the clamps
		if (code == 2 && value == 1)
		{
			robotic_arm->MoveServo(4, 180, 1000);
		}

		// If the home button is pushed, the robot will wait for 2 seconds
		if (code == 60 && value == 1)
		{
			sleep(2);
		}

		// If the A button is pushed, it will increase the angle of the wrist by 5 degrees
		if (code == 48 && value == 1)
		{
			// If the max angle is reached, it will do nothing
			if (wristAngle <= 175)
			{
				wristAngle += 5;
			}
			// Update the servo for the robotic arm
			robotic_arm->MoveServo(3, wristAngle, 1000);
		}

		// If the B button is pushed, it will decrease the angle of the wrist by 5 degrees
		if (code == 49 && value == 1)
		{
			// If the min angle is reached, it will do nothing
			if (wristAngle >= 5)
			{
				wristAngle -= 5;
			}
			// Update the servo for the robotic arm
			robotic_arm->MoveServo(3, wristAngle, 1000);
		}

		// If the + button is pushed, it will increase the angle of the elbow by 5 degrees
		if (code == 151 && value == 1)
		{
			// If the max angle is reached, it will do nothing
			if (elbowAngle <= 175)
			{
				elbowAngle += 5;
			}
			// Update the servo for the robotic arm
			robotic_arm->MoveServo(2, elbowAngle, 1000);
		}

		// If the - button is pushed, it will decrease the angle of the elbow by 5 degrees
		if (code == 156 && value == 1)
		{
			// If the min angle is reached, it will do nothing
			if (elbowAngle >= 5)
			{
				elbowAngle -= 5;
			}
			// Update the servo for the robotic arm
			robotic_arm->MoveServo(2, elbowAngle, 1000);
		}
	}
};

// A subclass for the WiimoteAccel class
class WiimoteAccelRobot : public WiimoteAccel
{
	// A private class for the field for the robot pointer
private:
	RoboticArm *robotic_arm;

public:
	// The constructor for the class
	WiimoteAccelRobot(RoboticArm *arm)
	{
		robotic_arm = arm;
	}

	// Overriding the AccelerationEvent
	void AccelerationEvent(int code, int acceleration)
	{
		// When the Wiimote is turned left and right and have the proper acceleration
		if (code == 3 && acceleration < 100 && acceleration > -100)
		{
			// There is a for loop that repeats 8 times
			for (int i = 0; i < 8; i++)
			{
				// It will find the interval of the acceleration
				if ((acceleration > (i * 25) - 100) && (acceleration < (i + 1) * 25) - 100)
				{
					// If it finds the interval, the base will move based on that acceleration interval
					robotic_arm->MoveServo(0, (180.0 / 7.0) * i, 50);
				}
			}
		}

		// When the Wiimote is turned up and down and have the proper acceleration
		if (code == 4 && acceleration < 100 && acceleration > -100)
		{
			// There is a for loop that repeats 8 times
			for (int i = 0; i < 8; i++)
			{
				// It will find the interval of the acceleration
				if ((acceleration > (i * 25) - 100) && (acceleration < (i + 1) * 25) - 100)
				{
					// If it finds the interval, the bicep will move based on that acceleration interval
					robotic_arm->MoveServo(1, (180.0 / 7.0) * i, 50);
				}
			}
		}
	}
};

int main()
{
	// The classes will be made
	RoboticArm robotic_arm;
	WiimoteButtonRobot Wb(&robotic_arm);
	WiimoteAccelRobot Wa(&robotic_arm);

	// An infinite while loop
	while (true)
	{
		// It will call the listen function on the subclasses. The Listen function is no longer a while loop itself
		Wa.Listen();
		Wb.Listen();
	}

	return 0;
}
