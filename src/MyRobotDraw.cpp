/*
 * MyRobotDraw.cpp
 *
 *  Created on: May 7, 2013
 *      Author: wso277
 */

#include <math.h>
#include <stdio.h>
#include "MyRobotDraw.h"

using namespace std;

float pi4 = acos(-1.0);
float deg2rad4 = pi4 / 180.0;

MyRobotDraw::MyRobotDraw(int stacks) {

	float altura = 0;
	float initx = -0.5;
	float initz = 0.5;
	float delta = 1.0 / 3;
	float angle = 315;
	slices = 12;
	float step = 360 / slices;
	int mov = 0;
	int j = 13;


	this->stacks = stacks;
	points.push_back(new Point(initx,altura,initz, stacks));

	for (int i = 1; i < 26; i++) {
		switch (mov) {
		case 0:
			initx += delta;
			points.push_back(new Point(initx,altura,initz, stacks));
			break;

		case 1:
			initz -= delta;
			points.push_back(new Point(initx,altura,initz, stacks));
			break;

		case 2:
			initx -= delta;
			points.push_back(new Point(initx,altura,initz, stacks));
			break;

		case 3:
			initz += delta;
			points.push_back(new Point(initx,altura,initz, stacks));
			break;

		case 4:
			points.push_back(new Point(sin(angle*deg2rad4) / 4.0, 1.0, cos(angle*deg2rad4) / 4.0, stacks));
			angle+=step;
			break;
		}

		if (i == 3)
			mov = 1;
		if (i == 6)
			mov = 2;
		if (i == 9)
			mov = 3;
		if (i == 12) {
			mov = 4;
			//printf("size: %d", points.size());
		}
	}

	//printf("size: %d", points.size());

	for (int i=0; i<13;i++) {

		points[i]->setStep(*points[j]);
		j++;
	}

}

void MyRobotDraw::getNormal() {

	float altura = 1.0 / stacks;
	float delta = 1.0 / 3.0;
	float deltax = 0.5 / stacks;

	x = 0;
	y = (0 - (-deltax * delta));
	z = (altura * delta);

}

void MyRobotDraw::draw() {

	float altura = 1.0 / stacks;
	float altura1 = 1.0 / stacks;


	for (float j=0.0; j < 1;) {

		glBegin(GL_TRIANGLE_STRIP);
		for (int i=0; i<13;i++) {


			glVertex3f(points[i]->xtemp - points[i]->distx, altura, points[i]->ztemp - points[i]->distz );
			glVertex3f(points[i]->xtemp, altura - altura1, points[i]->ztemp );

			points[i]->xtemp -= points[i]->distx;
			points[i]->ztemp -= points[i]->distz;
		}

		glEnd();

		altura+=altura1;
		j+=altura1;
	}

	for (int i=0; i<13;i++) {


		points[i]->xtemp = points[i]->x;
		points[i]->ztemp = points[i]->z;
	}

}

