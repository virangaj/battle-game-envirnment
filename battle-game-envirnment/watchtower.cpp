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


void base() {
	glPushMatrix();
	glColor4f(1.0f, 0, 0, 0);
	glTranslatef(0, 4, 0);
	glScalef(4, 0.1, 4);
	glutSolidCube(1);
	glPopMatrix();
}

void watchTower() {
	

	//floor base
	base();

	//top base

	//legs
	allTowerLegs();
}