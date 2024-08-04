#include <cstring>
#include <iostream>
#include <GLUT/glut.h>
using namespace std;


const int w = 800;
const int h = 600;

char userInput[256];
int PosX = w / 2;
int PosY = h / 2;
float textColor[3] = {1.0f, 1.0f, 1.0f}; 
int verticalMove = 0;
int horizontalMove = 0;
int Speed = 1;

void renderString(float x, float y, const char *string) {
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(textColor[0], textColor[1], textColor[2]);
    renderString(PosX,PosY, userInput);

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, w, 0.0, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
        case 'A':
            textColor[0] = 1.0f; 
            textColor[1] = 0.0f;
            textColor[2] = 0.0f;
            break;
        case 's':
        case 'S':
            verticalMove = (verticalMove == 0) ? 1 : 0; 
            break;
        case 'd':
        case 'D':
            horizontalMove = (horizontalMove == 0) ? 1 : 0; 
            break;
        case 'f':
        case 'F':
            Speed++;
            break;
        case 'q':
           exit(0);

    }
    glutPostRedisplay();
}

void idle() {
    if (verticalMove) {
        PosY += Speed;
        if (PosY > h) PosY = 0;
    }
    if (horizontalMove) {
        PosX += Speed;
        if (PosX > w) PosX = 0;
    }

    
    if (PosX < 0) PosX = 0;
    if (PosX > w) PosX = w;
    if (PosY < 0) PosY = 0;
    if (PosY > h) PosY = h;

    glutPostRedisplay();
}

int main(int argc, char **argv) {
    cout << "Enter a string to display: ";
    cin.getline(userInput, 256);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(w, h);
    glutCreateWindow("Interactive Text Display");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);

    glClearColor(0.0, 0.0, 0.0, 0.0); 

    glutMainLoop();
    return 0;
}
