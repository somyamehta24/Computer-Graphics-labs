// 190001058
// Somya Mehta
#include <bits/stdc++.h>
#include <GL/glut.h>

double rotate_x = 0, rotate_y = 0, zoom = 1, mgo = 0, mwo = 1;
int sofa_s = 0, sofa_d = 0;
using namespace std;
int width, height;

// To prints text
void Display_Stroke(GLfloat x, GLfloat y, GLfloat z, GLfloat s, GLfloat pointSize, GLfloat rotate, string text) {
    string buffer = text;
    glPushMatrix();
    glTranslatef(x, y, z);
    glPointSize(pointSize);
    glLineWidth(pointSize);
    glRotatef(rotate, 0.0, 1.0, 0.0);
    glScalef(s, s, s);
    for (auto ch : buffer)
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, ch);
    glPopMatrix();
}

void grass() {
    glColor3f(0.11, 0.51, 0.19);
    glBegin(GL_QUADS);
    glVertex3f(-2.2, -1.02, -2.2);
    glVertex3f(-2.2, -1.02, 2.2);
    glVertex3f(2.2, -1.02, 2.2);
    glVertex3f(2.2, -1.02, -2.2);
    glEnd();
}

void windows() {
    if (mwo == 1) {
        glColor3f(0.9, 0.8, 0.9);
        glBegin(GL_POLYGON);
        glVertex3f(-1.1f, -0.5f, 1.51f);
        glVertex3f(-1.1f, 0.0f, 1.51f);
        glVertex3f(-0.6f, 0.0f, 1.51f);
        glVertex3f(-0.6f, -0.5f, 1.51f);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex3f(1.1f, -0.5f, 1.51f);
        glVertex3f(1.1f, 0.0f, 1.51f);
        glVertex3f(0.6f, 0.0f, 1.51f);
        glVertex3f(0.6f, -0.5f, 1.51f);
        glEnd();
    } else {
        glColor3f(0.5, 0.55, 0.5);
        glBegin(GL_LINE_LOOP);
        glVertex3f(-1.1f, -0.5f, 1.51f);
        glVertex3f(-1.1f, 0.0f, 1.51f);
        glVertex3f(-0.6f, 0.0f, 1.51f);
        glVertex3f(-0.6f, -0.5f, 1.51f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex3f(1.1f, -0.5f, 1.51f);
        glVertex3f(1.1f, 0.0f, 1.51f);
        glVertex3f(0.6f, 0.0f, 1.51f);
        glVertex3f(0.6f, -0.5f, 1.51f);
        glEnd();
    }
}

void table() {
    glColor3f(0.80, 0.72, 0.62);
    glPushMatrix();
    glTranslated(0.375, -1.325 + 0.55, 0.0);
    glScaled(5.0, 0.75, 11.0);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.475, -1.425 + 0.525, -0.50);
    glScaled(0.5, 2.25, 0.5);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.475, -1.425 + 0.525, 0.50);
    glScaled(0.5, 2.25, 0.5);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.275, -1.425 + 0.525, 0.50);
    glScaled(0.5, 2.25, 0.5);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.275, -1.425 + 0.525, -0.50);
    glScaled(0.5, 2.25, 0.5);
    glutSolidCube(0.1);
    glPopMatrix();
}

