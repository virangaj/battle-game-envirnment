#include <stdio.h>
#include <stdlib.h>
#include "project.h"
#include <GL/glut.h>  
#include <math.h>

//create floor
void cube() {

    glutSolidCube(0.02);

}

void largeBuilding() {

}

void brokenHouse() {
   
    glPushMatrix();
    glScalef(2, 1, 1);
   
    glPopMatrix();
    
   

   
}
void woodHouse() {

}