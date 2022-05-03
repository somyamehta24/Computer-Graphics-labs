// 190001058
// Somya Mehta
// Assignment -5
// Scanfill Algo

#include <GL/glut.h>
#include <GL/glu.h>
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

// left edges and right edges we will find the intersection with the figures
int left_edge[500], right_edge[500], n, x, y;
vector<pair<int, int>> pts;
void utility_fill_intersection(int x1, int y1, int x2, int y2) {
    float x, slope;

    if (y1 > y2)
        swap(x1, x2), swap(y1, y2);

    if (y1 == y2)
        slope = (x2 - x1);
    else
        slope = (x2 - x1) / (y2 - y1);

    x = x1;
    for (int y = y1; y <= y2; y++) {
        if (x < left_edge[y])
            left_edge[y] = x;
        if (x > right_edge[y])
            right_edge[y] = x;

        x += slope;
    }
}

void Scanline_Algorithm() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 1);
    for (int i = 0; i < 500; i++)
        left_edge[i] = 500, right_edge[i] = 0;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < n; i++)
        glVertex2i(pts[i].first, pts[i].second);

    glEnd();

    for (int i = 0; i < n; i++)
        utility_fill_intersection(pts[i].first, pts[i].second, pts[(i + 1) % n].first, pts[(i + 1) % n].second);

    for (int y = 0; y < 500; y++) {
        for (int x = left_edge[y]; x < right_edge[y]; x++) {
            glBegin(GL_POINTS);
            glColor3f(0, 0, 1);
            glVertex2i(x, y);
            glEnd();
            glFlush();
        }
    }

    glFlush();
}

int main(int argc, char *argv[]) {
    // User input for number of vertices
    cout << "Enter total number of points: ";
    cin >> n;
    cout << "\nEnter total points in order \n";
    for (int i = 0; i < n; i++) {
        cout << "\nPoint :";
        cin >> x >> y;
        pts.push_back({x, y});
    }
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Polygon Filling Algorithm");
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(Scanline_Algorithm);
    glutMainLoop();
    return 0;
}