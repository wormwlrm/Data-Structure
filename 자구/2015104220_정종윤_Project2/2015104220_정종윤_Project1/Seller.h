#pragma once
#include "Product.h"
#include "SortedLinkedList.h"
#include <string>
using namespace std;

class Seller
{
public:
	/**
	*	기본 생성자
	*/
	Seller();

	/**
	*	소멸자
	*/
	~Seller();

	/**
	*	@brief	상호 설정
	*	@pre	
	*	@post	입력받은 상호로 갱신
	*	@param	data	갱신할 상호 명
	*/
	void setCompany(string _Company);
	/**
	*	@brief	사업자 등록 번호 설정
	*	@pre
	*	@post	입력받은 사업자 등록 번호로 갱신
	*	@param	data	갱신할 사업자 등록 번호
	*/
	void setRegistrationNumber(string _RegistrationNumber);
	/**
	*	@brief	이름 설정
	*	@pre
	*	@post	이름으로 갱신
	*	@param	data	갱신할 이름
	*/
	void setName(string _Name);
	/**
	*	@brief	연락처 설정
	*	@pre
	*	@post	입력받은 연락처로 갱신
	*	@param	data	갱신할 연락처
	*/
	void setPhoneNumber(string _PhoneNumber);
	/**
	*	@brief	판매자 등급 설정
	*	@pre
	*	@post	입력받은 판매자 등급로 갱신
	*	@param	data	갱신할 판매자 등급 명
	*/
	void setGrade(int _Grade);

	/**
	*	@brief	판매자 리스트에 추가
	*	@pre
	*	@post	판매자 리스트에 물품이 추가됨
	*	@param	data	추가할 물품
	*/
	void setSellerProducts(Product* _Product);

	/**
	*	@brief	판매자 설정
	*	@pre
	*	@post	입력받은 정보로 갱신
	*	@param	data	갱신할 상호 명, 사업자 등록번호, 이름, 연락처, 판매자 등급
	*/
	void setSeller(string _Company, string _RegistrationNumber, string _Name, string _PhoneNumber, int _Grade);

	/**
	*	@brief	총 판매 금액 설정
	*	@pre
	*	@post	입력받은 판매 금액을 더함
	*	@param	data	추가할 금액
	*/
	void setTotalCost(int _TotalCoast);
	
	/**
	*	@brief	상호 반환
	*	@pre	
	*	@post	상호 반환
	*/
	string getCompany();

	/**
	*	@brief	사업자 등록 번호 반환
	*	@pre
	*	@post	사업자 등록 번호 반환
	*/
	string getRegistrationNumber();

	/**
	*	@brief	이름 반환
	*	@pre
	*	@post	이름 반환
	*/
	string getName();

	/**
	*	@brief	연락처 반환
	*	@pre
	*	@post	연락처 반환
	*/
	string getPhoneNumber();

	/**
	*	@brief	판매 등급 반환
	*	@pre
	*	@post	판매 등급 반환
	*/
	int getGrade();

	/**
	*	@brief	총 판매 금액 반환
	*	@pre
	*	@post	총 판매 금액 반환
	*/
	int getTotalCost();

	/**
	*	@brief	물품 리스트를 출력
	*	@pre
	*	@post	물품 리스트를 출력
	*/
	void printProductList();

	/**
	*	@brief	판매자 == 연산자 오버로딩
	*/
	bool operator==(const Seller data);

	/**
	*	@brief	판매자 >= 연산자 오버로딩
	*/
	bool operator>=(const Seller data);

	/**
	*	@brief	판매자 <= 연산자 오버로딩
	*/
	bool operator<=(const Seller data);	

private:
	string s_Company; // 상호명
	string s_RegistrationNumber; // 사업자 등록 번호
	string s_Name; // 이름
	string s_PhoneNumber; // 연락처
	int s_Grade; // 판매 등급
	LinkedList<Product*> m_ProductList; // 판매하는 물품 링크드 리스트
	int s_TotalCost; // 총 판매 금액
};

