#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
class Star {
public:
	// ��������а뾶
	GLfloat radius;
	// ����Ĺ�ת���Դ��ٶ�
	GLfloat speed, selfSpeed;
	// ����������븸�ڵ��������ĵľ���
	GLfloat distance;
	// �������ɫ
	GLfloat rgbaColor[4];
	// ���ڵ�����
	Star* parentStar;
	// ���캯��������һ������ʱ�����ṩ
	// ��ת�뾶����ת�ٶȡ���ת�ٶȡ�����(���ڵ�)����
	Star(GLfloat radius, GLfloat distance,
		GLfloat speed, GLfloat selfSpeed,
		Star* parent);
	// ��һ���������ƶ�����ת�Ȼ���л���
	void drawStar();
	// �ṩĬ��ʵ�֣�������� drawStar()
	virtual void draw() { drawStar(); }
	// ����Ϊÿ��ˢ�»���ʱ��ʱ����
	virtual void update(long timeSpan);
protected:
	float alphaSelf, alpha;
};
class Planet : public Star {
public:
	// ���캯��
	Planet(GLfloat radius, GLfloat distance,
		GLfloat speed, GLfloat selfSpeed,
		Star* parent, GLfloat rgbColor[3]);
	// ���ӶԾ߱�������ʵ����ǻ��Ʋ���
	void drawPlanet();
	// �����������࿪����д����
	virtual void draw() { drawPlanet(); drawStar(); }
};
class LightPlanet : public Planet {
public:
	LightPlanet(GLfloat Radius, GLfloat Distance,
		GLfloat Speed, GLfloat SelfSpeed,
		Star* Parent, GLfloat rgbColor[]);
	// ���Ӷ��ṩ��Դ�ĺ��ǻ��ƹ���
	void drawLight();
	virtual void draw() { drawLight(); drawPlanet(); drawStar(); }
};