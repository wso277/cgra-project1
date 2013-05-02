#ifndef MY_CLOCK
#define MY_CLOCK

#include "myCylinder.h"
#include "CGFobject.h"


class MyClock : public CGFobject
{
	myCylinder* clock; 
public:
	MyClock(void);
	void draw();
	~MyClock(void);
};



#endif
