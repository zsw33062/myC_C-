
#include <GL/glut.h>
#include <math.h>
#include <iostream>

#define WINDOW_X_POS 50
#define WINDOW_Y_POS 50
#define WIDTH 700
#define HEIGHT 700
#define STARS_NUM 10
#define TIMEPAST 1
#define SELFROTATE 3
#define PI 3.1415926535
#define OFFSET 20
//公转半径
#define SUN_RADIUS 48.74
#define MER_RADIUS  7.32
#define VEN_RADIUS 18.15
#define EAR_RADIUS 19.13
#define MOO_RADIUS  6.15
#define MAR_RADIUS 10.19
#define JUP_RADIUS 42.90
#define SAT_RADIUS 36.16
#define URA_RADIUS 25.56
#define NEP_RADIUS 24.78

//距太阳的距离
#define MER_DIS   62.06
#define VEN_DIS  115.56
#define EAR_DIS  168.00
#define MOO_DIS   26.01
#define MAR_DIS  228.00
#define JUP_DIS  333.40
#define SAT_DIS  428.10
#define URA_DIS 848.00
#define NEP_DIS 949.10

//运动速度
#define MER_SPEED   870.0
#define VEN_SPEED  2250.0
#define EAR_SPEED  3650.0
#define MOO_SPEED   300.0
#define MAR_SPEED  6870.0
#define JUP_SPEED 12980.4
#define SAT_SPEED 32250.6
#define URA_SPEED 30660.4
#define NEP_SPEED 60140.8

#define SET_VALUE_3(name, value0, value1, value2) \
	((name)[0]) = (value0), ((name)[1]) = (value1), ((name)[2]) = (value2)
#define REST 700
#define REST_Z (REST)
#define REST_Y (-REST)

using namespace std;
enum STARS {
	Sun,      //太阳
	Mercury,  //水星
	Venus,    //金星
	Earth,      //地球
	Moon,     //月球
	Mars,     //火星
	Jupiter,  //土星
	Saturn,   //木星
	Uranus,   //天王星
	Neptune   //海王星
};

class Star {
public:
	GLfloat radius;
	GLfloat speed, selfSpeed;
	GLfloat distance;
	GLfloat rgbaColor[4];

	Star* parentStar;

	Star::Star(GLfloat radius, GLfloat distance, GLfloat speed,
		GLfloat selfSpeed, Star *parent);

	void drawStar();
	virtual void draw() { drawStar(); }
	virtual void update(long timeSpan);
protected:
	float alphaSelf, alpha;
};

class Planet : public Star {
public:
	Planet::Planet(GLfloat radius, GLfloat distance, GLfloat speed,
		GLfloat selfspeed, Star *parent, GLfloat rgbColor[3]);
	void drawPlanet();
	virtual void draw() { drawPlanet(); drawStar(); }
};

class LightPlanet :public Planet {
public:
	LightPlanet::LightPlanet(GLfloat Radius, GLfloat Distance, GLfloat Speed,
		GLfloat Selfspeed, Star *Parent, GLfloat rgbColor[]);
	void drawLight();
	virtual void draw() { drawLight(); drawPlanet(); drawStar(); }
};

class SolarSystem {
public:
	SolarSystem::SolarSystem();
	SolarSystem::~SolarSystem();

	void onDisplay();
	void onUpdate();
	void onKeyboard(unsigned char key, int x, int y);

private:
	Star *stars[STARS_NUM];

	GLdouble viewX, viewY, viewZ;
	GLdouble centerX, centerY, centerZ;
	GLdouble upX, upY, upZ;
};

void Star::update(long timeSpan) {
	alpha += timeSpan*speed;
	alphaSelf += selfSpeed;
}

void Star::drawStar() {
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	int n = 1440;

	glPushMatrix();
	{
		if (parentStar != 0 && parentStar->distance > 0) {
			//图像沿Z轴旋转alpha
			glRotatef(parentStar->alpha, 0, 0, 1);
			//x轴平移distance
			glTranslatef(parentStar->distance, 0.0, 0.0);
		}
		//绘制运行轨道
		glBegin(GL_LINES);
		for (int i = 0; i < n; ++i)
			glVertex2f(distance*cos(2 * PI*i / n), distance*sin(2 * PI*i / n));
		glEnd();
		//绕Z轴旋转alpha
		glRotatef(alpha, 0, 0, 1);
		glTranslatef(distance, 0.0, 0.0);

		//自转
		glRotatef(alphaSelf, 0, 0, 1);
		//上色
		glColor3f(rgbaColor[0], rgbaColor[1], rgbaColor[2]);
		glutSolidSphere(radius, 40, 32);
	}
	glPopMatrix();
}

Star::Star(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfspeed,
	Star* parent) {
	this->radius = radius;
	this->distance = distance;
	this->selfSpeed = selfspeed;
	this->alphaSelf = this->alpha = 0;
	for (int i = 0; i < 4; i++)
		this->rgbaColor[i] = 1.0f;
	this->parentStar = parent;

	if (speed > 0)
		this->speed = 360.0f / speed;
	else
		this->speed = 0.0f;
}

Planet::Planet(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfspeed, Star * parent, GLfloat rgbColor[3]) :
Star(radius, distance, speed, selfSpeed, parent)
{
	rgbaColor[0] = rgbColor[0];
	rgbaColor[1] = rgbColor[1];
	rgbaColor[2] = rgbColor[2];
	rgbaColor[3] = 1.0f;
}

