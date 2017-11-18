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
	*	@brief	대입 연산자
	*	@param  [b] 입력할 값
	*	@return 변환된 값을 반환
	*/
	Point operator = (Point& b)
	{
		x = b.x;
		y = b.y;
		return *this;
	}

	/**
	*	@brief	<< 연산자
	*	@param  [out] ostream, [t]출력할 포인트
	*	@return 변환된 ostream을 반환
	*/
	friend ostream &operator<<(ostream& out, Point& t)
	{
		out << "(" << t.x << "," << t.y << ")";
		return out;
	}

	/**
	*	@brief	>> 연산자
	*	@param  [out] istream, [t]입력할 포인트
	*	@return 변환된 istream을 반환
	*/
	friend istream &operator>>(istream& in, Point& t)
	{
		in >> t.x >> t.y;
		return in;
	}
};