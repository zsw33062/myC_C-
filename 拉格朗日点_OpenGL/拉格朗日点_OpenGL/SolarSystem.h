#include "Star.h"
//#define STARS_NUM=9;
class SolarSystem {
public:
	SolarSystem();
	~SolarSystem();
	void onDisplay();
	void onUpdate();
	void onKeyboard(unsigned char key, int x, int y);
private:
	Star *stars[5];
	// ����۲��ӽǵĲ���
	GLdouble viewX, viewY, viewZ;
	GLdouble centerX, centerY, centerZ;
	GLdouble upX, upY, upZ;
};