#include <GLUT/glut.h>
#include<stdio.h>
#include<stdlib.h>
 
 float red = 1.0, green = 1.0, blue = 1.0;

 void init() {

    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0.0, 640.0, 0.0, 680.0);
}

 void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(red, green, blue);
    glBegin(GL_QUADS);
    glVertex2f(200.0, 200.0);
    glVertex2f(400.0, 200.0);
    glVertex2f(400.0, 400.0);
    glVertex2f(200.0, 400.0);
    glEnd();
    glFlush();
}
void keyboard(unsigned char key,int x,int y)
{
    switch (key)
    {
    case 'r':
         red=1.0;
         green = 0.0;
         blue = 0.0;
        break;
    case 'g':
         red=0.0;
         green = 1.0;
         blue = 0.0;
        break;
    case 'b':
         red=0.0;
         green = 0.0;
         blue = 1.0;
        break;        
    case 27://esc key
         exit(0);
    
    }
    glutPostRedisplay(); 
}

int main(int argc, char** argv) {
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Keyboard Event Handling");
    
   init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}