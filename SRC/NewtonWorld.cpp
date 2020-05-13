#include "NewtonWorld.h"

void World::setGravity(const Vec2& v)
{
	gravity = v; //Para agregar el valor de la gravedad
}

void World::addBody(Body* b)
{

	bodies.push_back(b); //Va agregando elementos al vector bodies

}

void World::Step(float dt) //Parte importante
{

	if ((int)bodies.size() == 0) { cout << "No hay nada en este mundo." << endl; system("pause"); }

	for (int i = 0; i < (int)bodies.size(); i++) //Integrador de fuerza
	{

		bodies[i]->velocity += dt * (gravity + bodies[i]->invMass * bodies[i]->force);

	}

	for (int i = 0; i < (int)bodies.size(); i++) //Integrador de velocidad
	{

		bodies[i]->position += dt * bodies[i]->velocity;
		bodies[i]->force = Vec2(0.0f, 0.0f);

	}

}