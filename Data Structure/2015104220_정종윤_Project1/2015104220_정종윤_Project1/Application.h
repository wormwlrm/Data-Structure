#pragma once
#include "Customer.h"
#include "Seller.h"
#include "Product.h"
#include "SortedLinkedList.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class SmallCategoryNodeType // �Һз� ī�װ�
{
public:
	string SmallCategory;
	LinkedList<Product*> productList;
};

class MiddleCategoryNodeType // �ߺз� ī�װ�
{
public:
	string MiddleCategory;
	SmallCategoryNodeType Smalls[3];
};

class LargeCategoryNodeType // ��з� ī�װ�
{
public:
	string LargeCategory;
	MiddleCategoryNodeType Middles[3];
};

class Application
{
public:
	/**
	*	�⺻ ������
	*/
	Application();

	/**
	*	�Ҹ���
	*/
	~Application();

	/**
	*	@brief	���α׷� ����
	*	@pre
	*	@post	���α׷��� �����ϰ� �޴��� ȣ����
	*/
	void run();

	/**
	*	@brief	Customer �����͸� �о��
	*	@pre	Customer �����Ͱ� �����ؾ� ��
	*	@post	Customer �����͸� �о��
	*/
	void load_customer_file();

	/**
	*	@brief	Seller �����͸� �о��
	*	@pre	Seller �����Ͱ� �����ؾ� ��
	*	@post	Seller �����͸� �о��
	*/
	void load_seller_file();

	/**
	*	@brief	Product �����͸� �о��
	*	@pre	Product �����Ͱ� �����ؾ� ��
	*	@post	Product �����͸� �о��
	*/
	void load_product_file();

	/**
	*	@brief	���α׷� ���� �޴��� ���
	*	@pre	���α׷��� ����ǰ� �־�� ��
	*	@post	�޴��� ���
	*/
	int getMainCommand(); 

	/**
	*	@brief	�� �α��� ���ý� �޴� ���
	*	@pre	������ �α��� �޴��� �����ؾ� ��
	*	@post	�޴��� ���
	*/
	int getCustomerCommand(); 

	/**
	*	@brief	�Ǹ��� �α��� ���ý� �޴� ���
	*	@pre	�Ǹ��ڷ� �α��� �޴��� �����ؾ� ��
	*	@post	�޴��� ���
	*/
	int getSellerCommand();

	/**
	*	@brief	�� ���� �߰�
	*	@pre	
	*	@post	�� ���� ����Ʈ�� �߰���
	*/
	void Add_Customer();

	/**
	*	@brief	���� ���� ����
	*	@pre	������ ���� ����Ʈ�� �����ؾ� ��
	*	@post	���� ����Ʈ���� ������
	*/
	void Delete_Customer();

	/**
	*	@brief	���� ���� ������
	*	@pre	������ ���� ����Ʈ�� �����ؾ� ��
	*	@post	���� ������ ���ŵ�
	*/
	void Update_Customer();

	/**
	*	@brief	�� ���� �α�����
	*	@pre	����� ������ �̹� ��ϵǾ� �־�� ��
	*	@post	���� �α��� ��
	*	@param	data	����� ���̵�, ��й�ȣ
	*/
	Customer* customerlogIn(string _Id, string _Password);

	/**
	*	@brief	����ڰ� �α׾ƿ���
	*	@pre
	*	@post	�α��� �� ������ NULL�� ����
	*/
	void customerLogOut();

	/**
	*	@brief	�Ǹ��� ���� �α�����
	*	@pre	�Ǹ��� ������ �̹� ��ϵǾ� �־�� ��
	*	@post	�Ǹ��ڰ� �α��� ��
	*	@param	data	�Ǹ��� ��ȣ, ����� ��Ϲ�ȣ
	*/
	Seller* sellerlogin(string _Company, string _RegistrationNumber);

	/**
	*	@brief	�Ǹ��ڰ� �α׾ƿ���
	*	@pre
	*	@post	�α��� �� ������ NULL�� ����
	*/
	void sellerLogOut();

	/**
	*	@brief	������ ������
	*	@pre	������ ������ �����ؾ� ��
	*	@post	������ ���ŵǰ� ��� 1 ����
	*	@param	data	������ ����
	*/
	int Buy(Product& Dummy);	

	/**
	*	@brief	��ٱ��� ������ ������ ������
	*	@pre	������ ������ �����ؾ� ��
	*	@post	������ ���ŵǰ� ��� 1 ����
	*	@param	data	������ ����
	*/
	int BuyinBasket(Product& Dummy);

	/**
	*	@brief	��ǰ ���
	*	@pre
	*	@post	��ǰ�� �Ǹ� ����Ʈ�� �߰���
	*/
	int AddProduct();	

	/**
	*	@brief	��ǰ ���� ����
	*	@pre	������ ��ǰ�� �����ؾ� ��
	*	@post	���� ��ϵ� ��ǰ�� ������ ���ŵ�
	*/
	int UpdateProduct();	

	/**
	*	@brief	��ǰ ����
	*	@pre	������ ��ǰ�� �����ؾ� ��
	*	@post	��ǰ�� ������
	*/
	int DeleteProduct();	

	/**
	*	@brief	�Ǹ� ��Ȳ Ȯ��
	*	@pre	
	*	@post	���� �Ǹ����� ��ϰ� �� �Ǹ� �ݾ��� Ȯ��
	*/
	int SellProduct();	

	/**
	*	@brief	��� �߰�
	*	@pre
	*	@post	��ǰ�� ��� �߰���
	*/
	int StorageProduct();	

	/**
	*	@brief	������ �̸����� �˻���
	*	@pre	�˻��� ��ǰ�� �����ؾ� ��
	*	@post	�˻��Ͽ� ����
	*/
	int SearchProduct();

	/**
	*	@brief	����� ���� ���
	*	@pre	
	*	@post	����� ���� ���
	*/
	void printCustomerInfo();

	/**
	*	@brief	�Ǹ��� ���� ���
	*	@pre	
	*	@post	�Ǹ��� ���� ���
	*/
	void printSellerInfo();

	/**
	*	@brief	��ٱ��� ���
	*	@pre	
	*	@post	��ٱ��� ���
	*/
	void printShoppingBasket();

	/**
	*	@brief	��з� ī�װ��� ������
	*	@pre	
	*	@post	�ߺз� ī�װ��� ����
	*/
	void choiceLargeCategory();

	/**
	*	@brief	�ߺз� ī�װ��� ������
	*	@pre	��з� ī�װ��� ������
	*	@post	�Һз� ī�װ��� ����
	*/
	void choiceMiddleCategory(int choice);

	/**
	*	@brief	�Һз� ī�װ��� ������
	*	@pre	�ߺз� ī�װ��� ������
	*	@post	���� ����Ʈ���� ����
	*/
	void choiceSmallCategory(int choice, int choice2);

	/**
	*	@brief	ī�װ� ��� Ÿ��
	*/
	LargeCategoryNodeType Larges[3];

private:
	LinkedList<Customer*> m_CustomerList; // �� ��ũ�� ����Ʈ
	LinkedList<Seller*> m_SellerList; // �Ǹ��� ��ũ�� ����Ʈ
	Customer* LoginedCustomer; // �α��� �� ��
	Seller* LoginedSeller; // �α��� �� �Ǹ���
};

