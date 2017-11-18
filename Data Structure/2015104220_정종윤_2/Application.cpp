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
	// 입력받은 레코드를 리스트에 add, 리스트가 full일 경우는 add하지 않고 0을 리턴
	if(m_List.IsFull())
	{
		cout << "\tError : List is full!" << endl;
		return 0;
	}

	ItemType item;

	item.SetRecordFromKB();
	m_List.Add(item);

	// 현재 list 출력
	DisplayAllItem();

	return 1;
}


// Display all records in the list on screen.
void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	// list의 모든 데이터를 화면에 출력
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
	ItemType data;	// 읽기용 임시 변수
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if(!OpenInFile(filename))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while(!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// 현재 list 출력
	DisplayAllItem();

	return 1;
}


// Open a file as a write mode, and write all data into the file.
int Application::WriteDataToFile()
{
	ItemType data;	// 쓰기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if(!OpenOutFile(filename))
		return 0;

	// list 포인터를 초기화
	m_List.ResetList();

	// list의 모든 데이터를 파일에 쓰기
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
	if (m_List.GetLength() == 0) // 검색하기 전 리스트의 길이가 0이 아닌지 확인
	{
		cout << "\tError : There is nothing on item lists." << endl;
		return 0;
	}

	ItemType data;
	cout << "\n\tEnter the ID what you want to search : " << endl;
	data.SetIdFromKB();	// data의 ID에 검색할 ID를 입력
	if (m_List.Get(data) == 1) 	// 검색 성공 시 1을 리턴, 실패시 0을 리턴
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
	if (m_List.GetLength() == 0) // 삭제 하기 전 리스트의 길이가 0이 아닌지 확인
	{
		cout << "\tError : There is nothing on item lists." << endl;
		return;
	}
	
	ItemType data;
	cout << "\n\tEnter the ID what you want to delete : " << endl;
	data.SetIdFromKB();		// data에 등록된 ID를 기준으로 삭제
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
	if (m_List.GetLength() == 0) // 갱신하기 전 리스트의 길이가 0이 아닌지 확인
	{
		cout << "\tError : There is nothing on item lists." << endl;
		return;
	}

	ItemType data;
	cout << "\n\tIf you Enter the ID, you can update item. : " << endl;
	data.SetRecordFromKB(); // data에 갱신하고자 하는 정보를 입력받음
	if (m_List.Replace(data) == 1) // 갱신 성공 또는 실패를 출력
	{
		cout << "\tUpdate Success!" << endl;
		return;
	}
	else
	{
		cout << "\tError : There isn't exist what you want to update." << endl;
		return;
	}
	// data에 등록된 ID를 기준으로 갱신
};


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.
	
	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if(!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if(!m_OutFile)	return 0;
	else	return 1;
}

//
int Application :: retrieveRecordByMemberName()
{
	ItemType inData; // 검색할 단어를 포함할 임시 변수 inData 선언
	cout << "\tEnter the words in member name what you want to search." << endl;
	inData.SetNameFromKB(); // 검색할 단어를 임시 변수 inData에 저장
	SearchListByMemberName(inData); // inData에 담긴 단어와 비교하여 검색
	return 1;
}

//
int Application :: SearchListByMemberName(ItemType& inData)
{
	m_List.ResetList(); // List의 iterator 초기화
	int count = 0; // 반복을 위한 변수 count 설정
	ItemType Current; // 임시로 ItemType 변수 만듦

	while (count < m_List.GetLength()-1 && count >= 0) // m_List의 길이만큼 반복 시행
	{
		count = m_List.GetNextItem(Current); // Index 설정
		if (Current.GetName().find(inData.GetName()) != string::npos) // 일치하는 단어가 있는지 확인
		{
			m_List.Get(Current); // Current의 Address, ID를 받아옴
			Current.DisplayRecordOnScreen(); // 출력
		}
	}

	return 1;
}