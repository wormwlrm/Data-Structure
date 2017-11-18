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
	//클래스 변수들 초기화
	m_nLength = 0;
	m_pFirst = NULL;
	m_pLast = NULL;
}


// Class Destructor
template <typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList()
{
	MakeEmpty(); //리스트 내의 모든 node 제거
}


// Initialize list to empty state.
template <typename T>
int DoublySortedLinkedList<T>::MakeEmpty()
{
	DoublyNodeType<T>* pItem;		// 제거할 아이템을 가르키는 포인터
	DoublyIterator<T> itor(*this);	// this 포인터를 이용하여 iterator 선언

	while (itor.NotNull())	//CurPointer가 가리킬 값이 존재 하지 않을 때까지
	{
		pItem = itor.m_pCurPointer; //최초값을 저장 후 다음 노드로 변경 시킨다.
		itor.Next<T>();
		delete pItem;	//저장한 값을 삭제
	}
	
	m_pFirst = m_pLast = NULL; //포인터 데이터를 지움.
	m_nLength = 0; //길이 초기화
		
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
	DoublyNodeType<T> *node = new DoublyNodeType<T>; // 리스트에 새로 추가할 Node 를 동적할당으로 생성
		
	node->data = item; // item의 정보 입력
	node->next = NULL;
	node->prev = NULL;

	
	if (!m_nLength) // 현재 리스트가 존재하지 않는 경우
	{
		m_pFirst = node;
	}
	
	else // 리스트에 Node가 하나 이상 존재하는 경우
	{
		DoublyIterator<T> itor(*this);	// iterator 선언, 파라미터로 *this를 받으면서 m_pFirst로 값을 초기화

		while (true)
		{
			DoublyNodeType<T> *cur = itor.m_pCurPointer; // NodeType 포인터 *Cur를 iterator로 초기화
			if (cur->data >= node->data) // Cur의 데이터가 Node의 데이터보다 큰 경우
			{
				if (cur->prev != NULL) // Cur의 데이터가 Node의 데이터보다 크고, Cur가 First가 아닐 때 : 리스트의 Cur 번째 이전에 삽입
					cur->prev->next = node;
				else // Cur의 데이터가 Node의 데이터보다 크고, Cur가 First일때 : 리스트에 가장 작은 값으로 삽입
					m_pFirst = node;
				
				node->prev = cur->prev; // Node와 이전과 다음 포인터들을 각각 연결
				cur->prev = node;
				node->next = cur;

				m_nLength++; //길이증가 후 종료
				return 1;
			}
			
			if (cur->next == NULL) // Cur의 Next가 Null일 경우 : 리스트에 가장 큰 값으로 삽입
			{
				cur->next = node; // 리스트의 마지막 Node 와 연결
				node->prev = cur;
				break;
			}
			itor.Next<T>();	//다음 Node로 이동.
		}
	}
		
	m_nLength++; //길이 증가 후 종료
	return 1;
}


// Retrieve list element whose key matches item's key (if present).
template <typename T>
int DoublySortedLinkedList<T>::Get(T& item)
{
	DoublyIterator<T> itor(*this);	// this 포인터를 이용하여 iterator 선언

	while (itor.NotNull())	//itor가 Null이 아닐 때 까지 반복
	{
		if (item == itor.GetCurrentNode<T>().data)	//현재 Node의 데이터가 찾고있는 item과 같을 경우
		{
			item = itor.GetCurrentNode<T>().data;	//Current Data를 item에 복사
			return 1;		//성공 반환
		}
		else if (item <= itor.GetCurrentNode<T>().data)	//Sorted Linked List이므로 Current Node의 Data가 값이 더 크면 없는 경우
			return 0;		//실패 반환
		itor.Next<T>();		//Node 이동
	}
		
	return 0; //실패 반환
}

// Delete the item in the list whose key matches item's key (if present).
template <typename T>
int DoublySortedLinkedList<T>::Delete(T& item)
{
	if (m_nLength == 0) // List의 길이가 0일 경우 예외 처리
	{
		cout << "\n\tList is Empty" << endl;
		return 0;
	}
	DoublyIterator<T> itor(*this);	// this 포인터를 이용하여 iterator 선언
	DoublyNodeType<T> *cur_node;	// 삭제할 Node를 가리키는 포인터 변수

	while (itor.NotNull())	//itor가 Null이 아닐 때 까지 반복
	{
		cur_node = itor.m_pCurPointer;	//현재 CurPointer가 가리키는 노드를 가져옴

		if (item == cur_node->data)	// 삭제할 item을 찾은 경우
		{
			if (cur_node->prev != NULL)	// 삭제할 Node가 첫 번째가 아닌 경우
				cur_node->prev->next = cur_node->next;	//이전 노드와 다음 노드를 연결

			else						// 삭제할 Node가 첫번째인 경우
				m_pFirst = cur_node->next;	//첫 번째 노드를 다음 노드로 지정

			if (cur_node->next != NULL)	// 삭제할 Node가 마지막이 아닌 경우
				cur_node->next->prev = cur_node->prev;	//다음 노드와 이전 노드를 연결

			else						// 삭제할 Node가 마지막인 경우
				m_pLast = cur_node->prev;	//마지막 노드를 이전 노드로 지정

			delete cur_node;	//이번 노드를 삭제
			m_nLength--;		//길이 감소
			return 1;		//성공 반환
		}
		else if (item <= cur_node->data)	//Sorted Linked List이므로 Current Node의 Data가 값이 더 크면 없는 경우
			return 0;	//실패 반환
		itor.Next<T>();		//다음 노드로 이동.
	}
	//삭제 실패
	return 0;
}

// Replace the item in the list whose key matches item's key (if present).
template <typename T>
int DoublySortedLinkedList<T>::Replace(T& item)
{
	if (m_nLength == 0) // List의 길이가 0일 경우 예외 처리
	{
		cout << "\n\tList is Empty" << endl;
		return 0;
	}

	DoublyIterator<T> itor(*this);	// this 포인터를 이용하여 iterator 선언
	DoublyNodeType<T> *cur_node;	// 삭제할 Node를 가리키는 포인터 변수

	while (itor.NotNull())	//itor가 Null이 아닐 때 까지 반복
	{
		cur_node = itor.m_pCurPointer;	//이번 노드를 가져옴
		if (item == cur_node->data)	//item과 현재 Node가 일치할 경우
		{
			cout << "\n\tEnter data to Replace" << endl;
			item.SetNameFromKB();
			item.SetAddressFromKB();
			cur_node->data = item;
			
			cout << "\n\tData Replaced" << endl;
			return 1;
		}
		else if (item <= cur_node->data)	//Sorted Linked List이므로 Current Node의 Data가 값이 더 크면 없는 경우
			return 0;
		itor.Next<T>();		//다음 노드로 이동.
	}
	
	return 0; //교체 실패
}
#endif	// LINKED_LIST