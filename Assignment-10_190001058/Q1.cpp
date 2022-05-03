// Somya Mehta
// 190001058

#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rf(i, a, b) for (ll i = a; i >= b; i--)
#include <GL/glut.h>
#include <unistd.h>

using namespace std;

float intensity = 1;
GLfloat lightposition[] = {2.0, 2.0, 2.0, 1.0};
GLfloat lightposition2[] = {0.0, 1.0, -2.0, 1.0};

typedef GLfloat point[3];
point f[] = {{0.0, 0.25, 0.0}, {0.0, 1.0, 0.0}, {0.025, 0.25, -0.025}, {-0.025, 0.25, -0.025}, {-0.025, 0.25, 0.025}, {0.025, 0.25, 0.025}};
point fb[] = {{0.025, 0.25, -0.025}, {0.025, 0.25, 0.025}, {0.2, 0.25, 0.05}, {0.2, 0.25, -0.05}, {-0.025, 0.25, -0.025}, {-0.025, 0.25, 0.025}, {-0.2, 0.25, 0.05}, {-0.2, 0.25, -0.05}, {0.025, 0.25, -0.025}, {-0.025, 0.25, -0.025}, {-0.05, 0.25, -0.2}, {0.05, 0.25, -0.2}, {-0.025, 0.25, 0.025}, {0.025, 0.25, 0.025}, {0.05, 0.25, 0.2}, {-0.05, 0.25, 0.2}};
point t[] = {{1.1, -0.3, -0.5}, {1.1, 0.3, -0.5}, {1.1, 0.3, 0.5}, {1.1, -0.3, 0.5}};
point ts[] = {{1.1, 0.05, -0.05}, {1.1, 0.0, -0.05}, {1.1, 0.0, 0.05}, {1.1, 0.05, 0.05}, {1.49, 0.0, -0.05}, {1.49, -0.05, -0.05}, {1.49, -0.05, 0.05}, {1.49, 0.0, 0.05}};
;

double rotate_x = 0, rotate_y = 0, zoom = 1, mwo = 1;
float fanspeed = 2.0, angle = 0.0;
int fanflag = 0, lightflag = 0;
int sofa_s = 0, sofa_d = 0;
double doorAngle = 0;
int flag_time = 0;

int width, height;

int texImageWidth;
int texImageHeight;

void Tree(float x, float y, float z) {
    glPushMatrix();
    GLUquadricObj *qobj = gluNewQuadric();
    glTranslated(x, y, z);
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glColor3f(0, 0.8, 0);
    // leaves
    gluCylinder(qobj, 0.1, 0.5, 1, 16, 16);
    gluCylinder(qobj, 0, 0.8, 2.5, 16, 16);
    glColor3f(0.5, 0.3, 0);
    gluCylinder(qobj, 0.05, 0.05, 4, 16, 16);
    gluDeleteQuadric(qobj);
    glPopMatrix();
}

void spin() {
    angle = angle + fanspeed;
    if (angle >= 360) {
        angle = 0;
    }
    usleep(10000);
    flag_time += 1;
    glutPostRedisplay();
}

void grass() {
    glColor3f(0.13, 0.55, 0.13);
    glBegin(GL_QUADS);
    glVertex3f(-2.2, -1.02, -2.2);
    glVertex3f(-2.2, -1.02, 2.2);
    glVertex3f(2.2, -1.02, 2.2);
    glVertex3f(2.2, -1.02, -2.2);
    glEnd();
}

