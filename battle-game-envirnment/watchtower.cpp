#include "project.h"
#include <GL/glut.h> 


// single tower leg
void TowerLeg() {
	glPushMatrix();
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glTranslatef(0, 2.75, 0);
	glScalef(0.2, 5.5, 0.2);
	glutSolidCube(1);
	glPopMatrix();
}

//all tower legs
void allTowerLegs(){
	
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
}

// single ladder leg
void ladderLeg() {
	glPushMatrix();
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
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
		glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
		glTranslatef(0, 0.25*i, 0);
		glScalef(0.4, 0.1, 0.1);
		glutSolidCube(1);
		glPopMatrix();

	}
}


// floor base
void towerFloorBase() {
	glPushMatrix();
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glScalef(4, 0.1, 4);
	glutSolidCube(1);
	glPopMatrix();
}


// roof side traingle
void roofSide() {
	
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glVertex3f(0, 1, 0);
	glVertex3f(-2, 0, 2);
	glVertex3f(2, 0, 2);
	glEnd();
}

// whole roof
void roof() {
	for (int i = 0; i < 4; i++) {

		glPushMatrix();
		glRotatef(90*i, 0, 1, 0);
		roofSide();
		glPopMatrix();

	}
}

// side fence implementation
void sideFence() {

	//fence top bar
	glPushMatrix();
	glColor4f(1.0f, 0, 0, 1);
	glScalef(4, 0.1, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	//middle vertical bars
	for (int i = -3; i < 4; i++) {

		glPushMatrix();
		glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
		glTranslatef(0.5*i, 0, 0);
		glScalef(0.1, 0.5, 0.1);
		glutSolidCube(1);
		glPopMatrix();

	}

}

// side fence implementation
void frontHalfFence() {

	//fence top bar
	glPushMatrix();
	glColor4f(1.0f, 0, 0, 1);
	glScalef(1.4, 0.1, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	//middle vertical bars
	for (int i = -1.5; i < 1.5; i++) {

		glPushMatrix();
		glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
		glTranslatef(0.5 * i, 0, 0);
		glScalef(0.1, 0.5, 0.1);
		glutSolidCube(1);
		glPopMatrix();

	}

}


// fence around the base
void fence() {
	
	//back
	glPushMatrix();
	glTranslatef(0, 0, -1.8);
	sideFence();
	glPopMatrix();

	//left
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, -1.8);
	sideFence();
	glPopMatrix();

	//right
	glPushMatrix();
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, -1.8);
	sideFence();
	glPopMatrix();

	//front left
	glPushMatrix();
	glTranslatef(-1, 0, 1.8);
	frontHalfFence();
	glPopMatrix();

	//front right
	glPushMatrix();
	glTranslatef(1, 0, 1.8);
	frontHalfFence();
	glPopMatrix();
	

}

void watchTower() {
	//floor base
	glPushMatrix();
	glTranslatef(0, 4, 0);
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