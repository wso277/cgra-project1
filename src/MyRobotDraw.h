/*
 * MyRobotDraw.h
 *
 *  Created on: May 7, 2013
 *      Author: wso277
 */

#ifndef MYROBOTDRAW_H_
#define MYROBOTDRAW_H_


#include <vector>

#include "Point.h"
#include "CGFobject.h"

class MyRobotDraw : public CGFobject{

	int slices, stacks;
	vector<Point*> points;
	vector<vector<float> > normais;
	vector<float> normalx;
	vector<float> normalz;
	float x,y,z;
	bool wireframe;
public:
	MyRobotDraw(int stacks);
	void draw();
	void getNormal();
	vector<float> calculaNormais(vector<vector<float> > vertices);
	void setWireframe();

};

#endif /* MYROBOTDRAW_H_ */
