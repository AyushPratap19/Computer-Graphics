#include<stdlib.h>
#include<GLUT/glut.h>
#include<math.h>
#include<iostream>
using namespace std;
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-300, 300, -300, 300);
	glMatrixMode(GL_MODELVIEW);
}

int shape=0, off_x=0, off_y=0, rot=0, sx=1, sy=1;
/* for a 2d array [p] of [n] points (x,y) ,
		scale by factor [s] ,
		rotate anticlockwise by angle [o] degree,
		translate by [offset_x] horizontally ,
		translate by [offset_y] Vertically

	default values:
		[offset_x]	=>0
		[offset_y]	=>0
		[o]			=>0
		[s]			=>1
	You need to call glFlush() after function
*/
void draw_polygon(float p[][2], int n, double offset_x, double offset_y, double o, double s_x,double s_y) {
	if (n < 1) return;

	//cx,cy are centroid points. x,y are temporary variables
	float cx = 0, cy = 0, x, y;
	

	// convert 'o' from degree to angle
	o = 3.1415 * o / 180.0+3.1415;

	// calculate centroid of given set of points
	for (int i = 0;i < n;i++) {
		cx += p[i][0];
		cy += p[i][1];
	}
	cx /= n;
	cy /= n;


	glBegin(GL_POLYGON);
	for (int i = 0;i < n;i++) {
		// scale based with center as centroid
		x = (cx - p[i][0]) * s_x;
		y = (cy - p[i][1]) * s_y;

		glVertex2f(x* cos(o) - y * sin(o) + cx + offset_x, x* sin(o) + y * cos(o) + cy + offset_y);
	}
	glEnd();
}


void disp() {
	// list of vertices for polygons
	float square[][2] = {
		{ -10,  10 },
		{  10,  10 },
		{  10, -10 },
		{ -10, -10 }
	};
	float triangle[][2] = {
		{ -10,  -10 },
		{  10,  -10 },
		{  0,   10 },
	};
	float house[][2] = {
		{ -10,  10 },
		{	0,  15 },
		{  10,  10 },
		{  10, -10 },
		{ -10, -10 }
	};
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1,1);
	if (shape == 0){
		draw_polygon(square, 4, off_x, off_y, rot, sx,sy);
	}
	else if (shape == 1) {
		draw_polygon(triangle, 3, off_x, off_y, rot, sx, sy);
	}
	else {
		draw_polygon(house, 5, off_x, off_y, rot, sx, sy);
	}
	glFlush();
}

void d_menu(int op) {
	switch (op / 10) {
	case 0:
		shape = 0;
		break;
	case 1:
		shape = 1;
		break;
	case 2:
		shape = 2;
		break;
	}
	switch (op%10) {
	case 3:
		cout << "enter translation values for x and y:";
		cin >> off_x >> off_y;
		break;
	case 4:
		cout << "enter rotation angle:";
		cin >> rot;
		break;
	case 5:
		cout << "enter Scaling values for x and y:";
		cin >> sx >> sy;
		break;
	case 6:
		exit(0);
	}
	glutPostRedisplay();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w > h) {
		gluOrtho2D(-300 * w / (float)h, 300 * w / (float)h, -300, 300);
	}
	else {
		gluOrtho2D(-300, 300, -300 * h / (float)w, 300 * h / (float)w);
	}
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 300);

	glutCreateWindow("Template");
	init();
	glutReshapeFunc(reshape);
	int menu1 = glutCreateMenu(d_menu);
	glutAddMenuEntry("Translate", 3);
	glutAddMenuEntry("Rotate", 4);
	glutAddMenuEntry("Scale", 5);
	int menu2 = glutCreateMenu(d_menu);
	glutAddMenuEntry("Translate", 13);
	glutAddMenuEntry("Rotate", 14);
	glutAddMenuEntry("Scale", 15);
	int menu3 = glutCreateMenu(d_menu);
	glutAddMenuEntry("Translate", 23);
	glutAddMenuEntry("Rotate", 24);
	glutAddMenuEntry("Scale", 25);
	glutCreateMenu(d_menu);
	glutAddSubMenu("Square", menu1);
	glutAddSubMenu("triangle", menu2);
	glutAddSubMenu("house", menu3); 
	glutAddSubMenu("quit", 6); 
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(disp);
	glutMainLoop();
	return 0;
}