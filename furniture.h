//  ========================================================================
//  Alexander Duthie.
//
//  FILE NAME: furniture.h
//  Creates the model of the table and chair.
//  ========================================================================

#include <iostream>
#include <math.h>
#include <GL/freeglut.h>

void seat()
{
    //Bottom
    glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);
        glRotatef(90, 1.0, 0.0, 0.0);
        glutSolidTorus(0.2, 0.35, 20, 20);
    glPopMatrix();

    //Arm rests
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(-0.45, 0.275, 0.0);
        glScalef(0.2, 0.2, 1.0);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(0.45, 0.275, 0.0);
        glScalef(0.2, 0.2, 1.0);
        glutSolidCube(1.0);
    glPopMatrix();

    //Back
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(0.0, 0.925, -0.4);
        glScalef(1.1, 1.5, 0.2);
        glutSolidCube(1.0);
    glPopMatrix();
}

void table()
{
    //Tabletop
    glPushMatrix();
        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(0.0, 0.4, 0.0);
        glScalef(0.75, 0.1, 0.75);
        glutSolidCube(1.0);
    glPopMatrix();
    
    //Legs
    glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(0.3, 0.0, 0.3);
        glScalef(0.075, 0.75, 0.075);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(-0.3, 0.0, 0.3);
        glScalef(0.075, 0.75, 0.075);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(0.3, 0.0, -0.3);
        glScalef(0.075, 0.75, 0.075);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(-0.3, 0.0, -0.3);
        glScalef(0.075, 0.75, 0.075);
        glutSolidCube(1.0);
    glPopMatrix();

    //Teapot
    glPushMatrix();
        glColor3f(1.0, 0.4, 0.7);
        glTranslatef(0.0, 0.55, 0.0);
        glutSolidTeapot(0.1);
    glPopMatrix();

}
