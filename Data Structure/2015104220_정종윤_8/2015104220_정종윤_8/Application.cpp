#include "Application.h"
using namespace std;


// Program driver.
void Application::Run()
{
	while (1)
	{
		m_nCurCommand = GetCommand();

		switch (m_nCurCommand)
		{
		case 1:		// Inset item
			InsertItem();
			break;
		case 2:		// Delete item
			DeleteItem();
			break;
		case 3:		// Display All
			DisplayAll();
			break;
		case 4:		// Search item
			RetrieveItem();
			break;
		case 0:	// Quit
			return;
		default:
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
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Delete item" << endl;
	cout << "\t   3 : Display item" << endl;
	cout << "\t   4 : Search item" << endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::InsertItem()
{
	ItemType item;

	//Get information and add item
	item.SetRecordFromKB();
	m_List.Add(item);

	// Display all node
	DisplayAll();

	return 1;
}

// Display all records in the list on screen.
void Application::DisplayAll()
{
	cout << "\n\tCurrent list" << endl;
	m_List.PrintHeap(cout);
}


// Retrieve item in the list.
int Application::RetrieveItem()
{
	ItemType item;

	//get ID
	cout << "Enter ID of a item for search\n";
	item.SetIdFromKB();

	bool is_found = false;
	m_List.Retrieve(item, is_found);
	if (is_found)		//if Data is found
	{
		cout << "Target item exists in the list." << endl;
		return 1;
	}
	//if Data is not found
	cout << "Target item is not in the list." << endl;
	return 0;
}

// Make empty list.
int Application::MakeEmpty()
{
	m_List.MakeEmpty();
	DisplayAll();
	return 1;
}

// Delete item.
int Application::DeleteItem()
{
	ItemType data; // Temperory variable

	cout << "\n\tEnter ID of item to Delete" << endl; //Get ID
	data.SetIdFromKB();

	int result = m_List.Delete(data); //Delete Data
	switch (result)
	{
	case -1:
		cout << "\tList is empty." << endl;
		break;
	case 0:
		cout << "\tData not found." << endl;
		break;
	case 1:
		cout << "\tDelete Success!" << endl;
		break;
	default:
		break;
	}

	DisplayAll();

	return result;
}

