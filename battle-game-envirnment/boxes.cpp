#include <stdio.h>
#include <stdlib.h>
#include "project.h"
#include <GL/glut.h>  
#include <math.h>


float con_length = 6.0;
float con_width = 2.0;

void borderLength(float r, float g, float b) {
	glPushMatrix();
	glTranslatef(0, -1, 0);
	glColor3f(r, g, b);
	glScalef(con_length, 0.1, 0.1);
	glutSolidCube(1);
	glPopMatrix();
}

void borderWidth(float r, float g, float b) {
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glColor3f(r, g, b);
	glScalef(0.1, con_width, 0.1);
	glutSolidCube(1);
	glPopMatrix();
}


void containerBoxSide(float r, float g, float b) {

	
	//bottom border
	borderLength(r, g, b);
	//top border
	glPushMatrix();
	glTranslatef(0, 2, 0);
	borderLength(r, g, b);
	glPopMatrix();

	//left border
	glPushMatrix();
	glTranslatef(-con_length/2, 0, 0);
	borderWidth(r, g, b);
	glPopMatrix();

	//right border
	glPushMatrix();
	glTranslatef(con_length / 2, 0, 0);
	borderWidth(r, g, b);
	glPopMatrix();
	

	//side panel
	glPushMatrix();
	glColor3f(r, g, b);
	glScalef(con_length, con_width, 0.01);
	glutSolidCube(1);
	glPopMatrix();



	//half circles
	for (float i = -3; i < 3; i+=0.3) {
		glPushMatrix();
		glColor3f(r+0.19, g+0.25, b+0.35);
		glTranslatef(i, 1, -0.08);
		glRotatef(90, 1, 0, 0);
		halfCylinderWithCaps(0.1, 0.1, 2, 20);
		glPopMatrix();
	}
	
	
}

