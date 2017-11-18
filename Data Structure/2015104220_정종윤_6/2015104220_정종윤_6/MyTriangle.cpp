#include "MyTriangle.h"


MyTriangle::MyTriangle()
{
	this->attribute = 1;
}


MyTriangle::~MyTriangle()
{
}

void MyTriangle::Draw()
{
	for (int i = 0; i < 3; i++) 
	{
		cout << "Input Vertex " << i << "'s (x,y) : ";
		cin >> vertex[i]; // 세 꼭지점 입력
	}

	area = (double)((vertex[0].x * vertex[1].y + vertex[1].x * vertex[2].y + vertex[2].x * vertex[0].y) - (vertex[1].x*vertex[0].y + vertex[2].x * vertex[1].y + vertex[0].x * vertex[2].y)) / 2;
	if (area <= 0)
		area = -area;
}

void MyTriangle::Display()
{
	cout << "\tTriangle" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Vertex " << i << " : " << vertex[i] << endl; //Vertex 출력
	}
	cout << "Area : " << area << endl; // Area 출력
}
