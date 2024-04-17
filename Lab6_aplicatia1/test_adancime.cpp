/*
 Triunghiurile se ascund reciproc.
 Sa se faca reprezentarea fara activarea testului de adancime.
 In acest caz sa se schimbe ordinea specificarii triunghiurilor
 Mai conteaza ordinea specificarii in cazul in care se activeaza testul de adancime?
 */
#include "glos.h"

#include "gl.h"
#include "glu.h"
#include "glaux.h"

void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	//glEnable(GL_DEPTH_TEST);
}

void CALLBACK display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	{
		glVertex3f(0.9, -0.9, -30.0);
		glVertex3f(0.9, 0.9, -30.0);
		glVertex3f(-0.9, 0.0, -30.0);
	}
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	{
		glVertex3f(-0.9, -0.9, -40.0);
		glVertex3f(-0.9, 0.9, -40.0);
		glVertex3f(0.9, 0.0, -25.0);
	}
	glEnd();

	glFlush();
}

static void CALLBACK myReshape(int width, int height)
{
	glViewport(0, 0, (GLint)width, (GLint)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -0.5, 1000.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	auxInitDisplayMode(AUX_SINGLE | AUX_RGB | AUX_DEPTH);
	auxInitPosition(0, 0, 800, 600);
	auxInitWindow("Eliminarea suprafetelor ascunse");
	myInit();
	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return 0;
}
