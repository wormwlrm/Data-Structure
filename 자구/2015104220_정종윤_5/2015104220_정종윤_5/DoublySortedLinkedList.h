#ifndef _DOUBLY_LINKED_LIST_H
#define _DOUBLY_LINKED_LIST_H

/**
*	@brief	NodeType Structure for doubly linked list
*/
template <typename T>
struct DoublyNodeType
{
	T data;	///< Node Data
	DoublyNodeType* prev;	///< Pointer that pointing pre-node
	DoublyNodeType* next;	///< Pointer that pointing next-node
};

/**
*	@brief	Doubly Sorted Linked list class
*/
template <typename T>
class DoublySortedLinkedList; // friend class define
/**
*	@brief	Doubly Linked List Iterator class
*/
template <typename T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;		//Friend class

public:
	/**
	*	@brief	Default Constructor
	*/
	template <typename T>
	DoublyIterator(const DoublySortedLinkedList<T>& list)
		: m_List(list), m_pCurPointer(list.m_pFirst)
	{
	}

	/**
	*	@brief	Checking if current data in list is null.
	*/
	bool NotNull(){ return (m_pCurPointer != NULL); }

	/**
	*	@brief	Checking if next data in list is null.
	*/
	bool NextNotNull(){ return (m_pCurPointer->next != NULL); }

	/**
	*	@brief	Return the item that in first node in list. 
	*/
	template <typename T>
	T First(){ return m_List.m_pFirst }

	/**
	*	@brief	Move current pointer to next node.
	*/
	template <typename T>
	T Next()
	{
		m_pCurPointer = m_pCurPointer->next;
		return (m_pCurPointer != NULL) ? m_pCurPointer->data : T();
	}

	/**
	*	@brief	Return current pointer.
	*/
	template <typename T>
	DoublyNodeType<T> GetCurrentNode() { return *m_pCurPointer; }

private:
	const DoublySortedLinkedList<T>& m_List;	// Reference variable for using list.
	DoublyNodeType<T>* m_pCurPointer;			// Pointer that pointing a current node
};

template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator <T>;
public:
	/**
	*	@brief	Default constructor
	*/
	DoublySortedLinkedList();

	/**
	*	@brief	Destructor
	*/
	~DoublySortedLinkedList();

	/**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*	@return Return 1 if list is empyty.
	*/
	int MakeEmpty();

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
	*	@param	[item] Data that user want to search.
	*	@return		1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Get(T& item);

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
	*	@param	data	Data that have ID which is the basis of search.
	*	@return	Return 1 if this function works well, otherwise 0.
	*/
	int Replace(T& data);


private:
	DoublyNodeType<T>* m_pFirst;///< Pointer for pointing a first node.
	DoublyNodeType<T>* m_pLast;	///< Pointer for pointing a last node.

//	NodeType<T>* m_pCurPointer;		///< Node pointer for pointing current node to use iteration.
	int m_nLength;	///< Number of node in the list.
};


// Class Constructor
template <typename T>
DoublySortedLinkedList<T>::DoublySortedLinkedList()
{
	//Ŭ���� ������ �ʱ�ȭ
	m_nLength = 0;
	m_pFirst = NULL;
	m_pLast = NULL;
}


// Class Destructor
template <typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList()
{
	MakeEmpty(); //����Ʈ ���� ��� node ����
}


// Initialize list to empty state.
template <typename T>
int DoublySortedLinkedList<T>::MakeEmpty()
{
	DoublyNodeType<T>* pItem;		// ������ �������� ����Ű�� ������
	DoublyIterator<T> itor(*this);	// this �����͸� �̿��Ͽ� iterator ����

	while (itor.NotNull())	//CurPointer�� ����ų ���� ���� ���� ���� ������
	{
		pItem = itor.m_pCurPointer; //���ʰ��� ���� �� ���� ���� ���� ��Ų��.
		itor.Next<T>();
		delete pItem;	//������ ���� ����
	}
	
	m_pFirst = m_pLast = NULL; //������ �����͸� ����.
	m_nLength = 0; //���� �ʱ�ȭ
		
	return 1;
}


// Get number of elements in the list.
template <typename T>
int DoublySortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}


