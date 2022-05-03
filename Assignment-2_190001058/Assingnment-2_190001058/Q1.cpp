// 190001058
// Somya Mehta
#include <GL/gl.h>
#include <bits/stdc++.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;
vector<pair<int, int>> poly_pts;
vector<pair<int, int>> dda_pts;
void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10);
    glBegin(GL_POINTS);
    for (auto pt : poly_pts) {
        glColor3f(0, 0, 1);
        glVertex2f(pt.first, pt.second);
    }
    glEnd();
    glPointSize(5);
    glBegin(GL_POINTS);
    for (auto pt : dda_pts) {
        glColor3f(1, 0, 0);
        glVertex2f(pt.first, pt.second);
    }
    glEnd();
    glFlush();
}

int main(int C, char* V[]) {
    int x1, y1, xn, yn;
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
                poly_pts.push_back({xi, yi});
                dda_pts.push_back({xi, yi});
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
    double intercept = (xn * y1 - yn * x1) / (double)(xn - x1);
    double slope = (double)(yn - y1) / (double)(xn - x1);
    // Polynomial Method
    //  if |m|<=1
    if (abs(slope) <= 1) {
        for (int xi = x1; xi <= xn; xi++) {
            int yi = round(slope * (double)xi + intercept);
            poly_pts.push_back({xi, yi});
        }
    }  // if |m|>1
    else {
        if (slope > 0) {
            for (int yi = y1; yi <= yn; yi++) {
                int xi = round(((double)yi - intercept) / slope);
                poly_pts.push_back({xi, yi});
            }
        } else {
            for (int yi = y1; yi >= yn; yi--) {
                int xi = round((yi - intercept) / slope);
                poly_pts.push_back({xi, yi});
            }
        }
    }
    // Digital Differential Analyzer Method
    // if |m|<1
    if (abs(slope) <= 1) {
        double prevyi = y1;
        dda_pts.push_back({x1, y1});
        for (int xi = x1 + 1; xi <= xn; xi++) {
            int yi = round(slope + (double)prevyi);
            prevyi = slope + (double)prevyi;
            dda_pts.push_back({xi, yi});
        }

    } else {
        double prevxi = x1;
        double invSlope = 1.0 / slope;
        dda_pts.push_back({x1, y1});
        if (slope > 0) {
            for (int yi = y1 + 1; yi <= yn; yi++) {
                double c = invSlope + prevxi;
                int xi = round(c);
                prevxi = c;
                dda_pts.push_back({xi, yi});
            }
        } else {
            for (int yi = y1 - 1; yi >= yn; yi--) {
                double c = -invSlope + prevxi;
                int xi = round(c);
                prevxi = c;
                dda_pts.push_back({xi, yi});
            }
        }
    }
    glutInit(&C, V);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 800);
    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("Line Drawing Algos");
    glClearColor(1, 1, 1, 1);
    glutDisplayFunc(draw);
    // gluOrtho2D
    gluOrtho2D(-50, 50, -50, 50);
    glutMainLoop();
}