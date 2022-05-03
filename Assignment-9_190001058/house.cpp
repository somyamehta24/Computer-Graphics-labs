/*
Somya Mehta
190001058
*/
#include <bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

#define PI 3.14
float window_red = 160 / 255.0, window_green = 82 / 255.0, window_blue = 45 / 255.0;
float roof_red = 139 / 255.0, roof_green = 69 / 255.0, roof_blue = 19 / 255.0;
float house_red = 245.0 / 255, house_green = 175.0 / 255, house_blue = 103.0 / 255;
float door_red = 255 / 255, door_green = 255 / 255, door_blue = 0 / 255;

int start_x = -1;
int start_y = -1;

float reduce_intensity = 0.0;

float Theta = PI / 2;
float sii = 0;
float Radius = 25;
float front_back = 0;
float left_right = 0;
int flip = 0;
int window1 = 0;
int window2 = 0;

bool mouse_pressed = false;

float unit_change = (2 * PI * Radius) / 1000;

float reference_point = 0.0;

int intensity = 0;

float width_of_house = 6.0;
float height_of_house = 4.0;
float length_of_house = -4.0;
float width_of_roof = width_of_house + 1.5;
float height_of_roof = 8.0;
float extra_depth = 0.01;
float width_of_door = 0.8;
float height_of_door = 4.0;
float size_of_window = 0.8;
float camera[3] = {0, 0, 25};

void fill_color(float x, float y, float z) {
    glColor3f(x / 255, y / 255, z / 255);
}

void change_size_of_window(int width, int height) {
    if (height == 0)
        height = 1;
    float ratio = (width * 1.0) / height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
    gluPerspective(60.0, ratio, 0.1, 1000.0);
    glMatrixMode(GL_MODELVIEW);
}

void wall_with_window(int x) {
    glBegin(GL_POLYGON);
    glVertex3f(x, height_of_house, width_of_house);
    glVertex3f(x, size_of_window, width_of_house);
    glVertex3f(x, size_of_window, -width_of_house);
    glVertex3f(x, height_of_house, -width_of_house);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(x, -height_of_house, width_of_house);
    glVertex3f(x, -size_of_window, width_of_house);
    glVertex3f(x, -size_of_window, -width_of_house);
    glVertex3f(x, -height_of_house, -width_of_house);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(x, size_of_window, width_of_house);
    glVertex3f(x, size_of_window, size_of_window);
    glVertex3f(x, -size_of_window, size_of_window);
    glVertex3f(x, -size_of_window, width_of_house);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(x, size_of_window, -width_of_house);
    glVertex3f(x, size_of_window, -size_of_window);
    glVertex3f(x, -size_of_window, -size_of_window);
    glVertex3f(x, -size_of_window, -width_of_house);
    glEnd();
}

void wall_with_door(int z) {
    glBegin(GL_POLYGON);
    glVertex3f(width_of_house, height_of_house, z);
    glVertex3f(width_of_house, -height_of_house + height_of_door, z);
    glVertex3f(-width_of_house, -height_of_house + height_of_door, z);
    glVertex3f(-width_of_house, height_of_house, z);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(width_of_house, -height_of_house + height_of_door, z);
    glVertex3f(width_of_house, -height_of_house, z);
    glVertex3f(width_of_door, -height_of_house, z);
    glVertex3f(width_of_door, -height_of_house + height_of_door, z);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-width_of_house, -height_of_house + height_of_door, z);
    glVertex3f(-width_of_house, -height_of_house, z);
    glVertex3f(-width_of_door, -height_of_house, z);
    glVertex3f(-width_of_door, -height_of_house + height_of_door, z);
    glEnd();
}

