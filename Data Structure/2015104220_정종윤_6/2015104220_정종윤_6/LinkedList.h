#pragma once
#include <iostream>
using namespace std;

/**
*	@brief	NodeType Structure for doubly linked list
*/
template<typename T>
struct DoublyNodeType
{
	T data;	///< Node Data
	DoublyNodeType<T> *prev;	///< Pointer that pointing pre-node
	DoublyNodeType<T> *next;	///< Pointer that pointing next-node
};

template<typename T> class DoublyUnsortedLinkedList; ///< 프렌드 함수를 쓰기 위한 선언


/**
*	더블 링크드 리스트를 위해 관리하는 이터레이터 클래스
*/
template <typename T>
class DoublyIterator
{
	friend class DoublyUnsortedLinkedList<T>;  // friend class define
public:
	/**
	*	@brief	Default Constructor
	*/
	DoublyIterator(const DoublyUnsortedLinkedList<T>& list) : m_list(list), m_pCurPointer(list.m_pFirst)
	{};

	/**
	*	@brief  Checking if current data in list is null.
	*	@pre	None
	*	@post	None
	*   @return Return true if current data is null, otherwise false
	*/
	bool NotNull();

	/**
	*	@brief  Checking if next data in list is null.
	*	@pre	None
	*	@post	None
	*   @return Return true if next data is null, otherwise false
	*/
	bool NextNotNull();

	/**
	*	@brief  Return the item that in first node in list.
	*	@pre	None
	*	@post	None
	*   @return first node in list
	*/
	T First();

	/**
	*	@brief  Move current pointer to next node.
	*	@pre	List must be initialized.
	*	@post	Move to next node and return current item
	*   @return Next node's item
	*/
	T Next();

	/**
	*	@brief  Return current pointer.
	*	@pre	List must be initialized.
	*	@post	Return current location
	*   @return Current location
	*/
	DoublyNodeType<T>* GetCurrentNode();	///< 현재 node를 리턴

	/**
	*	@brief  Move current pointer to first node
	*	@pre	List must be initialized.
	*	@post	CurrentPointer is on first node
	*/
	void Reset();

	/**
	*	@brief  Move current pointer to pre node.
	*	@pre	List must be initialized.
	*	@post	Move to pre node and return current item
	*   @return Pre node's item
	*/
	T Prev();

private:
	const DoublyUnsortedLinkedList<T>& m_list;	// Reference variable for using list.
	DoublyNodeType<T>* m_pCurPointer;			// Pointer that pointing a current node
};

/**
*	@brief	Doubly Sorted Linked list class
*/
template <typename T>
class DoublyUnsortedLinkedList
{
	friend class DoublyIterator<T>;  // friend class define
public:
	/**
	*	@brief	Default constructor
	*/
	DoublyUnsortedLinkedList();

	/**
	*	@brief	Destructor
	*/
	~DoublyUnsortedLinkedList();

	/**
	*	@brief  Checking if list is full.
	*	@pre	None
	*	@post	None
	*   @return Return true if list is full, otherwise false
	*/
	bool IsFull();

	/**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*	@return Return 1 if list is empyty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
	int GetLength() const;

	/**
	*	@brief	Add item into this list.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Add(T item);

	/**
	*	@brief	Delete existing record.
	*	@pre	ID of data must be exist.
	*	@post	If same ID with primary key exists, delete data from the list.
	*	@param	data	Data that have ID which is the basis of search.
	*	@return	Return 1 if this function works well, otherwise 0.
	*/
	int Delete(T item);


protected:
	DoublyNodeType<T> *m_pFirst;	///< Pointer for pointing a first node.
	DoublyNodeType<T> *m_pLast;		///< Pointer for pointing a last node.
	int m_nLength;					///< Number of node in the list.

};



// 현재 위치의 노드가 Null 인지 판별하는 함수
template<typename T>
bool DoublyIterator<T> ::NotNull()
{
	if (m_pCurPointer == NULL)
		return false;
	else
		return true;
}

//Checking if next data in list is null.
template<typename T>
bool DoublyIterator<T> ::NextNotNull()
{
	if (m_pCurPointer->next == NULL)
		return false;
	else
		return true;
}

//Return the item that in first node in list.
template<typename T>
T DoublyIterator<T>::First()
{
	return m_list.m_pFirst->data;
}

//Move current pointer to next node.
template<typename T>
T DoublyIterator<T>::Next()
{
	if (m_pCurPointer == NULL)
		m_pCurPointer = m_list.m_pFirst;
	else
		m_pCurPointer = m_pCurPointer->next;

	return m_pCurPointer->data;
}

