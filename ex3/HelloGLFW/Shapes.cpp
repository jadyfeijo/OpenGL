#include "Shapes.h"

void Shape::DrawCircle(float posX, float posY, float radius, float nPoints)
{
	float rd = radius;

	float angle = 0.0;
	float slice = 2 * Pi / nPoints;
	float x, y;

	float xi = posX;
	float yi = posY;

	//Habilitar a cor do círculo
	glColor3f(0, 0, 0);

	//Tamanho do ponto
	glPointSize(5);

	//Espessura da linha
	glLineWidth(3);

	//Habilitar o desenho do tipo de primitiva escolhido (ponto, linha, polígono etc)
	glBegin(GL_POLYGON);
	while (angle <= 2 * Pi)
	{
		//Sorteia uma cor para o vertice
		float r = rand() % 10 / 10.0;
		float b = rand() % 10 / 10.0;
		float g = rand() % 10 / 10.0;

		glColor3f(r, g, b);

		//Calcular posicao do ponto em x, y
		x = xi + rd * cos(angle);
		y = yi + rd * sin(angle);
		glVertex2f(x, y);
		//Atualizar o angulo
		angle += slice;
	}
	//Desabilita o desenho do tipo de primitiva
	glEnd();

	//Para desenhar o contorno
	//Habilitar o desenho do tipo de primitiva escolhido (ponto, linha, polígono etc)
	glColor3f(0, 0, 0);
	angle = 0.0;
	glBegin(GL_LINE_LOOP);
	while (angle <= 2 * Pi)
	{
		//Calcular posicao do ponto em x, y
		x = xi + rd * cos(angle);
		y = yi + rd * sin(angle);
		glVertex2f(x, y);
		//Atualizar o angulo
		angle += slice;
	}
	//Desabilita o desenho do tipo de primitiva
	glEnd();

	//Para desenhar os pontos
	//Habilitar o desenho do tipo de primitiva escolhido (ponto, linha, polígono etc)
	glColor3f(1, 0, 1);
	angle = 0.0;
	glBegin(GL_POINTS);
	while (angle <= 2 * Pi)
	{
		//Calcular posicao do ponto em x, y
		x = xi + rd * cos(angle);
		y = yi + rd * sin(angle);
		glVertex2f(x, y);
		//Atualizar o angulo
		angle += slice;
	}
	//Desabilita o desenho do tipo de primitiva
	glEnd();
	
}



void Shape::DrawTriangle(float r, float g, float b)

{
	glColor3f(r, g, b);


	glBegin(GL_TRIANGLES);
		
		glVertex2f(-0.5,-0.5);
		glVertex3f( 0.0, 0.5,0);
		glVertex3f( 0.5,-0.5,0);
	glEnd();
}

void Shape::DrawT1()
{

	glColor3f(1, 0, 0);

	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5, -0.5);
	//glColor3f(0, 1, 0);
	glVertex3f(0.0, 0.5, 0);
	glColor3f(0, 0, 1);
	glVertex3f(0.5, -0.5, 0);
	glEnd();

	//glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.5, -0.5);
	glVertex3f(0.0, 0.5, 0);
	glVertex3f(0.5, -0.5, 0);
	glEnd();

	//glColor3f(0, 1, 1);
	glBegin(GL_POINTS);
	glVertex2f(-0.5, -0.5);
	glVertex3f(0.0, 0.5, 0);
	glVertex3f(0.5, -0.5, 0);
	glEnd();
}

void Shape::DrawT2()
{

	glColor3f(0, 1, 0);

	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5, -0.5);
	//glColor3f(0, 1, 0);
	glVertex3f(0.0, 0.5, 0);
	glColor3f(0, 0, 1);
	glVertex3f(0.5, -0.5, 0);
	glEnd();

	//glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.5, -0.5);
	glVertex3f(0.0, 0.5, 0);
	glVertex3f(0.5, -0.5, 0);
	glEnd();

	//glColor3f(0, 1, 1);
	glBegin(GL_POINTS);
	glVertex2f(-0.5, -0.5);
	glVertex3f(0.0, 0.5, 0);
	glVertex3f(0.5, -0.5, 0);
	glEnd();
}

void Shape::DrawT3()
{

	glColor3f(0, 1, 1);

	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5, -0.5);
	//glColor3f(0, 1, 0);
	glVertex3f(0.0, 0.5, 0);
	glColor3f(0, 0, 1);
	glVertex3f(0.5, -0.5, 0);
	glEnd();

	//glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.5, -0.5);
	glVertex3f(0.0, 0.5, 0);
	glVertex3f(0.5, -0.5, 0);
	glEnd();

	//glColor3f(0, 1, 1);
	glBegin(GL_POINTS);
	glVertex2f(-0.5, -0.5);
	glVertex3f(0.0, 0.5, 0);
	glVertex3f(0.5, -0.5, 0);
	glEnd();
}

