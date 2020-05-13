//Este .h hereda los valores de NewtonMath.h y NewtonBody.h

#include "NewtonBody.h"

struct World //Se encarga de hacer las iteraciones necesarias para la solucion
{

	//Constructores
	World() {}; //Valor predeterminado de la gravedad
	World(Vec2 gravity) : gravity(gravity) {};

	//Establecer gravedad
	void setGravity(const Vec2& v);

	//Creacion del cuerpo
	void addBody(Body* b);

	//Proceso de simulacion 
	void Step(float dt);

	Vec2 gravity;
	vector<Body*> bodies;

};

