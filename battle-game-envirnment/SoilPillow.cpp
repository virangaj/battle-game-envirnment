#include <stdio.h>
#include <stdlib.h>
#include "project.h"
#include <GL/glut.h>  
#include <math.h>



void conerGlobe() {
	glPushMatrix();
	glScalef(0.75, 1.25, 1.25);
	glutSolidSphere(1, 50, 50);
	glPopMatrix();
}


// display soil pillow
void soilPillow() {
	

	glPushMatrix();
	glColor3f(0.2, 0.4, 0.2);
	glTranslatef(2.8, 0, 0);
	conerGlobe();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.8, 0, 0);
	conerGlobe();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(0, 0, 0);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 0.7, 3);
	glutSolidTorus(1, 1.2, 50, 50);
	glPopMatrix();


}