void draw_cuboid(float x, float y, float z, float X, float Y, float Z) {
    glBegin(GL_POLYGON);
    glVertex3f(-x + X, Y + y, z + Z);
    glVertex3f(x + X, Y + y, z + Z);
    glVertex3f(x + X, Y - y, z + Z);
    glVertex3f(-x + X, Y - y, z + Z);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-x + X, Y + y, -z + Z);
    glVertex3f(x + X, Y + y, -z + Z);
    glVertex3f(x + X, Y - y, -z + Z);
    glVertex3f(-x + X, Y - y, -z + Z);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-x + X, Y + y, z + Z);
    glVertex3f(-x + X, Y + y, -z + Z);
    glVertex3f(-x + X, Y - y, -z + Z);
    glVertex3f(-x + X, Y - y, z + Z);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(x + X, Y + y, z + Z);
    glVertex3f(x + X, Y + y, -z + Z);
    glVertex3f(x + X, Y - y, -z + Z);
    glVertex3f(x + X, Y - y, z + Z);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-x + X, Y + y, z + Z);
    glVertex3f(-x + X, Y + y, -z + Z);
    glVertex3f(x + X, Y + y, -z + Z);
    glVertex3f(x + X, Y + y, z + Z);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-x + X, Y - y, z + Z);
    glVertex3f(-x + X, Y - y, -z + Z);
    glVertex3f(x + X, Y - y, -z + Z);
    glVertex3f(x + X, Y - y, z + Z);
    glEnd();
}

void table(float x, float y, float z) {
    draw_cuboid(1.8, 0.15, 1.8, x, y + 1.5, z);
    draw_cuboid(0.25, 1.5, 0.25, x - 1.5, y, z - 1.5);
    draw_cuboid(0.25, 1.5, 0.25, x + 1.5, y, z - 1.5);
    draw_cuboid(0.25, 1.5, 0.25, x - 1.5, y, z + 1.5);
    draw_cuboid(0.25, 1.5, 0.25, x + 1.5, y, z + 1.5);
}

void bed(float x, float y, float z) {
    draw_cuboid(1.5, 0.7, 0.15, x, y + 1, z + 3);
    draw_cuboid(1.5, 0.1, 3.2, x, y + 0.6, z);
    draw_cuboid(0.15, 0.6, 0.15, x - 1.4, y, z - 3.0);
    draw_cuboid(0.15, 0.6, 0.15, x + 1.4, y, z - 3.0);
    draw_cuboid(0.15, 0.6, 0.15, x - 1.4, y, z + 3.0);
    draw_cuboid(0.15, 0.6, 0.15, x + 1.4, y, z + 3.0);
}

void door() {
    if (flip) {
        float x = -width_of_door;
        float z = width_of_house;
        glBegin(GL_POLYGON);
        glVertex3f(x, -height_of_house + height_of_door, z);
        glVertex3f(x, -height_of_house + height_of_door, z + 2 * width_of_door);
        glVertex3f(x, -height_of_house, z + 2 * width_of_door);
        glVertex3f(x, -height_of_house, z);
        glEnd();
    } else {
        float z = width_of_house;
        glBegin(GL_POLYGON);
        glVertex3f(-width_of_door, -height_of_house + height_of_door, z);
        glVertex3f(width_of_door, -height_of_house + height_of_door, z);
        glVertex3f(width_of_door, -height_of_house, z);
        glVertex3f(-width_of_door, -height_of_house, z);
        glEnd();
    }
}

void window() {
    if (window1) {
        float x = -width_of_house;
        float z = -size_of_window;
        glBegin(GL_POLYGON);
        glVertex3f(x, size_of_window, z);
        glVertex3f(x - size_of_window * 2, size_of_window, z);
        glVertex3f(x - size_of_window * 2, -size_of_window, z);
        glVertex3f(x, -size_of_window, z);
        glEnd();
    } else {
        float x = -width_of_house;
        glBegin(GL_POLYGON);
        glVertex3f(x, size_of_window, size_of_window);
        glVertex3f(x, size_of_window, -size_of_window);
        glVertex3f(x, -size_of_window, -size_of_window);
        glVertex3f(x, -size_of_window, size_of_window);
        glEnd();
    }
    if (window2) {
        float x = width_of_house;
        float z = -size_of_window;
        glBegin(GL_POLYGON);
        glVertex3f(x, size_of_window, z);
        glVertex3f(x + size_of_window * 2, size_of_window, z);
        glVertex3f(x + size_of_window * 2, -size_of_window, z);
        glVertex3f(x, -size_of_window, z);
        glEnd();
    } else {
        float x = width_of_house;
        glBegin(GL_POLYGON);
        glVertex3f(x, size_of_window, size_of_window);
        glVertex3f(x, size_of_window, -size_of_window);
        glVertex3f(x, -size_of_window, -size_of_window);
        glVertex3f(x, -size_of_window, size_of_window);
        glEnd();
    }
}

