#include <stdio.h>
#include <stdlib.h>
#include "project.h"
#include <GL/glut.h>  
#include <math.h>


float length = 20.0;
float windowHeight = 0.5;
float windowWidth = 0.5;

float windowBorderWidth = 0.02;


//create half cylinder area
void halfCylinderArea() {

    for (float i = -length / 2; i < length / 2; i+=0.2) {        
        glPushMatrix();
        glTranslatef(i, 0, 0);
        glPushMatrix();
        glColor3f(0.53, 0.38, 0.38);
        glScalef(0.2, 1, 0.2);
        glRotatef(180, 0, 1, 0);
        glRotatef(-90, 1, 0, 0);
        halfCylinderWithCaps(1, 1, 1, 30);
        glPopMatrix();
        glPopMatrix();
    }   
}

//create payment
void payment() {
    glPushMatrix();
    glColor3f(0.31, 0.17, 0.04);
    glScalef(length, 0.2, 1);
    glutSolidCube(1);
    glPopMatrix();
}



//create single window
void singleWindow() {
    // create border of the window
        //bottom
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(0, windowHeight + windowBorderWidth / 2, 0);
    glScalef(windowWidth + 0.02, windowBorderWidth, windowBorderWidth);
    glutSolidCube(1);
    glPopMatrix();

    //top
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(0, windowBorderWidth / 2, 0);
    glScalef(windowWidth + 0.02, windowBorderWidth, windowBorderWidth);
    glutSolidCube(1);
    glPopMatrix();

    //left
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(-windowWidth / 2, windowHeight / 2 + windowBorderWidth / 2, 0);
    glScalef(windowBorderWidth, windowHeight, windowBorderWidth);
    glutSolidCube(1);
    glPopMatrix();
    //right
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(windowWidth / 2, windowHeight / 2 + windowBorderWidth / 2, 0);
    glScalef(windowBorderWidth, windowHeight, windowBorderWidth);
    glutSolidCube(1);
    glPopMatrix();

    //create transparent glass
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPushMatrix();
    glColor4f(0.57, 0.82, 0.88, 0.3);
    glTranslatef(0, 0.255, 0);
    glScalef(windowWidth, windowHeight, windowBorderWidth / 4);
    glutSolidCube(1);
    glPopMatrix();

    glDisable(GL_BLEND);


}




void fillWindow() {
   
    //fill color
    glPushMatrix();
    glColor3f(0.6, 0.38, 0.17);
    glTranslatef(0, 0.255, 0);
    glScalef(windowWidth, windowHeight+ 0.01, windowBorderWidth+0.01);
    glutSolidCube(1);
    glPopMatrix();
}

//create window set
void windowSet() {
    for (float i = -length / 10; i < length / 10; i += windowWidth) {

        glPushMatrix();
        glTranslatef(i, 0, 0);
        singleWindow();
        glPopMatrix();
    }
}

void windowFillSet() {

    for (float i = -length / 10; i < length / 10; i += windowWidth) {

        glPushMatrix();
        glTranslatef(i, 0, 0);
        fillWindow();
        glPopMatrix();
    }
}

// create left side of the building
void leftSideBuilding() {

    //second floar top wall
    glPushMatrix();
    glColor3f(0.6, 0.38, 0.17);
    glTranslatef(0, 4.125, 0);
    glScalef(length, 0.25, windowBorderWidth);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length / 10 + windowWidth / 2, 3.5, 0);
    int j = 0;
    for (float i = -length / 2; i < length / 2; i += 2*length / 5) {
    
        j++;


        glPushMatrix();
        glTranslatef(i, 0, 0);
        windowFillSet();
        glPopMatrix();

        if (j < 3) {
            glPushMatrix();
            glTranslatef(i + length / 5, 0, 0);
            windowSet();
            glPopMatrix();
        }
        
    }
    glPopMatrix();



    //second floar bottom wall
    glPushMatrix();
    glColor3f(0.6, 0.38, 0.17);
    glTranslatef(0, 3, 0);
    glScalef(length, 1, windowBorderWidth);
    glutSolidCube(1);
    glPopMatrix();

    //start of second floor
    glPushMatrix();
    glTranslatef(0, 3, 0);
    payment();
    glPopMatrix();


    //create second layer with half cylinders
    glPushMatrix();
    glTranslatef(0, 2, 0);
    halfCylinderArea();
    glPopMatrix();

    //create plane above payment
    glPushMatrix();
    glColor3f(0.6, 0.38, 0.17);
    glTranslatef(0, 1, 0);
    glScalef(length, 2, windowBorderWidth);
    glutSolidCube(1);
    glPopMatrix();

    //create bottom payment
    payment();

}





void largeBuilding() {

    glPushMatrix();
    glRotatef(-90, 0, 1, 0);


    //front
    glPushMatrix();
    glTranslatef(0, 0, 4);
    leftSideBuilding();
    glPopMatrix();
    
    //back
    glPushMatrix();
    glTranslatef(0, 0, -4);
    leftSideBuilding();
    glPopMatrix();

    //left side
    glPushMatrix();
    glTranslatef(-length/2, 0, 0);
    glColor3f(0.6, 0.38, 0.17);
    glScalef(0.4, 8.5, 8);
    glutSolidCube(1);
    glPopMatrix();


    glPopMatrix();
}

void brokenHouse() {
   
   
}
void woodHouse() {

}