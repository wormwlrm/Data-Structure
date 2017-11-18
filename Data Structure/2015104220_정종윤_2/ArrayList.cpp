#include "ArrayList.h"


// Make list empty.
void ArrayList::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
int ArrayList::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
bool ArrayList::IsFull()
{
	if(m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// add a new data into list.
int ArrayList::Add(ItemType inData)
{
	if (IsFull()) // ����Ʈ�� ���� �� ������ ������ Ȯ��
	{
		return 0; // ���� �� �ִٸ� 0 ��ȯ
	}
	
	bool FindInsertLocation; // ������ ��ġ�� ã�Ҵ����� �Ǵ��ϴ� ������ ����
	int CurrentLocation = 0; // ���� ��ġ�� ��Ÿ���� int�� ���� ����
	
	FindInsertLocation = (CurrentLocation < m_Length); // ���� ��ġ�� ��ü ���̺��� �۴ٸ� ��.
	
	while (FindInsertLocation) // ��ġ�� ��ü �������� �۴ٸ� �ݺ� ����
	{
		switch (inData.CompareByID(m_Array[CurrentLocation])) // ���� ��ġ�� ID�� �����ϰ��� �ϴ� ID�� ���� ��
		{
		case LESS: // �����ϰ��� �ϴ� ID�� ���� ���� CurrentLocation�� ���ԵǾ�� �ϹǷ�, while���� ���������� ���� FindInsertLocation�� false�� ��ü
			FindInsertLocation = false; 
			break;
		case GREATER: // �����ϰ��� �ϴ� ID�� ���� ���� CurrentLocation���� �ڿ� ���ԵǾ�� �ϹǷ�, CurrentLocation�� ���� �� FindInsertLocation�� �ٽ� Ȯ��
			CurrentLocation++; 
			FindInsertLocation = (CurrentLocation < m_Length); 
			break;
		case EQUAL: // ���� ���, ������ ID�� �ִٴ� ���̹Ƿ� 0 ��ȯ
			return 0;
		}
	}

	
	for (int i = m_Length; i > CurrentLocation; i--) // ������ ��ġ�� ã������, �� ���� �����͸� �� ĭ�� �Űܼ� ���ο� �����Ͱ� ���Ե� ������ ������. 
	{
		m_Array[i] = m_Array[i - 1];
	}

	m_Array[CurrentLocation] = inData; // ���� ��ġ�� ������ ����
	m_Length++; // ��ü ���̸� 1 �ø�
	return 1; // 1 ��ȯ

}


// Initialize list iterator.
void ArrayList::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
int ArrayList::GetNextItem(ItemType& data)
{
	m_CurPointer++;	// list pointer ����
	if(m_CurPointer == MAXSIZE)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

// Get the primary key, search item from the list and print it.
int ArrayList ::Get(ItemType& data)
{
	for (int i = 0; i < m_Length; i++) // ����Ʈ�� ���̸�ŭ �ݺ� ����
	{
		if (data.GetId() == m_Array[i].GetId()) // �˻��ϰ��� �ϴ� ID �߽߰� ����
		{
			data.SetAddress(m_Array[i].GetAddress());
			data.SetName(m_Array[i].GetName()); // data�� �ּ�, �̸��� ����
			return 1; // ������ 1�� ��ȯ
		}
	}
	return 0; // ���н� 0�� ��ȯ
};


// If same ID exist on list comparing with data, delete it.
int ArrayList::Delete(ItemType data)
{
	for (int i = 0; i < m_Length; i++)	// ����Ʈ ���� ��ŭ �ݺ� ����
	{
		if (data.GetId() == m_Array[i].GetId())	// �����ϰ��� �ϴ� ID �߰� �� ����
		{
			for (int j = i; j < m_Length - 1; j++) // �����ϰ��� �ϴ� item ���� list�� �� ĭ �� ������ �ű�
			{
				m_Array[i] = m_Array[i + 1];
			}
			m_Length--; // ����Ʈ ���̸� 1��ŭ ����
			return 1; // ������ 1�� ��ȯ
		}
	}
	return 0; // ���н� 0�� ��ȯ
};

// If same ID exist on list comparing with data, update it.
int ArrayList::Replace(ItemType data)
{
	for (int i = 0; i < m_Length; i++) // ����Ʈ ���̸�ŭ �ݺ� ����
	{
		if (data.GetId() == m_Array[i].GetId()) // �����ϰ��� �ϴ� ���̵� ã���� �� ����
		{
			m_Array[i] = data; //  data�� �Է��� ������ ����
			return 1; // ���� �� 1�� ��ȯ
		}
	}
	return 0; // ���� �� 0�� ��ȯ
};

int ArrayList::GetByBinarySearch(ItemType& data)
{
	ItemType Current; // Primary Key�� ���� �ӽ� ���� Current ����
	Current.SetIdFromKB();
	bool Finding;
	int index = 0;
	Finding = (index < m_Length); // ���̰� index���� ũ�� ��, index�� �迭 ���̸� �Ѿ� �� �� ����.

	while (Finding) // �迭 ���� index�� ���� ���� ��쿡�� while�� ����
	{
		switch (data.CompareByID(m_Array[index]))
		{
		case LESS:
			Finding = false;
			break;
		case GREATER:
			index++;
			Finding = (index < m_Length);
			break;
		case EQUAL:
			m_Array[index].DisplayRecordOnScreen();
			return 1;
		}
		return 0;

	}
};