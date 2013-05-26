#include "TPinterface.h"
#include "LightingScene.h"

TPinterface::TPinterface() {
	testVar = 0;
	on0 = 1;
	on1 = 1;
	on2 = 1;
	on3 = 1;
	on4 = 1;
	radioStatus = 0;
	listStatus = 0;
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
	GLUI_Panel *varPanel = addPanel("Lights", 1);

	// You could also pass a reference to a variable from the scene class, if public

	addCheckboxToPanel(varPanel, "light0", &on0, 0);
	addCheckboxToPanel(varPanel, "light1", &on1, 1);
	addCheckboxToPanel(varPanel, "light2", &on2, 2);
	addCheckboxToPanel(varPanel, "light3", &on3, 3);
	addCheckboxToPanel(varPanel, "light4", &on4, 4);

	addButtonToPanel(varPanel, "Clock", 5);


	GLUI_RadioGroup* wireframeGroup = addRadioGroupToPanel(varPanel,&radioStatus, 6);

	addRadioButtonToGroup(wireframeGroup, "Textured");
	addRadioButtonToGroup(wireframeGroup, "Wireframed");



	GLUI_Listbox* listBox = addListboxToPanel(varPanel,"Textures",&listStatus, 7);

	listBox->add_item(0, "Default");
	listBox->add_item(1, "Earth");

}

void TPinterface::processGUI(GLUI_Control *ctrl) {
	switch (ctrl->user_id) {
	case 0: {
		if (((LightingScene *) scene)->light0on) {
			printf("Light 0: off\n");
			((LightingScene *) scene)->light0->disable();
			((LightingScene *) scene)->light0on = false;
		} else {
			printf("Light 0: on\n");
			((LightingScene *) scene)->light0->enable();
			((LightingScene *) scene)->light0on = true;
		}
		break;
	}
	case 1: {
		if (((LightingScene *) scene)->light1on) {
			printf("Light 1: off\n");
			((LightingScene *) scene)->light1->disable();
			((LightingScene *) scene)->light1on = false;
		} else {
			printf("Light 1: on\n");
			((LightingScene *) scene)->light1->enable();
			((LightingScene *) scene)->light1on = true;
		}
		break;
	}
	case 2: {
		if (((LightingScene *) scene)->light2on) {
			printf("Light 2: off\n");
			((LightingScene *) scene)->light2->disable();
			((LightingScene *) scene)->light2on = false;
		} else {
			printf("Light 2: on\n");
			((LightingScene *) scene)->light2->enable();
			((LightingScene *) scene)->light2on = true;
		}
		break;
	}
	case 3: {
		if (((LightingScene *) scene)->light3on) {
			printf("Light 3: off\n");
			((LightingScene *) scene)->light3->disable();
			((LightingScene *) scene)->light3on = false;
		} else {
			printf("Light 3: on\n");
			((LightingScene *) scene)->light3->enable();
			((LightingScene *) scene)->light3on = true;
		}
		break;
	}
	case 4: {
		if (((LightingScene *) scene)->light4on) {
			printf("Light 4: off\n");
			((LightingScene *) scene)->light4->disable();
			((LightingScene *) scene)->light4on = false;
		} else {
			printf("Light 4: on\n");
			((LightingScene *) scene)->light4->enable();
			((LightingScene *) scene)->light4on = true;
		}
		break;
	}
	case 5: {
		if (((LightingScene *) scene)->animate)
			((LightingScene *) scene)->animate = 0;
		else
			((LightingScene *) scene)->animate = 1;

		break;
	}
	case 6: {
		((LightingScene *) scene)->robot.robot->setWireframe();
		break;
	}
	case 7: {
		((LightingScene *) scene)->robot.robot->setTexture(listStatus);
	}
	};
}

