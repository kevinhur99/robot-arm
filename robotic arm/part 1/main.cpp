#include "RoboticArm.h"
#include <unistd.h>
#include <iostream>

using namespace std;

int main()
{
	// Create the class for the robotic_arm
	RoboticArm robotic_arm;

	// Moving the base to the neutral position
	robotic_arm.MoveServo(0, 90, 50);

	// Moving the bicep so that it will bend down
	robotic_arm.MoveServo(1, 20, 20);

	// Moving the elbow so that it will bend down
	robotic_arm.MoveServo(2, 45, 20);

	// Opening up the Gripper
	robotic_arm.MoveServo(4, 180, 100);

	// Wait for 8 seconds
	sleep(8);

	// Close the gripper
	robotic_arm.MoveServo(4, 0, 75);

	// Wait for 3 seconds
	sleep(3);

	// Move the bicep to the opposite direction very fast, as well as the elbow
	robotic_arm.MoveServo(1, 110, 50000000);
	robotic_arm.MoveServo(2, 90, 50000000);

	// Open the gripper
	robotic_arm.MoveServo(4, 90, 77);
}