void containerBoxfrontFaceDoor(float r, float g, float b) {
	//side

	glPushMatrix();
	glTranslatef(con_width / 4, con_width / 2, 0);

	glPushMatrix();
	glTranslatef(0, 0, -0.02);
	glColor3f(r, g, b);
	glScalef(con_width / 2, con_width, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	//embosed part
	for (float i = -con_width + 1.5; i < con_width - 1; i += 0.5) {

		glPushMatrix();
		glTranslatef(0, i, 0);
		glColor3f(r+0.19, g+0.25, b+0.35);
		glScalef(con_width / 2, con_width / 8, 0.1);
		glutSolidCube(1);
		glPopMatrix();

		//handl holder torus
		glPushMatrix();
		glColor3f(r, g, b);
		glTranslatef(-0.2, i, 0.08);
		glScalef(0.3, 2, 0.3);
		glRotatef(90, 1, 0, 0);
		glutSolidTorus(0.01, 0.1, 20, 20);
		glPopMatrix();

		//handl holder torus
		glPushMatrix();
		glColor3f(r, g, b);
		glTranslatef(0.2, i, 0.08);
		glScalef(0.3, 2, 0.3);
		glRotatef(90, 1, 0, 0);
		glutSolidTorus(0.01, 0.1, 20, 20);
		glPopMatrix();
	}

	//cylinder handles
	glPushMatrix();
	glColor3f(r+0.19, g+0.25, b+0.35);
	glTranslatef(-0.2, -con_width / 2, 0.08);
	glRotatef(-90, 1, 0, 0);
	cylinderWithCap(0.02, 0.02, con_width, 20);
	glPopMatrix();

	//cylinder handles
	glPushMatrix();
	glColor3f(r+0.19, g+0.25, b+0.35);
	glTranslatef(0.2, -con_width / 2, 0.08);
	glRotatef(-90, 1, 0, 0);
	cylinderWithCap(0.02, 0.02, con_width, 20);
	glPopMatrix();

	glPopMatrix();



}


// box lengthy
void conteinerSurBox(float r, float g, float b) {

	glPushMatrix();
	glTranslatef(0, con_width / 2, 0);
	glRotatef(90, 0, 1, 0);
	//top
	glPushMatrix();
	glTranslatef(0, con_width / 2, 0);
	glRotatef(-90, 1, 0, 0);
	containerBoxSide(r, g, b);
	glPopMatrix();


	//bottom
	glPushMatrix();
	glTranslatef(0, -con_width / 2, 0);
	glRotatef(90, 1, 0, 0);
	containerBoxSide(r, g, b);
	glPopMatrix();


	//right
	glPushMatrix();
	glTranslatef(0, 0, -con_width / 2);
	glRotatef(180, 0, 1, 0);
	containerBoxSide(r, g, b);
	glPopMatrix();


	//left
	glPushMatrix();
	glTranslatef(0, 0, con_width / 2);
	containerBoxSide(r, g, b);
	glPopMatrix();

	glPopMatrix();

}


void containerBox(int open, float r, float g, float b) {
	glPushMatrix();
	conteinerSurBox(r, g, b);


	//front left door
	if (open == 1) {
		glPushMatrix();
		glTranslatef(-con_width / 2, 0, con_length / 2);
		glRotatef(-60, 0, 1, 0);
		containerBoxfrontFaceDoor(r, g, b);
		glPopMatrix();
	}
	else {
		glPushMatrix();
		glTranslatef(-con_width / 2, 0, con_length / 2);
		containerBoxfrontFaceDoor(r, g, b);
		glPopMatrix();
	}

	//front right door
	glPushMatrix();
	glTranslatef(0, 0, con_length / 2);
	containerBoxfrontFaceDoor(r, g, b);
	glPopMatrix();

	//back left door 
	glPushMatrix();
	glTranslatef(con_width / 2, 0, -con_length / 2);
	glRotatef(180, 0, 1, 0);
	containerBoxfrontFaceDoor(r, g, b);
	glPopMatrix();

	//back right root
	glPushMatrix();
	glTranslatef(0, 0, -con_length / 2);
	glRotatef(180, 0, 1, 0);
	containerBoxfrontFaceDoor(r, g, b);
	glPopMatrix();


	glPopMatrix();

	//containerBoxfrontFace();

}




//wooden box Row
void woodenBoxSingleRaw() {
	float n = 2;
	glPushMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.42, 0.251, 0.129);
	glVertex3f(-n, 0, n / 4);

	glColor3f(0.11, 0.047, 0);
	glVertex3f(n, 0, n / 4);

	glColor3f(0.42, 0.251, 0.129);
	glVertex3f(n, 0, -n / 4);

	glColor3f(0.11, 0.047, 0);
	glVertex3f(-n, 0, -n / 4);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glVertex3f(-n, 0, n / 4);
	glVertex3f(n, 0, n / 4);

	glVertex3f(-n, 0, -n / 4);
	glVertex3f(n, 0, -n / 4);

	glVertex3f(n, 0, -n / 4);
	glVertex3f(n, 0, n / 4);

	glVertex3f(-n, 0, -n / 4);
	glVertex3f(-n, 0, n / 4);

	glEnd();
	glLineWidth(1);
	glPopMatrix();

	glPopMatrix();
}

//box border
void drawBoxBorder() {
	glPushMatrix();
	glColor3f(0.922, 0.565, 0.314);
	glScalef(4, 0.1, 0.2);
	glutSolidCube(1);
	glPopMatrix();
}

//box side
void woodenBoxSide() {
	float n = 2;
	glPushMatrix();

	glPushMatrix();
	for (float i = -(3 * n / 4); i < n; i += n / 4) {
		glPushMatrix();
		glTranslatef(0, 0, i);
		woodenBoxSingleRaw();
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	for (float i = 0; i < 360; i += 90) {
		glPushMatrix();
		glRotatef(i, 0, 1, 0);
		glTranslatef(0, 0.05, -2);
		drawBoxBorder();
		glPopMatrix();
	}
	glPopMatrix();

	glPopMatrix();
}

//full bpx
void woodenBox() {
	glPushMatrix();
	for (float i = 0; i < 360; i += 90) {
		glPushMatrix();
		glRotatef(i, 0, 0, 1);
		glTranslatef(0, 2, 0);
		woodenBoxSide();
		glPopMatrix();
	}

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 2, 0);
	woodenBoxSide();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, 2, 0);
	woodenBoxSide();
	glPopMatrix();

	glPopMatrix();
}