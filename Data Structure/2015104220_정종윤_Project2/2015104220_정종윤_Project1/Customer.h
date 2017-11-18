#pragma once
#include "Product.h"
#include "SortedLinkedList.h"
#include <string>
using namespace std;

class Customer
{
public:
	/**
	*	�⺻ ������
	*/
	Customer();

	/**
	*	�Ҹ���
	*/
	~Customer();

	/**
	*	@brief	����Ʈ ����
	*	@pre
	*	@post	����Ʈ�� ������
	*	@param	data	������ ����Ʈ
	*/

	void setPoint(int _Point);

	/**
	*	@brief	����Ʈ�� ������
	*	@pre
	*	@post	����Ʈ ��ȯ
	*/
	int getPoint();

	/**
	*	@brief	���̵� ����
	*	@pre
	*	@post	���̵� ������
	*	@param	data	������ ���̵�
	*/
	void setId(string _Id);

	/**
	*	@brief	��й�ȣ ����
	*	@pre
	*	@post	��й�ȣ�� ������
	*	@param	data	������ ��й�ȣ
	*/
	void setPassword(string _Password);

	/**
	*	@brief	�̸� ����
	*	@pre
	*	@post	�̸��� ������
	*	@param	data	������ �̸�
	*/
	void setName(string _Name);

	/**
	*	@brief	��ٱ��Ͽ� ������ �߰���
	*	@pre
	*	@post	��ٱ��ϰ� ������
	*	@param	data	������ ����
	*/
	void setShoppingBasket(Product& _Product);

	/**
	*	@brief	���θ���Ʈ�� ������ �߰���
	*	@pre
	*	@post	���θ���Ʈ�� ������
	*	@param	data	�߰��� ����
	*/
	void setMyShoppingList(Product* _Product);

	/**
	*	@brief	����� ����
	*	@pre
	*	@post	����ڰ� ������
	*	@param	data	����� ���̵�, ��й�ȣ, �̸�, ����Ʈ
	*/
	void setCustomer(string _Id, string _Password, string _Name, int _Point);
	
	/**
	*	@brief	���̵� ��ȯ
	*	@pre
	*	@post	���̵� ��ȯ
	*/
	string getId();

	/**
	*	@brief	��й�ȣ ��ȯ
	*	@pre
	*	@post	��й�ȣ ��ȯ
	*/
	string getPassword();

	/**
	*	@brief	�̸� ��ȯ
	*	@pre
	*	@post	�̸� ��ȯ
	*/
	string getName();

	/**
	*	@brief	���� ��ȯ
	*	@pre
	*	@post	���� ��ȯ
	*/
	int GetLength() const;

	/**
	*	@brief	��ٱ��ϸ� �����
	*	@pre
	*	@post	��ٱ��� ���
	*/
	int printShoppingBasket();

	/**
	*	@brief	���� ����Ʈ�� �����
	*	@pre
	*	@post	���� ����Ʈ ���
	*/
	void PrintMyShoppingList();

	/**
	*	@brief	��ٱ��� ������ ������ ������ ��ȯ
	*	@pre
	*	@post	��ٱ��� ������ ������ ������ ��ȯ
	*	@param	data	����ڰ� ������ ���� ��ȣ
	*/
	Product* PassDummy(int choice);

	/**
	*	@brief	�� == ������ �����ε�
	*/
	bool operator==(const Customer data);

	/**
	*	@brief	�� >= ������ �����ε�
	*/
	bool operator>=(const Customer data);

	/**
	*	@brief	�� <= ������ �����ε�
	*/
	bool operator<=(const Customer data);
	
private:
	string c_Id; // ���̵�
	string c_Password; // ��й�ȣ
	string c_Name; // �̸�
	int c_Point; // ����Ʈ
	LinkedList<Product> c_ShoppingBasket; // ��ٱ��� ��ũ�� ����Ʈ
	LinkedList<Product> c_ShoppingList; // ������ ��ϵ� ��ũ�� ����Ʈ
};


