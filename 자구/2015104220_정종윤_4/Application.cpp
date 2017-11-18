#include "Application.h"
using namespace std;


// Program driver.
void Application::Run()
{
	while(1)
	{
		m_nCurCommand = GetCommand();

		switch(m_nCurCommand)
		{
		case 1:		// Inset item
			InsertItem();
			break;
		case 2:		// Retrieves item
			DisplayAll();
			break;
		case 3:		// Make Empty list
			MakeEmpty();
			break;
		case 4:		// Search item
			RetrieveItem();
			break;
		case 5:		// Delete item
			DeleteItem();
			break;
		case 6:		// Replace item
			UpdateItem();
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
	cout << "\t   1 : Add new student" << endl;
	cout << "\t   2 : Print all on Screen" << endl;
	cout << "\t   3 : Make Empty List" << endl;
	cout << "\t   4 : Search Student" << endl;
	cout << "\t   5 : Delete Student" << endl;
	cout << "\t   6 : Update Student" << endl;
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

	item.SetRecordFromKB();
	m_List.Add(item);

	DisplayAll();

	return 1;
}

// Display all records in the list on screen.
void Application::DisplayAll()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	m_List.ResetList();	// 리스트 초기화
	// list의 모든 데이터를 화면에 출력
	for(int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(data);
		data.DisplayRecordOnScreen();
	}
}


// Retrieve item in the list.
int Application::RetrieveItem()
{
	ItemType item;
	cout << "\tEnter a item you want to search";
	item.SetIdFromKB();

	if(m_List.Get(item)) // 찾고자 하는 데이터가 있을 경우
	{
		cout << "\tTarget item exists in the list." << endl;
		return 1;
	}
	else // 그렇지 않은 경우
	{
		cout << "\tTarget item is not in the list." << endl;
		return 0;
	}
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
	ItemType data; // 임시 ItemType 변수 선언
		
	cout << "\n\tEnter id of item to Delete" << endl; //삭제할 데이터를 입력받음.
	data.SetIdFromKB();
		
	int result = m_List.Delete(data); //데이터를 삭제
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

// Replace item.
int Application::UpdateItem()
{
	ItemType data; // 임시 ItemType 변수 선언

	cout << "\n\tEnter id of item to Update" << endl;//교체할 데이터를 입력받음.
	data.SetIdFromKB();

	int result = m_List.Replace(data); //데이터를 교체
	DisplayAll();

	switch (result)
	{
	case -1:
		cout << "\tList is empty." << endl;
		break;
	case 0:
		cout << "\tData not found." << endl;
		break;
	case 1:
		cout << "\tReplace Success!" << endl;
		break;
	default:
		break;
	}

	return result;
}