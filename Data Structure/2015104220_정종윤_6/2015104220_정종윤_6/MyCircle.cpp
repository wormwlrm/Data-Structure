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
	cin >> vertex; //Vertex �Է�
		
	cout << "Input radius : ";
	cin >> radius; //Radius �Է�

	this->area = pow(radius, 2) * 3.141592;
}

void MyCircle::Display()
{
	cout << "\tCircle" << endl;
	cout << "Vertex : " << vertex << endl; //Vertex ���
	cout << "Radius : " << radius << endl; //Radius ���
	cout << "Area : " << area << endl; //Area ���
}