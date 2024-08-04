#include <stdlib.h>
#include <GLUT/glut.h>

float angleX = 0.0, angleY = 0.0, angleZ = 0.0;
float scale = 1.0;
float translateX = 0.0, translateY = 0.0, translateZ = 0.0;

float translationMatrix[16];

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

void setTranslationMatrix(float x, float y, float z) {
    translationMatrix[0] = 1.0; translationMatrix[4] = 0.0; translationMatrix[8] = 0.0; translationMatrix[12] = x;
    translationMatrix[1] = 0.0; translationMatrix[5] = 1.0; translationMatrix[9] = 0.0; translationMatrix[13] = y;
    translationMatrix[2] = 0.0; translationMatrix[6] = 0.0; translationMatrix[10] = 1.0; translationMatrix[14] = z;
    translationMatrix[3] = 0.0; translationMatrix[7] = 0.0; translationMatrix[11] = 0.0; translationMatrix[15] = 1.0;
}

void applyTranslation() {
    glMultMatrixf(translationMatrix);
}

void drawCube() {
    glBegin(GL_QUADS);

    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);

    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);

    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);

    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    setTranslationMatrix(translateX, translateY, translateZ);
    applyTranslation();
    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);
    glRotatef(angleZ, 0.0, 0.0, 1.0);
    glScalef(scale, scale, scale);
    drawCube();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'x': angleX += 5.0; break;
    case 'X': angleX -= 5.0; break;
    case 'y': angleY += 5.0; break;
    case 'Y': angleY -= 5.0; break;
    case 'z': angleZ += 5.0; break;
    case 'Z': angleZ -= 5.0; break;
    case 's': scale += 0.1; break;
    case 'S': scale -= 0.1; break;
    case 't': translateX += 0.1; break;
    case 'T': translateX -= 0.1; break;
    case 'u': translateY += 0.1; break;
    case 'U': translateY -= 0.1; break;
    case 'v': translateZ += 0.1; break;
    case 'V': translateZ -= 0.1; break;
    case 27: exit(0); break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Transformations");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
