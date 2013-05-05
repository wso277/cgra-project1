#include "MyClock.h"
#include <math.h>
#include <stdio.h>



MyClock::MyClock()
{
	hour.setAngle(90);
	min.setAngle(180);
	sec.setAngle(270);
	saved = 0;
}

void MyClock::draw()
{



	glPushMatrix();
	glTranslated(7.2,8,0);
	glRotated(90,1,0,0);
	glScaled(1,0.2,1);
	clockCil.draw();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(7.2,8,0.2);
	glRotatef(sec.getAngle(),0,0,1);
	glScaled(0.025,0.8,0.025);
	sec.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(7.2,8,0.2);
	glRotatef(min.getAngle(),0,0,1);
	glScaled(0.05,0.7,0.05);
	min.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(7.2,8,0.2);
	glRotatef(hour.getAngle(),0,0,1);
	glScaled(0.05,0.5,0.05);
	hour.draw();
	glPopMatrix();

}

void MyClock::update(unsigned long time) {

	unsigned long temp = 0;
	if (saved == 0)
	{
		saved = time / 1000;
	}
	else {
		temp = time/1000 - saved;
		if ( temp >= 1) {
			sec.setAngle( ((360-sec.getAngle()) + temp * 6));
			min.setAngle( ((360-min.getAngle()) + temp * 0.1));
			hour.setAngle(((360-hour.getAngle()) + temp * (0.1/60)));
			saved = time/1000;
		}
	}
}

