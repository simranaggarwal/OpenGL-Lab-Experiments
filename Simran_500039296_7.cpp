#include<GL/glut.h>
#include<string.h>
#include<cmath>
#include<stdio.h>
#include<iostream>
#define PI 3.14159265

using namespace std;
float OriginalTriangle [3][3]={{0,50,0},{50,50,25},{1,1,1}};
float ModifiedTriangle [3][3]={};
static float tx=0, ty=0, theta=0, sx=0, sy=0;
void display()
{
  const char *str2="Simran Aggarwal";
  int j = strlen( str2 );
  glColor3f( 0.9, 0.5, 1.0 );
  glRasterPos2f(-280, 280 );
  for( int i = 0; i < j; i++ )
  {
    glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, str2[i] );
  }
  glFlush();
}

void drawTriangle(float Tri[3][3])
{
  glClear(GL_COLOR_BUFFER_BIT);//Clearing Screen
  glClearColor(0.0f, 0.0f, 0.0f, 0.8f);
  glBegin(GL_POLYGON);
  glColor3f(0.722, 0.525, 0.043);
  glVertex2f(Tri[0][0],Tri[1][0]);//Matrix position
  glVertex2f(Tri[0][1],Tri[1][1]);
  glVertex2f(Tri[0][2],Tri[1][2]);
  glEnd();
  glFinish();

  const char *str2="Simran Aggarwal";
  int j = strlen( str2 );
  glColor3f( 0.9, 0.5, 1.0 );
  glRasterPos2f(-280, 280 );
  for( int i = 0; i < j; i++ )
  {
    glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, str2[i] );
  }
  glFlush();
}


void orignal()
{
  sx=0;sy=0;tx=0;ty=0;
  drawTriangle(OriginalTriangle);
  
}

void modify(float a[3][3], float b[3][3], float c[3][3])
{
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      c[i][j]=0;
    }
  }
  for (int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      float sum=0;
      for (int k=0;k<3;k++)
      {
        sum=sum+(b[i][k]*a[k][j]);
      }
      c[i][j]=sum;
    }
  }  
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      OriginalTriangle[i][j]=c[i][j];
    }
  }
  drawTriangle(OriginalTriangle);
}

void showOption()
{
    cout<<"Choose the transformation:";
    cout<<"\t\n.Translation: a,w,s,d";
    cout<<"\t\n.Rotation: SPACEBAR";
    cout<<"\t\n.Scaling: z";
    cout<<"\t\n.Reflection: x, y";
    cout<<"\t\n.Orignal: o";
}

void myKey(unsigned char key, int x, int y)
{
 
  if (key==97)
  {
    float b[3][3]={{1,0,-1},{0,1,0},{0,0,1}};
    modify(OriginalTriangle, b, ModifiedTriangle);
  }
  else
  if (key==119)//move up with 'w'
  {
    float b[3][3]={{1,0,0},{0,1,1},{0,0,1}};
    modify(OriginalTriangle, b, ModifiedTriangle);
  }
  else
  if (key==100)//move right with 'd'
  {
    float b[3][3]={{1,0,1},{0,1,0},{0,0,1}};
    modify(OriginalTriangle, b, ModifiedTriangle);
  }
  else
  if (key==115)//move down with 's'
  {
    float b[3][3]={{1,0,0},{0,1,-1},{0,0,1}};
    modify(OriginalTriangle, b, ModifiedTriangle);
  }
  else
  if(key==111)//show orignal with 'o'
  orignal();
  if(key==122) //zoom z
  {
    float b[3][3]={{2,0,0},{0,2,0},{0,0,1}};
    modify(OriginalTriangle, b, ModifiedTriangle);
  }  
  else 
  if(key==113)
  {
    float b[3][3]={{0.5,0,0},{0,0.5,0},{0,0,1}};
    modify(OriginalTriangle, b, ModifiedTriangle);
  }
  else 
  if(key==32)//rotate 90 degrees with 'space'
  {
    float b[3][3]={{cos(3.14/2), sin(3.14/2), 0},{-sin(3.14/2), cos(3.14/2),0},{0,0,1}};
    modify(OriginalTriangle, b, ModifiedTriangle);
  }
  else if(key==120)
  {
    float b[3][3]={{1,0,0},{0,-1,0},{0,0,1}};
    modify(OriginalTriangle, b, ModifiedTriangle);
  }
  else if(key==121)
  {
    float b[3][3]={{-1,0,0},{0,1,0},{0,0,1}};
    modify(OriginalTriangle, b, ModifiedTriangle);
  }
}


int main(int argc, char** argv)
{
  showOption();
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Transformation");
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-300,300,300,-300);
  glutDisplayFunc(display);
  glutKeyboardFunc(myKey);
  glutMainLoop();
}