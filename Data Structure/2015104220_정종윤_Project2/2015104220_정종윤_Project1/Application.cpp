#include "Application.h"


Application::Application()
{
	system("title 2015104220 정종윤 - 쇼핑몰 관리 시스템");
	load_customer_file();	// 고객 데이터 불러옴
	load_seller_file();		// 판매자 데이터 불러옴
	load_product_file();	// 물품 데이터 불러옴
}


Application::~Application()
{
}

void Application::run()
{
	cout << "┌─────────────────┐" << endl;
	cout << "│┌───────────────┐│" << endl;
	cout << "││≪   쇼핑몰 관리 프로그램   ≫││" << endl;
	cout << "│└───────────────┘│" << endl;
	cout << "└─────────────────┘" << endl;
	getMainCommand(); // 메인 메뉴 호출
}

void Application::load_customer_file()
{
	ifstream loadCustomer("Customers.txt"); // Customers.txt 파일 호출
	string _Id;
	string _Password;
	string _Name;
	int _Point;

	while (loadCustomer >> _Id >> _Password >> _Name >> _Point)  // 파일 입력이 없을 때 까지 데이터를 불러옴
	{
		Customer* temp = new Customer(); // 임시 고객 변수 동적 할당
		temp->setCustomer(_Id, _Password, _Name, _Point); // 받은 데이터 설정
		m_CustomerList.Add(temp); // 고객 리스트에 추가
	}	
}

void Application::load_seller_file()
{
	ifstream loadSeller("Sellers.txt"); // Customers.txt 파일 호출
	string _Company;
	string _RegistrationNumber;
	string _Name;
	string _PhoneNumber;
	int _Grade;	

	while (loadSeller >> _Company >> _RegistrationNumber >> _Name >> _PhoneNumber >> _Grade) // 파일 입력이 없을 때 까지 데이터를 불러옴
	{
		Seller *temp = new Seller();// 임시 판매자 변수 동적 할당
		temp->setSeller(_Company, _RegistrationNumber, _Name, _PhoneNumber, _Grade); // 받은 데이터 설정
		m_SellerList.Add(temp);// 판매자 리스트에 추가
	}
}

void Application::load_product_file()
{
	Larges[0].LargeCategory = "의류"; // 카테고리 설정
	Larges[1].LargeCategory = "식품";
	Larges[2].LargeCategory = "디지털";

	Larges[0].Middles[0].MiddleCategory = "여성의류";
	Larges[0].Middles[1].MiddleCategory = "남성의류";
	Larges[0].Middles[2].MiddleCategory = "유아의류";

	Larges[0].Middles[0].Smalls[0].SmallCategory = "여성상의";
	Larges[0].Middles[0].Smalls[1].SmallCategory = "여성하의";
	Larges[0].Middles[0].Smalls[2].SmallCategory = "여성아우터";
	Larges[0].Middles[1].Smalls[0].SmallCategory = "남성상의";
	Larges[0].Middles[1].Smalls[1].SmallCategory = "남성하의";
	Larges[0].Middles[1].Smalls[2].SmallCategory = "남성아우터";
	Larges[0].Middles[2].Smalls[0].SmallCategory = "유아상의";
	Larges[0].Middles[2].Smalls[1].SmallCategory = "유아하의";
	Larges[0].Middles[2].Smalls[2].SmallCategory = "유아아우터";

	Larges[1].Middles[0].MiddleCategory = "신선식품";
	Larges[1].Middles[1].MiddleCategory = "가공식품";
	Larges[1].Middles[2].MiddleCategory = "건강식품";

	Larges[1].Middles[0].Smalls[0].SmallCategory = "과일채소";
	Larges[1].Middles[0].Smalls[1].SmallCategory = "수산물";
	Larges[1].Middles[0].Smalls[2].SmallCategory = "축산물";
	Larges[1].Middles[1].Smalls[0].SmallCategory = "과자간식";
	Larges[1].Middles[1].Smalls[1].SmallCategory = "즉석식품";
	Larges[1].Middles[1].Smalls[2].SmallCategory = "통조림";
	Larges[1].Middles[2].Smalls[0].SmallCategory = "홍삼";
	Larges[1].Middles[2].Smalls[1].SmallCategory = "영양제";
	Larges[1].Middles[2].Smalls[2].SmallCategory = "다이어트";

	Larges[2].Middles[0].MiddleCategory = "휴대폰";
	Larges[2].Middles[1].MiddleCategory = "컴퓨터";
	Larges[2].Middles[2].MiddleCategory = "카메라";

	Larges[2].Middles[0].Smalls[0].SmallCategory = "SKT";
	Larges[2].Middles[0].Smalls[1].SmallCategory = "KT";
	Larges[2].Middles[0].Smalls[2].SmallCategory = "LG";
	Larges[2].Middles[1].Smalls[0].SmallCategory = "노트북";
	Larges[2].Middles[1].Smalls[1].SmallCategory = "데스크탑";
	Larges[2].Middles[1].Smalls[2].SmallCategory = "조립PC";
	Larges[2].Middles[2].Smalls[0].SmallCategory = "카메라";
	Larges[2].Middles[2].Smalls[1].SmallCategory = "렌즈";
	Larges[2].Middles[2].Smalls[2].SmallCategory = "액세서리";

	ifstream loadProduct("Products.txt"); // Product.txt 파일에서 데이터 불러옴
	string _Category_Large;
	string _Category_Middle;
	string _Category_Small;
	string _Name;
	string _Seller;
	int _Price;
	int _Stock;
	string _Image;

	while (loadProduct >> _Category_Large >> _Category_Middle >> _Category_Small >> _Name >> _Seller >> _Price >> _Stock >> _Image) // 파일 입력이 없을 때 까지 데이터를 불러옴
	{
		Product* temp = new Product();
		Seller* Dummy2;
		temp->setProduct(_Category_Large, _Category_Middle, _Category_Small, _Name, _Seller, _Price, _Stock, _Image); // 받은 데이터 설정
		for (int i = 0; i < 3; i++) // 대분류 카테고리 설정
		{
			if (Larges[i].LargeCategory == temp->getCategoryLarge())  // 일치할 경우
			{
				for (int j = 0; j < 3; j++) // 중분류 카테고리 설정
				{
					if (Larges[i].Middles[j].MiddleCategory == temp->getCategoryMiddle()) // 일치할 경우
					{
						for (int k = 0; k < 3; k++) // 소분류 카테고리 설정
						{
							if (Larges[i].Middles[j].Smalls[k].SmallCategory == temp->getCategorySmall()) // 일치할 경우
							{
								m_ProductList.Add(temp); // 전체 물건 배열에 추가
								Larges[i].Middles[j].Smalls[k].productList.Add(temp);	 // 소분류 카테고리 안에 포인터	 						
								m_SellerList.ResetList();
								for (int l = 0; l < m_SellerList.GetLength(); l++) // 리스트 길이 만큼 반복
								{
									m_SellerList.GetNextItem(Dummy2); 
									if (temp->getSeller() == Dummy2->getCompany())// 판매자가 등록한 물건일 경우
									{
										Dummy2->setSellerProducts(temp);
									}
								}
								break;
							}
						}
					}
				}
			}
		}
	}
}

