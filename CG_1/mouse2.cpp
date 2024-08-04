//change color of the square based on mouse button 
#include <GLUT/glut.h>


float red = 1.0, green = 1.0, blue = 1.0;


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(red, green, blue);
    glBegin(GL_QUADS);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);
    glEnd();
    glFlush();
}
void init()
{
    gluOrtho2D(-1, 1, -1, 1);
}
void mouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        switch (button) {
        case GLUT_LEFT_BUTTON:
            red = 1.0;
            green = 0.0;
            blue = 0.0;
            break;
        case GLUT_MIDDLE_BUTTON:
            red = 0.0;
            green = 1.0;
            blue = 0.0;
            break;
        case GLUT_RIGHT_BUTTON:
            red = 0.0;
            green = 0.0;
            blue = 1.0;
            break;
        }
        glutPostRedisplay();   
    }
}

int main(int argc, char** argv) {
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Mouse Event Handling");


    glClearColor(1.0, 1.0, 1.0, 1.0);
    
   init();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    

  
    glutMainLoop();
    return 0;
}