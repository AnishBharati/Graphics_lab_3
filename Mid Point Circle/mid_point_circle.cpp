#include <GL/glut.h>
#include <math.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    int xc = 600, yc = 600; 
    float r = 200.0;      
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 0.0); 

    int x = 0, y = r;
    int P = (5/4) - r;  

    glVertex2f(xc,yc);

    auto plotPoints = [&](int x, int y) {
        glVertex2f(xc + x, yc + y);
        glVertex2f(xc - x, yc + y);
        glVertex2f(xc + x, yc - y);
        glVertex2f(xc - x, yc - y);
        glVertex2f(xc + y, yc + x);
        glVertex2f(xc - y, yc + x);
        glVertex2f(xc + y, yc - x);
        glVertex2f(xc - y, yc - x);
    };

    plotPoints(x, y);

    while (x < y) {
        x++;
        if (P < 0) {
            P += 2 * x + 1;
        } else {
            y--;
            P += 2 * (x - y) + 1;
        }
        plotPoints(x, y);
    if(x>y){
        break;
    }
    }
    

    glEnd();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Midpoint Circle");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    gluOrtho2D(0.0, 1200.0, 0.0, 1200.0); 
    glPointSize(5.0); 
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