int Application::getMainCommand()
{
	while (1)
	{
		cout << "───────────────────" << endl;
		cout << "1. 고객 모드\n2. 판매자 모드\n0. 종료" << endl;
		cout << "───────────────────" << endl;
		int choice; //메뉴 선택
		string tempId, tempPw;
		cin >> choice; 
		switch (choice)
		{
		case 1: // 고객모드
			cout << "───────────────────" << endl;
			cout << "1. 기존 회원으로 로그인\n2. 회원 가입\n0. 이전 메뉴로" << endl;
			cout << "───────────────────" << endl;
			cin >> choice;
			switch (choice) // 기존 회원으로 로그인 할 경우
			{
			case 1:
				cout << "ID : "; cin >> tempId;
				cout << "Password : "; cin >> tempPw;
				customerlogIn(tempId, tempPw); // 고객 로그인 함수 시행
				break;
			case 2: // 사용자 추가
				Add_Customer();
				break;
			case 0: //이전 메뉴 호출
				getMainCommand();
				break;
			default: // 잘못된 입력 예외 처리
				cout << "───────────────────" << endl;
				cout << "잘못된 입력입니다." << endl;
				cout << "───────────────────" << endl;
				break;
			}
			break;
		case 2: // 판매자 모드
			cout << "상호명 : "; cin >> tempId;
			cout << "사업자 등록번호 : "; cin >> tempPw;
			sellerlogin(tempId,tempPw);	 // 판매자 로그인 함수 시행		
			break;
		case 0: // 종료
			exit(100);
		default: // 잘못된 입력 예외처리
			cout << "───────────────────" << endl;
			cout << "잘못된 입력입니다." << endl;
			cout << "───────────────────" << endl;
			break;
		}
	}
	return 0;
}
int Application::getCustomerCommand()
{
	while (1)
	{
		printCustomerInfo();  // 현재 고객 정보를 보여줌
		cout << "1. 쇼핑 시작하기\n2. 이름으로 검색하기\n3. 쇼핑 리스트 확인\n4. 장바구니 확인\n5. 최근 등록된 상품 \n6. 경품 추첨\n7. 회원정보 수정\n8. 회원 탈퇴\n0. 로그아웃" << endl;
		cout << "───────────────────" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: // 카테고리 선택하여 구매
			choiceLargeCategory();
			break;
		case 2: // 이름으로 검색하여 구매
			SearchProduct();
			break;
		case 3: // 쇼핑 리스트 출력
			LoginedCustomer->PrintMyShoppingList();
			break;
		case 4: // 장바구니 출력
			printShoppingBasket();
			break; 
		case 5: // 최근 등록 리스트 출력
			printRecentlyAdded();
			break;
		case 6: // 경품 추첨
			EventShop();
			break;
		case 7: // 고객 정보 갱신
			Update_Customer();
			break;
		case 8: // 고객 탈퇴
			Delete_Customer();
			break;			
		case 0: // 로그아웃
			customerLogOut();
			getMainCommand();
			break;
		default: // 잘못된 입력 예외처리
			cout << "───────────────────" << endl;
			cout << "잘못된 입력입니다." << endl;
			cout << "───────────────────" << endl;
			break;
		}
	}
	return 0;	
}
int Application::getSellerCommand()
{
	while (1)
	{
		printSellerInfo(); // 현재 판매자 정보 출력
		cout << "1. 상품 등록\n2. 상품 변경\n3. 상품 삭제\n4. 상품 판매 현황\n5. 상품 입고\n6. 경품 등록\n0. 로그아웃" << endl;
		cout << "───────────────────" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: // 상품 등록
			AddProduct();
			break;
		case 2: // 상품 변경
			UpdateProduct();
			break;
		case 3: // 상품 삭제
			DeleteProduct();
			break;
		case 4: // 상품 판매
			SellProduct();
			break;
		case 5: // 상품 입고
			StorageProduct();
			break;
		case 6: // 경품 등록
			AddEvent();
			break;
		case 0: // 로그아웃
			sellerLogOut();
			getMainCommand();
			break;
		default: // 잘못된 입력 예외처리
			cout << "───────────────────" << endl;
			cout << "잘못된 입력입니다." << endl;
			cout << "───────────────────" << endl;
			break;
		}
	}
	return 0;
}
void Application::Add_Customer()
{
	Customer *Temp = new Customer(); // 신규 고객 변수 선언
	string _Id, _PW, _N;
	cout << "계정을 생성합니다." << endl;
	cout << "아이디   : "; cin >> _Id;
	cout << "비밀번호 : "; cin >> _PW;
	cout << "이름     : "; cin >> _N;
	Temp->setCustomer(_Id, _PW, _N, 0); // 정보 입력
	m_CustomerList.Add(Temp); // 리스트에 추가
	cout << "등록이 완료되었습니다." << endl;
}