// Add item into this list.
template <typename T>
int DoublySortedLinkedList<T>::Add(T item)
{
	DoublyNodeType<T> *node = new DoublyNodeType<T>; // ����Ʈ�� ���� �߰��� Node �� �����Ҵ����� ����
		
	node->data = item; // item�� ���� �Է�
	node->next = NULL;
	node->prev = NULL;

	
	if (!m_nLength) // ���� ����Ʈ�� �������� �ʴ� ���
	{
		m_pFirst = node;
	}
	
	else // ����Ʈ�� Node�� �ϳ� �̻� �����ϴ� ���
	{
		DoublyIterator<T> itor(*this);	// iterator ����, �Ķ���ͷ� *this�� �����鼭 m_pFirst�� ���� �ʱ�ȭ

		while (true)
		{
			DoublyNodeType<T> *cur = itor.m_pCurPointer; // NodeType ������ *Cur�� iterator�� �ʱ�ȭ
			if (cur->data >= node->data) // Cur�� �����Ͱ� Node�� �����ͺ��� ū ���
			{
				if (cur->prev != NULL) // Cur�� �����Ͱ� Node�� �����ͺ��� ũ��, Cur�� First�� �ƴ� �� : ����Ʈ�� Cur ��° ������ ����
					cur->prev->next = node;
				else // Cur�� �����Ͱ� Node�� �����ͺ��� ũ��, Cur�� First�϶� : ����Ʈ�� ���� ���� ������ ����
					m_pFirst = node;
				
				node->prev = cur->prev; // Node�� ������ ���� �����͵��� ���� ����
				cur->prev = node;
				node->next = cur;

				m_nLength++; //�������� �� ����
				return 1;
			}
			
			if (cur->next == NULL) // Cur�� Next�� Null�� ��� : ����Ʈ�� ���� ū ������ ����
			{
				cur->next = node; // ����Ʈ�� ������ Node �� ����
				node->prev = cur;
				break;
			}
			itor.Next<T>();	//���� Node�� �̵�.
		}
	}
		
	m_nLength++; //���� ���� �� ����
	return 1;
}


// Retrieve list element whose key matches item's key (if present).
template <typename T>
int DoublySortedLinkedList<T>::Get(T& item)
{
	DoublyIterator<T> itor(*this);	// this �����͸� �̿��Ͽ� iterator ����

	while (itor.NotNull())	//itor�� Null�� �ƴ� �� ���� �ݺ�
	{
		if (item == itor.GetCurrentNode<T>().data)	//���� Node�� �����Ͱ� ã���ִ� item�� ���� ���
		{
			item = itor.GetCurrentNode<T>().data;	//Current Data�� item�� ����
			return 1;		//���� ��ȯ
		}
		else if (item <= itor.GetCurrentNode<T>().data)	//Sorted Linked List�̹Ƿ� Current Node�� Data�� ���� �� ũ�� ���� ���
			return 0;		//���� ��ȯ
		itor.Next<T>();		//Node �̵�
	}
		
	return 0; //���� ��ȯ
}

// Delete the item in the list whose key matches item's key (if present).
template <typename T>
int DoublySortedLinkedList<T>::Delete(T& item)
{
	if (m_nLength == 0) // List�� ���̰� 0�� ��� ���� ó��
	{
		cout << "\n\tList is Empty" << endl;
		return 0;
	}
	DoublyIterator<T> itor(*this);	// this �����͸� �̿��Ͽ� iterator ����
	DoublyNodeType<T> *cur_node;	// ������ Node�� ����Ű�� ������ ����

	while (itor.NotNull())	//itor�� Null�� �ƴ� �� ���� �ݺ�
	{
		cur_node = itor.m_pCurPointer;	//���� CurPointer�� ����Ű�� ��带 ������

		if (item == cur_node->data)	// ������ item�� ã�� ���
		{
			if (cur_node->prev != NULL)	// ������ Node�� ù ��°�� �ƴ� ���
				cur_node->prev->next = cur_node->next;	//���� ���� ���� ��带 ����

			else						// ������ Node�� ù��°�� ���
				m_pFirst = cur_node->next;	//ù ��° ��带 ���� ���� ����

			if (cur_node->next != NULL)	// ������ Node�� �������� �ƴ� ���
				cur_node->next->prev = cur_node->prev;	//���� ���� ���� ��带 ����

			else						// ������ Node�� �������� ���
				m_pLast = cur_node->prev;	//������ ��带 ���� ���� ����

			delete cur_node;	//�̹� ��带 ����
			m_nLength--;		//���� ����
			return 1;		//���� ��ȯ
		}
		else if (item <= cur_node->data)	//Sorted Linked List�̹Ƿ� Current Node�� Data�� ���� �� ũ�� ���� ���
			return 0;	//���� ��ȯ
		itor.Next<T>();		//���� ���� �̵�.
	}
	//���� ����
	return 0;
}

// Replace the item in the list whose key matches item's key (if present).
template <typename T>
int DoublySortedLinkedList<T>::Replace(T& item)
{
	if (m_nLength == 0) // List�� ���̰� 0�� ��� ���� ó��
	{
		cout << "\n\tList is Empty" << endl;
		return 0;
	}

	DoublyIterator<T> itor(*this);	// this �����͸� �̿��Ͽ� iterator ����
	DoublyNodeType<T> *cur_node;	// ������ Node�� ����Ű�� ������ ����

	while (itor.NotNull())	//itor�� Null�� �ƴ� �� ���� �ݺ�
	{
		cur_node = itor.m_pCurPointer;	//�̹� ��带 ������
		if (item == cur_node->data)	//item�� ���� Node�� ��ġ�� ���
		{
			cout << "\n\tEnter data to Replace" << endl;
			item.SetNameFromKB();
			item.SetAddressFromKB();
			cur_node->data = item;
			
			cout << "\n\tData Replaced" << endl;
			return 1;
		}
		else if (item <= cur_node->data)	//Sorted Linked List�̹Ƿ� Current Node�� Data�� ���� �� ũ�� ���� ���
			return 0;
		itor.Next<T>();		//���� ���� �̵�.
	}
	
	return 0; //��ü ����
}
#endif	// LINKED_LIST