#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename T>
struct NodeType
{
	T data;	///< A data for each node.
	NodeType* next;	///< A node pointer to point succeed node.
};

template <typename T>
class LinkedList
{
public:
	/**
	*	default constructor.
	*/
	LinkedList();

	/**
	*	destructor.
	*/
	~LinkedList();

	/**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
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
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Get(T& item);

	/**
	*	@brief	Initialize current pointer for an iteration through the list.
	*	@pre	None.
	*	@post	current pointer is prior to list. current pointer has been initialized.
	*/
	void ResetList();

	/**
	*	@brief	Get the next element in list.
	*	@pre	current pointer is defined. Element at current pointer is not last in list.
	*	@post	current pointer is updated to next position. item is a copy of element at current pointer.
	*/
	void GetNextItem(T& item);

	/**
	*	@brief	Delete existing record.
	*	@pre	ID of data must be exist.
	*	@post	If same ID with primary key exists, delete data from the list.
	*	@param	data	Data that have ID which is the basis of search.
	*	@return	Return 1 if this function works well, otherwise 0.
	*/
	int Delete(T& data);

	/**
	*	@brief	Update existing record.
	*	@pre	ID of data must be exist.
	*	@post	If same ID with primary key exists, update data from the list.
	*	@param	data	Data that have ID which is the basis of search
	*	@return	Return 1 if this function works well, otherwise 0.
	*/
	int Replace(T& data, int changingWhat, string temp);

	/**
	*	@brief	Update existing record.
	*	@pre	ID of data must be exist.
	*	@post	If same ID with primary key exists, update data from the list.
	*	@param	data	ChangingWhat is a code that what user want to change remains into item
	*	@return	Return 1 if this function works well, otherwise 0.
	*/
	int Update(T& data, int changingWhat, string item);

	/**
	*	@brief	Update existing record.
	*	@pre	ID of data must be exist.
	*	@post	If same ID with primary key exists, update data from the list.
	*	@param	data	ChangingWhat is a code that what user want to change remains into item
	*	@return	Return 1 if this function works well, otherwise 0.
	*/
	int Update(T& data, int changingWhat, int item);

	/**
	*	@brief	Idx 번째에 있는 링크드 리스트 노드를 반환
	*	@post	Idx 번째에 있는 링크드 리스트 노드가 반환됨
	*	@param	data	인덱스
	*	@return	해당 링크드 리스트 노드
	*/
	T at(int idx)
	{
		ResetList();
		m_pCurPointer = m_pList;
		for (int i = 0; i < idx; i++)
		{
			m_pCurPointer = m_pCurPointer->next;
		}
		return m_pCurPointer->data;
	}

private:
	NodeType<T>* m_pList;	///< Pointer for pointing a first node.
	NodeType<T>* m_pCurPointer;	///< Node pointer for pointing current node to use iteration.
	int m_nLength;	///< Number of node in the list.
};


// Class constructor
template <typename T>
LinkedList<T>::LinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}


// Class destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
	//리스트내의 모든 node 제거
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void LinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
	NodeType<T>* tempPtr;

	while (m_pList != NULL) // 리스트의 처음 값이 존재하지 않을 때 까지
	{
		tempPtr = m_pList; // 현재 처음 포인터 값을 임시로 저장한 후
		m_pList = m_pList->next; // next 값을 처음 값으로 변경한 뒤
		delete tempPtr; // 저장한 값을 삭제한다.
	}

	m_nLength = 0; // 길이를 0으로 바꿈
}


// Get number of elements in the list.
template <typename T>
int LinkedList<T>::GetLength() const
{
	return m_nLength;
}


// Add item into this list.
template <typename T>
int LinkedList<T>::Add(T item)
{
	// 리스트 초기화
	ResetList();

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre; // Cur 이전 포인터

	T dummy;

	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		// 가장 마지막 node 로 이동 후 삽입
		while (1)
		{
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);

			// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->data >= node->data) // 
			{
				if (pre == NULL) // node가 가장 작은 경우
				{
					m_pList = node;
					node->next = m_pCurPointer;
					break;
				}
				// 마지막 node 와 새로운 node 연결
				pre->next = node;
				node->next = m_pCurPointer;
				break;
			}

			if (m_pCurPointer->next == NULL) // node가 가장 큰 경우
			{
				m_pCurPointer->next = node;
				break;
			}
		}
	}
	m_nLength++; // 길이 증가
	return 1;
}


