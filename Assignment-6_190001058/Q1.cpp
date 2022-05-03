// 190001058
// Somya Mehta
#include <bits/stdc++.h>
#include <GL/glut.h>

#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rf(i, a, b) for (ll i = a; i >= b; i--)
typedef std::vector<long long> vi;
#define F first
#define S second
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mod 1000000007
#define PB push_back
#define MP make_pair
#define PI 3.14159265358979323846
#define all(a) a.begin(), a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
const ll INF = LLONG_MAX / 2;
const ll N = 2e5 + 1;

using namespace std;

// this is Called when a key is pressed
double rotat_Y = 0;
double ydif = 0.0f;
double rotat_X = 0;  // how much x, y have been rotated using mouse

bool lMBclicked = false;  // We are checking  if LMB is clicked
float white_light = 0.8;  // diffused light intensity
int xtex = 0, ytex = 0;

// This code is called when the window is resized
void handleResize(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 800.0);
}
float amb_white_light = 0.2;  // ambient light intensity
double xdif = 0.0f;           // temp variables

// float _angle = -70.0f;
void ground() {
    // this is code for ground
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-4.0f, -1.5001f, 2.0f);
    glVertex3f(0.0f, -1.5001f, 2.0f);
    glVertex3f(0.0f, -1.5001f, -2.0f);
    glVertex3f(-4.0f, -1.5001f, -2.0f);
}
void frontWall() {
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-2.0f, -1.5f, -1.0f);
    glVertex3f(-2.0f, 0.0f, -1.0f);
    glVertex3f(-2.0f, 0.0f, 1.0f);
    glVertex3f(-2.0f, -1.5f, 1.0f);
}
void rightWall() {
    // this code is for Right Wall
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-3.5f, -1.5f, -1.0f);
    glVertex3f(-2.0f, -1.5f, -1.0f);
    glVertex3f(-2.0f, 0.0f, -1.0f);
    glVertex3f(-3.5f, 0.0f, -1.0f);
}
void frontWindow() {
    // this is the code for Window
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.999f, -1.0f, 0.3f);
    glVertex3f(-1.999f, -0.5f, 0.3f);
    glVertex3f(-1.999f, -0.5f, 0.7f);
    glVertex3f(-1.999f, -1.0f, 0.7f);
}
void rightWindow() {
    // this is the code for Right Window
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-3.0f, -1.0f, -1.0001f);
    glVertex3f(-2.5f, -1.0f, -1.0001f);
    glVertex3f(-2.5f, -0.5f, -1.0001f);
    glVertex3f(-3.0f, -0.5f, -1.0001f);
}
void leftWindow() {
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-3.0f, -1.0f, 1.0001f);
    glVertex3f(-2.5f, -1.0f, 1.0001f);
    glVertex3f(-2.5f, -0.5f, 1.0001f);
    glVertex3f(-3.0f, -0.5f, 1.0001f);
}
void roof() {
    // roof
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-3.5f, 0.0f, 1.1f);
    glVertex3f(-2.0f, 0.0f, 1.1f);
    glVertex3f(-2.75f, 1.0f, 0.0f);
    glVertex3f(-2.75f, 1.0f, 0.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-3.5f, 0.0f, -1.1f);
    glVertex3f(-2.0f, 0.0f, -1.1f);
    glVertex3f(-2.75f, 1.0f, 0.0f);
    glVertex3f(-2.75f, 1.0f, 0.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-3.5f, 0.0f, 1.1f);
    glVertex3f(-3.5f, 0.0f, -1.1f);
    glVertex3f(-2.75f, 1.0f, 0.0f);
    glVertex3f(-2.75f, 1.0f, 0.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-2.0f, 0.0f, -1.1f);
    glVertex3f(-2.0f, 0.0f, 1.1f);
    glVertex3f(-2.75f, 1.0f, 0.0f);
    glVertex3f(-2.75f, 1.0f, 0.0f);
}
void base() {
    glColor3f(0.8f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-3.6f, -1.5f, 1.1f);
    glVertex3f(-1.9f, -1.5f, 1.1f);
    glVertex3f(-1.9f, -1.5f, -1.1f);
    glVertex3f(-3.6f, -1.5f, -1.1f);
}
void backWall() {
    // this is code for Back part

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-3.5f, -1.5f, -1.0f);
    glVertex3f(-3.5f, -1.5f, 1.0f);
    glVertex3f(-3.5f, 0.0f, 1.0f);
    glVertex3f(-3.5f, 0.0f, -1.0f);
}
void door() {
    // this is code for door part

    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.999f, -1.5f, -0.5f);
    glVertex3f(-1.999f, -0.3f, -0.5f);
    glVertex3f(-1.999f, -0.3f, 0.0f);
    glVertex3f(-1.999f, -1.5f, 0.0f);
}
void leftWall() {
    // this is code for left wall part
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-3.5f, -1.5f, 1.0f);
    glVertex3f(-2.0f, -1.5f, 1.0f);
    glVertex3f(-2.0f, 0.0f, 1.0f);
    glVertex3f(-3.5f, 0.0f, 1.0f);
}
void draw_Function_Hut() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -8.0f);

    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};  // Color (0.2, 0.2, 0.2) and intensity //can be greater than 1 so not like color
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    // Add positioned light
    // GLfloat lightColor0[] = {4.5f, 0.5f, 0.5f, 1.0f};  // Color (0.5, 0.5, 0.5)
    // GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f};    // Positioned at (4, 0, 8)
    // glLightfv(GL_LIGHT0, GL_AMBIENT, lightColor0);
    // glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    // Add directed light
    // GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f};  // Color (0.5, 0.2, 0.2)
    // It is Coming from the direction (-1, 0.5, 0.5)
    // 0 because direced light source
    // GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
    // glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    // glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

    glRotatef(rotat_X, 1.0, 0.0, 0.0);  // rotate abt x-axis
    glRotatef(rotat_Y, 0.0, 1.0, 0.0);  // rotate abt y-axis

    ground();
    frontWall();

    // this is the code for  front wall

    door();

    frontWindow();
    leftWindow();
    rightWall();
    leftWall();
    rightWindow();

    // Base of house
    base();
    backWall();
    // bottom

    roof();

    glEnd();

    glutSwapBuffers();
}

