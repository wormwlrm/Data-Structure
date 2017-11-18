#include "Customer.h"


Customer::Customer()
{
	c_Point = 0;
}

Customer::~Customer()
{
	c_ShoppingList.MakeEmpty(); // 쇼핑 리스트 삭제
	c_ShoppingBasket.MakeEmpty(); // 장바구니 삭제
}

void Customer::setId(string _Id)
{
	c_Id = _Id; // 아이디 설정
}
void Customer::setPassword(string _Password)
{
	c_Password = _Password; // 비밀번호 설정
}
void Customer::setName(string _Name)
{
	c_Name = _Name; // 이름 설정
}
void Customer::setShoppingBasket(Product& _Product)
{
	c_ShoppingBasket.Add(_Product); // 장바구니 리스트에 추가
}
void Customer::setMyShoppingList(Product* _Product)
{
	c_ShoppingList.Add(*_Product); // 쇼핑 리스트에 추가
	int temp = _Product->getStock(); 
	_Product->setStock(temp - 1); // 재고 1만큼 감소
}

void Customer::setCustomer(string _Id, string _Password, string _Name, int _Point)
{
	c_Id = _Id; // 고객 설정
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
	cout << "───────────────────" << endl;
	cout << "   장바구니 리스트 " << endl;
	cout << "───────────────────" << endl;
	cout << " 상품명        가격   재고 " << endl;
	cout << "───────────────────" << endl;
	c_ShoppingBasket.ResetList(); // 장바구니 포인터 초기화
	Product *Dummy = new Product();
	for (int j = 0; j < c_ShoppingBasket.GetLength(); j++) // 장바구니 길이만큼 반복
	{
		c_ShoppingBasket.GetNextItem(*Dummy); // 다음 아이템을 가리킴
		cout << j + 1; Dummy->printProductDisplay(); 
	}
	if (c_ShoppingBasket.GetLength() == 0) // 길이가 0일 경우
	{
		cout << "상품이 존재하지 않습니다." << endl;
		cout << "───────────────────" << endl;
		return NULL;
	}
	return 0;
}

Product* Customer::PassDummy(int command)
{
	if (command == 0) // 0 입력 받을 경우
	{
		return NULL;
	}
	Product* Dummy = new Product();
	c_ShoppingBasket.ResetList();
	for (int k = 0; k < command; k++) // command만큼 반복
	{
		c_ShoppingBasket.GetNextItem(*Dummy);
	}
	Dummy->printProductInfo(); // 현재 Dummy의 정보 출력
	cout << "───────────────────" << endl;

	return Dummy; 
}


void Customer::PrintMyShoppingList()
{
	Product data;
	cout << "───────────────────" << endl;
	cout << "   쇼핑한 물건 리스트 " << endl;
	cout << "───────────────────" << endl;
	if (c_ShoppingList.GetLength() == 0) // 쇼핑 리스트 길이가 0일 경우 예외 처리
	{
		cout << "상품이 존재하지 않습니다." << endl;
		cout << "───────────────────" << endl;
		return;
	}
	c_ShoppingList.ResetList();
	for (int i = 0; i < c_ShoppingList.GetLength(); i++) // 쇼핑 리스트 길이만큼 반복
	{
		c_ShoppingList.GetNextItem(data); // 다음 아이템 가리킴
		data.printProductShoppingList(); // data의 정보 출력
	}
}

