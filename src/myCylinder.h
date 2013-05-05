#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGFobject.h"


class myCylinder : public CGFobject {

	int slices,stacks;
	bool smooth;
	public:
		myCylinder();
		myCylinder(int slices, int stacks, bool smooth);
		void draw();

};



#endif