void Application::Delete_Customer()
{
	string tempPW;
	cout << "───────────────────" << endl; 
	cout << "본인 확인을 위해 비밀번호를 다시 입력해주세요." << endl;
	cout << "───────────────────" << endl;
	cin >> tempPW;
	if (LoginedCustomer->getPassword() != tempPW) // 비밀번호로 본인 재확인
	{
		cout << "───────────────────" << endl;
		cout << "비밀 번호가 일치하지 않습니다." << endl;
		cout << "───────────────────" << endl;
		return;
	}
	cout << "───────────────────" << endl;
	cout << "정말 탈퇴하시겠습니까?" << endl; 
	cout << "1. 예\n2. 아니오" << endl;
	cout << "───────────────────" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1: // 1 선택시
		m_CustomerList.Delete(LoginedCustomer); // 회원 삭제
		cout << "탈퇴가 완료되었습니다." << endl;
		cout << "───────────────────" << endl;
		getMainCommand();
		break;
	case 2: // 2 선택시
		return;
		break;
	default: //잘못된 입력 예외처리
		cout << "───────────────────" << endl;
		cout << "잘못된 입력입니다." << endl;
		cout << "───────────────────" << endl;
		break;
	}
}
void Application::Update_Customer()
{
	string tempPW;
	cout << "───────────────────" << endl;
	cout << "본인 확인을 위해 비밀번호를 다시 입력해주세요." << endl;
	cout << "───────────────────" << endl;
	cin >> tempPW;
	if (LoginedCustomer->getPassword() != tempPW) // 비밀번호로 본인 재확인
	{
		cout << "───────────────────" << endl;
		cout << "비밀 번호가 일치하지 않습니다." << endl;
		cout << "───────────────────" << endl;
		return;
	}
	int choice;
	string temp;
	cout << "───────────────────" << endl;
	cout << "수정할 정보를 선택해주세요." << endl;
	cout << "1. 이름\n2. 비밀번호" << endl;
	cout << "───────────────────" << endl;
	cin >> choice;
	switch (choice) // 수정할 정보 선택
	{
	case 1: // 1 선택시
		cout << "───────────────────" << endl;
		cout << "새 이름을 입력해주세요." << endl;
		cout << "───────────────────" << endl;
		cin >> temp;
		LoginedCustomer->setName(temp);
		m_CustomerList.Replace((LoginedCustomer),1,temp); // 이름 갱신
		cout << "───────────────────" << endl;
		cout << "저장되었습니다." << endl;
		cout << "───────────────────" << endl;
		break;
	case 2: // 2선택시
		cout << "───────────────────" << endl;
		cout << "새 비밀번호를 입력해주세요." << endl;
		cout << "───────────────────" << endl;
		cin >> temp;
		LoginedCustomer->setPassword(temp);
		m_CustomerList.Replace((LoginedCustomer), 2, temp); // 비밀번호 갱신
		cout << "───────────────────" << endl;
		cout << "저장되었습니다." << endl;
		cout << "───────────────────" << endl;
		break;
	default: // 잘못된 입력 예외처리
		cout << "───────────────────" << endl;
		cout << "잘못된 입력입니다." << endl;
		cout << "───────────────────" << endl;
		break;
	}	
}

Customer* Application::customerlogIn(string _Id, string _Password)
{
	Customer Temp; //임시 고객 변수 선언
	Temp.setId(_Id); // 아이디 설정
	Temp.setPassword(_Password); // 비밀번호 설정
	int count = 0;
	Customer *Dummy = new Customer(); // 현재 탐색중인 노드를 가르키는 변수 선언
		
	m_CustomerList.ResetList(); 
	while (count < m_CustomerList.GetLength()) // 고객 리스트 내부 순환
	{
		m_CustomerList.GetNextItem(Dummy); 
		if (Dummy->getId() == Temp.getId()) // 일치하는 아이디를 찾았을 경우
		{
			if (Dummy->getPassword() == Temp.getPassword()) // 아이디와 비밀번호 모두 일치하는 경우
				{
					cout << "성공적으로 로그인 하였습니다." << endl;
					cout << "───────────────────" << endl;
					LoginedCustomer = (Dummy); // 현재 로그인 된 고객을 Dummy로 변경
					getCustomerCommand();
					return LoginedCustomer;
				}
			cout << "비밀번호가 일치하지 않습니다." << endl; // 비밀번호가 일치하지 않는 경우
			cout << "───────────────────" << endl;
			return NULL;

		}
		count++;
	}

	cout << "일치하는 ID가 없습니다." << endl; // 일치하는 아이디를 찾지 못한 경우
	cout << "───────────────────" << endl;
	return NULL;
}

void Application::customerLogOut()
{
	Customer* Dummy = new Customer(); // 임시 고객 변수 동적 할당
	m_CustomerList.ResetList();
	int count = 0;
	while (count < m_CustomerList.GetLength()) // 고객 리스트를 탐색
	{
		m_CustomerList.GetNextItem(Dummy);
		if (Dummy->getId()==LoginedCustomer->getId()) // 일치하는 아이디가 있을 경우
		{
			break; // 반복문 종료
		}
		count++;
	}
	Dummy = LoginedCustomer; // 현재까지의 정보를 기존 고객에 저장
	LoginedCustomer = NULL; // 로그인된 유저를 NULL로
}

