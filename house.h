//  ========================================================================
//  Alexander Duthie.
//
//  FILE NAME: house.h
//  Creates the house model.
//  ========================================================================

#include <iostream>
#include <math.h>
#include <GL/freeglut.h>

GLUquadricObj*	q;

//Creates the window of the house.
void window()
{
    glColor3f(0.75, 0.75, 1.0);

    q =  gluNewQuadric ( );
    glutSolidTorus(0.25, 1.5, 10, 36);

	glPushMatrix(); 
	    glScalef(1.0, 1.0, 0.0);	 
	    gluSphere (q, 1.5, 36, 2);
    glPopMatrix();
    
}

//Creates the doorway arch of the house
void arch()
{
    float angle1,angle2, ca1,sa1, ca2,sa2;
	float x1,z1, x2,z2, x3,z3, x4,z4; 
    float toRad = 3.14159265/180.0; 

    float radius = 1.25;

    glBegin(GL_QUADS);
	for(int i = 90; i < 270; i += 6)    
	{
		angle1 = i * toRad;      
		angle2 = (i+6) * toRad;
		ca1=cos(angle1); 
        ca2=cos(angle2);
		sa1=sin(angle1); 
        sa2=sin(angle2);

		x1=(radius-0.1875)*sa1; 
		x2=(radius+0.1875)*sa1; 
		x3=(radius+0.1875)*sa2; 
		x4=(radius-0.1875)*sa2; 

        z1=(radius-0.1875)*ca1; 
        z2=(radius+0.1875)*ca1;
        z3=(radius+0.1875)*ca2;
        z4=(radius-0.1875)*ca2;

		glNormal3f(0., 1.0, 0.);     
		glVertex3f(x1, 0.375, z1);
		glVertex3f(x2, 0.375, z2);
		glVertex3f(x3, 0.375, z3);
		glVertex3f(x4, 0.375, z4); 

		glNormal3f(0., -1.0, 0.);     
		glVertex3f(x1, 0.0, z1);
		glVertex3f(x2, 0.0, z2);
		glVertex3f(x3, 0.0, z3);
		glVertex3f(x4, 0.0, z4);

		glNormal3f(-sa1, 0.0, -ca1);   
		glVertex3f(x1, 0.0, z1);
		glVertex3f(x1, 0.375, z1);
		glNormal3f(-sa2 ,0.0, -ca2);
		glVertex3f(x4, 0.375, z4);
		glVertex3f(x4, 0.0, z4);

		glNormal3f(sa1, 0.0, ca1);  
		glVertex3f(x2, 0.375, z2);
		glVertex3f(x2, 0.0, z2);
		glNormal3f(sa2, 0.0, ca2);
		glVertex3f(x3, 0.0, z3);
		glVertex3f(x3, 0.375, z3);
    }
    glEnd();
}

//Creates the doorway model of the house.
void doorFrame()
{

    //Left pillar
	glPushMatrix(); 
        glTranslatef(-1.25, 1.75, 0.0);
	    glScalef(0.375, 3.5, 0.375);	 
	    glutSolidCube(1.0);
    glPopMatrix();

    //Right pillar
	glPushMatrix(); 
        glTranslatef(1.25, 1.75, 0.0);
	    glScalef(0.375, 3.5, 0.375);	 
	    glutSolidCube(1.0);
    glPopMatrix();

    //Arch
    glPushMatrix(); 
        glTranslatef(0.0, 3.5, -0.1875);
        glRotatef(90, 1.0, 0.0, 0.0);
        arch();
    glPopMatrix();

}