// Return current pointer.
template<typename T>
DoublyNodeType<T>* DoublyIterator<T>::GetCurrentNode()
{
	return m_pCurPointer;
}

// Move current pointer to first node
template<typename T>
void DoublyIterator<T> ::Reset()
{
	m_pCurPointer = m_list.m_pFirst;
	return;
}

// Move current pointer to pre node.
template<typename T>
T DoublyIterator<T>::Prev()
{
	if (m_pCurpointer == NULL)
		m_pCurPointer = m_list.m_pFirst;
	else
		m_pCurPointer = m_pCurPointer->prev;

	return m_pCurPointer->data;
}


//default constructor
template<typename T>
DoublyUnsortedLinkedList<T> ::DoublyUnsortedLinkedList()
{
	m_pFirst = new DoublyNodeType<T>;   ///< 동적할당
	m_pLast = new DoublyNodeType<T>;	///< 동적할당
	m_pFirst->next = m_pLast;			///< 처음 포인터의 next는 마지막을 기리킨다.
	m_pLast->prev = m_pFirst;			///< 마지막 포인터의 prev는 처음을 가리킨다.
	m_nLength = 0;						///< 리스트의 길이는 0
	m_pFirst->prev = NULL;				///< 처음 포인터의 prev는 없다.(NULL)
	m_pLast->next = NULL;				///< 마지막 포인터의 next는 없다.(NULL)
}

//Destructor
template<typename T>
DoublyUnsortedLinkedList<T> ::~DoublyUnsortedLinkedList()
{
	MakeEmpty();  ///< 리스트 비워냄
}


//Checking if list is full.
template<typename T>
bool DoublyUnsortedLinkedList<T> ::IsFull()
{
	DoublyNodeType<T>* Location;
	try
	{
		Location = new DoublyNodeType<T>;  // 동적 메모리 할당
		delete Location;
		return false;   // 성공시 false.(가득 차있지 않다.)
	}
	catch (bad_alloc exception)  // 가득 차있는경우
	{
		return true;			// true 반환
	}
}


//Initialize list to empty state.
template<typename T>
void DoublyUnsortedLinkedList<T> ::MakeEmpty()
{
	DoublyNodeType<T> *pItem;
	DoublyIterator<T> Iter(*this); // this 포인터를 이용하여 Iterator 선언
	while (Iter.NotNull())
	{
		pItem = Iter.m_pCurPointer;
		Iter.Next();
		delete pItem;
	}

	m_pFirst = m_pLast = NULL;
	return;
}

//Get number of elements in the list.
template<typename T>
int DoublyUnsortedLinkedList<T> ::GetLength() const
{
	return m_nLength;
}


//Add item into this list.
template<typename T>
int DoublyUnsortedLinkedList<T> ::Add(T item)
{
	if (!IsFull())
	{
		DoublyNodeType<T>* tmp = new DoublyNodeType<T>;
		DoublyIterator<T> Iter(*this);
		tmp->data = item;
		Iter.Reset();
		if (m_nLength == 0) // 처음에추가할 때
		{
			DoublyNodeType<T>* dummy;
			dummy = Iter.GetCurrentNode();
			tmp->prev = dummy;
			tmp->next = dummy->next;
			dummy->next->prev = tmp;
			dummy->next = tmp;
			m_nLength++;
			return 1;
		}

		while ((Iter.GetCurrentNode()->next) != m_pLast)
			Iter.Next();

		if ((tmp->data) == (Iter.GetCurrentNode()->next->data))
			return 0;  // data가 이미 존재하는 경우. 실패.

		DoublyNodeType<T>* dummy;
		dummy = Iter.GetCurrentNode();
		tmp->prev = dummy;
		tmp->next = dummy->next;
		dummy->next->prev = tmp;
		dummy->next = tmp;

		m_nLength++;

		return 1;
	}
	else
	{
		cout << " 리스트가 가득 차있습니다. " << endl;
		return 0;  //실패
	}
}


//Delete existing record.
template<typename T>
int DoublyUnsortedLinkedList<T> ::Delete(T item)
{
	DoublyIterator<T> Iter(*this);
	Iter.Reset();
	int i;
	for (i = 0; i<m_nLength; i++)
	{
		Iter.Next();
		if (Iter.GetCurrentNode()->data == item)
		{
			DoublyNodeType<T>* tmp = new DoublyNodeType<T>;
			DoublyNodeType<T>* dummy;
			dummy = Iter.GetCurrentNode();
			tmp = Iter.GetCurrentNode();
			dummy->prev->next = dummy->next;
			dummy->next->prev = dummy->prev;
			delete tmp;
			break;
		}
	}

	if (i == m_nLength)
		return 0;

	m_nLength--;
	return 1;
}