Seller* Application::sellerlogin(string _Id, string _Password)
{
	Seller Temp; // 판매자 변수 선언
	Temp.setCompany(_Id); // 아이디 삽입
	Temp.setRegistrationNumber(_Password); // 비밀번호 삽입
	int count = 0;
	Seller* Dummy = new Seller(); // 임시 판매자 변수 동적 할당

	m_SellerList.ResetList();
	while (count < m_SellerList.GetLength()) // 판매자 리스트 순환
	{
		m_SellerList.GetNextItem(Dummy);
		if (Dummy->getCompany() == Temp.getCompany()) // 판매자 상호가 일치할 경우
		{
			if (Dummy->getRegistrationNumber() == Temp.getRegistrationNumber()) // 등록된 번호 또한 일치하는지 확인함
			{
				cout << "성공적으로 로그인 하였습니다." << endl;
				cout << "───────────────────" << endl;
				LoginedSeller = Dummy; // 현재 Dummy값을 로그인된 판매자 변수에 저장
				getSellerCommand();
				return LoginedSeller;
			}
			cout << "사업자 등록 번호가 일치하지 않습니다." << endl; // 사업자 등록번호가 일치하지 않을 경우
			cout << "───────────────────" << endl;
			return NULL;
		}
		count++;
	}
	cout << "일치하는 상호가 없습니다." << endl; //판매자 상호가 일치하지 않는 경우
	cout << "───────────────────" << endl;
	return NULL;
}
void Application::sellerLogOut()
{
	LoginedSeller = NULL; // 로그인된 유저를 NULL로 
}

void Application::printCustomerInfo()
{
	cout << "───────────────────" << endl;
	cout << "아이디   :" << setw(10) << LoginedCustomer->getId() << endl; // 로그인 된 유저의 아이디 출력
	cout << "이름     :" << setw(10) << LoginedCustomer->getName() << endl; //로그인된 유저의 이름 출력
	cout << "포인트   :" << setw(10) << LoginedCustomer->getPoint(); // 포인트 출력
	cout << "\n───────────────────" << endl;
}

void Application::printSellerInfo()
{
	cout << "───────────────────" << endl;
	cout << "상호     : " << setw(10) << LoginedSeller->getCompany() << endl; // 로그인된 판매자의 상호 출력
	cout << "등록번호 : " << setw(10) << LoginedSeller->getRegistrationNumber() << endl; // 로그인된 판매자의 사업자등록번호 출력
	cout << "이름     : " << setw(10) << LoginedSeller->getName() << endl;// 로그인된 판매자의 이름 출력
	cout << "연락처   : " << setw(10) << LoginedSeller->getPhoneNumber() << endl;// 로그인된 판매자의 연락처 출력
	cout << "판매등급 : " << setw(10) << LoginedSeller->getGrade();// 로그인된 판매자의 판매등급
	cout << "\n───────────────────" << endl;
}

void Application::choiceLargeCategory()
{
	cout << "───────────────────" << endl;
	cout << "카테고리를 선택해 주세요." << endl;
	cout << "───────────────────" << endl;
	int choice;
	for (int i = 0; i < 3; i++) // 대분류 카테고리 설정
	{
		cout << i+1 << ". " << Larges[i].LargeCategory << endl;
	}
	cout << "───────────────────" << endl;
	cin >> choice;
	if (choice < 1 || choice>3) // 잘못된 입력 예외처리
	{
		cout << "───────────────────" << endl;
		cout << "잘못된 입력입니다." << endl;
		cout << "───────────────────" << endl;
		return;
	}
	choice--;
	choiceMiddleCategory(choice); // 중분류 카테고리 설정으로 이동
}
void Application::choiceMiddleCategory(int choice)
{
	int choice2;
	cout << "───────────────────" << endl;
	for (int i = 0; i < 3; i++) // 중분류 카테고리 설정
	{
		cout << i+1 << ". " << Larges[choice].Middles[i].MiddleCategory << endl;
	}
	cout << "───────────────────" << endl;
	cin >> choice2;
	if (choice2 < 1 || choice2>3) // 잘못된 입력 예외처리
	{
		cout << "───────────────────" << endl;
		cout << "잘못된 입력입니다." << endl;
		cout << "───────────────────" << endl;
		return;
	}
	choice2--;
	choiceSmallCategory(choice, choice2); // 소분류 카테고리 설정으로 이동
}

void Application::choiceSmallCategory(int choice, int choice2)
{
	int choice3;
	cout << "───────────────────" << endl;
	for (int i = 0; i < 3; i++)		// 소분류 카테고리 설정
	{
		cout << i+1 << ". " << Larges[choice].Middles[choice2].Smalls[i].SmallCategory << endl;
	}
	cout << "───────────────────" << endl;
	cin >> choice3;
	if (choice3 < 1 || choice3>3) // 잘못된 입력 예외처리
	{
		cout << "───────────────────" << endl;
		cout << "잘못된 입력입니다." << endl;
		cout << "───────────────────" << endl;
		return;
	}
	choice3--;

	while (1)
	{
		Product *Dummy = new Product(); // 임시 물품 변수 동적 할당
		Larges[choice].Middles[choice2].Smalls[choice3].productList.ResetList(); // 선택한 카테고리의 물품 리스트
		cout << "───────────────────" << endl;
		cout << " 상품명        가격   재고 " << endl;
		cout << "───────────────────" << endl;
		for (int j = 0; j < Larges[choice].Middles[choice2].Smalls[choice3].productList.GetLength(); j++) // 리스트 길이만큼 반복
		{
			Larges[choice].Middles[choice2].Smalls[choice3].productList.GetNextItem(Dummy);  //선택한 번호의 물건을 불러오기 위해 GetNextItem 시행
			cout << j+1; Dummy->printProductDisplay(); // 정보 출력
		}
		
		if (Larges[choice].Middles[choice2].Smalls[choice3].productList.GetLength() == 0) // 만약 물품이 존재하지 않을 경우 에외 처리
		{
			cout << "상품이 존재하지 않습니다." << endl;
			cout << "───────────────────" << endl;
			getCustomerCommand();
		}

		int command; 
		cout << "───────────────────" << endl;
		cout << "상품 번호를 선택하여 정보를 확인합니다.\n0 입력 시 이전 메뉴로 돌아갑니다. " << endl;
		cout << "───────────────────" << endl;
		cin >> command;
		if (command == 0) // 0 입력시 메뉴 호출
		{
			getCustomerCommand();
			break;
		}

		Larges[choice].Middles[choice2].Smalls[choice3].productList.ResetList(); // 선택한 카테고리의 물품 리스트
		for (int k = 0; k < command; k++)
		{
			Larges[choice].Middles[choice2].Smalls[choice3].productList.GetNextItem(Dummy); // 선택한 번호의 물건을 불러오기 위해 GetNextItem 시행
		}
		Dummy->printProductInfo(); // 현재 선택한 물품의 정보 출력
		cout << "───────────────────" << endl;
		Buy(*Dummy); // 구매 함수 시행
	}
}

