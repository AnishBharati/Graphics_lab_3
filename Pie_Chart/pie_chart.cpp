#include <GL/glut.h>
#include <cmath>
#include <iostream>

int centerX = 300, centerY = 300; 
int radius = 200;
int borderWidth = 10;

const int MAX_SECTIONS = 5;
float percentages[MAX_SECTIONS]; 
float colors[MAX_SECTIONS][3] = {
    {1.0, 0.0, 0.0}, 
    {0.0, 1.0, 0.0}, 
    {0.0, 0.0, 1.0}, 
    {1.0, 1.0, 0.0}, 
    {1.0, 0.0, 1.0}  
};

void drawCircle(int cx, int cy, int r) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(cx, cy);
    for (int i = 0; i <= 360; i++) {
        float theta = i * 3.14159 / 180;
        float x = cx + r * cos(theta);
        float y = cy + r * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawPieChart(int cx, int cy, int r, float startAngle, float endAngle, float color[3]) {
    glColor3fv(color);
    glBegin(GL_POLYGON);
    glVertex2i(cx, cy); 
    for (float angle = startAngle; angle < endAngle; angle += 1.0) {
        float theta = angle * 3.14159 / 180;
        float x = cx + r * cos(theta);
        float y = cy + r * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    drawCircle(centerX, centerY, radius + borderWidth / 2);

    float startAngle = 0.0;
    for (int i = 0; i < MAX_SECTIONS; i++) {
        float endAngle = startAngle + percentages[i] * 360 / 100;
        drawPieChart(centerX, centerY, radius, startAngle, endAngle, colors[i]);
        startAngle = endAngle;
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Pie Chart");
    glClearColor(1.0, 1.0, 1.0, 0.0); // White background
    gluOrtho2D(0, 600, 0, 600); // Set the viewport

    std::cout << "Enter the percentage for each segment (up to 5, summing to 100%):\n";
    float total = 0;
    int count = 0;
    while (total < 100 && count < MAX_SECTIONS) {
        std::cout << "Percentage for segment " << (count + 1) << ": ";
        std::cin >> percentages[count];
        total += percentages[count];
        if (total > 100) {
            std::cout << "Total percentage exceeds 100%, please enter values again.\n";
            total = 0;
            count = -1;
        }
        count++;
    }

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