// act on mouse movement
void mouse_movement(int current_X, int currY) {
    if (lMBclicked) {
        rotat_X = currY - ydif;
        rotat_Y = current_X - xdif;
        glutPostRedisplay();
    }
}

// detect mouse actions
void detectFunc(int butt, int current_state, int current_X, int currY) {
    if (butt == GLUT_LEFT_BUTTON && current_state == GLUT_DOWN) {
        lMBclicked = true;  // set LMB true
        xdif = current_X - rotat_Y;
        ydif = currY - rotat_X;
    } else
        lMBclicked = false;

    // Wheel reports as butt 3(scroll up)
    if (butt == 3) {
        xtex += 0.5;
        ytex += 0.5;
        if (current_state == GLUT_UP) return;  // Disregard redundant GLUT_UP events
        white_light = white_light * 1.1;       // increase diffused light intensity
        if (white_light > 1)                   // intensity <= 1
            white_light = 1;
        glutPostRedisplay();
    }
    // Wheel reports as butt 4(scroll down)
    if (butt == 4) {
        xtex -= 0.5;
        ytex -= 0.5;
        if (current_state == GLUT_DOWN) return;  // Disregard redundant GLUT_DOWN events
        white_light = white_light * 0.9;         // decrease diffused light intensity
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    // Create the window
    // GLUT_DOUBLE for smooth animations
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 700);

    // Initializes 3D rendering

    glutCreateWindow("3D House");
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    // glEnable(GL_LIGHTING);  //Enable lighting
    // you can have upto 8 lighting
    // glEnable(GL_LIGHT0);  //Enable light #0
    // glEnable(GL_LIGHT1);  //Enable light #1
    // glEnable(GL_LIGHT2);     //Enable light #2
    // glEnable(GL_LIGHT3);     //Enable light #3
    // glEnable(GL_LIGHT4);     //Enable light #4
    // glEnable(GL_LIGHT5);     //Enable light #5
    // glEnable(GL_LIGHT6);     //Enable light #6
    // glEnable(GL_LIGHT7);     //Enable light #7
    glEnable(GL_NORMALIZE);  // Automatically normalize normals
                             // glShadeModel(GL_SMOOTH); //Enable smooth shading

    // Set handler functions
    glutDisplayFunc(draw_Function_Hut);
    glutReshapeFunc(handleResize);

    glutMouseFunc(detectFunc);
    glutMotionFunc(mouse_movement);
    glutMainLoop();
    return 0;
}