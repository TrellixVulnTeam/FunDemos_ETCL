#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, 0);
    glVertex2f(0, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("test");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

