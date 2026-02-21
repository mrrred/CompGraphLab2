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

	glVertex2i(-3, 4);

	glEnd();
}

void display_2_1()
{
	glViewport(200, 200, 200, 200);

	glColor3ub(255, 0, 0);
	glPointSize(8.0);

	glBegin(GL_POINTS);

	glVertex2i(3, 3);

	glEnd();
}

void display_2_2()
{
	glViewport(400, 200, 200, 200);

	glLineWidth(1); 


	glBegin(GL_LINE_LOOP);

	glColor3ub(255, 255, 255);
	
	glVertex2f(-5, 4);
	glVertex2f(-3, 5);
	glVertex2f(-3, 3);
	glVertex2f(-5, 2);
	glVertex2f(-2, 5);
	glVertex2f(-2, 2);


	glEnd();

}

void display_2_3()
{
	
}

void display_3_0()
{
	glViewport(0, 0, 200, 200);

	glColor3ub(0, 0, 255);
	glPointSize(18.0);
	glEnable(GL_POINT_SMOOTH);

	glBegin(GL_POINTS);

	glVertex2i(-5, -5);

	glEnd();
}

void display_3_1()
{
	glViewport(200, 0, 200, 200);

	glColor3ub(0, 255, 0);
	glPointSize(8.0);

	glBegin(GL_POINTS);

	glVertex2i(3, -4);

	glEnd();
}

void display_3_2_3_3()
{

}

void  display(void)
{
	display_2_0();
	display_2_1();
	display_2_2();
	display_2_3();
	display_3_0();
	display_3_1();
	display_3_2_3_3();


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
	glOrtho(-6.0, 6.0, -6.0, 6.0, 2.0, 12.0);
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
