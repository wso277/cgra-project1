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
	vector<vector<float>> normais;
	float x,y,z;
public:
	MyRobotDraw(int stacks);
	void draw();
	void getNormal();
	
	vector<float> calculaNormais(const vector< vector<float>> vertices)
	{
		vector<float> tmp;
		tmp.push_back(0);
		tmp.push_back(0);
		tmp.push_back(0);

		for(int i = 0; i< vertices.size(); i++)
		{
			vector<float> current = vertices[i];
			vector<float> next = vertices[ (i+1) % vertices.size() ];

			tmp[0] += ((current[1] - next[1]) * ( current[2] + next[2] )); 
			tmp[1] += ((current[2] - next[2]) * ( current[0] + next[0] )); 
			tmp[2] += ((current[0] - next[0]) * ( current[1] + next[1] )); 

			
		}


		printf("normal0 = %f\nnormal\ = %f\nnormal2 = %f\n", tmp[0],tmp[1],tmp[2]);

		return tmp;
	}
};

#endif /* MYROBOTDRAW_H_ */