int Application::Buy(Product& Dummy)
{
	int choice;
	cout << "1. 즉시 구매하기" << endl;
	cout << "2. 장바구니에 담기" << endl;
	cout << "3. 이전 메뉴로" << endl;
	cout << "───────────────────" << endl;
	cin >> choice;
	Seller *New; // 임시 판매자 포인터 변수
	switch (choice)
	{
	case 1: // 물건 즉시 구매하기
		if (Dummy.getStock() <= 0) // 만약 선택한 물건의 재고가 0일 경우 예외 처리
		{
			cout << "모든 물량이 판매되었습니다." << endl;
			break;
		}
		LoginedCustomer->setMyShoppingList(&Dummy); // 로그인 된 유저의 쇼핑 리스트에 추가
		
		LoginedCustomer->setPoint(LoginedCustomer->getPoint() + Dummy.getPrice() / 10);
		New = new Seller(); // 임시 판매자 변수 선언
		m_SellerList.ResetList();
		for (int i = 0; i < m_SellerList.GetLength(); i++)  // 판매자 리스트만큼 반복
		{
			m_SellerList.GetNextItem(New);
			if (Dummy.getSeller() == New->getCompany()) // 물건의 상호가 같은 판매자 발견 시
			{
				New->setTotalCost(Dummy.getPrice()); // 판매자의 판매 금액 추가
				break;
			}
		}
		break;
	case 2: // 물건 장바구니에 담기
		LoginedCustomer->setShoppingBasket(Dummy);
		cout << "장바구니에 담겼습니다." << endl;
		break;
	case 3: // 메뉴 출력
		getCustomerCommand();
		break;
	default: // 잘못된 입력 예외 처리
		cout << "───────────────────" << endl;
		cout << "잘못된 입력입니다." << endl;
		cout << "───────────────────" << endl;
		break;
	}
	return 0;
}

int Application::SearchProduct()
{
	string name;
	Product* temp = new Product(); // 임시 물건 변수 선언
	Product* Dummy; // 더미 설정
	cout << "───────────────────" << endl;
	cout << "찾으시는 물건 이름을 입력하세요." << endl;
	cout << "───────────────────" << endl;
	cin >> name;
	temp->setName(name);
	for (int i = 0; i < 3; i++) // 대분류 카테고리
	{
		for (int j = 0; j < 3; j++) // 중분류 카테고리
		{
			for (int k = 0; k < 3; k++) // 소분류 카테고리
			{
				Larges[i].Middles[j].Smalls[k].productList.ResetList(); // 리스트 포인터 초기화
				for (int l = 0; l < Larges[i].Middles[j].Smalls[k].productList.GetLength(); l++) // 리스트 길이만큼 반복
				{
					Larges[i].Middles[j].Smalls[k].productList.GetNextItem(Dummy); // 다음 리스트를 가리킴
					if (Dummy->getName() == temp->getName()) // 찾고자 하는  이름이 일치할 경우
					{
						cout << "───────────────────" << endl;
						Dummy->printProductInfo(); // 현재 정보 출력
						Buy(*Dummy); // 구매 함수 출력
						return 1;
						break;
					}
				}
			}
		}
	}
	cout << "───────────────────" << endl;
	cout << "찾으시는 물건이 없습니다." << endl;
	cout << "───────────────────" << endl;
	return 0;
}

int Application::AddProduct()
{
	cout << "───────────────────" << endl;
	cout << "상품 등록을 위한 정보를 입력합니다." << endl;
	cout << "상품 카테고리를 선택해 주세요." << endl;
	cout << "───────────────────" << endl;
	int choice;
	for (int i = 0; i < 3; i++) // 대분류 카테고리 추가
	{
		cout << i + 1 << ". " << Larges[i].LargeCategory << endl;
	}
	cout << "───────────────────" << endl;
	cin >> choice;
	if (choice < 1 || choice>3) //잘못된 입력 시 예외 처리
	{
		cout << "───────────────────" << endl;
		cout << "잘못된 입력입니다." << endl;
		cout << "───────────────────" << endl;
		return 0;
	}
	choice--;
	int choice2;
	cout << "───────────────────" << endl;
	for (int i = 0; i < 3; i++) // 중분류 카테고리 추가
	{
		cout << i + 1 << ". " << Larges[choice].Middles[i].MiddleCategory << endl;
	}
	cout << "───────────────────" << endl;
	cin >> choice2;
	if (choice2 < 1 || choice2>3) // 잘못된 입력시 예외 처리
	{
		cout << "───────────────────" << endl;
		cout << "잘못된 입력입니다." << endl;
		cout << "───────────────────" << endl;
		return 0;
	}
	choice2--;
	int choice3;
	cout << "───────────────────" << endl;
	for (int i = 0; i < 3; i++) // 소분류 카테고리 추가
	{
		cout << i + 1 << ". " << Larges[choice].Middles[choice2].Smalls[i].SmallCategory << endl;
	}
	cout << "───────────────────" << endl;
	cin >> choice3;
	if (choice3 < 1 || choice3>3) // 잘못된 입력 시 예외 처리
	{
		cout << "───────────────────" << endl;
		cout << "잘못된 입력입니다." << endl;
		cout << "───────────────────" << endl;
		return 0;
	}
	choice3--;

	Product* New = new Product(); // 새로 추가할 물품 변수 추가
	string _Name; 
	int _Price;
	int _Stock;
	string _Image;
	cout << "───────────────────" << endl;
	cout << "상품명      : "; cin >> _Name; //상품명 추가
	cout << "상품 가격   : "; cin >> _Price;//상품 가격 추가
	cout << "상품 재고   : "; cin >> _Stock;//상품 재고 추가
	cout << "상품 이미지 : "; cin >> _Image;//이미지 추가
	New->setProduct(Larges[choice].LargeCategory, Larges[choice].Middles[choice2].MiddleCategory, 
		Larges[choice].Middles[choice2].Smalls[choice3].SmallCategory,_Name,LoginedSeller->getCompany(),
		_Price,_Stock,_Image); // 입력받은 정보를 바탕으로 물품 설정
	Larges[choice].Middles[choice2].Smalls[choice3].productList.Add(New); // 물품 리스트에 추가
	m_ProductList.Add(New);
	LoginedSeller->setSellerProducts(New); //로그인된 판매자의 판매중인 물건에 추가
	cout << "───────────────────" << endl;
	cout << "상품이 추가되었습니다." << endl;
	cout << "───────────────────" << endl;
	return 0;
}

