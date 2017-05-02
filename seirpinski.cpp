//seirpinski
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>
#define GLfloat float

using namespace std;
GLfloat v[4][3]={{0.0,0.0,1.0},{0.0,1.0,0.0},
                     {-1.0,-0.5,0.0}, {1.0,-0.5,0.0}};
GLfloat colors[4][3]={{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{0.0,0.0,0.0}};
int n;
int count=15, cnt=15;
GLfloat xRot, yRot, zRot, scale;

void animate(int value);
void animation(int value);
void Scale()
{
	glScalef(scale, scale, scale);
	glRotatef(xRot, 1.0, 0.0, 0.0);
	glRotatef(yRot, 0.0, 1.0, 0.0);
	glRotatef(zRot, 0.0, 0.0, 1.0);
}

void triangle(GLfloat *va,GLfloat *vb,GLfloat *vc)
{
        glVertex3fv(va);
        glVertex3fv(vb);
        glVertex3fv(vc);
}

void tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d)
{
    glColor3fv(colors[0]);
    triangle( a, b, c);
    glColor3fv(colors[1]);
    triangle( a, c, d);
    glColor3fv(colors[2]);
    triangle( a, d, b);
    glColor3fv(colors[3]);
    triangle( b, d, c);
}

void divide_tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d,int m)
{
    GLfloat mid[6][3];
    int j;
    if(m>0)
    {   
        for(j=0;j<3;j++) mid[0][j]=(a[j]+b[j])/2;
        for(j=0;j<3;j++) mid[1][j]=(a[j]+c[j])/2;
        for(j=0;j<3;j++) mid[2][j]=(a[j]+d[j])/2;
        for(j=0;j<3;j++) mid[3][j]=(b[j]+c[j])/2;
        for(j=0;j<3;j++) mid[4][j]=(c[j]+d[j])/2;
        for(j=0;j<3;j++) mid[5][j]=(b[j]+d[j])/2;
        divide_tetra(a,mid[0],mid[1],mid[2],m-1);
        divide_tetra(mid[0],b,mid[3],mid[5],m-1);
        divide_tetra(mid[1],mid[3],c,mid[4],m-1);
        divide_tetra(mid[2],mid[5],mid[4],d,m-1);
    }
    else
        tetra( a, b, c, d);      
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);     
    divide_tetra(v[0],v[1],v[2],v[3],n); 
    glEnd(); 
    glFlush();                          
}

void myKey(unsigned char key, int x, int y)
{
	if(key==65)
	{		
		scale+=1.05;
		Scale();
		glutPostRedisplay();
		
	}
	if(key==83)
	{
		scale=0.5;
		Scale();
		glutPostRedisplay();
	}
}

void myReshape(int w,int h)
{
    glViewport(0,0,w,h);                
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();                       
    glOrtho(-2.0,2.0,-2.0,2.0 ,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();    
}

void init()
{
	glClear(GL_COLOR_BUFFER_BIT);
	xRot=yRot=zRot=0.0;
	scale=1.0;
}
void animation(int value)
{
	if(count <=15 && count>0)
    {
    	scale+=0.005;
    	yRot+=0.1;
    	cout<<scale<<" ";
		Scale();
		glutPostRedisplay();
		glutTimerFunc(250, animation, 0);
		count--;
    }
    else
    if(count==0)
    {
    	cnt=15;
    	glutTimerFunc(250, animate, 0);
    }
}

void animate(int value)
{
	if(cnt<=15 && cnt >0) 
	{
		scale-=0.01;
		yRot-=0.1;
		cout<<scale<<" ";
		Scale();
		glutPostRedisplay();
		glutTimerFunc(250, animate, 0);
		cnt--;
	}
	else
	if(cnt==0)
	{
		count=15;
		glutTimerFunc(250, animation, 0);
	}

}
int main(int argc,char **argv)
{
printf("enter the no of division ");
scanf("%d",&n);
glutInit(&argc,argv);                                 
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(500,500);       
glutCreateWindow("3d gasket");  
init(); 
glutReshapeFunc(myReshape);
glutDisplayFunc(display);       
glEnable(GL_DEPTH_TEST);
glutKeyboardFunc(myKey);
glutTimerFunc(250, animation, 0);


                        // Enable hidden surface removal or visible surface determination
                            // this test is usually enabled in conjunction with use of
                            // GLUT_DEPTH in glutInitDisplayMode and hence only in 3D
                                         // programs
glClearColor(1.0,1.0,1.0,1.0);        // Set the background color to white
glutMainLoop();     // most important line of every program. This calls the event
return 0;
}