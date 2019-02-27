//  ========================================================================
//  Alexander Duthie.
//
//  FILE NAME: gary.h
//  Creates the gary model.
//  ========================================================================

#include <iostream>
#include <math.h>
#include <GL/freeglut.h>

float garyTheta = 0.0;

//Timer for gary's animation.
void garyTimer(int value)
{
    garyTheta++;
	
    glutPostRedisplay();
    glutTimerFunc(35, garyTimer, 0);
}

//Create a model of gary's eye.
void eye()
{
    glPushMatrix();
        glColor3f(0.3, 1.0, 1.0);  
        glScalef(0.05, 0.65, 0.05);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.9, 1.0, 0.9); 
        glTranslatef(0.0, 0.3, 0.0);
        gluSphere (q, 0.085, 20, 20);
    glPopMatrix();
}

//Creates the gary model.
void garyModel()
{
    

    //Body
    glPushMatrix();
        glColor3f(0.3, 1.0, 1.0); 
        glTranslatef(0.0, 0.075, 0.0);
        glScalef(0.75, 0.15, 0.175);
        gluSphere (q, 1, 20, 20);
    glPopMatrix();

    //Eyes
    glPushMatrix();
        glTranslatef(0.6, 0.4, 0.125);
        glRotatef(10, 1.0, 0.0, 0.0);
        eye();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.6, 0.4, -0.125);
        glRotatef(-10, 1.0, 0.0, 0.0);
        eye();
    glPopMatrix();



    //Shell
    glPushMatrix();
        glColor3f(1.0, 0.7, 0.8);
        glTranslatef(-0.25, 0.4, 0.0);
        glRotatef(90, 0.0, 0.0, 1.0);
        glScalef(0.4, 0.6, 0.4);
        glutSolidTorus(0.5, 0.5, 20, 20);
    glPopMatrix();
}

//Transforms the gary model.
void gary()
{
    glPushMatrix();
        glRotatef(-garyTheta, 0.0, 1.0, 0.0);
        glTranslatef(0.0, 0.0, -2.0);
        garyModel();
    glPopMatrix();
}
