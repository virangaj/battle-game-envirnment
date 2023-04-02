#include <stdio.h>
#include <stdlib.h>
#include "project.h"
#include <GL/glut.h>  
#include <math.h>


// create radar leg
void radarMachineLeg() {

	//leg
	glPushMatrix();
	glColor3f(0.06, 0.28, 0.03);
	glTranslatef(0, 1, 0);
	glRotatef(90, 1, 0, 0);
	cylinderWithCap(0.25, 0.25, 1, 10);
	glPopMatrix();

	//stand
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	cylinderWithCap(0.5, 0.4, 0.1, 10);
	glPopMatrix();
}

//place all the legs
void radarMachineAllLegs() {
	//front left
	glPushMatrix();
	glTranslatef(-1.2, 0, 3);
	radarMachineLeg();
	glPopMatrix();

	//front right
	glPushMatrix();
	glTranslatef(1.2, 0, 3);
	radarMachineLeg();
	glPopMatrix();

	//back left
	glPushMatrix();
	glTranslatef(-1.2, 0, -3);
	radarMachineLeg();
	glPopMatrix();


	//back right
	glPushMatrix();
	glTranslatef(1.2, 0, -3);
	radarMachineLeg();
	glPopMatrix();
}

//create staircase for radar machine
void radarStairCase() {

	for (float i = 0; i < 1; i+=0.2) {
		
		glPushMatrix();
		glTranslatef(0, i, -i);
		glScalef(1, 0.2, 0.2);
		glutSolidCube(1);
		glPopMatrix();
		
	}


	
}

//create antena bars
void anternaBars() {

	glPushMatrix();
	glTranslatef(0, 1.8, 0);
	glScalef(0.2, 3, 0.2);
	glutSolidCube(1);
	glPopMatrix();
}

//create antena sphere
void antenaSphere() {
	//left bar
	glColor3f(0, 0.41, 0.2);

	glPushMatrix();
	glTranslatef(-1.5, 0, 0);
	glRotatef(-30, 0, 0, 1);
	anternaBars();
	glPopMatrix();

	//right bar
	glPushMatrix();
	glTranslatef(1.5, 0, 0);
	glRotatef(30, 0, 0, 1);
	anternaBars();
	glPopMatrix();

	//top square
	glPushMatrix();
	glTranslatef(0, 2.8, 0);
	glutSolidSphere(0.4, 10, 10);
	glPopMatrix();


	//create clipped sphere
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glScalef(3, 1, 3);
	glPushMatrix();
	
	glEnable(GL_CLIP_PLANE0);
	
	double planeEquation[] = { 0.0, -1.0, 0.0, -0.6 }; 
	glClipPlane(GL_CLIP_PLANE0, planeEquation);

	glutSolidSphere(1, 20, 20);
	
	glPopMatrix();
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();
	

}

void antenaHandle() {

	//angle bar
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, 2, 0);
	glRotatef(-30, 0, 0, 1);
	glRotatef(-90, 1, 0, 0);
	cylinderWithCap(0.2, 0.2, 1, 20);
	glPopMatrix();

	//joint
	glPushMatrix();
	glTranslatef(0, 2, -0.2);
	cylinderWithCap(0.2, 0.2, 0.4, 20);
	glPopMatrix();


	//bottom bar
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	cylinderWithCap(0.2, 0.2, 2, 20);
	glPopMatrix();

}

//create radar antena
void radarAntena() {

	antenaHandle();

	glPushMatrix();
	glTranslatef(0.5, 2.5, 0);
	glRotatef(-30, 0, 0, 1);
	antenaSphere();
	glPopMatrix();

}



void completeRadarMachine(float angle) {
	// all the legs
	radarMachineAllLegs();


	//place antena
	glPushMatrix();
	glTranslatef(1, 4, -1);
	glRotatef(angle, 0, 1, 0);
	radarAntena();
	glPopMatrix();


	// staircase
	glPushMatrix();
	glTranslatef(-0.5, 0, 5.5);
	radarStairCase();
	glPopMatrix();

	//radar
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glScalef(1.5, 1.5, 1.5);
	containerBox(1, 0.06, 0.28, 0.03);
	glPopMatrix();
}


//create radar machine
void radarMachine(float angle) {

	glPushMatrix();
	glTranslatef(0, 0, 8);
	glLineWidth(1.4);
	drawFenceRow(3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -8);
	glLineWidth(1.4);
	drawFenceRow(3);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(6, 0, 0);
	glRotatef(90, 0, 1, 0);
	glLineWidth(1.4);
	drawFenceRow(4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6, 0, 0);
	glRotatef(90, 0, 1, 0);
	glLineWidth(1.4);
	drawFenceRow(4);
	glPopMatrix();

	completeRadarMachine(angle);
	
}