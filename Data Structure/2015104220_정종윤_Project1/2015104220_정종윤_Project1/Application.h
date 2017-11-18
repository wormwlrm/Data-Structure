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

class SmallCategoryNodeType // 소분류 카테고리
{
public:
	string SmallCategory;
	LinkedList<Product*> productList;
};

class MiddleCategoryNodeType // 중분류 카테고리
{
public:
	string MiddleCategory;
	SmallCategoryNodeType Smalls[3];
};

class LargeCategoryNodeType // 대분류 카테고리
{
public:
	string LargeCategory;
	MiddleCategoryNodeType Middles[3];
};

class Application
{
public:
	/**
	*	기본 생성자
	*/
	Application();

	/**
	*	소멸자
	*/
	~Application();

	/**
	*	@brief	프로그램 시행
	*	@pre
	*	@post	프로그램을 시작하고 메뉴를 호출함
	*/
	void run();

	/**
	*	@brief	Customer 데이터를 읽어옴
	*	@pre	Customer 데이터가 존재해야 함
	*	@post	Customer 데이터를 읽어옴
	*/
	void load_customer_file();

	/**
	*	@brief	Seller 데이터를 읽어옴
	*	@pre	Seller 데이터가 존재해야 함
	*	@post	Seller 데이터를 읽어옴
	*/
	void load_seller_file();

	/**
	*	@brief	Product 데이터를 읽어옴
	*	@pre	Product 데이터가 존재해야 함
	*	@post	Product 데이터를 읽어옴
	*/
	void load_product_file();

	/**
	*	@brief	프로그램 메인 메뉴를 출력
	*	@pre	프로그램이 시행되고 있어야 함
	*	@post	메뉴를 출력
	*/
	int getMainCommand(); 

	/**
	*	@brief	고객 로그인 선택시 메뉴 출력
	*	@pre	고객으로 로그인 메뉴를 선택해야 함
	*	@post	메뉴를 출력
	*/
	int getCustomerCommand(); 

	/**
	*	@brief	판매자 로그인 선택시 메뉴 출력
	*	@pre	판매자로 로그인 메뉴를 선택해야 함
	*	@post	메뉴를 출력
	*/
	int getSellerCommand();

	/**
	*	@brief	새 고객을 추가
	*	@pre	
	*	@post	새 고객이 리스트에 추가됨
	*/
	void Add_Customer();

	/**
	*	@brief	기존 고객을 삭제
	*	@pre	삭제할 고객이 리스트에 존재해야 함
	*	@post	고객이 리스트에서 삭제됨
	*/
	void Delete_Customer();

	/**
	*	@brief	기존 고객을 갱신함
	*	@pre	갱신할 고객이 리스트에 존재해야 함
	*	@post	고객의 정보가 갱신됨
	*/
	void Update_Customer();

	/**
	*	@brief	고객 모드로 로그인함
	*	@pre	사용자 정보가 이미 등록되어 있어야 함
	*	@post	고객이 로그인 함
	*	@param	data	사용자 아이디, 비밀번호
	*/
	Customer* customerlogIn(string _Id, string _Password);

	/**
	*	@brief	사용자가 로그아웃함
	*	@pre
	*	@post	로그인 된 계정을 NULL로 만듦
	*/
	void customerLogOut();

	/**
	*	@brief	판매자 모드로 로그인함
	*	@pre	판매자 정보가 이미 등록되어 있어야 함
	*	@post	판매자가 로그인 함
	*	@param	data	판매자 상호, 사업자 등록번호
	*/
	Seller* sellerlogin(string _Company, string _RegistrationNumber);

	/**
	*	@brief	판매자가 로그아웃함
	*	@pre
	*	@post	로그인 된 계정을 NULL로 만듦
	*/
	void sellerLogOut();

	/**
	*	@brief	물건을 구매함
	*	@pre	구매할 물건이 존재해야 함
	*	@post	물건이 구매되고 재고가 1 깎임
	*	@param	data	구매할 물건
	*/
	int Buy(Product& Dummy);	

	/**
	*	@brief	장바구니 내에서 물건을 구매함
	*	@pre	구매할 물건이 존재해야 함
	*	@post	물건이 구매되고 재고가 1 깎임
	*	@param	data	구매할 물건
	*/
	int BuyinBasket(Product& Dummy);

	/**
	*	@brief	상품 등록
	*	@pre
	*	@post	상품이 판매 리스트에 추가됨
	*/
	int AddProduct();	

	/**
	*	@brief	상품 정보 갱신
	*	@pre	갱신할 상품이 존재해야 함
	*	@post	현재 등록된 상품의 정보가 갱신됨
	*/
	int UpdateProduct();	

	/**
	*	@brief	상품 삭제
	*	@pre	삭제할 상품이 존재해야 함
	*	@post	상품이 삭제됨
	*/
	int DeleteProduct();	

	/**
	*	@brief	판매 현황 확인
	*	@pre	
	*	@post	현재 판매중인 목록과 총 판매 금액을 확인
	*/
	int SellProduct();	

	/**
	*	@brief	재고 추가
	*	@pre
	*	@post	상품의 재고를 추가함
	*/
	int StorageProduct();	

	/**
	*	@brief	물건을 이름으로 검색함
	*	@pre	검색할 상품이 존재해야 함
	*	@post	검색하여 구매
	*/
	int SearchProduct();

	/**
	*	@brief	사용자 정보 출력
	*	@pre	
	*	@post	사용자 정보 출력
	*/
	void printCustomerInfo();

	/**
	*	@brief	판매자 정보 출력
	*	@pre	
	*	@post	판매자 정보 출력
	*/
	void printSellerInfo();

	/**
	*	@brief	장바구니 출력
	*	@pre	
	*	@post	장바구니 출력
	*/
	void printShoppingBasket();

	/**
	*	@brief	대분류 카테고리를 선택함
	*	@pre	
	*	@post	중분류 카테고리를 선택
	*/
	void choiceLargeCategory();

	/**
	*	@brief	중분류 카테고리를 선택함
	*	@pre	대분류 카테고리가 설정됨
	*	@post	소분류 카테고리를 선택
	*/
	void choiceMiddleCategory(int choice);

	/**
	*	@brief	소분류 카테고리를 선택함
	*	@pre	중분류 카테고리가 설정됨
	*	@post	물건 리스트에서 선택
	*/
	void choiceSmallCategory(int choice, int choice2);

	/**
	*	@brief	카테고리 노드 타입
	*/
	LargeCategoryNodeType Larges[3];

private:
	LinkedList<Customer*> m_CustomerList; // 고객 링크드 리스트
	LinkedList<Seller*> m_SellerList; // 판매자 링크드 리스트
	Customer* LoginedCustomer; // 로그인 된 고객
	Seller* LoginedSeller; // 로그인 된 판매자
};

