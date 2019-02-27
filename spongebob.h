//  ========================================================================
//  Alexander Duthie.
//
//  FILE NAME: spongebob.h
//  Creates the spongebob character model.
//  ========================================================================


#include <iostream>
#include <math.h>
#include <GL/freeglut.h>
#include "loadTGA.h"

//Animation globals.
int spongeTheta = 0;
int spongeMoveTheta = 0;
float spongeTrans = 0.0;
bool forward = true;

//Texture global.
GLuint txIdSponge;

//Load the sponge texture.
void loadGLSpongeTextures()			
{
	glGenTextures(1, &txIdSponge); 			
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txIdSponge);		
    loadTGA("textures/sponge.tga");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}

//Timer for spongebob's arm and leg animations.
void spongebobTimer(int value)
{
	if (spongeTheta < 20 and forward == true)
	{
		spongeTheta += 2;
	}
	else if (spongeTheta > -20 and forward == false)
	{
		spongeTheta -= 2;
	}
	else if (spongeTheta <= -20)
	{
		forward = true;
		spongeTheta += 2;
	}
	else if (spongeTheta >= 20)
	{
		forward = false;
		spongeTheta -= 2;
	}
    glutPostRedisplay();
    glutTimerFunc(35, spongebobTimer, 0);
}

//Timer for spongebob's path movement animation.
void spongePathTimer(int value)
{
    if (spongeMoveTheta < 180)
    {
        spongeMoveTheta++;
    }
    else if (spongeMoveTheta == 180 and spongeTrans < 3.0)
    {
        spongeTrans += 0.03;
    }
    else if (spongeMoveTheta < 360)
    {
        spongeMoveTheta++;
    }
    else if (spongeMoveTheta == 360 and spongeTrans > 0.0)
    {
        spongeTrans -= 0.03;
    }
    else if (spongeMoveTheta == 360)
    {
        spongeMoveTheta = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(35, spongePathTimer, 0);
}

//Create spongebob's left leg model.
void leftLeg()
{
    //Upper Leg
    glPushMatrix(); 
        glTranslatef(0.0, 0.55, 0.0);
	    glScalef(0.1, 0.3, 0.1);	 
	    glutSolidCube(1.0);
    glPopMatrix();

    //Knee
    glPushMatrix();
        glTranslatef(0.0, 0.35, 0.0); 
        gluSphere (q, 0.075, 20, 20);
    glPopMatrix();

    //Lower Leg
    glPushMatrix(); 
        glTranslatef(0.0, 0.4, 0.0);
        glRotatef(-spongeTheta, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.2, 0.0);
	    glScalef(0.1, 0.4, 0.1);	 
	    glutSolidCube(1.0);
    glPopMatrix();

    //Foot
    glPushMatrix(); 
        glTranslatef(0.0, 0.4, 0.0);
        glRotatef(-spongeTheta, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.35, 0.125);
	    glScalef(0.1, 0.1, 0.2);	 
	    glutSolidCube(1.0);
    glPopMatrix();
}

//Create spongebob's right leg model.
void rightLeg()
{
    //Upper Leg
    glPushMatrix(); 
        glTranslatef(0.0, 0.55, 0.0);
	    glScalef(0.1, 0.3, 0.1);	 
	    glutSolidCube(1.0);
    glPopMatrix();

    //Knee
    glPushMatrix();
        glTranslatef(0.0, 0.35, 0.0); 
        gluSphere (q, 0.075, 20, 20);
    glPopMatrix();

    //Lower Leg
    glPushMatrix(); 
        glTranslatef(0.0, 0.4, 0.0);
        glRotatef(spongeTheta, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.2, 0.0);
	    glScalef(0.1, 0.4, 0.1);	 
	    glutSolidCube(1.0);
    glPopMatrix();

    //Foot
    glPushMatrix(); 
        glTranslatef(0.0, 0.4, 0.0);
        glRotatef(spongeTheta, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.35, 0.125);
	    glScalef(0.1, 0.1, 0.2);	 
	    glutSolidCube(1.0);
    glPopMatrix();
}

//Create spongebob's arm model.
void arm()
{
    glPushMatrix(); 
	    glScalef(0.1, 0.85, 0.1);	 
	    glutSolidCube(1.0);
    glPopMatrix();
}

//Create a cube out of quads for spongebob's body.
void cube()
{


    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txIdSponge);

 

    glBegin(GL_QUADS); 
    //Front
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(1.0, 0.0);
	glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0, 1.0);
	glVertex3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0, 1.0);
	glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0, 0.0);
	glVertex3f(-0.5f, -0.5f, 0.5f);

    //Top
	glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2f(0.0, 1.0);
	glVertex3f(-0.5, 0.5, 0.5);
    glTexCoord2f(1.0, 1.0);
	glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(1.0, 0.0);
	glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(0.0, 0.0);
	glVertex3f(-0.5, 0.5, -0.5);


	// right

	glNormal3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0, 0.0);
	glVertex3f(0.5f, 0.5f, -0.5f);
    glTexCoord2f(1.0, 1.0);
	glVertex3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0, 1.0);
	glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(0.0, 0.0);
	glVertex3f(0.5f, -0.5f, -0.5f);
 

	// left

	glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0, 1.0);
	glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0, 1.0);
	glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(1.0, 0.0);
	glVertex3f(-0.5f, 0.5f, -0.5f);
    glTexCoord2f(0.0, 0.0);
	glVertex3f(-0.5f, -0.5f, -0.5f);

	// bottom

	glNormal3f(0.0f, -1.0f, 0.0f);
    glTexCoord2f(1.0, 1.0);
	glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(0.0, 1.0);
	glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(0.0, 0.0);
	glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0, 0.0);
	glVertex3f(0.5f, -0.5f, -0.5f);

	// back

	glNormal3f(0.0f, 0.0f, -1.0f);
    glTexCoord2f(1.0, 1.0);
	glVertex3f(0.5f, 0.5f, -0.5f);
    glTexCoord2f(1.0, 0.0);
	glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(0.0, 0.0);
	glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(0.0, 1.0);
	glVertex3f(-0.5f, 0.5f, -0.5f);
 
	glEnd();

    glDisable(GL_TEXTURE_2D);

}