void tree(float X, float Y, float Z) {
    fill_color(0, 255, 0);
    glPushMatrix();
    glTranslated(X, Y + 15, Z);
    glRotated(90, -1.0, 0.0, 0.0);
    glutSolidCone(3, 6, 50, 50);
    glPopMatrix();
    glPushMatrix();
    glTranslated(X, Y + 13, Z);
    glRotated(90, -1.0, 0.0, 0.0);
    glutSolidCone(3.5, 5, 50, 50);
    glPopMatrix();
    glPushMatrix();
    glTranslated(X, Y + 11, Z);
    glRotated(90, -1.0, 0.0, 0.0);
    glutSolidCone(4, 4, 50, 50);
    glPopMatrix();
    glPushMatrix();
    fill_color(200, 100, 20);
    glTranslated(X, Y + 7, Z);
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
    gluCylinder(quadratic, 1.0, 1.0, 6.0, 32, 32);
    glPopMatrix();
}

void ground(float X) {
    fill_color(194, 178, 128);
    glBegin(GL_POLYGON);
    glVertex3f(-X, -height_of_house, -X);
    glVertex3f(X, -height_of_house, -X);
    glVertex3f(X, -height_of_house, X);
    glVertex3f(-X, -height_of_house, X);
    glEnd();
}

void road(float l) {
    fill_color(128, 128, 128);
    glBegin(GL_POLYGON);
    glVertex3f(-l, -height_of_house + 0.01, 3 * height_of_house);
    glVertex3f(l, -height_of_house + 0.01, 3 * height_of_house);
    glVertex3f(l, -height_of_house + 0.01, 6 * height_of_house);
    glVertex3f(-l, -height_of_house + 0.01, 6 * height_of_house);
    glEnd();
}
void chalo() {
    fill_color(255, 0, 0);

    glBegin(GL_POLYGON);
    glVertex3f(reference_point + width_of_house, reference_point - height_of_house + 0.01, reference_point + width_of_house);
    glVertex3f(reference_point + width_of_house, reference_point - height_of_house + 0.01, reference_point - width_of_house);
    glVertex3f(reference_point - width_of_house, reference_point - height_of_house + 0.01, reference_point - width_of_house);
    glVertex3f(reference_point - width_of_house, reference_point - height_of_house + 0.01, reference_point + width_of_house);
    glEnd();

    glColor3f(roof_red, roof_green, roof_blue);
    glBegin(GL_POLYGON);
    glVertex3f(reference_point + width_of_roof, reference_point + height_of_house, reference_point + width_of_roof);
    glVertex3f(reference_point + width_of_roof, reference_point + height_of_house, reference_point - width_of_roof);
    glVertex3f(reference_point - width_of_roof, reference_point + height_of_house, reference_point - width_of_roof);
    glVertex3f(reference_point - width_of_roof, reference_point + height_of_house, reference_point + width_of_roof);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(reference_point + width_of_roof, reference_point + height_of_house, reference_point + width_of_roof);
    glVertex3f(reference_point + width_of_roof, reference_point + height_of_house, reference_point - width_of_roof);
    glVertex3f(reference_point, height_of_roof, reference_point);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(reference_point + width_of_roof, reference_point + height_of_house, reference_point - width_of_roof);
    glVertex3f(reference_point - width_of_roof, reference_point + height_of_house, reference_point - width_of_roof);
    glVertex3f(reference_point, height_of_roof, reference_point);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(reference_point, height_of_roof, reference_point);
    glVertex3f(reference_point - width_of_roof, reference_point + height_of_house, reference_point - width_of_roof);
    glVertex3f(reference_point - width_of_roof, reference_point + height_of_house, reference_point + width_of_roof);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(reference_point + width_of_roof, reference_point + height_of_house, reference_point + width_of_roof);
    glVertex3f(reference_point, height_of_roof, reference_point);
    glVertex3f(reference_point - width_of_roof, reference_point + height_of_house, reference_point + width_of_roof);
    glEnd();
}
void bhopal() {
    table(-width_of_house + 2, -height_of_house + 1.5, -width_of_house + 2);
    bed(0.5 * width_of_house, -height_of_house + 0.6, 0);
    door();
    window();
}
void house() {
    fill_color(255, 255, 255);
    glBegin(GL_POLYGON);

    glVertex3f(reference_point + width_of_house, reference_point - height_of_house, reference_point - width_of_house);
    glVertex3f(reference_point + width_of_house, reference_point + height_of_house, reference_point - width_of_house);
    glVertex3f(reference_point - width_of_house, reference_point + height_of_house, reference_point - width_of_house);
    glVertex3f(reference_point - width_of_house, reference_point - height_of_house, reference_point - width_of_house);
    glEnd();

    glColor3f(house_red, house_green, house_blue);

    wall_with_door(width_of_house);

    wall_with_window(width_of_house);

    wall_with_window(-width_of_house);

    chalo();

    bhopal();
}

