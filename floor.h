#include <iostream>
#include <math.h>
#include <GL/freeglut.h>

void floor()
{
    glColor3f(0.0, 1.0, 0.0);
	glNormal3f(0.0, 1.0, 0.0);
    
	for(int i = -50; i <= 50; i ++)
	{
		glBegin(GL_LINES);			
			glVertex3f(-50, -2, i);
			glVertex3f(50, -2, i);
			glVertex3f(i, -2, -50);
			glVertex3f(i, -2, 50);
		glEnd();
	}

}

//Floor solid
    /*
    glBegin(GL_QUADS);
    
    for(int i = -100; i < 100; i++)
    {
        for(int j = -100; j < 100; j++)
        {
            glVertex3f(i, 0, j);
            glVertex3f(i, 0, j + 1);
            glVertex3f(i + 1, 0, j + 1);
            glVertex3f(i + 1, 0, j);
        }
    }
    glEnd();
    */
