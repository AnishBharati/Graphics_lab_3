#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    float r = 200.0;
    float anginc = 1.0; 
    float ang = 0;
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 0.0);

    while (ang < 360) {
        float x = r * cos(ang * 3.14159 / 180); 
        float y = r * sin(ang * 3.14159 / 180);

        glVertex2f(x, y); 
        glVertex2f(x, -y);
        glVertex2f(-x, y);
        glVertex2f(-x, -y);
        glVertex2f(y, x);
        glVertex2f(y, -x);
        glVertex2f(-y, x);
        glVertex2f(-y, -x);

        ang += anginc;
    }

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Polar Coordinate Circle");
    glClearColor(1.0, 1.0, 1.0, 0.0); 
    gluOrtho2D(-550.0, 550.0, -550.0, 550.0);
    glPointSize(5.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
