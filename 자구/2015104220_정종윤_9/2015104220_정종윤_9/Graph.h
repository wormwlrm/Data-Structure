#pragma once

#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_VERTEICES 10

/**
*	@brief	Graph Class
*/
template <typename T>
class CGraph;

/**
*	@brief	Return vertex's index
*	@return Return index
*/
template <typename T>
int IndexIs(T* vertices, T vertex, int vertexNum);

/**
*	@brief	Breadth Frist Search funtion
*/
template <typename T>
void BreadthFirstSearch(CGraph<T>& graph, T startVertex, T endVertex);

/**
*	@brief	Depth First Search function
*/
template <typename T>
void DepthFirstSearch(CGraph<T>& graph, T startVertex, T endVertex);

/**
*	@brief	CGraph Class
*/
template <typename T>
class CGraph
{
public:
	/**
	*	@brief	Default constructor
	*/
	CGraph(void);
	/**
	*	@brief	Constructor
	*	@param	[max] Size of graph
	*/
	CGraph(int max);
	/**
	*	@brief	Destructor
	*/
	~CGraph(void);

	/**
	*	@brief	Make graph Empty
	*	@post	Graph become empty
	*/
	void MakeEmpty(void);

	/**
	*	@brief	Check graph is empty
	*	@return Return true if graph is empty, otherwise false
	*/
	bool IsEmpty(void);

	/**
	*	@brief	check graph is full
	*	@return Return true if graph is full, otherwise false
	*/
	bool IsFull(void);
	/**
	*	@brief	Add vertex
	*	@post	Add vertex.
	*	@param	vertext Vertex to add
	*	@return Return true if add successfully,otherwise false
	*/
	bool AddVertex(T vertex);
	/**
	*	@brief	Add Edge
	*	@post	Add edge.
	*	@param	[fromvertex] Starting vertex to add edge	[toVertex] Ending vertex to add edge	[weight] Edge weight
	*	@return Return true if add successfully, otherwise false
	*/
	bool AddEdge(T fromVertex, T toVertex, int weight);
	/**
	*	@brief	Return edge weight between two vertex.
	*	@pre	Edge must be initialized
	*	@post	Return weight
	*	@param	[fromVertex] Starting vertex	[toVertex] Ending vertex
	*	@return weight
	*/
	int WeightIs(T fromVertex, T toVertex);

	/**
	*	@brief	Insert adjacent vertices in a queue
	*	@pre	adjacent vertices must be initialized
	*	@post	adjacent vertices is inserted
	*	@param	[vertex] standard vertex	[adgVertices] Queue to insert
	*/
	void GetToVertices(T vertex, QueueType<T>& adgVertices);
	/**
	*	@brief	Delete Marks
	*	@post	Delete Marks
	*/
	void ClearMarks(void);
	/**
	*	@brief	Mark on vertex
	*	@pre
	*	@post	Mark on vertex
	*	@param	[vertex] Vertex
	*/
	void MarkVertex(T vertex);
	/**
	*	@brief	Check vertex is marked
	*	@param	[vertex] vertex
	*	@return	Return true if vertex is marked, otherwise false
	*/
	bool IsMarked(T vertex);
	/**
	*	@brief	print vertices
	*	@post	print vertices
	*/
	void PrintVertices(void);
	/**
	*	@brief	print edges
	*	@post	print edges
	*/
	void PrintEdges(void);

	/**
	*	@brief	Check if vertex found
	*	@param	[vertex] vertex to find
	*	@return	Return true if vertex found, otherwise false
	*/
	bool FindVertex(T vertex);

protected:
	int m_numVertices;	// Current Vertices
	int m_maxVertices;	// Maximum Vertices
	T* m_Vertics;		// Vertex Pointer
	int** m_Edges;		// Weighted Edge Pointer
	bool* m_Marks;		// Mark Vertex Pointer
};

// Default constructer
template <typename T>
CGraph<T>::CGraph(void)
{
	m_maxVertices = MAX_VERTEICES;
	m_numVertices = 0;
	m_Vertics = new T[m_maxVertices];
	m_Edges = new int*[m_maxVertices];
	for (int i = 0; i<m_maxVertices; i++)
	{
		m_Edges[i] = new int[m_maxVertices];
		for (int j = 0; j < m_maxVertices; j++)
		{
			if (i == j)
				m_Edges[i][j] = 0;
			else
				m_Edges[i][j] = -1;
		}
	}
	m_Marks = new bool[m_maxVertices];
	ClearMarks();
}

