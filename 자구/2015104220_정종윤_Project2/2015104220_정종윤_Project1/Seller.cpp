#include "Seller.h"


Seller::Seller()
{
	s_TotalCost = 0; // �� �Ǹ� �ݾ��� 0���� �ʱ�ȭ
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
	m_ProductList.ResetList(); // ��ǰ ����Ʈ ������ �ʱ�ȭ
	for (int i = 0; i< m_ProductList.GetLength(); i++) // ��ǰ ����Ʈ ���̸�ŭ �ݺ�
	{
		m_ProductList.GetNextItem(Dummy); // ���� �������� ����Ŵ
		Dummy->printProductDisplay(); // Dummy�� ���� ���
	}
}