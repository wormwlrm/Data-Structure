#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Product
{
public:
	/**
	*	기본 생성자
	*/
	Product();

	/**
	*	소멸자
	*/
	~Product();

	/**
	*	@brief	대분류 카테고리 설정
	*	@pre
	*	@post	대분류 카테고리가 설정됨
	*	@param	data	설정할 카테고리
	*/
	void setCategoryLarge(string _CategoryLarge);

	/**
	*	@brief	중분류 카테고리 설정
	*	@pre
	*	@post	중분류 카테고리가 설정됨
	*	@param	data	설정할 카테고리
	*/
	void setCategoryMiddle(string _CategoryMiddle);

	/**
	*	@brief	소분류 카테고리 설정
	*	@pre
	*	@post	소분류 카테고리가 설정됨
	*	@param	data	설정할 카테고리
	*/
	void setCategorySmall(string _CategorySmall);

	/**
	*	@brief	이름 설정
	*	@pre
	*	@post	이름이 설정됨
	*	@param	data	설정할 이름
	*/
	void setName(string _Name);

	/**
	*	@brief	상호 설정
	*	@pre
	*	@post	상호가 설정됨
	*	@param	data	설정할 상호
	*/
	void setSeller(string _Seller);

	/**
	*	@brief	가격 설정
	*	@pre
	*	@post	가격이 설정됨
	*	@param	data	설정할 가격
	*/
	void setPrice(int _Price);

	/**
	*	@brief	재고 설정
	*	@pre
	*	@post	재고가 설정됨
	*	@param	data	설정할 재고
	*/
	void setStock(int _Stock);

	/**
	*	@brief	이미지 설정
	*	@pre
	*	@post	이미지가 설정됨
	*	@param	data	설정할 이미지
	*/
	void setImage(string _Image);

	/**
	*	@brief	물품 설정
	*	@pre
	*	@post	물품이 설정됨
	*	@param	data	설정할 대분류, 중분류, 소분류 카테고리, 이름, 상호, 가격, 재고, 이미지
	*/
	void setProduct(string _CategoryLarge, string _CategoryMiddle, string _CategorySmall,
		string _Name, string _Seller, int _Price, int _Stock, string _Image);

	/**
	*	@brief	대분류 카테고리 반환
	*	@pre
	*	@post	대분류 카테고리 반환
	*/
	string getCategoryLarge();

	/**
	*	@brief	중분류 카테고리 반환
	*	@pre
	*	@post	중분류 카테고리 반환
	*/
	string getCategoryMiddle();
	
	/**
	*	@brief	소분류 카테고리 반환
	*	@pre
	*	@post	소분류 카테고리 반환
	*/
	string getCategorySmall();

	/**
	*	@brief	물품명 반환
	*	@pre
	*	@post	물품명 반환
	*/
	string getName();

	/**
	*	@brief	판매자 반환
	*	@pre
	*	@post	판매자 반환
	*/
	string getSeller();

	/**
	*	@brief	가격 반환
	*	@pre
	*	@post	가격 반환
	*/
	int getPrice();

	/**
	*	@brief	재고 반환
	*	@pre
	*	@post	재고 반환
	*/
	int getStock();

	/**
	*	@brief	이미지 반환
	*	@pre
	*	@post	이미지 반환
	*/
	string getImage();

	/**
	*	@brief	물품을 진열용으로 출력함
	*	@pre
	*	@post	정보 출력
	*/
	void printProductDisplay();

	/**
	*	@brief	물품의 자세한 정보를 출력함
	*	@pre
	*	@post	정보 출력
	*/
	void printProductInfo();

	/**
	*	@brief	판매될 물건 리스트를 출력함
	*	@pre
	*	@post	정보 출력
	*/
	void printProductShoppingList();

	/**
	*	@brief	물품 == 연산자 오버로딩
	*/
	bool operator==(const Product data);

	/**
	*	@brief	물품 >= 연산자 오버로딩
	*/
	bool operator>=(const Product data);

	/**
	*	@brief	물품 <= 연산자 오버로딩
	*/
	bool operator<=(const Product data);



private:
	string p_Category_Large; //대분류 카테고리
	string p_Category_Middle; //중분류 카테고리
	string p_Category_Small; //소분류 카테고리
	string p_Name; //물품명
	string p_Seller; //상호
	int p_Price; //가격
	int p_Stock; //재고
	string p_Image; //이미지
};

