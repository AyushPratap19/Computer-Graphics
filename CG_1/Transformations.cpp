#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <GLUT/glut.h>
using namespace std;

enum Shape { NONE, TRIANGLE, SQUARE, HOUSE };
Shape currentShape = NONE;

float translationX = 0.0f, translationY = 0.0f;
float rotationAngle = 0.0f;
float scaleX = 1.0f, scaleY = 1.0f;

void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
}

void drawSquare() {
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
}

void drawHouse() {
    glBegin(GL_QUADS); 
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(-0.5f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES); 
    glVertex2f(-0.5f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
}

void applyTransformations() {
    float transformedVertices[8];
    float vertices[8];

    // Set vertices based on current shape
    if (currentShape == TRIANGLE) {
        vertices[0] = -0.5f; vertices[1] = -0.5f;
        vertices[2] = 0.5f; vertices[3] = -0.5f;
        vertices[4] = 0.0f; vertices[5] = 0.5f;
        vertices[6] = 0.0f; vertices[7] = 0.0f; // not used, but to avoid out of bounds
    } else if (currentShape == SQUARE) {
        vertices[0] = -0.5f; vertices[1] = -0.5f;
        vertices[2] = 0.5f; vertices[3] = -0.5f;
        vertices[4] = 0.5f; vertices[5] = 0.5f;
        vertices[6] = -0.5f; vertices[7] = 0.5f;
    } else if (currentShape == HOUSE) {
        vertices[0] = -0.5f; vertices[1] = -0.5f;
        vertices[2] = 0.5f; vertices[3] = -0.5f;
        vertices[4] = 0.5f; vertices[5] = 0.0f;
        vertices[6] = -0.5f; vertices[7] = 0.0f;
    }

    // Apply transformations
    for (int i = 0; i < 8; i += 2) {
        // Apply scaling
        float x = vertices[i] * scaleX;
        float y = vertices[i+1] * scaleY;

        // Apply rotation
        float xRotated = x * cos(rotationAngle * M_PI / 180.0) - y * sin(rotationAngle * M_PI / 180.0);
        float yRotated = x * sin(rotationAngle * M_PI / 180.0) + y * cos(rotationAngle * M_PI / 180.0);

        // Apply translation
        transformedVertices[i] = xRotated + translationX;
        transformedVertices[i+1] = yRotated + translationY;
    }

    // Draw the transformed shape
    if (currentShape == TRIANGLE) {
        glBegin(GL_TRIANGLES);
        glVertex2f(transformedVertices[0], transformedVertices[1]);
        glVertex2f(transformedVertices[2], transformedVertices[3]);
        glVertex2f(transformedVertices[4], transformedVertices[5]);
        glEnd();
    } else if (currentShape == SQUARE) {
        glBegin(GL_QUADS);
        glVertex2f(transformedVertices[0], transformedVertices[1]);
        glVertex2f(transformedVertices[2], transformedVertices[3]);
        glVertex2f(transformedVertices[4], transformedVertices[5]);
        glVertex2f(transformedVertices[6], transformedVertices[7]);
        glEnd();
    } else if (currentShape == HOUSE) {
        // Draw base
        glBegin(GL_QUADS);
        glVertex2f(transformedVertices[0], transformedVertices[1]);
        glVertex2f(transformedVertices[2], transformedVertices[3]);
        glVertex2f(transformedVertices[4], transformedVertices[5]);
        glVertex2f(transformedVertices[6], transformedVertices[7]);
        glEnd();

        // Draw roof
        float roofVertices[6];
        roofVertices[0] = transformedVertices[0]; roofVertices[1] = transformedVertices[5];
        roofVertices[2] = transformedVertices[2]; roofVertices[3] = transformedVertices[5];
        roofVertices[4] = (transformedVertices[0] + transformedVertices[2]) / 2; roofVertices[5] = transformedVertices[5] + 0.5f * scaleY;

        glBegin(GL_TRIANGLES);
        glVertex2f(roofVertices[0], roofVertices[1]);
        glVertex2f(roofVertices[2], roofVertices[3]);
        glVertex2f(roofVertices[4], roofVertices[5]);
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    applyTransformations();
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void promptTranslation() {
    cout << "Enter translation values (dx, dy): ";
    cin >> translationX >> translationY;
    glutPostRedisplay();
}

void promptRotation() {
    cout << "Enter rotation angle: ";
    cin >> rotationAngle;
    glutPostRedisplay();
}

void promptScaling() {
    cout << "Enter scaling factors (sx, sy): ";
    cin >> scaleX >> scaleY;
    glutPostRedisplay();
}

void shapeMenu(int option) {
    currentShape = static_cast<Shape>(option);
    glutPostRedisplay();
}

void transformMenu(int option) {
    switch (option) {
        case 1:
            promptTranslation();
            break;
        case 2:
            promptRotation();
            break;
        case 3:
            promptScaling();
            break;
    }
}

void createMenu() {
    int shapeSubMenu = glutCreateMenu(shapeMenu);
    glutAddMenuEntry("Triangle", TRIANGLE);
    glutAddMenuEntry("Square", SQUARE);
    glutAddMenuEntry("House", HOUSE);

    int transformSubMenu = glutCreateMenu(transformMenu);
    glutAddMenuEntry("Translate", 1);
    glutAddMenuEntry("Rotate", 2);
    glutAddMenuEntry("Scale", 3);

    glutCreateMenu(shapeMenu); // Directly using shapeMenu function
    glutAddSubMenu("Shapes", shapeSubMenu);
    glutAddSubMenu("Transformations", transformSubMenu);
    glutAddMenuEntry("Exit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Transformations");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    createMenu();

    glutMainLoop();
    return 0;
}
