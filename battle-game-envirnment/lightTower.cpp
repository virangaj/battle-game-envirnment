#include <stdlib.h>
#include "project.h"
#include <GL/glut.h>  
#include <math.h>


//create lamp body
void lampTowerBody() {

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glColor3f(0.48, 0.47, 0.46);
	cylinderWithCap(0.25, 0.065, 5, 10);
	glPopMatrix();
}

void lighLeak(float end) {

	glBegin(GL_LINES);
	glLineWidth(2);
	glColor3f(0.35, 0.7, 0.95);
	glVertex3f(0, 0, 0);
	glVertex3f(end, 0, 0);
	glEnd();
}


//create lamb section
void lampSection(int i, int leaks) {

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	cylinderWithCap(0.065, 0.25, 0.25, 10);
	glPopMatrix();

	//light
	
	float end = 0;
	
	if (i % 10 != 0) {
		glPushMatrix();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		//light beam
		glTranslatef(0, -0.2, 0);
		glRotatef(90, 1, 0, 0);
		glColor4f(0.93, 1, 0, 0.4);
		cylinderWithCap(0.1, 1, 4.8, 10);
		

		glDisable(GL_BLEND);
		glPopMatrix();
		
	}

	//triiger light leak
	if (i % 5 == 0) {
		for (float j = 0; j < 0.2; j += 0.1) {
			end = j;
		}
	}
	if (leaks == 1) {
		//light leaks
		glPushMatrix();
		glTranslatef(0.4, -0.2, 0);
		glRotatef(-30, 0, 0, 1);
		lighLeak(end);
		glPopMatrix();


		glPushMatrix();
		glTranslatef(-0.4, -0.4, 0);
		glRotatef(50, 0, 0, 1);
		lighLeak(end);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -0.4, 0.4);
		glRotatef(90, 0, 1, 0);
		glRotatef(30, 0, 0, 1);
		lighLeak(end);
		glPopMatrix();


		glPushMatrix();
		glTranslatef(0, -0.4, -0.4);
		glRotatef(90, 0, 1, 0);
		glRotatef(-30, 0, 0, 1);
		lighLeak(end);
		glPopMatrix();
	}
	
	
}



//create lamp handle
void lampHand(int i, int leaks) {

	//lamp bend hand
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glRotatef(-30, 1, 0, 0);
	glColor3f(0.48, 0.47, 0.46);
	cylinderWithCap(0.065, 0.065, 1, 10);
	glPopMatrix();


	//lamp holder
	glPushMatrix();
	glTranslatef(0.8, 0.5, 0);
	glRotatef(90, 1, 0, 0);
	glColor3f(0.48, 0.47, 0.46);
	cylinderWithCap(0.025, 0.025, 0.3, 10);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.8, 0.2, 0);
	lampSection(i, leaks);
	glPopMatrix();
}



//create lamp base section
void lampTowerBase() {
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glColor3f(0.25, 0.25, 0.25);
	cylinderWithCap(1, 0.5, 0.25, 10);
	glPopMatrix();
}

void lampTower(int i, int leaks) {
	glPushMatrix();
	glTranslatef(0, 4.8, 0);
	lampHand(i, leaks);
	glPopMatrix();


	glPushMatrix();
	lampTowerBody();
	glPopMatrix();

	lampTowerBase();

}