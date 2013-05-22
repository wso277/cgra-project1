#ifndef TPinterface_H
#define TPinterface_H

#include "CGFinterface.h"

class TPinterface: public CGFinterface {
public:
	int on0;
	int on1;
	int on2;
	int on3;
	int on4;
	int radioStatus;
	int listStatus;
	TPinterface();

	virtual void initGUI();
	virtual void processGUI(GLUI_Control *ctrl);

	virtual void processKeyboard(unsigned char key, int x, int y);

	int testVar;
};

#endif
