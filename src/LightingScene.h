#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "MyTable.h"
#include "Plane.h"
#include "LeftWall.h"
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
	bool light0on;
	CGFlight* light1;
	bool light1on;
	CGFlight* light2;
	bool light2on;
	CGFlight* light3;
	bool light3on;
	CGFlight* light4;
	bool light4on;
	MyClock clock;
	MyRobot robot;
	unsigned long updateTime;
	int animate;
	int sceneVar;
	myTable* table;
	Plane* wall;
	Plane* impostor;
    LeftWall* windowWall;
	Plane* boardA;
	Plane* boardB;
	CGFappearance* materialA;
	CGFappearance* materialB;

	~LightingScene();
};

#endif
