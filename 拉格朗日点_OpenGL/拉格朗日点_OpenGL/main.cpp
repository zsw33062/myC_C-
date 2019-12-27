//  main.cpp
#include <GL/glut.h>
#include "solarsystem.h"
#define WINDOW_X_POS 50
#define WINDOW_Y_POS 50
#define WIDTH 700
#define HEIGHT 700
SolarSystem solarsystem;//实例化一个太阳系
void onDisplay(void) {
	solarsystem.onDisplay();
}
void onUpdate(void) {
	solarsystem.onUpdate();
}
void onKeyboard(unsigned char key, int x, int y) {
	solarsystem.onKeyboard(key, x, y);
}
int mainGL(int argc, char*  argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(WINDOW_X_POS, WINDOW_Y_POS);
	glutCreateWindow("SolarSystem at ");
	glutDisplayFunc(onDisplay);
	glutIdleFunc(onUpdate);
	glutKeyboardFunc(onKeyboard);
	glutMainLoop();
	return 0;
}