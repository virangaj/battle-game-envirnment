#include "project.h"
#include <GL/glut.h>  


float planeR = 0.39;
float planeB = 0.39;
float planeG = 0.39;


void plane() {
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t * 90.0;

    /// Main body
    glColor3d(planeR, planeR, planeR);
    glPushMatrix();
    glTranslated(0, 0, 0);
    glScaled(3, 0.4, 0.5);
    glutSolidSphere(1, 30, 30);
    glPopMatrix();

    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(1.7, 0.1, 0);
    glScaled(1.5, 0.7, 0.8);
    glRotated(40, 0, 1, 0);
    glutSolidSphere(0.45, 30, 30);
    glPopMatrix();

    ///Wings

    ///Right
    glColor3d(planeR, planeG, planeB);
    glPushMatrix();
    glTranslated(0, 0, 1.2);
    glRotated(-50, 0, 1, 0);
    glScaled(0.7, 0.1, 3);
    glRotated(25, 0, 1, 0);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(planeR, planeG, planeB);
    glPushMatrix();
    glTranslated(-0.3, -0.15, 1.5);
    glRotated(90, 0, 1, 0);
    glScaled(0.1, 0.1, 0.9);
    glutSolidTorus(0.5, 0.5, 50, 50);
    glPopMatrix();

    glColor3d(planeR, planeG, planeB);
    glPushMatrix();
    glTranslated(0.2, -0.15, 0.9);
    glRotated(90, 0, 1, 0);
    glScaled(0.1, 0.1, 0.9);
    glutSolidTorus(0.5, 0.5, 50, 50);
    glPopMatrix();

    ///Left
    glColor3d(planeR, planeG, planeB);
    glPushMatrix();
    glTranslated(0, 0, -1.2);
    glRotated(50, 0, 1, 0);
    glScaled(0.7, 0.1, 3);
    glRotated(-25, 0, 1, 0);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(planeR, planeG, planeB);
    glPushMatrix();
    glTranslated(-0.3, -0.15, -1.5);
    glRotated(90, 0, 1, 0);
    glScaled(0.1, 0.1, 0.9);
    glutSolidTorus(0.5, 0.5, 50, 50);
    glPopMatrix();

    glColor3d(planeR, planeG, planeB);
    glPushMatrix();
    glTranslated(0.2, -0.15, -0.9);
    glRotated(90, 0, 1, 0);
    glScaled(0.1, 0.1, 0.9);
    glutSolidTorus(0.5, 0.5, 50, 50);
    glPopMatrix();


    ///tail wings
    glPushMatrix();
    glTranslated(-2.8, 0, 0);
    glScaled(0.8, 0.5, 0.3);

    ///Right
    glColor3d(planeR, planeG, planeB);
    glPushMatrix();
    glTranslated(0.4, 0, 1.5);
    glRotated(-30, 0, 1, 0);
    glScaled(0.7, 0.1, 3);
    glRotated(10, 0, 1, 0);
    glutSolidCube(1);
    glPopMatrix();

    ///left
    glColor3d(planeR, planeG, planeB);
    glPushMatrix();
    glTranslated(0.4, 0, -1.5);
    glRotated(30, 0, 1, 0);
    glScaled(0.7, 0.1, 3);
    glRotated(-10, 0, 1, 0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();

    /// tail vertical wing
    glColor3d(planeR, planeG, planeB);
    glPushMatrix();
    glTranslated(-2.7, 0.5, 0);
    glRotated(45, 0, 0, 1);
    glScaled(0.8, 2, 0.1);
    glRotated(-20, 0, 0, 1);
    glutSolidCube(0.5);
    glPopMatrix();

}


void groupPlanes() {

    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    glScalef(0.5, 0.5, 0.5);
    plane();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3, 0, -3);
    glRotatef(-90, 0, 1, 0);
    glScalef(0.5, 0.5, 0.5);
    plane();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3, 0, -3);
    glRotatef(-90, 0, 1, 0);
    glScalef(0.5, 0.5, 0.5);
    plane();
    glPopMatrix();

}


