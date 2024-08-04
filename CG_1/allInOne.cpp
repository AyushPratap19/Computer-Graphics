#include <GLUT/glut.h>
#include<cmath>
void myInit()
{
    glClearColor(1, 1, 1, 1);
	gluOrtho2D(0, 500,0, 500);

}
void displaypoints()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glColor3f(0, 1, 0);
	glVertex2i(100, 100);
	glColor3f(1, 0, 0);
	glVertex2i(150, 200);
	glEnd();
	glFlush();
}
void displayLines() {
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(10, 10);
	glVertex2f(60, 70);
	glVertex2f(60, 70);
	glVertex2f(10, 100);
	glVertex2f(60, 70);
	glVertex2f(100, 100);
	glVertex2f(60, 70);
	glVertex2f(100, 10);


	glEnd();
	glFlush();
}
void displayhouse() {
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(1, 0.4, 0);
	glVertex2f(10, 10);
	glVertex2f(10, 70);
	glVertex2f(70, 70);
	glVertex2f(70, 10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(10, 70);
	glVertex2f(70, 70);
	glVertex2f(40, 100);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.4);
	glColor3f(1, 0.7, 1);
	glVertex2f(30, 10);
	glVertex2f(50, 10);

	glVertex2f(50, 30);
	glVertex2f(30, 30);
	glEnd();
	glFlush();
}
void displaysquare()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2i(50, 50);
	glVertex2i(150, 50);
	glVertex2i(150, 150);
	glVertex2i(50, 150);
	glEnd();
	glFlush();
}
void displayrectangle()

{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2i(50, 50);
	glVertex2i(200, 50);
	glVertex2i(200, 300);
	glVertex2i(50, 300);
	glEnd();
	glFlush();
}
void displaycircle()

{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	int i;
	double angle;
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	for (i = 0; i <= 36; i++)
	{
		angle = (3.14 / 18) * i;
		glVertex2f(250+40 * cos(angle), 250+40 * sin(angle));
	}
	glEnd();
	glFlush();
}
int main(int argc, char** argv)  {
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Displaying...");
	myInit();
	glutDisplayFunc(displaycircle);

	glutMainLoop();

}