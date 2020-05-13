#include <SFML/Graphics.hpp>
#include "NewtonWorld.h"
using namespace sf;
int main()
{

	RenderWindow window(VideoMode(800, 600), "Proyecto #1: Caminar, Correr y Saltar"); //Tamaño de la pantalla

	Event event;
	Clock clock;

	//Declaracion de booleanas
	bool boolSpace = false; 
	bool boolJump = false; 

	// Cargar las sprite para jugador
	Texture lilBoyTex;
	Sprite lilBoySprite;

	//carga el sprite del fondo 
	Texture BackGTex;
	Sprite BackGSprite;

	//ahora lo cargamos 
	if (!BackGTex.loadFromFile("Assets/Sprite/fondo.jpg")) {

		cout << "No se puede encontrar la textura";

	}

	if (!lilBoyTex.loadFromFile("Assets/Sprite/boy.png"))
	{
		cout << "No se puede encontrar la textura" << endl;
		system("pause");
	}


	//sprites y objetos sin movimiento 
	BackGSprite.setTexture(BackGTex);

	//escala
	BackGSprite.setScale(Vector2f(1.0f, 1.0f));

	//Configuramos nuestro mundo
	World w1;
	w1.setGravity(Vec2(0.0f, 450.0f));

	Body b1;
	b1.mass = 2.0f;
	b1.position = Vec2(400.0f, 430.0f); //Posicion inical (x,y)
	b1.velocity = Vec2(0.0f, 0.0f); //Velocidad inicial 

	w1.addBody(&b1);

	//Configurando sprites del niño objeto
	lilBoySprite.setTexture(lilBoyTex);
	lilBoySprite.setScale(Vector2f(2.0f, 2.0f));

	//Colocamos el origen del sprite 
	Rect<float> size = lilBoySprite.getGlobalBounds();
	lilBoySprite.setOrigin(Vector2f(size.width / 2, size.height / 2));

	//Coloca la caja en el centro de la pantalla
	//El sprite usa la misma posición inicial que se le da al cuerpo en la configuración de cuerpo
	lilBoySprite.setPosition(Vector2f(b1.position.x, b1.position.y));

	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
			{

				window.close();

			}

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					boolSpace = true;
					cout << "Se ha apretado espacio" << endl;
				}
			}

			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Space)
				{
					boolSpace = false;
				}
			}

		}

		
		b1.velocity.x = 0.0f;		
		
		if (!boolJump) 
		{
			if (boolSpace)
			{
				
				b1.velocity.y = -250.0f;
				
				boolJump = true;

			}
		}

		if (Keyboard::isKeyPressed(Keyboard::D))
		{
							
			b1.velocity.x = 50.0f;

			cout << "D ha sido apretado, se mueve a la derecha." << endl;

		}		

		if (Keyboard::isKeyPressed(Keyboard::A))
		{

			b1.velocity.x = -50.0f;

			cout << "A ha sido apretado, se mueve a la izquierda." << endl;

		}		

		if ((Keyboard::isKeyPressed(Keyboard::A)) && (Keyboard::isKeyPressed(Keyboard::LShift))) {

			b1.velocity.x = -100.0f;

			cout << "A ha sido apretado, corre hacia la izquierda." << endl;

		}

		if ((Keyboard::isKeyPressed(Keyboard::D)) && (Keyboard::isKeyPressed(Keyboard::LShift))) {

			b1.velocity.x = 100.0f;

			cout << "D ha sido apretado, corre hacia la derecha." << endl;

		}

		

		Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		//Uso el tiempo calculado para usar la función Step() de World w1
		w1.Step(dt);		

		if (b1.position.y >= 430.0f)
		{

			b1.position.y = 430.0f;

			boolJump = false;
		}
		
		lilBoySprite.setPosition(Vector2f(b1.position.x, b1.position.y));

		window.clear(Color::Transparent);
		window.draw(BackGSprite);
		window.draw(lilBoySprite);
		window.display();
		 

	}

	return 0;

}