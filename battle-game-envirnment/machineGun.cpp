#include "project.h"
#include <GL/glut.h> 
#include <GL/glut.h>  
#include <math.h>
#define PI 3.1415927



float d = 0.5;
void laser() {
	glBegin(GL_LINES);
	glLineWidth(2);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 100);
	glEnd();
}


void machineGunBarrel() {
	float angle = 0.0;
	float x2 = 0.0;
	float y2 = 0.0;
	//round small barrel
	while (angle < 2 * PI) {
		x2 = (d - 0.1) * cos(angle);
		y2 = (d - 0.1) * sin(angle);
		glPushMatrix();
		glColor3f(0.1, 0.08, 0.08);
		glTranslatef(x2, y2, -1);
		cylinder(0.08, 0.08, 2, 10);
		glPopMatrix();
		angle = angle + PI/3;
	}
	laser();

	//round large baller holder
	glPushMatrix();
	glColor3f(0.4, 0.37, 0.37);
	glTranslatef(0, 0, 0.8);
	cylinderWithCap(d, d, 0.05, 10);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.4, 0.37, 0.37);
	glTranslatef(0, 0, 0.2);
	cylinderWithCap(d, d, 0.05, 10);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.4, 0.37, 0.37);
	glTranslatef(0, 0, -0.4);
	cylinderWithCap(d, d, 0.2, 10);
	glPopMatrix();


}

void miniGunBase() {

	//main barel
	glPushMatrix();
	cylinderWithCap(d, d, 2, 10);
	glPopMatrix();


	//main barel large holder
	glPushMatrix();
	glTranslatef(0, 0, 1.5);
	cylinderWithCap(d+0.2, d+0.2, 0.5, 10);
	glPopMatrix();

	//small side barrel
	glPushMatrix();
	glTranslatef(0.6, -0.2, 0.2);
	cylinderWithCap(d/2, d/2, 1, 10);
	glPopMatrix();

	//small side barrel
	glPushMatrix();
	glTranslatef(-0.6, -0.2, 0.2);
	cylinderWithCap(d / 2, d / 2, 1, 10);
	glPopMatrix();


	//carry handle
	glPushMatrix();
	glTranslatef(0, 0.5, 1);
	glScalef(0.8, 0.5, 0.5);
	glutSolidTorus(0.1, 1, 20, 20);
	glPopMatrix();


	//trigger part
	glPushMatrix();
	glTranslatef(0.4, 0, 0);
	glRotatef(30, 0, 1, 0);
	glScalef(0.4, 0.4, 0.4);
	glutSolidTorus(0.1, 1, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.4, 0, 0);
	glRotatef(-30, 0, 1, 0);
	glScalef(0.4, 0.4, 0.4);
	glutSolidTorus(0.1, 1, 10, 10);
	glPopMatrix();





}

void miniGunLeg() {

	//leg
	glPushMatrix();
	glTranslatef(0, 1.6, 0);
	glRotatef(30, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	cylinderWithCap(0.05, 0.05, 2, 10);
	glPopMatrix();

	//stand
	glPushMatrix();
	glTranslatef(0.9, 0, 0);
	glRotatef(-90, 1, 0, 0);
	cylinderWithCap(0.3, 0.2, 0.1, 10);
	glPopMatrix();

}


void miniGunHolder() {
	
	glPushMatrix();
	glTranslatef(0, 1.8, 0);
	glRotatef(90, 1, 0, 0);
	cylinderWithCap(0.2, 0.3, 0.5, 10);
	glPopMatrix();


	for (int i = 0; i < 3; i++) {
		glPushMatrix();
		glRotatef(120 * i, 0, 1, 0);
		miniGunLeg();
		glPopMatrix();
	}
}

void miniGun() {

	glPushMatrix();
	glTranslatef(0, 0, -2);
	glColor3f(0.4, 0.37, 0.37);
	miniGunBase();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0, 0, 1);
	machineGunBarrel();
	glPopMatrix();
}



void machineGun(float angle) {
	glPushMatrix();
	glTranslatef(0, 2.5, 0.2);
	glRotatef(angle, 0, 1, 0);
	glRotatef(5, 1, 0, 0);
	glScalef(1, 1, 1.5);
	miniGun();
	glPopMatrix();

	glColor3f(0, 0, 0);
	miniGunHolder();
}