//Creates a single leaf of the pineapple head.
void leaf()
{
    glBegin(GL_QUADS);
        glNormal3f(0.0, 0.0, -1.0); 
		glVertex3f(-0.75, 0.0, 0.0);
		glVertex3f(0.75, 0.0, 0.0);
		glVertex3f(1.0, 3.5, 0.0);
		glVertex3f(-1.0, 3.5, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
		glVertex3f(-1.0, 3.5, 0.0);
		glVertex3f(1.0, 3.5, 0.);
        glVertex3f(0, 5.5, 0.35);
    glEnd();
}

//Creates the pineapple head model.
void pineappleHead()
{
    //Back
	glPushMatrix(); 
        glTranslatef(0.0, 0.0, -1.25);
        glRotatef(-15, 1.0, 0.0, 0.0);
        leaf();
    glPopMatrix();

    //Front
	glPushMatrix(); 
        glTranslatef(0.0, 0.0, 1.25);
        glRotatef(15, 1.0, 0.0, 0.0);
        glRotatef(180, 0.0, 1.0, 0.0);
        leaf();
    glPopMatrix();

    //Side1
	glPushMatrix(); 
        glRotatef(50, 0.0, 1.0, 0.0);
        glTranslatef(0.0, 0.0, 1.25);
        glRotatef(15, 1.0, 0.0, 0.0);
        glScalef(0.6, 0.75, 1.0);
        glRotatef(180, 0.0, 1.0, 0.0);
        leaf();
    glPopMatrix();

    //Side2
	glPushMatrix(); 
        glRotatef(-50, 0.0, 1.0, 0.0);
        glTranslatef(0.0, 0.0, 1.25);
        glRotatef(15, 1.0, 0.0, 0.0);
        glScalef(0.6, 0.75, 1.0);
        glRotatef(180, 0.0, 1.0, 0.0);
        leaf();
    glPopMatrix();

    //Side3
	glPushMatrix(); 
        glRotatef(230, 0.0, 1.0, 0.0);
        glTranslatef(0.0, 0.0, 1.25);
        glRotatef(15, 1.0, 0.0, 0.0);
        glScalef(0.6, 0.75, 1.0);
        glRotatef(180, 0.0, 1.0, 0.0);
        leaf();
    glPopMatrix();

    //Side4
	glPushMatrix(); 
        glRotatef(-230, 0.0, 1.0, 0.0);
        glTranslatef(0.0, 0.0, 1.25);
        glRotatef(15, 1.0, 0.0, 0.0);
        glScalef(0.6, 0.75, 1.0);
        glRotatef(180, 0.0, 1.0, 0.0);
        leaf();
    glPopMatrix();

   //Side5
	glPushMatrix(); 
        glRotatef(90, 0.0, 1.0, 0.0);
        glTranslatef(0.0, 0.0, 1.25);
        glRotatef(30, 1.0, 0.0, 0.0);
        glScalef(0.4, 0.5, 1.0);
        glRotatef(180, 0.0, 1.0, 0.0);
        leaf();
    glPopMatrix();

   //Side6
	glPushMatrix(); 
        glRotatef(-90, 0.0, 1.0, 0.0);
        glTranslatef(0.0, 0.0, 1.25);
        glRotatef(30, 1.0, 0.0, 0.0);
        glScalef(0.4, 0.5, 1.0);
        glRotatef(180, 0.0, 1.0, 0.0);
        leaf();
    glPopMatrix();

}


//Creates the cyclinder model of the house.
void cylinder()
{
    float radius = 7;

   //House cylinder
    glBegin(GL_QUADS);
    
    float angle1,angle2, ca1,sa1, ca2,sa2;
	float x1,z1, x2,z2, x3,z3, x4,z4; 
    float toRad = 3.14159265/180.0; 

    glBegin(GL_QUADS);
	for(int i = 0; i < 360; i += 6)    
	{
        angle1 = i * toRad;      
        angle2 = (i+6) * toRad;
        ca1=cos(angle1); 
        ca2=cos(angle2);
        sa1=sin(angle1); 
        sa2=sin(angle2);

        x1=(radius)*sa1; 
        x2=(radius)*sa1; 
        x3=(radius)*sa2; 
        x4=(radius)*sa2; 

        z1=(radius)*ca1; 
        z2=(radius)*ca1;
        z3=(radius)*ca2;
        z4=(radius)*ca2;

        if(i != 0 and i != 6 and i != 354 and i != 348)
        {
            for (int j = 1; j < 110; j+=1)
            {
                glNormal3f(sa1, 0.0, ca1); 
                glVertex3f(x1, (float(j)/10), z1);
                glVertex3f(x2, (float(j)/10) - 0.1, z2);
                glNormal3f(sa2, 0.0, ca2);
                glVertex3f(x3, (float(j)/10) - 0.1, z3);
                glVertex3f(x4, (float(j)/10), z4);
            }
        }

        //Doorway segments
        else if(i == 0)
        {
            glNormal3f(sa1, 0.0, ca1); 
            glVertex3f(x1, 10.5, z1);
            glVertex3f(x2, 4.9, z2);
            glNormal3f(sa2, 0.0, ca2);
            glVertex3f(x3, 4.75, z3);
            glVertex3f(x4, 10.5, z4);
        }

        else if(i == 354)
        {
            glNormal3f(sa1, 0.0, ca1); 
            glVertex3f(x1, 10.5, z1);
            glVertex3f(x2, 4.75, z2);
            glNormal3f(sa2, 0.0, ca2);
            glVertex3f(x3, 4.9, z3);
            glVertex3f(x4, 10.5, z4);
        }

        else if(i == 6)
        {
            glNormal3f(sa1, 0.0, ca1); 
            glVertex3f(x1, 10.5, z1);
            glVertex3f(x2, 4.3, z2);
            glNormal3f(sa2, 0.0, ca2);
            glVertex3f(x3, 3.8, z3);
            glVertex3f(x4, 10.5, z4);
        }

        else if(i == 348)
        {
            glNormal3f(sa1, 0.0, ca1); 
            glVertex3f(x1, 10.5, z1);
            glVertex3f(x2, 3.8, z2);
            glNormal3f(sa2, 0.0, ca2);
            glVertex3f(x3, 4.3, z3);
            glVertex3f(x4, 10.5, z4);
        }
    }
    glEnd();
}

//Creates the frame of the house.
void houseFrame()
{
    float radius = 7;

    double plane[4] = {0.0, 1.0, 0.0, 0.35}; 

    glEnable(GL_CLIP_PLANE0);
    
    //House dome
    q =  gluNewQuadric ( );
	glPushMatrix(); 
	    glTranslatef(0.0, 10.75, 0.0);	
        glClipPlane(GL_CLIP_PLANE0, plane); 
	    gluSphere (q, radius, 36, 36);
    glPopMatrix();

    glDisable(GL_CLIP_PLANE0);

    cylinder();
}

//Puts all the house model pieces together to create the house model.
void house()
{
    //Pineapple frame
    glPushMatrix();
        glColor3f(1.0, 0.5, 0.1);
        houseFrame();
    glPopMatrix();

    //House pineapple leave top
	glPushMatrix(); 
        glColor3f(0.0, 1.0, 0.0);
	    glTranslatef(0.0, 17.0, 0.0);
        glScalef(2.0, 1.5, 2.0);
        pineappleHead();
    glPopMatrix();

    //Windows
    glPushMatrix(); 
        glRotatef(-32, 0.0, 1.0, 0.0);
        glTranslatef(0.0, 9.0, 7.0);
        glScalef(0.85, 0.85, 0.85);
        window();
    glPopMatrix();

    glPushMatrix(); 
        glRotatef(35, 0.0, 1.0, 0.0);
        glTranslatef(0.0, 4.0, 7.0);
        glScalef(0.85, 0.85, 0.85);
        window();
    glPopMatrix();

    //Door frame
    glPushMatrix(); 
        glTranslatef(0.0, 0.0, 7.0);
        glScalef(1.05, 1.0, 1.0);
        doorFrame();
    glPopMatrix();

    //Celling
	glPushMatrix(); 
        glTranslatef(0.0, 7.0, 0.0);
        glRotatef(90, 1.0, 0.0, 0.0);
	    glScalef(7.0, 6.9, 0.0);	 
	    gluSphere (q, 1.0, 36, 2);
    glPopMatrix();

}
