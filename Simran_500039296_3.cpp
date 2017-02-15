#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
//#include <freeglut.h>
#include <iostream>
#include <string>
#include <cmath>
bool flagr=false;
bool flagl=false;
using namespace std;
void RenderString(float x, float y, void *font, const char* string)
{  
  char *c;
  glColor3f(0.91, 0.91, 0.91); 
  glRasterPos2f(x, y);
  for(int i=0;string[i]!='\0';i++)
  glutBitmapCharacter(font, string[i]);
}

//circle
void circle(float r, float g, float b, float xc,float yc)
{
	glBegin(GL_TRIANGLE_FAN);
    	for(int i=0;i<100;i++)
    	{
    		float theta=(2.0f)*(3.1415926f)*float(i)/(float)(100);
    		float x=(0.05f)*cosf(theta);
    		float y=(0.05f)*sinf(theta);
    		glColor3f(r, g, b);
    		glVertex2f(x+xc, y+yc);
    	}        
    glEnd();
}

void display(void)
{

    glClear (GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    	glColor3f(0.804, 0.522, 0.247);
        glVertex2f (-0.75, -0.50);
        glVertex2f (-0.75, 0.15);
        glVertex2f (0.75, 0.15);
        glVertex2f (0.75, -0.50);
    glEnd();
    glBegin(GL_POLYGON);
    	glColor3f(0.647, 0.165, 0.165);
    	glVertex2f (-0.5, -0.50);
    	glVertex2f (-0.5, -0.30);
    	glVertex2f (-0.3, -0.30);
    	glVertex2f (-0.3, -0.50);
    glEnd();
    glBegin(GL_POLYGON);
    	glColor3f(0.647, 0.165, 0.165);
    	glVertex2f (0.5, -0.50);
    	glVertex2f (0.5, -0.30);
    	glVertex2f (0.3, -0.30);
    	glVertex2f (0.3, -0.50);
    glEnd();
    glBegin(GL_POLYGON);
    	glColor3f(0.871, 0.722, 0.529);
    	glVertex2f (-0.75, 0.0);
    	glVertex2f (-0.75, -0.30);
    	glVertex2f (-0.6, -0.30);
    	glVertex2f (-0.6, 0.0);
    glEnd();
     glBegin(GL_POLYGON);
    	glColor3f(0.871, 0.722, 0.529);
    	glVertex2f (0.75, 0.0);
    	glVertex2f (0.75, -0.30);
    	glVertex2f (0.6, -0.30);
    	glVertex2f (0.6, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
    	glColor3f(0.941, 0.902, 0.549);
    	glVertex2f (-0.2, -0.150);
    	glVertex2f (-0.2, 0.150);
    	glVertex2f (0.2, 0.150);
    	glVertex2f (0.2, -0.150);
    glEnd();
     glBegin(GL_POLYGON);
    	glColor3f(0.545, 0.271, 0.075);
    	glVertex2f (-0.15, -0.150);
    	glVertex2f (-0.15, 0.);
    	glVertex2f (0.15, 0);
    	glVertex2f (0.15, -0.150);
    glEnd();
    glBegin(GL_POLYGON);
    	glColor3f(0.941, 0.902, 0.549);
    	glVertex2f (-0.1, 0.150);
    	glVertex2f (0.1, 0.150);
    	glVertex2f (0.0, 0.450);
    glEnd();
    glBegin(GL_POLYGON);
    	glColor3f(0.804, 0.522, 0.247);
        glVertex2f (-0.75, 0.150);
        glVertex2f (-0.5, 0.15);
        glVertex2f (-0.625, 0.45);        
    glEnd();
    glBegin(GL_POLYGON);
    	glColor3f(0.804, 0.522, 0.247);
        glVertex2f (0.75, 0.150);
        glVertex2f (0.5, 0.15);
        glVertex2f (0.625, 0.45);        
    glEnd();
    circle(0.94, 0.66, 0.02, 0.7,0.8);
    if(flagl==false)
    {
    	circle(0.96, 0.66, 0.71,-0.625,0.3);
    }
    else
    if(flagl==true)
    {
    	circle(0.184, 0.310, 0.310, -0.625,0.3);
    }
    if(flagr==false)
    {
    	circle(0.184, 0.310, 0.310, 0.625,0.3);
    }
    else
    if(flagr==true)
    {
 
    	circle(0.96, 0.66, 0.71, 0.625,0.3);
    }

    RenderString(-0.75f, 0.8f, GLUT_BITMAP_TIMES_ROMAN_24, "Simran, R134214067");
    RenderString(-0.75f, -0.8f, GLUT_BITMAP_TIMES_ROMAN_24, "Hut");
    glFlush ();
}
void myMouse(int button, int state, int x, int y)
{	
	float mx=float(x)/(700.0f)*(2)-1;
	float my=float(y)/(700.0f)*2-1;
	my=-my;
	float vall=(mx+0.625)*(mx+0.625)+(my-0.3)*(my-0.3)-(0.05f)*(0.05f);
	float valr=(mx-0.625)*(mx-0.625)+(my-0.3)*(my-0.3)-(0.05f)*(0.05f);
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(vall<=0)
		{
			flagl=!flagl;
			glutPostRedisplay();
		}
		if(valr<=0)
		{
			flagr=!flagr;
			glutPostRedisplay();
		}
	}
}
void init (void) 
{
    glClearColor(0.15, 0.15, 0.15, 0.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (700, 700); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("R134214067");
    init ();
    glutMouseFunc(myMouse);
    glutDisplayFunc(display); 
    glutMainLoop();
	return 0;
}
