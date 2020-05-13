#pragma once //Se utiliza para prevenir la sobreescritura

//Librerias
#include <iostream>
#include <math.h>
#include <vector>

using namespace std; //Para evitar usar std::cout y etc

struct Vec2 //Sus valores son predeterminadamente publicos
{
	//Constructores
	Vec2() {}; //Valor predeterminado del constructor
	Vec2(float x, float y) : x(x), y(y) {};

	//Asignar valores al vector
	void Set(float x_, float y_);

	//Propiedades del vector
	float Length();
	float LengthSquared();
	void display();

	//Operaciones con vectores
	void operator += (const Vec2& v);
	void operator -= (const Vec2& v);

	// & para pasar por referencia, usar los valores que ya tiene vec2 
	float Dot(const Vec2& a, const Vec2& b);  // en alguna parte de la memoria
	float Cross(const Vec2& a, const Vec2& b);
	// const para evitar que cambien el valor de Vec2


	float x, y;

};

inline Vec2 operator * (float k, const Vec2& v)
{
	return Vec2(k * v.x, k * v.y);
}

inline Vec2 operator + (Vec2 v1, Vec2 v2)
{
	return Vec2(v1.x + v2.x, v1.y + v2.y);
}