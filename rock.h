//  ========================================================================
//  Alexander Duthie.
//
//  FILE NAME: rock.h
//  Creates the rock model.
//  ========================================================================

#include <iostream>
#include <math.h>
#include <GL/freeglut.h>
#include "loadTGA.h"

GLuint txIdRock;

//Load the rock texture.
void loadGLRockTextures()			
{
	glGenTextures(1, &txIdRock); 			
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txIdRock);	
    loadTGA("textures/rock.tga");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}

//Create the rock model.
void rock()
{
    double plane[4] = {0.0, 1.0, 0.0, 0.0}; 

    glEnable(GL_CLIP_PLANE0);
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txIdRock);

	gluQuadricTexture (q, GL_TRUE);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPushMatrix();
        glColor3f(0.65, 0.4, 0.4);
        glClipPlane(GL_CLIP_PLANE0, plane);
        gluSphere (q, 7, 50, 50);
    glPopMatrix();


	glDisable(GL_TEXTURE_2D);
    glDisable(GL_CLIP_PLANE0);
}