void sofa1() {
    glColor3f(0.96, 0.60, 0.35);
    glPushMatrix();
    glTranslated(-0.4 + sofa_s, -1.425 + 0.55, 0 + sofa_d);  // bottom
    glScaled(4, 2.5, 12);
    glutSolidCube(0.1);
    glPopMatrix();

    glColor3f(0.93, 0.80, 0.70);
    glPushMatrix();
    glTranslated(-0.4 + sofa_s, -1.3125 + 0.55, -0.501 + sofa_d);  // back
    glScaled(4.01, 1.5, 2);
    glutSolidCube(0.1);
    glPopMatrix();

    glColor3f(0.93, 0.80, 0.70);
    glPushMatrix();
    glTranslated(-0.4 + sofa_s, -1.3125 + 0.55, 0.501 + sofa_d);  // front
    glScaled(4.01, 1.5, 2);
    glutSolidCube(0.1);
    glPopMatrix();

    glColor3f(0.87, 0.70, 0.50);
    glPushMatrix();
    glTranslated(-0.550 + sofa_s, -1.275 + 0.55, 0 + sofa_d);  // rest
    glScaled(1.0, 4.0, 10);
    glutSolidCube(0.1);
    glPopMatrix();
}
void back() {
    //*** BACK ***
    glColor3f(0.8f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.5, -1.0, -1.5);
    glVertex3f(-1.5, 1.0, -1.5);
    glVertex3f(1.5, 1.0, -1.5);
    glVertex3f(1.5, -1.0, -1.5);
    glEnd();
}
void front() {
    //*** FRONT ***
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.0, 0.3);
    glVertex3f(-1.5, 0.20, 1.5);
    glVertex3f(-1.5, 1.0, 1.5);
    glVertex3f(1.5, 1.0, 1.5);
    glVertex3f(1.5, 0.20, 1.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.0, 0.3);
    glVertex3f(-1.5, -1.0, 1.5);
    glVertex3f(-1.5, 0.20, 1.5);
    glVertex3f(-0.30, 0.20, 1.5);
    glVertex3f(-0.30, -1.0, 1.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.0, 0.3);
    glVertex3f(1.5, -1.0, 1.5);
    glVertex3f(1.5, 0.20, 1.5);
    glVertex3f(0.30, 0.20, 1.5);
    glVertex3f(0.30, -1.0, 1.5);
    glEnd();
}
void gate() {
    if (mgo == 0) {
        glBegin(GL_QUADS);
        glColor3f(0.65f, 0.41f, 0.16f);
        glVertex3f(0.30, -1.0, 1.501);
        glVertex3f(0.30, 0.20, 1.501);
        glVertex3f(0.003, 0.20, 1.501);
        glVertex3f(0.003, -1.0, 1.501);
        glEnd();

        glBegin(GL_QUADS);
        glVertex3f(-0.30, -1.0, 1.501);
        glVertex3f(-0.30, 0.20, 1.501);
        glVertex3f(-0.003, 0.20, 1.501);
        glVertex3f(-0.003, -1.0, 1.501);
        glEnd();
    }

    if (mgo == 1) {
        glBegin(GL_QUADS);
        glColor3f(0.65f, 0.41f, 0.16f);
        glVertex3f(0.30, -1.0, 1.501);
        glVertex3f(0.30, 0.20, 1.501);
        glVertex3f(0.60, 0.20, 1.801);
        glVertex3f(0.60, -1.0, 1.801);
        glEnd();

        glBegin(GL_QUADS);
        glVertex3f(-0.30, -1.0, 1.501);
        glVertex3f(-0.30, 0.20, 1.501);
        glVertex3f(-0.60, 0.20, 1.801);
        glVertex3f(-0.60, -1.0, 1.801);
        glEnd();
    }
}
void frontTri() {
    glColor3f(0.5f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.75f, 1.0f, 1.5f);
    glVertex3f(1.75f, 1.0f, 1.5f);
    glVertex3f(0.0f, 2.5f, 0.0f);
    glEnd();
}
void backTri() {
    glColor3f(0.65f, 0.41f, 0.16f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.75f, 1.0f, -1.5f);
    glVertex3f(1.75f, 1.0f, -1.5f);
    glVertex3f(0.0f, 2.5f, 0.0f);
    glEnd();
}
void rightTri() {
    glColor3f(0.5f, 0.2f, 0.3f);
    glBegin(GL_TRIANGLES);
    glVertex3f(1.75f, 1.0f, 1.5f);
    glVertex3f(1.75f, 1.0f, -1.5f);
    glVertex3f(0.0f, 2.5f, 0.0f);
    glEnd();
}
void leftTri() {
    glColor3f(0.5f, 0.2f, 0.1f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.75f, 1.0f, 1.5f);
    glVertex3f(-1.75f, 1.0f, -1.5f);
    glVertex3f(0.0f, 2.5f, 0.0f);
    glEnd();
}
void right() {
    //*** RIGHT ***
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.0f, 0.9f);
    glVertex3f(1.5, -1.0, -1.5);
    glVertex3f(1.5, 1.0, -1.5);
    glVertex3f(1.5, 1.0, 1.5);
    glVertex3f(1.5, -1.0, 1.5);
    glEnd();
}
void left() {
    //*** LEFT ***
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.0f, 0.7f);
    glVertex3f(-1.5, -1.0, -1.5);
    glVertex3f(-1.5, 1.0, -1.5);
    glVertex3f(-1.5, 1.0, 1.5);
    glVertex3f(-1.5, -1.0, 1.5);
    glEnd();
}
void top() {
    glBegin(GL_QUADS);
    glVertex3f(-1.75, 1.0, 1.5);
    glVertex3f(-1.75, 1.0, -1.5);
    glVertex3f(1.75, 1.0, -1.5);
    glVertex3f(1.75, 1.0, 1.5);
    glEnd();
}
void bottom() {
    glBegin(GL_QUADS);
    glVertex3f(-1.5, -1.0, 1.5);
    glVertex3f(-1.5, -1.0, -1.5);
    glVertex3f(1.5, -1.0, -1.5);
    glVertex3f(1.5, -1.0, 1.5);
    glEnd();
}
void furniture() {
    // Grass
    grass();

    // Sofa
    sofa1();

    // Table
    table();

    // Windows
    windows();
    // Direction of rotation
}
// Display house
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    // Translate the house
    glTranslatef(0.0f, 0.0f, -1.0f);

    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glScalef(zoom, zoom, zoom);

    // Printing text
    Display_Stroke(-0.62, 0.65, 1.51, 0.0010, 4, 0, "SOMYA");
    Display_Stroke(0.18, 0.65, 1.51, 0.0010, 4, 0, "MEHTA");

    // Eabling Texture Environment
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    front();
    gate();
    back();
    right();
    left();

    top();
    bottom();

    //*** ROOF ***

    rightTri();
    backTri();
    frontTri();
    furniture();

    glFlush();
    glutSwapBuffers();
}

