#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include<stdlib.h>

static double x[10] = {0}, x2 = 0.0, r1 = 0.0;
static double yaxis[10] = {-15, -15, -15, -15, -15, -15, -15, -15, -15, -15};
static int max = 0;
static bool takeOff = false;

void stroke_output(GLfloat x, GLfloat y, char *format, ...) {
    va_list args;
    char buffer[200], *p;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
    glPushMatrix();
    glTranslatef(-2.5, y, 0);
    glScaled(0.003, 0.005, 0.005);
    for (p = buffer; *p; p++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    glPopMatrix();
}

// Runway strip
void strip(float x1) {
    glPushMatrix();
    glRotatef(-65, 0, 1, 0);
    glColor3f(1, 1, 1);
    glTranslatef(x1, -3.5, 7.8);
    glScaled(1, 0.15, 0.1);
    glutSolidCube(1);
    glPopMatrix();
}

void drawPlane(float y1) {
    glPushMatrix();

    // Main Body
    glPushMatrix();
    glScalef(.3, 0.3, 1.5);
    if (y1 <= 15)
        glColor3f(1, 1.0, 0.5);
    if (y1 >= 15)
        glColor3f(1, 0.3, 0.5);
    glutSolidSphere(2.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.1, -1.8);
    glScalef(1.0, 1, 1.5);
    glColor3f(0, 0, 1);
    glutSolidSphere(0.5, 25, 25);
    glPopMatrix();

    // Left Fin
    glPushMatrix();
    glTranslatef(-1.0, 0, 0);
    glScalef(1.5, 0.1, 0.5);
    glColor3f(0, 0, 0);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    // Right Fin
    glPushMatrix();
    glTranslatef(1.0, 0, 0);
    glScalef(1.5, 0.1, 0.5);
    glColor3f(0, 0, 0);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    // Right Tail fin
    glPushMatrix();
    glTranslatef(0.8, 0, 2.4);
    glScalef(1.2, 0.1, 0.5);
    glColor3f(0.0, 0, 0);
    glutSolidSphere(0.4, 50, 50);
    glPopMatrix();

    // Left Tail fin
    glPushMatrix();
    glTranslatef(-0.8, 0, 2.4);
    glScalef(1.2, 0.1, 0.5);
    glColor3f(0.0, 0, 0);
    glutSolidSphere(0.4, 50, 50);
    glPopMatrix();

    // Top tail fin
    glPushMatrix();
    glTranslatef(0, 0.5, 2.4);
    glScalef(0.1, 1.1, 0.5);
    glColor3f(0.0, 0, 0);
    glutSolidSphere(0.4, 50, 50);
    glPopMatrix();

    // Blades
    glPushMatrix();
    glRotatef(x2, 0.0, 0.0, 1.0);

    glPushMatrix();
    glTranslatef(0, 0.0, -3.0);
    glScalef(1.5, 0.2, 0.1);
    glColor3f(0.0, 0, 0);
    glutSolidSphere(0.3, 50, 50);
    glPopMatrix();

    // Blades
    glPushMatrix();
    glRotatef(90, 0.0, 0.0, 1.0);
    glTranslatef(0, 0.0, -3.0);
    glScalef(1.5, 0.2, 0.1);
    glColor3f(0.0, 0, 0);
    glutSolidSphere(0.3, 50, 50);
    glPopMatrix();

    glPopMatrix();

    // Front Wheels
    glPushMatrix();
    glTranslatef(0.0, -0.8, -1.5);
    glRotatef(90, 0.0, 1, 0);
    glScaled(0.3, 0.3, 0.3);
    glutSolidTorus(0.18, 0.5, 25, 25);
    glColor3f(1, 1, 1);
    glutSolidTorus(0.2, 0.1, 25, 25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, -0.4, -1.5);
    glRotatef(20, 0.0, 1, 0);
    glScaled(0.05, 0.3, 0.05);
    glutSolidSphere(1.0, 25, 25);
    glPopMatrix();

    // Rear Wheels
    glPushMatrix();
    glTranslatef(0.3, -0.8, 0.7);
    glRotatef(90, 0.0, 1, 0);
    glScaled(0.3, 0.3, 0.3);
    glColor3f(0, 0, 0);
    glutSolidTorus(0.18, 0.5, 25, 25);
    glColor3f(1, 1, 1);
    glutSolidTorus(0.2, 0.1, 25, 25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, -0.4, 0.7);
    glRotatef(20, 0.0, 1, 0);
    glScaled(0.05, 0.3, 0.05);
    glutSolidSphere(1.0, 25, 25);
    glPopMatrix();

    // Rear 2
    glPushMatrix();
    glTranslatef(-0.3, -0.8, 0.7);
    glRotatef(90, 0.0, 1, 0);
    glScaled(0.3, 0.3, 0.3);
    glColor3f(0, 0, 0);
    glutSolidTorus(0.18, 0.5, 25, 25);
    glColor3f(1, 1, 1);
    glutSolidTorus(0.2, 0.1, 25, 25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3, -0.4, 0.7);
    glRotatef(20, 0.0, 1, 0);
    glScaled(0.05, 0.3, 0.05);
    glutSolidSphere(1.0, 25, 25);
    glPopMatrix();

    glPopMatrix();
}

void animate(float y1, float x1) {
    // Plane Transition
    glPushMatrix();
    
    // Move the Plane towards rotating zone
    if (y1 <= -2) {
        glTranslatef(5.5 + y1, 3, 0);
        glRotatef(-90, 0, 1, 0);
    }
    
    // Move the Plane towards 2nd runway
    if (takeOff) {
        if (y1 >= 15) {
            glRotatef(140, 0, 1, 0);
            if (y1 >= 15 && y1 <= 20)
                glTranslatef(2 + 15 - y1, -3, -3);
            if (y1 >= 20)
                glTranslatef(2 + 15 - y1, -3 - 20 + y1, -3);
        }
    }

    // Keep rotating the plane
    if (y1 >= -2 && y1 <= 2) {
        glTranslatef(3.0, 3.0, 0.0);
    }

    // Start descending the plane
    if (y1 >= 2 && y1 <= 6.5) {
        glTranslatef(3, 3 - y1 + 2, 0);
    }

    // Move towards runway
    if (y1 >= 6.5 && y1 <= 8.2) {
        glTranslatef(3 - y1 + 6.5, 3 - y1 + 2, 0);
    }

    // Landing only change the x-axis
    if (y1 >= 8.2 && y1 <= 15) {
        glTranslatef(3 - y1 + 6.5, 3 - 8.2 + 2, 0);
    }

    // Rotate the plane about its own axis w.r.t y-axis.
    if (y1 >= -2) {
        glRotatef(x1, 0, 1, 0);
    }

    glPushMatrix();
    // Move the plane away from its axis
    glTranslatef(1, 0, 0);
    glScaled(0.3, 0.3, 0.15);

    // Tilt the plane until it's being rotated
    if (y1 <= 8.2) {
        if (yaxis[0] >= -2) {
            glRotatef(15, 0, 0, 1);
        }
    }

    if (y1 <= 15) {
        drawPlane(y1);
    }
    
    if (y1 >= 15 && takeOff) {
        drawPlane(y1);
    }

    glPopMatrix();
    glPopMatrix();
}


void Runway() {
    // Road
    glPushMatrix();
    glTranslatef(0, -3.5, 0);
    glScaled(20, 0.1, 2);
    glColor3f(0.5, 0.5, 0.5);
    glutSolidCube(1);
    glPopMatrix();

    // Rotate Strip
    strip(-0.5);
    strip(1.5);

    // Main Runway Strip
    glPushMatrix();
    for (int i = 0; i < 10; i++) {
        glTranslatef(1.5, 0, 0);
        strip(x[i]);
    }
    glPopMatrix();

    // Top Runway Strip
    glPushMatrix();
    for (int i = 0; i < 10; i++) {
        glTranslatef(-1.5, 0, 0);
        strip(x[i]);
    }
    glPopMatrix();

    // Rotate Strip
    strip(-x2 - 0.5);
    strip(-x2 + 1.5);
}

void airport() {
    glPushMatrix();

    // Grass
    glPushMatrix();
    glTranslatef(0, -3.5, 0);
    glScaled(60, 0.1, 20);
    glColor3f(0.0, 1.0, 0.0);
    glutSolidCube(1);
    glPopMatrix();

    // Runway
    glPushMatrix();
    glTranslatef(0, 0, 0);
    Runway();
    glPopMatrix();

    // Tower
    glPushMatrix();
    glTranslatef(14, -3.5, 0);
    glScaled(1, 10, 1);
    glColor3f(0.8, 0.8, 0.8);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(14, 2.5, 0);
    glScaled(2, 1, 2);
    glColor3f(0.0, 0.5, 0.8);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(14, -2.5, 0);
    glScaled(1, 8, 1);
    glColor3f(0.0, 0.5, 0.8);
    glutWireCube(1);
    glPopMatrix();

    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 2.0, 35, 0.0, 0.0, 0.0, 0, 1, 0);

    glPushMatrix();
    airport();
    glPopMatrix();

    animate(r1, x2);

    if (r1 < 100)
        r1 += .05;
    if (r1 > 15)
        takeOff = true;
    x2 += 0.02;

    for (int i = 0; i < 10; i++) {
        if (x[i] <= -1)
            x[i] = 0;
        else
            x[i] -= .001;
    }

    glutSwapBuffers();
}

void resize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / h, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

void mouse(int btn, int state, int x, int y) {
    switch (btn) {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            max = (max - 50) % 100;
        break;
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
            max = ((max + 50) % 100);
        break;
    }
    glutPostRedisplay();
}

void menu(int item) {
    switch (item) {
    case 1:
        max = 10;
        break;
    case 2:
        max = 100;
        break;
    case 3:
        max = 50;
        break;
    case 4:
        exit(0);
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Airplane Animation");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutIdleFunc(display);
    glutMouseFunc(mouse);
    

    glutCreateMenu(menu);
    glutAddMenuEntry("Runway 10", 1);
    glutAddMenuEntry("Runway 100", 2);
    glutAddMenuEntry("Runway 50", 3);
    glutAddMenuEntry("Exit", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
