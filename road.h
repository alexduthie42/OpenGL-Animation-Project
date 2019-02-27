//  ========================================================================
//  Alexander Duthie.
//
//  FILE NAME: road.h
//  Creates the roads on the floor plane.
//  ========================================================================

#include <iostream>
#include <math.h>
#include <GL/freeglut.h>
#include "loadTGA.h"

GLuint txIdRoad;

//Load the jellyfish texture.
void loadGLRoadTextures()			
{
	glGenTextures(1, &txIdRoad); 			
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txIdRoad);		
    loadTGA("textures/road.tga");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	
}

void road()
{
    glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, txIdRoad);

    //Main Road.
    glBegin(GL_QUADS);
    
    for(int i = -100; i < 100; i += 2)
    {
        for(int j = -2; j < 2; j += 2)
        {
            glTexCoord2f(0.0, 0.0);
            glVertex3f(i, 0, j);
            glTexCoord2f(0.0, 1.0);
            glVertex3f(i, 0, j + 2);
            glTexCoord2f(1.0, 1.0);
            glVertex3f(i + 2, 0, j + 2);
            glTexCoord2f(1.0, 0.0);
            glVertex3f(i + 2, 0, j);
        }
    }
    glEnd();

    //SpongeBob's path.
    glBegin(GL_QUADS);
    
    for(int i = -1; i < 1; i += 2)
    {
        for(int j = -18; j < -2; j += 1)
        {
            glTexCoord2f(0.0, 0.0);
            glVertex3f(i, 0, j);
            glTexCoord2f(0.0, 1.0);
            glVertex3f(i, 0, j + 2);
            glTexCoord2f(1.0, 1.0);
            glVertex3f(i + 2, 0, j + 2);
            glTexCoord2f(1.0, 0.0);
            glVertex3f(i + 2, 0, j);
        }
    }
    glEnd();

    //Patrick's path.
    glBegin(GL_QUADS);
    
    for(int i = -26; i < -25; i += 2)
    {
        for(int j = -18; j < -2; j += 2)
        {
            glTexCoord2f(0.0, 0.0);
            glVertex3f(i, 0, j);
            glTexCoord2f(0.0, 1.0);
            glVertex3f(i, 0, j + 2);
            glTexCoord2f(1.0, 1.0);
            glVertex3f(i + 2, 0, j + 2);
            glTexCoord2f(1.0, 0.0);
            glVertex3f(i + 2, 0, j);
        }
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);

}
