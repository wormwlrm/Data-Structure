#pragma once
#include "MyBase.h"
#include <cmath>

/**
*	@brief	Rectangle class
*/
class MyRectangle : public MyBase
{
public:
	MyRectangle(); // this->attribute = 0;
	~MyRectangle();

	/**
	*	@brief	funtion that get coordinate and calculate area
	*/
	void Draw();

	/**
	*	@brief	funtion that display items
	*/
	void Display();

private:
	Point vertex[2];	// ²ÀÁþÁ¡
};

