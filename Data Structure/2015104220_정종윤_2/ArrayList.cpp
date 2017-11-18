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
	if (IsFull()) // 리스트가 가득 차 있지는 않은지 확인
	{
		return 0; // 가득 차 있다면 0 반환
	}
	
	bool FindInsertLocation; // 삽입할 위치를 찾았는지를 판단하는 변수를 선언
	int CurrentLocation = 0; // 현재 위치를 나타내는 int형 변수 선언
	
	FindInsertLocation = (CurrentLocation < m_Length); // 현재 위치가 전체 길이보다 작다면 참.
	
	while (FindInsertLocation) // 위치가 전체 갯수보다 작다면 반복 실행
	{
		switch (inData.CompareByID(m_Array[CurrentLocation])) // 현재 위치의 ID와 삽입하고자 하는 ID의 값을 비교
		{
		case LESS: // 삽입하고자 하는 ID의 값이 현재 CurrentLocation에 삽입되어야 하므로, while문을 빠져나가기 위해 FindInsertLocation을 false로 교체
			FindInsertLocation = false; 
			break;
		case GREATER: // 삽입하고자 하는 ID의 값이 현재 CurrentLocation보다 뒤에 삽입되어야 하므로, CurrentLocation을 더한 뒤 FindInsertLocation을 다시 확인
			CurrentLocation++; 
			FindInsertLocation = (CurrentLocation < m_Length); 
			break;
		case EQUAL: // 같은 경우, 동일한 ID가 있다는 것이므로 0 반환
			return 0;
		}
	}

	
	for (int i = m_Length; i > CurrentLocation; i--) // 삽입할 위치를 찾았으면, 그 뒤의 데이터를 한 칸씩 옮겨서 새로운 데이터가 삽입될 공간을 마련함. 
	{
		m_Array[i] = m_Array[i - 1];
	}

	m_Array[CurrentLocation] = inData; // 현재 위치에 데이터 삽입
	m_Length++; // 전체 길이를 1 늘림
	return 1; // 1 반환

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

int ArrayList::GetByBinarySearch(ItemType& data)
{
	ItemType Current; // Primary Key를 담을 임시 변수 Current 생성
	Current.SetIdFromKB();
	bool Finding;
	int index = 0;
	Finding = (index < m_Length); // 길이가 index보다 크면 참, index는 배열 길이를 넘어 설 수 없다.

	while (Finding) // 배열 안을 index가 돌고 있을 경우에만 while문 성립
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