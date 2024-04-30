#include <GL/glut.h>
#include <iostream>
#include <cmath>

int xc = 300, yc = 300; 
int rx = 150, ry = 100;   

void drawEllipsePoints(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glEnd();
}

void drawEllipse() {
    int x = 0, y = ry;
    float P1 = pow(ry, 2) - (pow(rx, 2) * ry) + (0.25 * pow(rx, 2));

    drawEllipsePoints(x, y);

    while ((pow(rx, 2) * (y - 0.5)) > (pow(ry, 2) * (x + 1))) {
        if (P1 < 0) {
            P1 += pow(ry, 2) * (2 * x + 3);
        } else {
            P1 += pow(ry, 2) * (2 * x + 3) + pow(rx, 2) * (-2 * y + 2);
            y--;
        }
        x++;
        drawEllipsePoints(x, y);
    }

    float P2 = pow(ry, 2) * pow((x + 0.5), 2) + pow(rx, 2) * pow((y - 1), 2) - pow(rx, 2) * pow(ry, 2);

    while (y > 0) {
        if (P2 < 0) {
            P2 += pow(ry, 2) * (2 * x + 2) + pow(rx, 2) * (-2 * y + 3);
            x++;
        } else {
            P2 += pow(rx, 2) * (-2 * y + 3);
        }
        y--;
        drawEllipsePoints(x, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); 
    glPointSize(5.0);        

    glPushMatrix();
    glTranslatef(xc, yc, 0);
    glTranslatef(-xc, -yc, 0);
    drawEllipse();

    glPopMatrix();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Ellipse");
    glClearColor(1.0, 1.0, 1.0, 0.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);    
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
