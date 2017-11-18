#include <iostream>
using namespace std;

/**
*	@brief	coordinate struct
*/
struct Point
{
	int x;	//@brief value of x
	int y;	//@brief value of y

	/**
	*	@brief	���� ������
	*	@param  [b] �Է��� ��
	*	@return ��ȯ�� ���� ��ȯ
	*/
	Point operator = (Point& b)
	{
		x = b.x;
		y = b.y;
		return *this;
	}

	/**
	*	@brief	<< ������
	*	@param  [out] ostream, [t]����� ����Ʈ
	*	@return ��ȯ�� ostream�� ��ȯ
	*/
	friend ostream &operator<<(ostream& out, Point& t)
	{
		out << "(" << t.x << "," << t.y << ")";
		return out;
	}

	/**
	*	@brief	>> ������
	*	@param  [out] istream, [t]�Է��� ����Ʈ
	*	@return ��ȯ�� istream�� ��ȯ
	*/
	friend istream &operator>>(istream& in, Point& t)
	{
		in >> t.x >> t.y;
		return in;
	}
};