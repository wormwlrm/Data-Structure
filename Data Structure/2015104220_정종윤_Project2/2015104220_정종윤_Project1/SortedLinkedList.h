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
	*	@brief	Idx ��°�� �ִ� ��ũ�� ����Ʈ ��带 ��ȯ
	*	@post	Idx ��°�� �ִ� ��ũ�� ����Ʈ ��尡 ��ȯ��
	*	@param	data	�ε���
	*	@return	�ش� ��ũ�� ����Ʈ ���
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
	//����Ʈ���� ��� node ����
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void LinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;

	while (m_pList != NULL) // ����Ʈ�� ó�� ���� �������� ���� �� ����
	{
		tempPtr = m_pList; // ���� ó�� ������ ���� �ӽ÷� ������ ��
		m_pList = m_pList->next; // next ���� ó�� ������ ������ ��
		delete tempPtr; // ������ ���� �����Ѵ�.
	}

	m_nLength = 0; // ���̸� 0���� �ٲ�
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
	// ����Ʈ �ʱ�ȭ
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre; // Cur ���� ������

	T dummy;

	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	// list �� node �� �������� �ʴ� ���
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		// ���� ������ node �� �̵� �� ����
		while (1)
		{
			// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;

			// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);

			// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->data >= node->data) // 
			{
				if (pre == NULL) // node�� ���� ���� ���
				{
					m_pList = node;
					node->next = m_pCurPointer;
					break;
				}
				// ������ node �� ���ο� node ����
				pre->next = node;
				node->next = m_pCurPointer;
				break;
			}

			if (m_pCurPointer->next == NULL) // node�� ���� ū ���
			{
				m_pCurPointer->next = node;
				break;
			}
		}
	}
	m_nLength++; // ���� ����
	return 1;
}


// Retrieve list element whose key matches item's key (if present).
template <typename T>
int LinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location; // ��� ��ġ ������ ����

	location = m_pList; // ��ũ�� ����Ʈ ���� ó������ �̵�
	found = false; // �߰� ���� Ȯ�� ����
	moreToSearch = (location != NULL);

	while (moreToSearch && !found) // ����Ʈ�� �� ���� �ְų� ã�� ���� ���
	{
		if (item == location->data) // ã�� ���
		{
			found = true; // �߰� ���θ� True����
			item = location->data;
		}
		else // ã�� ���� ���
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
	// current pointer �ʱ�ȭ
	m_pCurPointer = NULL;
}


// Gets the next element in list.
template <typename T>
void LinkedList<T>::GetNextItem(T& item)
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;

	//item �� current position �� info �� ����
	item = m_pCurPointer->data;
}

template <typename T>
int LinkedList<T>::Delete(T& item)
{
	if (m_nLength == 0) // ���̰� 0�� ��� ���� ó��
	{
		return -1;
	}

	ResetList();
	NodeType<T>* pre; // CurrentPointer�� ���� List�� ����Ű�� ������
	NodeType<T>* target;
	T dummy;

	target = m_pList;
	m_pCurPointer = m_pList;

	if (m_pList->data == item) // ù ��° �����͸� ������ ���
	{
		m_pList = m_pList->next;
		delete target;
		m_nLength--;
		return 1;
	}
	else
	{
		while (m_pCurPointer->next != NULL) // �̿��� �����͸� ������ ���
		{
			pre = m_pCurPointer;
			GetNextItem(dummy);
			if (m_pCurPointer->data == item) // ������ ������ �߰� ��
			{
				pre->next = pre->next->next; //Ÿ���� ���� ��°�� �ٴ��� ��°�� ����Ű���� ����
				delete m_pCurPointer;
				m_nLength--;
				return 1;
			}
		}
		if (m_pCurPointer->next == NULL) // ������ �����͸� ã�� ���� ���
		{
			return 0;
		}
	}
	return 0;
}

template <typename T>
int LinkedList<T>::Replace(T& item,int changingWhat, string temp)
{
	if (m_nLength == 0) // ���̰� 0�� ��� ���� ó��
	{
		return -1;
	}

	NodeType<T>* target; // ��ü�� ����
	target = m_pList;

	if (!(m_pList->data == item))	//���� ������ �����Ͱ� Ÿ���� �ƴϸ�
	{
		while (!(target->data == item)) // Ÿ���� �̵�
		{
			target = target->next;

			if (target == NULL) // ã���� �ϴ� �����Ͱ� ���� ���
			{
				return 0;
			}
		}
	}

	// ��ü�ϰ��� �ϴ� ������ �߰� ��

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
	if (m_nLength == 0) // ���̰� 0�� ��� ���� ó��
	{
		return -1;
	}

	NodeType<T>* target; // ��ü�� ����
	target = m_pList;

	if (!(m_pList->data == item))	//���� ������ �����Ͱ� Ÿ���� �ƴϸ�
	{
		while (!(target->data == item)) // Ÿ���� �̵�
		{
			target = target->next;

			if (target == NULL) // ã���� �ϴ� �����Ͱ� ���� ���
			{
				return 0;
			}
		}
	}
	
	// ��ü�ϰ��� �ϴ� ������ �߰� ��

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
	if (m_nLength == 0) // ���̰� 0�� ��� ���� ó��
	{
		return -1;
	}

	NodeType<T>* target; // ��ü�� ����
	target = m_pList;

	if (!(m_pList->data == item))	//���� ������ �����Ͱ� Ÿ���� �ƴϸ�
	{
		while (!(target->data == item)) // Ÿ���� �̵�
		{
			target = target->next;

			if (target == NULL) // ã���� �ϴ� �����Ͱ� ���� ���
			{
				return 0;
			}
		}
	}

	// ��ü�ϰ��� �ϴ� ������ �߰� ��
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
