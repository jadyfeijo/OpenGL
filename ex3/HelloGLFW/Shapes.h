#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <ctime>

const float Pi = 3.14159;

//Coordenadas da janela do mundo (Ortho2D)
const float Xmin = -20;
const float Xmax = 20;
const float Ymin = -20.0;
const float Ymax = 20;


using namespace std;

class Shape
{
public:
	Shape() {}
	~Shape() {}
	void DrawCircle(float posX, float posY, float radius, float nPoints);
	void Shape::DrawTriangle(float r, float g, float b, float xt, float yt, float xs, float ys);
	void DrawT1();
	void DrawT2();
	void DrawT3();

	void DrawGrid();
	void DesenhaBonco();
	void DesenhaCami();
	void DesenhaHeli();
	void DesenhaGato();
	void desenhaPlanta();
	void desenhaCama();
	void desenhaArm();
	void desenhaMPC();
	void desenhaTV();
	void desenhaSofa();
	void desenhaMesa();
	void desenhaTapete();
	void desenhaTeste();



};
