#pragma once
#include "Product.h"
#include "SortedLinkedList.h"
#include <string>
using namespace std;

class Customer
{
public:
	/**
	*	기본 생성자
	*/
	Customer();

	/**
	*	소멸자
	*/
	~Customer();

	/**
	*	@brief	아이디 설정
	*	@pre
	*	@post	아이디가 설정됨
	*	@param	data	설정할 아이디
	*/
	void setId(string _Id);

	/**
	*	@brief	비밀번호 설정
	*	@pre
	*	@post	비밀번호가 설정됨
	*	@param	data	설정할 비밀번호
	*/
	void setPassword(string _Password);

	/**
	*	@brief	이름 설정
	*	@pre
	*	@post	이름이 설정됨
	*	@param	data	설정할 이름
	*/
	void setName(string _Name);

	/**
	*	@brief	장바구니에 물건이 추가됨
	*	@pre
	*	@post	장바구니가 설정됨
	*	@param	data	설정할 물건
	*/
	void setShoppingBasket(Product& _Product);

	/**
	*	@brief	쇼핑리스트에 물건이 추가됨
	*	@pre
	*	@post	쇼핑리스트가 설정됨
	*	@param	data	추가할 물건
	*/
	void setMyShoppingList(Product* _Product);

	/**
	*	@brief	사용자 설정
	*	@pre
	*	@post	사용자가 설정됨
	*	@param	data	사용자 아이디, 비밀번호, 이름
	*/
	void setCustomer(string _Id, string _Password, string _Name);
	
	/**
	*	@brief	아이디 반환
	*	@pre
	*	@post	아이디 반환
	*/
	string getId();

	/**
	*	@brief	비밀번호 반환
	*	@pre
	*	@post	비밀번호 반환
	*/
	string getPassword();

	/**
	*	@brief	이름 반환
	*	@pre
	*	@post	이름 반환
	*/
	string getName();

	/**
	*	@brief	길이 반환
	*	@pre
	*	@post	길이 반환
	*/
	int GetLength() const;

	/**
	*	@brief	장바구니를 출력함
	*	@pre
	*	@post	장바구니 출력
	*/
	int printShoppingBasket();

	/**
	*	@brief	쇼핑 리스트를 출력함
	*	@pre
	*	@post	쇼핑 리스트 출력
	*/
	void PrintMyShoppingList();

	/**
	*	@brief	장바구니 내에서 선택한 물건을 반환
	*	@pre
	*	@post	장바구니 내에서 선택한 물건을 반환
	*	@param	data	사용자가 선택한 물건 번호
	*/
	Product* PassDummy(int choice);

	/**
	*	@brief	고객 == 연산자 오버로딩
	*/
	bool operator==(const Customer data);

	/**
	*	@brief	고객 >= 연산자 오버로딩
	*/
	bool operator>=(const Customer data);

	/**
	*	@brief	고객 <= 연산자 오버로딩
	*/
	bool operator<=(const Customer data);
	
private:
	string c_Id; // 아이디
	string c_Password; // 비밀번호
	string c_Name; // 이름
	LinkedList<Product> c_ShoppingBasket; // 장바구니 링크드 리스트
	LinkedList<Product> c_ShoppingList; // 쇼핑한 목록들 링크드 리스트
};


