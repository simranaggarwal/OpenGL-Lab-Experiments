#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;

vector<pair<float,float> >coord;
bool flagb=false,flagd=false;
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
    RenderString(-0.75f, 0.8f, GLUT_BITMAP_TIMES_ROMAN_24, "Simran, R134214067");
    RenderString(-0.75f, -0.8f, GLUT_BITMAP_TIMES_ROMAN_24, "DDA and Bresenham's Algorithm");
    glFlush ();
}

void init (void) 
{
    glClearColor(0.15, 0.15, 0.15, 0.0);
}

void dda()
{
	float x=coord[0].first,y=coord[0].second;
	float dx=coord[1].first-x,dy=coord[1].second-y;
	int length=(abs(dx)>abs(dy))?(abs(dx))*500:(abs(dy))*500;
	float xInc,yInc;
	xInc=dx/length;
	yInc=dy/length;

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	for(int i=0;i<length;i++)
	{
		x=x+xInc;
		y=y+yInc;
		glVertex2f(x,y);
	}
	glEnd();
	glFlush();
}

void bresenham()
{	
	float x1,x2,y1,y2,x,y,p,dx,dy;
	x1=coord[0].first;
	y1=coord[0].second;
	x2=coord[1].first;
	y2=coord[1].second;
	dx=max(x1,x2)-min(x1,x2);
	dy=(dx==x2-x1)?(y2-y1):(y1-y2);
	x=min(x1,x2);
	y=(x==x1)?y1:y2;
	if(dx==0)
	{
		glColor3f(0.0,1.0,0.0);
		glBegin(GL_POINTS);
		for(float yy=min(y1,y2);yy<=max(y1,y2);yy=yy+0.001)
		{
			glVertex2f(x,yy);
			cout<<yy<<" ";
		}
		glEnd();
		glFlush();
	}
	else
	if(dy==0)
	{
		glColor3f(0.0,1.0,0.0);
		glBegin(GL_POINTS);
		for(float xx=min(x1,x2);xx<=max(x1,x2);xx=xx+0.001)
		{
			glVertex2f(xx,y);
		}
		glEnd();
		glFlush();
	}
	else
	{
		glColor3f(0.0,1.0,0.0);
		glBegin(GL_POINTS);
		if(dy>0)
		{
			if(dx>dy)
			{
				p=2*dy-dx;
				while(x<=max(x1,x2) && y<=max(y1,y2))
				{
					if(p<0)
					{
						glVertex2f(x,y);
						x=x+0.001;
						p=p+2*dy;
					}
					else
					{
						glVertex2f(x,y);
						x=x+0.001;
						y=y+0.001;
						p=p+2*dy-2*dx;
					}
				}
			}
			else
			{
				p=2*dx-dy;
				while(x<=max(x1,x2) && y<=max(y1,y2))
				{
					if(p<0)
					{
						glVertex2f(x,y);
						y=y+0.001;
						p=p+2*dx;
					}
					else
					{
						glVertex2f(x,y);
						x=x+0.001;
						y=y+0.001;
						p=p+2*dx-2*dy;
					}
				}
			}
		}
		else
		if(dy<0)
		{
			if(dx>abs(dy))
			{
				p=-2*dy-dx;
				while(x<=max(x1,x2) && y<=max(y1,y2))
				{
					if(p<0)
					{
						glVertex2f(x,y);
						//mx++;
						x=x+0.001;
						p=p-2*dy;
					}
					else
					{
						glVertex2f(x,y);
						x=x+0.001;
						y=y-0.001;
						p=p-2*dy-2*dx;
					}
				}
			}
			else
			{
				p=2*dx+dy;
				while(x<=max(x1,x2) && y<=max(y1,y2))
				{
					if(p<0)
					{
						glVertex2f(x,y);
						y=y-0.001;
						p=p+2*dx;
					}
					else
					{
						glVertex2f(x,y);
						x=x+0.001;
						y=y-0.001;
						p=p+2*dx+2*dy;
					}
				}
			}
		}
		glEnd();
		glFlush();
	}
	
}

void myMouse(int button, int state, int x, int y)
{	
	float mx=float(x)/(700.0f)*(2)-1;
	float my=float(y)/(700.0f)*2-1;
	my=-my;
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		coord.push_back(make_pair(mx,my));
		if(coord.size()==2)
		{	
			if(flagd==true)
			{
				dda();
				flagd=false;
			}
			if(flagb==true)
			{
				bresenham();
				flagb=false;
			}
			coord.clear();
		}
	}
}

void keypr(unsigned char ch, int x, int y)
{
	if(ch==32)
	{
		glutPostRedisplay();
	}
	if(ch==66)
	{
		flagb=true;
	}
	else
	if(ch==68)
	{
		flagd=true;
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (700, 700); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("R134214067");
    init ();
    glutDisplayFunc(display); 
    glutMouseFunc(myMouse);
    glutKeyboardFunc(keypr);
    glutMainLoop();
	return 0;
}