// Retrieve list element whose key matches item's key (if present).
template <typename T>
int LinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location; // 노드 위치 포인터 변수

	location = m_pList; // 링크드 리스트 제일 처음으로 이동
	found = false; // 발견 여부 확인 변수
	moreToSearch = (location != NULL);

	while (moreToSearch && !found) // 리스트가 더 남아 있거나 찾지 않은 경우
	{
		if (item == location->data) // 찾을 경우
		{
			found = true; // 발견 여부를 True으로
			item = location->data;
		}
		else // 찾지 못한 경우
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}

	if (found)
		return 1;
	else
		return 0;
}


// Initializes current pointer for an iteration through the list.
template <typename T>
void LinkedList<T>::ResetList()
{
	// current pointer 초기화
	m_pCurPointer = NULL;
}


// Gets the next element in list.
template <typename T>
void LinkedList<T>::GetNextItem(T& item)
{
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;

	//item 에 current position 의 info 를 삽입
	item = m_pCurPointer->data;
}

template <typename T>
int LinkedList<T>::Delete(T& item)
{
	if (m_nLength == 0) // 길이가 0일 경우 예외 처리
	{
		return -1;
	}

	ResetList();
	NodeType<T>* pre; // CurrentPointer의 이전 List를 가리키는 포인터
	NodeType<T>* target;
	T dummy;

	target = m_pList;
	m_pCurPointer = m_pList;

	if (m_pList->data == item) // 첫 번째 데이터를 삭제할 경우
	{
		m_pList = m_pList->next;
		delete target;
		m_nLength--;
		return 1;
	}
	else
	{
		while (m_pCurPointer->next != NULL) // 이외의 데이터를 삭제할 경우
		{
			pre = m_pCurPointer;
			GetNextItem(dummy);
			if (m_pCurPointer->data == item) // 삭제할 데이터 발견 시
			{
				pre->next = pre->next->next; //타겟의 다음 번째를 다다음 번째를 가르키도록 변경
				delete m_pCurPointer;
				m_nLength--;
				return 1;
			}
		}
		if (m_pCurPointer->next == NULL) // 삭제할 데이터를 찾지 못할 경우
		{
			return 0;
		}
	}
	return 0;
}

template <typename T>
int LinkedList<T>::Replace(T& item,int changingWhat, string temp)
{
	if (m_nLength == 0) // 길이가 0일 경우 예외 처리
	{
		return -1;
	}

	NodeType<T>* target; // 교체할 변수
	target = m_pList;

	if (!(m_pList->data == item))	//만약 최초의 데이터가 타겟이 아니면
	{
		while (!(target->data == item)) // 타겟을 이동
		{
			target = target->next;

			if (target == NULL) // 찾고자 하는 데이터가 없을 경우
			{
				return 0;
			}
		}
	}

	// 교체하고자 하는 데이터 발견 시

	switch (changingWhat)
	{
	case 1:
		item->setName(temp);
		break;
	case 2:
		item->setPassword(temp);
		break;
	default:
		break;
	}
	target->data = item;

	return 1;
}

template <typename T>
int LinkedList<T>:: Update(T& item, int changingWhat, string temp)
{
	if (m_nLength == 0) // 길이가 0일 경우 예외 처리
	{
		return -1;
	}

	NodeType<T>* target; // 교체할 변수
	target = m_pList;

	if (!(m_pList->data == item))	//만약 최초의 데이터가 타겟이 아니면
	{
		while (!(target->data == item)) // 타겟을 이동
		{
			target = target->next;

			if (target == NULL) // 찾고자 하는 데이터가 없을 경우
			{
				return 0;
			}
		}
	}
	
	// 교체하고자 하는 데이터 발견 시

	switch (changingWhat)
	{
	case 1:
		item->setName(temp);
		break;
	case 3:
		item->setImage(temp);
		break;
	default:
		break;
	}
	target->data = item;

	return 1;
}

template <typename T>
int LinkedList<T>::Update(T& item, int changingWhat, int temp)
{
	if (m_nLength == 0) // 길이가 0일 경우 예외 처리
	{
		return -1;
	}

	NodeType<T>* target; // 교체할 변수
	target = m_pList;

	if (!(m_pList->data == item))	//만약 최초의 데이터가 타겟이 아니면
	{
		while (!(target->data == item)) // 타겟을 이동
		{
			target = target->next;

			if (target == NULL) // 찾고자 하는 데이터가 없을 경우
			{
				return 0;
			}
		}
	}

	// 교체하고자 하는 데이터 발견 시
	int tempstock;
	switch (changingWhat)
	{
	case 1:
		item->setPrice(temp);
		break;
	case 4:
		tempstock = item->getStock();
		item->setStock(temp + tempstock);
		break;
	default:
		break;
	}
	target->data = item;

	return 1;
}
