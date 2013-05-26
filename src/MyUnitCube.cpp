#include "MyUnitCube.h"

void myUnitCube :: draw()

{
	glPushMatrix();
	glTranslated(0,0,-0.5);
	glRotated(180,0,1,0);
	glBegin(GL_POLYGON);
	glNormal3f(0,0,1);
	glTexCoord2d(0.0,0.0);
	glVertex2d(-0.5,-0.5);
	glTexCoord2d(5.0,0.0);
	glVertex2d(0.5,-0.5);
	glTexCoord2d(5.0,3.0);
	glVertex2d(0.5,0.5);
	glTexCoord2d(0.0,3.0);
	glVertex2d(-0.5,0.5);
	glEnd();
	
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,0.5);	
	glBegin(GL_POLYGON);
	glNormal3f(0,0,1);
	glTexCoord2d(0.0,0.0);
	glVertex2d(-0.5,-0.5);
	glTexCoord2d(5.0,0.0);
	glVertex2d(0.5,-0.5);
	glTexCoord2d(5.0,3.0);
	glVertex2d(0.5,0.5);
	glTexCoord2d(0.0,3.0);
	glVertex2d(-0.5,0.5);
	glEnd();
	
	glPopMatrix();

	glPushMatrix();
	glRotated(90,0,1,0);
	glTranslated(0,0, 0.5);	
	glBegin(GL_POLYGON);
	glNormal3f(0,0,1);
	glTexCoord2d(0.0,0.0);
	glVertex2d(-0.5,-0.5);
	glTexCoord2d(5.0,0.0);
	glVertex2d(0.5,-0.5);
	glTexCoord2d(5.0,3.0);
	glVertex2d(0.5,0.5);
	glTexCoord2d(0.0,3.0);
	glVertex2d(-0.5,0.5);
	glEnd();
	glPopMatrix();

		glPushMatrix();
	glRotated(-90,0,1,0);
	glTranslated(0,0,0.5);	
	glBegin(GL_POLYGON);
	glNormal3f(0,0,1);
	glTexCoord2d(0.0,0.0);
	glVertex2d(-0.5,-0.5);
	glTexCoord2d(5.0,0.0);
	glVertex2d(0.5,-0.5);
	glTexCoord2d(5.0,3.0);
	glVertex2d(0.5,0.5);
	glTexCoord2d(0.0,3.0);
	glVertex2d(-0.5,0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotated(90,1,0,0);
	glTranslated(0,0, 0.5);	
	glBegin(GL_POLYGON);
	glNormal3f(0,0,1);
	glTexCoord2d(0.0,0.0);
	glVertex2d(-0.5,-0.5);
	glTexCoord2d(5.0,0.0);
	glVertex2d(0.5,-0.5);
	glTexCoord2d(5.0,3.0);
	glVertex2d(0.5,0.5);
	glTexCoord2d(0.0,3.0);
	glVertex2d(-0.5,0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotated(-90,1,0,0);
	glTranslated(0,0, 0.5);	
	glBegin(GL_POLYGON);
	glNormal3f(0,0,1);
	glTexCoord2d(0.0,0.0);
	glVertex2d(-0.5,-0.5);
	glTexCoord2d(5.0,0.0);
	glVertex2d(0.5,-0.5);
	glTexCoord2d(5.0,3.0);
	glVertex2d(0.5,0.5);
	glTexCoord2d(0.0,3.0);
	glVertex2d(-0.5,0.5);
	glEnd();
	glPopMatrix();
}