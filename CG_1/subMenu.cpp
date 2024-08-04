#include<stdio.h>
#include<stdlib.h>
#include<GLUT/glut.h>

int squaresize = 100;
float squareColor[3] = { 1.0,1.0,1.0 };

void drawSquare() {
	glColor3fv(squareColor);
	glBegin(GL_QUADS);
	glVertex2i(100, 100);
	glVertex2i(100 + squaresize, 100);
	glVertex2i(100 + squaresize, 100 + squaresize);
	glVertex2i(100, 100 + squaresize);
	glEnd();
}

void menu(int value) {

	switch (value) {
		case 11:squaresize += 10;
		        break;

		case 'a':if (squaresize > 10) {
			         squaresize -= 10;
			         break;
				 }
		
		case 3:squareColor[0] = 1.0;
			   squareColor[1] = 0.0;
			   squareColor[2] = 0.0;
			   break;

		case 4:squareColor[0] = 0.0;
			   squareColor[1] = 1.0;
			   squareColor[2] = 0.0;
			   break;

		case 5:squareColor[0] = 0.0;
			   squareColor[1] = 0.0;
			   squareColor[2] = 1.0;
			   break;

		case 6:exit(0);
						   		
	}
	glutPostRedisplay();
}
void createMenu() {
	int submenu;
	submenu = glutCreateMenu(menu);
	glutAddMenuEntry("Green", 4);
	glutAddMenuEntry("Red", 3);
	glutAddMenuEntry("Blue", 5);
	glutCreateMenu(menu);
	glutAddSubMenu("Change Color", submenu);
	glutAddMenuEntry("Increase size", 11);
	glutAddMenuEntry("Decrease size", 'a');
	glutAddMenuEntry("Quit", 6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void init(int windowwidth, int windowHeight) {
	gluOrtho2D(0, windowwidth, 0, windowHeight);
	glClearColor(0.0, 0.0, 0.0, 1.0);
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawSquare();
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("SubMenuProgram");
	init(400,600);
	glutDisplayFunc(display);
	createMenu();
	glutMainLoop();
}