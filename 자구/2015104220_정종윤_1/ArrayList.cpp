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
	if(!IsFull())
	{
		m_Array[m_Length] = inData;
		m_Length++;
	}
	else
		return 0;

	return 1;
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