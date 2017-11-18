#include "MyRectangle.h"


MyRectangle::MyRectangle()
{
	this->attribute = 0;
}


MyRectangle::~MyRectangle()
{
}

void MyRectangle::Draw()
{
	
	cout << "Input Vertex 1's (x,y) : ";
	cin >> vertex[0]; //Vertex 1 �Է�

	cout << "Input Vertex 2's (x,y) : ";
	cin >> vertex[1]; //Vertex 2 �Է�

	this->area = abs((vertex[1].x) - (vertex[0].x)) * ((vertex[1].y) - (vertex[0].y));
}

void MyRectangle::Display()
{
	cout << "\tRectangle" << endl;
	cout << "Vertex 1 : " << vertex[0] << endl; //Vertex 1 ���
	cout << "Vertex 2 : " << vertex[1] << endl; //Vertex 2 ���
	cout << "Area : " << area << endl; //Area �Է�
}
