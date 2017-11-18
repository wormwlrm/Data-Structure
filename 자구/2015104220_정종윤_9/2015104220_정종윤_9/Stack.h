#include <iostream>
using namespace std;


/**
*	@brief	Exception class thrown by Push when stack is full.
*/
class FullStack
{
public:
	/**
	*	@brief	Display a message for full stack on screen.
	*/
	void print()
	{
		cout << "\tFullstack exception thrown." << endl;
	}
};

/**
*	@brief	Exception class thrown by Pop and Top when stack is empty.
*/
class EmptyStack
{
public:
	/**
	*	@brief	Display a message for empty stack on screen.
	*/
	void print()
	{
		cout << "\tEmtpyStack exception thrown." << endl;
	}
};

/**
*	@brief	Stack class.
*	@details	This class processes as Last In, First Out (LIFO).
*/
template<typename ItemType>
class StackType
{
public:

	/**
	*	@brief	Allocate dynamic array whose size is maxStack.
	*	@pre	The maxStack is defined
	*	@post	Member of items points the allocated array.
	*/
	StackType();

	/**
	*	@brief	Allocate dynamic array whose size is maxStack.
	*	@pre	The maxStack is defined
	*	@post	Member of items points the allocated array.
	*/
	StackType(int max);

	/**
	*	@brief	Destruct the object. Free the array dynamically allocated.
	*	@pre	Release memory for stack pointer.
	*	@post	none.
	*/
	~StackType();

	/**
	*	@brief	Determines whether the stack is full.
	*	@pre	Stack has been initialized.
	*	@post	Function value = (stack is full)
	*/
	bool IsFull() const;

	/**
	*	@brief	Determines whether the stack is empty.
	*	@pre	Stack has been initialized.
	*	@post	Function value = (stack is empty)
	*/
	bool IsEmpty() const;

	/**
	*	@brief	make stack to empty.
	*	@pre	None
	*	@post	stack is empty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Adds newItem to the top of the stack.
	*	@pre	Stack has been initialized.
	*	@post	If (stack is full), FullStack exception is thrown; otherwise, newItem is at the top of the stack.
	*/
	void Push(ItemType item);

	/**
	*	@brief	Removes top item from the stack.
	*	@pre	Stack has been initialized.
	*	@post	If (stack is empty), EmptyStack exception is thrown; otherwise, top element has been removed from stack.
	*/
	void Pop(ItemType &item);

	/**
	*	@brief	Returns a copy of top item on the stack.
	*	@pre	Stack has been initialized.
	*	@post	If (stack is empty), EmptyStack exception is thrown; otherwise, top element has been removed from stack.
	*/
	ItemType Top();

	/**
	*	@brief	Print all the items in the stack on screen
	*	@pre	Stack has been initialized.
	*	@post	None.
	*/
	void Print();

private:
	int m_iTop;			///< Number of elements.
	int m_nMaxStack;	///< Max stack size
	ItemType *m_pItems;	///< Pointer for a stack.
};


/////////////////////////// Member functions /////////////////////////

// Allocate dynamic array whose size is maxStack.
template<typename ItemType>
StackType<ItemType>::StackType()
{

	m_nMaxStack = 100;
	m_pItems = new ItemType[m_nMaxStack];
	MakeEmpty();
}

// Allocate dynamic array whose size is maxStack.
template<typename ItemType>
StackType<ItemType>::StackType(int max)
{
	maxStack = max;
	items = new ItemType[maxStack];
	MakeEmpty();

}

// Destruct the object. Free the array dynamically allocated.
template<typename ItemType>
StackType<ItemType>::~StackType()
{

	delete[](ItemType*)m_pItems;
}

// make stack to empty.
template<typename ItemType>
void StackType<ItemType>::MakeEmpty()
{
	m_iTop = -1;
}

// Determines whether the stack is full.
template<typename ItemType>
bool StackType<ItemType>::IsEmpty() const
{
	if (m_iTop <= -1)
		return true;
	else
		return false;
}

// Determines whether the stack is empty.
template<typename ItemType>
bool StackType<ItemType>::IsFull() const
{

	if (m_iTop >= m_nMaxStack - 1)
		return true;
	else
		return false;
}

// Adds newItem to the top of the stack.
template<typename ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{

	if (IsFull())
		throw FullStack();
	else
	{
		m_iTop++;
		m_pItems[m_iTop] = newItem;
	}
}

// Removes top item from the stack.
template<typename ItemType>
void StackType<ItemType>::Pop(ItemType &item)
{
	if (IsEmpty())
		throw EmptyStack();
	else
	{
		item = Top();
		m_iTop--;
	}
}

// Removes top item from the stack.
template<typename ItemType>
ItemType StackType<ItemType>::Top()
{
	if (IsEmpty())
		throw EmptyStack();
	else
	{
		return m_pItems[m_iTop];
	}
}

// Print all the items in the stack on screen
template<typename ItemType>
void StackType<ItemType>::Print()
{

	cout << "\tStack : ";

	for (int i = m_iTop; i >= 0; i--)
		cout << m_pItems[i] << " - ";

	cout << endl;
}