void Shape::DrawGrid()
{
	glLineWidth(1);

	float xi = Xmin;
	float yi = Ymin;
	float ncells = 20.0;

	float cell = (Xmax - Xmin )/ ncells;
	
	glPointSize(10);
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2f(Xmin, Ymin);
	glVertex2f(Xmin, Ymax);
	glVertex2f(Xmax, Ymin);
	glVertex2f(Xmax, Ymax);
	glEnd();

	glColor3f(0.8, 0.8, 0.8);
	for (int i = 0; i < ncells; i++)
	{
		for (int j = 0; j < ncells; j++)
		{
			
			glBegin(GL_LINE_LOOP);
			glVertex2f(xi + cell*j, yi + cell*i);
			glVertex2f(xi + cell*(j+1), yi + cell*i);
			glVertex2f(xi + cell*(j + 1), yi + cell*(i+1));
			glVertex2f(xi + cell*j, yi + cell*(i+1));
			glEnd();
		}
	}

}



void Shape::DesenhaBonco() {

	glColor3f(0.5, 0.5, 0.5);

	glBegin(GL_QUADS);
	glVertex2f(8, 17);
	glVertex2f(14, 17);
	glVertex2f(14, 11);
	glVertex2f(8, 11);
	glEnd();


	glBegin(GL_TRIANGLES);
	glVertex2f(8, 17);
	glVertex2f(8, 11);
	glVertex2f(6, 14);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(14, 17);
	glVertex2f(16, 14);
	glVertex2f(14, 11);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_QUADS);
	glVertex2f(2, 10);
	glVertex2f(2, 8);
	glVertex2f(7, 8);
	glVertex2f(7, 10);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(15, 10);
	glVertex2f(15, 8);
	glVertex2f(20, 8);
	glVertex2f(20, 10);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(10, 3);
	glVertex2f(10, 0);
	glVertex2f(6, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(12, 3);
	glVertex2f(12, 0);
	glVertex2f(16, 0);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);

	glBegin(GL_TRIANGLES);
	glVertex2f(8, 10);
	glVertex2f(8, 3);
	glVertex2f(7, 3);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(14, 10);
	glVertex2f(14, 3);
	glVertex2f(15, 3);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(8, 10);
	glVertex2f(8, 3);
	glVertex2f(14, 3);
	glVertex2f(14, 10);
	glEnd();
}

void Shape::DesenhaHeli() {

	glColor3f(0.0, 0.0, 0.0);


	glBegin(GL_QUADS);
	glVertex2f(17, 15);
	glVertex2f(18, 15);
	glVertex2f(18, 10);
	glVertex2f(17, 10);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(19, 10);
	glVertex2f(25, 11);
	glVertex2f(25, 9);

	glVertex2f(16, 10);
	glVertex2f(10, 11);
	glVertex2f(10, 9);


	glColor3f(0.8, 0.8, 0.8);

	glVertex2f(15, 8);
	glVertex2f(15, 2);
	glVertex2f(4, 8);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(16, 8);
	glVertex2f(26, 7);
	glVertex2f(26, 0);
	glVertex2f(16, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(2, 9);
	glVertex2f(3, 9);
	glVertex2f(4, 8);
	glVertex2f(3, 7);
	glVertex2f(2, 7);
	glVertex2f(1, 8);
	glVertex2f(2, 9);

	glEnd();

}

void Shape::DesenhaCami() {

	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_QUADS);
	glVertex2f(8, 13);
	glVertex2f(11, 13);
	glVertex2f(11, 10);
	glVertex2f(8, 10);

	glColor3f(1.0, 1.0, 0.0);

	glVertex2f(12, 13);
	glVertex2f(12, 10);
	glVertex2f(19, 10);
	glVertex2f(19, 13);

	glColor3f(0.0, 0.3, 0.0);

	glVertex2f(2, 10);
	glVertex2f(2, 4);
	glVertex2f(22, 4);
	glVertex2f(22, 10);

	glColor3f(0.3, 0.7, 0.0);


	glVertex2f(23, 15);
	glVertex2f(33, 13);
	glVertex2f(33, 4);
	glVertex2f(23, 4);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(8, 4);
	glVertex2f(12, 4);
	glVertex2f(14, 2);
	glVertex2f(12, 0);
	glVertex2f(8, 0);
	glVertex2f(6, 2);
	glVertex2f(8, 4);
	glEnd();


	glBegin(GL_LINE_LOOP);
	glVertex2f(26, 4);
	glVertex2f(30, 4);
	glVertex2f(32, 2);
	glVertex2f(30, 0);
	glVertex2f(26, 0);
	glVertex2f(24, 2);
	glVertex2f(26, 4);
	glEnd();
}

