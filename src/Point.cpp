/*
 * Point.cpp
 *
 *  Created on: May 13, 2013
 *      Author: wso277
 */

#include "Point.h"

using namespace std;

Point::Point(float x1,float y1, float z1, int stacks) {

	 x = x1;
	 y = y1;
	 z = z1;
	 xtemp = x;
	 ztemp = z;
	 this->stacks = stacks;

}

void Point::setStep(Point p1) {

	distx = (x-p1.x) / stacks;
	distz = (z-p1.z) / stacks;
}

