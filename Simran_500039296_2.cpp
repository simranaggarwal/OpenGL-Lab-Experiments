#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

void RenderString(float x, float y, void *font, const char* string)
{  
  char *c;
  glColor3f(0.91, 0.91, 0.91); 
  glRasterPos2f(x, y);
  for(int i=0;string[i]!='\0';i++)
  glutBitmapCharacter(font, string[i]);
}
void display(void)
{

    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f (-0.25, 0);
        glVertex2f (0.25, 0);
        glVertex2f (0, 0.5);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f (-0.25, 0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f (-0.75, 0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f (-0.5, -0.5);
    glEnd();
    RenderString(-0.75f, 0.8f, GLUT_BITMAP_TIMES_ROMAN_24, "Simran, R134214067");
    RenderString(-0.85f, -0.8f, GLUT_BITMAP_TIMES_ROMAN_24, "Two Coloured triangles");
    glFlush ();
}

void init (void) 
{
    glClearColor(0.15, 0.15, 0.15, 0.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (250, 250); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("R134214067");
    init ();
    glutDisplayFunc(display); 
    glutMainLoop();
    return 0;  
}