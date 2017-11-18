#pragma once
#include "HeapBase.h"

#define MAX_SIZE 20

/**
*	@brief	Max Heap
*/
template <typename T>
class MaxHeap : public HeapBase<T>
{
public:
	/**
	*	@brief	�⺻ ������
	*/
	MaxHeap();

	/**
	*	@brief	������
	*/
	MaxHeap(int size) : m_nMaxSize(size)
	{
		m_iLastNode = 0;
		m_pHeap = new T[m_nMaxSize];
	}
	/**
	*	@brief	�Ҹ���
	*/
	~MaxHeap();

	/**
	*	@brief	Add item into this heap.
	*	@pre	None.
	*	@post	Item is inserted in this heap.
	*	@return	1 if this function works well, otherwise 0.
	*/
	virtual int Add(T item);

	/**
	*	@brief	Delete item from this heap.
	*	@pre	Item that want to delete must exist
	*	@post	If same ID with primary key exists, delete data from the list.
	*	@param	[data] Item that want to delete
	*/
	virtual int Delete(T data);

	/**
	*	@brief	Retrieve tree element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key, then the element's data is copied to the item.
	*	@param	[item] Data that user want to search.
	*			[found] Save data found
	*/
	virtual void Retrieve(T& item, bool& found);

	/**
	*	@brief	Pop a root node
	*	@pre	root node must be initialized
	*	@post	root node popped
	*	@return	Popped Node
	*/
	virtual T Pop();

	/**
	*	@brief	Sort heap from up to down
	*	@pre	Must be intialized
	*	@post	Heap sorted
	*	@param	[iparent] Parents node, [ibottom] Key node
	*/
	virtual void ReheapDown(int iparent, int ibottom);

	/**
	*	@brief	Sort heap from down to up
	*	@pre	Must be intialized
	*	@post	Heap sorted
	*	@param	[iroot] Root node, [ibottom] Ket node
	*/
	virtual void ReheapUp(int iroot, int ibottom);

	/**
	*	@brief	Delete item on heap
	*	@pre	Must be initialized
	*	@post	Data deleted
	*	@param	[item] item which want to delete, [found] is it found, [iparent] Parents node
	*/
	virtual void Delete(T item, bool& found, int iparent);

	/**
	*	@brief	Retreive item on heap
	*	@pre	Must be initialized
	*	@post	Search Data and save item
	*	@param	[item] item which want to search, [found] is it found, [iparent] Parents node
	*/
	virtual void Retrieve(T& item, bool& found, int iparent);
};

//Default constructor
template <typename T>
MaxHeap<T>::MaxHeap()
{
	m_iLastNode = 0;
	m_nMaxSize = MAX_SIZE;
	m_pHeap = new T[m_nMaxSize];
}

//Destructor
template <typename T>
MaxHeap<T>::~MaxHeap()
{
	MakeEmpty();	
}

//Add item into this heap.
template <typename T>
int MaxHeap<T>::Add(T item)
{
	if (isFull()) // ���� ���� ������ ��� ����ó��
		return 0;

	m_pHeap[m_iLastNode++] = item; // �������� ����
	ReheapUp(0, m_iLastNode - 1); // �Ʒ��������� ������
	return 1;
}

//Sort heap from up to down
template <typename T>
void MaxHeap<T>::ReheapDown(int iparent, int ibottom)
{
	int max;
	int right;
	int left;
	// ���������� �� ����
	left = iparent * 2 + 1; // ����
	right = iparent * 2 + 2; // ������
	if (left <= ibottom)
	{
		if (left == ibottom)
			max = left;
		else
		{
			if (m_pHeap[left] <  m_pHeap[right] || m_pHeap[left] == m_pHeap[right])
				max = right;
			else
				max = left;
		}
		if (m_pHeap[iparent] < m_pHeap[max]) //�θ��� ���� �� ���� ���
		{
			swap(m_pHeap[iparent], m_pHeap[max]);	//��ġ �ٲ�
			ReheapDown(max, ibottom);	//��� �ݺ� 
		}
	}
}

//Sort heap from down to up
template <typename T>
void MaxHeap<T>::ReheapUp(int iroot, int ibottom)
{
	int parent;
	//�Ʒ��������� �� ����
	if (ibottom > iroot) // ���� ó��
	{
		parent = (ibottom - 1) / 2;
		if (m_pHeap[parent] < m_pHeap[ibottom]) // �θ��� ���� �� ���� ���
		{
			swap(m_pHeap[parent], m_pHeap[ibottom]);  //��ġ �ٲ�
			ReheapUp(iroot, parent);  // ��� �ݺ�
		}
	}
}

//Delete item from this heap.
template<typename T>
int MaxHeap<T>::Delete(T data)
{
	if (isEmpty())	//���� ������� ��� ���� ó��
		return 0;

	bool found = false;
	Delete(data, found, 0); // ����

	return found;
}

//Delete item from this heap.
template <typename T>
void MaxHeap<T>::Delete(T item, bool& found, int iparent)
{
	if (m_pHeap[iparent] == item)	//���� ��ġ�� ���
	{
		m_pHeap[iparent] = m_pHeap[--m_iLastNode]; // ����
		ReheapDown(iparent, m_iLastNode - 1);  // ���������� ������
		found = true;
		return;
	}
	else
		Delete(item, found, ++iparent); // ã�� ������ ��� �ݺ�
}

//Retrieve tree element whose key matches item's key (if present).
template <typename T>
void MaxHeap<T>::Retrieve(T& item, bool& found, int iparent)
{
	found = false;
	if (isEmpty()) // ���� ����ִ� ��� ����ó��
		return;
	if (iparent == m_iLastNode) // ���������� ã�� ���� ��� ����ó��
		return;

	if (m_pHeap[iparent] == item) // ã�� ���
	{
		item = m_pHeap[iparent]; // Item������ ������ ����
		found = true;
	}
	else
		Retrieve(item, found, iparent + 1); // ã�� ������ ��� �ݺ�
}

//Retrieve tree element whose key matches item's key (if present).
template <typename T>
void MaxHeap<T>::Retrieve(T& item, bool& found)
{
	Retrieve(item, found, 0);
}

//Pop a root node
template<typename T>
T MaxHeap<T>::Pop()
{
	T temp;
	if (isEmpty())	//���� ������� ��� ����ó��
		return temp;

	temp = m_pHeap[0];  // Root Node ����
	m_pHeap[0] = m_pHeap[--m_iLastNode]; //Root Node ����
	ReheapDown(0, m_iLastNode - 1); //���������� �� ����
	return temp;
}