//  ========================================================================
//  Alexander Duthie.
//
//  FILE NAME: fan.h
//  Creates the fan model.
//  ========================================================================

#include <iostream>
#include <math.h>
#include <GL/freeglut.h>

float fanTheta = 0.0;

//Timer for the fan animation.
void fanTimer(int value)
{
	if (fanTheta < 360)
	{
		fanTheta += 6;
	}
	else if (fanTheta == 360)
	{
        fanTheta = 0.0;
    }
    glutPostRedisplay();
    glutTimerFunc(35, fanTimer, 0);
}

//Creates the fans mount model.
void mount()
{
    glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);
        glScalef(0.1, 0.9, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(0.0, -0.45, 0.0);
        glScalef(0.1, 0.1, 0.1);
        gluSphere (q, 1, 20, 20);
    glPopMatrix();
}

//Creates a model of the fan arm.
void fanArm()
{
    glPushMatrix();
        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(0.0, -0.45, 0.0);
        glScalef(0.75, 0.04, 0.1);
        gluSphere (q, 1, 20, 20);
    glPopMatrix();
}

//Creates the whole fan model
void fanModel()
{
    mount();

    //Arm 1
    glPushMatrix();
        glTranslatef(0.65, 0.0, 0.0);
        fanArm();
    glPopMatrix();

    //Arm 2
    glPushMatrix();
        glTranslatef(-0.65, 0.0, 0.0);
        fanArm();
    glPopMatrix();

    //Arm 3
    glPushMatrix();
        glTranslatef(0.0, 0.0, 0.65);
        glRotatef(90, 0.0, 1.0, 0.0);
        fanArm();
    glPopMatrix();

    //Arm 4
    glPushMatrix();
        glTranslatef(0.0, 0.0, -0.65);
       glRotatef(90, 0.0, 1.0, 0.0);
        fanArm();
    glPopMatrix();
}

//Transforms the fan models and the spotlight.
void fan()
{
   float spot_pos[] = {1.0, -0.5, 0.0, 1.0}; 
   float spot_dir[] = {4, -2.25, 0.0};

    glPushMatrix();
        glColor3f(1.0, 0.2, 0.4);
        glTranslatef(0.0, 1.0, 0.0);
        glRotatef(fanTheta, 0.0, 1.0, 0.0);
        glLightfv(GL_LIGHT1, GL_POSITION, spot_pos); 
        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_dir);
        fanModel();
    glPopMatrix();
}
