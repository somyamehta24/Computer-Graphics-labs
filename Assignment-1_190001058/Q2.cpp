// 190001058
// Somya Mehta
// Q2. Create a House
#include <GL/glut.h>
#include <iostream>
#include <GL/glu.h>
#include <math.h>
using namespace std;
// create triangle
void createTriangle(int x1, int x2, int x3, int y1, int y2, int y3) {
    glBegin(GL_POLYGON);

    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);

    glEnd();
}
// create rectangle
void rectangle(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4) {
    glBegin(GL_POLYGON);

    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glVertex2i(x4, y4);

    glEnd();
}
void House(void) {
    // Clear the screen buffer
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(4.0);

    // base of hut
    glColor3f(1.0, 1.0, 0.84f);
    rectangle(260, 400, 400, 260, 260, 260, 400, 400);

    // Hut's triangle part
    glColor3f(0.80, 0.4, 0.11);
    createTriangle(330, 420, 240, 540, 400, 400);

    // Left Window

    glColor3f(0.0f, 1.0f, 1.0f);
    rectangle(270, 300, 300, 270, 340, 340, 370, 370);

    // Gate
    glColor3f(0.80, 0.4, 0.11);
    rectangle(315, 350, 350, 315, 260, 260, 340, 340);

    // Right Window
    glColor3f(0.0f, 1.0f, 1.0f);
    rectangle(360, 390, 390, 360, 340, 340, 370, 370);

    // Door Knob
    glColor3f(1.0, 1.0, 0);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 360; i++) {
        float theta = i * 3.142 / 180;
        glVertex2f(320 + 3 * cos(theta), 310 + 3 * sin(theta));
    }

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1200, 1200);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("House");

    // Clear the screen color
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Specify the display area
    gluOrtho2D(100.0, 600.0, 150.0, 600.0);
    glutDisplayFunc(House);  // Creates the window and sets the title

    glutMainLoop();

    return 0;
}