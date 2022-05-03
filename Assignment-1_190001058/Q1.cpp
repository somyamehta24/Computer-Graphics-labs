// 190001058
// Somya Mehta
// Q1. Construct a tree
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <GL/glu.h>
using namespace std;
// create a Triangle
void createTriangle(int x1, int x2, int x3, int y1, int y2, int y3) {
    glBegin(GL_POLYGON);

    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);

    glEnd();
}
// create a Rectangle
void rectangle(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4) {
    glBegin(GL_POLYGON);

    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glVertex2i(x4, y4);

    glEnd();
}
void Tree(void) {
    // Clear the screen buffer
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(4.0);

    // 3 triangles of Tree
    glColor3f(0.0f, 1.0f, 0.0f);

    createTriangle(400, 320, 360, 400, 400, 500);

    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_LINE_LOOP);

    glVertex2i(400, 400);
    glVertex2i(320, 400);
    glVertex2i(360, 500);

    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    createTriangle(400, 320, 360, 360, 360, 460);

    glColor3f(0.0f, 1.0f, 0.0f);

    createTriangle(400, 320, 360, 320, 320, 420);

    // creating base of tree
    glColor3f(1.0f, 0.0f, 0.0f);
    rectangle(350, 370, 370, 350, 320, 320, 280, 280);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1200, 1200);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("Tree");

    // Clear the screen color
    glClearColor(0, 1.0, 0.9, 1.0);

    // Specify the display area
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
    glutDisplayFunc(Tree);  // Creates the window and sets the title

    glutMainLoop();

    return 0;
}
