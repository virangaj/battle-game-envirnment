#include <GL/glut.h>
#include "project.h"
#include <math.h>


#define PI 3.1415927

GLfloat camX, camY, camZ = 0.0f;
GLfloat sX, sY, sZ = 0.0f;
GLfloat sRx, sRy, sRz = 0.0f;
GLfloat animYRot = 0.0f;

GLfloat sceX = 0.0;
GLfloat sceY = 0.0;
GLfloat sceZ = 0.0;
GLfloat steps = 1.0f;

float heliRotX = 0, heliRotY = 0, heliRotZ = 0, helimoveX = 0, helimoveY = 0, helimoveZ = 0, helpHeli = 0;


float tankWheel = 0, tankTurrent = 0, tankMove = 15;


float artellaryBarrelAngle = 0.0;
float minigunRot = 0.0f, minigunRotHelper = 0.0f;
int frame = 0;


void init() {
    glClearColor(0.58, 0.78, 0.93, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    
}
void placeLightning() {
    /* set material parameters */
    const GLfloat blue[4] = { 0.3, 0.3, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
    const GLfloat matwhite[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glMaterialfv(GL_FRONT, GL_SPECULAR, matwhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 128.0f);

    glEnable(GL_LIGHT0);
    /* positioned the light source 1 */
    GLfloat position0[] = { 20.0,20.0,20.0,1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, position0);

    /* set light intensities for light source 1 */
    GLfloat paleYellow[] = { 1.0,1.0,0.75,1.0 };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, paleYellow);
    GLfloat white[] = { 1.0,1.0,1.0,1.0 };
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);
    
    glEnable(GL_LIGHT1);
    /* positioned the light source 2 */
    GLfloat position1[] = { -25.0,20.0,-25,1.0 };
    glLightfv(GL_LIGHT1, GL_POSITION, position1);

    /* set light intensities for light source 2 */
    glLightfv(GL_LIGHT1, GL_DIFFUSE, paleYellow);
    //GLfloat white[] = { 1.0,1.0,1.0,1.0 };
    glLightfv(GL_LIGHT1, GL_SPECULAR, white);


    glEnable(GL_LIGHT2);
    /* positioned the light source 2 */
    GLfloat position2[] = { -25.0,20.0,25,1.0 };
    glLightfv(GL_LIGHT2, GL_POSITION, position2);

    /* set light intensities for light source 2 */
    glLightfv(GL_LIGHT2, GL_DIFFUSE, paleYellow);
    //GLfloat white[] = { 1.0,1.0,1.0,1.0 };
    glLightfv(GL_LIGHT2, GL_SPECULAR, white);
    
}


//helicopter animation function
void helicopterTakeOffAnimation() {
    glPushMatrix();
    glTranslatef(22, 0, -10);

    //animation section
    glPushMatrix();

    //move heli
    glTranslatef(helimoveX,helimoveY,helimoveZ);

    //rotate heli
    glRotatef(heliRotX, 1, 0, 0);
    glRotatef(-heliRotY, 0, 1, 0);
    glRotatef(-heliRotZ, 0, 0, 1);

    glScalef(0.8, 0.8, 0.8);
    helicopter(frame * 20);
    

    glPopMatrix();

    glPopMatrix();

}

//display the whole scene
void createScene() {

    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t * 90.0;
    double aa = a;

    //glRotated(aa, 0, 1, 0);
    //glTranslatef(-10, 10, -10);
    //glRotatef(-30, 0, 0, 1);
    //groupPlanes();
    //glPopMatrix();




    //watch tower
   //front right tower

    glPushMatrix();
    glTranslatef(10, 0, 10);
    glRotatef(180, 0, 1, 0);
    watchTower(minigunRot);
    glPopMatrix();

    //front left tower
    glPushMatrix();
    glTranslatef(-10, 0, 10);
    glRotatef(180, 0, 1, 0);
    watchTower(minigunRot);
    glPopMatrix();

    //back left tower
    glPushMatrix();
    glTranslatef(-10, 0, -10);
    watchTower(minigunRot);
    glPopMatrix();


    //back right tower
    glPushMatrix();
    glTranslatef(10, 0, -10);
    watchTower(minigunRot);
    glPopMatrix();
   


    //large building
    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    largeBuilding();
    glPopMatrix();


    //place the trees
    for (float i = -6; i < 8; i += 4) {
        glPushMatrix();
        glTranslatef(10, 0, i);
        glScalef(0.2, 0.2, 0.2);
        maketree(4.0f, 0.3f, 0.93, 0.7, 0.59);
        glPopMatrix();
    }


    //place the lamp towers
    for (float i = -15; i < 15; i += 5) {

        glPushMatrix();
        glTranslatef(13, 0, i);
        if (fmod(i, 3) == 0) {
            lampTower(frame, 1);
        }
        else {
            lampTower(0, 0);
        }
        glPopMatrix();
    }

    //broken trees dues to plane crash
    glPushMatrix();
    glTranslatef(-10, 0, -6);
    glScalef(0.2, 0.2, 0.2);
    maketree(4.0f, 0.3f, 0.93, 0.7, 0.59);
    glPopMatrix();

    //fallen tree 1
    glPushMatrix();
    glTranslatef(-10, -0.2, -2);
    glScalef(0.2, 0.2, 0.2);
    glRotatef(-60, 1, 0, 0);
    maketree(4.0f, 0.3f, 0.93, 0.7, 0.59);
    glPopMatrix();

    //fallen tree 2
    glPushMatrix();
    glTranslatef(-10, -0.2, 2);
    glScalef(0.2, 0.2, 0.2);
    glRotatef(-60, 0, 0, 1);
    maketree(4.0f, 0.3f, 0.93, 0.7, 0.59);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, 0, 6);
    glScalef(0.2, 0.2, 0.2);
    maketree(4.0f, 0.3f, 0.93, 0.7, 0.59);
    glPopMatrix();

    //place broken plane
    glPushMatrix();
    glTranslatef(-8, 0, -2);
    glRotatef(53, 0, 1, 0);
    brokenPlane();
    glPopMatrix();


    //place mini gun
    glPushMatrix();
    glTranslatef(-3, 0, 18);
    glScalef(0.5, 0.5, 0.5);
    groundMiniGunBase(-minigunRot);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3, 0, 18);
    glScalef(0.5, 0.5, 0.5);
    groundMiniGunBase(-minigunRot);
    glPopMatrix();


    //place container boxes
    for (float i = -10; i < 10; i+=6) {

        for (float j = 0; j <4; j += 2) {
            glPushMatrix();
            glTranslatef(-22, j, i);
            containerBox(0, 0, 0.1, 0.24);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-24, j, i);
            containerBox(0, 0.24, 0, 0);
            glPopMatrix();
        }
    }

    //place arteryGun
   
    glPushMatrix();
    glTranslatef(-8, 0, -24);
    arteryGun(artellaryBarrelAngle);
    glPopMatrix();

    //place radars
    glPushMatrix();
    glTranslatef(22, 0, 5);
    glScalef(0.6, 0.6, 0.6);
    radarMachine(frame*20);
    glPopMatrix();

    //place helicopter 
    helicopterTakeOffAnimation();
   

    //place secondhelicopter 
    glPushMatrix();
    glTranslatef(22, 0, -25);
    helicopter(0);
    helipad();
    glPopMatrix();

    //place helicopter pad
    glPushMatrix();
    glTranslatef(22, 0, -10);
    helipad();
    glPopMatrix();

    //place tank
    glPushMatrix();
    glTranslatef(tankMove, 0, 15);
    glScalef(0.6, 0.6, 0.6);
    armorTank(frame, minigunRot);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-16, 0, -tankMove);
    glRotatef(90, 0, 1, 0);
    glScalef(0.6, 0.6, 0.6);
    armorTank(frame, minigunRot);
    glPopMatrix();


    //place antena

    glPushMatrix();
    glTranslatef(-20, 0, -20);
    antenaTower(frame);
    glPopMatrix();
  


    //place gound
    glPushMatrix();
    ground();
    glPopMatrix();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float basePosition = 20;
  
    //place camera
    gluLookAt(basePosition + camX, basePosition + camY, basePosition + camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    
    //add ligts
    placeLightning();


    glPushMatrix();

    glTranslatef(sceX, sceY, sceZ);
   
    glRotatef(sRy, 0, 1, 0);

    glPushMatrix();
    createScene();
    //ground();
  
  

   /* drawGrid();
    drawAxis();*/
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}



