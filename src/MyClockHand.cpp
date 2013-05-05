/*
 * MyClockHand.cpp
 *
 *  Created on: May 5, 2013
 *      Author: wso277
 */

#include "MyClockHand.h"

MyClockHand::MyClockHand() {
	angPointer = 360;
}

void MyClockHand::draw() {

	pointer.draw();

}

void MyClockHand::setAngle(float angle) {

	angPointer = 360 - angle;
}

float MyClockHand::getAngle() {
	return angPointer;
}
