#include <GLUT/glut.h>
#include <cmath>
#include <cstdlib>

void myinit() {
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 500, 0, 500);
}

void setpixel(int x, int y) {
    glColor3f(0, 0, 1);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void lineDDA() {
    glClear(GL_COLOR_BUFFER_BIT);

    int x0 = 50, y0 = 50, xend = 100, yend = 100;
    int dx = xend - x0, dy = yend - y0, steps, k;
    float xin, yin, x = x0, y = y0;

    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);

    xin = dx / (float)steps;
    yin = dy / (float)steps;

    setpixel(std::round(x), std::round(y));

    for (k = 0; k < steps; k++) {
        x += xin;
        y += yin;
        setpixel(std::round(x), std::round(y));
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing");
    myinit();
    glutDisplayFunc(lineDDA);
    glutMainLoop();
    return 0;
}
