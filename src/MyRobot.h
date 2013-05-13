#ifndef ROBOT_H
#define ROBOT_H

#include "CGFobject.h"
#include "MyRobotDraw.h"

class MyRobot{
	int rotacao;
	double translate_x;
	double translate_z;
	MyRobotDraw* robot;
public:
	MyRobot(){rotacao = 200;translate_x=8.0;translate_z = 8.0;robot = new MyRobotDraw(6);};
	MyRobot(int stacks) {rotacao = 200;translate_x=8.0;translate_z = 8.0;robot = new MyRobotDraw(stacks);};
	void draw();
	void moveLeft();
	void moveRight();
	void moveForward();
	void moveBackward();
};
#endif
