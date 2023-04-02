#include "project.h"
#include <GL/glut.h> 


// single tower leg
void TowerLeg() {
	glPushMatrix();
	glColor3f(0.6, 0.38, 0.17);
	glTranslatef(0, 2.75, 0);
	glScalef(0.2, 5.5, 0.2);
	glutSolidCube(1);
	glPopMatrix();
}

// cross
void cross() {

	//left turn
	glPushMatrix();
	glRotatef(-45, 0, 0, 1);
	glScalef(1, 0.5, 1);
	TowerLeg();
	glPopMatrix();

	//right turn
	glPushMatrix();
	glTranslatef(2, 0, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(1, 0.5, 1);
	TowerLeg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 0, 0);
	glRotatef(90, 0, 0, 1);
	glScalef(1, 0.38, 1);
	TowerLeg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 2, 0);
	glRotatef(90, 0, 0, 1);
	glScalef(1, 0.38, 1);
	TowerLeg();
	glPopMatrix();

}

//all tower legs
void allTowerLegs() {

	//front left leg
	glPushMatrix();
	glTranslatef(-1, 0, 1);
	TowerLeg();
	glPopMatrix();


	//front right leg
	glPushMatrix();
	glTranslatef(1, 0, 1);
	TowerLeg();
	glPopMatrix();

	//back left leg
	glPushMatrix();
	glTranslatef(-1, 0, -1);
	TowerLeg();
	glPopMatrix();

	//back right leg	
	glPushMatrix();
	glTranslatef(1, 0, -1);
	TowerLeg();
	glPopMatrix();


	//front cross
	glPushMatrix();
	glTranslatef(-1, 1, 1);
	cross();
	glPopMatrix();

	//back cross
	glPushMatrix();
	glTranslatef(-1, 1, -1);
	cross();
	glPopMatrix();

	// leftt cross
	glPushMatrix();
	glTranslatef(-1, 1, 1);
	glRotatef(90, 0, 1, 0);
	cross();
	glPopMatrix();


	// right cross
	glPushMatrix();
	glTranslatef(1, 1, 1);
	glRotatef(90, 0, 1, 0);
	cross();
	glPopMatrix();
}

// single ladder leg
void ladderLeg() {
	glPushMatrix();
	glColor3f(0.6, 0.38, 0.17);
	glTranslatef(0, 2, 0);
	glScalef(0.1, 4, 0.1);
	glutSolidCube(1);
	glPopMatrix();
}


//whole ladder
void ladder() {

	//left leg
	glPushMatrix();
	glTranslatef(-0.2, 0, 0);
	ladderLeg();
	glPopMatrix();

	//right legs
	glPushMatrix();
	glTranslatef(0.2, 0, 0);
	ladderLeg();
	glPopMatrix();

	//middle bars
	for (int i = 0; i < 16; i++) {

		glPushMatrix();
		glColor3f(0.6, 0.38, 0.17);
		glTranslatef(0, 0.25 * i, 0);
		glScalef(0.4, 0.1, 0.1);
		glutSolidCube(1);
		glPopMatrix();

	}
}


// floor base
void towerFloorBase() {
	glPushMatrix();
	glColor3f(0.6, 0.38, 0.17);
	glScalef(4, 0.1, 4);
	glutSolidCube(1);
	glPopMatrix();
}


// roof side traingle
void roofSide() {

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.38, 0.17);
	glVertex3f(0, 1, 0);
	glVertex3f(-2, 0, 2);
	glVertex3f(2, 0, 2);
	glEnd();
}

// whole roof
void roof() {
	for (int i = 0; i < 4; i++) {

		glPushMatrix();
		glRotatef(90 * i, 0, 1, 0);
		roofSide();
		glPopMatrix();

	}
}

// side fence implementation
void sideFence() {

	//fence top bar
	glPushMatrix();
	glColor4f(0.1, 0.02, 0.04, 1);
	glScalef(4, 0.1, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	//middle vertical bars
	for (int i = -3; i < 4; i++) {

		glPushMatrix();
		glColor3f(0.6, 0.38, 0.17);
		glTranslatef(0.5 * i, 0, 0);
		glScalef(0.1, 0.8, 0.1);
		glutSolidCube(1);
		glPopMatrix();

	}

}

// side fence implementation
void frontHalfFence() {

	//fence top bar
	glPushMatrix();
	glColor4f(0.1, 0.02, 0.04, 1);
	glScalef(1.4, 0.1, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	//middle vertical bars
	for (int i = -1.5; i < 1.5; i++) {

		glPushMatrix();
		glColor3f(0.6, 0.38, 0.17);
		glTranslatef(0.5 * i, 0, 0);
		glScalef(0.1, 0.8, 0.1);
		glutSolidCube(1);
		glPopMatrix();

	}

}


// fence around the base
void fence() {
	
	//back
	glPushMatrix();
	glTranslatef(0, 0.2, -1.8);
	sideFence();
	glPopMatrix();

	//left
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0.2, -1.8);
	sideFence();
	glPopMatrix();

	//right
	glPushMatrix();
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0.2, -1.8);
	sideFence();
	glPopMatrix();

	//front left
	glPushMatrix();
	glTranslatef(-1, 0.2, 1.8);
	frontHalfFence();
	glPopMatrix();

	//front right
	glPushMatrix();
	glTranslatef(1, 0.2, 1.8);
	frontHalfFence();
	glPopMatrix();
	

}

void watchTower(float angle) {
	//floor base
	glPushMatrix();
	glTranslatef(0, 4, 0);
	glPushMatrix();
	glTranslatef(0, 0, -0.5);
	glScalef(0.25, 0.25, 0.25);
	glRotatef(90, 0, 1, 0);
	machineGun(angle, 1);
	glPopMatrix();
	towerFloorBase();
	glPopMatrix();

	//roof
	glPushMatrix();
	glTranslatef(0, 5.35, 0);
	roof();
	glPopMatrix();

	//legs
	allTowerLegs();

	//ladder
	glPushMatrix();
	glTranslatef(0, 0, 2);
	ladder();
	glPopMatrix();

	//fence
	glPushMatrix();
	glTranslatef(0, 4.2, 0);
	fence();
	glPopMatrix();
}