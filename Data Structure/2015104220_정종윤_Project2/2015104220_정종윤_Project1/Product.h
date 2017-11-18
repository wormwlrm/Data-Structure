#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Product
{
public:
	/**
	*	�⺻ ������
	*/
	Product();

	/**
	*	�Ҹ���
	*/
	~Product();

	/**
	*	@brief	��з� ī�װ� ����
	*	@pre
	*	@post	��з� ī�װ��� ������
	*	@param	data	������ ī�װ�
	*/
	void setCategoryLarge(string _CategoryLarge);

	/**
	*	@brief	�ߺз� ī�װ� ����
	*	@pre
	*	@post	�ߺз� ī�װ��� ������
	*	@param	data	������ ī�װ�
	*/
	void setCategoryMiddle(string _CategoryMiddle);

	/**
	*	@brief	�Һз� ī�װ� ����
	*	@pre
	*	@post	�Һз� ī�װ��� ������
	*	@param	data	������ ī�װ�
	*/
	void setCategorySmall(string _CategorySmall);

	/**
	*	@brief	�̸� ����
	*	@pre
	*	@post	�̸��� ������
	*	@param	data	������ �̸�
	*/
	void setName(string _Name);

	/**
	*	@brief	��ȣ ����
	*	@pre
	*	@post	��ȣ�� ������
	*	@param	data	������ ��ȣ
	*/
	void setSeller(string _Seller);

	/**
	*	@brief	���� ����
	*	@pre
	*	@post	������ ������
	*	@param	data	������ ����
	*/
	void setPrice(int _Price);

	/**
	*	@brief	��� ����
	*	@pre
	*	@post	��� ������
	*	@param	data	������ ���
	*/
	void setStock(int _Stock);

	/**
	*	@brief	�̹��� ����
	*	@pre
	*	@post	�̹����� ������
	*	@param	data	������ �̹���
	*/
	void setImage(string _Image);

	/**
	*	@brief	��ǰ ����
	*	@pre
	*	@post	��ǰ�� ������
	*	@param	data	������ ��з�, �ߺз�, �Һз� ī�װ�, �̸�, ��ȣ, ����, ���, �̹���
	*/
	void setProduct(string _CategoryLarge, string _CategoryMiddle, string _CategorySmall,
		string _Name, string _Seller, int _Price, int _Stock, string _Image);

	/**
	*	@brief	��з� ī�װ� ��ȯ
	*	@pre
	*	@post	��з� ī�װ� ��ȯ
	*/
	string getCategoryLarge();

	/**
	*	@brief	�ߺз� ī�װ� ��ȯ
	*	@pre
	*	@post	�ߺз� ī�װ� ��ȯ
	*/
	string getCategoryMiddle();
	
	/**
	*	@brief	�Һз� ī�װ� ��ȯ
	*	@pre
	*	@post	�Һз� ī�װ� ��ȯ
	*/
	string getCategorySmall();

	/**
	*	@brief	��ǰ�� ��ȯ
	*	@pre
	*	@post	��ǰ�� ��ȯ
	*/
	string getName();

	/**
	*	@brief	�Ǹ��� ��ȯ
	*	@pre
	*	@post	�Ǹ��� ��ȯ
	*/
	string getSeller();

	/**
	*	@brief	���� ��ȯ
	*	@pre
	*	@post	���� ��ȯ
	*/
	int getPrice();

	/**
	*	@brief	��� ��ȯ
	*	@pre
	*	@post	��� ��ȯ
	*/
	int getStock();

	/**
	*	@brief	�̹��� ��ȯ
	*	@pre
	*	@post	�̹��� ��ȯ
	*/
	string getImage();

	/**
	*	@brief	��ǰ�� ���������� �����
	*	@pre
	*	@post	���� ���
	*/
	void printProductDisplay();

	/**
	*	@brief	��ǰ�� �ڼ��� ������ �����
	*	@pre
	*	@post	���� ���
	*/
	void printProductInfo();

	/**
	*	@brief	�Ǹŵ� ���� ����Ʈ�� �����
	*	@pre
	*	@post	���� ���
	*/
	void printProductShoppingList();

	/**
	*	@brief	��ǰ == ������ �����ε�
	*/
	bool operator==(const Product data);

	/**
	*	@brief	��ǰ >= ������ �����ε�
	*/
	bool operator>=(const Product data);

	/**
	*	@brief	��ǰ <= ������ �����ε�
	*/
	bool operator<=(const Product data);



private:
	string p_Category_Large; //��з� ī�װ�
	string p_Category_Middle; //�ߺз� ī�װ�
	string p_Category_Small; //�Һз� ī�װ�
	string p_Name; //��ǰ��
	string p_Seller; //��ȣ
	int p_Price; //����
	int p_Stock; //���
	string p_Image; //�̹���
};

