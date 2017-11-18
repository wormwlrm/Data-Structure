#include "Application.h"

// Program driver.
void Application::Run()
{
	try
	{
		while (1)
		{
			m_Command = GetCommand();

			switch (m_Command)
			{
			case 1:		// Push Element.
				enQueueItem();
				break;
			case 2:		// Pop Element.
				deQueueItem();
				break;
			case 3:		// Is Empty?
				CheckEmpty();
				break;
			case 4:		// Is Full?
				CheckFull();
				break;
			case 5:		// Test EmptyQueue Exception.
				TestEmptyException();
				break;
			case 6:		// Test FullQueue Exception.
				TestFullException();
				break;
			case 7:		// Print all the elements in the queue.
				DisplayAllItem();
				break;
			case 0:		
				return;
			default:	// 그 이외의 값 예외 처리
				cout << "\tIllegal selection...\n";
				break;
			}
		}
	}
	catch (FullQueue Error)		//FullQueue일 경우 예외처리
	{
		Error.print();
	}
	catch (EmptyQueue Error)	//EmptyQueue일 경우 예외처리
	{
		Error.print();
	}
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t--- ID - Command -----" << endl;
	cout << "\t    1. Enqueue Element" << endl;
	cout << "\t    2. Dequeue Element" << endl;
	cout << "\t    3. Is Empty?" << endl;
	cout << "\t    4. Is Full?" << endl;
	cout << "\t    5. EmptyQueue Exception test" << endl;
	cout << "\t    6. FullQueue Exception test" << endl;
	cout << "\t    7. Print all" << endl;
	cout << "\t    0. Quit" << endl << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Push new record into the queue.
int Application::enQueueItem()
{
	if (!m_queue.isFull()) // 큐가 가득 차 있지 않을 경우
	{
		ItemType Temp; // 임시 ItemType 변수 선언
		cout << "Input Element : ";
		cin >> Temp;

		m_queue.Enqueue(Temp); // Enqueue 함수 시행
		DisplayAllItem();

		return 1; // 성공 반환
	}
	else // 큐가 가득 차 있는 경우
		cout << "\t Queue is Full" << endl;

	return 0; // 실패 반환
}

// Pop a record of top from the queue.
int Application::deQueueItem()
{
	if (!m_queue.isEmpty()) // 큐가 비어있지 않은 경우
	{
		ItemType Temp; // 임시 ItemType 변수 선언
		m_queue.Dequeue(Temp); // Dequeue 함수 실행
		cout << "Deque Element : " << Temp << endl << endl;

		DisplayAllItem();

		return 1; // 성공 반환
	} 
	else // 큐가 비어있는 경우
		cout << "\t Queue is empty" << endl;

	return 0; // 실패 반환
}


// Check the queue is empty state.
int Application::CheckEmpty()
{
	if (m_queue.isEmpty())	
	{
		cout << "Queue is Empty." << endl << endl;
		return 1;
	}
	else					
		cout << "Queue is not Empty." << endl << endl;
	return 0;
}


// Check the queue is full state.
int Application::CheckFull()
{
	if (m_queue.isFull())
	{
		cout << "Queue is Full." << endl << endl;
		return 1;
	}
	else				
		cout << "Queue is not Full." << endl << endl;
	return 0;
}


// Test the exeception of empty queue.
void Application::TestEmptyException()
{
	ItemType item;

	while (1)
		m_queue.Dequeue(item);
}


// Test the exeception of full queue.
void Application::TestFullException()
{
	ItemType item;
	srand((unsigned long)time(NULL));

	while (1)
	{
		item = rand();
		m_queue.print();
		m_queue.Enqueue(item);
	}
}

// Display all records in the queue on screen.
void Application::DisplayAllItem()
{

	if (m_queue.isEmpty())
	{
		cout << "Queue is Empty." << endl << endl;
	}

	else
		m_queue.print();
}