//Create the whole spongebob model.
void spongebobModel()
{
    glColor3f(1.0, 1.0, 0.0); 

    //Body
    glPushMatrix(); 
        glTranslatef(0.0, 1.4, 0.0);
	    glScalef(1.0, 1.4, 0.5);	 
	    cube();
    glPopMatrix();

    //Legs
    glPushMatrix();
        glTranslatef(0.25, 0.7, 0.0);
        glRotatef(spongeTheta, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.7, 0.0);
        leftLeg();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.25, 0.7, 0.0);
        glRotatef(-spongeTheta, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.7, 0.0);
        rightLeg();
    glPopMatrix();

    //Arms
    glPushMatrix();
        glTranslatef(0.61, 0.925, 0.0);
        glRotatef(10, 0.0, 0.0, 1.0);
        glTranslatef(0.0, 0.5, 0.0);
        glRotatef(-spongeTheta, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.5, 0.0);
        arm();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.61, 0.925, 0.0);
        glRotatef(-10, 0.0, 0.0, 1.0);
        glTranslatef(0.0, 0.5, 0.0);
        glRotatef(spongeTheta, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.5, 0.0);
        arm();
    glPopMatrix();

}

//Transform the spongebob model.
void spongebob()
{
    glPushMatrix();

        glTranslatef(0.0, 0.0, -spongeTrans);
        glRotatef(-spongeMoveTheta, 0.0, 1.0, 0.0);
        glTranslatef(1.5, 0.0, 0.0);
        spongebobModel();
    glPopMatrix();
}
