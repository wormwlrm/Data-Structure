#include "Application.h"


// Program driver.
void Application::Run()
{
	while(1)
	{
		m_Command = GetCommand();

		switch(m_Command)
		{
		case 1:		// read a record and add to list.
			AddItem();
			break;
		case 2:		// display all the records in list on screen.
			DisplayAllItem();
			break;
		case 3:		// make empty list.
			m_List.MakeEmpty();
			break;
		case 4:		// search a item from the list by checking ID.
			SearchItem();
			break;
		case 5:		// search a item from the list by checking member name.
			retrieveRecordByMemberName();
			break;
		case 6:		// delete a item from the list.
			DeleteItem();
			break;
		case 7:		// update a item from the list.
			UpdataItem();
			break;
		case 8:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 9:		// save list data into a file.
			WriteDataToFile(); 
			break;			
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
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
	cout << "\t   2 : Print all on screen" << endl;
	cout << "\t   3 : Make empty list" << endl;
	cout << "\t   4 : Search item by ID" << endl;
	cout << "\t   5 : Search item by name" << endl;
	cout << "\t   6 : Delete item" << endl;
	cout << "\t   7 : Update item" << endl;
	cout << "\t   8 : Get from file" << endl; 
	cout << "\t   9 : Put to file " << endl; 
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::AddItem()
{
	// �Է¹��� ���ڵ带 ����Ʈ�� add, ����Ʈ�� full�� ���� add���� �ʰ� 0�� ����
	if(m_List.IsFull())
	{
		cout << "\tError : List is full!" << endl;
		return 0;
	}

	ItemType item;

	item.SetRecordFromKB();
	m_List.Add(item);

	// ���� list ���
	DisplayAllItem();

	return 1;
}


// Display all records in the list on screen.
void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.DisplayRecordOnScreen();
		curIndex = m_List.GetNextItem(data);
	}
}

// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	// �б�� �ӽ� ����
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while(!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// ���� list ���
	DisplayAllItem();

	return 1;
}


// Open a file as a write mode, and write all data into the file.
int Application::WriteDataToFile()
{
	ItemType data;	// ����� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenOutFile(filename))
		return 0;

	// list �����͸� �ʱ�ȭ
	m_List.ResetList();

	// list�� ��� �����͸� ���Ͽ� ����
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}

// Search a item from the list.
int Application::SearchItem()
{
	if (m_List.GetLength() == 0) // �˻��ϱ� �� ����Ʈ�� ���̰� 0�� �ƴ��� Ȯ��
	{
		cout << "\tError : There is nothing on item lists." << endl;
		return 0;
	}

	ItemType data;
	cout << "\n\tEnter the ID what you want to search : " << endl;
	data.SetIdFromKB();	// data�� ID�� �˻��� ID�� �Է�
	if (m_List.Get(data) == 1) 	// �˻� ���� �� 1�� ����, ���н� 0�� ����
	{
		data.DisplayRecordOnScreen();
		return 1;
	}
	else
	{
		cout << "\tError : There isn't exist what you want to search." << endl;
		return 0;
	}

};

// Delete a item from the list.
void Application::DeleteItem()
{
	if (m_List.GetLength() == 0) // ���� �ϱ� �� ����Ʈ�� ���̰� 0�� �ƴ��� Ȯ��
	{
		cout << "\tError : There is nothing on item lists." << endl;
		return;
	}
	
	ItemType data;
	cout << "\n\tEnter the ID what you want to delete : " << endl;
	data.SetIdFromKB();		// data�� ��ϵ� ID�� �������� ����
	if (m_List.Delete(data) == 1)
	{
		cout << "\tDelete Success!" << endl;
		return;
	}
	else
	{
		cout << "\tError : There isn't exist what you want to delete." << endl; 
		return;
	}
};

//	Update a item from the list.
void Application::UpdataItem()
{
	if (m_List.GetLength() == 0) // �����ϱ� �� ����Ʈ�� ���̰� 0�� �ƴ��� Ȯ��
	{
		cout << "\tError : There is nothing on item lists." << endl;
		return;
	}

	ItemType data;
	cout << "\n\tIf you Enter the ID, you can update item. : " << endl;
	data.SetRecordFromKB(); // data�� �����ϰ��� �ϴ� ������ �Է¹���
	if (m_List.Replace(data) == 1) // ���� ���� �Ǵ� ���и� ���
	{
		cout << "\tUpdate Success!" << endl;
		return;
	}
	else
	{
		cout << "\tError : There isn't exist what you want to update." << endl;
		return;
	}
	// data�� ��ϵ� ID�� �������� ����
};


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.
	
	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_OutFile)	return 0;
	else	return 1;
}

//
int Application :: retrieveRecordByMemberName()
{
	ItemType inData; // �˻��� �ܾ ������ �ӽ� ���� inData ����
	cout << "\tEnter the words in member name what you want to search." << endl;
	inData.SetNameFromKB(); // �˻��� �ܾ �ӽ� ���� inData�� ����
	SearchListByMemberName(inData); // inData�� ��� �ܾ�� ���Ͽ� �˻�
	return 1;
}

//
int Application :: SearchListByMemberName(ItemType& inData)
{
	m_List.ResetList(); // List�� iterator �ʱ�ȭ
	int count = 0; // �ݺ��� ���� ���� count ����
	ItemType Current; // �ӽ÷� ItemType ���� ����

	while (count < m_List.GetLength()-1 && count >= 0) // m_List�� ���̸�ŭ �ݺ� ����
	{
		count = m_List.GetNextItem(Current); // Index ����
		if (Current.GetName().find(inData.GetName()) != string::npos) // ��ġ�ϴ� �ܾ �ִ��� Ȯ��
		{
			m_List.Get(Current); // Current�� Address, ID�� �޾ƿ�
			Current.DisplayRecordOnScreen(); // ���
		}
	}

	return 1;
}