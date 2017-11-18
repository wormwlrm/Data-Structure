#include "ItemType.h"
#include <iostream>
using namespace std;

#define QUEUE_MAX_DATA 8

/**
*	@brief	Exception class thrown by Push when queue is full.
*/
class FullQueue
{
public:
	/**
	*	@brief	Display a message for full queue on screen.
	*/
	void print()
	{
		cout << "FullQueue exception thrown." << endl;
	}
};


/**
*	@brief	Exception class thrown by Pop and Top when queue is empty.
*/
class EmptyQueue
{
public:
	/**
	*	@brief	Display a message for full queue on screen.
	*/
	void print()
	{
		cout << "EmtpyQueue exception thrown." << endl;
	}
};

/**
*	@brief	Circular Queue class.
*	@details	This class processes as First In, First Out (FIFO).
*/

template<class Type>
class CircularQueueType
{
public:
	/**
	*	@brief	Allocate dynamic array whose size is QUEUE_MAX_DATA.
	*	@pre	The queue size is defined
	*	@post	Member of items points the allocated array.
	*/
	CircularQueueType();

	/**
	*	@brief	Allocate dynamic array whose size is QUEUE_MAX_DATA.
	*	@pre	The queue size is user defined(not defiend).
	*	@post	Member of items points the allocated array.
	*/
	CircularQueueType(int max);

	/**
	*	@brief	Destruct the object. Free the array dynamically allocated.
	*	@pre	Release memory for queue pointer.
	*	@post	none.
	*/
	~CircularQueueType();

	/**
	*	@brief	Determines whether the queue is full.
	*	@pre	Stack has been initialized.
	*	@post	Function value = (queue is full)
	*	@return Return 1 if this queue is full, otherwise 0.
	*/
	bool isFull() const;

	/**
	*	@brief	Determines whether the queue is empty.
	*	@pre	Stack has been initialized.
	*	@post	Function value = (queue is empty)
	*/
	bool isEmpty() const;

	/**
	*	@brief	Adds newItem to the top of the queue.
	*	@pre	Stack has been initialized.
	*	@post	If (queue is full), FullStack exception is thrown; otherwise, newItem is at the top of the queue.
	*/
	void makeEmpty();

	/**
	*	@brief	Adds newItem to the top of the queue.
	*	@detail	Get Item by parameter, and add that to rear.
	*	@pre	None.
	*	@post	If (queue is full), FullStack exception is thrown; otherwise, newItem is at the top of the queue. Rear and count increased.
	*	@param	Item that user want to add.
	*/
	void Enqueue(Type item);

	/**
	*	@brief	Deletes newItem to the top of the queue.
	*	@detail	Get Item by parameter, and delete item in queue.
	*	@pre	Item user want to delete must be exist
	*	@post	If (queue is empty), EmptyStack exception is thrown; otherwise, front element has been removed from queue. Front increased. Count Decreased.
	*	@param	Item that user want to delete.
	*/
	void Dequeue(Type& item);

	/**
	*	@brief	Print all the items in the queue on screen
	*	@pre	Stack has been initialized.
	*	@post	None.
	*/
	void print() const;

private:
	int m_count;		//Queue count
	int m_iFront;		//Queue front
	int m_iRear;		//Queue rear
	int m_nMaxQueue;	//Queue length
	Type* m_pItems;		//Queue item
};

template<typename Type> 
CircularQueueType<Type>::CircularQueueType() // 기본생성자
{
	m_count = 0;
	m_nMaxQueue = QUEUE_MAX_DATA;
	m_iFront = 0;
	m_iRear = 0;
	m_pItems = new Type;
}

template<typename Type> 
CircularQueueType<Type>::CircularQueueType(int max) // 길이 설정 생성자
{
	m_count = 0;
	m_nMaxQueue = max;
	m_iFront = 0;
	m_iRear = 0;
	m_pItems = new T;
}

template<typename Type> 
CircularQueueType<Type>::~CircularQueueType() //소멸자
{
}

template<typename Type> 
bool CircularQueueType<Type>::isFull() const // Queue가 가득 찼는지 여부를 확인
{
	return (m_count == m_nMaxQueue);
}

template<typename Type> 
bool CircularQueueType<Type>::isEmpty() const // Queue가 비었는지 여부를 확인
{
	return (m_iFront == m_iRear) && !isFull();
}

template<typename Type> 
void CircularQueueType<Type>::makeEmpty() // Queue 전체를 비우는 함수.
{
	while (!isEmpty())	// Queue가 빌 때 까지 데이터 삭제하는 함수 호출
		Dequeue();
}

template<typename Type> 
void CircularQueueType<Type>::Enqueue(Type item) //queue에 데이터를 추가하는 함수.
{
	if (!isFull())
	{
		m_pItems[m_iRear] = item;	//rear에 아이템을 추가
		m_iRear = (m_iRear + 1) % m_nMaxQueue;	//rear를 증가시키고 최대 길이로 나눈 나머지로 바꿔줌
		m_count++;	//queue 갯수 증가
	}
	else
		throw FullQueue();		//에러 처리
}

template<typename Type> 
void CircularQueueType<Type>::Dequeue(Type& item) //queue에 데이터를 삭제하는 함수.
{
	if (!isEmpty())
	{
		item = m_pItems[m_iFront];	//item에 지울 값 복사
		m_iFront = (m_iFront + 1) % m_nMaxQueue;	//front를 증가시키고 최대 길이로 나눈 나머지로 바꿈
		m_count--;	//queue 개수 감수
	}
	else
		throw EmptyQueue();		//에러 처리
}

template<typename Type> 
void CircularQueueType<Type>::print() const //queue의 모든 데이터를 출력하는 함수.
{

	for (int i = m_iFront; i < m_iFront + m_count; i++)
		cout << m_pItems[i % m_nMaxQueue] << "\t" ; // Queue의 길이 만큼 나누어야 순환 가능
	cout << endl;
}