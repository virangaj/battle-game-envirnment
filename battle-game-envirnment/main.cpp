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
GLfloat steps = 0.1f;

GLboolean door_open = false;

GLfloat door_Angle = 0.0;


void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
}


void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t * 90.0;
    double aa = a;

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    gluLookAt(5.0 + camX, 5.0 + camY, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    /* set material parameters */
    const GLfloat blue[4] = { 0.3, 0.3, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
    const GLfloat matwhite[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glMaterialfv(GL_FRONT, GL_SPECULAR, matwhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 128.0f);

    /* positioned the light source 1 */
    GLfloat position0[] = { 10.0,10.0,10.0,1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, position0);

    /* set light intensities for light source 1 */
    GLfloat paleYellow[] = { 1.0,1.0,0.75,1.0 };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, paleYellow);
    GLfloat white[] = { 1.0,1.0,1.0,1.0 };
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);

    /* positioned the light source 2 */
    GLfloat position1[] = { -10.0,10.0,-10.0,1.0 };
    glLightfv(GL_LIGHT1, GL_POSITION, position1);

    /* set light intensities for light source 2 */
    glLightfv(GL_LIGHT1, GL_DIFFUSE, paleYellow);
    GLfloat green[] = { 0.0,1.0,0.0,1.0 };
    glLightfv(GL_LIGHT1, GL_SPECULAR, green);




    glTranslatef(sceX, sceY, sceZ);
    // glRotatef(sRy, 0, 1, 0);
     //house

    glPushMatrix();
    //watchTower();
    drawGrid();



    glPushMatrix();
    glRotated(aa, 0, 1, 0);
    glTranslatef(-10, 10, -10);
    glRotatef(-30, 0, 0, 1);
    // groupPlanes();
    glPopMatrix();

    terrain();
    ground();

    //artilleryShell();
    //artilleryAmmoCrate();
    glPushMatrix();
    arteryGun();
    glPopMatrix();
    
    drawAxis();
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

    switch (key)
    {
    case 'q':
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

        break;
    case 'r':
        sRy -= 1;
        break;
    case 'l':
        sRy += 1;
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
    case '1':
        glEnable(GL_LIGHT0);
        break;
    case '!':
        glDisable(GL_LIGHT0);
        break;
    case '2':
        glEnable(GL_LIGHT1);
        break;
    case '@':
        glDisable(GL_LIGHT1);
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
    glutInitWindowSize(500, 500);
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