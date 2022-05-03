// 190001058
// Somya Mehta
// Q3. Construct a BiCycle
#include <GL/glut.h>
#include <iostream>
#include <GL/glu.h>
#include <math.h>
using namespace std;
// create concentric circle
void createcircle(int x1, int y1, int r) {
    float theta;
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_POINTS);

    for (int i = 0; i < 366; i++) {
        theta = i * 3.142 / 180;
        glVertex2f(x1 + r * cos(theta), y1 + r * sin(theta));
    }

    glEnd();
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);

    for (int i = 0; i < 366; i++) {
        theta = i * 3.142 / 180;
        glVertex2f(x1 + (r - 7) * cos(theta), y1 + (r - 7) * sin(theta));
        glBegin(GL_LINES);

        glVertex2i(x1, y1);
        glVertex2i(x1 + (r - 7) * cos(theta), y1 + (r - 7) * sin(theta));
        glEnd();
    }

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
void Bicycle(void) {
    // Clear the screen buffer
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(4.0);

    // Left Wheel
    // glColor3f(1.0f, 1.0f, 1.0f);
    createcircle(280, 280, 50);

    // Right Wheel
    // glColor3f(1.0f, 1.0f, 1.0f);
    createcircle(455, 280, 50);

    glColor3f(1.0f, 1.0f, 1.0f);

    // Connecting pipes of cylce
    glBegin(GL_LINE_STRIP);

    glVertex2i(280, 280);
    glVertex2i(367, 280);
    glVertex2i(367, 360);
    glVertex2i(280, 280);

    glEnd();

    glBegin(GL_LINES);

    glVertex2i(455, 280);
    glVertex2i(455, 360);

    glVertex2i(367, 360);
    glVertex2i(455, 360);

    glVertex2i(367, 280);
    glVertex2i(455, 360);

    glEnd();

    // seat
    glBegin(GL_LINE_LOOP);

    glVertex2i(350, 360);
    glVertex2i(350, 377);
    glVertex2i(380, 377);
    glVertex2i(380, 360);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    rectangle(350, 380, 380, 350, 377, 377, 360, 360);

    // handle
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2i(380, 377);
    glVertex2i(380, 360);
    glEnd();
    glBegin(GL_LINES);

    glVertex2i(435, 377);
    glVertex2i(470, 343);
    glVertex2i(435, 377);
    glVertex2i(445, 387);
    glVertex2i(470, 343);
    glVertex2i(480, 353);

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1200, 1200);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("BIcycle");

    // Clear the screen color
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Specify the display area
    gluOrtho2D(100.0, 600.0, 150.0, 600.0);
    glutDisplayFunc(Bicycle);  // Creates the window and sets the title

    glutMainLoop();

    return 0;
}