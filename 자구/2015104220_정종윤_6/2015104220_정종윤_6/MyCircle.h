#pragma once
#include "MyBase.h"
#include <cmath>

/**
*	@brief	Circle class
*/
class MyCircle : public MyBase
{
public:
	MyCircle();
	~MyCircle();

	/**
	*	@brief	funtion that get coordinate
	*/
	void Draw();

	/**
	*	@brief	funtion that display items
	*/
	void Display();

private:
	Point vertex;	//중점
	int radius;		//반지름
};

