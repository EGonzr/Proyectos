#include <SFML/Graphics.hpp>
#include "NewtonWorld.h"
using namespace sf;
int main()
{

	RenderWindow window(VideoMode(800, 600), "Proyecto #2: Gliding"); //Tamaño de la pantalla

	Event event;
	Clock clock;

	//Declaracion de booleanas
	bool paracaidas = false;

	//movimiento
	bool der = false;
	bool izq = false;

	//start
	bool caer = false;
	
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
	b1.position = Vec2(400.0f, 20.0f); //Posicion inical (x,y)
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
				if (event.key.code == Keyboard::P)
				{
					paracaidas = true;
					cout << "Se abre el paracaidas" << endl;
				}
				
				if (event.key.code == Keyboard::A) {
					izq = true;
					cout << "Mover a la izquierda" << endl;
				}

				if (event.key.code == Keyboard::D) {
					der = true;
					cout << "Mover a la derecha" << endl;
				}
				if (event.key.code == Keyboard::Enter) {
					caer = true;
				}
			}

			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::P)
				{
					paracaidas = false;

				}
				if (event.key.code == Keyboard::A) {
					izq = false;
					cout << "No se mueve" << endl;
				}

				if (event.key.code == Keyboard::D) {
					der = false;
					cout << "No se mueve" << endl;
				}

				
			}
		}

		//paracaidas
		if (paracaidas) {
			b1.velocity.y = -1.0f;
		}

		//movimiento
		if (izq) {
			b1.velocity.x = -50.0f;
		}

		if (der) {
			b1.velocity.x = 50.0f; 
		}
			
		Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		//Uso el tiempo calculado para usar la función Step() de World w1
		if (caer) {

			w1.Step(dt);
		}
		
		
		if (b1.position.y >= 430.0f)
		{

			b1.position.y = 430.0f;
			
		}

		lilBoySprite.setPosition(Vector2f(b1.position.x, b1.position.y));

		window.clear(Color::Transparent);
		window.draw(BackGSprite);
		window.draw(lilBoySprite);
		window.display();

	}

	return 0;

}