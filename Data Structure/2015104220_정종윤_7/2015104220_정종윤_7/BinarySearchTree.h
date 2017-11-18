#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE
#include <iostream>
using namespace std;

#define MAX_LENGHT 10

template <typename T>
struct BinaryTreeNode
{
	T data; // Node data
	BinaryTreeNode *left; // Pointer pointing left node 
	BinaryTreeNode *right; // Pointer pointing right node
};

template <typename T>
class BinarySearchTree
{
public:
	/**
	*	@brief	default constructor
	*/
	BinarySearchTree();

	/**
	*	@brief	destructor
	*/
	~BinarySearchTree();

	/**
	*	@brief	Check tree is empty
	*	@return Return true if tree is empty, otherwise false
	*/
	bool isEmpty() const { return m_root == NULL; } 

	/**
	*	@brief	Check tree is full
	*	@return Return true if tree is full, otherwise false
	*/
	bool isFull(); 

	/**
	*	@brief	Initialize tree to empty state.
	*	@pre	None
	*	@post	Tree is empty.
	*	@return Return 1 if tree is empyty.
	*/
	int MakeEmpty();

	/**
	*	@brief	Get number of elements in the tree.
	*	@pre	None.
	*	@post	Function value = number of items in tree.
	*	@return	Number of elements in this tree.
	*/
	int GetLength();

	/**
	*	@brief	Add item into this tree.
	*	@pre	None.
	*	@post	Item is inserted in this tree.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int AddItem(T item);

	/**
	*	@brief	Delete item from this tree.
	*	@pre	Item that want to delete must exist
	*	@post	If same ID with primary key exists, delete data from the list.
	*	@param	[data] Item that want to delete
	*/
	int DeleteItem(T& data);

	/**
	*	@brief	Retrieve tree element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key, then the element's data is copied to the item.
	*	@param	[item] Data that user want to search.
	*			[found] Save data found
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int RetrieveItem(T& item, bool& found);

	/**
	*	@brief	Print tree
	*	@pre	Tree must be initialized
	*	@param	[out] outstream
	*/
	void PrintTree(ostream& out);
	
private:
	BinaryTreeNode<T>* m_root;
};

// Clss Constructor
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	//Class varialbe initialization
	m_root = NULL;
}

// Destructor
template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	//Delete all node in Binary Tree
	MakeEmpty();
}

// Check tree is full
template <typename T>
bool BinarySearchTree<T>::isFull()
{
	return GetLength() == MAX_LENGHT;
}

// Get number of elements in the tree.
template<typename T>
int BinarySearchTree<T>::MakeEmpty()
{
	MakeEmptyTree(m_root);
	return 1;
}

template <typename T>
void MakeEmptyTree(BinaryTreeNode<T>*&root)
{
	if (root == NULL) // Already empty
		return;
	if (root->left != NULL)		// if left node exist, move to left
		MakeEmptyTree(root->left);
	else if (root->right != NULL)	// if right node exist, move to right
		MakeEmptyTree(root->right);
	delete root;
	root = NULL;
}

template<typename T>
int BinarySearchTree<T>::GetLength() 
{
	return CountNodes(m_root);
}

template <typename T>
int CountNodes(BinaryTreeNode<T>*&root)
{
	if (root == NULL)	//if tree root is null, return 0
		return 0;

	int num = 1;
	if (root->left != NULL)		// if left node exist, move to left
		num += CountNodes(root->left);
	if (root->right != NULL)		// if right node exist, move to right
		num += CountNodes(root->right);
	return num;
}
template <typename T>
int BinarySearchTree<T>::AddItem(T item)
{
	if (isFull())
	{
		cout << "\tTree is already full." << endl;
		return 1;
	}
	Insert(m_root, item);
	return 0;
}

template<typename T>
void Insert(BinaryTreeNode<T>*&root, T item)
{
	if (root == NULL)	// tree root not exist
	{
		root = new BinaryTreeNode<T>;
		root->data = item;
		root->left = NULL;
		root->right = NULL;
	}
	else if (root->data > item)		// if data is smaller, move to left
		Insert(root->left, item);
	else if (root->data < item)		// if data is bigger, move to right
		Insert(root->right, item);
}

template<typename T>
void BinarySearchTree<T>::PrintTree(ostream& out)
{
	PrintInOrderTraversal(m_root, out);
}

template<typename T>
void PrintInOrderTraversal(BinaryTreeNode<T>*&root, ostream& out)
{
	if (root == nullptr)
		return;

	PrintInOrderTraversal(root->left, out);
	out << root->data << endl;
	PrintInOrderTraversal(root->right, out);
}

template<typename T>
void PrintPreOrderTraversal(BinaryTreeNode<T>*&root, ostream& out)
{
	if (root == nullptr)
		return;

	out << root->data << endl;
	PrintPreOrderTraversal(root->left, out);
	PrintPreOrderTraversal(root->right, out);
}

template<typename T>
void PrintPostOrderTraversal(BinaryTreeNode<T>*&root, ostream& out)
{
	if (root == nullptr)
		return;

	PrintPostOrderTraversal(root->left, out);
	PrintPostOrderTraversal(root->right, out);
	out << root->data << endl;
}

template<typename T>
int BinarySearchTree<T>::DeleteItem(T& data)
{
	if (isEmpty())
	{
		cout << "\tTree is empty." << endl;
		return 1;
	}
	DeleteNode(m_root, data);
	return 0;
}

template<typename T>
void ReplaceNode(BinaryTreeNode<T>*& root, BinaryTreeNode<T>*& newData)
{
	if (root == NULL)
		return;

	if (root->left != NULL && root->right != NULL)
	{
		newData->left = root->left;
		if (root->right != newData)
			newData->right = root->right;
	}

	BinaryTreeNode<T>* temp = root;
	root = newData;
	delete temp;
}

template<typename T>
void DeleteNode(BinaryTreeNode<T>*& root, T item)
{
	if (root == NULL)
		return;

	if (root->data == item)
	{
		if (root->left == NULL && root->right == NULL)
		{
			// leaf node
			delete root;
			root = NULL;
		}
		else if (root->left != NULL && root->right != NULL)// Root have two leafs
		{
			//Find minimun data in right root
			BinaryTreeNode<T>* min_term = root->right;
			while (min_term->left)
				min_term = min_term->left;

			ReplaceNode(root, min_term);
		}
		else if (root->left != NULL && root->right == NULL)// Root have only left leaf
			ReplaceNode(root, root->left);
		else if (root->left == NULL && root->right != NULL)// Root have only right leaf
			ReplaceNode(root, root->right);
	}
	else if (item > root->data)//Move right if item is bigger than data
		DeleteNode(root->right, item);
	else	// Move left if item is smaller than data
		DeleteNode(root->left, item);
}

template<typename T>
int BinarySearchTree<T>::RetrieveItem(T& item, bool& found)
{
	if (isEmpty())
	{
		cout << "\tTree is empty." << endl;
		return 1;
	}
	RetrieveNode(m_root, item, found);

	return 0;
}

template<typename T>
void RetrieveNode(BinaryTreeNode<T>*root, T& item, bool& found)
{
	if (found)	// if found is true
		return;

	if (root == NULL)	//There is no root
		return;

	if (root->data == item)
		found = true;
	else if (root->data > item)		// Move left if item is smaller than data
		RetrieveNode(root->left, item, found);
	else if (root->data < item)		// Move left if item is smaller than data
		RetrieveNode(root->right, item, found);
}
#endif // Binary Search Tree