#include <stdlib.h>
#include "project.h"
#include <GL/glut.h>  
#include <math.h>

#define PI 3.1415927

// draw cylinder
void cylinder(float br, float tr, float h, int slices) {
    GLUquadricObj* quadratic;
    quadratic = gluNewQuadric();
    gluCylinder(quadratic, br, tr, h, slices, slices);

}

// draw cylinder with caps
void cylinderWithCap(float br, float tr, float h, int slices) {
    cylinder(br, tr, h, slices);
    float x = 0.0;
    float y = 0.0;
    float angle = 0.0;
    float angle_stepsize = 0.1;

    glBegin(GL_POLYGON);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = tr * cos(angle);
        y = tr * sin(angle);
        glVertex3f(x, y, h);
        angle = angle + angle_stepsize;
    }
    glVertex3f(tr, 0.0, h);
    glEnd();

    glBegin(GL_POLYGON);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = br * cos(angle);
        y = br * sin(angle);
        glVertex3f(x, y, 0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(br, 0.0, 0);
    glEnd();
}