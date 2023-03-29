#include "project.h"
#include <GL/glut.h>  

//draw axis

GLfloat x = 40;


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


float textureCordinates[] = {
    -x, -0.1, -x, x, -0.1, -x, x, -0.1, x, -x, -0.1, x
};


void ground() {

    glPushMatrix();


    glColor3f(0.1f, 0.1f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f(-x, -0.1, -x);
    glVertex3f(x, -0.1, -x);
    glVertex3f(x, -0.1, x);
    glVertex3f(-x, -0.1, x);
    glEnd();
    glPopMatrix();
}