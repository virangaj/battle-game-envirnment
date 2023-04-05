#include "project.h"
#include <GL/glut.h> 
#include <math.h>
float towerHeight = 20;



// single tower leg
void antenaTowerLeg(int r, int g, int b) {
	glPushMatrix();
	glColor3f(r, g, b);
	glTranslatef(0, 2.75, 0);
	glScalef(0.2, 5.5, 0.2);
	glutSolidCube(1);
	glPopMatrix();
}


// antena cross
void antenaCross(int r, int g, int b) {

	//left turn
	glPushMatrix();
	glRotatef(-45, 0, 0, 1);
	glScalef(1, 0.5, 1);
	antenaTowerLeg(r, g, b);
	glPopMatrix();

	//right turn
	glPushMatrix();
	glTranslatef(2, 0, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(1, 0.5, 1);
	antenaTowerLeg(r, g, b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 0, 0);
	glRotatef(90, 0, 0, 1);
	glScalef(1, 0.38, 1);
	antenaTowerLeg(r, g, b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 2, 0);
	glRotatef(90, 0, 0, 1);
	glScalef(1, 0.38, 1);
	antenaTowerLeg(r, g, b);
	glPopMatrix();

}

//create antena single section
void antenaTowerOneSection(int r, int g, int b) {
	//front left leg
	glPushMatrix();
	glTranslatef(-1, 0, 1);
	glScalef(0.5, 0.4, 0.5);
	antenaTowerLeg(r, g, b);
	glPopMatrix();


	//front right leg
	glPushMatrix();
	glTranslatef(1, 0, 1);
	glScalef(0.5, 0.4, 0.5);
	antenaTowerLeg(r, g, b);
	glPopMatrix();

	//back left leg
	glPushMatrix();
	glTranslatef(-1, 0, -1);
	glScalef(0.5, 0.4, 0.5);
	antenaTowerLeg(r, g, b);
	glPopMatrix();

	//back right leg	
	glPushMatrix();
	glTranslatef(1, 0, -1);
	glScalef(0.5, 0.4, 0.5);
	antenaTowerLeg(r, g, b);
	glPopMatrix();


	//front cross
	glPushMatrix();
	glTranslatef(-1, 0, 1);
	antenaCross(r, g, b);
	glPopMatrix();

	//back cross
	glPushMatrix();
	glTranslatef(-1, 0, -1);
	antenaCross(r, g, b);
	glPopMatrix();

	// leftt cross
	glPushMatrix();
	glTranslatef(-1, 0, 1);
	glRotatef(90, 0, 1, 0);
	antenaCross(r, g, b);
	glPopMatrix();


	// right cross
	glPushMatrix();
	glTranslatef(1, 0, 1);
	glRotatef(90, 0, 1, 0);
	glColor3f(1, 1, 1);
	antenaCross(r, g, b);
	glPopMatrix();
}


//tower top section
void antenaTowerTopSection(float pulse) {




	//antena holder
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(1, 0, 0);
	glScalef(0.2, 0.2, 4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(-1, 0, 0);
	glScalef(0.2, 0.2, 4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(0, 0, 1);
	glScalef(4, 0.2, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(0, 0, -1);
	glScalef(4, 0.2, 0.2);
	glutSolidCube(1);
	glPopMatrix();



	//antena box
	glPushMatrix();
	glScalef(1.5, 1.5, 1.5);
	antenaTowerOneSection(1, 0, 0);
	glPopMatrix();



	//light bulb section
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(1, 4, 1);
	glScalef(0.2, 4, 0.2);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	if (fmod(pulse, 4)) {
		glColor3f(1, 0, 0);
	}
	else {
		glColor3f(0, 0, 0);

	}
	glTranslatef(1, 6, 1);
	glutSolidSphere(0.2, 10, 10);
	glPopMatrix();

	

}

//build tower structure
void towerStructure() {
	for (float i = 0; i < towerHeight; i += 2) {
		glPushMatrix();
		glTranslatef(0, i+ i * 0.1, 0);
		if (fmod(i, 4)) {
			antenaTowerOneSection(1, 0, 0);
		}
		else {
			antenaTowerOneSection(1, 1, 1);
		}
		glPopMatrix();
	}
}


void antenaTower(float pulse) {

	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	glPushMatrix();
	glTranslatef(0, 22, 0);
	antenaTowerTopSection(pulse);
	glPopMatrix();
	towerStructure();
	glPopMatrix();

	//support lines
	glBegin(GL_LINES);
	glLineWidth(6);
	glColor3f(0, 0, 0);
	glVertex3f(-2, 0, 0);
	glVertex3f(-0.5, 10, 0);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(6);
	glColor3f(0, 0, 0);
	glVertex3f(2, 0, 0);
	glVertex3f(0.5, 10, 0);
	glEnd();
}