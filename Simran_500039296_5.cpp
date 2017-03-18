#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;
float a=400,b=300;
int p,q;
void RenderString(float x, float y, void *font, const char* string)
{  
  char *c;
  glColor3f(0.0, 0.0, 0.0); 
  glRasterPos2f(x, y);
  for(int i=0;string[i]!='\0';i++)
  glutBitmapCharacter(font, string[i]);
}

void polar_circle(float x, float y, float r)
{
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 0.0);
		for(int theta=0;theta<=360;theta++)
		{
			float xx=x+r*cos(theta);
			float yy=y+r*sin(theta);
			glVertex2f(xx,yy);
		}
	glEnd();
	glFlush();
}

void polar_ellipse(float x, float y)
{
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 0.0);
		for(int theta=0;theta<=360;theta++)
		{
			float xx=x+a*cos(theta);
			float yy=y+b*sin(theta);
			glVertex2f(xx,yy);
		}
	glEnd();
	glFlush();
}

void midpoint_circle(float x, float y, float r)
{
	int xx=0,yy=r;
	int pk;
	pk=5/4-r;
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 0.0);
	while(xx<=yy)
	{
		if(pk<0)
		{
			xx=xx+1;
			pk=pk+2*xx+1;
		}
		else
		{
			xx=xx+1;
			yy=yy-1;
			pk=pk+2*xx-2*yy+1;
		}
		glVertex2f(x+xx,y+yy);
		glVertex2f(x+yy,y+xx);
		glVertex2f(x-xx,y+yy);
		glVertex2f(x-yy,y+xx);
		glVertex2f(x+xx,y-yy);
		glVertex2f(x+yy,y-xx);
		glVertex2f(x-xx,y-yy);
		glVertex2f(x-yy,y-xx);
	}
	glEnd();
	glFlush();
}

void midpoint_ellipse(float x, float y)
{			
	int pk;		
	int xx=0,yy=b;
	pk=b*b*(xx+1)*(xx+1)+a*a*(yy-0.5)*(yy+0.5)-a*a*b*b;
	glBegin(GL_POINTS);
	glColor3f(0.0,0.0,0.0);
		while((b*b*xx)<=(a*a*yy))
		{	
			if(pk<0)
			{
				//cout<<"here\n";
				xx=xx+1;//0.001;					
				pk=pk+2*b*b*(xx)+b*b;								
			}
			else
			{	
				//cout<<"there\n";		
				xx=xx+1;
				yy=yy-1;
				pk=pk+2*b*b*(xx)+b*b-2*a*a*(yy);
			}				
			glVertex2f(x+xx,y+yy);
			glVertex2f(x-xx,y+yy);	
			glVertex2f(x+xx,y-yy);	
			glVertex2f(x-xx,y-yy);	
		}
		//cout<<xx<<" "<<yy<<"\n";
		pk=b*b*(xx+1)*(xx+1)+a*a*(yy-0.5)*(yy-0.5)-a*a*b*b;
		while(yy>0)
		{
			if(pk<=0)
			{
				xx=xx+1;
				yy=yy-1;
				pk=pk+2*b*b*(xx)+a*a-2*a*a*(yy);										
			}
			else
			{					
				yy=yy-1;
				pk=pk-2*a*a*(yy)+a*a;											
			}			
			glVertex2f(x+xx,y+yy);
			glVertex2f(x-xx,y+yy);	
			glVertex2f(x+xx,y-yy);	
			glVertex2f(x-xx,y-yy);	
		}
	glEnd();
	glFlush();
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    p=0,q=0;
    glFlush ();
}
void disp1(void)
{
	glClearColor(0.933, 0.510, 0.933, 0.0);
	glClear (GL_COLOR_BUFFER_BIT);
	polar_ellipse(p,q);
    RenderString(-750.0f, -800.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Polar Ellipse");
	glFlush ();
}
void disp2(void)
{
	glClearColor(0.941, 0.902, 0.549, 0.0);
	glClear (GL_COLOR_BUFFER_BIT);	
	polar_circle(p,q,400);
    RenderString(-750.0f, -800.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Polar Circle");
	glFlush ();
}
void disp3(void)
{
	glClearColor(0.604, 0.804, 0.196, 0.0);
	glClear (GL_COLOR_BUFFER_BIT);
	midpoint_ellipse(p,q);
    RenderString(-750.0f, -800.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Midpoint Ellipse");
	glFlush ();
}
void disp4(void)
{
	glClearColor(1.000, 0.894, 0.882, 0.0);
	glClear (GL_COLOR_BUFFER_BIT);
	midpoint_circle(p,q,400);
    RenderString(-750.0f, -800.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Midpoint Cirlce");
	glFlush ();
}

void init (void) 
{
    glClearColor(0.933, 0.510, 0.933, 0.0);
}

void myMouse(int button, int state, int x, int y)
{	
	float mx=float(x)/(700.0f)*(2000)-1000;
	float my=float(y)/(700.0f)*2000-1000;
	my=-my;
	//cin>>a>>b;
}

void keypr(unsigned char ch, int x, int y)
{
	if(ch==32)
	{
		glutPostRedisplay();
	}
}

int main(int argc, char** argv)
{
	int win,w1,w2,w3,w4;
	glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (700, 700); 
    glutInitWindowPosition (300, 300);
    win=glutCreateWindow ("R134214067");
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1000, 1000,-1000, 1000);
	glutDisplayFunc(display); 
	init ();
    w1=glutCreateSubWindow(win, 0 , 0, 350, 350);
    gluOrtho2D(-1000, 1000,-1000, 1000);
    glutDisplayFunc(disp1);
    w2=glutCreateSubWindow(win, 0, 350, 350, 350);
    gluOrtho2D(-1000, 1000,-1000, 1000);
    glutDisplayFunc(disp2);
    w3=glutCreateSubWindow(win, 350, 0, 350, 350);
    gluOrtho2D(-1000, 1000,-1000, 1000);
    glutDisplayFunc(disp3);
    w4=glutCreateSubWindow(win, 350, 350, 350, 350);
    gluOrtho2D(-1000, 1000,-1000, 1000);
    glutDisplayFunc(disp4);
    glutMouseFunc(myMouse);
    glutKeyboardFunc(keypr);
    glutMainLoop();
	return 0;
}