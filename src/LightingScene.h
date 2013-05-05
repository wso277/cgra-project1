#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "MyTable.h"
#include "Plane.h"
#include "MyRobot.h"
#include "MyClock.h"



class LightingScene : public CGFscene
{
public:
	void init();
	void display();
	void toggleSomething(){};
	void update(unsigned long millis);
	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;
	CGFlight* light4;
	MyClock clock;
	MyRobot robot;
	unsigned long updateTime = 100;
	int animate = 1;
	int sceneVar;
	myTable* table;
	Plane* wall;
	Plane* boardA;
	Plane* boardB;
	CGFappearance* materialA;
	CGFappearance* materialB;

	~LightingScene();
};

#endif
