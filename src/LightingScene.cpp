#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "MyTable.h"
#include "Plane.h"
#include "myCylinder.h"
#include "MyClock.h"


#include <math.h>

float pi = acos(-1.0);
float deg2rad=pi/180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// Positions for two lights
float light0_pos[4] = {4, 6.0, 1.0, 1.0};
float light1_pos[4] = {10.5, 6.0, 1.0, 1.0};

float light2_pos[4] = {10.5, 6.0, 5.0, 1.0};
float light3_pos[4] = {4, 6.0, 5.0, 1.0};

float light4_pos[4] = {0.5, 5.0, 7.0, 1.0};

// Global ambient light (do not confuse with ambient component of individual lights)j
float globalAmbientLight[4]= {0,0,0,1.0};

// number of divisions
#define BOARD_A_DIVISIONS 30
#define BOARD_B_DIVISIONS 100

// Coefficients for material A
float ambA[3] = {0.2, 0.2, 0.2};
float difA[3] = {0.6, 0.6, 0.6};
float specA[3] = {0, 1, 0.8};//{0.2, 0.2, 0.2};
float shininessA = 120.f;//10.f;

// Coefficients for material B
float ambB[3] = {0.2, 0.2, 0.2};
float difB[3] = {0.6, 0.6, 0.6};
float specB[3] = {0.8, 0.8, 0.8};
float shininessB = 120.f;

float ambientNull[4]={0,0,0,1};
float yellow[4]={1,1,0,1};

CGFappearance* tableAppearance;
CGFappearance* windowAppearance;
CGFappearance* slidesAppearance;
CGFappearance* boardAppearance;
CGFappearance* floorAppearance;
CGFappearance* clockAppearance;
CGFappearance* robotAppearance;
CGFappearance* earthAppearance;



void LightingScene::init()
{
	sceneVar = 0;
	// Enables lighting computations
	glEnable(GL_LIGHTING);

	animate=1;
	updateTime=100;

	light0on = true;
	light1on = true;
	light2on = true;
	light3on = true;
	light4on = true;


	// Sets up some lighting parameters
	// Computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

	// Define ambient light (do not confuse with ambient component of individual lights)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);

	// Declares and enables two lights, with null ambient component

	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setAmbient(ambientNull);
	light0->setSpecular(yellow);


	light0->enable();
	//light0->enable();

	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);

	light1->enable();
	//light1->enable();


	light2 = new CGFlight(GL_LIGHT2, light2_pos);
	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 0);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 1);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0);
	light2->setAmbient(ambientNull);

	light2->enable();

	light3 = new CGFlight(GL_LIGHT3, light3_pos);
	glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 0);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0);
	glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 1);
	light3->setAmbient(ambientNull);

	light3->enable();

	light4 =new CGFlight(GL_LIGHT4, light4_pos);
	glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, 1);
	light4->setAmbient(ambientNull);

	light4->enable();

	// Uncomment below to enable normalization of lighting normal vectors
	 glEnable (GL_NORMALIZE);

	//Declares scene elements
	table = new myTable();
	wall = new Plane(1,-0.5 ,2);
	windowWall = new LeftWall(1,-0.5,2);
	boardA = new Plane(BOARD_A_DIVISIONS,0,1);
	boardB = new Plane(BOARD_B_DIVISIONS,0,1);

	//Declares materials
	materialA = new CGFappearance(ambA,difA,specA,shininessA);
	materialB = new CGFappearance(ambB,difB,specB,shininessB);

	float ambT[3] = {0.2, 0.2, 0.2};
	float difT[3] = {0.6, 0.6, 0.6};
	float specT[3] = {0.2, 0.2, 0.2};
	float shininessT = 10.f;

	float ambS[3] = {0.2, 0.2, 0.2};
	float difS[3] = {0.6, 0.6, 0.6};
	float specS[3] = {0.2, 0.2, 0.2};
	float shininessS = 10.f;

	float ambBd[3] = {0.2, 0.2, 0.2};
	float difBd[3] = {0.2, 0.2, 0.2};
	float specBd[3] = {0.5, 0.5, 0.5};
	float shininessBd = 120.f;
	tableAppearance = new CGFappearance(ambT,difT,specT,shininessT);
	tableAppearance->setTexture("table.png");


	slidesAppearance = new CGFappearance(ambS,difS,specS,shininessS);
	slidesAppearance->setTexture("slides.png");
	boardAppearance = new CGFappearance(ambBd,difBd,specBd,shininessBd);
	boardAppearance->setTexture("board.png");

	windowAppearance = new CGFappearance(ambT,difT,specT,shininessT);
	windowAppearance->setTexture("window.png");
	windowAppearance->setTextureWrap(GL_CLAMP, GL_CLAMP);

	floorAppearance = new CGFappearance(ambT,difT,specT,shininessT);
	floorAppearance->setTexture("floor.png");

	clockAppearance = new CGFappearance(ambT,difT,specT,shininessT);
	clockAppearance->setTexture("clock.png");
	clockAppearance->setTextureWrap(GL_CLAMP, GL_CLAMP);

	robotAppearance = new CGFappearance(ambT,difT,specT,shininessT);
	robotAppearance->setTexture("robot1.jpg");

	earthAppearance = new CGFappearance(ambT,difT,specT,shininessT);
	earthAppearance->setTexture("earth.jpg");

	setUpdatePeriod(updateTime);
}

