#include <GLUT/glut.h>
#include<stdio.h>
#include<stdlib.h>
 
int wh = 640, ww = 480, size = 5;

 void init() {

    
    gluOrtho2D(0.0, ww, 0.0, wh);
}

 void display() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0,1);
    glBegin(GL_POLYGON);
     glVertex2f(250.0 + size, 250.0 + size);
    glVertex2f(250.0 - size, 250.0 + size);
    glVertex2f(250.0 - size, 250.0 - size);
    glVertex2f(250.0 + size, 250.0 - size);
    glEnd();
    glFlush();
}
void dmenu(int op)
{
    switch (op)
    {
    case 1:
         size+=5;
        break;
    case 2:
         size-=5;
        break;
    case 3:
         size=0;
        break;        
    case 4://esc key
         exit(0);
    
    }
    glutPostRedisplay();  
}
void keyboard(unsigned char key,int x,int y)
{
    switch (key)
    {
    case 'i':
         size+=5;
        break;
    case 'd':
         size-=5;
        break;
    case 'r':
         size=0;
        break;        
    case 27://esc key
         exit(0);
    
    }
    glutPostRedisplay(); 
}

int main(int argc, char** argv) {
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(ww, wh);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Menu");
    
   init();
    glutCreateMenu(dmenu);
    glutAddMenuEntry("Increase",1);
    glutAddMenuEntry("decrease",2);
    glutAddMenuEntry("refresh",3);
    glutAddMenuEntry("quit",4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}