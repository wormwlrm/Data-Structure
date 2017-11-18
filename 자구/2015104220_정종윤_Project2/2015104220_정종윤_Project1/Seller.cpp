#include "Seller.h"


Seller::Seller()
{
	s_TotalCost = 0; // 총 판매 금액을 0으로 초기화
}

Seller::~Seller()
{
}

void Seller::setCompany(string _Company)
{
	s_Company = _Company;
}
void Seller::setRegistrationNumber(string _RegistrationNumber)
{
	s_RegistrationNumber = _RegistrationNumber;
}
void Seller::setName(string _Name)
{
	s_Name = _Name;
}
void Seller::setPhoneNumber(string _PhoneNumber)
{
	s_PhoneNumber = _PhoneNumber;
}
void Seller::setGrade(int _Grade)
{
	s_Grade = _Grade;
}
void Seller::setSellerProducts(Product* _Product)
{
	m_ProductList.Add(_Product);
}

void Seller::setTotalCost(int _TotalCost)
{
	s_TotalCost += _TotalCost;
}

void Seller :: setSeller(string _Company, string _RegistrationNumber, string _Name, string _PhoneNumber, int _Grade)
{
	s_Company = _Company;
	s_RegistrationNumber = _RegistrationNumber;
	s_Name = _Name;
	s_PhoneNumber = _PhoneNumber;
	s_Grade = _Grade;
}
string Seller::getCompany()
{
	return s_Company;
}
string Seller::getRegistrationNumber()
{
	return s_RegistrationNumber;
}
string Seller::getName()
{
	return s_Name;
}
string Seller::getPhoneNumber()
{
	return s_PhoneNumber;
}
int Seller::getGrade()
{
	return s_Grade;
}

int Seller::getTotalCost()
{
	return s_TotalCost;
}

bool Seller::operator==(const Seller data)
{
	if (this->s_Name == data.s_Name)
		return true;
	else
		return false;
}
bool Seller::operator>=(const Seller data)
{
	if (this->s_Name >= data.s_Name)
		return true;
	else
		return false;
}

bool Seller::operator<=(const Seller data)
{
	if (this->s_Name <= data.s_Name)
		return true;
	else
		return false;
}

void Seller::printProductList()
{
	Product* Dummy = new Product();
	m_ProductList.ResetList(); // 물품 리스트 포인터 초기화
	for (int i = 0; i< m_ProductList.GetLength(); i++) // 물품 리스트 길이만큼 반복
	{
		m_ProductList.GetNextItem(Dummy); // 다음 아이템을 가리킴
		Dummy->printProductDisplay(); // Dummy의 정보 출력
	}
}