//interactive DDA
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <iostream>
#include <cmath>

int x_1, y_1, x_2, y_2, var = 1;

void setpixel(int x, int y) {
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

inline int Round(float a) {
    return static_cast<int>(a + 0.5);
}

void display() {
    glFlush();
}

void Line_DDA() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    int dx = x_2 - x_1, dy = y_2 - y_1, steps, k;
    float xincr, yincr, x = x_1, y = y_1;

    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);

    xincr = dx / static_cast<float>(steps);
    yincr = dy / static_cast<float>(steps);

    setpixel(Round(x), Round(y));
    for (k = 0; k < steps; k++) {
        x += xincr;
        y += yincr;
        setpixel(Round(x), Round(y));
    }

    glFlush();
}

void myinit() {
    gluOrtho2D(0, 500, 0, 500);
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        if (var == 1) {
            x_1 = x;
            y_1 = 500 - y; 
            std::cout << "First Point: (" << x_1 << ", " << y_1 << ")" << std::endl;
            var++;
        }
        else {
            x_2 = x;
            y_2 = 500 - y; 
            std::cout << "Second Point: (" << x_2 << ", " << y_2 << ")" << std::endl;
            Line_DDA();
            var = 1; // Reset for next line
        }
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA LINE DRAWING ALGORITHM");
    myinit();
    glutMouseFunc(mouse);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}