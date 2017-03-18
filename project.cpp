#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;

static float Xvalue = 0.0, Yvalue = 0.0, Angle = 0.0;


int MoveMerc = 0;
int MoveVen = 0;
int MoveEar = 0;
int MoveMars = 0;
int MoveJup = 0;
int MoveSat = 0;
int MoveUra = 0;
int MoveNept = 0;

void myInit(void) {
 glClearColor (0.0, 0.0, 0.0, 0.0);
}

static float Merc[360][2];
static float Ven[360][2];
static float Ear[360][2];
static float Mars[360][2];
static float Jup[360][2];
static float Sat[360][2];
static float Ura[360][2];
static float Nept[360][2];

void generateCircle()
{
    int i = 0;
    for(i=0; i <= 360; i++)
    {
        Merc[i][0] = sin(i*3.1416/180)*1;
        Merc[i][1] = cos(i*3.1416/180)*1;
    }

    for(i=0; i <= 360; i++)
    {
        Ven[i][0] = sin(i*3.1416/180)*1.5;
        Ven[i][1] = cos(i*3.1416/180)*1.5;
    }
 
    for(i=0; i <= 360; i++)
    {
        Ear[i][0] = sin(i*3.1416/180)*2.0;
        Ear[i][1] = cos(i*3.1416/180)*2.0;
    }
    for(i=0; i <= 360; i++)
    {
        Mars[i][0] = sin(i*3.1416/180)*2.5;
        Mars[i][1] = cos(i*3.1416/180)*2.5;
    }
    for(i=0; i <= 360; i++)
    {
        Jup[i][0] = sin(i*3.1416/180)*3.4;
        Jup[i][1] = cos(i*3.1416/180)*3.4;
    }
    for(i=0; i <= 360; i++)
    {
        Sat[i][0] = sin(i*3.1416/180)*4.3;
        Sat[i][1] = cos(i*3.1416/180)*4.3;
    }
    for(i=0; i <= 360; i++)
    {
        Ura[i][0] = sin(i*3.1416/180)*5.0;
        Ura[i][1] = cos(i*3.1416/180)*5.0;
    }
    for(i=0; i <= 360; i++)
    {
        Nept[i][0] = sin(i*3.1416/180)*5.8;
        Nept[i][1] = cos(i*3.1416/180)*5.8;
    }

}

void myDisplay(void) {
 
 glClear (GL_COLOR_BUFFER_BIT);
 glColor3f (1.0, 1.0, 1.0);
 
 //sun
 glPushMatrix();
 glColor3f(1.000, 1.000, 0.000); 
 gluLookAt (0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 glTranslatef(Xvalue, 0.0, Yvalue);
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glutWireSphere (0.7, 15, 15);
 glPopMatrix();
 
 //Mercury
 glPushMatrix();
 glColor3f (0.55, 0.55, 0.55);
 gluLookAt (0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 if(MoveMerc==360)
  MoveMerc = 0;
 glTranslatef(Merc[MoveMerc][1], Merc[MoveMerc][0], 0.0);
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glutWireSphere (0.2, 15, 15);
 glPopMatrix();

 //Venus
  glPushMatrix();
 glColor3f (0.604, 0.804, 0.196);
 gluLookAt (0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 if(MoveVen==360)
  MoveVen = 0;
 glTranslatef(Ven[MoveVen][1], Ven[MoveVen][0], 0.0);
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glutWireSphere (0.2, 15, 15);
 glPopMatrix();

//Earth
  glPushMatrix();
 glColor3f (0.275, 0.510, 0.706);
 gluLookAt (0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 if(MoveEar==360)
  MoveEar = 0;
 glTranslatef(Ear[MoveEar][1], Ear[MoveEar][0], 0.0);
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glutWireSphere (0.4, 15, 15);
 glPopMatrix();

//Mars
glPushMatrix();
 glColor3f (1.0, 0.0, 0.0);
 gluLookAt (0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 if(MoveMars==360)
  MoveMars = 0;
 glTranslatef(Mars[MoveMars][1], Mars[MoveMars][0], 0.0);
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glutWireSphere (0.3, 15, 15);
 glPopMatrix();

//Jupiter
 glPushMatrix();
 glColor3f (1.000, 0.647, 0.000);
 gluLookAt (0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 if(MoveJup==360)
  MoveJup = 0;
 glTranslatef(Jup[MoveJup][1], Jup[MoveJup][0], 0.0);
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glutWireSphere (0.6, 15, 15);
 glPopMatrix();

//Saturn
 glPushMatrix();
 glColor3f (1.000, 0.871, 0.678);
 gluLookAt (0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 if(MoveSat==360)
  MoveSat = 0;
 glTranslatef(Sat[MoveSat][1], Sat[MoveSat][0], 0.0);
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glutWireSphere (0.4, 15, 15);
 int i = 0;
 glBegin(GL_QUAD_STRIP);
 for(i=0; i <= 360; i++)
 {
  glVertex3f(sin(i*3.1416/180)*0.5, cos(i*3.1416/180)*0.5, 0 );
  glVertex3f(sin(i*3.1416/180)*0.7, cos(i*3.1416/180)*0.7, 0 );
 }
 glEnd();
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glPopMatrix();
 
//Uranus
 glPushMatrix();
 glColor3f (0.000, 0.000, 0.545);
 gluLookAt (0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 if(MoveUra==360)
  MoveUra = 0;
 glTranslatef(Ura[MoveUra][1], Ura[MoveUra][0], 0.0);
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glutWireSphere (0.4, 15, 15);
 glPopMatrix();

//Neptune
  glPushMatrix();
 glColor3f (0.255, 0.412, 0.882);
 gluLookAt (0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 if(MoveNept==360)
  MoveNept = 0;
 glTranslatef(Nept[MoveNept][1], Nept[MoveNept][0], 0.0);
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glutWireSphere (0.4, 15, 15);
 i = 0;
 glBegin(GL_QUAD_STRIP);
 for(i=0; i <= 360; i++)
 {
  glVertex3f(sin(i*3.1416/180)*0.5, cos(i*3.1416/180)*0.5, 0 );
  glVertex3f(sin(i*3.1416/180)*0.7, cos(i*3.1416/180)*0.7, 0 );
 }
 glEnd();
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glPopMatrix();

 glFlush ();
}

void resize(int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
}

void animation(int value)
{
    Angle += 15.0;
    glutPostRedisplay();
    MoveMerc +=1;
    MoveVen +=1*2;
    MoveEar +=1*3;
    MoveMars +=1;
    MoveJup +=1*2;
    MoveSat +=1;
    MoveUra +=1*3;
    MoveNept +=1*2;
    glutPostRedisplay();
    glutTimerFunc(100, animation, 0);
}


int main(int argc, char ** argv)
{    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Solar System");
    myInit();
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(resize);  
    generateCircle();
    glutTimerFunc(100, animation, 0);
    glutMainLoop();
}





















