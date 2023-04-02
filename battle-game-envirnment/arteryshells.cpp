#include <stdio.h>
#include <stdlib.h>
#include "project.h"
#include <GL/glut.h>  
#include <math.h>

#define PI 3.1415927



void draw_cylinder_side_open(GLfloat radius,
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
    glColor3f(R, G, B );
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
        glVertex3f(x, y, 0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, 0);


    glEnd();
}


void topCone() {
   
    glutSolidCone(1, 1, 100, 100);
}

// artery shell
void artilleryShell() {

    glPushMatrix();

   


    //top cone 
    glPushMatrix();
    glTranslatef(0, 0, 0.85);
    glScalef(0.21, 0.21, 0.5);
    glColor3f(0, 0.22, 0.08);
    topCone();
    glPopMatrix();


    //middle cone
    glPushMatrix();
    glTranslatef(0, 0, 0.75);
    glScalef(0.25, 0.25, 0.5);
    glColor3f(1.0, 0, 0);
    topCone();
    glPopMatrix();

    artilleryEmptyShell();



    glPopMatrix();
 
}

// empty artery shell
void artilleryEmptyShell() {

    glPushMatrix();
    glScalef(0.25, 0.25, 0.75);
    glColor3f(1, 0.84, 0);
    draw_cylinder_side_open(1, 1, 0.41, 0.34, 0);
    glPopMatrix();

}

void sidePlaneofBox() {
    
    glBegin(GL_POLYGON);
    glColor3f(0.25, 0.25, 0.25);
    glVertex3f(-1, 0, 0);
    glVertex3f(-1, 2, 0);
    glVertex3f(1, 2, 0);
    glVertex3f(1, 0, 0);
    glEnd();
}

void artelleryAmmoCase() {

   
    //front
    glPushMatrix();
    glTranslatef(0 ,0, 1);
    sidePlaneofBox();
    glPopMatrix();
    
    //left
    glPushMatrix();
    glTranslatef(-1, 0, 0);
    glRotatef(90, 0, 1, 0);
    sidePlaneofBox();
    glPopMatrix();


    //right 
    glPushMatrix();
    glTranslatef(1, 0, 0);
    glRotatef(90, 0, 1, 0);
    sidePlaneofBox();
    glPopMatrix();

    //back
    glPushMatrix();
    glTranslatef(0, 0, -1);
    sidePlaneofBox();
    glPopMatrix();

    //bottom
    glPushMatrix();
    glTranslatef(0, 0, -1);
    glRotatef(90, 1, 0, 0);
    sidePlaneofBox();
    glPopMatrix();

}


void artilleryAmmoCrate() {


  //  artelleryAmmoCase();
   
    for (GLfloat i = 0; i <= 2; i += 0.35) {
        for (GLfloat j = 0; j <= 1; j += 0.35) {
            glPushMatrix();
            glTranslatef(i, j, 0);
            artilleryShell();
            glPopMatrix();
        }

    }
}