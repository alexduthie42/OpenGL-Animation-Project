//  ========================================================================
//  Alexander Duthie.
//
//  FILE NAME: assignmentMain.cpp
//  Initialises OpenGL parameters and display.
//  Displays models, lights and camera.
//  ========================================================================

#include "house.h"
#include "spongebob.h"
#include "gary.h"
#include "jellyfish.h"
#include "fan.h"
#include "rock.h"
#include "skybox.h"
#include "boundingFence.h"
#include "barrel.h"
#include "road.h"
#include "furniture.h"
#include <iostream>
#include <math.h>
#include <GL/freeglut.h>

//Global variables to determine cameras current position and direction
float angle = 0;
float eye_x = 0.1*sin(angle);
float eye_z = 0.1*sin(angle);
float look_x = eye_z - 100 * sin(angle);
float look_z = eye_z - 100 * cos(angle);

//True if the camera is in first-person of Gary.
bool character_camera = false;


void display(void)
{
	float lpos[4] = {-40., 40., 10., 1.0}; 
    float shadowMat[16] = {40.0, 0, 0, 0, 40, 0, -10, -1, 0, 0, 40, 0, 0, 0, 0, 40};
	float white[4] = {1., 1., 1., 1.};
	float black[4] = {0};

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if (not character_camera)
    {
        gluLookAt(eye_x, 2, eye_z, look_x, 0, look_z, 0, 1, 0);
    }

    //First person camera of gary the snail.
    else if (character_camera)
    {
        glRotatef(90, 0.0, 1.0, 0.0);
        glTranslatef(0.0, 0.0, 2.0);
        glRotatef(garyTheta, 0.0, 1.0, 0.0);
        glTranslatef(-3.0, -0.75, 23.0);
    }

    glLightfv(GL_LIGHT0,GL_POSITION, lpos); 

    //Planar Shadow of house

    glDisable(GL_LIGHTING);

    glPushMatrix();
        glMultMatrixf(shadowMat);
        glTranslatef(0.0, 0.0, -25.0);
        glColor4f(0.2, 0.2, 0.2, 1.0);

        cylinder();

        glPushMatrix();
            glTranslatef(0.0, 0.0, 7.0);
            glScalef(1.05, 1.0, 1.0);
            doorFrame();
        glPopMatrix();
    glPopMatrix();

    glEnable(GL_LIGHTING);

    //Turn on spectular reflections
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);

    //House
    glPushMatrix();
        glTranslatef(0.0, 0.0, -25.0);
        house();
    glPopMatrix();

    //Patricks rock
    glPushMatrix();
        glTranslatef(-25.0, 0.0, -25.0);
        rock();
    glPopMatrix();

	glMaterialfv(GL_FRONT, GL_SPECULAR, black);

    //Skybox
    glPushMatrix();
        glTranslatef(0.0, -0.1, 0.0);
        skybox();
    glPopMatrix();

    //Bounding Fence
    fence();

    //Spongebob
    glPushMatrix();
        glTranslatef(-1.5, 0.0, -23.0);
        spongebob();
    glPopMatrix();

    //Gary the snail
    glPushMatrix();
        glTranslatef(3.0, 0.075, -23.0);
        gary();
    glPopMatrix();

    //Jellyfish 1
    glPushMatrix();
        glTranslatef(-4.625, 1.5, -28.44);
        jellyfish();
    glPopMatrix();

    //Jellyfish 2
    glPushMatrix();
        glTranslatef(3.0, 0.85, -29.0);
        jellyfish();
    glPopMatrix();

    //Celling fan
    glPushMatrix();
        glTranslatef(0.0, 5.0, -25.0);
        fan();
    glPopMatrix();

    //Barrels
    glPushMatrix();
        glTranslatef(-5.0, 0.0, -28.0); 
        glScalef(0.125, 0.15, 0.125);
        barrel();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-4.25, 0.0, -28.8); 
        glScalef(0.125, 0.15, 0.125);
        barrel();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-4.625, 1.5, -28.44); 
        glScalef(0.125, 0.15, 0.125);
        barrel();
    glPopMatrix();

    //Road
    road();

    //Seats
    glPushMatrix();
        glTranslatef(3.5, 0.2, -29.5);
        glRotatef(-35, 0.0, 1.0, 0.0);
        seat();
    glPopMatrix();

    //Table
    glPushMatrix();
        glTranslatef(4.3, 0.5, -28.5);
        glRotatef(-35, 0.0, 1.0, 0.0);
        table();
    glPopMatrix();

	glMaterialfv(GL_FRONT, GL_SPECULAR, white);



    glFlush();
    glutSwapBuffers(); 
}
    
void initialize(void)
{
    float grey[4] = {0.2, 0.2, 0.2, 1.0};
    float white[4]  = {1.0, 1.0, 1.0, 1.0};

    loadGLRockTextures();	
    loadGLSpongeTextures();
    loadGLJellyTextures();
    loadGLRoadTextures();
    loadGLTextures();	
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glEnable(GL_LIGHTING);	
	glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_AMBIENT, grey);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialf(GL_FRONT, GL_SHININESS, 50);

    glEnable(GL_LIGHT1);
	
    glLightfv(GL_LIGHT1, GL_AMBIENT, grey);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT1, GL_SPECULAR, white);
    
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 13.0);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1.0);

 	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluPerspective(60., 1.0, 1.0, 400.0);  

}

void special(int key, int x, int y)
{
    if (not character_camera)
    {
        if(key == GLUT_KEY_RIGHT) angle += 0.1;
        else if(key == GLUT_KEY_LEFT) angle -= 0.1;
        else if(key == GLUT_KEY_DOWN)
        {
            eye_x -= 0.2*sin(angle);
            eye_z += 0.2*cos(angle);
            if(eye_x >= 34 or eye_x <= -34 or eye_z >= 34 or eye_z <= -34)
            {
                eye_x += 0.2*sin(angle);
                eye_z -= 0.2*cos(angle);
            }
        }
        else if(key == GLUT_KEY_UP)
        {
            eye_x += 0.2*sin(angle);
            eye_z -= 0.2*cos(angle);
            if(eye_x >= 34 or eye_x <= -34 or eye_z >= 34 or eye_z <= -34)
            {
                eye_x -= 0.2*sin(angle);
                eye_z += 0.2*cos(angle);
            }
        }
        
        look_x = eye_x + 100 * sin(angle);
        look_z = eye_z - 100 * cos(angle);
    }

    if (key == GLUT_KEY_F1 and character_camera)
    {
        character_camera = false;
    }
    else if (key == GLUT_KEY_F1 and not character_camera)
    {
        character_camera = true;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1250, 1000);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Assingment1");

    initialize();
    glutSpecialFunc(special);
    glutDisplayFunc(display);
    
    glutTimerFunc(35, jellyfishTimer, 0);
    glutTimerFunc(35, garyTimer, 0);
    glutTimerFunc(35, fanTimer, 0);
    glutTimerFunc(35, spongebobTimer, 0);
    glutTimerFunc(35, spongePathTimer, 0);
    glutTimerFunc(35, barrelTimer, 0);

    glutMainLoop();
    return 0;
}