void LightingScene::display()
{
	myCylinder cilindro(30,5,true);
	myCylinder cilindro_flat(30,5,false);

	// ---- BEGIN Background, camera and axis setup

	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	light0->draw();
	light1->draw();
	light2->draw();
	light3->draw();
	light4->draw();
	// Draw axis
	axis.draw();

	// ---- END Background, camera and axis setup

	// ---- BEGIN Primitive drawing section

	glPushMatrix();
	glTranslated(2,0,11);
	glScaled(1,8,1);
	cilindro.draw();
	glPopMatrix();

	/*glPushMatrix();
	glTranslated(14,0,11);
	glScaled(1,8,1);
	cilindro_flat.draw();
	glPopMatrix();*/

	//PlaneWall
	glPushMatrix();
		glTranslated(7.5,4,0);
		glRotated(90.0,1,0,0);
		glScaled(15,0.2,8);

		wall->draw();
	glPopMatrix();


	//clock
	clockAppearance->apply();
	clock.draw();

	switch (robot.robot->texture) {
	case 0: robotAppearance->apply();
			break;
	case 1: earthAppearance->apply();
			break;

	}

	robot.draw();

		//LeftWall
	glPushMatrix();
		glTranslated(0,4,7.5);
		glRotated(-90.0,0,0,1);

		glScaled(8,0.2,15);
		windowAppearance->apply();
		windowWall->draw();
	glPopMatrix();



		//Floor
	glPushMatrix();
		glTranslated(7.5,0,7.5);
		glScaled(15,0.2,15);
		floorAppearance->apply();
		wall->draw(12,10);
	glPopMatrix();
	// Board A
	glPushMatrix();
		glTranslated(4,4,0.2);
		glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
		glRotated(90.0,1,0,0);
		slidesAppearance->apply();
		boardA->draw();
	glPopMatrix();

	//PlaneB
	glPushMatrix();
		glTranslated(10.5,4,0.2);
		glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
		glRotated(90.0,1,0,0);
		boardAppearance->apply();
		boardB->draw();
	glPopMatrix();

		//First Table
	glPushMatrix();
		glTranslated(5,-6.5,8);
		tableAppearance->apply();
		table->draw();
	glPopMatrix();



	/*//Second Table
	glPushMatrix();
		glTranslated(12,-6.5,8);
		table->draw();
	glPopMatrix();*/

	// ---- END Primitive drawing section


	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

LightingScene::~LightingScene()
{
	delete(light0);
	delete(light1);

	delete(table);
	delete(wall);
	delete(boardA);
	delete(boardB);
	delete(materialA);
	delete(materialB);
}

void LightingScene::update(unsigned long milis) {

	if (animate)
		clock.update(milis);
}
