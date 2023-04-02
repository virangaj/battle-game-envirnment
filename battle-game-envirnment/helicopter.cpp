#include <stdio.h>
#include <stdlib.h>
#include "project.h"
#include <GL/glut.h>  
#include <math.h>

GLfloat xRotated = 0, yRotated = 0, zRotated = 0;
GLdouble radius = 1;


//create body
void heliBody() {
	
	glPushMatrix();
	glTranslatef(3.5, -0.25, 0);
	glScalef(1, 1, 2);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();


	//font face
	glPushMatrix();
	glTranslatef(3, 0, 0);
	glScalef(1, 1.5, 2);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	//back face
	glPushMatrix();
	glScalef(1, 1.5, 2);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	//hull
	glPushMatrix();
	glScalef(3, 1.5, 2);
	glRotatef(90, 0, 1, 0);
	cylinderWithCap(1, 1, 1, 20);
	glPopMatrix();

}


void clippedHeliBody() {

	//clip back
	
	glEnable(GL_CLIP_PLANE0);
	double backPlaneEq[] = { -1.0, 0.0, 0.0, 0.5}; //clip plane equaton
	glClipPlane(GL_CLIP_PLANE0, backPlaneEq);

	heliBody();

	glDisable(GL_CLIP_PLANE0);


	//clip front

	glEnable(GL_CLIP_PLANE0);
	double frontPlaneEq[] = { 1.0, 0.0, 0.0, -2.5 }; //clip plane equaton
	glClipPlane(GL_CLIP_PLANE0, frontPlaneEq);

	heliBody();

	glDisable(GL_CLIP_PLANE0);


	//clip top
	glEnable(GL_CLIP_PLANE0);
	double topPlaneEq[] = { 0.0, 1.0, 0.0, -0.5 }; //clip plane equaton
	glClipPlane(GL_CLIP_PLANE0, topPlaneEq);

	heliBody();

	glDisable(GL_CLIP_PLANE0);


	//clip bottom
	glEnable(GL_CLIP_PLANE0);
	double bottomPlaneEq[] = { 0.0, -1.0, 0.0, -0.75 }; //clip plane equaton
	glClipPlane(GL_CLIP_PLANE0, bottomPlaneEq);

	heliBody();

	glDisable(GL_CLIP_PLANE0);

}



//create helicoptertail
void heliTail(){
	
	glPushMatrix();
	glScalef(1, 1.5, 0.5);
	glRotatef(-90, 0, 1, 0);
	cylinderWithCap(0.5, 0.2, 6, 20);
	glPopMatrix();
}


void heliRotterBlade() {
	
	//solid cube
	glPushMatrix();
	glRotatef(10, 1, 0, 0);
	glColor3f(0.3, 0.34, 0.38);
	glTranslatef(4.5, 0, 0);
	glScalef(8, 0.05, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	//attach cylinder
	glPushMatrix();
	glColor3f(0, 0, 0);
	glRotatef(90, 0, 1, 0);
	cylinderWithCap(0.1, 0.1, 1, 20);
	glPopMatrix();
}

//create main rotter
void heliMainRotter() {
	

	//top cap
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	cylinderWithCap(0.4, 0.4, 0.2, 20);
	glPopMatrix();

	//main holder
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	cylinderWithCap(0.2, 0.2, 1.2, 20);
	glPopMatrix();

	//position rotter blades
	glPushMatrix();
	glTranslatef(0, 0.8, 0);
	//generate rotter bales
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glRotatef(90 * i, 0, 1, 0);
		heliRotterBlade();
		glPopMatrix();
	}
	glPopMatrix();

}


//create main rotter
void heliTailRotter() {


	//top cap
	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	glRotatef(-90, 1, 0, 0);
	cylinderWithCap(0.2, 0.2, 0.1, 20);
	glPopMatrix();

	//main holder
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	cylinderWithCap(0.1, 0.1, 0.5, 20);
	glPopMatrix();

	//position rotter blades
	glPushMatrix();
	glTranslatef(0, 0.4, 0);
	glPushMatrix();
	//generate rotter bales
	for (int i = 0; i < 4; i++) {

		glPushMatrix();
		glRotatef(90 * i, 0, 1, 0);
		glScalef(0.1, 0.5, 0.5);
		heliRotterBlade();
		glPopMatrix();

	}
	glPopMatrix();
	glPopMatrix();

}


