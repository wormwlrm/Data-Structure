#ifndef _QUEUETYPE_H
#define _QUEUETYPE_H

#include<iostream>

using namespace std;

#define MAX_ITEMS 100

/**
*	@brief	Exception class thrown by Enqueue when queue is full.
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
*	@brief	Exception class thrown by Dequeue when queue is empty.
*/
class EmptyQueue
{
public:
	/**
	*	@brief	Display a message for empty queue on screen.
	*/
	void print()
	{
		cout << "EmtpyQueue exception thrown." << endl;
	}
};

/**
*	@brief	Queue class.
*	@details	This class processes as First In, First Out (FIFO).
*/
template <class ItemType>
class QueueType
{
public:
	/**
	*	@brief	Allocate dynamic array whose size is Max size
	*	@pre	Max is defined
	*	@post	Items points the array allocated.
	*/
	QueueType();

	/**
	*	@brief	Allocate dynamic array whose size is Max size
	*	@pre	Max is defined
	*	@post	Items points the array allocated.
	*/
	QueueType(int max);

	/**
	*	@brief	destruct the object. Free the array dynamically allocated
	*	@pre	Items is initialized.
	*	@post	None
	*/
	~QueueType();

	/**
	*	@brief	Determines whether the Queue is full.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (Queue is full)
	*/
	bool IsFull();

	/**
	*	@brief	Determines whether the Queue is empty.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (Queue is empty)
	*/
	bool IsEmpty();

	/**
	*	@brief	Make queue to empty.
	*	@pre	None
	*	@post	Queue is empty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Adds newItem to the rear of Queue.
	*	@pre	Queue has been initialized.
	*	@post	If (Queue is full), FullQueue exception is thrown; otherwise, newItem is at the rear of Queue.
	*/
	void EnQueue(ItemType newItem);

	/**
	*	@brief	Removes front item of the queue
	*	@pre	Queue has been initialized.
	*	@post	If (queue is empty), EmptyQueue exception is thrown; otherwise, front element has been removed from queue.
	*/
	void DeQueue(ItemType& item);

	/**
	*	@brief	Print all the items in the queue on screen
	*	@pre	Queue has been initialized.
	*	@post	None
	*/
	void Print();

private:
	int m_iFront;		///< Front 
	int m_iRear;		///< Rear
	int m_nMaxQueue;	///< Max stack size
	ItemType* m_pItems;	///< Pointer for a queue.
};


/////////////////////////// Member functions /////////////////////////


// Allocate dynamic array whose size is Max size
template <class ItemType>
QueueType<ItemType>::QueueType()
{
	m_nMaxQueue = MAX_ITEMS + 1;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;
	m_pItems = new ItemType[m_nMaxQueue];   // dynamically allocates
}

// Allocate dynamic array whose size is Max size
template <class ItemType>
QueueType<ItemType>::QueueType(int max)
{
	m_nMaxQueue = max + 1;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;
	m_pItems = new ItemType[m_nMaxQueue];   // dynamically allocates
}

// destruct the object. Free the array dynamically allocated
template <class ItemType>
QueueType<ItemType>::~QueueType()
{
	delete[] m_pItems;
}

// Determines whether the Queue is full.
template <class ItemType>
bool QueueType<ItemType>::IsFull()
{
	return ((m_iRear + 1) % m_nMaxQueue == m_iFront);
}

// Determines whether the Queue is empty.
template <class ItemType>
bool QueueType<ItemType>::IsEmpty()
{
	return (m_iRear == m_iFront);
}

// Make queue to empty.
template <class ItemType>
void QueueType<ItemType>::MakeEmpty()
{
	m_iFront = m_iRear;
}

// Adds newItem to the rear of Queue.
template <class ItemType>
void QueueType<ItemType>::EnQueue(ItemType newItem)
{
	if (IsFull())
		throw  FullQueue();
	else
	{
		m_iRear = (m_iRear + 1) % m_nMaxQueue;
		m_pItems[m_iRear] = newItem;
	}

}

// Removes front item of the queue
template <class ItemType>
void QueueType<ItemType>::DeQueue(ItemType& item)
{
	
	if (IsEmpty())
		throw EmptyQueue();
	else
	{
		m_iFront = (m_iFront + 1) % m_nMaxQueue;
		item = m_pItems[m_iFront];
	}
}

// Print all the items in the queue on screen
template <class ItemType>
void QueueType<ItemType>::Print()
{
	cout << "Queue: ";
	for (int i = (m_iFront + 1) % m_nMaxQueue; i - 1 != m_iRear; i++)
	{
		// i값이 MaxSize - 1보다 크면 0으로 값을 바꿔줌
		if (i > m_nMaxQueue - 1)	i = 0;

		cout << m_pItems[i] << " - ";
	}
	cout << endl;
}
#endif