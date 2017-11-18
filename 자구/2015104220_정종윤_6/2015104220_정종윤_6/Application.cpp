#pragma once
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
		case 1:		// 원 그리기
			DrawItem(new MyCircle);
			break;
		case 2:		//	사각형 그리기
			DrawItem(new MyRectangle);
			break;
		case 3:		// 삼각형 그리기
			DrawItem(new MyTriangle);
			break;
		case 4:		// 모두 출력
			DisplayAll();
			break;
		case 0:		// 종료
			exit(100);
			return;
		default:	// 잘못된 입력 예외 처리
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
	cout << "\t   1 : Circle Draw" << endl;
	cout << "\t   2 : Rectangle Draw" << endl;
	cout << "\t   3 : Triangle Draw" << endl;
	cout << "\t   4 : Display All" << endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

//Display all Polygons.
void Application::DisplayAll()
{
	DoublyIterator<MyBase*> Iter(m_list);

	cout << "\n\tCurrent list" << endl;

	for (int i = 0; i < m_list.GetLength(); i++) 	// list의 모든 데이터를 화면에 출력
	{
		Iter.Next();
		Iter.GetCurrentNode()->data->Display();
		cout << endl;
	}
}

void Application::DrawItem(MyBase* item)
{
	item->Draw();		//아이템의 Draw 함수 호출
	m_list.Add(item);	//아이템을 리스트에 추가
}