//create back of the helicopter
void backSecction(float angle) {
	heliTail();

	//angle tail
	glPushMatrix();
	glTranslatef(-5.5, 0, 0);
	glRotatef(-30, 0, 0, 1);
	glScalef(0.3, 0.5, 0.5);
	heliTail();
	glPopMatrix();

	//tail rotter
	glPushMatrix();
	glTranslatef(-6.5, 0.55, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(angle, 0, 1, 0);
	heliTailRotter();
	glPopMatrix();
	
}

void heliEngine() {
	
	//engine cylinder
	glPushMatrix();
	glTranslatef(-0.5, 0.25, -0.5);
	glColor3f(0.15, 0.15, 0.15);
	glRotatef(-90, 0, 1, 0);
	cylinder(0.25, 0.25, 1, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 0.25, 0.5);
	glColor3f(0.15, 0.15, 0.15);
	glRotatef(-90, 0, 1, 0);
	cylinder(0.25, 0.25, 1, 20);
	glPopMatrix();


	//engine holder
	glPushMatrix();
	glColor3f(0.49, 0.49, 0.49);
	glScalef(2, 0.5, 1);
	glutSolidSphere(1, 10, 10);
	glPopMatrix();

}

//create helicopter stand
void heliStand() {

	//bottom bar
	glPushMatrix();
	glScalef(4, 0.05, 0.05);
	glutSolidCube(1);
	glPopMatrix();

	//left bar
	glPushMatrix();
	glTranslatef(-1.4, 0.25, 0.0);
	glScalef(0.05, 0.5, 0.05);
	glutSolidCube(1);
	glPopMatrix();


	//right bar
	glPushMatrix();
	glTranslatef(1.4, 0.25, 0.0);
	glScalef(0.05, 0.5, 0.05);
	glutSolidCube(1);
	glPopMatrix();


}

//mount machinve guns
void mountMiniGun() {

	// mini gun mount handle
	glPushMatrix();
	glTranslatef(-0.2, 0, 0);
	glScalef(0.1, 0.1, 3);
	glutSolidCube(1);
	glPopMatrix();

	//right gun
	glPushMatrix();
	glTranslatef(0, 0, 1.5);
	glRotatef(90, 0, 1, 0);
	glScalef(0.2, 0.2, 0.4);
	miniGun(0);
	glPopMatrix();


	//left gun
	glPushMatrix();
	glTranslatef(0, 0, -1.5);
	glRotatef(90, 0, 1, 0);
	glScalef(0.2, 0.2, 0.4);
	miniGun(0);
	glPopMatrix();
}

//assemble helicopter
void assembleHelicopter(float angle) {
	//heli body
	glPushMatrix();
	glScalef(1, 0.5, 0.5);
	clippedHeliBody();
	glPopMatrix();

	//machine guns
	glPushMatrix();
	glTranslatef(3, 0.2, 0);
	mountMiniGun();
	glPopMatrix();




	//bck
	backSecction(angle);

	glPushMatrix();
	glTranslatef(2, 0.5, 0);
	//engine
	glPushMatrix();
	glTranslatef(-0.5, 0, 0);
	glScalef(0.5, 1, 0.5);
	heliEngine();
	glPopMatrix();
	
	//main rotter
	glPushMatrix();
	glRotatef(angle, 0, 1, 0);
	heliMainRotter();
	glPopMatrix();

	glPopMatrix();
}

//whole helicopter
void helicopter(float angle) {
	
	glColor3f(0.49, 0.49, 0.49);

	glPushMatrix();
	glTranslatef(0, 1, 0);
	assembleHelicopter(angle);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 0, -0.5);
	heliStand();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 0, 0.5);
	heliStand();
	glPopMatrix();


}

//daw H 
void letterH(){
	
	//left length
	glPushMatrix();
	glTranslatef(0, 0, -2);
	glScalef(5, 0.01, 0.4);
	glColor3f(0.86, 0.59, 0);
	glutSolidCube(1);
	glPopMatrix();


	
	//right length

	glPushMatrix();
	glTranslatef(0, 0, 2);
	glScalef(5, 0.01, 0.4);
	glColor3f(0.86, 0.59, 0);
	glutSolidCube(1);
	glPopMatrix();


	//middle
	glPushMatrix();
	glScalef(0.4, 0.01, 4);
	glColor3f(0.86, 0.59, 0);
	glutSolidCube(1);
	glPopMatrix();


}

//create helipad
void helipad() {

	//cretae back circle
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glColor3f(0, 0, 0);
	cylinderWithCap(5, 5, 0.01, 20);
	glPopMatrix();

	//ring
	glPushMatrix();
	glScalef(8, 1, 8);
	glRotatef(90, 1, 0, 0);
	glColor3f(1, 1, 1);
	glutSolidTorus(0.05, 0.5, 100, 100);
	glPopMatrix();


	letterH();

}