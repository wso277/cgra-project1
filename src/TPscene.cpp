#include "TPscene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"

#include <math.h>

float pi2 = acos(-1.0);
float deg2rad1=pi2/180.0;

#include "CGFappearance.h"

CGFappearance *mat1;

void TPscene::init() 
{
	// Enables lighting computations
	glEnable(GL_LIGHTING);

	// Sets up some lighting parameters
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, CGFlight::background_ambient);  // Define ambient light
	
	// Declares and enables a light
	float light0_pos[4] = {4.0, 6.0, 5.0, 1.0};
	CGFlight* light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->enable();

	// Defines a default normal
	glNormal3f(0,0,1);

}

void TPscene::display() 
{

	// ---- BEGIN Background, camera and axis setup
	
	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	// Draw axis
	axis.draw();

	// ---- END Background, camera and axis setup


	// ---- BEGIN Geometric transformation section

	// NOTE: OpenGL transformation matrices are transposed

	// Translate (5, 0, 2)
	
	float tra[16] = { 1.0, 0.0, 0.0, 0.0,
                      0.0, 1.0, 0.0, 0.0,
                      0.0, 0.0, 1.0, 0.0,
                      5.0, 0.0, 2.0, 1.0};

	// Rotate 30 degrees around Y
	// These constants would normally be pre-computed at initialization time
	// they are placed here just to simplify the exampl
	
	float a_rad=30.0*deg2rad1;
	float cos_a = cos(a_rad);
	float sin_a = sin(a_rad);

	
	
	
	
	

	// ---- END Geometric transformation section
	

	// ---- BEGIN Primitive drawing section

    // NOTE: the visible face of the polygon is determined by the order of the vertices

	myObject.draw();
	glPopMatrix();

	// ---- END Primitive drawing section

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	
	myTable table;
	myFloor floor;
	myChair chair;
	
	glPushMatrix();
	glTranslated(4,0,3);
	floor.draw();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(3,-6.25,3);
	table.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(3,-8,2);
	chair.draw();
	glPopMatrix();
	
	
	
	glutSwapBuffers();
}
