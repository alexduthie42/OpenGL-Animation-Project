//  ========================================================================
//  Alexander Duthie.
//
//  FILE NAME: skybox.h
//  Creates the skybox of the scene.
//  ========================================================================

#include <iostream>
#include <math.h>
#include <GL/freeglut.h>
#include "loadTGA.h"

#define GL_CLAMP_TO_EDGE 0x812F 

GLuint texId[6];

//Load the skybox textures.
void loadGLTextures()			
{
	glGenTextures(6, texId); 	
	//left
	glBindTexture(GL_TEXTURE_2D, texId[0]);
	loadTGA("textures/sqpantslf.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);	

	//front
	glBindTexture(GL_TEXTURE_2D, texId[1]);
	loadTGA("textures/sqpantsft.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);	

	//right
	glBindTexture(GL_TEXTURE_2D, texId[2]);
	loadTGA("textures/sqpantsrt.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);	

	//back
	glBindTexture(GL_TEXTURE_2D, texId[3]);
	loadTGA("textures/sqpantsbk.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);	

	//top
	glBindTexture(GL_TEXTURE_2D, texId[4]);
	loadTGA("textures/sqpantsup.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);	

	//down
	glBindTexture(GL_TEXTURE_2D, texId[5]);
	loadTGA("textures/sand.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
}

//Create and texture the whole skybox.
void skybox()
{
    glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
    //Left
    glBindTexture(GL_TEXTURE_2D, texId[2]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.05);
    glVertex3f(-100,  0, 100);
    glTexCoord2f(1.0, 0.05);
    glVertex3f(-100, 0., -100);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-100, 100, -100);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-100, 100, 100);
    glEnd();

    //Front
    glBindTexture(GL_TEXTURE_2D, texId[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.05);
    glVertex3f(-100,  0, -100);
    glTexCoord2f(1.0, 0.05);
    glVertex3f(100, 0., -100);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(100, 100, -100);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-100,  100, -100);
    glEnd();

    //Right
    glBindTexture(GL_TEXTURE_2D, texId[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.05);
    glVertex3f(100,  0, -100);
    glTexCoord2f(1.0, 0.05);
    glVertex3f(100, 0, 100);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(100, 100,  100);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(100,  100,  -100);
    glEnd();


    //Back
    glBindTexture(GL_TEXTURE_2D, texId[3]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.05);
    glVertex3f( 100, 0, 100);
    glTexCoord2f(1.0, 0.05);
    glVertex3f(-100, 0,  100);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-100, 100,  100);
    glTexCoord2f(0.0, 1.0);
    glVertex3f( 100, 100, 100);
    glEnd();

    //Top
    glBindTexture(GL_TEXTURE_2D, texId[4]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.05);
    glVertex3f(-100, 100, -100);
    glTexCoord2f(1.0, 0.05);
    glVertex3f(100, 100,  -100);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(100, 100,  100);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-100, 100, 100);
    glEnd();

    //Floor
    glBindTexture(GL_TEXTURE_2D, texId[5]);

    glBegin(GL_QUADS);
    
    for(int i = -100; i < 100; i += 2)
    {
        for(int j = -100; j < 100; j += 2)
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
