//square that can resize,move and change its color
//how to run:-
//g++ mini.cpp -o f -framework OpenGL -framework GLUT
//./subAct
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include<stdio.h>

float x = 400;
float y = 300;
float size = 25;
float r = 1.0, g = 1.0, b = 1.0;


void display() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x + size, y + size);
    glVertex2f(x - size, y + size);
    glVertex2f(x - size, y - size);
    glVertex2f(x + size, y - size);
    glEnd();
    glFlush();
}

void init() {

    //glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}
void keyboard(unsigned char key, int x1, int y1) {
    switch (key) {
    case 'w':
        ::y = y + 10;
        break;
    case 'a': 
        ::y = y - 10;
        break;
    case 's':
        ::x = x + 10;
        break;
    case 'd':
        ::x = x - 10;
        break;
    case '+':size = size + 10;
        break;
    case '-':size = size - 10;
        break;
    case 'r':r = 1.0;
        g = 0.0;
        b = 0.0;
        break;
    case 'g':r = 0.0;
        g = 1.0;
        b = 0.0;
        break;
    case 'b':r = 0.0;
        g = 0.0;
        b = 1.0;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
  
    glutCreateWindow("Square");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}