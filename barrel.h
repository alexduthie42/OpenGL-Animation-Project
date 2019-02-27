//  ========================================================================
//  Alexander Duthie.
//
//  FILE NAME: barrel.h
//  Creates the barrel model.
//  ========================================================================

#include <iostream>
#include <math.h>
#include <GL/freeglut.h>

const int N = 22;

float vx[N] = {0, 2.6,2.8,3,3.6,4,4.2,4.4,4.2,4,3.6,3,2.8,2.6,3,3.4,3.6,3.8,3.6,3.4,3,2.6};
float vy[N] = {0.2,0.2,0,0,1,2,3,5,7,8,9,10,10,9.8,9,8,7,5,3,2,1,0.2};
float vz[N] = {0};

float barrelTheta = 0.0;

//Timer for the barrel animation.
void barrelTimer(int value)
{
    barrelTheta++;
	
    glutPostRedisplay();
    glutTimerFunc(35, barrelTimer, 0);
}

//Calculates the normal of a quad from three of its points.
void normal(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3 )
{
	  float nx, ny, nz;
	  nx = y1*(z2-z3)+ y2*(z3-z1)+ y3*(z1-z2);
	  ny = z1*(x2-x3)+ z2*(x3-x1)+ z3*(x1-x2);
	  nz = x1*(y2-y3)+ x2*(y3-y1)+ x3*(y1-y2);

      glNormal3f(nx, ny, nz);
}

//Creates the barrel model using a surface of revolution.
void barrelModel()
{
    float wx[N], wy[N], wz[N]; 
	float angStep = 10.0*3.1415926/180.0;

    glColor4f (1.0, 0.75, 0.5, 1.0); 

    for (int j = 0; j < 36; j++)
    {

        for (int i = 0; i < N; i++)
        {
            wx[i] = vx[i] * cos(angStep) + vz[i] * sin(angStep);
            wy[i] = vy[i];
            wz[i] = -vx[i] * sin(angStep) + vz[i] * cos(angStep);
        }



        glBegin(GL_TRIANGLE_STRIP);
        for (int i = 0; i < N; i++)
        {
            if (i > 0) 
            {
                normal(wx[i], wy[i], wz[i], vx[i], vy[i], vz[i], vx[i-1], vy[i-1], vz[i-1]);
            }
            glVertex3f(vx[i], vy[i], vz[i]);
            if (i > 0) 
            {
                normal(wx[i], wy[i], wz[i], vx[i - 1], vy[i - 1], vz[i - 1], wx[i - 1], wy[i - 1], wz[i - 1]);
            }
            glVertex3f(wx[i], wy[i], wz[i]);
        }

        glVertex3f(vx[0], vy[N-1], vz[0]);
        glVertex3f(wx[0], wy[N-1], wz[0]);

        glEnd();

        for (int i = 0; i < N; i++)
        {
            vx[i] = wx[i];
            vy[i] = wy[i];
            vz[i] = wz[i];
        }
    }

}

//Transform the barrel model
void barrel()
{
    glPushMatrix();
        glRotatef(barrelTheta, 0.0, 1.0, 0.0);
        barrelModel();
    glPopMatrix();
}
