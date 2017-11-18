#include "Customer.h"


Customer::Customer()
{
	c_Point = 0;
}

Customer::~Customer()
{
	c_ShoppingList.MakeEmpty(); // ���� ����Ʈ ����
	c_ShoppingBasket.MakeEmpty(); // ��ٱ��� ����
}

void Customer::setId(string _Id)
{
	c_Id = _Id; // ���̵� ����
}
void Customer::setPassword(string _Password)
{
	c_Password = _Password; // ��й�ȣ ����
}
void Customer::setName(string _Name)
{
	c_Name = _Name; // �̸� ����
}
void Customer::setShoppingBasket(Product& _Product)
{
	c_ShoppingBasket.Add(_Product); // ��ٱ��� ����Ʈ�� �߰�
}
void Customer::setMyShoppingList(Product* _Product)
{
	c_ShoppingList.Add(*_Product); // ���� ����Ʈ�� �߰�
	int temp = _Product->getStock(); 
	_Product->setStock(temp - 1); // ��� 1��ŭ ����
}

void Customer::setCustomer(string _Id, string _Password, string _Name, int _Point)
{
	c_Id = _Id; // �� ����
	c_Password = _Password;
	c_Name = _Name;
	c_Point = _Point;
}

string Customer::getId()
{
	return c_Id;
}
string Customer::getPassword()
{
	return c_Password;
}
string Customer::getName()
{
	return c_Name;
}

void Customer::setPoint(int _Point)
{
	c_Point = _Point;
}

int Customer::getPoint()
{
	return c_Point;
}

bool Customer::operator==(const Customer data)
{
	if (this->c_Id == data.c_Id)
		return true;
	else
		return false;
}
bool Customer::operator>=(const Customer data)
{
	if (this->c_Id >= data.c_Id)
		return true;
	else
		return false;
}

bool Customer::operator<=(const Customer data)
{
	if (this->c_Id <= data.c_Id)
		return true;
	else
		return false;
}

int Customer::printShoppingBasket()
{
	Product data;
	cout << "��������������������������������������" << endl;
	cout << "   ��ٱ��� ����Ʈ " << endl;
	cout << "��������������������������������������" << endl;
	cout << " ��ǰ��        ����   ��� " << endl;
	cout << "��������������������������������������" << endl;
	c_ShoppingBasket.ResetList(); // ��ٱ��� ������ �ʱ�ȭ
	Product *Dummy = new Product();
	for (int j = 0; j < c_ShoppingBasket.GetLength(); j++) // ��ٱ��� ���̸�ŭ �ݺ�
	{
		c_ShoppingBasket.GetNextItem(*Dummy); // ���� �������� ����Ŵ
		cout << j + 1; Dummy->printProductDisplay(); 
	}
	if (c_ShoppingBasket.GetLength() == 0) // ���̰� 0�� ���
	{
		cout << "��ǰ�� �������� �ʽ��ϴ�." << endl;
		cout << "��������������������������������������" << endl;
		return NULL;
	}
	return 0;
}

Product* Customer::PassDummy(int command)
{
	if (command == 0) // 0 �Է� ���� ���
	{
		return NULL;
	}
	Product* Dummy = new Product();
	c_ShoppingBasket.ResetList();
	for (int k = 0; k < command; k++) // command��ŭ �ݺ�
	{
		c_ShoppingBasket.GetNextItem(*Dummy);
	}
	Dummy->printProductInfo(); // ���� Dummy�� ���� ���
	cout << "��������������������������������������" << endl;

	return Dummy; 
}


void Customer::PrintMyShoppingList()
{
	Product data;
	cout << "��������������������������������������" << endl;
	cout << "   ������ ���� ����Ʈ " << endl;
	cout << "��������������������������������������" << endl;
	if (c_ShoppingList.GetLength() == 0) // ���� ����Ʈ ���̰� 0�� ��� ���� ó��
	{
		cout << "��ǰ�� �������� �ʽ��ϴ�." << endl;
		cout << "��������������������������������������" << endl;
		return;
	}
	c_ShoppingList.ResetList();
	for (int i = 0; i < c_ShoppingList.GetLength(); i++) // ���� ����Ʈ ���̸�ŭ �ݺ�
	{
		c_ShoppingList.GetNextItem(data); // ���� ������ ����Ŵ
		data.printProductShoppingList(); // data�� ���� ���
	}
}

