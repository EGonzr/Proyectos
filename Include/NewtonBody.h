//Este .h hereda los valores de NewtonMath.h

#include "NewtonMath.h"

struct Body
{
public:

	//Constructores
	Body() {} //Valor predeterminado 

	//Mostrar información del cuerpo
	void DisplayInfo();

	//Aplicación de fuerzas
	void addForce(const Vec2& f);

	float mass;
	float invMass = 1 / mass;
	Vec2 position;
	Vec2 velocity;
	Vec2 force = Vec2(0.0f, 0.0f);
};
