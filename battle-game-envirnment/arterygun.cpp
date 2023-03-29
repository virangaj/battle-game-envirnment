#include <stdio.h>
#include <stdlib.h>
#include "project.h"
#include <GL/glut.h>  
#include <math.h>

#define PI 3.1415927



GLfloat limitX = 5, limitY = 1;


// draw cylinder
void cylinder(GLfloat br, GLfloat tr, GLfloat h) {
    GLUquadricObj* quadratic;
    quadratic = gluNewQuadric();
    gluCylinder(quadratic, br, tr, h, 100, 100);

}

// draw cylinder with caps
void cylinderWithCap(GLfloat br, GLfloat tr, GLfloat h) {
    cylinder(br, tr, h);
    GLfloat x = 0.0;
    GLfloat y = 0.0;
    GLfloat angle = 0.0;
    GLfloat angle_stepsize = 0.1;

    glBegin(GL_POLYGON);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = tr * cos(angle);
        y = tr * sin(angle);
        glVertex3f(x, y, h);
        angle = angle + angle_stepsize;
    }
    glVertex3f(tr, 0.0, h);


    glBegin(GL_POLYGON);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = br * cos(angle);
        y = br * sin(angle);
        glVertex3f(x, y, 0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(br, 0.0, 0);

}







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
void mainCylinderBarrel() {

    glPushMatrix();
    glColor3f(0.2, 0.2, 0.1);
    cylinder(0.4, 0.125, 1);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.5, 0.2, 0.1);
    cylinder(0.2, 0.125, 2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.2, 0.2, 0.1);
    cylinder(0.125, 0.125, 3);
    glPopMatrix();
}

// shield one side
void gunShieldRectangle(){
    
    // bar
    glPushMatrix();
    glColor3f(0.2, 0.2, 0.1);
    glTranslatef(0, 0, -0.25);
    glScalef(0.05, 0.05, 0.5);
    glutSolidCube(1);
    glPopMatrix();

    //shield cover
    glPushMatrix();
    glColor3f(0.2, 0.2, 0.1);
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
    glColor3f(0, 0, 0);
    
    draw_cylinder(1, 1, 0, 0, 0);
    glPopMatrix();
}


//behind bar structure
void behindBars() {

    glPushMatrix();
    glTranslatef(-0.5, 0, -4);
    glRotatef(-10, 0, 1, 0);
    glScalef(0.5, 0.5, 8);
    glColor3f(0.2, 0.2, 0.1);
    glutSolidCube(1);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.5, 0, -4);
    glRotatef(10, 0, 1, 0);
    glScalef(0.5, 0.5, 8);
    glColor3f(0.2, 0.2, 0.1);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, -8);
    glColor3f(0.2, 0.2, 0.1);
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
    glColor3f(0.2, 0.2, 0.5);
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
    mainCylinderBarrel();
    glPopMatrix();


    glPopMatrix();

}

void pillowBarrier() {

      
    for (GLfloat i = -limitX; i < limitX + 3; i+=1.25) {
        for (GLfloat j = 0 ; j < limitY; j+=0.25) {
        
            glPushMatrix();
            glTranslatef(i, j, 0);
            glScalef(0.2, 0.2, 0.2);
            soilPillow();
            glPopMatrix();
        }

    }
}

//whole gun
void arteryGun(){
   //ammo create
    glPushMatrix();
    glTranslatef(5, 0, -2);
    artilleryAmmoCrate();
    glPopMatrix();
    
    
    //pillow baricade
    glPushMatrix();
    glTranslatef(0, 0, 4);
    pillowBarrier();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-limitX, 0, -2);
    glRotatef(90, 0, 1, 0);
    pillowBarrier();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(limitX + 3, 0, -2);
    glRotatef(90, 0, 1, 0);
    pillowBarrier();
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