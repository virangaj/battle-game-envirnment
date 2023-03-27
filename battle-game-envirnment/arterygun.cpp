#include <stdio.h>
#include <stdlib.h>
#include "project.h"
#include <GL/glut.h>  
#include <math.h>

#define PI 3.1415927


void draw_cylinder(GLfloat radius,
    GLfloat height,
    GLfloat R,
    GLfloat G,
    GLfloat B)
{
    GLfloat x = 0.0;
    GLfloat y = 0.0;
    GLfloat angle = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(R, G, B);
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
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);

    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, 0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, 0);


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

    draw_cylinder(0.125, 3, 0.1, 0.1, 0.0);
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
    glPushMatrix();
    glColor3f(0.1, 0.1, 0);
    glutSolidCube(1);
    glPopMatrix();

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


//stand wheel
void wheel() {
    glPushMatrix();
    glScalef(0.75, 1, 1);
    glRotatef(90, 0, 1, 0);
    draw_cylinder(1, 1, 0, 0, 0);
    glPopMatrix();
}


//behind bar structure
void behindBars() {

    glPushMatrix();
    glTranslatef(-0.5, 0, -4);
    glRotatef(-10, 0, 1, 0);
    glScalef(0.5, 0.5, 8);
    glColor3f(0, 0, 1);
    glutSolidCube(1);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.5, 0, -4);
    glRotatef(10, 0, 1, 0);
    glScalef(0.5, 0.5, 8);
    glColor3f(0, 0, 1);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, -8);
    glColor3f(0, 0, 1);
    glutSolidCube(1.5);
    glPopMatrix();
}

//gun base stand
void baseStand() {

    //wheel holder
    glPushMatrix();
    glTranslatef(-3, 0, 0);
    glScalef(6, 0.125, 0.125);
    glRotatef(90, 0, 1, 0);
    draw_cylinder(1, 1, 0, 0, 0);
    glPopMatrix();


    //left wheel
    glPushMatrix();
    glTranslatef(-3.25, 0, 0);
    wheel();
    glPopMatrix();

    //right wheel
    glPushMatrix();
    glTranslatef(2.5, 0, 0);
    wheel();
    glPopMatrix();

    // base stand
    glPushMatrix();
    glScalef(4, 0.5, 2);
    glRotatef(45, 1, 0, 0);
    glColor3f(1, 0, 0);
    glutSolidCube(1);
    glPopMatrix();

    //left bar
    behindBars();

    
    //right bar

}



// whole gun base
void gunBase() {
    
    glPushMatrix();
    glTranslatef(0, 0.5, 0);
    baseStand();
    glPopMatrix();
}


// gun structure
void gunStructure() {

    glPushMatrix();

    protectiveSheild();

    glPushMatrix();
    glTranslatef(0, 0, 0.5);
    maincylinderbarel();
    glPopMatrix();


    glPopMatrix();

}

//whole gun
void arteryGun(){
   //ammo create
    glPushMatrix();
    glTranslatef(5, 0, -2);
    artilleryAmmoCrate();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(0, 1.75, 0);
    glRotatef(-40, 1, 0, 0);
    glScalef(1.5, 1.5, 1.5);
    gunStructure();
    glPopMatrix();


    glPushMatrix();
    gunBase();
    glPopMatrix();
}