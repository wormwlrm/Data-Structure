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
	m_CurPointer++;	// list pointer 증가
	if(m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

// Get the primary key, search item from the list and print it.
int ArrayList ::Get(ItemType& data)
{
	for (int i = 0; i < m_Length; i++) // 리스트의 길이만큼 반복 시행
	{
		if (data.GetId() == m_Array[i].GetId()) // 검색하고자 하는 ID 발견시 시행
		{
			data.SetAddress(m_Array[i].GetAddress());
			data.SetName(m_Array[i].GetName()); // data에 주소, 이름을 설정
			return 1; // 성공시 1을 반환
		}
	}
	return 0; // 실패시 0을 반환
};


// If same ID exist on list comparing with data, delete it.
int ArrayList::Delete(ItemType data)
{
	for (int i = 0; i < m_Length; i++)	// 리스트 길이 만큼 반복 시행
	{
		if (data.GetId() == m_Array[i].GetId())	// 삭제하고자 하는 ID 발견 시 시행
		{
			for (int j = i; j < m_Length - 1; j++) // 삭제하고자 하는 item 뒤의 list를 한 칸 씩 앞으로 옮김
			{
				m_Array[i] = m_Array[i + 1];
			}
			m_Length--; // 리스트 길이를 1만큼 감소
			return 1; // 성공시 1을 반환
		}
	}
	return 0; // 실패시 0을 반환
};

// If same ID exist on list comparing with data, update it.
int ArrayList::Replace(ItemType data)
{
	for (int i = 0; i < m_Length; i++) // 리스트 길이만큼 반복 시행
	{
		if (data.GetId() == m_Array[i].GetId()) // 갱신하고자 하는 아이디를 찾았을 때 시행
		{
			m_Array[i] = data; //  data에 입력한 정보로 갱신
			return 1; // 성공 시 1을 반환
		}
	}
	return 0; // 실패 시 0을 반환
};