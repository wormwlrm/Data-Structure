#pragma once
#include "Point.h"

/**
*	@brief	virtual class that used for inheriting
*/
class MyBase
{
public:
	/**
	*	@brief	pure virtual funtion that get coordinate
	*/
	virtual void Draw() = 0;

	/**
	*	@brief	pure virtual funtion that display items
	*/
	virtual void Display() = 0;

protected:
	int attribute;	// 도형 속성
	double area;	// 도형 넓이
};