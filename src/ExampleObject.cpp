#include "ExampleObject.h"

void ExampleObject::draw() 
{
		glBegin(GL_QUADS);
		glVertex3d(0,0,0);
		glVertex3d(4,0,0);
		glVertex3d(4,3,0);
		glVertex3d(0,3,0);
		glEnd();

		glBegin(GL_TRIANGLES);
		glVertex3d(5,3,0);
		glVertex3d(2,4,0);
	
		glVertex3d(-1,3,0);
		glEnd();
}





void myFloor :: draw()
{
	
	glScaled(8,0.1,6);
	cube.draw();
}


void myChair :: draw()
{
	glPushMatrix();
	glTranslated(0,10,0);
	glScaled(2,0.1,2);
	cube.draw();
	glPopMatrix(); //Tampo

	glPushMatrix();
	glTranslated(0,11,-1);
	glRotated(90,1,0,0);
	glScaled(2,0.1,2);
	cube.draw();
	glPopMatrix(); //Encosto

	glPushMatrix();
	glTranslated(-0.7,9,0.7);
	glScaled(0.1,2,0.1);
	cube.draw();
	glPopMatrix(); // Perna 1

	glPushMatrix();
	glTranslated(-0.7,9,-0.7);
	glScaled(0.1,2,0.1);
	cube.draw();
	glPopMatrix(); // Perna 2

	glPushMatrix();
	glTranslated(0.7,9,0.7);
	glScaled(0.1,2,0.1);
	cube.draw();
	glPopMatrix(); // Perna 3

	glPushMatrix();
	glTranslated(0.7,9,-0.7);
	glScaled(0.1,2,0.1);
	cube.draw();
	glPopMatrix(); // Perna 4
}