void light(float X, float Y, float Z) {
    GLfloat position0[] = {X, Y, Z, 0.0};

    GLfloat ambient0[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat specular0[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat diffuse0[] = {1.0, 1.0, 1.0, 1.0};

    glEnable(GL_LIGHTING);

    glEnable(GL_COLOR_MATERIAL);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    GLfloat specular_material[] = {0, 0, 0, 1};
    GLfloat emission_material[] = {0, 0, 0, 1};
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_material);
    glMaterialfv(GL_FRONT, GL_EMISSION, emission_material);

    if (intensity == 1) {
        glEnable(GL_LIGHT0);
        glLightfv(GL_LIGHT0, GL_POSITION, position0);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
        glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);
    } else {
        glDisable(GL_LIGHT0);
    }
    if (intensity == 2) {
        glEnable(GL_LIGHT1);
        glLightfv(GL_LIGHT1, GL_POSITION, position0);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse0);
        glLightfv(GL_LIGHT1, GL_AMBIENT, ambient0);
        glLightfv(GL_LIGHT1, GL_SPECULAR, specular0);
    }
    if (intensity == 3) {
        glEnable(GL_LIGHT2);
        glLightfv(GL_LIGHT2, GL_POSITION, position0);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse0);
        glLightfv(GL_LIGHT2, GL_AMBIENT, ambient0);
        glLightfv(GL_LIGHT2, GL_SPECULAR, specular0);
    }
    if (intensity == 4) {
        glEnable(GL_LIGHT3);
        glLightfv(GL_LIGHT3, GL_POSITION, position0);
        glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuse0);
        glLightfv(GL_LIGHT3, GL_AMBIENT, ambient0);
        glLightfv(GL_LIGHT3, GL_SPECULAR, specular0);
    }
    if (intensity == 5) {
        glEnable(GL_LIGHT4);
        glLightfv(GL_LIGHT4, GL_POSITION, position0);
        glLightfv(GL_LIGHT4, GL_DIFFUSE, diffuse0);
        glLightfv(GL_LIGHT4, GL_AMBIENT, ambient0);
        glLightfv(GL_LIGHT4, GL_SPECULAR, specular0);
    }
    if (intensity == 6) {
        glEnable(GL_LIGHT5);
        glLightfv(GL_LIGHT5, GL_POSITION, position0);
        glLightfv(GL_LIGHT5, GL_DIFFUSE, diffuse0);
        glLightfv(GL_LIGHT5, GL_AMBIENT, ambient0);
        glLightfv(GL_LIGHT5, GL_SPECULAR, specular0);
    }
}
void func() {
    camera[0] += front_back * sin(sii);
    camera[2] -= front_back * cos(sii);
    front_back = 0;
    float lookat[] = {Radius * sin(sii) + camera[0], Radius * cos(Theta) + camera[1], -Radius * cos(sii) + camera[2]};
    cout << "Radius " << Radius << endl;
    gluLookAt(camera[0], camera[1], camera[2], /* look from camera XYZ */
              lookat[0], lookat[1], lookat[2], /* look at the origin */
              0, 1, 0);                        /* positive Y up vector */
    cout << "see at " << lookat[0] << " " << lookat[1] << " " << lookat[2] << endl;
    cout << "sii " << sii << endl;
}
void banao() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    func();

    glPushMatrix();
    light(30, 30, 30);
    ground(1000);
    tree(5 * width_of_house, -3 * height_of_house, width_of_house);
    house();
    road(300);

    glPopMatrix();
    glutSwapBuffers();
}

