#ifndef MY_CLOCK
#define MY_CLOCK

#include "myCylinder.h"
#include "CGFobject.h"


class MyClock : public CGFobject
{
	myCylinder clockCil;
	myCylinder min;
	myCylinder sec;
	myCylinder hour;
public:
	MyClock();
	void draw();
};



#endif
