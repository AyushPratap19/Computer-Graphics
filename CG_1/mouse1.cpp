//Program to demonstrate mouse event handling function
//where ever we click a square will come
#include<stdio.h> 
#include<stdlib.h> 
#include<GLUT/glut.h>
int wh = 500, ww = 500; float siz = 3;
void myinit()
{
    
    
    gluOrtho2D(0, wh, 0, ww);// xmin, xmax, ymin, ymax    
    
}
void drawsq(int x, int y)
{
    y = wh - y;
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(x + siz, y + siz);
    glVertex2f(x - siz, y + siz);
    glVertex2f(x - siz, y - siz);
    glVertex2f(x + siz, y - siz);
    glEnd();
    glFlush();
}
void display()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}
void myMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        drawsq(x, y);
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        exit(0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(wh, ww);
    glutCreateWindow("square");
    glutDisplayFunc(display);
    glutMouseFunc(myMouse);
    myinit();
    glutMainLoop();
}