// constructer
template <typename T>
CGraph<T>::CGraph(int max)
{
	m_maxVertices = max;
	m_numVertices = 0;
	m_Vertics = new T[m_maxVertices];
	m_Edges = new int*[m_maxVertices];
	for (int i = 0; i<m_maxVertices; i++)
	{
		m_Edges[i] = new int[m_maxVertices];
		for (int j = 0; j < m_maxVertices; j++)
			m_Edges[i][j] = -1;
	}
	m_Marks = new bool[m_maxVertices];
	ClearMarks();
}

// Destructer
template <typename T>
CGraph<T>::~CGraph(void)
{
	delete[] m_Vertics;
	for (int i = 0; i<m_maxVertices; i++)
		delete[] m_Edges[m_maxVertices];
	delete m_Edges;
	delete[] m_Marks;
}

// Make graph empty
template <typename T>
void CGraph<T>::MakeEmpty(void)
{
	m_numVertices = 0;
}

// Check graph is empty
template <typename T>
bool CGraph<T>::IsEmpty(void)
{
	if (m_numVertices == 0)
		return true;
	return false;
}

// Check graph is full
template <typename T>
bool CGraph<T>::IsFull(void)
{
	if (m_numVertices == m_maxVertices)
		return true;
	return false;
}

// Add vertex
template <typename T>
bool CGraph<T>::AddVertex(T vertex)
{
	if (IsFull()) // 예외처리
		return 0;
	for (int i = 0; i < m_numVertices; i++)
		if (m_Vertics[i] == vertex)	//중복체크
			return 0;

	m_Vertics[m_numVertices++] = vertex; // 마지막에 버텍스를 넣고 버텍스 수 증가
	return 1; // 1반환
}

// Add edge
template <typename T>
bool CGraph<T>::AddEdge(T fromVertex, T toVertex, int weight)
{
	int first_index = -1, second_index = -1;
	bool first_flag = false, second_flag = false;
	for (int i = 0; i < m_maxVertices; i++)
	{
		if (fromVertex == m_Vertics[i])
		{
			//인덱스 저장 및 플레그 변경
			first_index = i;
			first_flag = true;
		}
		if (toVertex == m_Vertics[i])
		{
			//인덱스 저장 및 플레그 변경
			second_index = i;
			second_flag = true;
		}
	}
	if (first_flag && second_flag) // 플래그가 모두 참이면
	{
		m_Edges[first_index][second_index] = weight;
		return true;
	}
	return false;
}

template <typename T>
int CGraph<T>::WeightIs(T fromVertex, T toVertex)
{
	int first_index = -1, second_index = -1;
	bool first_flag = false, second_flag = false;
	for (int i = 0; i < m_maxVertices; i++)
	{
		if (fromVertex == m_Vertics[i])
		{
			//인덱스 저장 및 플레그 변경
			first_index = i;
			first_flag = true;
		}
		if (toVertex == m_Vertics[i])
		{
			//인덱스 저장 및 플레그 변경
			second_index = i;
			second_flag = true;
		}
	}
	if (first_flag && second_flag) // 플래그가 모두 참이면
		return m_Edges[first_index][second_index];
	return -1;
}

template <typename T>
void CGraph<T>::GetToVertices(T vertex, QueueType<T>& adgVertices)
{
	int position = IndexIs(m_Vertics, vertex, m_numVertices);
	for (int i = 0; i < m_numVertices; i++)
		if (m_Edges[position][i] != -1)
			adgVertices.EnQueue(m_Vertics[i]); // 찾으면, 큐에 삽입
}

template <typename T>
void CGraph<T>::ClearMarks(void)
{
	for (int i = 0; i<m_numVertices; i++)
		m_Marks[i] = false;
}

template <typename T>
void CGraph<T>::MarkVertex(T vertex)
{
	int index = IndexIs(m_Vertics, vertex, m_numVertices);	// index 받아오기
	m_Marks[index] = true;
}

