//*****************************************************
//
// Projeto com diferentes viewports
//
//
// Projeto disponibilizado por Vini Cassol - 22/08/2019
// 
//*****************************************************

#include <cstdlib>
#include <iostream>
#include "Shapes.h" //é a Shapes que está incluindo a glfw!

#define NVIEWPORTS 2  //vai gerar NVIEWPORTS x NVIEWPORTS, na verdade

using namespace std;

Shape shape; //objeto da classe shape



//Protótipos de algumas funções (para não se preocupar com a ordem)
void ajustaCamera2D(int width, int height);


//Callback de erro 
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

//Callback de teclado

//Variaveis globais para controle do teclado
bool drawCircle = false; //flag para habilitar o desenho de círculos (apenas um exemplo)
bool oneview = false;
bool twoview = false;
bool nineview = false;

bool escalar = false;
bool change = false;


int xs,ys,xt,yt;
float cor[3];
float r, g, b;



int width, height;
float ratio;



int randonEscala() {

	return rand() % 10;
}

int randonPosic() {

	return rand() % 10 - 5;

}

float randonColor() {

	
	return (rand() % 10) / 10.0;

}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	int i;
	//Mapeamento de teclas na GLFW: https://www.glfw.org/docs/latest/group__keys.html

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_Q && action == GLFW_PRESS)
	{

		

		xs = randonEscala();
		ys = randonEscala();
		xt = randonPosic();
		yt = randonPosic();
		r = randonColor();
		g = randonColor();
		b = randonColor();

		escalar = true;
	}
	
}

//Callback de redimensionamento
void reshape(GLFWwindow* window, int width, int height)
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (height == 0)
		height = 1;

	ajustaCamera2D(width,height);

}

void ajustaCamera2D(int width, int height)
{
	//Ativa a matriz de projeção --> conceitos mais tarde!!
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (width < height) //altura menor que largura
	{
		float aspecto = (float)height / width; //proporcao altura/largura 
		gluOrtho2D(Xmin, Xmax, Ymin*aspecto, Ymax*aspecto); //corrige a proporção na largura
	}
	else {
		float aspecto = (float)width / height; //proporcao largura/altura
		gluOrtho2D(Xmin*aspecto, Xmax*aspecto, Ymin, Ymax); //corrige a proporção na altura

	}
}



// Programa Principal 
int main(void)
{
	srand(time(NULL));

	//Inicialização da janela da aplicação
	GLFWwindow* window;

	//Setando a callback de erro
	glfwSetErrorCallback(error_callback);

	//Inicializando a lib
	if (!glfwInit())
		exit(EXIT_FAILURE);

	//Criando a janela
	window = glfwCreateWindow(1000, 1000, "Viewports Example Code!!!", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Colocando a janela criada como sendo o contexto atual
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	//Setando a callback de teclado
	glfwSetKeyCallback(window, key_callback);

	//Setando a callback de reshape
	glfwSetFramebufferSizeCallback(window, reshape);

	ajustaCamera2D(1000, 1000);

	while (!glfwWindowShouldClose(window)) //loop da aplicação :)
	{	

		//aqui recupera o tamanho atual da janela
		glfwGetFramebufferSize(window, &width, &height);

		// Limpa a janela de visualização com a cor branca
		glClearColor(1, 1, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		//seta a matriz de modelo 
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		if (escalar)
		{
			glScalef(xs, ys, 1);

			glTranslatef(xt, yt, 0);

			shape.DrawTriangle(r,g,b);

			glScalef(-xs, -ys, 1);

			glTranslatef(-xt, -yt, 0);

		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);

	return 0;
}