void Shape::DesenhaGato() {

	glColor3f(0.0, 1.0, 0.0);

	glBegin(GL_QUADS);
	glVertex2f(11, 8);
	glVertex2f(16, 8);
	glVertex2f(16, 1);
	glVertex2f(11, 1);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_QUADS);
	glVertex2f(12, 13);
	glVertex2f(13, 13);
	glVertex2f(13, 11);
	glVertex2f(12, 11);

	glVertex2f(14, 13);
	glVertex2f(15, 13);
	glVertex2f(15, 11);
	glVertex2f(14, 11);

	glVertex2f(10, 3);
	glVertex2f(11, 3);
	glVertex2f(11, 1);
	glVertex2f(10, 1);

	glVertex2f(16, 3);
	glVertex2f(17, 3);
	glVertex2f(17, 1);
	glVertex2f(16, 1);

	glColor3f(0.0, 0.3, 0.0);

	glVertex2f(11, 5);
	glVertex2f(13, 5);
	glVertex2f(13, 1);
	glVertex2f(11, 1);

	glVertex2f(14, 5);
	glVertex2f(16, 5);
	glVertex2f(16, 1);
	glVertex2f(14, 1);

	glEnd();

	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_TRIANGLES);
	glVertex2f(12.5, 10);
	glVertex2f(14.5, 10);
	glVertex2f(13.5, 9);


	glVertex2f(12.5, 10);
	glVertex2f(14.5, 10);
	glVertex2f(13.5, 9);

	glVertex2f(11, 17);
	glVertex2f(13, 14);
	glVertex2f(11, 14);

	glVertex2f(16, 17);
	glVertex2f(16, 14);
	glVertex2f(14, 14);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(11, 14);
	glVertex2f(16, 14);
	glVertex2f(19, 11);
	glVertex2f(16, 8);
	glVertex2f(11, 8);
	glVertex2f(8, 11);
	glVertex2f(11, 14);
	glEnd();

	glBegin(GL_LINE_LOOP);

	glVertex2f(16, 4.5);
	glVertex2f(21, 4.5);
	glVertex2f(22, 2.5);
	glVertex2f(21, 1.5);
	glVertex2f(20, 3.5);
	glVertex2f(16, 3.5);
	glVertex2f(16, 4.5);

	glEnd();
}

void Shape::desenhaPlanta()

{
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINE_STRIP);
	glVertex2f(18, 14);
	glVertex2f(25, 14);
	glVertex2f(25, 0);
	glVertex2f(0, 0);
	glVertex2f(0, 14);
	glVertex2f(8, 14);

	glEnd();

	glBegin(GL_LINES);
	glVertex2f(13, 14);
	glVertex2f(13, 0);
	glEnd();

	
	glBegin(GL_LINE_STRIP);

	glVertex2f(6, 14);
	glVertex2f(6, 24);
	glVertex2f(21, 24);
	glVertex2f(21, 19);
	
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(21, 24);
	glVertex2f(21, 35);
	glVertex2f(35, 35);
	glVertex2f(35, 9);
	glVertex2f(25, 9);

	glEnd();
}

void Shape::desenhaCama()
{

	glColor3f(0.8, 0.92,1);

	glBegin(GL_QUADS);
	glVertex2f(0, 9);
	glVertex2f(6, 9);
	glVertex2f(6, 0);
	glVertex2f(0, 0);

	glColor3f(1, 0.95, 0.9);
	glVertex2f(0, 9);
	glVertex2f(6, 9);
	glVertex2f(5, 7);
	glVertex2f(0, 7);

	glEnd();

	glColor3f(1, 1, 1);

	glBegin(GL_LINES);
	glVertex2f(1, 0);
	glVertex2f(1, 7);
	glVertex2f(2, 0);
	glVertex2f(2, 7);
	glVertex2f(3, 0);
	glVertex2f(3, 7);
	glVertex2f(4, 0);
	glVertex2f(4, 7);
	glVertex2f(5, 0);
	glVertex2f(5, 7);

	glColor3f(0.8, 0.92, 1);
	glVertex2f(6, 9);
	glVertex2f(0, 9);
	glVertex2f(0, 9);
	glVertex2f(0, 0);

	glEnd();


}

void Shape::desenhaArm() {
	glColor3f(0.6, 0.3, 0);


	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glVertex2f(0, 4);
	glVertex2f(12, 4);
	glVertex2f(12, 0);
	glEnd();

	glColor3f(0.3, 0.14, 0);

	glBegin(GL_LINES);
	glVertex2f(4, 0);
	glVertex2f(4, 4);
	glVertex2f(8, 0);
	glVertex2f(8, 4);
	glEnd();
	
}