//broken plane
void brokenPlane() {

    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t * 90.0;

    /// Main body

    glPushMatrix();
    glColor3d(planeR, planeG, planeB);
    glTranslated(0, 0, 0);
    glScaled(3, 0.4, 0.5);
    glutSolidSphere(1, 10, 10);
    glPopMatrix();


    glPushMatrix();
    glColor3d(0, 0, 0);
    glTranslated(1.7, 0.1, 0);
    glScaled(1.5, 0.7, 0.8);
    glRotated(40, 0, 1, 0);
    glutSolidSphere(0.45, 10, 10);
    glPopMatrix();

    ///Wings

    ///Right
    glPushMatrix();
    glTranslatef(1, 0.5, 0.5);
    glRotatef(30, 1, 0, 0);

    glPushMatrix();
    glColor3d(planeR, planeG, planeB);
    glTranslated(0, 0, 1.2);
    glRotated(-50, 0, 1, 0);
    glScaled(0.7, 0.1, 3);
    glRotated(25, 0, 1, 0);
    glutSolidCube(1);
    glPopMatrix();

    //engine2
    glPushMatrix();
    glColor3f(0.18, 0.66, 0.66);
    glTranslated(-0.3, -0.15, 1.5);
    glRotated(90, 0, 1, 0);
    glScaled(0.1, 0.1, 0.9);
    glutSolidTorus(0.5, 0.5, 50, 50);
    glPopMatrix();
    //engine1
    glPushMatrix();
    glColor3f(0.18, 0.66, 0.66);
    glTranslated(0.2, -0.15, 0.9);
    glRotated(90, 0, 1, 0);
    glScaled(0.1, 0.1, 0.9);
    glutSolidTorus(0.5, 0.5, 50, 50);
    glPopMatrix();
    glPopMatrix();


    ///Left

    glPushMatrix();
    glTranslatef(-1, 0.5, -0.5);
    glRotatef(-30, 1, 0, 0);

    glPushMatrix();
    glColor3d(planeR, planeG, planeB);
    glTranslated(0, 0, -1.2);
    glRotated(50, 0, 1, 0);
    glScaled(0.7, 0.1, 3);
    glRotated(-25, 0, 1, 0);
    glutSolidCube(1);
    glPopMatrix();
    //engine1

    glPushMatrix();
    glColor3f(0.18, 0.66, 0.66);
    glTranslated(-0.3, -0.15, -1.5);
    glRotated(90, 0, 1, 0);
    glScaled(0.1, 0.1, 0.9);
    glutSolidTorus(0.5, 0.5, 50, 50);
    glPopMatrix();
    //engine2

    glPushMatrix();
    glColor3f(0.18, 0.66, 0.66);
    glTranslated(0.2, -0.15, -0.9);
    glRotated(90, 0, 1, 0);
    glScaled(0.1, 0.1, 0.9);
    glutSolidTorus(0.5, 0.5, 50, 50);
    glPopMatrix();
    glPopMatrix();



    ///tail wings
    glPushMatrix();
    glTranslated(-2.8, 0, 0);
    glScaled(0.8, 0.5, 0.3);

    ///Right
    glColor3d(planeR, planeG, planeB);
    glPushMatrix();
    glTranslated(0.4, 0, 1.5);
    glRotated(-30, 0, 1, 0);
    glScaled(0.7, 0.1, 3);
    glRotated(10, 0, 1, 0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();

    /// tail vertical wing
    glColor3d(planeR, planeG, planeB);
    glPushMatrix();
    glTranslated(-2.7, 0.5, 0);
    glRotated(45, 0, 0, 1);
    glScaled(0.8, 2, 0.1);
    glRotated(-20, 0, 0, 1);
    glutSolidCube(0.5);
    glPopMatrix();
  

}