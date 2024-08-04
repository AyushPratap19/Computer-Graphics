//2d tranformations with builtin
#include<stdlib.h>
#include<GLUT/glut.h>

float angle = 0.0;
float scale = 1.0;
float translateX = 0.0;
float translateY = 0.0;


void initGL() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}
void reshape(int w, int h) {
	glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w > h) {
		
		gluOrtho2D(-10.0 * (float)w / (float)h, 10.0 * (float)w / (float)h, -10.0, 10.0);	
	}
	else {
		
		gluOrtho2D(-10.0, 10.0, -10.0 * (float)h / (float)w, 10.0 * (float)h / (float)w);	
	}
    glMatrixMode(GL_MODELVIEW);
	
}
void display() {
	 glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);

	glLoadIdentity();
	
	glTranslatef(translateX, translateY, 0.0);
	glScalef(scale, scale, 1.0);
	glRotatef(angle, 0.0, 0.0, 1.0);

	glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 5.0);
	glVertex2f(-5.0, -5.0);
	glVertex2f(5.0, -5.0);
	
	glEnd();
	glFlush();

}
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':angle += 5.0;
		     break;
	case 'd':angle -= 5.0;
		     break;
	case 'w':scale += 0.1;
		     reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
			 break;
	case 's':if (scale > 0.1) {
				scale -= 0.1;
	         }
			 reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
			 break;
	case 'i':translateY += 0.5;
		     break;
	case 'k':translateY -= 0.5;
		     break;
	case 'j':translateX -= 0.5;
		     break;
	case 'l':translateX += 0.5;
		     break;
	case 27:exit(0);
		    break;

	}
	glutPostRedisplay();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("2D Geometric Operations using buit in functions");
	initGL();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}