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
    int x1, y1, r;
    cout << "Enter x y coordinates of start point & radius of circle\n";
    cin >> x1 >> y1 >> r;
    // BresennHam Method for circle drawing
    int di = 3 - 2 * r;
    int x = 0, y = r;
    bresenham_pts.push_back({0, r});
    while (x <= y) {
        x++;
        if (di > 0) {
            y--;
            di = di + 4 * x - 4 * y + 10;
        } else {
            di = di + 4 * x + 6;
        }
        bresenham_pts.push_back({x, y});
    }
    int n = bresenham_pts.size();
    for (int i = 0; i < n; i++) {
        bresenham_pts.push_back({bresenham_pts[i].second, bresenham_pts[i].first});
    }
    n = bresenham_pts.size();
    for (int i = 0; i < n; i++) {
        bresenham_pts.push_back({-bresenham_pts[i].first, bresenham_pts[i].second});
    }
    n = bresenham_pts.size();
    for (int i = 0; i < n; i++) {
        bresenham_pts.push_back({bresenham_pts[i].first, -bresenham_pts[i].second});
    }
    n = bresenham_pts.size();
    for (int i = 0; i < n; i++) {
        bresenham_pts[i].first += x1, bresenham_pts[i].second += y1;
    }
    //  Mid Point Circle drawing algorithm
    int xi = 0, yi = r;
    int dii = 1 - r;
    midAlgo_pts.push_back({0, r});
    while (xi <= yi) {
        xi++;
        if (dii <= 0) {
            dii = dii + 2 * xi + 3;
        } else {
            yi--;
            dii = dii + 2 * xi - 2 * yi + 5;
        }
        midAlgo_pts.push_back({xi, yi});
    }

    n = midAlgo_pts.size();
    for (int i = 0; i < n; i++) {
        midAlgo_pts.push_back({midAlgo_pts[i].second, midAlgo_pts[i].first});
    }
    n = midAlgo_pts.size();
    for (int i = 0; i < n; i++) {
        midAlgo_pts.push_back({-midAlgo_pts[i].first, midAlgo_pts[i].second});
    }
    n = midAlgo_pts.size();
    for (int i = 0; i < n; i++) {
        midAlgo_pts.push_back({midAlgo_pts[i].first, -midAlgo_pts[i].second});
    }
    n = midAlgo_pts.size();
    for (int i = 0; i < n; i++) {
        midAlgo_pts[i].first += x1, midAlgo_pts[i].second += y1;
    }

    glutInit(&C, V);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1200, 1200);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Line Drawing Algos");
    glClearColor(1, 1, 1, 1);
    glutDisplayFunc(draw);
    // gluOrtho2D
    gluOrtho2D(-500, 500, -500, 500);
    glutMainLoop();
}