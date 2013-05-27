/*
 * LeftWall.cpp
 *
 *  Created on: May 22, 2013
 *      Author: wso277
 */

#include "LeftWall.h"
#include "MyUnitCube.h"
#include <GL/glu.h>

LeftWall::LeftWall(int n, double delta, double dominio) {
	_numDivisions = 3;
	this->delta = -0.75;
	this->dominio = 2.5;
}

void LeftWall::draw() {

	glPushMatrix();
	glRotatef(180.0, 1, 0, 0);
	glTranslatef(-0.5, 0.0, -0.5);
	glScalef(1.0 / (double) _numDivisions, 1, 1.0 / (double) _numDivisions);
	glNormal3f(0, -1, 0);

	for (int bx = 0; bx < _numDivisions; bx++) {
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2d(texturePointsX(bx), texturePointsZ(0));
		glVertex3f(bx, 0, 0);
		for (int bz = 0; bz < _numDivisions; bz++) {

			if (bz == 1 && bx == 1) {

				glTexCoord2d(texturePointsX(bx + 1), texturePointsZ(bz));
				glVertex3f(bx + 1, 0, bz);

				glEnd();
				glBegin(GL_TRIANGLE_STRIP);

				glTexCoord2d(texturePointsX(bx), texturePointsZ(bz + 1));
				glVertex3f(bx, 0, bz + 1);

			} else {
				glTexCoord2d(texturePointsX(bx + 1), texturePointsZ(bz));
				glVertex3f(bx + 1, 0, bz);
				glTexCoord2d(texturePointsX(bx), texturePointsZ(bz + 1));
				glVertex3f(bx, 0, bz + 1);
			}
		}
		glTexCoord2d(texturePointsX(bx + 1), texturePointsZ(_numDivisions));
		glVertex3d(bx + 1, 0, _numDivisions);

		glEnd();
	}
	glPopMatrix();

}

double LeftWall::texturePointsX(int value) {
	switch (value) {
	case 0:
		return -1;
	case 1:
		return 0.02;
	case 2:
		return 0.97;
	case 3:
		return 2;
	}
}

double LeftWall::texturePointsZ(int value) {
	switch (value) {
	case 0:
		return -1;
	case 1:
		return 0.04;
	case 2:
		return 0.97;
	case 3:
		return 2;
	}
}

