#ifndef MY_CLOCK
#define MY_CLOCK

#include "myCylinder.h"
#include "MyClockHand.h"
#include "CGFobject.h"


class MyClock : public CGFobject
{
	myCylinder clockCil;
	MyClockHand min;
	MyClockHand sec;
	MyClockHand hour;
	unsigned long saved;
public:
	MyClock();
	void draw();
	void update(unsigned long time);
};



#endif