void specialKeys(int key, int x, int y) {
    switch (key)
    {
    case GLUT_KEY_UP:
        camY += steps;
        break;
    case GLUT_KEY_DOWN:
        camY -= steps;
        break;
    case GLUT_KEY_LEFT:
        camX -= steps;
        break;
    case GLUT_KEY_RIGHT:
        camX += steps;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void keyPress(unsigned char key, int x, int y) {

    switch (key){
        case 'r':
            camX = 0;
            camY = 0;
            camZ = 0;
            sceX = 0;
            sceY = 0;
            sceZ = 0;
            sX = 0;
            sY = 0;
            sZ = 0;
            sRy = 0;
            sRx = 0;
            sRz = 0;
            artellaryBarrelAngle = 0;
            minigunRotHelper = 0;
            break;

        case 'q':
            camZ += 1;
            break;
        case 'e':
            camZ -= 1;
            break;
        case 'k':
            sRy += 1;
            break;
        case 'l':
            sRy -= 1;
            break;
        case 'w':
            sceZ += steps;
            break;
        case 's':
            sceZ -= steps;
            break;
        case 'd':
            sceX -= steps;
            break;
        case 'a':
            sceX += steps;
            break;
        case 'Z':
            sceY += steps;
            break;
        case 'z':
            sceY -= steps;
            break;
        case 'n':
            artellaryBarrelAngle += 0.5;
        case 'N':
            artellaryBarrelAngle -= 0.5;
        case '1':
            //glEnable(GL_LIGHT0);
            break;
        case '!':
            //glDisable(GL_LIGHT0);
            break;
        case '2':
            //glEnable(GL_LIGHT1);
            break;
        case '@':
            //glDisable(GL_LIGHT1);
            break;
        case '3':
            glPolygonMode(GL_FRONT, GL_LINE);
            glPolygonMode(GL_BACK, GL_LINE);
            break;
        case '4':
            glPolygonMode(GL_FRONT, GL_FILL);
            glPolygonMode(GL_BACK, GL_FILL);
            break;
        default:
            break;
    }

    glutPostRedisplay();

}

void timer(int x) {
    frame++;
    minigunRotHelper++;
    helpHeli++;

    tankMove -= 0.02;

    //helicopter movement
    //heli up
    if (helpHeli < 135) {
        heliRotY++;
        helimoveY = helimoveY + 0.08;
    }
    //z bend towards
    if (helpHeli > 75 && helpHeli < 135) {
        heliRotZ = heliRotZ + 0.15;
    }
    //move 
    if (helpHeli > 135 && helpHeli < 220) {
        helimoveX = helimoveX - 0.5;
        helimoveZ = helimoveZ + 0.5;
    }
    //z bend back
    if (helpHeli > 170 && helpHeli < 220) {
        heliRotZ = heliRotZ - 0.15;
    }
    //turn back
    if (helpHeli > 220 && helpHeli < 310) {
        heliRotY+=2;
    }
    //z bend towards
    if (helpHeli > 220 && helpHeli < 270) {
        heliRotZ = heliRotZ + 0.15;
    }
    //come back
    if (helpHeli > 310 && helpHeli < 395) {
        helimoveX = helimoveX + 0.5;
        helimoveZ = helimoveZ - 0.5;
    }
    //z bend back
    if (helpHeli > 355 && helpHeli < 405) {
        heliRotZ = heliRotZ - 0.15;
    }
    //down
    if (helpHeli > 405 && helpHeli < 532) {
        helimoveY = helimoveY - 0.08;
        heliRotY++;
    }

   /* if (helpHeli == 150) {
        helimoveX, helimoveZ, heliRotY, helimoveY, heliRotZ, helpHeli = 0;
    }*/


    //minigun rotation
    if (minigunRotHelper < 90) {
        minigunRot+=2;
    }
    else {
        minigunRot = minigunRot - 2;
    }

    if (minigunRotHelper == 180) {
        minigunRotHelper = 0;
    }
   
    glutPostRedisplay();
    glutTimerFunc(60.0, timer, 1);
}

void reshape(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //glOrtho(-10, 10, -10, 10, -1, 1);
    //Define the Perspective projection frustum 
    // (FOV_in_vertical, aspect_ratio, z-distance to the near plane from the camera position, z-distance to far plane from the camera position)
    gluPerspective(120.0, aspect_ratio, 0.5, 100.0);

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize(1200, 1000);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("Gaming Envirnment");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // keyboard function activation
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyPress);
    glutTimerFunc(60.0, timer, 1);
    init();
    glutMainLoop();


    return 0;
}