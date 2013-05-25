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

			if (bz == 1 && bx == 1) {


				glTexCoord2d(
						(((double) (bx + 1) / _numDivisions) * dominio + delta),
						(((double) (bz) / _numDivisions)) * dominio + delta);
				glVertex3f(bx + 1, 0, bz);

				glEnd();
				glBegin(GL_TRIANGLE_STRIP);

				glTexCoord2d(
						(((double) (bx) / _numDivisions) * dominio + delta),
						(((double) (bz + 1) / _numDivisions) * dominio + delta));
				glVertex3f(bx, 0, bz + 1);

			} else {
				glTexCoord2d(
						(((double) (bx + 1) / _numDivisions) * dominio + delta),
						(((double) (bz) / _numDivisions)) * dominio + delta);
				glVertex3f(bx + 1, 0, bz);
				glTexCoord2d(
						(((double) (bx) / _numDivisions) * dominio + delta),
						(((double) (bz + 1) / _numDivisions) * dominio + delta));
				glVertex3f(bx, 0, bz + 1);
			}
		}
		glTexCoord2d((((double) (bx + 1) / _numDivisions) * dominio + delta),
				1.0 * dominio + delta);
		glVertex3d(bx + 1, 0, _numDivisions);

		glEnd();
	}
	glPopMatrix();

	//glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

	//glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

	/*glBegin(GL_TRIANGLE_STRIP);

	 glNormal3f(1,0,0);
	 glVertex3d(0.0,8.0,0.0);
	 glVertex3d(0.0,0.0,15.0);
	 glVertex3d(0.0,0.0,0.0);
	 //glVertex3d(0.0,10.0,0.0);

	 glEnd();*/

	//glDisable(GL_CULL_FACE);
	/*float ysize = 2.6;
	 float ystep = ysize/3.0;
	 float zsize = 5.0;
	 float zstep = zsize/3.0;

	 glNormal3f(1,0,0);

	 for (float y=0.0; y < ysize; y+=ystep) {

	 glBegin(GL_TRIANGLE_STRIP);
	 for (float z=zsize; z >= 0; z-=zstep) {

	 glNormal3f(1,0,0);
	 glVertex3d(0, y+ystep, z);

	 glNormal3f(1,0,0);
	 glVertex3d(0, y, z);
	 }

	 glEnd();
	 }

	 for (float y=ysize; y < ysize*2; y+=ystep) {

	 glBegin(GL_TRIANGLE_STRIP);
	 for (float z=zsize; z >= 0; z-=zstep) {

	 glNormal3f(1,0,0);
	 glVertex3d(0, y+ystep, z);

	 glNormal3f(1,0,0);
	 glVertex3d(0, y, z);
	 }

	 glEnd();
	 }

	 for (float y=ysize*2; y < ysize*3; y+=ystep) {

	 glBegin(GL_TRIANGLE_STRIP);
	 for (float z=zsize; z >= 0; z-=zstep) {

	 glNormal3f(1,0,0);
	 glVertex3d(0, y+ystep, z);

	 glNormal3f(1,0,0);
	 glVertex3d(0, y, z);
	 }

	 glEnd();
	 }





	 for (float y=0.0; y < ysize-ystep; y+=ystep) {

	 glBegin(GL_TRIANGLE_STRIP);
	 for (float z=zsize*2; z >= zsize; z-=zstep) {

	 glNormal3f(1,0,0);
	 glVertex3d(0, y+ystep, z);

	 glNormal3f(1,0,0);
	 glVertex3d(0, y, z);
	 }

	 glEnd();
	 }

	 for (float y=ysize*2+ystep; y < ysize*3; y+=ystep) {

	 glBegin(GL_TRIANGLE_STRIP);
	 for (float z=zsize*2; z >= zsize; z-=zstep) {

	 glNormal3f(1,0,0);
	 glVertex3d(0, y+ystep, z);

	 glNormal3f(1,0,0);
	 glVertex3d(0, y, z);
	 }

	 glEnd();
	 }






	 for (float y=0.0; y < ysize; y+=ystep) {

	 glBegin(GL_TRIANGLE_STRIP);
	 for (float z=zsize*3; z >= zsize*2-zstep; z-=zstep) {

	 glNormal3f(1,0,0);
	 glVertex3d(0, y+ystep, z);

	 glNormal3f(1,0,0);
	 glVertex3d(0, y, z);
	 }

	 glEnd();
	 }

	 for (float y=ysize; y < ysize*2; y+=ystep) {

	 glBegin(GL_TRIANGLE_STRIP);
	 for (float z=zsize*3; z >= zsize*2-zstep; z-=zstep) {

	 glNormal3f(1,0,0);
	 glVertex3d(0, y+ystep, z);

	 glNormal3f(1,0,0);
	 glVertex3d(0, y, z);
	 }

	 glEnd();
	 }

	 for (float y=ysize*2; y < ysize*3; y+=ystep) {

	 glBegin(GL_TRIANGLE_STRIP);
	 for (float z=zsize*3; z >= zsize*2-zstep; z-=zstep) {

	 glNormal3f(1,0,0);
	 glVertex3d(0, y+ystep, z);

	 glNormal3f(1,0,0);
	 glVertex3d(0, y, z);
	 }

	 glEnd();
	 }*/

	//glEnable(GL_CULL_FACE);
	//glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
}
