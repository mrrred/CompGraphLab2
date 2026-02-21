#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void resize(int width, int height)
{
}

void display_2_0()
{
	glViewport(0, 200, 200, 200);

	glColor3ub(255, 255, 0);
	glPointSize(8.0);
	glEnable(GL_POINT_SMOOTH);

	glBegin(GL_POINTS);

	glVertex2f(-3, 4);

	glEnd();
}

void display_2_1()
{
	glViewport(200, 200, 200, 200);

	glColor3ub(255, 0, 0);
	glPointSize(8.0);

	glBegin(GL_POINTS);

	glVertex2f(3, 3);

	glEnd();
}

void display_2_2()
{

}

void display_2_3()
{

}

void display_3_0()
{

}

void display_3_1()
{

}

void display_3_2_3_3()
{

}

void  display(void)
{
	display_2_0();
	display_2_1();

	glFlush();

}
void init(void)
{
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-24.0, 24.0, -30.0, 30.0, 2.0, 12.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(
		0, 0, 5, 
		0, 0, 0, 
		0, 1, 0);

}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(50, 10);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Hello");
	glutReshapeFunc(resize);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
