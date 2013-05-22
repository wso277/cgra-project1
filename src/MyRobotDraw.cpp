/*
 * MyRobotDraw.cpp
 *
 *  Created on: May 7, 2013
 *      Author: wso277
 */

#include <math.h>
#include <stdio.h>
#include "MyRobotDraw.h"

using namespace std;

float pi4 = acos(-1.0);
float deg2rad4 = pi4 / 180.0;

MyRobotDraw::MyRobotDraw(int stacks) {

	float altura = 0;
	float initx = -0.5;
	float initz = 0.5;
	float delta = 1.0 / 3;
	float angle = 315;
	slices = 12;
	float step = 360 / slices;
	int mov = 0;
	int j = 16;
	vector<float> ponto;

	wireframe = false;
	texture = 0;

	this->stacks = stacks;
	points.push_back(new Point(initx, altura, initz, stacks));
	ponto.push_back(0);
	ponto.push_back(0);
	ponto.push_back(1);
	normais.push_back(ponto);
	ponto.clear();

	for (int i = 1; i < 26; i++) {
		switch (mov) {
		case 0:
			initx += delta;
			points.push_back(new Point(initx, altura, initz, stacks));
			ponto.push_back(0);
			ponto.push_back(0);
			ponto.push_back(1);
			normais.push_back(ponto);
			ponto.clear();

			break;

		case 1:
			initz -= delta;
			points.push_back(new Point(initx, altura, initz, stacks));
			ponto.push_back(1);
			ponto.push_back(0);
			ponto.push_back(0);
			normais.push_back(ponto);
			ponto.clear();
			break;

		case 2:
			initx -= delta;
			points.push_back(new Point(initx, altura, initz, stacks));
			ponto.push_back(0);
			ponto.push_back(0);
			ponto.push_back(-1);
			normais.push_back(ponto);
			ponto.clear();
			break;

		case 3:
			initz += delta;
			points.push_back(new Point(initx, altura, initz, stacks));
			ponto.push_back(-1);
			ponto.push_back(0);
			ponto.push_back(0);
			normais.push_back(ponto);
			ponto.clear();
			break;

		case 4:
			points.push_back(
					new Point(sin(angle * deg2rad4) / 4.0, 1.0,
							cos(angle * deg2rad4) / 4.0, stacks));
			ponto.push_back(sin((angle-100) * deg2rad4));
			ponto.push_back(-0.5);
			ponto.push_back(cos((angle-100) * deg2rad4));
			normais.push_back(ponto);
			ponto.clear();
			angle += step;
			break;
		}

		if (i == 3) {
			mov = 1;
			points.push_back(new Point(initx, altura, initz, stacks));
			ponto.push_back(1);
			ponto.push_back(0);
			ponto.push_back(0);
			normais.push_back(ponto);
			ponto.clear();
		}
		if (i == 6) {
			mov = 2;
			points.push_back(new Point(initx, altura, initz, stacks));
			ponto.push_back(0);
			ponto.push_back(0);
			ponto.push_back(-1);
			normais.push_back(ponto);
			ponto.clear();
		}
		if (i == 9) {
			mov = 3;
			points.push_back(new Point(initx, altura, initz, stacks));
			ponto.push_back(-1);
			ponto.push_back(0);
			ponto.push_back(0);
			normais.push_back(ponto);
			ponto.clear();
		}
		if (i == 12) {
			mov = 4;
		}
	}

	for (int i = 0; i < 16; i++) {

		points[i]->setStep(*points[j]);
		normalx.push_back((normais[i][0] - normais[j][0]) / stacks);
		normaly.push_back((normais[i][1] - normais[j][1]) / stacks);
		normalz.push_back((normais[i][2] - normais[j][2]) / stacks);
		if (i == 3 || i == 6 || i == 9) {
		}
		else {
			j++;
		}

		points[i]->xtemp = points[i]->x;
		points[i]->ztemp = points[i]->z;
	}

}

void MyRobotDraw::getNormal() {

	float altura = 1.0 / stacks;
	float delta = 1.0 / 3.0;
	float deltax = 0.5 / stacks;

	x = 0;
	y = (0 - (-deltax * delta));
	z = (altura * delta);

}

void MyRobotDraw::draw() {

	float altura = 1.0 / stacks;
	float altura1 = 1.0 / stacks;
	vector<float> ponto;
	vector<vector<float> > vertices;

//	printf("normal0 = %f\nnormal\ = %f\nnormal2 = %f\n", normais[0][0],normais[0][1],normais[0][2]);

	glDisable(GL_CULL_FACE);

	if (wireframe) {
		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
	}

	for (int i = 0; i < 16; i++) {

		points[i]->xtemp = points[i]->x;
		points[i]->ztemp = points[i]->z;
	}

	int a = 0;

	for (float j = 0.0; j < 1;) {

		glBegin(GL_TRIANGLE_STRIP);

		for (int i = 0; i < 16; i++) {

			//glTexCoord2d(   (((double)(j+1)/1.0)),(( (double)(i)/1.0)));
			glNormal3f(normais[i][0] + ((a + 1) * normalx[i]), normais[i][1] + ((a + 1) * normaly[i]),
					normais[i][2] + ((a + 1) * normalz[i]));

			glTexCoord2f(points[i]->xtemp - points[i]->distx + 0.5, 0.5 - (points[i]->ztemp - points[i]->distz));

			glVertex3f(points[i]->xtemp - points[i]->distx, altura,
					points[i]->ztemp - points[i]->distz);

			glNormal3f(normais[i][0] + (a * normalx[i]),  normais[i][1] + (a * normaly[i]),
					normais[i][2] + (a * normalz[i]));

			glTexCoord2f(points[i]->xtemp + 0.5, 0.5 - points[i]->ztemp);

			glVertex3f(points[i]->xtemp, altura - altura1, points[i]->ztemp);

			points[i]->xtemp -= points[i]->distx;
			points[i]->ztemp -= points[i]->distz;
		}

		glEnd();

		altura += altura1;
		j += altura1;
		a++;

	}

	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

	glEnable(GL_CULL_FACE);

}

void MyRobotDraw::setWireframe() {

	if (wireframe) {
		wireframe = false;
	}
	else {
		wireframe = true;
	}
}

void MyRobotDraw::setTexture(int t) {
	texture = t;
}

/**Metodo de Newell para poligonos com numero de vertices arbitrario.
 *
 * Por aconselhamento do professor, utilizamos alternativamente calculo de normais atraves de interpolacao
 */
vector<float> MyRobotDraw::calculaNormais(vector<vector<float> > vertices) {
	vector<float> tmp;
	tmp.push_back(0);
	tmp.push_back(0);
	tmp.push_back(0);

	for (unsigned int i = 0; i < vertices.size(); i++) {
		vector<float> current = vertices[i];
		vector<float> next = vertices[(i + 1) % vertices.size()];

		tmp[0] += ((current[1] - next[1]) * (current[2] + next[2]));
		tmp[1] += ((current[2] - next[2]) * (current[0] + next[0]));
		tmp[2] += ((current[0] - next[0]) * (current[1] + next[1]));

	}

	printf("normal0 = %f\nnormal\ = %f\nnormal2 = %f\n", tmp[0], tmp[1],
			tmp[2]);

	return tmp;
}