void Shape::desenhaMPC() {
	glColor3f(1,0.65, 0.3);


	glBegin(GL_QUADS);
	glVertex2f(0, 2);
	glVertex2f(0, 6);
	glVertex2f(8, 6);
	glVertex2f(8, 2);

	glVertex2f(8, 6);
	glVertex2f(10, 6);
	glVertex2f(10, 0);
	glVertex2f(8, 2);

	glVertex2f(10, 6);
	glVertex2f(15, 6);
	glVertex2f(15, 0);
	glVertex2f(10, 0);

	glColor3f(1, 0.8, 0.8);

	glVertex2f(11, 5);
	glVertex2f(13, 5);
	glVertex2f(13, 2);
	glVertex2f(11, 2);

	glColor3f(0.85, 1, 0.8);

	glVertex2f(12, 4);
	glVertex2f(14, 4);
	glVertex2f(14, 1);
	glVertex2f(12, 1);

	glColor3f(0, 0, 0);

	glVertex2f(2, 2);
	glVertex2f(5, 2);
	glVertex2f(5, 1);
	glVertex2f(2, 1);

	glColor3f(0.3, 0.3, 0.3);

	glVertex2f(2, 0);
	glVertex2f(5, 0);
	glVertex2f(5, 1);
	glVertex2f(2, 1);

	glEnd();

}

void Shape::desenhaTV() {

	glColor3f(0.48, 0.25, 0.01);


	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glVertex2f(0, 7);
	glVertex2f(2.5, 7);
	glVertex2f(2.5, 0);

	glColor3f(0.3, 0.3, 0.3);
	glVertex2f(2, 6);
	glVertex2f(2, 1);
	glVertex2f(0.5, 2);
	glVertex2f(0.5, 5);

	glColor3f(0, 0, 0);
	glVertex2f(2, 6);
	glVertex2f(3, 6);
	glVertex2f(3, 1);
	glVertex2f(2, 1);

	glEnd();
}

void Shape::desenhaSofa() {

	glColor3f(0.97, 0.02, 0.02);
	glBegin(GL_QUADS);

	glVertex2f(0, 0);
	glVertex2f(0, 5);
	glVertex2f(5, 5);
	glVertex2f(5, 0);

	glColor3f(0.48, 0.01, 0.01);

	glVertex2f(0, 5);
	glVertex2f(5, 5);
	glVertex2f(4.7, 3);
	glVertex2f(0.3, 3);

	glEnd();
}

void Shape::desenhaMesa() {

	glColor3f(0.9, 1, 1);

	glBegin(GL_POLYGON);
	glVertex2f(2, 3);
	glVertex2f(2, 6);
	glVertex2f(3, 7);
	glVertex2f(12, 7);
	glVertex2f(13, 6);
	glVertex2f(13, 3);
	glVertex2f(12, 2);
	glVertex2f(3, 2);
	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.72, 0.27, 0.72);

	glVertex2f(4, 7);
	glVertex2f(6, 7);
	glVertex2f(6, 8);
	glVertex2f(4, 8);

	glVertex2f(9, 7);
	glVertex2f(11, 7);
	glVertex2f(11, 8);
	glVertex2f(9, 8);

	glVertex2f(13, 5.5);
	glVertex2f(14, 5.5);
	glVertex2f(14, 3.5);
	glVertex2f(13, 3.5);

	glVertex2f(9, 2);
	glVertex2f(11, 2);
	glVertex2f(11, 1);
	glVertex2f(9, 1);

	glVertex2f(4, 2);
	glVertex2f(6, 2);
	glVertex2f(6, 1);
	glVertex2f(4, 1);

	glVertex2f(1, 5.5);
	glVertex2f(2, 5.5);
	glVertex2f(2, 3.5);
	glVertex2f(1, 3.5);

	glEnd();

}

void Shape::desenhaTapete() {

	glColor3f(0.27, 0.27, 0.72);

	glBegin(GL_QUADS);

	glVertex2f(0, 0);
	glVertex2f(0, 9);
	glVertex2f(9, 9);
	glVertex2f(9, 0);

	glColor3f(0.27, 0.5, 0.72);

	glVertex2f(1, 1);
	glVertex2f(1, 8);
	glVertex2f(8, 8);
	glVertex2f(8, 1);

	glColor3f(0.27, 0.72, 0.72);

	glVertex2f(2, 2);
	glVertex2f(2, 7);
	glVertex2f(7, 7);
	glVertex2f(7, 2);

	glEnd();


}