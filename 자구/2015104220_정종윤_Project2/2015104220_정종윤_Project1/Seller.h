#pragma once
#include "Product.h"
#include "SortedLinkedList.h"
#include <string>
using namespace std;

class Seller
{
public:
	/**
	*	�⺻ ������
	*/
	Seller();

	/**
	*	�Ҹ���
	*/
	~Seller();

	/**
	*	@brief	��ȣ ����
	*	@pre	
	*	@post	�Է¹��� ��ȣ�� ����
	*	@param	data	������ ��ȣ ��
	*/
	void setCompany(string _Company);
	/**
	*	@brief	����� ��� ��ȣ ����
	*	@pre
	*	@post	�Է¹��� ����� ��� ��ȣ�� ����
	*	@param	data	������ ����� ��� ��ȣ
	*/
	void setRegistrationNumber(string _RegistrationNumber);
	/**
	*	@brief	�̸� ����
	*	@pre
	*	@post	�̸����� ����
	*	@param	data	������ �̸�
	*/
	void setName(string _Name);
	/**
	*	@brief	����ó ����
	*	@pre
	*	@post	�Է¹��� ����ó�� ����
	*	@param	data	������ ����ó
	*/
	void setPhoneNumber(string _PhoneNumber);
	/**
	*	@brief	�Ǹ��� ��� ����
	*	@pre
	*	@post	�Է¹��� �Ǹ��� ��޷� ����
	*	@param	data	������ �Ǹ��� ��� ��
	*/
	void setGrade(int _Grade);

	/**
	*	@brief	�Ǹ��� ����Ʈ�� �߰�
	*	@pre
	*	@post	�Ǹ��� ����Ʈ�� ��ǰ�� �߰���
	*	@param	data	�߰��� ��ǰ
	*/
	void setSellerProducts(Product* _Product);

	/**
	*	@brief	�Ǹ��� ����
	*	@pre
	*	@post	�Է¹��� ������ ����
	*	@param	data	������ ��ȣ ��, ����� ��Ϲ�ȣ, �̸�, ����ó, �Ǹ��� ���
	*/
	void setSeller(string _Company, string _RegistrationNumber, string _Name, string _PhoneNumber, int _Grade);

	/**
	*	@brief	�� �Ǹ� �ݾ� ����
	*	@pre
	*	@post	�Է¹��� �Ǹ� �ݾ��� ����
	*	@param	data	�߰��� �ݾ�
	*/
	void setTotalCost(int _TotalCoast);
	
	/**
	*	@brief	��ȣ ��ȯ
	*	@pre	
	*	@post	��ȣ ��ȯ
	*/
	string getCompany();

	/**
	*	@brief	����� ��� ��ȣ ��ȯ
	*	@pre
	*	@post	����� ��� ��ȣ ��ȯ
	*/
	string getRegistrationNumber();

	/**
	*	@brief	�̸� ��ȯ
	*	@pre
	*	@post	�̸� ��ȯ
	*/
	string getName();

	/**
	*	@brief	����ó ��ȯ
	*	@pre
	*	@post	����ó ��ȯ
	*/
	string getPhoneNumber();

	/**
	*	@brief	�Ǹ� ��� ��ȯ
	*	@pre
	*	@post	�Ǹ� ��� ��ȯ
	*/
	int getGrade();

	/**
	*	@brief	�� �Ǹ� �ݾ� ��ȯ
	*	@pre
	*	@post	�� �Ǹ� �ݾ� ��ȯ
	*/
	int getTotalCost();

	/**
	*	@brief	��ǰ ����Ʈ�� ���
	*	@pre
	*	@post	��ǰ ����Ʈ�� ���
	*/
	void printProductList();

	/**
	*	@brief	�Ǹ��� == ������ �����ε�
	*/
	bool operator==(const Seller data);

	/**
	*	@brief	�Ǹ��� >= ������ �����ε�
	*/
	bool operator>=(const Seller data);

	/**
	*	@brief	�Ǹ��� <= ������ �����ε�
	*/
	bool operator<=(const Seller data);	

private:
	string s_Company; // ��ȣ��
	string s_RegistrationNumber; // ����� ��� ��ȣ
	string s_Name; // �̸�
	string s_PhoneNumber; // ����ó
	int s_Grade; // �Ǹ� ���
	LinkedList<Product*> m_ProductList; // �Ǹ��ϴ� ��ǰ ��ũ�� ����Ʈ
	int s_TotalCost; // �� �Ǹ� �ݾ�
};

