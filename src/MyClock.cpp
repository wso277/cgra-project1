#include "MyClock.h"




MyClock::MyClock(void)
{
	clock = new myCylinder(12, 1, true);
}

void MyClock::draw()
{


	clock->draw();
	/*glPushMatrix();
	glTranslated(2,1,11);
	glRotated(90.0,1,0,0);
	glPopMatrix();*/
	
	


}


MyClock::~MyClock(void)
{
}
