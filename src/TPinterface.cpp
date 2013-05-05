#include "TPinterface.h"
#include "LightingScene.h"

TPinterface::TPinterface() {
	testVar = 0;
}

void TPinterface::processKeyboard(unsigned char key, int x, int y) {
	// Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
	 //CGFinterface::processKeyboard(key, x, y);

	switch (key) {
	case 'a': {
		// This is an example of accessing the associated scene
		// To test, create the function toggleSomething in your scene to activate/deactivate something
		((LightingScene *) scene)->toggleSomething();
		break;
	}

	case 'j':
		((LightingScene *) scene)->robot.moveLeft();
		break;

	case 'l':
		((LightingScene *) scene)->robot.moveRight();
		break;
	case 'i':
		((LightingScene *) scene)->robot.moveForward();
		break;
	case 'k':
		((LightingScene *) scene)->robot.moveBackward();
		break;
	}
}

void TPinterface::initGUI() {
	// Check CGFinterface.h and GLUI documentation for the types of controls available
	GLUI_Panel *varPanel = addPanel("Group", 1);
	//addSpinnerToPanel(varPanel, "Val 1(interface)", 2, &testVar, 1);

	// You could also pass a reference to a variable from the scene class, if public
	//addSpinnerToPanel(varPanel, "Val 2(scene)", 2, &(((LightingScene*) scene)->sceneVar), 2);
	int on0 = 1;
	int on1 = 1;
	int on2 = 1;
	int on3 = 1;
	int on4 = 1;
	addCheckboxToPanel(varPanel, "light0", &on0, 0);
	addCheckboxToPanel(varPanel, "light1", &on1, 1);
	addCheckboxToPanel(varPanel, "light2", &on2, 2);
	addCheckboxToPanel(varPanel, "light3", &on3, 3);
	addCheckboxToPanel(varPanel, "light4", &on4, 4);

	addButtonToPanel(varPanel, "Clock", 5);

}

void TPinterface::processGUI(GLUI_Control *ctrl) {
	switch (ctrl->user_id) {
	case 0: {
		if (((LightingScene *) scene)->light0->isEnabled()) {
			printf("Light 0: off\n");
			((LightingScene *) scene)->light0->disable();
		} else {
			printf("Light 0: on\n");
			((LightingScene *) scene)->light0->enable();
		}
		break;
	}
	case 1: {
		if (((LightingScene *) scene)->light1->isEnabled()) {
			printf("Light 1: off\n");
			((LightingScene *) scene)->light1->disable();
		} else {
			printf("Light 1: on\n");
			((LightingScene *) scene)->light1->enable();
		}
		break;
	}
	case 2: {
		if (((LightingScene *) scene)->light2->isEnabled()) {
			printf("Light 2: off\n");
			((LightingScene *) scene)->light2->disable();
		} else {
			printf("Light 2: on\n");
			((LightingScene *) scene)->light2->enable();
		}
		break;
	}
	case 3: {
		if (((LightingScene *) scene)->light3->isEnabled()) {
			printf("Light 3: off\n");
			((LightingScene *) scene)->light3->disable();
		} else {
			printf("Light 3: on\n");
			((LightingScene *) scene)->light3->enable();
		}
		break;
	}
	case 4: {
		if (((LightingScene *) scene)->light4->isEnabled()) {
			printf("Light 4: off\n");
			((LightingScene *) scene)->light4->disable();
		} else {
			printf("Light 4: on\n");
			((LightingScene *) scene)->light4->enable();
		}
		break;
	}
	case 5: {
		if (((LightingScene *) scene)->animate)
			((LightingScene *) scene)->animate = 0;
		else
			((LightingScene *) scene)->animate = 1;
	}
	};
}

