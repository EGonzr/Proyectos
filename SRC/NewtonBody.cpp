//Necesitamos heredar los valores de NewtonBody.h
#include "NewtonBody.h"

void Body::DisplayInfo()
{
	cout << "Masa: " << mass << endl;
	cout << "Posicion: ", position.display(); //Para mostrar en patalla la info
	cout << "Velocidad: ", velocity.display();
}

void Body::addForce(const Vec2& f)
{

	force += f; //Lo utilizaremos para recoger el valor de la fuerza

}