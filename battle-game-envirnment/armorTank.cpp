#include <stdio.h>
#include <stdlib.h>
#include "project.h"
#include <GL/glut.h>  
#include <math.h>


#define PI 3.1415927

//create trapezium hull
void quadTrapizium() {
	//create tank hull
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glRotatef(45, 0, 0, 1);
	cylinder(2, 1.5, 2, 4);
	glPopMatrix();
}

//create bottom hull
void bottomHull() {

	//top box
	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glScalef(6.8, 0.2, 2.2);
	glutSolidCube(1);
	glPopMatrix();


	//top quad
	glPushMatrix();
	glTranslatef(0, 1.2, 0);
	glScalef(3, 0.2, 1);
	quadTrapizium();
	glPopMatrix();

	//middle box
	glPushMatrix();
	glTranslatef(0, 1.1, 0);
	glScalef(9, 0.2, 2.8);
	glutSolidCube(1);
	glPopMatrix();

	//bottom quad
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glScalef(3, 0.2, 1);
	glRotatef(-180, 1, 0, 0);
	quadTrapizium();
	glPopMatrix();

}

//create pentagon
void hexagon() {

	//create tank hull
	glPushMatrix();
	glScalef(1.2, 1, 1);
	glRotatef(-90, 1, 0, 0);
	cylinder(2, 1.5, 0.5, 6);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	glScalef(0.78, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 2);
	glVertex3f(-2, 0, 1);
	glVertex3f(-2, 0, -1);
	glVertex3f(0, 0, -2);
	glVertex3f(2, 0, -1);
	glVertex3f(2, 0, 1);
	glEnd();
	glPopMatrix();

}

void gunBarrelHolder() {

	hexagon();

	glPushMatrix();
	glRotatef(180, 1, 0, 0);
	hexagon();
	glPopMatrix();
}


//create single gun cylinder
void singleGunCylinder() {
	glPushMatrix();
	cylinderWithCap(0.25, 0.25, 4, 20);
	glPopMatrix();
}

//create gun
void tankGunCylinder() {

	glPushMatrix();
	glScalef(0.75, 0.75, 2);
	singleGunCylinder();
	glPopMatrix();

	singleGunCylinder();
}

//create gun turrent
void gunTurrent() {

	//mount minigun
	glPushMatrix();
	glTranslatef(0.5, 0.6, 0.2);
	glScalef(0.2, 0.2, 0.5);
	glRotatef(-90, 0, 1, 0);
	machineGun(0, 0);
	glPopMatrix();

	//gun holder canopy
	glPushMatrix();
	glScalef(1, 1.2, 1.5);
	glColor3f(0.12, 0.17, 0.13);
	gunBarrelHolder();
	glPopMatrix();

	// gun barrel
	tankGunCylinder();

}

//create single tank wheel
void singleTankWheel() {

	float wheelRadius = 1;

	glPushMatrix();
	cylinderWithCap(wheelRadius, wheelRadius, 0.5, 20);
	glPopMatrix();


	float x = 0.0;
	float y = 0.0;
	float angle = 0.0;
	float angle_stepsize = 0.3;

	while (angle < 2 * PI) {
		x = wheelRadius * cos(angle);
		y = wheelRadius * sin(angle);
		glPushMatrix();
		glTranslatef(x, y, 0);
		cylinderWithCap(0.08, 0.08, 0.5, 20);
		glPopMatrix();

		angle = angle + angle_stepsize;
	}
}

//create wheel set
void singleWheelSet(float tankWheel) {

	
	glPushMatrix();
	glRotatef(tankWheel, 0, 0, 1);

	//wheel middle bar
	glPushMatrix();
	glTranslatef(0, 0, -2);
	glColor3f(1, 0, 0);
	cylinderWithCap(0.1, 0.1, 4, 20);
	glPopMatrix();

	//front wheeel
	glPushMatrix();
	glTranslatef(0, 0, 1.4);
	glScalef(0.5, 0.5, 1);
	glColor3f(0, 0.23, 0.23);
	singleTankWheel();
	glPopMatrix();

	//back wheel
	glPushMatrix();
	glTranslatef(0, 0, -1.9);
	glScalef(0.5, 0.5, 1);
	glColor3f(0, 0.23, 0.23);
	singleTankWheel();
	glPopMatrix();

	glPopMatrix();

	
}

//whole wheel set
void wheelSet(float tankWheel) {
	//front set
	glPushMatrix();
	glTranslatef(2, 0, 0);
	singleWheelSet(tankWheel);
	glPopMatrix();

	//back set
	glPushMatrix();
	glTranslatef(-2, 0, 0);
	singleWheelSet(tankWheel);
	glPopMatrix();

	//middle set
	glPushMatrix();
	singleWheelSet(tankWheel);
	glPopMatrix();
}

//assemble the tank
void tankBody(float tankRurrent) {

	//place gun turrent
	glPushMatrix();
	glTranslatef(1, 2, 0);
	glScalef(0.8, 0.8, 0.8);
	glRotatef(-tankRurrent, 0, 1, 0);
	gunTurrent();
	glPopMatrix();

	//place bottom hull
	glPushMatrix();
	glScalef(0.8, 1, 1.2);
	glColor3f(0.02, 0.15, 0.07);
	bottomHull();	
	glPopMatrix();

	//place wheel cover
	glPushMatrix();
	glTranslatef(0, 0.4, 0);
	glScalef(5.2, 0.6, 2.5);
	glColor3f(0.12, 0.17, 0.13);
	glutSolidCube(1);
	glPopMatrix();
}

void armorTank(float tankWheel, float tankRurrent) {
	glPushMatrix();
	glTranslatef(0, 0.3, 0);


	glPushMatrix();
	glTranslatef(0, -0.2, 0);
	tankBody(tankRurrent);
	glPopMatrix();

	wheelSet(tankWheel);

	glPopMatrix();
}