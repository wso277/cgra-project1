#include "MyTable.h"

void myTable :: draw()

{
	glPushMatrix();
	glTranslated(0,10,0);
	glScaled(5,0.3,3);
	cube.draw();
	glPopMatrix(); //Tampo


	glPushMatrix();
	glTranslated(-2,8.1,1);
	glScaled(0.3,3.5,0.3);
	cube.draw();
	glPopMatrix(); // Perna 1

	glPushMatrix();
	glTranslated(-2,8.1,-1);
	glScaled(0.3,3.5,0.3);
	cube.draw();
	glPopMatrix(); // Perna 2

	glPushMatrix();
	glTranslated(2,8.1,1);
	glScaled(0.3,3.5,0.3);
	cube.draw();
	glPopMatrix(); // Perna 3

	glPushMatrix();
	glTranslated(2,8.1,-1);
	glScaled(0.3,3.5,0.3);
	cube.draw();
	glPopMatrix(); // Perna 4
}