int Application::UpdateProduct()
{
	string name;
	Product* temp = new Product(); // 임시 물품 변수 동적 할당
	Product* Dummy;
	cout << "───────────────────" << endl;
	cout << "수정하실 물건 이름을 입력하세요." << endl;
	cout << "───────────────────" << endl;
	LoginedSeller->printProductList(); // 현재 판매중인 물건 리스트 출력
	cout << "───────────────────" << endl;
	cin >> name;
	temp->setName(name);
	for (int i = 0; i < 3; i++) // 대분류 카테고리
	{
		for (int j = 0; j < 3; j++) // 중분류 카테고리
		{
			for (int k = 0; k < 3; k++) // 소분류 카테고리
			{
				Larges[i].Middles[j].Smalls[k].productList.ResetList();
				for (int l = 0; l < Larges[i].Middles[j].Smalls[k].productList.GetLength(); l++) // 리스트 길이만큼 반복
				{
					Larges[i].Middles[j].Smalls[k].productList.GetNextItem(Dummy); // 다음 리스트를 가리킴
					if (Dummy->getName() == temp->getName()) // 일치하는 물건 발견 시
					{
						if (Dummy->getSeller() != LoginedSeller->getCompany()) // 판매하는 회사의 물품이 아닐 경우
						{
							cout << "로그인 된 회사의 상품이 아닙니다." << endl;
							cout << "───────────────────" << endl;
							return 0;
						}
						cout << "───────────────────" << endl;
						string _Name;
						string _Image;
						int _Price;
						Dummy->printProductInfo(); // 현재 정보 출력
						cout << "───────────────────" << endl;
						cout << "어떤 정보를 수정하시겠습니까?" << endl;
						cout << "───────────────────" << endl;
						cout << "1. 상품명" << endl;
						cout << "2. 상품 가격" << endl;
						cout << "3. 상품 이미지" << endl;
						cout << "───────────────────" << endl;
						int choice4;
						cin >> choice4;
						cout << "───────────────────" << endl;
						cout << "수정할 정보를 입력하세요." << endl;
						cout << "───────────────────" << endl;

						switch (choice4)
						{
						case 1: // 이름 수정
							cin >> _Name;
							Larges[i].Middles[j].Smalls[k].productList.Update(Dummy, 1, _Name);
							break;
						case 2: // 가격 수정
							cin >> _Price;
							Larges[i].Middles[j].Smalls[k].productList.Update(Dummy, 2, _Price);
							break;
						case 3: // 이미지 수정
							cin >> _Image;
							Larges[i].Middles[j].Smalls[k].productList.Update(Dummy, 3, _Name);
							break;
						default: // 잘못된 입력 시 예외 처리
							cout << "───────────────────" << endl;
							cout << "잘못된 입력입니다." << endl;
							cout << "───────────────────" << endl;
							break;
						} 
						cout << "───────────────────" << endl;
						cout << "성공적으로 완료되었습니다." << endl;
						cout << "───────────────────" << endl;
						return 1;
						break;
					}
				}
			}
		}
	}
	cout << "상품 수정에 실패하였습니다." << endl; // 카테고리에서 발견 실패 시
	cout << "───────────────────" << endl;
	return 0; 
	
}
int Application::DeleteProduct()
{
	string name;
	Product* temp = new Product(); // 임시 물품 변수 동적 할당
	Product* Dummy;
	cout << "───────────────────" << endl;
	cout << "삭제하실 물건 이름을 입력하세요." << endl;
	cout << "───────────────────" << endl;
	LoginedSeller->printProductList(); // 판매중인 물건 리스트 출력
	cout << "───────────────────" << endl;
	cin >> name;
	temp->setName(name);
	for (int i = 0; i < 3; i++) // 대분류 카테고리
	{
		for (int j = 0; j < 3; j++) // 중분류 카테고리
		{
			for (int k = 0; k < 3; k++) // 소분류 카테고리
			{
				Larges[i].Middles[j].Smalls[k].productList.ResetList();
				for (int l = 0; l < Larges[i].Middles[j].Smalls[k].productList.GetLength(); l++) // 리스트 길이만큼 반복
				{
					Larges[i].Middles[j].Smalls[k].productList.GetNextItem(Dummy); // 다음 리스트를 가리킴
					if (Dummy->getName() == temp->getName()) // 이름이 일치할 경우
					{
						if (Dummy->getSeller() != LoginedSeller->getCompany())//로그인한 회사의 상품이 아닐 경우
						{
							cout << "로그인 된 회사의 상품이 아닙니다." << endl;
							cout << "───────────────────" << endl;
							return 0;
						}
						Larges[i].Middles[j].Smalls[k].productList.Delete(Dummy); // 상품 삭제
						m_ProductList.Delete(Dummy);
						cout << "───────────────────" << endl;
						cout << "성공적으로 완료되었습니다." << endl;
						cout << "───────────────────" << endl;
						return 1;
						break;
					}
				}
			}
		}
	} 
	cout << "───────────────────" << endl; // 발견 실패 시
	cout << "상품 삭제에 실패하였습니다." << endl;
	cout << "───────────────────" << endl;

	return 0;
}
int Application::SellProduct()
{
	cout << "───────────────────" << endl;
	cout << "현재 판매중인 상품 리스트" << endl;
	cout << "───────────────────" << endl;
	LoginedSeller->printProductList(); // 현재 판매중인 상품 리스트 출력
	cout << "───────────────────" << endl;
	cout << "총 판매금 : " << LoginedSeller->getTotalCost() << endl; // 현재까지 판매된 금액을 출력
	cout << "───────────────────" << endl;
	return 1;
}
int Application::StorageProduct()
{
	string name;
	Product* temp = new Product(); // 임시 물품 변수 동적 할당
	Product* Dummy; 
	cout << "───────────────────" << endl;
	cout << "재고를 추가할 물건 이름을 입력하세요." << endl;
	cout << "───────────────────" << endl;
	LoginedSeller->printProductList(); // 현재 판매중인 상품 리스트 출력
	cout << "───────────────────" << endl;
	cin >> name;
	temp->setName(name);
	for (int i = 0; i < 3; i++) // 대분류 카테고리
	{
		for (int j = 0; j < 3; j++) // 중분류 카테고리
		{
			for (int k = 0; k < 3; k++) // 소분류 카테고리
			{
				Larges[i].Middles[j].Smalls[k].productList.ResetList(); // 리스트 포인터 초기화
				for (int l = 0; l < Larges[i].Middles[j].Smalls[k].productList.GetLength(); l++) // 리스트 길이만큼 반복
				{
					Larges[i].Middles[j].Smalls[k].productList.GetNextItem(Dummy); // 다음 리스트를 가리킴
					if (Dummy->getName() == temp->getName())
					{
						if (Dummy->getSeller() != LoginedSeller->getCompany()) // 로그인된 회사의 상품이 아닐 경우
						{
							cout << "로그인 된 회사의 상품이 아닙니다." << endl;
							cout << "───────────────────" << endl;
							return 0;
						}
						cout << "───────────────────" << endl;
						Dummy->printProductInfo(); // 현재 가리키는 물건의 정보 출력
						cout << "───────────────────" << endl;
						cout << "추가할 개수를 입력해 주세요." << endl;
						cout << "───────────────────" << endl;
						int choice4;
						cin >> choice4;
						if (choice4 <= 0) // 추가하고자 하는 개수가 0보다 같거나 작을 경우
						{
							cout << "───────────────────" << endl;
							cout << "잘못된 입력입니다." << endl;
							cout << "───────────────────" << endl;
							return 0;
						}
						Larges[i].Middles[j].Smalls[k].productList.Update(Dummy, 4, choice4); // 재고 추가
						cout << "───────────────────" << endl;
						cout << "성공적으로 완료되었습니다." << endl;
						cout << "───────────────────" << endl;
						return 1;
						break;
					}
				}
			}
		}
	}
	cout << "상품 수정에 실패하였습니다." << endl; // 상품을 발견하지 못했을 때
	cout << "───────────────────" << endl;
	return 0;
}


