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
			ponto.push_back(sin(angle * deg2rad4));
			ponto.push_back(0);
			ponto.push_back(cos(angle * deg2rad4));
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
			//printf("size: %d", points.size());
		}
	}

	//printf("size: %d", points.size());

	for (int i = 0; i < 16; i++) {

		points[i]->setStep(*points[j]);
		normalx.push_back((normais[i][0] - normais[j][0]) / stacks);
		normalz.push_back((normais[i][2] - normais[j][2]) / stacks);
		if (i == 3 || i == 6 || i == 9) {
		}
		else {
			j++;
		}

		points[i]->xtemp = points[i]->x;
		points[i]->ztemp = points[i]->z;
	}

	/*float alturatmp = 1.0 / stacks;
	 float altura1 = 1.0 / stacks;
	 vector<float> ponto;
	 vector<vector<float> > vertices;

	 for (float j = 0.0; j < 1;) {

	 for (int i = 0; i <= 13; i++) {

	 if (j == 0) {
	 ponto.push_back(points[i]->xtemp - points[i]->distx);
	 ponto.push_back(alturatmp);
	 ponto.push_back(points[i]->ztemp - points[i]->distz);
	 vertices.push_back(ponto);
	 ponto.clear();

	 ponto.push_back(points[i + 1]->xtemp - points[i + 1]->distx);
	 ponto.push_back(alturatmp);
	 ponto.push_back(points[i + 1]->ztemp - points[i + 1]->distz);
	 vertices.push_back(ponto);
	 ponto.clear();

	 ponto.push_back(points[i + 1]->xtemp - points[i + 1]->distx);
	 ponto.push_back(alturatmp - altura1);
	 ponto.push_back(points[i + 1]->ztemp - points[i + 1]->distz);
	 vertices.push_back(ponto);
	 ponto.clear();

	 ponto.push_back(points[i]->xtemp);
	 ponto.push_back(alturatmp - altura1);
	 ponto.push_back(points[i]->ztemp);
	 vertices.push_back(ponto);
	 ponto.clear();

	 if (i > 0) {
	 ponto.push_back(points[i - 1]->xtemp);
	 ponto.push_back(alturatmp - altura1);
	 ponto.push_back(points[i - 1]->ztemp);
	 vertices.push_back(ponto);
	 ponto.clear();

	 ponto.push_back(points[i - 1]->xtemp);
	 ponto.push_back(alturatmp);
	 ponto.push_back(points[i - 1]->ztemp);
	 vertices.push_back(ponto);
	 ponto.clear();
	 }

	 if (i == 0) {
	 ponto.push_back(points[12]->xtemp);
	 ponto.push_back(alturatmp - altura1);
	 ponto.push_back(points[12]->ztemp);
	 vertices.push_back(ponto);
	 ponto.clear();

	 ponto.push_back(points[12]->xtemp);
	 ponto.push_back(alturatmp);
	 ponto.push_back(points[12]->ztemp);
	 vertices.push_back(ponto);
	 ponto.clear();
	 }

	 normais.push_back(calculaNormais(vertices));
	 vertices.clear();
	 } else {
	 ponto.push_back(points[i]->xtemp - points[i]->distx);
	 ponto.push_back(alturatmp);
	 ponto.push_back(points[i]->ztemp - points[i]->distz);
	 vertices.push_back(ponto);
	 ponto.clear();

	 ponto.push_back(points[i + 1]->xtemp - points[i + 1]->distx);
	 ponto.push_back(alturatmp);
	 ponto.push_back(points[i + 1]->ztemp - points[i + 1]->distz);
	 vertices.push_back(ponto);
	 ponto.clear();

	 ponto.push_back(points[i + 1]->xtemp - points[i + 1]->distx);
	 ponto.push_back(alturatmp - altura1);
	 ponto.push_back(points[i + 1]->ztemp - points[i + 1]->distz);
	 vertices.push_back(ponto);
	 ponto.clear();

	 ponto.push_back(points[i]->xtemp);
	 ponto.push_back(alturatmp - altura1);
	 ponto.push_back(points[i]->ztemp);
	 vertices.push_back(ponto);
	 ponto.clear();

	 ponto.push_back(points[i]->xtemp + points[i]->distx);
	 ponto.push_back(alturatmp - (2 * altura1));
	 ponto.push_back(points[i]->ztemp + points[i]->distz);
	 vertices.push_back(ponto);
	 ponto.clear();

	 if (i > 0) {
	 ponto.push_back(points[i - 1]->xtemp);
	 ponto.push_back(alturatmp - altura1);
	 ponto.push_back(points[i - 1]->ztemp);
	 vertices.push_back(ponto);
	 ponto.clear();

	 ponto.push_back(
	 points[i - 1]->xtemp + points[i - 1]->distx);
	 ponto.push_back(alturatmp - (2 * altura1));
	 ponto.push_back(
	 points[i - 1]->ztemp + points[i - 1]->distz);
	 vertices.push_back(ponto);
	 ponto.clear();
	 }
	 if (i == 0) {
	 ponto.push_back(points[12]->xtemp);
	 ponto.push_back(alturatmp - altura1);
	 ponto.push_back(points[12]->ztemp);
	 vertices.push_back(ponto);
	 ponto.clear();

	 ponto.push_back(
	 points[12]->xtemp + points[12]->distx);
	 ponto.push_back(alturatmp - (2 * altura1));
	 ponto.push_back(
	 points[12]->ztemp + points[12]->distz);
	 vertices.push_back(ponto);
	 ponto.clear();
	 }

	 normais.push_back(calculaNormais(vertices));
	 vertices.clear();
	 }

	 points[i]->xtemp -= points[i]->distx;
	 points[i]->ztemp -= points[i]->distz;

	 }

	 alturatmp += altura1;
	 j += altura1;

	 }*/

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

	for (int i = 0; i < 16; i++) {

		points[i]->xtemp = points[i]->x;
		points[i]->ztemp = points[i]->z;
	}

	for (float j = 0.0; j < 1;) {

		glBegin(GL_TRIANGLE_STRIP);
		for (int i = 0; i < 16; i++) {

			glNormal3f(normais[i][0] + ((i + 1) * normalx[i]), 0,
					normais[i][2] + ((i + 1) * normalz[i]));

			glVertex3f(points[i]->xtemp - points[i]->distx, altura,
					points[i]->ztemp - points[i]->distz);

			glNormal3f(normais[i][0] + (i * normalx[i]), 0,
					normais[i][2] + (i * normalz[i]));

			glVertex3f(points[i]->xtemp, altura - altura1, points[i]->ztemp);

			points[i]->xtemp -= points[i]->distx;
			points[i]->ztemp -= points[i]->distz;

		}

		glEnd();

		altura += altura1;
		j += altura1;

	}

}

/**Metodo de Newell para poligonos com numero de vertices arbitrario.
 *
 * Por aconselhamento do professor, utilizamos alternativamente calculo atraves de interpolacao
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
