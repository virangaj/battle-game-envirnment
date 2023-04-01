#include "project.h"
#include <GL/glut.h> 


//make cylinder
void makecylinder(float height, float Base, float r, float g, float b){
	GLUquadricObj* qobj;
	qobj = gluNewQuadric();
	glColor3f(r, b, b);
	glPushMatrix();
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	gluCylinder(qobj, Base, Base - (0.2 * Base), height, 10, 1);
	glPopMatrix();
}




// make a tree
void maketree(float height, float Base, float r, float g, float b){

	glPushMatrix();
	float angle;
	makecylinder(height, Base, r, g, b);
	glTranslatef(0.0f, height, 0.0f);
	height -= height * 0.2f;
	Base -= Base * 0.3f;

	if (height > 1)
	{
		angle = 22.5f;
		
		glPushMatrix();
		glRotatef(angle, -1.0f, 0.0f, 0.0f);
		maketree(height, Base, r-0.02, g - 0.02, b - 0.02);
		glPopMatrix();
		
		glPushMatrix();
		glRotatef(angle, 0.5f, 0.0f, 0.866f);
		maketree(height, Base, r - 0.02, g - 0.02, b - 0.02);
		glPopMatrix();

		glPushMatrix();
		glRotatef(angle, 0.5f, 0.0f, -0.866f);
		maketree(height, Base, r - 0.02, g - 0.02, b - 0.02);
		glPopMatrix();
	
	}
	glPopMatrix();
}