int axis_x = 0, axis_y = 0;

// Takes action on pressing keyboard key
void encodedKeys(unsigned char key, int x, int y) {
    // Reset
    if (key == 'r' or key == 'R') {
        rotate_x = 0;
        rotate_y = 0;
    }

    // Zoom in/out
    if (key == 'a' or key == 'A') {
        zoom *= 1.021897148;
    }
    if (key == 's' or key == 'S') {
        zoom /= 1.021897148;
    }

    // To open and close main gate
    if (key == 'g' or key == 'G') {
        if (mgo == 0)
            mgo = 1;
        else
            mgo = 0;
    }

    // To open and close windows
    if (key == 'w' or key == 'W') {
        if (mwo == 0)
            mwo = 1;
        else
            mwo = 0;
    }

    glutPostRedisplay();
}

void keyboardRotate(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) {
        rotate_y += 5;
        axis_y = 0;
    }
    if (key == GLUT_KEY_RIGHT) {
        rotate_y -= 5;
        axis_y = 1;
    }
    if (key == GLUT_KEY_DOWN) {
        rotate_x -= 5;
        axis_x = 1;
    }
    if (key == GLUT_KEY_UP) {
        rotate_x += 5;
        axis_x = 0;
    }
    glutPostRedisplay();
}

int last_x = 0, last_y = 0;

void mouseRotate(int x, int y) {
    if (x > 700 or y > 700 or x < 0 or y < 0)
        return;
    if (abs(x - last_x) > 25 or abs(y - last_y) > 25) {
        last_x = x;
        last_y = y;
        return;
    }
    rotate_x += (last_y - y + 0.0) * 0.5;
    rotate_y += (last_x - x + 0.0) * 0.5;
    if ((last_y - y) > 0)
        axis_x = 0;
    if ((last_y - y) < 0)
        axis_x = 1;
    if ((last_x - x) > 0)
        axis_y = 0;
    if ((last_x - x) < 0)
        axis_y = 1;
    last_x = x;
    last_y = y;

    glutPostRedisplay();
}

// To show Zoom-in/out
void mouseZoom(int btn, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        if (btn == 3) {
            zoom *= 1.021897148;
        }
        if (btn == 4) {
            zoom /= 1.021897148;
        }
    }
    glutPostRedisplay();
}

void setup_Camera(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);

    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv) {
    cout << "r/R-> For Reset\n\n";

    cout << "a/s for Zoom-in/out\n\n";
    cout << "g/G for open/close gate\n\n";
    cout << "w/W for open/close Window\n\n";
    glutInit(&argc, argv);
    glutInitWindowPosition(700, 0);  // set window position
    glutInitWindowSize(700, 700);    // set window size
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("3D - HOUSE - 190001058");  // set window title

    glClearColor(0.0, 0.1, 0.12, 1.0);
    glEnable(GL_DEPTH_TEST);

    // Camera view
    setup_Camera(width, height);
    glutDisplayFunc(display);
    glutReshapeFunc(setup_Camera);

    glutKeyboardFunc(encodedKeys);
    glutSpecialFunc(keyboardRotate);

    glutMouseFunc(mouseZoom);
    glutMotionFunc(mouseRotate);

    glutMainLoop();
    return 0;
}