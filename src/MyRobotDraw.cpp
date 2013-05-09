/*
 * MyRobotDraw.cpp
 *
 *  Created on: May 7, 2013
 *      Author: wso277
 */

#include <math.h>
#include <stdio.h>
#include "MyRobotDraw.h"

MyRobotDraw::MyRobotDraw(int stacks) {

	slices = 12;
	this->stacks = stacks;
	getNormal();

}

void MyRobotDraw::getNormal() {

	float altura = 1.0 / stacks;
	float delta = 1.0 / 3.0;
	float deltax = 0.5 / stacks;

	x = 0;
	y =  (0 - (-deltax * delta));
	z = (altura * delta);

	printf("x=%f\n y=%f\n z=%f", x,y,z);


}

void MyRobotDraw::draw() {

	float altura = 1.0 / stacks;
	float altura1 = 1.0 / stacks;
	float c = 1.0;
	float delta = c / 3.0;
	float deltax = 0.5 / stacks;
	float initx = -0.5;
	float initz = 0.5;
	int mov = 0;

	for (float j = 0; j < 1;) {
	glBegin(GL_TRIANGLE_STRIP);

	glNormal3f(x, y, z);

	glVertex3f(initx+deltax, altura, initz-deltax);
	glVertex3f(initx, altura-altura1, initz);

	for (int i = 1; i <= slices; i++) {

		switch (mov) {
		case 0:
			glNormal3f(x, y, z);
			initx+=delta;
			if (initx<=0)
				glVertex3f(initx+deltax, altura,initz-deltax);
			else
				glVertex3f(initx-deltax, altura,initz-deltax);

			glVertex3f(initx, altura - altura1,initz);
			break;

		case 1:
			glNormal3f(z, y, x);
			initz-=delta;
			if (initz<=0)
				glVertex3f(initx-deltax, altura,initz+deltax);
			else
				glVertex3f(initx-deltax, altura,initz-deltax);

			glVertex3f(initx, altura - altura1,initz);
			break;

		case 2:
			glNormal3f(x, y, -z);
			initx-=delta;
			if (initx<=0)
				glVertex3f(initx+deltax, altura,initz+deltax);
			else
				glVertex3f(initx-deltax, altura,initz+deltax);

			glVertex3f(initx, altura - altura1,initz);
			break;

		case 3:
			glNormal3f(-z, y, x);
			initz+=delta;
			if (initz<=0)
				glVertex3f(initx+deltax, altura,initz+deltax);
			else
				glVertex3f(initx+deltax, altura,initz-deltax);

			glVertex3f(initx, altura - altura1,initz);
			break;
		}

		if (i == 3)
			mov = 1;
		if (i == 6)
			mov = 2;
		if (i == 9)
			mov = 3;
	}

	glEnd();

	mov = 0;
	initx += deltax;
	initz -= deltax;
	j+=altura1;
	altura+=altura1;
	c -= deltax*2;
	delta = c / 3.0;

	}
}
