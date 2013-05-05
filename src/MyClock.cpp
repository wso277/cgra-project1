#include "MyClock.h"




MyClock::MyClock()
{

}

void MyClock::draw()
{



	glPushMatrix();
	glTranslated(7.2,7,0);
	glRotated(90,1,0,0);
	glScaled(1,0.2,1);
	clockCil.draw();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(7.2,7,0.2);
	glRotated(90,0,0,1);
	glScaled(0.1,0.8,0.1);
	min.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(7.2,7,0.2);
	glScaled(0.1,0.7,0.1);
	hour.draw();
	glPopMatrix();
	


}
