/*
 Eliminarea fetelor functie de orientare. Se va afisa fara activarea eliminarii fetelor. Cu orientarea
 directa implicita se  vor schimba fetele care se elimina cele fata sau cele spate-cu functia glCullFace.
 Se va schimba apoi ordinea directa a varfurilor cu glFrontFace avand parametrii - GL_CW, GL_CCW.
 */
#include "glos.h"

#include "gl.h"
#include "glu.h"
#include "glaux.h"

void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

void CALLBACK display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -4.0);

    glColor3f(1.0, 0.0, 0.0);
    glDisable(GL_CULL_FACE); // Dezactivă eliminarea fețelor temporar
    glBegin(GL_POLYGON);
    {
        glVertex2f(-1.0, 0.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 1.0);
        glVertex2f(-1.0, 1.0);
    }
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    {
        glVertex2f(1.0, 1.0);
        glVertex2f(2.0, 1.0);
        glVertex2f(2.0, 0.0);
        glVertex2f(1.0, 0.0);
    }
    glEnd();

    glEnable(GL_CULL_FACE); // Re-activează eliminarea fețelor

    glFlush();
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
	if (!h) return;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 3.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -4.0);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
}

int main(int argc, char** argv)
{
	auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
	auxInitPosition(0, 0, 800, 600);
	auxInitWindow("Eliminarea fetelor functie de orientare");
	myInit();
	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return 0;
}
