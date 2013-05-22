#pragma once

#include "CGFobject.h"

class LeftWall
{
public:
	LeftWall(int n, double delta, double dominio);
	void draw();
private:
	int _numDivisions; // Number of triangles that constitute rows/columns
	double delta;
	double dominio;
};

