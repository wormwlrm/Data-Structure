#include "MyCircle.h"


MyCircle::MyCircle()
{
	this->attribute = 2;
}


MyCircle::~MyCircle()
{
}

void MyCircle::Draw()
{
	cout << "Input Vertex (x,y) : ";
	cin >> vertex; //Vertex 입력
		
	cout << "Input radius : ";
	cin >> radius; //Radius 입력

	this->area = pow(radius, 2) * 3.141592;
}

void MyCircle::Display()
{
	cout << "\tCircle" << endl;
	cout << "Vertex : " << vertex << endl; //Vertex 출력
	cout << "Radius : " << radius << endl; //Radius 출력
	cout << "Area : " << area << endl; //Area 출력
}