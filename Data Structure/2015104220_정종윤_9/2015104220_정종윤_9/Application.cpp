#include "Application.h"


// Program driver.
void Application::Run()
{
	while (1)
	{
		m_nCurCommand = GetCommand();

		switch (m_nCurCommand)
		{
		case 1:		// Add vertex
			AddVertex();
			break;
		case 2:		// Add weight
			AddWeight();
			break;
		case 3:		// Retrieve Item
			RetrieveItem();
			break;
		case 4:		// Print Item
			PrintItem();
			break;
		case 5:		// Print weight
			PrintWeight();
			break;
		case 0:		// Quit
			exit(100);
			return;
		default:	// Exception
			cout << "\tIllegal sellection...\n";
			break;
		}
	}
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Vertex" << endl;
	cout << "\t   2 : Add Weight" << endl;
	cout << "\t   3 : Search Path" << endl;
	cout << "\t   4 : Print items" << endl;
	cout << "\t   5 : Print Weight" << endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// Add new vertex into graph
int Application::AddVertex()
{
	ItemType item;

	//Get information and add item
	cout << "\n\t Vertex : ";
	cin >> item;

	m_List.AddVertex(item);
	// // Display current graph
	PrintItem();

	return 1;
}

// Add new weight into list.
int Application::AddWeight()
{
	ItemType vertex1;
	cout << "\n\t 1st Vertex : ";
	cin >> vertex1;

	if (!m_List.FindVertex(vertex1))
	{
		cout << "\t 1st Vertex not found on Graph" << endl;
		return 0;
	}

	ItemType vertex2;
	cout << "\n\t 2nd Vertex : ";
	cin >> vertex2;
	if (vertex1 == vertex2)
	{
		cout << "\t 1st vertex and 2nd vertex is same" << endl;
	}

	if (!m_List.FindVertex(vertex2))
	{
		cout << "\t 2nd Vertex not found on Graph" << endl;
		return 0;
	}

	int weight;
	cout << "\t input Weight : ";
	cin >> weight;

	bool success = m_List.AddEdge(vertex1, vertex2, weight);
	PrintWeight();
	return success;
}


// Display all items in the graph on screen.
void Application::PrintItem()
{
	cout << "\n\tCurrent Vertex" << endl;
	m_List.PrintVertices();
}


// Display all weights in the graph on screen.
void Application::PrintWeight()
{
	cout << "\n\tCurrent Weight" << endl;
	m_List.PrintEdges();
}

// Retrieve item in the list by getting ID
void Application::RetrieveItem()
{
	ItemType vertex1;
	cout << "\n\t 1st Vertex : ";
	cin >> vertex1;

	if (!m_List.FindVertex(vertex1))
	{
		cout << "\t 1st Vertex not found on Graph" << endl;
		return;
	}

	ItemType vertex2;
	cout << "\n\t 2nd Vertex : ";
	cin >> vertex2;

	if (!m_List.FindVertex(vertex2))
	{
		cout << "\t 2nd Vertex not found on Graph" << endl;
		return;
	}
	DepthFirstSearch(m_List, vertex1, vertex2); // ±íÀÌ ¿ì¼± Å½»ö ½ÇÇà
}