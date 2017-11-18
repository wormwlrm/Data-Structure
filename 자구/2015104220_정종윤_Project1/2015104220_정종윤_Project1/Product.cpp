#include "Product.h"


Product::Product()
{
}

Product::~Product()
{

}

void Product :: setCategoryLarge(string _CategoryLarge)
{
	p_Category_Large = _CategoryLarge;
}
void Product::setCategoryMiddle(string _CategoryMiddle)
{
	p_Category_Middle = _CategoryMiddle;
}
void Product::setCategorySmall(string _CategorySmall)
{
	p_Category_Small = _CategorySmall;
}
void Product::setName(string _Name)
{
	p_Name = _Name;
}
void Product::setSeller(string _Seller)
{
	p_Seller = _Seller;
}
void Product::setPrice(int _Price)
{
	p_Price = _Price;
}
void Product::setStock(int _Stock)
{
	p_Stock = _Stock;
	
}
void Product::setImage(string _Image)
{
	p_Image = _Image;
}
void Product::setProduct(string _CategoryLarge, string _CategoryMiddle, string _CategorySmall, string _Name, string _Seller, int _Price, int _Stock, string _Image)
{
	p_Category_Large = _CategoryLarge;
	p_Category_Middle = _CategoryMiddle;
	p_Category_Small = _CategorySmall;
	p_Name = _Name;
	p_Seller = _Seller;
	p_Price = _Price;
	p_Stock = _Stock;
	p_Image = _Image;
}

string Product::getCategoryLarge()
{
	return p_Category_Large;
}
string Product::getCategoryMiddle()
{
	return p_Category_Middle;
}
string Product::getCategorySmall()
{
	return p_Category_Small;
}
string Product::getName()
{
	return p_Name;
}
string Product::getSeller()
{
	return p_Seller;
}
int Product::getPrice()
{
	return p_Price;
}
int Product::getStock()
{
	return p_Stock;
}
string Product::getImage()
{
	return p_Image;
}

bool Product::operator==(const Product data)
{
	if (this->p_Name == data.p_Name)
		return true;
	else
		return false;
}
bool Product::operator>=(const Product data)
{
	if (this->p_Name >= data.p_Name)
		return true;
	else
		return false;
}

bool Product::operator<=(const Product data)
{
	if (this->p_Name <= data.p_Name)
		return true;
	else
		return false;
}

void Product::printProductDisplay()
{
	cout << setw(11) << getName() << setw(8) << getPrice() << setw(7) << getStock() << endl; // ������ ���� ���
}

void Product::printProductInfo()
{
	cout << setw(10) << "��ǰ�� : " << setw(10) << getName() << endl; // ��ǰ�� ���
	cout << setw(10) << "��з� : " << setw(10) << getCategoryLarge() << endl; // ��з� ���
	cout << setw(10) << "�ߺз� : " << setw(10) << getCategoryMiddle() << endl; // �ߺз� ���
	cout << setw(10) << "�Һз� : " << setw(10) << getCategorySmall() << endl; // �Һз� ���
	cout << setw(10) << "�Ǹ��� : " << setw(10) << getSeller() << endl; // �Ǹ��� ���
	cout << setw(10) << "�̹��� : " << setw(10) << getImage() << endl; // �̹��� ���
	cout << setw(10) << "����   : " << setw(10) << getPrice() << endl; // ���� ���
	cout << setw(10) << "���   : " << setw(10) << getStock() << endl; // ��� ���
	cout << "��������������������������" << endl;
}

void Product::printProductShoppingList()
{
	cout << setw(10) << "��ǰ�� : " << setw(10) << getName() << endl; // ��ǰ�� ���
	cout << setw(10) << "��з� : " << setw(10) << getCategoryLarge() << endl; // ��з� ���
	cout << setw(10) << "�ߺз� : " << setw(10) << getCategoryMiddle() << endl; // �ߺз� ���
	cout << setw(10) << "�Һз� : " << setw(10) << getCategorySmall() << endl; // �Һз� ���
	cout << setw(10) << "�Ǹ��� : " << setw(10) << getSeller() << endl; // �Ǹ��� ���
	cout << setw(10) << "�̹��� : " << setw(10) << getImage() << endl; // �̹��� ���
	cout << setw(10) << "����   : " << setw(10) << getPrice() << endl; // ���� ���
	cout << "��������������������������" << endl;
}