LightPlanet::LightPlanet(GLfloat Radius, GLfloat Distance, GLfloat Speed, GLfloat Selfspeed, Star * Parent, GLfloat rgbColor[]) :
Planet(radius, distance, speed, selfSpeed, Parent, rgbColor)
{
	;
}

void Planet::drawPlanet() {
	GLfloat mat_ambient[] = { 0.0f, 0.0f, 0.5f, 1.0f };
	GLfloat mat_diffuse[] = { 0.0f, 0.0f, 0.5f, 1.0f };
	GLfloat mat_specular[] = { 0.0f, 0.0f, 1.0f, 1.0f };
	GLfloat mat_emission[] = { rgbaColor[0], rgbaColor[1], rgbaColor[2], rgbaColor[3] };
	GLfloat mat_shininess = 90.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
}

void LightPlanet::drawLight() {
	GLfloat light_position[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);//零号光源位置
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);//各种光线反射到该材质上，经过多次反射后遗留的光线强度
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);//漫反射后的光照强度
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);//镜面反射后的光照强度

}

void SolarSystem::onUpdate() {
	for (int i = 0; i < STARS_NUM; i++)
		stars[i]->update(TIMEPAST);
	this->onDisplay();
}

void SolarSystem::onKeyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':viewY += OFFSET; break;
	case 's':viewZ += OFFSET; break;
	case 'S':viewZ -= OFFSET; break;
	case 'a':viewX -= OFFSET; break;
	case 'd':viewX += OFFSET; break;
	case 'x':viewY -= OFFSET; break;
	case 'r':
		viewX = 0; viewY = REST_Y; viewZ = REST_Z;
		centerX = centerY = centerZ = 0;
		upX = upY = 0; upZ = 1;
		break;
	case '27':exit(0); break;
	default:break;
	}
}

SolarSystem::SolarSystem()
{
	viewX = 0;
	viewY = REST_Y;
	viewZ = REST_Z;

	centerX = centerY = centerZ = 0;
	upX = upY = 0;
	upZ = 1;

	//solar
	GLfloat rgbColor[3] = { 1, 0, 0 };
	stars[Sun] = new LightPlanet(SUN_RADIUS, 0, 0, SELFROTATE, 0, rgbColor);
	//shui xing
	SET_VALUE_3(rgbColor, .2, .2, .5);
	stars[Mercury] = new Planet(MER_RADIUS, MER_DIS, MER_SPEED, SELFROTATE, 0, rgbColor);
	// jin xing
	SET_VALUE_3(rgbColor, 1, .7, 0);
	stars[Venus] = new Planet(VEN_RADIUS, VEN_DIS, VEN_SPEED, SELFROTATE, stars[Sun], rgbColor);
	//earth
	SET_VALUE_3(rgbColor, 0, 1, 0);
	stars[Earth] = new Planet(EAR_RADIUS, EAR_DIS, EAR_SPEED, SELFROTATE, stars[Sun], rgbColor);
	//moon
	SET_VALUE_3(rgbColor, 1, 1, 0);
	stars[Moon] = new Planet(MOO_RADIUS, MOO_DIS, MOO_SPEED, SELFROTATE, stars[Earth], rgbColor);
	//mars
	SET_VALUE_3(rgbColor, 1, .5, .5);
	stars[Mars] = new Planet(MAR_RADIUS, MAR_DIS, MAR_SPEED, SELFROTATE, stars[Sun], rgbColor);

	SET_VALUE_3(rgbColor, 1, 1, .5);
	stars[Jupiter] = new Planet(JUP_RADIUS, JUP_DIS, JUP_SPEED, SELFROTATE, stars[Sun], rgbColor);

	SET_VALUE_3(rgbColor, .5, 1, .5);
	stars[Saturn] = new Planet(SAT_RADIUS, SAT_DIS, SAT_SPEED, SELFROTATE, stars[Sun], rgbColor);

	SET_VALUE_3(rgbColor, .4, .4, .4);
	stars[Uranus] = new Planet(URA_RADIUS, URA_DIS, URA_SPEED, SELFROTATE, stars[Sun], rgbColor);

	SET_VALUE_3(rgbColor, .5, .5, 1);
	stars[Neptune] = new Planet(NEP_RADIUS, NEP_DIS, NEP_SPEED, SELFROTATE, stars[Sun], rgbColor);
}

SolarSystem::~SolarSystem()
{
	for (int i = 0; i < STARS_NUM; i++)
		delete stars[i];
}

void SolarSystem::onDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(.7f, .7f, .7f, .7f);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(75.0f, 1.0f, 1.0f, 40000000);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	gluLookAt(viewX, viewY, viewZ, centerX, centerY, centerZ, upX, upY, upZ);

	glEnable(GL_LIGHT0);

	glEnable(GL_LIGHTING);

	glEnable(GL_DEPTH_TEST);

	for (int i = 0; i < STARS_NUM; i++)
		stars[i]->draw();


	glutSwapBuffers();
}

SolarSystem solarsystem;
void onDisplay(void) {
	solarsystem.onDisplay();
};

void onUpdate(void) {
	solarsystem.onUpdate();
};

void onKeyboard(unsigned char key, int x, int y) {
	solarsystem.onKeyboard(key, x, y);
};

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	//使用RGBA模式和双缓冲窗口
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(WINDOW_X_POS, WINDOW_Y_POS);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("SolarSystem");


	glutDisplayFunc(onDisplay);
	glutIdleFunc(onUpdate);
	glutKeyboardFunc(onKeyboard);

	glutMainLoop();
	return 0;
}