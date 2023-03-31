#include <stdlib.h>
#include "project.h"
#include <GL/glut.h>  
#include <math.h>


//create lamp body
void lampTowerBody() {

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glColor3f(1, 0, 0);
	cylinderWithCap(0.25, 0.065, 5, 10);
	glPopMatrix();
}

//create lamb section
void lampSection(int i) {

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	cylinderWithCap(0.065, 0.25, 0.25, 10);
	glPopMatrix();

	
	
	//light
	glPushMatrix();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	if (i % 10 != 0) {
		glTranslatef(0, -0.2, 0);
		glRotatef(90, 1, 0, 0);
		glColor4f(0.93, 1, 0, 0.4);
		cylinderWithCap(0.065, 2, 4.8, 10);
	}
	
	glPopMatrix();
}



//create lamp handle
void lampHand(int i) {

	//lamp bend hand
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glRotatef(-30, 1, 0, 0);
	glColor3f(0, 1, 0);
	cylinderWithCap(0.065, 0.065, 1, 10);
	glPopMatrix();


	//lamp holder
	glPushMatrix();
	glTranslatef(0.8, 0.5, 0);
	glRotatef(90, 1, 0, 0);
	glColor3f(0, 0, 1);
	cylinderWithCap(0.025, 0.025, 0.3, 10);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.8, 0.2, 0);
	lampSection(i);
	glPopMatrix();
}



//create lamp base section
void lampTowerBase() {
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glColor3f(0.25, 0.25, 0.25);
	cylinderWithCap(1, 0.5, 0.25, 5);
	glPopMatrix();
}

void lampTower(int i) {
	glPushMatrix();
	glTranslatef(0, 4.8, 0);
	lampHand(i);
	glPopMatrix();


	glPushMatrix();
	lampTowerBody();
	glPopMatrix();

	lampTowerBase();

}