void windows() {
    if (mwo == 1) {
        glColor3f(0.5, 0.55, 0.5);
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

void tv(point a, point b, point c, point d) {
    glColor3f(0.19, 0.31, 0.31);
    glBegin(GL_POLYGON);
    glVertex3fv(a);
    glVertex3fv(b);
    glVertex3fv(c);
    glVertex3fv(d);
    glEnd();
}

void tvs(point a, point b, point c, point d, point a1, point b1, point c1, point d1) {
    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_LINES);
    glVertex3fv(a);
    glVertex3fv(a1);
    glEnd();
    glBegin(GL_LINES);
    glVertex3fv(b);
    glVertex3fv(b1);
    glEnd();
    glBegin(GL_LINES);
    glVertex3fv(c);
    glVertex3fv(c1);
    glEnd();
    glBegin(GL_LINES);
    glVertex3fv(d);
    glVertex3fv(d1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3fv(a);
    glVertex3fv(a1);
    glVertex3fv(b1);
    glVertex3fv(b);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3fv(a);
    glVertex3fv(a1);
    glVertex3fv(d1);
    glVertex3fv(d);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3fv(b);
    glVertex3fv(b1);
    glVertex3fv(c1);
    glVertex3fv(c);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3fv(c);
    glVertex3fv(c1);
    glVertex3fv(d1);
    glVertex3fv(d);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3fv(a1);
    glVertex3fv(b1);
    glVertex3fv(c1);
    glVertex3fv(d1);
    glEnd();
}

void fan(point a, point b, point c, point d, point e, point f) {
    glColor3f(0.72, 0.53, 0.04);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex3fv(a);
    glVertex3fv(b);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3fv(c);
    glVertex3fv(d);
    glVertex3fv(e);
    glVertex3fv(f);
    glEnd();
}

void fblade(point a, point b, point c, point d, point a1, point b1, point c1, point d1, point a2, point b2, point c2, point d2, point a3, point b3, point c3, point d3) {
    glColor3f(0.72, 0.53, 0.04);
    if (fanflag == 1)
        glRotatef(angle, 0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3fv(a);
    glVertex3fv(b);
    glVertex3fv(c);
    glVertex3fv(d);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3fv(a1);
    glVertex3fv(b1);
    glVertex3fv(c1);
    glVertex3fv(d1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3fv(a2);
    glVertex3fv(b2);
    glVertex3fv(c2);
    glVertex3fv(d2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3fv(a3);
    glVertex3fv(b3);
    glVertex3fv(c3);
    glVertex3fv(d3);
    glEnd();
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

void banner() {
    GLUquadricObj *qobj = gluNewQuadric();

    glPushMatrix();
    glTranslatef(2.5, -1, 0);
    glColor3f(0.45, 0.25, 0.13);
    glRotatef(270, 1.0, 0, 0);
    gluCylinder(qobj, 0.1, 0.1, 3.0, 10, 16);
    glPushMatrix();
    glRotatef(-270, 1.0, 0, 0);

    float num_elements = 100;
    float dx = 1 / num_elements;
    for (int i = 0; i < num_elements; i++) {
        float phase1 = i * dx;
        int j = i + 1;
        float phase2 = j * dx;

        glColor3f(0.7, 0.7, 0.3);
        glBegin(GL_POLYGON);

        glTexCoord2f(0, 0);
        glVertex3f(dx * i, 2, (sinf((2 * 3.14159 / 500 * flag_time) + phase1)) * i / num_elements);
        glTexCoord2f(0, 1);
        glVertex3f(dx * i, 3, (sinf((2 * 3.14159 / 500 * flag_time) + phase1)) * i / num_elements);
        glTexCoord2f(1, 1);
        glVertex3f(dx * j, 3, (sinf((2 * 3.14159 / 500 * flag_time) + phase2)) * j / num_elements);
        glTexCoord2f(1, 0);
        glVertex3f(dx * j, 2, (sinf((2 * 3.14159 / 500 * flag_time) + phase2)) * j / num_elements);

        glEnd();
    }
    glPopMatrix();
    glPopMatrix();
}

void sofa1() {
    glColor3f(0.96, 0.64, 0.38);
    glPushMatrix();
    glTranslated(-0.4 + sofa_s, -1.425 + 0.55, 0 + sofa_d);  // bottom
    glScaled(4, 2.5, 12);
    glutSolidCube(0.1);
    glPopMatrix();

    glColor3f(0.93, 0.84, 0.72);
    glPushMatrix();
    glTranslated(-0.4 + sofa_s, -1.3125 + 0.55, -0.501 + sofa_d);
    glScaled(4.01, 1.5, 2);
    glutSolidCube(0.1);
    glPopMatrix();

    glColor3f(0.93, 0.84, 0.72);
    glPushMatrix();
    glTranslated(-0.4 + sofa_s, -1.3125 + 0.55, 0.501 + sofa_d);
    glScaled(4.01, 1.5, 2);
    glutSolidCube(0.1);
    glPopMatrix();

    glColor3f(0.87, 0.72, 0.53);
    glPushMatrix();
    glTranslated(-0.550 + sofa_s, -1.275 + 0.55, 0 + sofa_d);  // rest
    glScaled(1.0, 4.0, 10);
    glutSolidCube(0.1);
    glPopMatrix();
}

void front() {
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-1.5, 0.20, 1.5);
    glVertex3f(-1.5, 1.0, 1.5);
    glVertex3f(1.5, 1.0, 1.5);
    glVertex3f(1.5, 0.20, 1.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-1.5, -1.0, 1.5);
    glVertex3f(-1.5, 0.20, 1.5);
    glVertex3f(-0.30, 0.20, 1.5);
    glVertex3f(-0.30, -1.0, 1.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1.5, -1.0, 1.5);
    glVertex3f(1.5, 0.20, 1.5);
    glVertex3f(0.30, 0.20, 1.5);
    glVertex3f(0.30, -1.0, 1.5);
    glEnd();
}
void back() {
    glColor3f(0.8f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.5, -1.0, -1.5);
    glVertex3f(-1.5, 1.0, -1.5);
    glVertex3f(1.5, 1.0, -1.5);
    glVertex3f(1.5, -1.0, -1.5);
    glEnd();
}
void gate() {
    glPushMatrix();
    glTranslatef(0.3, 0, 1.5);
    glRotatef(doorAngle, 0, 1, 0);
    glTranslatef(-0.3, 0, -1.5);
    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.41f, 0.16f);
    glVertex3f(0.30, -1.0, 1.501);
    glVertex3f(0.30, 0.20, 1.501);
    glVertex3f(0.003, 0.20, 1.501);
    glVertex3f(0.003, -1.0, 1.501);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3, 0, 1.5);
    glRotatef(-doorAngle, 0, 1, 0);
    glTranslatef(0.3, 0, -1.5);
    glBegin(GL_QUADS);
    glVertex3f(-0.30, -1.0, 1.501);
    glVertex3f(-0.30, 0.20, 1.501);
    glVertex3f(-0.003, 0.20, 1.501);
    glVertex3f(-0.003, -1.0, 1.501);
    glEnd();
    glPopMatrix();
}
void right() {
    glBegin(GL_QUADS);
    glColor3f(0.8f, 1.0f, 0.9f);
    glVertex3f(1.5, -1.0, -1.5);
    glVertex3f(1.5, 1.0, -1.5);
    glVertex3f(1.5, 1.0, 1.5);
    glVertex3f(1.5, -1.0, 1.5);
    glEnd();
}
void left() {
    glBegin(GL_QUADS);
    glColor3f(0.8f, 1.0f, 0.7f);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1.5, -1.0, -1.5);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-1.5, 1.0, -1.5);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-1.5, 1.0, 1.5);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1.5, -1.0, 1.5);
    glEnd();
}
void bottom() {
    glBegin(GL_QUADS);
    double x = 10;
    glColor3f(0.1f, 1.0f, 0.2f);
    glVertex3f(-x, -1.0, x);
    glVertex3f(-x, -1.0, -x);
    glVertex3f(x, -1.0, -x);
    glVertex3f(x, -1.0, x);
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
void roof() {
    // left tri
    glColor3f(0.5f, 0.2f, 0.1f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.75f, 1.0f, 1.5f);
    glVertex3f(-1.75f, 1.0f, -1.5f);
    glVertex3f(0.0f, 2.5f, 0.0f);
    glEnd();

    // right tri
    glColor3f(0.5f, 0.2f, 0.3f);
    glBegin(GL_TRIANGLES);
    glVertex3f(1.75f, 1.0f, 1.5f);
    glVertex3f(1.75f, 1.0f, -1.5f);
    glVertex3f(0.0f, 2.5f, 0.0f);
    glEnd();

    // back tri
    glColor3f(0.65f, 0.41f, 0.16f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.75f, 1.0f, -1.5f);
    glVertex3f(1.75f, 1.0f, -1.5f);
    glVertex3f(0.0f, 2.5f, 0.0f);
    glEnd();

    // front tri
    glColor3f(0.5f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.75f, 1.0f, 1.5f);
    glVertex3f(1.75f, 1.0f, 1.5f);
    glVertex3f(0.0f, 2.5f, 0.0f);
    glEnd();
}
void tree() {
    for (int i = -3; i < 2; i++) {
        glPushMatrix();
        Tree(-3.5, 3, i);
        glPopMatrix();
    }

    for (int i = -3; i < 2; i++) {
        glPushMatrix();
        Tree(-5, 3, i);
        glPopMatrix();
    }
}
void road() {
    glPushMatrix();
    glTranslatef(0, 0.1, 5);
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    int x = 10;
    double y = 2;
    glVertex3f(-x, -1, y);
    glVertex3f(-x, -1, -y);
    glVertex3f(x, -1, -y);
    glVertex3f(x, -1, y);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    x = 10;
    y = 0.1;
    glVertex3f(-x, -0.9, y);
    glVertex3f(-x, -0.9, -y);
    glVertex3f(x, -0.9, -y);
    glVertex3f(x, -0.9, y);
    glEnd();
    glPopMatrix();
}
void sun() {
    glPushMatrix();
    glColor3f(0.8, 0.7, 0);
    float sca = 2;
    glTranslatef(lightposition[0] * sca, lightposition[1] * sca, lightposition[2] * sca);
    glutSolidSphere(0.3, 12, 12);
    glPopMatrix();
}
void pool() {
    glPushMatrix();
    glTranslatef(4.5, 0.1, 0);
    glColor3f(0, 0.5, 0.8);
    glBegin(GL_QUADS);
    int x = 1.5;
    glVertex3f(-x, -1, x);
    glVertex3f(-x, -1, -x);
    glVertex3f(x, -1, -x);
    glVertex3f(x, -1, x);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(4.5, -0.9, 1.5);
    glScalef(2 * x, 0.2, 0.1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(4.5, -0.9, -1.5);
    glScalef(2 * x, 0.2, 0.1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(3, -0.9, 0);
    glScalef(0.1, 0.2, 2 * x);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(6, -0.9, 0);
    glScalef(0.1, 0.2, 2 * x);
    glutSolidCube(1);
    glPopMatrix();
}
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(3 * 1.0 / 255 * intensity, 211 * 1.0 / 255 * intensity, 252 * 1.0 / 255 * intensity, 1);
    GLfloat mat_ambient[] = {0.7, 0.7, 0.7, 1.0};
    GLfloat mat_diffuse[] = {0.5, 0.5, 0.5, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {50.0};
    GLfloat lightintensity[] = {1 * intensity, 1 * intensity, 1 * intensity, intensity};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glLightfv(GL_LIGHT0, GL_POSITION, lightposition);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightintensity);
    glLightfv(GL_LIGHT0, GL_SPECULAR, mat_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, lightposition2);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightintensity);
    glLightfv(GL_LIGHT1, GL_SPECULAR, mat_specular);

    if (lightflag)
        glEnable(GL_LIGHTING);
    else
        glDisable(GL_LIGHTING);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -1.0f);

    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glScalef(zoom, zoom, zoom);

    front();

    gate();

    back();
    left();
    right();

    top();

    bottom();

    roof();

    tree();
    road();

    sun();

    pool();

    tv(t[0], t[1], t[2], t[3]);
    tvs(ts[0], ts[1], ts[2], ts[3], ts[4], ts[5], ts[6], ts[7]);

    sofa1();

    table();

    windows();
    grass();
    fan(f[0], f[1], f[2], f[3], f[4], f[5]);
    fblade(fb[0], fb[1], fb[2], fb[3], fb[4], fb[5], fb[6], fb[7], fb[8], fb[9], fb[10], fb[11], fb[12], fb[13], fb[14], fb[15]);

    banner();

    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

int axis_x = 0, axis_y = 0;

void SpecialKeys(unsigned char key, int x, int y) {
    if (key == 'I') {
        intensity += 0.1;
    }
    if (key == 'i') {
        intensity -= 0.1;
    }
    if (key == 'r' or key == 'R') {
        rotate_x = 0;
        rotate_y = 0;
    }
    if (key == 'a' or key == 'A') {
        zoom *= 1.021897148;
    }
    if (key == 's' or key == 'S') {
        zoom /= 1.021897148;
    }
    if (key == 'g') {
        doorAngle += 10;
        if (doorAngle >= 120)
            doorAngle = 120;
    }

    if (key == 'G') {
        doorAngle -= 10;
        if (doorAngle <= 0)
            doorAngle = 0;
    }
    if (key == 'w' or key == 'W') {
        if (mwo == 0)
            mwo = 1;
        else
            mwo = 0;
    }
    if (key == 'f' or key == 'F') {
        if (fanflag == 0)
            fanflag = 1;
        else
            fanflag = 0;
    }
    if (key == 'n' or key == 'N') {
        fanspeed += 4.0f;
    }
    if (key == 'm' or key == 'M') {
        fanspeed -= 4.0f;
    }
    if (key == 'l' or key == 'L') {
        if (lightflag == 0)
            lightflag = 1;
        else
            lightflag = 0;
    }
    if (key == 'x') {
        lightposition[0] += 0.1;
        lightposition2[0] += 0.1;
    }
    if (key == 'X') {
        lightposition[0] -= 0.1;
        lightposition2[0] -= 0.1;
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
    if (x > 500 or y > 500 or x < 0 or y < 0)
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

void idleSpinFunc() {
    if (axis_x == 0)
        rotate_x += 0.2;
    if (axis_x == 1)
        rotate_x -= 0.2;
    if (axis_y == 0)
        rotate_y += 0.2;
    if (axis_y == 1)
        rotate_y -= 0.2;

    usleep(10000);
    flag_time += 1;
    // Draw();
    glutPostRedisplay();
}

void setupCamera(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);

    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void choose_Menu(int value) {
    if (value == 999)
        exit(0);
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(700, 0);
    glutInitWindowSize(700, 700);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("3D - HOUSE | 190001058");

    glClearColor(0.0, 0.1, 0.12, 1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glDepthFunc(GL_LEQUAL);

    setupCamera(width, height);
    glutDisplayFunc(display);
    glutReshapeFunc(setupCamera);

    glutKeyboardFunc(SpecialKeys);
    glutSpecialFunc(keyboardRotate);

    glutMouseFunc(mouseZoom);
    glutMotionFunc(mouseRotate);
    glutIdleFunc(spin);

    glutMainLoop();
    return 0;
}