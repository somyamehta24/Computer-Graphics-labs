// 190001058 Somya Mehta
// BoundaryFill Algo
// Assignment-5

#include <bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glut.h>

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

int n;
vector<pair<int, int>> pts;

int neighbourhood;
vector<float> border_color = {1, 0, 0};
vector<float> interior_color = {0, 1, 0};
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
void boundaryfillalgo(int x, int y) {
    float color[3];
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color);
    vector<float> cmp = {color[0], color[1], color[2]};
    if ((color[0] != border_color[0] || color[1] != border_color[1] || color[2] != border_color[2]) &&
        cmp != interior_color) {
        glBegin(GL_POINTS);
        glColor3f(interior_color[0], interior_color[1], interior_color[2]);
        glVertex2f(x, y);
        glEnd();
        glFlush();
        if (neighbourhood == 1) {
            for (int i = 0; i < 8; i++)
                boundaryfillalgo(x + dx[i], y + dy[i]);
        } else {
            for (int i = 0; i < 4; i++)
                boundaryfillalgo(x + dx[i], y + dy[i]);
        }
    }
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(4);
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < n; i++) {
        glVertex2f(pts[i].first, pts[i].second);
    }
    glEnd();
    glFlush();
    int x, y;
    cout << "\n Enter an interior point of the shape from which you want to start ";
    cin >> x >> y;
    boundaryfillalgo(x, y);

    glFlush();
}

int main(int C, char* V[]) {
    cout << "\n*****How many boundary points you want to show *********\n";
    cin >> n;
    cout << "\n***** PLease enter the points in clockwise direction******** \n";
    for (int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;
        pts.push_back({xi, yi});
    }
    cout << "\nEnter 0 for 4-neighbourhood and 1 for 8-neighbourhood: ";
    cin >> neighbourhood;
    if (neighbourhood != 0 && neighbourhood != 1) {
        cout << "\nWrong Input Given...Exiting";
        exit(0);
    }
    glutInit(&C, V);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(800, 800);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Boundary Filling Algo");
    glClearColor(0, 0, 0, 0);
    gluOrtho2D(0, 800, 0, 800);
    glutDisplayFunc(draw);
    glutMainLoop();
}