//for (float j = 0; j < 1;) {
//	glBegin(GL_TRIANGLE_STRIP);
//
//	glNormal3f(x, y, z);
//
//	if (j != 1 - altura1) {
//		glVertex3f(initx + (deltax / 2), altura, initz - (deltax / 2));
//	} else {
//		glNormal3f(cos(angle * deg2rad4) / 4, 0, sin(angle * deg2rad4) / 4);
//		glVertex3f(cos(angle * deg2rad4) / 4, altura,
//				sin(angle * deg2rad4) / 4);
//		angle += step;
//	}
//
//	glNormal3f(x, y, z);
//	glVertex3f(initx, altura - altura1, initz);
//
//	for (int i = 1; i <= slices; i++) {
//
//		switch (mov) {
//		case 0:
//			glNormal3f(x, y, z);
//			initx += delta;
//			if (j != 1 - altura1) {
//				if (i == 3) {
//					if (initx <= 0)
//						glVertex3f(initx + (deltax / 2), altura,
//								initz - (deltax / 2));
//					else
//						glVertex3f(initx - (deltax / 2), altura,
//								initz - (deltax / 2));
//				} else
//					glVertex3f(initx, altura, initz - (deltax / 2));
//			} else {
//				glNormal3f(cos(angle * deg2rad4) / 4, 0,
//						sin(angle * deg2rad4) / 4);
//				glVertex3f(cos(angle * deg2rad4) / 4, altura,
//						sin(angle * deg2rad4) / 4);
//				angle += step;
//			}
//
//			glNormal3f(x, y, z);
//			glVertex3f(initx, altura - altura1, initz);
//			break;
//
//		case 1:
//			glNormal3f(z, y, x);
//			initz -= delta;
//			if (j != 1 - altura1) {
//				if (i == 6) {
//					if (initz <= 0)
//						glVertex3f(initx - (deltax / 2), altura,
//								initz + (deltax / 2));
//					else
//						glVertex3f(initx - (deltax / 2), altura,
//								initz - (deltax / 2));
//				} else
//					glVertex3f(initx - (deltax / 2), altura, initz);
//			} else {
//				glNormal3f(cos(angle * deg2rad4) / 4, 0,
//						sin(angle * deg2rad4) / 4);
//				glVertex3f(cos(angle * deg2rad4) / 4, altura,
//						sin(angle * deg2rad4) / 4);
//				angle += step;
//			}
//
//			glNormal3f(z, y, x);
//			glVertex3f(initx, altura - altura1, initz);
//			break;
//
//		case 2:
//			glNormal3f(x, y, -z);
//			initx -= delta;
//			if (j != 1 - altura1) {
//				if (i == 9) {
//					if (initx <= 0)
//						glVertex3f(initx + (deltax / 2), altura,
//								initz + (deltax / 2));
//					else
//						glVertex3f(initx - (deltax / 2), altura,
//								initz + (deltax / 2));
//				} else
//					glVertex3f(initx, altura, initz + (deltax / 2));
//
//			} else {
//				glNormal3f(cos(angle * deg2rad4) / 4, 0,
//						sin(angle * deg2rad4) / 4);
//				glVertex3f(cos(angle * deg2rad4) / 4, altura,
//						sin(angle * deg2rad4) / 4);
//				angle += step;
//			}
//
//			glNormal3f(x, y, -z);
//			glVertex3f(initx, altura - altura1, initz);
//			break;
//
//		case 3:
//			glNormal3f(-z, y, x);
//			initz += delta;
//			if (j != 1 - altura1) {
//				if (i == 12) {
//					if (initz <= 0)
//						glVertex3f(initx + (deltax / 2), altura,
//								initz + (deltax / 2));
//					else
//						glVertex3f(initx + (deltax / 2), altura,
//								initz - (deltax / 2));
//				} else
//					glVertex3f(initx + (deltax / 2), altura, initz);
//
//			} else {
//				glNormal3f(cos(angle * deg2rad4) / 4, 0,
//						sin(angle * deg2rad4) / 4);
//				glVertex3f(cos(angle * deg2rad4) / 4, altura,
//						sin(angle * deg2rad4) / 4);
//				angle += step;
//			}
//
//			glNormal3f(-z, y, x);
//			glVertex3f(initx, altura - altura1, initz);
//			break;
//		}
//
//		if (i == 3)
//			mov = 1;
//		if (i == 6)
//			mov = 2;
//		if (i == 9)
//			mov = 3;
//	}
//
//	glEnd();
//
//	mov = 0;
//	initx += (deltax / 2);
//	initz -= (deltax / 2);
//	j += altura1;
//	altura += altura1;
//	c -= deltax;
//	delta = c / 3.0;
//
//}

/*float altura = 1.0 / stacks;
 float altura1 = 1.0 / stacks;
 float c = 1.0;
 float delta = c / 3.0;
 float deltax = 0.5 / stacks;
 float initx = -0.5;
 float initz = 0.5;
 float angle = 225;
 float step = 360.0 / slices;
 float divStep = 4.0 / stacks;
 float div = 2.0 - divStep;
 int mov = 0;


 for (float j = 0; j < 1;) {

 glBegin(GL_TRIANGLE_STRIP);


 glVertex3f(cos(angle * deg2rad4) / (div + divStep), altura,
 sin(angle * deg2rad4) / (div + divStep));

 if (j == 0.0) {
 glVertex3f(initx, 0, initz);
 } else {
 glVertex3f(cos(angle * deg2rad4) / div, altura - altura1,
 sin(angle * deg2rad4) / div);
 }

 angle += step;
 for (int i = 0; i <= slices; i++) {

 glVertex3f(cos(angle * deg2rad4) / (div + divStep), altura,
 sin(angle * deg2rad4) / (div + divStep));

 if (j == 0.0) {
 switch (mov) {
 case 0:
 initx += delta;
 glVertex3f(initx, 0, initz);
 break;
 case 1:
 initz -= delta;
 glVertex3f(initx, 0, initz);
 break;
 case 2:
 initx -= delta;
 glVertex3f(initx, 0, initz);
 break;
 case 3:
 initz += delta;
 glVertex3f(initx, 0, initz);
 break;
 }

 if (i == 4)
 mov = 1;
 if (i == 5)
 mov = 2;
 if (i == 8)
 mov = 3;

 } else {
 glVertex3f(cos(angle * deg2rad4) / div, altura - altura1,
 sin(angle * deg2rad4) / div);
 }

 angle+=step;
 }

 glEnd();

 angle = 225;
 div += divStep;
 altura+= altura1;
 j+=altura1;
 }*/
