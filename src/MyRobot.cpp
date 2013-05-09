#include "MyRobot.h"
#include <math.h>
#include <stdio.h>

float pi3 = acos(-1.0);
float deg2rad3 = pi3 / 180.0;

void MyRobot::draw() {

	glPushMatrix();
	glNormal3f(0, 1, 0);
	glTranslated(translate_x, 0, translate_z);
	glRotated(rotacao, 0, 1, 0);
	robot->draw();
	glPopMatrix();
}

void MyRobot::moveLeft() {

	rotacao += 2;
	if (rotacao >= 360)
		rotacao = rotacao - 360;
	draw();

}

void MyRobot::moveRight() {
	rotacao -= 2;
	if (rotacao <= 0)
		rotacao += 360;
	draw();
}

void MyRobot::moveForward() {

	translate_x += 0.2 * sin(rotacao * deg2rad3);
	translate_z += 0.2 * cos(rotacao * deg2rad3);
	draw();
}

void MyRobot::moveBackward() {

	translate_x -= 0.2 * sin(rotacao * deg2rad3);
	translate_z -= 0.2 * cos(rotacao * deg2rad3);
	draw();
}
