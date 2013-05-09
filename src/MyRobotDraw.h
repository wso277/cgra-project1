/*
 * MyRobotDraw.h
 *
 *  Created on: May 7, 2013
 *      Author: wso277
 */

#ifndef MYROBOTDRAW_H_
#define MYROBOTDRAW_H_


#include "CGFobject.h"

class MyRobotDraw : public CGFobject{

	int slices, stacks;
	float x,y,z;
public:
	MyRobotDraw(int stacks);
	void draw();
	void getNormal();
};

#endif /* MYROBOTDRAW_H_ */
