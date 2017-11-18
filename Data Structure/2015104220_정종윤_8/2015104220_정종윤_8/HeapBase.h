#ifndef _HEAP_H_
#define _HEAP_H_

#include <iostream>
using namespace std;

/**
*	@brief	HeapBase for MinHeap and MaxHeap
*/
template <typename T>
class HeapBase
{
public:
	/**
	*	@brief	default constructor
	*/
	HeapBase() {};

	/**
	*	@brief	destructor
	*/
	virtual ~HeapBase() {};

	/**
	*	@brief	check heap is empty
	*	@return Return true if heap is empty, otherwise false
	*/
	bool isEmpty();

	/**
	*	@brief	check heap is full
	*	@return Return true if heap is full, otherwise false
	*/
	bool isFull();

	/**
	*	@brief	get number of current node
	*	@pre	none.
	*	@return	Return length of members of heap
	*/
	int GetLength() const;

	/**
	*	@brief	make heap empty
	*	@pre	none
	*	@post	Heap become empty
	*/
	void MakeEmpty();

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
	*	@brief	Pop a root node
	*	@pre	root node must be initialized
	*	@post	root node popped
	*	@return	Popped Node
	*/
	virtual T Pop();

	/**
	*	@brief	Retrieve tree element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key, then the element's data is copied to the item.
	*	@param	[item] Data that user want to search.
	*			[found] Save data found
	*/
	virtual void Retrieve(T& item, bool& found);

	/**
	*	@brief	Print nodes in heap
	*	@pre	Must be intialized
	*	@param	[out] outstream
	*/
	virtual void PrintHeap(ostream& out);

	/**
	*	@brief	Sort heap from up to down
	*	@pre	Must be intialized
	*	@post	Heap sorted
	*	@param	[iparent] Parents node, [ibottom] Key node
	*/
	virtual void ReheapDown(int iparent, int ibottom) = 0;

	/**
	*	@brief	Sort heap from down to up
	*	@pre	Must be intialized
	*	@post	Heap sorted
	*	@param	[iroot] Root node, [ibottom] Ket node
	*/
	virtual void ReheapUp(int iroot, int ibottom) = 0;

	/**
	*	@brief	Delete item on heap
	*	@pre	Must be initialized
	*	@post	Data deleted
	*	@param	[item] item which want to delete, [found] is it found, [iparent] Parents node
	*/
	virtual void Delete(T item, bool& found, int iparent) = 0;

	/**
	*	@brief	Retreive item on heap
	*	@pre	Must be initialized
	*	@post	Search Data and save item
	*	@param	[item] item which want to search, [found] is it found, [iparent] Parents node
	*/
	virtual void Retrieve(T& item, bool& found, int iparent) = 0;

protected:
	T* m_pHeap;		/// element array
	int m_iLastNode;/// number of nodes in heap
	int m_nMaxSize; /// maximum array size
};

//check heap is full
template <typename T>
bool HeapBase<T>::isFull()
{
	return m_iLastNode == m_nMaxSize;
}

//make heap empty
template<typename T>
void HeapBase<T>::MakeEmpty()
{
	m_iLastNode = 0;
}

//check heap is empty
template<typename T>
bool HeapBase<T>::isEmpty()
{
	return m_iLastNode == 0;
}

//HeapBase::Add item into this heap.
template<typename T>
int HeapBase<T>::Add(T item)
{
	cout << "Error : HeapBase::Add is Called" << endl;
	return 0;
}

//HeapBase::Delete item from this heap.
template<typename T>
int HeapBase<T>::Delete(T data)
{
	cout << "Error : HeapBase::Delete is Called" << endl;
	return 0;
}

//Print item in heap
template<typename T>
void HeapBase<T>::PrintHeap(ostream& out)
{
	for (int i = 0; i < m_iLastNode; i++)
		out << m_pHeap[i] << endl;
}

//HeapBase::Retrieve tree element whose key matches item's key (if present).
template<typename T>
void HeapBase<T>::Retrieve(T& item, bool& found)
{
	cout << "Error : HeapBase::Retreive is Called" << endl;
}

//HeapBase::Pop a root node
template<typename T>
T HeapBase<T>::Pop()
{
	cout << "Error : HeapBase::Pop is Called" << endl;
	return T();
}
#endif	// Heap