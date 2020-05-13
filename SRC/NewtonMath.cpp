#include "NewtonMath.h"

void Vec2::Set(float x_, float y_) {

	x = x_;
	y = y_;  //Valores del vector

}

float Vec2::Length()
{
	return sqrt(x * x + y * y);
}

float Vec2::LengthSquared()
{
	return x * x + y * y;
}

void Vec2::display()
{

	cout << "El vector es (" << x << ", " << y << ")" << endl;  //Mostrar el vector

}

void Vec2::operator+=(const Vec2& v)
{
	x += v.x;
	y += v.y;  //Suma

}

void Vec2::operator-=(const Vec2& v)
{
	x -= v.x;
	y -= v.y; //Resta

}

float Vec2::Dot(const Vec2& a, const Vec2& b)
{
	return a.x * b.x + a.y * b.y; //Multiplicacion de punto

}

float Vec2::Cross(const Vec2& a, const Vec2& b)
{
	return a.x * b.y - a.y * b.x; //Multiplicacion cruz

}