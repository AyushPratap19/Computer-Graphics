#include<iostream>
#include<GLUT/glut.h>
using namespace std;

char str[20] = "RNSIT";
int cx1 = 50, cy1 = 100, cx2 = 20, cy2 = 100, d = 10;

void display1()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);

	glRasterPos2i(cx1, cy1);
	int i, j;
	long int k;
	for (int j = 0; j < 100; j++)
	{
		glRasterPos2i(cx1 + 5 * j, cy1);
		for (int i = 0; i < strlen(str); i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
		glFlush();

		for (k = 0; k < 650000000; k++);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1, 0, 0);
	}

	glFlush();

}

void myinit()
{
	gluOrtho2D(0, 200, 0, 200);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 100);

	glutCreateWindow("TEXT MOVING");
	myinit();
	glutDisplayFunc(display1);
	glutMainLoop();
}