// 190001058
// Somya Mehta
#include <GL/gl.h>
#include <bits/stdc++.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;
vector<pair<int, int>> bresenham_pts;
vector<pair<int, int>> midAlgo_pts;
void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10);
    glBegin(GL_POINTS);
    for (auto pt : bresenham_pts) {
        glColor3f(0, 0, 1);
        glVertex2f(pt.first, pt.second);
    }
    glEnd();
    glPointSize(5);
    glBegin(GL_POINTS);
    for (auto pt : midAlgo_pts) {
        glColor3f(1, 0, 0);
        glVertex2f(pt.first, pt.second);
    }
    glEnd();
    glFlush();
}

int main(int C, char* V[]) {
    int x1, y1, xn, yn;
    int t1, t2, p1, p2;
    cout << "Enter Start & end points\n";
    cin >> x1 >> y1;
    cin >> xn >> yn;
    if (x1 > xn) {
        swap(x1, xn);
        swap(y1, yn);
    } else if (x1 == xn) {
        cout << "Straight line parallel to y-axis will be formed/nDo you want to continue? y or n /n";
        char ch;
        cin >> ch;
        if (ch == 'y' || ch == 'Y') {
            for (int yi = min(y1, yn); yi <= max(y1, yn); yi++) {
                int xi = x1;
                bresenham_pts.push_back({xi, yi});
                midAlgo_pts.push_back({xi, yi});
            }
            glutInit(&C, V);
            glutInitWindowPosition(0, 0);
            glutInitWindowSize(500, 500);
            glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
            glutCreateWindow("Line Drawing Algos");
            glClearColor(1, 1, 1, 1);
            glutDisplayFunc(draw);
            // gluOrtho2D
            gluOrtho2D(-100, 100, 100, -100);
            glutMainLoop();
        }
        return 0;
    }
    t1 = x1, t2 = xn, p1 = y1, p2 = yn;
    int dy = yn - y1, dx = xn - x1;
    // BresennHam Method
    //  if |m|<=1
    if (dx >= dy) {
        int pi = 2 * dy - dx;  // for checking whether to increment yi
        bresenham_pts.push_back({x1, y1});
        int yi = y1;
        for (int xi = x1 + 1; xi <= xn; xi++) {
            if (pi >= 0) {
                yi = yi + 1;
                pi = pi + 2 * dy - 2 * dx;
            } else if (pi < 0) {
                pi = pi + 2 * dy;
            }
            bresenham_pts.push_back({xi, yi});
        }
    }  // if |m|>1 // we can swap x and y
    else {
        swap(dx, dy);
        swap(x1, y1);
        swap(xn, yn);
        if (x1 > xn) {
            swap(x1, xn);
            swap(y1, yn);
        }
        dx = xn - x1;
        dy = yn - y1;
        // p0;
        int pi = 2 * dy - dx;
        bresenham_pts.push_back({y1, x1});
        int yi = y1;
        for (int xi = x1 + 1; xi <= xn; xi++) {
            if (pi >= 0) {
                yi = yi + 1;
                pi = pi + 2 * dy - 2 * dx;
            } else if (pi < 0) {
                pi = pi + 2 * dy;
            }
            bresenham_pts.push_back({yi, xi});
        }
    }
    x1 = t1, xn = t2, y1 = p1, yn = p2;

    //  Mid Point Line drawing algorithm
    //  if |m|<=1
    dx = xn - x1;
    dy = yn - y1;
    if (dx >= dy) {
        double di = dy - dx / 2.0;  // for checking the position of mid point
        int yi = y1;
        midAlgo_pts.push_back({x1, y1});
        for (int xi = x1 + 1; xi <= xn; xi++) {
            if (di >= 0) {
                yi = yi + 1.0;
                di = di + dy - dx;
            } else if (di < 0) {
                di = di + dy;
            }
            midAlgo_pts.push_back({xi, yi});
        }
    }  // if |m|>1 // we can swap x and y
    else {
        swap(dx, dy);
        swap(x1, y1);
        swap(xn, yn);
        if (x1 > xn) {
            swap(x1, xn);
            swap(y1, yn);
        }
        if (x1 > xn) {
            swap(x1, xn);
            swap(y1, yn);
        }
        dx = xn - x1;
        dy = yn - y1;
        double di = dy - dx / 2.0;
        int yi = y1;
        midAlgo_pts.push_back({y1, x1});
        for (int xi = x1 + 1; xi <= xn; xi++) {
            if (di >= 0) {
                yi = yi + 1.0;
                di = di + dy - dx;
            } else if (di < 0) {
                di = di + dy;
            }
            midAlgo_pts.push_back({yi, xi});
        }
    }
    glutInit(&C, V);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 800);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Line Drawing Algos");
    glClearColor(1, 1, 1, 1);
    glutDisplayFunc(draw);
    // gluOrtho2D
    gluOrtho2D(-50, 50, -50, 50);
    glutMainLoop();
}
