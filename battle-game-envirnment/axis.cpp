#include "project.h"
#include <GL/glut.h>  

//draw axis

GLfloat x = 50;


void drawAxis() {

    //x axis
    glPushMatrix();
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex3f(-x, 0, 0);
    glVertex3f(x, 0, 0);
    glEnd();
    glPopMatrix();

    //y axis
    glPushMatrix();
    glBegin(GL_LINES);
    glColor3f(0, 1, 0);
    glVertex3f(0, -x, 0);
    glVertex3f(0, x, 0);
    glEnd();
    glPopMatrix();


    //z axis
    glPushMatrix();
    glBegin(GL_LINES);
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, x);
    glVertex3f(0, 0, -x);
    glEnd();
    glPopMatrix();
}
void drawGrid() {


    GLfloat steps = 1.0f;
    glPushMatrix();
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    for (GLint i = -x; i < x; i += steps) {

        if (i==0) {
            continue;
        }
        else{
            glVertex3f(-x, 0, i);
            glVertex3f(x, 0, i);
        }
    }
    glEnd();


    glBegin(GL_LINES);
    for (GLint i = -x; i < x; i += steps) {
        if (i == 0) {
            continue;
        }
        else{
            glVertex3f(i, 0, x);
            glVertex3f(i, 0, -x);
        }
    }
    glEnd();
    glPopMatrix();

}


void groundPlane() {
    glPushMatrix();
    //glColor3f(0.26, 0.07, 0);
    glColor3f(0.22, 0.15, 0.01);
    glBegin(GL_POLYGON);
    glVertex3f(-x, -0.1, -x);
    glVertex3f(x, -0.1, -x);
    glVertex3f(x, -0.1, x);
    glVertex3f(-x, -0.1, x);
    glEnd();
    glPopMatrix();
}

void roadConerCircle() {

    glPushMatrix();
    glColor3f(0, 0, 0);
    glRotatef(90, 1, 0, 0);
    halfCylinderWithCaps(1, 1, 0.01, 30);
    glPopMatrix();
}
void roadConer() {
    glPushMatrix();
    glTranslatef(0, 0, 1);
    glRotatef(90, 0, 1, 0);
    roadConerCircle();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glScalef(2, 0.01, 2);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1, 0, 1);
    glColor3f(0, 0, 0);
    glScalef(2, 0.01, 2);
    glutSolidCube(1);
    glPopMatrix();
}


void straightRoad() {
    glPushMatrix();
    glColor3f(0, 0, 0);
    glScalef(2, 0.01, 2);
    glutSolidCube(1);
    glPopMatrix();
}

void road() {

    //right road
    glPushMatrix();
    glTranslatef(15, 0, 0);
    glScalef(1, 1, 40);
    straightRoad();
    glPopMatrix();


    //left road
    glPushMatrix();
    glTranslatef(-16, 0, 0);
    glScalef(1, 1, 15);
    straightRoad();
    glPopMatrix();

    //middle front road
    glPushMatrix();
    glTranslatef(5, 0, 15);
    glScalef(20, 1, 1);
    straightRoad();
    glPopMatrix();

    //middle back road
    glPushMatrix();
    glTranslatef(0, 0, -17);
    glScalef(15, 1, 1);
    straightRoad();
    glPopMatrix();


    //front left
    glPushMatrix();
    glTranslatef(-15, 0, 15);
    glRotatef(-90, 0, 1, 0);
    roadConer();
    glPopMatrix();


    ////front right
    //glPushMatrix();
    //glTranslatef(15, 0, 15);
    //roadConer();
    //glPopMatrix();


    //back left
    glPushMatrix();
    glTranslatef(-16, 0, -16);
    glRotatef(-180, 0, 1, 0);
    roadConer();
    glPopMatrix();

    
  
}



void ground() {
    groundPlane();


    road();

}
