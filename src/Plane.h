#pragma once

#include "CGFobject.h"
class Plane
{
public:
	Plane(void);
	Plane(int n, double delta, double dominio);
	~Plane(void);
	void draw();
private:
	int _numDivisions; // Number of triangles that constitute rows/columns
	double delta;
	double dominio;
};