void Application::printShoppingBasket()
{
	Product* Temp = new Product(); // 임시 물품 변수 동적 할당
	Product* Real;
	cout << "───────────────────" << endl;
	LoginedCustomer->printShoppingBasket(); // 현재 로그인 한 고객의 장바구니 출력
	int command;
	cout << "───────────────────" << endl;
	cout << "상품 번호를 선택하여 정보를 확인합니다.\n0 입력 시 이전 메뉴로 돌아갑니다. " << endl;
	cout << "───────────────────" << endl;
	cin >> command;
	if (command == 0) // 0 입력시 현재 함수 종료
	{
		return;
	}
	Temp = LoginedCustomer->PassDummy(command); //선택한 번호의 상품 정보 출력

	for (int i = 0; i < 3; i++) // 대분류 카테고리
	{
		for (int j = 0; j < 3; j++) // 중분류 카테고리
		{
			for (int k = 0; k < 3; k++) // 소분류 카테고리
			{
				Larges[i].Middles[j].Smalls[k].productList.ResetList(); // 리스트 포인터 초기화
				for (int l = 0; l < Larges[i].Middles[j].Smalls[k].productList.GetLength(); l++) // 리스트 길이만큼 반복
				{
					Larges[i].Middles[j].Smalls[k].productList.GetNextItem(Real); // 다음 아이템을 가리킴
					if (Real->getName() == Temp->getName()) // 장바구니 내의 물품 이름과 리스트 내 물품의 이름이 같을 경우
					{
						BuyinBasket(*Real); // 리스트 내 물품을 구매
						return;
					}
				}
			}
		}
	}
}

int Application::BuyinBasket(Product& Dummy)
{
	int choice;
	cout << "1. 즉시 구매하기" << endl;
	cout << "2. 이전 메뉴로" << endl;
	cout << "───────────────────" << endl;
	cin >> choice;
	Product* Temp = new Product; // 임시 물품 변수 동적 할당
	Seller *New;
	switch (choice)
	{
	case 1: // 즉시 구매하기
		if (Dummy.getStock() <= 0) // Dummy의 재고가 0보다 작거나 같을 경우 예외 처리
		{
			cout << "모든 물량이 판매되었습니다." << endl;
			break;
		}
		LoginedCustomer->setMyShoppingList(&Dummy); // 로그인한 사용자의 쇼핑 리스트에 추가
		New = new Seller();
		m_SellerList.ResetList();
		for (int i = 0; i < m_SellerList.GetLength(); i++) // 판매자 리스트 길이만큼 반복
		{
			m_SellerList.GetNextItem(New);
			if (Dummy.getSeller() == New->getCompany()) // Dummy의 판매자가 Seller의 상호와 일치할 때
			{
				New->setTotalCost(Dummy.getPrice()); //판매자의 판매 금액 추가
				break;
			}
		}
		break;
	case 2: // 메뉴 호출
		getCustomerCommand();
		break;
	default: // 잘못된 입력 예외 처리
		cout << "───────────────────" << endl;
		cout << "잘못된 입력입니다." << endl;
		cout << "───────────────────" << endl;
		break;
	}
	return 0;
}

