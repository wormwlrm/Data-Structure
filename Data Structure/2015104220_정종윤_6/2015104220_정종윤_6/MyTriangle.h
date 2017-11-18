#pragma once
#include "MyBase.h"
#include <cmath>

/**
*	@brief	Triangle class
*/
class MyTriangle : public MyBase
{
public:
	MyTriangle();
	~MyTriangle();

	/**
	*	@brief	funtion that get coordinate
	*/
	void Draw();

	/**
	*	@brief	funtion that display items
	*/
	void Display();

private:
	Point vertex[3];	//≤¿¡ˆ¡°
};