// make rotation active if current mouse left button is clicked
void track_mouse_press(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        switch (button) {
            case 3:
                Radius -= 0.5;
                break;
            case 4:
                Radius += 0.5;
                break;
            default:
                break;
        }
    }
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_UP) {
            mouse_pressed = false;
            start_x = -1;
            start_y = -1;
        } else {
            mouse_pressed = true;
        }
    }
}

void track_mouse_movement(int x, int y) {
    if (start_x == -1)
        start_x = x;
    if (start_y == -1)
        start_y = y;
    if (mouse_pressed) {
        Theta += (y - start_y) * unit_change * 0.015;

        sii -= (x - start_x) * unit_change * 0.015;

        if (sii > 2 * PI)
            sii -= 2 * PI;
        if (sii < 0)
            sii += 2 * PI;
        if (Theta > 2 * PI)
            Theta -= 2 * PI;
        if (Theta < 0)
            Theta += 2 * PI;
    }
    start_x = x;
    start_y = y;
}

void processNormalKeys(unsigned char key, int x, int y) {
    switch (key) {
        case 'z':
            intensity += 1;
            break;
        case 'x':
            intensity -= 1;
            break;
    }
    switch (key) {
        case 'w':
            front_back += 1;
            break;
        case 's':
            front_back -= 1;
            break;
    }
    switch (key) {
        case 'f':
            flip = !flip;
            break;
        case 'c':
            window1 = !window1;
            break;
        case 'v':
            window2 = !window2;
            break;
    }
}
void encode(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            Theta -= unit_change * 0.3;
            break;
        case GLUT_KEY_DOWN:
            Theta += unit_change * 0.3;
            break;
    }
    switch (key) {
        case GLUT_KEY_RIGHT:
            if (Theta >= (3 * PI / 2) || Theta <= (PI / 2))
                sii -= unit_change * 0.3;
            else
                sii += unit_change * 0.3;
            break;
        case GLUT_KEY_LEFT:
            if (Theta >= (3 * PI / 2) || Theta <= (PI / 2))
                sii += unit_change * 0.3;
            else
                sii -= unit_change * 0.3;
            break;
    }
    if (sii > 2 * PI)
        sii -= 2 * PI;
    if (sii < 0)
        sii += 2 * PI;
    if (Theta > 2 * PI)
        Theta -= 2 * PI;
    if (Theta < 0)
        Theta += 2 * PI;
}
void encodeSKeys(int key, int x, int y) {
    encode(key, x, y);
}

int main(int C, char *V[]) {
    glutInit(&C, V);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(300, 300);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("House");

    glutDisplayFunc(banao);
    glutReshapeFunc(change_size_of_window);
    glutIdleFunc(banao);

    glClearColor(128 / 255.0, 128 / 255.0, 255 / 255.0, 0.0);

    glutMouseFunc(track_mouse_press);
    glutMotionFunc(track_mouse_movement);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(encodeSKeys);

    glEnable(GL_DEPTH_TEST);
    glutMainLoop();

    return 0;
}

