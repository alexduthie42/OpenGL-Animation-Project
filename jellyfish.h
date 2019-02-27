//  ========================================================================
//  Alexander Duthie.
//
//  FILE NAME: jellyfish.h
//  Creates the jellyfish model.
//  ========================================================================

#include <iostream>
#include <math.h>
#include <GL/freeglut.h>
#include "loadTGA.h"

float jellyHeight = 0.3;
float jellyTheta = 15.0;
bool out = false;

GLuint txIdJelly;

//Load the jellyfish texture.
void loadGLJellyTextures()			
{
	glGenTextures(1, &txIdJelly); 			
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txIdJelly);		
    loadTGA("textures/jelly.tga");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	
}

//Timer for the jellyfish animation.
void jellyfishTimer(int value)
{
	if (jellyTheta < 15 and out == true)
	{
		jellyTheta += 0.5;
        jellyHeight -= 0.02;
	}
	else if (jellyTheta > -15 and out == false)
	{
		jellyTheta -= 0.5;
        jellyHeight += 0.02;
	}
	else if (jellyTheta == -15)
	{
		out = true;
		jellyTheta += 0.5;
        jellyHeight -= 0.02;
	}
	else if (jellyTheta == 15)
	{
		out = false;
		jellyTheta -= 0.5;
        jellyHeight += 0.02;
	}
    glutPostRedisplay();
    glutTimerFunc(35, jellyfishTimer, 0);
}

void tenticle()
{
    glPushMatrix();
        glScalef(0.04, 0.35, 0.04);
        glutSolidCube(1.0);
    glPopMatrix();
}

//Create the jellyfish model.
void jellyfishModel()
{
    //Body
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txIdJelly);

	gluQuadricTexture (q, GL_TRUE);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    glPushMatrix();
        glTranslatef(0.0, 1.0, 0.0);
        glScalef(0.175, 0.2, 0.175);
        gluSphere (q, 1, 20, 20);
    glPopMatrix();

	glDisable(GL_TEXTURE_2D);

    glPushMatrix();
        glColor3f(0.3, 1.0, 1.0);
        glTranslatef(0.0, 0.865, 0.0);
        glRotatef(90, 1.0, 0.0, 0.0);
        glScalef(0.26, 0.26, 0.35);
        glutSolidTorus(0.1, 0.5, 20, 20);
    glPopMatrix();

    //Tenticles
    glPushMatrix();
        glTranslatef(0.0, 0.7, -0.12);
        glTranslatef(0.0, 0.175, 0.0);
        glRotatef(jellyTheta, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.175, 0.0);
        tenticle();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0, 0.7, 0.12);
        glTranslatef(0.0, 0.175, 0.0);
        glRotatef(-jellyTheta, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.175, 0.0);
        tenticle();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.12, 0.7, 0.0);
        glTranslatef(0.0, 0.175, 0.0);
        glRotatef(jellyTheta, 0.0, 0.0, 1.0);
        glTranslatef(0.0, -0.175, 0.0);
        tenticle();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.12, 0.7, 0.0);
        glTranslatef(0.0, 0.175, 0.0);
        glRotatef(-jellyTheta, 0.0, 0.0, 1.0);
        glTranslatef(0.0, -0.175, 0.0);
        tenticle();
    glPopMatrix();
}

//Transform the jellyfish model.
void jellyfish()
{
    glPushMatrix();
        glTranslatef(0.0, jellyHeight, 0.0);
        jellyfishModel();
    glPopMatrix();
}