void Application::printRecentlyAdded()
{
	int size = m_ProductList.GetLength();
	int count = 0;
	for (int i = size - 5; i < size; i++)
	{
		cout << count + 1; m_ProductList.at(i)->printProductDisplay();
		count++;
	}
	int command; Product *Dummy = new Product();
	cout << "───────────────────" << endl;
	cout << "상품 번호를 선택하여 정보를 확인합니다.\n0 입력 시 이전 메뉴로 돌아갑니다. " << endl;
	cout << "───────────────────" << endl;
	cin >> command;
	if (command == 0) // 0 입력시 메뉴 호출
	{
		getCustomerCommand();
		return;
	}
	Dummy = m_ProductList.at(size - 6 + command);
	Dummy->printProductInfo(); // 현재 선택한 물품의 정보 출력
	cout << "───────────────────" << endl;
	Buy(*Dummy);
}

void Application::EventShop()
{
	Product *Dummy = new Product();
	cout << "───────────────────" << endl;
	cout << "누적 포인트 : " << LoginedCustomer->getPoint() << endl;
	cout << "───────────────────" << endl;
	cout << "진행중인 이벤트 " << endl;
	if (m_EventList.GetLength() == 0)
	{
		cout << "진행중인 이벤트가 없습니다." << endl;
		cout << "───────────────────" << endl;
		return;
	}
	for (int i = 0; i < m_EventList.GetLength(); i++)
	{
		cout << i + 1 << ". " << m_EventList.at(i)->getName() << "추첨 이벤트" << endl;
	}
	int command; cin >> command;
	cout << "───────────────────" << endl;
	cout << m_EventList.at(--command)->getName() << " 추첨 이벤트 입니다." << endl;
	cout << "경품명      : "; cout << m_EventList.at(command)->getName() << endl;
	cout << "참가 가능 수: "; cout << m_EventList.at(command)->getStock() << endl;
	cout << "현 참여 인원: "; cout << m_EventList.at(command)->getPrice() << endl;
	cout << "상품 이미지 : "; cout << m_EventList.at(command)->getImage() << endl;	
	cout << "───────────────────" << endl;
	cout << "참여하시겠습니까? \n1. 예 \n2. 아니오" << endl;
	int choice; cin >> choice;
	if (choice == 1)
	{
		if (LoginedCustomer->getPoint() < 100) // 포인트 모자람
		{
			cout << "포인트가 부족합니다." << endl;
			cout << "───────────────────" << endl;
			return;
		}
		LoginedCustomer->setPoint(LoginedCustomer->getPoint() - 100); // 포인트 깎음
		m_EventList.at(command)->setPrice(m_EventList.at(command)->getPrice() + 1);
		cout << "참여가 완료되었습니다." << endl;
		cout << "───────────────────" << endl;
		if (m_EventList.at(command)->getPrice() == m_EventList.at(command)->getStock())
		{
			srand((unsigned)time(NULL));
			cout << rand() % m_EventList.at(command)->getPrice() << "번 째 응모자가 당첨되었습니다." << endl;
			cout << "───────────────────" << endl;
			Dummy = m_EventList.at(command);
			m_EventList.Delete(Dummy);
		}
		
	}
	else if (choice == 2)
	{
		return;
	}
}

void Application::AddEvent()
{
	cout << "───────────────────" << endl;
	cout << "경품을 등록합니다." << endl;
	cout << "경품 카테고리를 선택해 주세요." << endl;
	cout << "───────────────────" << endl;
	int choice;
	for (int i = 0; i < 3; i++) // 대분류 카테고리 추가
	{
		cout << i + 1 << ". " << Larges[i].LargeCategory << endl;
	}
	cout << "───────────────────" << endl;
	cin >> choice;
	if (choice < 1 || choice>3) //잘못된 입력 시 예외 처리
	{
		cout << "───────────────────" << endl;
		cout << "잘못된 입력입니다." << endl;
		cout << "───────────────────" << endl;
		return;
	}
	choice--;
	int choice2;
	cout << "───────────────────" << endl;
	for (int i = 0; i < 3; i++) // 중분류 카테고리 추가
	{
		cout << i + 1 << ". " << Larges[choice].Middles[i].MiddleCategory << endl;
	}
	cout << "───────────────────" << endl;
	cin >> choice2;
	if (choice2 < 1 || choice2>3) // 잘못된 입력시 예외 처리
	{
		cout << "───────────────────" << endl;
		cout << "잘못된 입력입니다." << endl;
		cout << "───────────────────" << endl;
		return;
	}
	choice2--;
	int choice3;
	cout << "───────────────────" << endl;
	for (int i = 0; i < 3; i++) // 소분류 카테고리 추가
	{
		cout << i + 1 << ". " << Larges[choice].Middles[choice2].Smalls[i].SmallCategory << endl;
	}
	cout << "───────────────────" << endl;
	cin >> choice3;
	if (choice3 < 1 || choice3>3) // 잘못된 입력 시 예외 처리
	{
		cout << "───────────────────" << endl;
		cout << "잘못된 입력입니다." << endl;
		cout << "───────────────────" << endl;
		return;
	}
	choice3--;
	Product* New = new Product(); // 새로 추가할 물품 변수 추가
	string _Name;
	int _Stock;
	string _Image;
	cout << "───────────────────" << endl;
	cout << "경품명      : "; cin >> _Name;		//상품명 추가
												//상품 가격을 현재 이벤트에 참여중인 인원으로 사용
	cout << "참여 인원   : "; cin >> _Stock;	//재고를 참여 가능한 최대 인원으로 사용함
	cout << "상품 이미지 : "; cin >> _Image;	//이미지 추가
	New->setProduct(Larges[choice].LargeCategory, Larges[choice].Middles[choice2].MiddleCategory,
		Larges[choice].Middles[choice2].Smalls[choice3].SmallCategory, _Name, LoginedSeller->getCompany(),
		0, _Stock, _Image); // 입력받은 정보를 바탕으로 물품 설정
	m_EventList.Add(New); // 이벤트 리스트에 추가
	cout << "───────────────────" << endl;
	cout << "경품이 추가되었습니다." << endl;
	cout << "───────────────────" << endl;
	return;
}

