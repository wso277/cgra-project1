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
	_numDivisions = n;
	this->delta = delta;
	this->dominio = dominio;
}

void LeftWall::draw() {
	//glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

	glPushMatrix();
	glRotatef(180.0, 1, 0, 0);
	glTranslatef(-0.5, 0.0, -0.5);
	glScalef(1.0 / (double) _numDivisions, 1, 1.0 / (double) _numDivisions);
	glNormal3f(0, -1, 0);

	for (int bx = 0; bx < _numDivisions; bx++) {
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2d((((double) (bx) / _numDivisions) * dominio + delta),
				(((double) (0) / _numDivisions)) * dominio + delta);
		glVertex3f(bx, 0, 0);
		for (int bz = 0; bz < _numDivisions; bz++) {
			glTexCoord2d(
					(((double) (bx + 1) / _numDivisions) * dominio + delta),
					(((double) (bz) / _numDivisions)) * dominio + delta);
			glVertex3f(bx + 1, 0, bz);
			glTexCoord2d((((double) (bx) / _numDivisions) * dominio + delta),
					(((double) (bz + 1) / _numDivisions) * dominio + delta));
			glVertex3f(bx, 0, bz + 1);
		}
		glTexCoord2d((((double) (bx + 1) / _numDivisions) * dominio + delta),
				1.0 * dominio + delta);
		glVertex3d(bx + 1, 0, _numDivisions);

		glEnd();
	}
	glPopMatrix();

	//glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

}
