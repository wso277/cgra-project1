/*
 * MyClockHand.h
 *
 *  Created on: May 5, 2013
 *      Author: wso277
 */

#ifndef MYCLOCKHAND_H_
#define MYCLOCKHAND_H_

#include "myCylinder.h"
#include "CGFobject.h"

class MyClockHand : public CGFobject
{
	myCylinder pointer;
	float angPointer;
public:
	MyClockHand();
	void draw();
	void setAngle(float angle);
	float getAngle();
};


#endif /* MYCLOCKHAND_H_ */
