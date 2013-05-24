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
	_numDivisions = 30;
	this->delta = delta;
	this->dominio = dominio;
}

void LeftWall::draw() {
	//glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

	/*glBegin(GL_TRIANGLE_STRIP);

		glNormal3f(1,0,0);
	glVertex3d(0.0,8.0,0.0);
	glVertex3d(0.0,0.0,15.0);
	glVertex3d(0.0,0.0,0.0);
	//glVertex3d(0.0,10.0,0.0);

	glEnd();*/

	//glDisable(GL_CULL_FACE);

	float ysize = 2.6;
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
	}

	//glEnable(GL_CULL_FACE);

	//glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

}
