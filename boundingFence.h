//  ========================================================================
//  Alexander Duthie.
//
//  FILE NAME: boundingFence.h
//  Creates the bounding fence.
//  ========================================================================

#include <iostream>
#include <math.h>
#include <GL/freeglut.h>

//Create one segment of the fence.
void segment()
{
    glPushMatrix();
        glTranslatef(0.425, 0.9575, 0.0);
        glRotatef(90, 0.0, 0.0, 1.0);
        glScalef(0.15, 1.0, 0.15);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.425, 0.45, 0.0);
        glRotatef(90, 0.0, 0.0, 1.0);
        glScalef(0.15, 1.0, 0.15);
        glutSolidCube(1.0);
    glPopMatrix();


    glPushMatrix();
        glTranslatef(0.0, 0.5, 0.0);
        glScalef(0.15, 1.0, 0.15);
        glutSolidCube(1.0);
    glPopMatrix();
}

//Create the whole fence model around the scene.
void fence()
{
    for(int i = 0; i < 70; i += 1) 
    {
        glPushMatrix();
            glTranslatef(-35 + i, 0.0, -35);
            segment();
        glPopMatrix();
    }

    for(int i = 0; i < 70; i += 1) 
    {
        glPushMatrix();
            glTranslatef(35, 0.0, -35 + i);
            glRotatef(-90, 0.0, 1.0, 0.0);
            segment();
        glPopMatrix();
    }

    for(int i = 0; i < 70; i += 1) 
    {
        glPushMatrix();
            glTranslatef(35 - i, 0.0, 35);
            glRotatef(-180, 0.0, 1.0, 0.0);
            segment();
        glPopMatrix();
    }

    for(int i = 0; i < 70; i += 1) 
    {
        glPushMatrix();
            glTranslatef(-35, 0.0, 35 - i);
            glRotatef(-270, 0.0, 1.0, 0.0);
            segment();
        glPopMatrix();
    }

}