// #include <bits/stdc++.h>
// typedef long long ll;
// typedef long double ld;
// #define fr(i,a,b) for(ll i=a; i<b; i++)
// #define rf(i,a,b) for(ll i=a; i>=b; i--)
// typedef std::vector<long long > vi ;
// #define F first
// #define S second
// #define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define mod 1000000007
// #define PB push_back
// #define MP make_pair
// #define PI 3.14159265358979323846
// #define all(a) a.begin(),a.end()
// #define mx(a) *max_element(all(a))
// #define mn(a) *min_element(all(a))
// const ll INF=LLONG_MAX/2;
// const ll N=2e5+1;
// using  namespace std;
// long long  fact[100005],ifact[100005];
// void pre();
// ll ncr(ll,ll);
// ll pow1(ll n,ll p)
// {
//    if(p==0)return 1;
//    ll x=pow1(n, p/2);
//    x=(x*x)%mod;
//    if(p%2==0)
//    return x;
//    else
//    return (x*n)%mod;
// }
// ll binarySearch(ll arr[], ll l, ll r,ll x)
// {
//    if (r >= l)
//    {
// 	   ll mid = l + (r - l) / 2;
// 		if (arr[mid] == x)
// 		return mid;
// 		if (arr[mid] > x)
// 		return binarySearch(arr, l, mid - 1, x);
// 		return binarySearch(arr, mid + 1, r, x);
//    }
// 	return -1;
// }
// ll gcd(ll a, ll b, ll &x, ll &y)
//  {
// if (a == 0) {
//  x = 0; y = 1;
// 		return b;
//  }
// 	ll x1, y1;
// 	ll d = gcd(b%a, a, x1, y1);
// 	x = y1 - (b / a) * x1;
// 	y = x1;
// 	return d;
// }
// bool find_any_solution(ll a, ll b,ll c, ll &x0, ll &y0, ll &g) {
// 	g = gcd(llabs(a), llabs(b), x0, y0);
// 	if (c % g) {
// 		return false;
// 	}
// 	x0 *= c / g;
// 	y0 *= c / g;
// 	if (a < 0) x0 = -x0;
// 	if (b < 0) y0 = -y0;
// 	return true;
// }
// void shift_solution(ll & x,ll & y, ll a, ll b, ll cnt) {
// x += cnt * b;
// 	y -= cnt * a;
// }
// ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy)
// {
// ll x, y, g;
// if (!find_any_solution(a, b, c, x, y, g))
// return 0;
// a /= g;
// 	b /= g;

// 	ll sign_a = a > 0 ? +1 : -1;
// 	ll sign_b = b > 0 ? +1 : -1;

// 	shift_solution(x, y, a, b, (minx - x) / b);
//    if (x < minx)
// shift_solution(x, y, a, b, sign_b);
// if (x > maxx)
// return 0;
// ll lx1 = x;
// shift_solution(x, y, a, b, (maxx - x) / b);
// if (x > maxx)
// shift_solution(x, y, a, b, -sign_b);
// ll rx1 = x;
// shift_solution(x, y, a, b, -(miny - y) / a);
// if (y < miny)
// shift_solution(x, y, a, b, -sign_a);
// if (y > maxy)
// return 0;
// ll lx2 = x;

//  shift_solution(x, y, a, b, -(maxy - y) / a);
// if (y > maxy)
// shift_solution(x, y, a, b, sign_a);
// ll rx2 = x;
// if (lx2 > rx2)
// swap(lx2, rx2);
// 	ll lx = max(lx1, lx2);
// 	ll rx = min(rx1, rx2);
// if (lx > rx)
// return 0;
// return (rx - lx) / llabs(b) + 1;
// }
// bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b)
// {
//  return (a.second < b.second);
// }

// bool compare(const pair<ll, ll>&p1, const pair<ll,ll>&p2)
// {
//   if(p1.F < p2.F) return true;
//  if(p1.F == p2.F) return p1.S < p2.S;
// return false;
// }
// int main()
// {
// 	fast;
//    ll t=1;
//    std::cin >> t;
//    while(t--)
//    {
// 	   ll n,i,j=0;
// 	   std::cin >> n;
//    }
// }
// void pre()
// {
// 	ll n=100000;
// 	fact[0]=fact[1]=1;
// 	for(long long  i=2;i<=n;i++) fact[i]=(fact[i-1]*i)%mod;
// 	ifact[n]=pow1(fact[n],mod-2);
// 	for(long long  i=n-1;i>=0;i--)
// 	{
// 	   ifact[i]=(ifact[i+1]*(i+1))%mod;
// 	}
// }
// ll ncr(ll n,ll r)
// {
// ll res=(fact[n]*ifact[r])%mod;
// 	res=(res*ifact[n-r])%mod;
// return res;
// }