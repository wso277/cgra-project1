#include "Plane.h"
#include "MyUnitCube.h"
#include <GL/glu.h>


Plane::Plane(void)
{
	_numDivisions = 1;
	delta = 0;
	dominio = 1;
}

Plane::Plane(int n, double delta, double dominio)
{
	_numDivisions = n;
	this->delta = delta;
	this->dominio = dominio;
}


Plane::~Plane(void)
{
}

void Plane::draw()
{
	glPushMatrix();
		glRotatef(180.0,1,0,0);
		glTranslatef(-0.5,0.0,-0.5);
		glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
		glNormal3f(0,-1,0);

		for (int bx = 0; bx<_numDivisions; bx++)
		{
			glBegin(GL_TRIANGLE_STRIP);
			glTexCoord2d(   (((double)(bx)/_numDivisions)*dominio + delta),(( (double)(0)/_numDivisions)) * dominio + delta);
				glVertex3f(bx, 0, 0);
				for (int bz = 0; bz<_numDivisions; bz++)
				{
					glTexCoord2d(   (((double)(bx+1)/_numDivisions)*dominio + delta),(( (double)(bz)/_numDivisions)) * dominio + delta);
					glVertex3f(bx + 1, 0, bz);
					glTexCoord2d(   (((double)(bx)/_numDivisions) * dominio + delta),  (((double)(bz+1)/_numDivisions)*dominio + delta)    );
					glVertex3f(bx, 0, bz + 1);
				}
				glTexCoord2d( (((double)(bx+1)/_numDivisions)*dominio+delta),1.0  * dominio + delta);
				glVertex3d(bx+ 1, 0, _numDivisions);

			glEnd();
		}
	glPopMatrix();

}

void Plane::draw(int s, int t)
{
	glPushMatrix();
		glRotatef(180.0,1,0,0);
		glTranslatef(-0.5,0.0,-0.5);
		glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
		glNormal3f(0,-1,0);

		for (int bx = 0; bx<_numDivisions; bx++)
		{
			glBegin(GL_TRIANGLE_STRIP);
			glTexCoord2d(   (((double)(bx)/_numDivisions)*s ),(( (double)(0)/_numDivisions)) * t);
				glVertex3f(bx, 0, 0);
				for (int bz = 0; bz<_numDivisions; bz++)
				{
					glTexCoord2d(   (((double)(bx+1)/_numDivisions)*s),(( (double)(bz)/_numDivisions)) * t);
					glVertex3f(bx + 1, 0, bz);
					glTexCoord2d(   (((double)(bx)/_numDivisions) * s),  (((double)(bz+1)/_numDivisions)*t));
					glVertex3f(bx, 0, bz + 1);
				}
				glTexCoord2d( (((double)(bx+1)/_numDivisions)*s),1.0  * t);
				glVertex3d(bx+ 1, 0, _numDivisions);

			glEnd();
		}
	glPopMatrix();

}
