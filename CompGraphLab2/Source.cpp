#include <string>

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int g_winW = 1000;
int g_winH = 800;

int start_g_winW = 1000;
int start_g_winH = 800;

float xResize = (float)g_winW / (float)start_g_winW;

float yResize = (float)g_winH / (float)start_g_winH;

void resize(int width, int height)
{
    if (width <= 0 || height <= 0) return;

    if (width == g_winW && height == g_winH) return;

    g_winW = width;
    g_winH = height;

	xResize = (float)g_winW / (float)start_g_winW;

	yResize = (float)g_winH / (float)start_g_winH;

    glViewport(0, 0, g_winW, g_winH);
    glutPostRedisplay();
}

void drawAllViewportsBorders(int cols, int rows)
{
	if (cols <= 0 || rows <= 0) return;

	glViewport(0, 0, g_winW, g_winH);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, g_winW, 0, g_winH, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glDisable(GL_LIGHTING);
	glColor3ub(255, 255, 255);
	glLineWidth(2.0f);

	int cellW = g_winW / cols;
	int cellH = g_winH / rows;

	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < cols; ++c)
		{
			int x = c * cellW;
			int y = (rows - 1 - r) * cellH; 

			int x0 = x + 1;
			int y0 = y + 1;
			int x1 = x + cellW - 1;
			int y1 = y + cellH - 1;

			glBegin(GL_LINE_LOOP);
			glVertex2i(x0, y0);
			glVertex2i(x1, y0);
			glVertex2i(x1, y1);
			glVertex2i(x0, y1);
			glEnd();
		}
	}

	glEnable(GL_LIGHTING);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void display_2_0()
{
	glViewport(0, 200 * yResize, 200 * xResize, 200 * yResize);

	glColor3ub(255, 255, 0);
	glPointSize(8.0);
	glEnable(GL_POINT_SMOOTH);

	glBegin(GL_POINTS);

	glVertex2f(-3 , 4);

	glEnd();
}

void display_2_1()
{
	glViewport(200 * xResize, 200 * yResize, 200 * xResize, 200 * yResize);

	glColor3ub(255, 0, 0);
	glPointSize(8.0);

	glBegin(GL_POINTS);

	glVertex2i(3, 3);

	glEnd();
}

void display_2_2()
{
	glViewport(400 * xResize, 200 * yResize, 200 * xResize, 200 * yResize);

	glLineWidth(2); 


	glBegin(GL_LINE_STRIP);

	glColor3ub(255, 255, 255);
	
	//glVertex2f(-5, 4);
	//glVertex2f(-3, 5);
	//glVertex2f(-3, 3);
	//glVertex2f(-5, 2);
	//glVertex2f(-2, 5);
	//glVertex2f(-2, 2);

	glVertex2f(-5, 0);
	glVertex2f(0, 5);
	glVertex2f(0, -5);
	glVertex2f(-2, -2);
	glVertex2f(5, 2);
	glVertex2f(5, -4);

	glEnd();

}

void display_2_3()
{
	glViewport(600 * xResize, 200 * yResize, 200 * xResize, 200 * yResize);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);

	glColor3ub(0, 0, 255);

	glVertex2i(3, 5);
	glVertex2i(4, -1);
	glVertex2i(-3, 1);

	glEnd();

}

void display_3_0()
{
	glViewport(0, 0, 200 * xResize, 200 * yResize);

	glColor3ub(0, 0, 255);
	glPointSize(18.0);
	glEnable(GL_POINT_SMOOTH);

	glBegin(GL_POINTS);

	glVertex2i(-5, -5);

	glEnd();
}

void display_3_1()
{
	glViewport(200 * xResize, 0, 200 * xResize, 200 * yResize);

	glColor3ub(0, 255, 0);
	glPointSize(8.0);

	glBegin(GL_POINTS);

	glVertex2i(3, -4);

	glEnd();
}

void display_3_2_3_3()
{
	glViewport(400 * xResize, 0, 400 * xResize, 200 * yResize);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glBegin(GL_QUADS);

	glVertex2i(-4, 0);
	glVertex2i(2, 4);
	glVertex2i(4, -3);
	glVertex2i(0, -4);

	glEnd();
}

void displatString(std::string str,
	int vp_x, int vp_y, int vp_w, int vp_h,
	int posx, int posy
	)
{
	glViewport(vp_x, vp_y, vp_w, vp_h);

	glRasterPos2i(posx, posy);

	for (char symb : str)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, symb);
	}
}

void  display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, g_winW, g_winH);

	display_2_0();
	display_2_1();
	display_2_2();
	display_2_3();
	display_3_0();
	display_3_1();
	display_3_2_3_3();

	displatString("AVT-414", 800 * xResize, 600 * yResize, 200 * xResize, 200 * yResize, -5, -5);

	glColor3b(255, 255, 0);

	drawAllViewportsBorders(5, 4);

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
	glutInitWindowSize(g_winW, g_winH);
	glutCreateWindow("Hello");
	glutReshapeFunc(resize);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
