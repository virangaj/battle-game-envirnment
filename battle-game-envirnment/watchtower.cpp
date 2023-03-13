#include "project.h"
#include <GL/glut.h> 



void TowerLeg() {
	glPushMatrix();
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glTranslatef(0, 2.5, 0);
	glScalef(0.2, 5, 0.2);
	glutSolidCube(1);
	glPopMatrix();
}


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


void ladderLeg() {
	glPushMatrix();
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glTranslatef(0, 2, 0);
	glScalef(0.1, 4, 0.1);
	glutSolidCube(1);
	glPopMatrix();
}

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
		glColor4f(1.0f, 0, 0, 0);
		glTranslatef(0, 0.25*i, 0);
		glScalef(0.4, 0.1, 0.1);
		glutSolidCube(1);
		glPopMatrix();

	}
}

void base() {
	glPushMatrix();
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glScalef(4, 0.1, 4);
	glutSolidCube(1);
	glPopMatrix();
}

void watchTower() {
	

	//floor base
	glPushMatrix();
	glTranslatef(0, 4, 0);
	base();
	glPopMatrix();

	//top base

	//legs
	allTowerLegs();

	glPushMatrix();
	glTranslatef(0, 0, 2);
	ladder();
	glPopMatrix();
}