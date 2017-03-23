#include "stdafx.h"
#include <cmath>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

GLfloat x_1 = 150.0f;

GLfloat y_1 = 150.0f;

GLsizei rsize = 49;
///////////////////////////////////////////////////////////
// Wywo�ywana w celu przerysowania sceny
void RenderScene(void) {
	// Wyczyszczenie okna aktualnym kolorem czyszczcym   
	glClear(GL_COLOR_BUFFER_BIT);
	// Aktualny kolor rysujcy - czerwony  
	//           R     G     B  
	glColor3f(1.0f, 0.0f, 0.0f);
	// Narysowanie prostokta wype�nionego aktualnym kolorem  
	int triangleAmount = 7;
	GLfloat twicePi = 2.0f * 3.14;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x_1, y_1);

	for (int i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(
			x_1 + (10.0*sin(i*twicePi / triangleAmount)) * 5,
			y_1 + (10.0*cos(i*twicePi / triangleAmount)) * 5);
	}
	glEnd();
	glFlush();
	// Wys�anie polece do wykonania     
	glFlush();
	glutSwapBuffers();
}
///////////////////////////////////////////////////////////
// Konfiguracja stanu renderowania  
void SetupRC(void) {
	// Ustalenie niebieskiego koloru czyszczcego     
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
}
///////////////////////////////////////////////////////////
// Wywo�ywana przez bibliotek GLUT w przypadku zmiany rozmiaru okna
void ChangeSize(int w, int h) {
	GLfloat aspectRatio;
	// Zabezpieczenie przed dzieleniem przez zero  
	if (h == 0)   h = 1;
	// Ustawienie wielko�ci widoku na r�wn� wielko�ci okna     
	glViewport(0, 0, w, h);
	// Ustalenie uk�adu wsp�rz�dnych  
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Wyznaczenie przestrzeni ograniczaj�cej (lewy, prawy, dolny, g�rny, bliski, odleg�y)  
	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h)    glOrtho(-100.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
	else    glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);  glLoadIdentity();
}
///////////////////////////////////////////////////////////
// G��wny punkt wejcia programu
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("GLRect");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();
	return 0;
}
