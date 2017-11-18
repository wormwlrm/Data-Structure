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
		case 1:		// �� �׸���
			DrawItem(new MyCircle);
			break;
		case 2:		//	�簢�� �׸���
			DrawItem(new MyRectangle);
			break;
		case 3:		// �ﰢ�� �׸���
			DrawItem(new MyTriangle);
			break;
		case 4:		// ��� ���
			DisplayAll();
			break;
		case 0:		// ����
			exit(100);
			return;
		default:	// �߸��� �Է� ���� ó��
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

	for (int i = 0; i < m_list.GetLength(); i++) 	// list�� ��� �����͸� ȭ�鿡 ���
	{
		Iter.Next();
		Iter.GetCurrentNode()->data->Display();
		cout << endl;
	}
}

void Application::DrawItem(MyBase* item)
{
	item->Draw();		//�������� Draw �Լ� ȣ��
	m_list.Add(item);	//�������� ����Ʈ�� �߰�
}