template <typename T>
bool CGraph<T>::IsMarked(T vertex)
{
	int index = IndexIs(m_Vertics, vertex, m_numVertices);	// index 받아오기

	if (m_Marks[index])
		return true;
	return false;
}

template <typename T>
void CGraph<T>::PrintVertices(void)
{
	for (int i = 0; i<m_numVertices; i++)
		cout << setw(10) << m_Vertics[i];
	cout << endl;
}

template <typename T>
void CGraph<T>::PrintEdges(void)
{
	for (int i = 0; i<m_numVertices; i++)
	{
		for (int j = 0; j<m_numVertices; j++)
			cout << setw(10) << m_Edges[i][j];
		cout << endl;
	}
	cout << endl;
}

template <typename T>
bool CGraph<T>::FindVertex(T vertex)
{
	for (int i = 0; i < m_numVertices; i++)
		if (m_Vertics[i] == vertex)
			return true;
	return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Global Funtion for Graph
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// return vertex's index
template <typename T>
int IndexIs(T* vertices, T vertex, int vertexNum)
{
	for (int i = 0; i<vertexNum; i++)
	{
		if (vertices[i] == vertex)
			return i;
	}
	return -1;
}

// BFS
template <typename T>
void BreadthFirstSearch(CGraph<T>& graph, T startVertex, T endVertex)
{
	// 큐로 하면 FIFO 이라 처음부터 찾는다.
	QueueType<T> queue;	// vertex 저장할 큐
	QueueType<T> vertexQ;	// 인접 vertex 저장할 큐
	bool found = false;		// 발견 여부

	T vertex;	// 임시 vertex 변수
	T item;		// 임시 item 변수

	graph.ClearMarks();			// Mark 초기화
	queue.EnQueue(startVertex);	// Queue에 시작 Vertex 입력

	do
	{
		queue.DeQueue(vertex);	// 현재 Queue의 값
		if (vertex == endVertex)	// 도착
		{
			cout << setw(10) << vertex << endl;
			found = true;
		}
		else
		{
			if (!graph.IsMarked(vertex))		// Mark 안됐을 시
			{
				graph.MarkVertex(vertex);	// Mark 함
				cout << setw(10) << vertex;		
				graph.GetToVertices(vertex, vertexQ);	// 인접 vertex 받아옴
				while (!vertexQ.IsEmpty())		// 인접 vertex가 없을때까지
				{
					vertexQ.DeQueue(item);		// Queue에서 삭제
					if (!graph.IsMarked(item))	// Mark 안됐을 시
						queue.EnQueue(item);	// Queue에 넣음
				}
			}
		}
	} while (!queue.IsEmpty() && !found);	// 길이가 없고 발견 되지 않을 경우

	if (!found)	// 길을 찾을 수 없을 경우 예외 처리
		cout << "Path not found." << endl;
}

// DFS
template <typename T>
void DepthFirstSearch(CGraph<T>& graph, T startVertex, T endVertex)
{
	StackType<T> stack; // Stack
	QueueType<T> vertexQ; // Queue
	bool found = false;		// 발견 여부

	T vertex;	// 임시 vertex 변수
	T item;		// 임시 item 변수

	graph.ClearMarks();			// Mark 초기화
	stack.Push(startVertex);	// Stack에 시작 Vertex 입력

	do
	{
		stack.Pop(vertex);	// 현재 Stack의 값
		if (vertex == endVertex)	// 도착
		{
			cout << setw(10) << vertex << endl;		
			found = true;
		}
		else
		{
			if (!graph.IsMarked(vertex))		// Mark 안됐을 시
			{
				graph.MarkVertex(vertex);	// Mark 함
				cout << setw(10) << vertex;		
				graph.GetToVertices(vertex, vertexQ);	// 인접 vertex 받아옴
				while (!vertexQ.IsEmpty())	// 인접 vertex가 없을때까지
				{
					vertexQ.DeQueue(item);		// Queue에서 삭제
					if (!graph.IsMarked(item))	// Mark 되어 있지 않은 경우
						stack.Push(item);		// 스택에 넣음
				}
			}
		}
	} while (!stack.IsEmpty() && !found);	// 길이가 없고 발견 되지 않을 경우

	if (!found) // 길을 찾을 수 없을 경우 예외 처리
		cout << "\nPath not found." << endl;
}