#include "myCylinder.h"
#include <math.h>


float pi1 = acos(-1.0);
float deg2rad2=pi1/180.0;

myCylinder::myCylinder() {

	this->slices = 12;
	this->stacks = 1;
	this->smooth = true;
}

myCylinder::myCylinder(int slices, int stacks, bool smooth) {
	
	this->slices = slices;
	this->stacks = stacks;
	this->smooth = smooth;
}


void myCylinder :: draw()
{
	float angulo = 360 / slices;
	float altura = 1.0 / stacks;
	float altura1 = 1.0 / stacks;
	float delta = 360 / slices;
	
	for(float j = 0 ; j < 1 ; )
	{
	if(smooth)
	{
	glBegin(GL_QUAD_STRIP);
	
	glNormal3f(cos(0.0),0,sin(0.0));
	glVertex3f(cos(0.0),altura - altura1 ,sin(0.0));
	glVertex3f(cos(0.0),altura,sin(0.0));
	
	
	for(int i = 0; i <= slices ; i++)
	{
		glNormal3f(cos((angulo)*deg2rad2),0.0,sin((angulo)*deg2rad2));
		glVertex3f(cos(angulo*deg2rad2),altura - altura1 ,sin(angulo*deg2rad2));
		glVertex3f(cos(angulo*deg2rad2),altura,sin(angulo*deg2rad2));
		

		angulo += delta ;
	}

	
	glEnd();
	
	}

	else
	{

	for(int i = 0; i <= slices ; i++)
	{
	glBegin(GL_QUADS);
	
	glNormal3f(sin((angulo-(delta/2))*deg2rad2),0.0,cos((angulo-(delta/2))*deg2rad2));
	
	glVertex3f(sin((angulo-delta)*deg2rad2),altura - altura1 ,cos((angulo-delta)*deg2rad2));
	glVertex3f(sin(angulo*deg2rad2),altura - altura1,cos(angulo*deg2rad2));
	glVertex3f(sin(angulo*deg2rad2),altura,cos(angulo*deg2rad2));
	glVertex3f(sin((angulo-delta)*deg2rad2),altura,cos((angulo-delta)*deg2rad2));
	//glVertex3f(cos(angulo*deg2rad2),altura - altura1 ,sin(angulo*deg2rad2));
	
	

	
	

		
	

	
	glEnd();
	angulo += delta ;
	}
	
	}

	j = j + altura1;
	altura += altura1;
	angulo = 360 / slices;
	}
}
