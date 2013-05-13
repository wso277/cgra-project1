/*
 * Point.h
 *
 *  Created on: May 13, 2013
 *      Author: wso277
 */

#ifndef POINT_H_
#define POINT_H_

using namespace std;

class Point {


public:
	float x,y,z;
	float xtemp,ztemp;
	int stacks;
	float distx,distz;
	Point(float x1,float y1, float z1, int stacks);
	void setStep(Point p1);
};

#endif /* POINT_H_ */
