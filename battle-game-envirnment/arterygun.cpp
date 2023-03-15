#include <stdio.h>
#include <stdlib.h>
#include "project.h"
#include <GL/glut.h>  
#include <math.h>

#define PI 3.1415927


void draw_cylinder(GLfloat radius,
    GLfloat height,
    GLubyte R,
    GLubyte G,
    GLubyte B)
{
    GLfloat x = 0.0;
    GLfloat y = 0.0;
    GLfloat angle = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3ub(R - 40, G - 40, B - 40);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        glVertex3f(x, y, 0.0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(R, G, B);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glEnd();
}


// main barrel
void maincylinderbarel() {
    glPushMatrix();
    glColor3f(1, 0, 0);
    glutSolidCone(0.2, 3, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 1, 0);
    glutSolidCone(0.25, 1, 20, 20);
    glPopMatrix();

    draw_cylinder(0.125, 3, 100, 100, 100);
}

// shield one side
void gunShieldRectangle(){
    
    // bar
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(0, 0, -0.25);
    glScalef(0.05, 0.05, 0.5);
    glutSolidCube(1);
    glPopMatrix();

    //shield cover
    glPushMatrix();
    glColor3f(0, 0, 1);
    glScalef(1,2,0.01);
    glutSolidCube(1);
    glPopMatrix();
}



// make gun base
void protectiveSheild() {
    
    // base of the gun
    glutSolidCube(1);

    //left -> gun sheilds
    glPushMatrix();
    glTranslatef(-1.2, 0, 0.5);
    gunShieldRectangle();
    glPopMatrix();

    //right -> gun sheilds
    glPushMatrix();
    glTranslatef(1.2, 0, 0.5);
    gunShieldRectangle();
    glPopMatrix();

    //protective sheild holder
    glPushMatrix();
    glColor3f(0,0,1);
    glScalef(3, 0.1, 0.1);
    glutSolidCube(1);
    glPopMatrix();

}

void gunStructure() {
   
    glPushMatrix();
    protectiveSheild();

    glPushMatrix(); 
    glTranslatef(0, 0, 0.5);
    maincylinderbarel();
    glPopMatrix();


    glPopMatrix();

}


void arteryGun(){
    glPushMatrix();
    glTranslatef(0, 4, 0);
    glRotatef(-40, 1, 0, 0);
    gunStructure();
    glPopMatrix();
}