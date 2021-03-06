#include "Application.h"


Application::Application()
{
	system("title 2015104220 薑謙彌 - 澗ё路 婦葬 衛蝶蠱");
	load_customer_file();	// 堅偌 等檜攪 碳楝褥
	load_seller_file();		// っ衙濠 等檜攪 碳楝褥
	load_product_file();	// 僭ヶ 等檜攪 碳楝褥
}


Application::~Application()
{
}

void Application::run()
{
	cout << "忙式式式式式式式式式式式式式式式式式忖" << endl;
	cout << "弛忙式式式式式式式式式式式式式式式忖弛" << endl;
	cout << "弛弛∫   澗ё路 婦葬 Щ煎斜極   ∮弛弛" << endl;
	cout << "弛戌式式式式式式式式式式式式式式式戎弛" << endl;
	cout << "戌式式式式式式式式式式式式式式式式式戎" << endl;
	getMainCommand(); // 詭檣 詭景 ��轎
}

void Application::load_customer_file()
{
	ifstream loadCustomer("Customers.txt"); // Customers.txt だ橾 ��轎
	string _Id;
	string _Password;
	string _Name;
	int _Point;

	while (loadCustomer >> _Id >> _Password >> _Name >> _Point)  // だ橾 殮溘檜 橈擊 陽 梱雖 等檜攪蒂 碳楝褥
	{
		Customer* temp = new Customer(); // 歜衛 堅偌 滲熱 翕瞳 й渡
		temp->setCustomer(_Id, _Password, _Name, _Point); // 嫡擎 等檜攪 撲薑
		m_CustomerList.Add(temp); // 堅偌 葬蝶お縑 蹺陛
	}	
}

void Application::load_seller_file()
{
	ifstream loadSeller("Sellers.txt"); // Customers.txt だ橾 ��轎
	string _Company;
	string _RegistrationNumber;
	string _Name;
	string _PhoneNumber;
	int _Grade;	

	while (loadSeller >> _Company >> _RegistrationNumber >> _Name >> _PhoneNumber >> _Grade) // だ橾 殮溘檜 橈擊 陽 梱雖 等檜攪蒂 碳楝褥
	{
		Seller *temp = new Seller();// 歜衛 っ衙濠 滲熱 翕瞳 й渡
		temp->setSeller(_Company, _RegistrationNumber, _Name, _PhoneNumber, _Grade); // 嫡擎 等檜攪 撲薑
		m_SellerList.Add(temp);// っ衙濠 葬蝶お縑 蹺陛
	}
}

void Application::load_product_file()
{
	Larges[0].LargeCategory = "曖盟"; // 蘋纔堅葬 撲薑
	Larges[1].LargeCategory = "衝ヶ";
	Larges[2].LargeCategory = "蛤雖瓚";

	Larges[0].Middles[0].MiddleCategory = "罹撩曖盟";
	Larges[0].Middles[1].MiddleCategory = "陴撩曖盟";
	Larges[0].Middles[2].MiddleCategory = "嶸嬴曖盟";

	Larges[0].Middles[0].Smalls[0].SmallCategory = "罹撩鼻曖";
	Larges[0].Middles[0].Smalls[1].SmallCategory = "罹撩ж曖";
	Larges[0].Middles[0].Smalls[2].SmallCategory = "罹撩嬴辦攪";
	Larges[0].Middles[1].Smalls[0].SmallCategory = "陴撩鼻曖";
	Larges[0].Middles[1].Smalls[1].SmallCategory = "陴撩ж曖";
	Larges[0].Middles[1].Smalls[2].SmallCategory = "陴撩嬴辦攪";
	Larges[0].Middles[2].Smalls[0].SmallCategory = "嶸嬴鼻曖";
	Larges[0].Middles[2].Smalls[1].SmallCategory = "嶸嬴ж曖";
	Larges[0].Middles[2].Smalls[2].SmallCategory = "嶸嬴嬴辦攪";

	Larges[1].Middles[0].MiddleCategory = "褐摹衝ヶ";
	Larges[1].Middles[1].MiddleCategory = "陛奢衝ヶ";
	Larges[1].Middles[2].MiddleCategory = "勒鬼衝ヶ";

	Larges[1].Middles[0].Smalls[0].SmallCategory = "婁橾瓣模";
	Larges[1].Middles[0].Smalls[1].SmallCategory = "熱骯僭";
	Larges[1].Middles[0].Smalls[2].SmallCategory = "蹴骯僭";
	Larges[1].Middles[1].Smalls[0].SmallCategory = "婁濠除衝";
	Larges[1].Middles[1].Smalls[1].SmallCategory = "闊戮衝ヶ";
	Larges[1].Middles[1].Smalls[2].SmallCategory = "鱔褻葡";
	Larges[1].Middles[2].Smalls[0].SmallCategory = "�姣�";
	Larges[1].Middles[2].Smalls[1].SmallCategory = "艙曄薯";
	Larges[1].Middles[2].Smalls[2].SmallCategory = "棻檜橫お";

	Larges[2].Middles[0].MiddleCategory = "�瑒踰�";
	Larges[2].Middles[1].MiddleCategory = "闡У攪";
	Larges[2].Middles[2].MiddleCategory = "蘋詭塭";

	Larges[2].Middles[0].Smalls[0].SmallCategory = "SKT";
	Larges[2].Middles[0].Smalls[1].SmallCategory = "KT";
	Larges[2].Middles[0].Smalls[2].SmallCategory = "LG";
	Larges[2].Middles[1].Smalls[0].SmallCategory = "喻お磁";
	Larges[2].Middles[1].Smalls[1].SmallCategory = "等蝶觼鱉";
	Larges[2].Middles[1].Smalls[2].SmallCategory = "褻董PC";
	Larges[2].Middles[2].Smalls[0].SmallCategory = "蘋詭塭";
	Larges[2].Middles[2].Smalls[1].SmallCategory = "溶鍔";
	Larges[2].Middles[2].Smalls[2].SmallCategory = "擋撮憮葬";

	ifstream loadProduct("Products.txt"); // Product.txt だ橾縑憮 等檜攪 碳楝褥
	string _Category_Large;
	string _Category_Middle;
	string _Category_Small;
	string _Name;
	string _Seller;
	int _Price;
	int _Stock;
	string _Image;

	while (loadProduct >> _Category_Large >> _Category_Middle >> _Category_Small >> _Name >> _Seller >> _Price >> _Stock >> _Image) // だ橾 殮溘檜 橈擊 陽 梱雖 等檜攪蒂 碳楝褥
	{
		Product* temp = new Product();
		Seller* Dummy2;
		temp->setProduct(_Category_Large, _Category_Middle, _Category_Small, _Name, _Seller, _Price, _Stock, _Image); // 嫡擎 等檜攪 撲薑
		for (int i = 0; i < 3; i++) // 渠碟盟 蘋纔堅葬 撲薑
		{
			if (Larges[i].LargeCategory == temp->getCategoryLarge())  // 橾纂й 唳辦
			{
				for (int j = 0; j < 3; j++) // 醞碟盟 蘋纔堅葬 撲薑
				{
					if (Larges[i].Middles[j].MiddleCategory == temp->getCategoryMiddle()) // 橾纂й 唳辦
					{
						for (int k = 0; k < 3; k++) // 模碟盟 蘋纔堅葬 撲薑
						{
							if (Larges[i].Middles[j].Smalls[k].SmallCategory == temp->getCategorySmall()) // 橾纂й 唳辦
							{
								m_ProductList.Add(temp); // 瞪羹 僭勒 寡翮縑 蹺陛
								Larges[i].Middles[j].Smalls[k].productList.Add(temp);	 // 模碟盟 蘋纔堅葬 寰縑 ん檣攪	 						
								m_SellerList.ResetList();
								for (int l = 0; l < m_SellerList.GetLength(); l++) // 葬蝶お 望檜 虜躑 奩犒
								{
									m_SellerList.GetNextItem(Dummy2); 
									if (temp->getSeller() == Dummy2->getCompany())// っ衙濠陛 蛔煙и 僭勒橾 唳辦
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
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "1. 堅偌 賅萄\n2. っ衙濠 賅萄\n0. 謙猿" << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		int choice; //詭景 摹鷗
		string tempId, tempPw;
		cin >> choice; 
		switch (choice)
		{
		case 1: // 堅偌賅萄
			cout << "式式式式式式式式式式式式式式式式式式式" << endl;
			cout << "1. 晦襄 �蛾衋虞� 煎斜檣\n2. �蛾� 陛殮\n0. 檜瞪 詭景煎" << endl;
			cout << "式式式式式式式式式式式式式式式式式式式" << endl;
			cin >> choice;
			switch (choice) // 晦襄 �蛾衋虞� 煎斜檣 й 唳辦
			{
			case 1:
				cout << "ID : "; cin >> tempId;
				cout << "Password : "; cin >> tempPw;
				customerlogIn(tempId, tempPw); // 堅偌 煎斜檣 л熱 衛ч
				break;
			case 2: // 餌辨濠 蹺陛
				Add_Customer();
				break;
			case 0: //檜瞪 詭景 ��轎
				getMainCommand();
				break;
			default: // 澀跤脹 殮溘 蕨諼 籀葬
				cout << "式式式式式式式式式式式式式式式式式式式" << endl;
				cout << "澀跤脹 殮溘殮棲棻." << endl;
				cout << "式式式式式式式式式式式式式式式式式式式" << endl;
				break;
			}
			break;
		case 2: // っ衙濠 賅萄
			cout << "鼻�ㄧ� : "; cin >> tempId;
			cout << "餌機濠 蛔煙廓�� : "; cin >> tempPw;
			sellerlogin(tempId,tempPw);	 // っ衙濠 煎斜檣 л熱 衛ч		
			break;
		case 0: // 謙猿
			exit(100);
		default: // 澀跤脹 殮溘 蕨諼籀葬
			cout << "式式式式式式式式式式式式式式式式式式式" << endl;
			cout << "澀跤脹 殮溘殮棲棻." << endl;
			cout << "式式式式式式式式式式式式式式式式式式式" << endl;
			break;
		}
	}
	return 0;
}
int Application::getCustomerCommand()
{
	while (1)
	{
		printCustomerInfo();  // ⑷營 堅偌 薑爾蒂 爾罹邀
		cout << "1. 澗ё 衛濛ж晦\n2. 檜葷戲煎 匐儀ж晦\n3. 澗ё 葬蝶お �挫垥n4. 濰夥掘棲 �挫垥n5. 譆斬 蛔煙脹 鼻ヶ \n6. 唳ヶ 蹺繩\n7. �蛾讔內� 熱薑\n8. �蛾� 驍黴\n0. 煎斜嬴醒" << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: // 蘋纔堅葬 摹鷗ж罹 掘衙
			choiceLargeCategory();
			break;
		case 2: // 檜葷戲煎 匐儀ж罹 掘衙
			SearchProduct();
			break;
		case 3: // 澗ё 葬蝶お 轎溘
			LoginedCustomer->PrintMyShoppingList();
			break;
		case 4: // 濰夥掘棲 轎溘
			printShoppingBasket();
			break; 
		case 5: // 譆斬 蛔煙 葬蝶お 轎溘
			printRecentlyAdded();
			break;
		case 6: // 唳ヶ 蹺繩
			EventShop();
			break;
		case 7: // 堅偌 薑爾 偵褐
			Update_Customer();
			break;
		case 8: // 堅偌 驍黴
			Delete_Customer();
			break;			
		case 0: // 煎斜嬴醒
			customerLogOut();
			getMainCommand();
			break;
		default: // 澀跤脹 殮溘 蕨諼籀葬
			cout << "式式式式式式式式式式式式式式式式式式式" << endl;
			cout << "澀跤脹 殮溘殮棲棻." << endl;
			cout << "式式式式式式式式式式式式式式式式式式式" << endl;
			break;
		}
	}
	return 0;	
}
int Application::getSellerCommand()
{
	while (1)
	{
		printSellerInfo(); // ⑷營 っ衙濠 薑爾 轎溘
		cout << "1. 鼻ヶ 蛔煙\n2. 鼻ヶ 滲唳\n3. 鼻ヶ 餉薯\n4. 鼻ヶ っ衙 ⑷�淚n5. 鼻ヶ 殮堅\n6. 唳ヶ 蛔煙\n0. 煎斜嬴醒" << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: // 鼻ヶ 蛔煙
			AddProduct();
			break;
		case 2: // 鼻ヶ 滲唳
			UpdateProduct();
			break;
		case 3: // 鼻ヶ 餉薯
			DeleteProduct();
			break;
		case 4: // 鼻ヶ っ衙
			SellProduct();
			break;
		case 5: // 鼻ヶ 殮堅
			StorageProduct();
			break;
		case 6: // 唳ヶ 蛔煙
			AddEvent();
			break;
		case 0: // 煎斜嬴醒
			sellerLogOut();
			getMainCommand();
			break;
		default: // 澀跤脹 殮溘 蕨諼籀葬
			cout << "式式式式式式式式式式式式式式式式式式式" << endl;
			cout << "澀跤脹 殮溘殮棲棻." << endl;
			cout << "式式式式式式式式式式式式式式式式式式式" << endl;
			break;
		}
	}
	return 0;
}
void Application::Add_Customer()
{
	Customer *Temp = new Customer(); // 褐敘 堅偌 滲熱 摹樹
	string _Id, _PW, _N;
	cout << "啗薑擊 儅撩м棲棻." << endl;
	cout << "嬴檜蛤   : "; cin >> _Id;
	cout << "綠塵廓�� : "; cin >> _PW;
	cout << "檜葷     : "; cin >> _N;
	Temp->setCustomer(_Id, _PW, _N, 0); // 薑爾 殮溘
	m_CustomerList.Add(Temp); // 葬蝶お縑 蹺陛
	cout << "蛔煙檜 諫猿腎歷蝗棲棻." << endl;
}

void Application::Delete_Customer()
{
	string tempPW;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl; 
	cout << "獄檣 �挫怹� 嬪п 綠塵廓�ㄧ� 棻衛 殮溘п輿撮蹂." << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> tempPW;
	if (LoginedCustomer->getPassword() != tempPW) // 綠塵廓�ㄦ� 獄檣 營�挫�
	{
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "綠塵 廓�ㄟ� 橾纂ж雖 彊蝗棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		return;
	}
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "薑蜓 驍黴ж衛啊蝗棲梱?" << endl; 
	cout << "1. 蕨\n2. 嬴棲螃" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1: // 1 摹鷗衛
		m_CustomerList.Delete(LoginedCustomer); // �蛾� 餉薯
		cout << "驍黴陛 諫猿腎歷蝗棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		getMainCommand();
		break;
	case 2: // 2 摹鷗衛
		return;
		break;
	default: //澀跤脹 殮溘 蕨諼籀葬
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "澀跤脹 殮溘殮棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		break;
	}
}
void Application::Update_Customer()
{
	string tempPW;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "獄檣 �挫怹� 嬪п 綠塵廓�ㄧ� 棻衛 殮溘п輿撮蹂." << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> tempPW;
	if (LoginedCustomer->getPassword() != tempPW) // 綠塵廓�ㄦ� 獄檣 營�挫�
	{
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "綠塵 廓�ㄟ� 橾纂ж雖 彊蝗棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		return;
	}
	int choice;
	string temp;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "熱薑й 薑爾蒂 摹鷗п輿撮蹂." << endl;
	cout << "1. 檜葷\n2. 綠塵廓��" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> choice;
	switch (choice) // 熱薑й 薑爾 摹鷗
	{
	case 1: // 1 摹鷗衛
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "億 檜葷擊 殮溘п輿撮蹂." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cin >> temp;
		LoginedCustomer->setName(temp);
		m_CustomerList.Replace((LoginedCustomer),1,temp); // 檜葷 偵褐
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "盪濰腎歷蝗棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		break;
	case 2: // 2摹鷗衛
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "億 綠塵廓�ㄧ� 殮溘п輿撮蹂." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cin >> temp;
		LoginedCustomer->setPassword(temp);
		m_CustomerList.Replace((LoginedCustomer), 2, temp); // 綠塵廓�� 偵褐
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "盪濰腎歷蝗棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		break;
	default: // 澀跤脹 殮溘 蕨諼籀葬
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "澀跤脹 殮溘殮棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		break;
	}	
}

Customer* Application::customerlogIn(string _Id, string _Password)
{
	Customer Temp; //歜衛 堅偌 滲熱 摹樹
	Temp.setId(_Id); // 嬴檜蛤 撲薑
	Temp.setPassword(_Password); // 綠塵廓�� 撲薑
	int count = 0;
	Customer *Dummy = new Customer(); // ⑷營 鬚儀醞檣 喻萄蒂 陛腦酈朝 滲熱 摹樹
		
	m_CustomerList.ResetList(); 
	while (count < m_CustomerList.GetLength()) // 堅偌 葬蝶お 頂睡 牖��
	{
		m_CustomerList.GetNextItem(Dummy); 
		if (Dummy->getId() == Temp.getId()) // 橾纂ж朝 嬴檜蛤蒂 瓊懊擊 唳辦
		{
			if (Dummy->getPassword() == Temp.getPassword()) // 嬴檜蛤諦 綠塵廓�� 賅舒 橾纂ж朝 唳辦
				{
					cout << "撩奢瞳戲煎 煎斜檣 ж艘蝗棲棻." << endl;
					cout << "式式式式式式式式式式式式式式式式式式式" << endl;
					LoginedCustomer = (Dummy); // ⑷營 煎斜檣 脹 堅偌擊 Dummy煎 滲唳
					getCustomerCommand();
					return LoginedCustomer;
				}
			cout << "綠塵廓�ㄟ� 橾纂ж雖 彊蝗棲棻." << endl; // 綠塵廓�ㄟ� 橾纂ж雖 彊朝 唳辦
			cout << "式式式式式式式式式式式式式式式式式式式" << endl;
			return NULL;

		}
		count++;
	}

	cout << "橾纂ж朝 ID陛 橈蝗棲棻." << endl; // 橾纂ж朝 嬴檜蛤蒂 瓊雖 跤и 唳辦
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	return NULL;
}

void Application::customerLogOut()
{
	Customer* Dummy = new Customer(); // 歜衛 堅偌 滲熱 翕瞳 й渡
	m_CustomerList.ResetList();
	int count = 0;
	while (count < m_CustomerList.GetLength()) // 堅偌 葬蝶お蒂 鬚儀
	{
		m_CustomerList.GetNextItem(Dummy);
		if (Dummy->getId()==LoginedCustomer->getId()) // 橾纂ж朝 嬴檜蛤陛 氈擊 唳辦
		{
			break; // 奩犒僥 謙猿
		}
		count++;
	}
	Dummy = LoginedCustomer; // ⑷營梱雖曖 薑爾蒂 晦襄 堅偌縑 盪濰
	LoginedCustomer = NULL; // 煎斜檣脹 嶸盪蒂 NULL煎
}

Seller* Application::sellerlogin(string _Id, string _Password)
{
	Seller Temp; // っ衙濠 滲熱 摹樹
	Temp.setCompany(_Id); // 嬴檜蛤 鳶殮
	Temp.setRegistrationNumber(_Password); // 綠塵廓�� 鳶殮
	int count = 0;
	Seller* Dummy = new Seller(); // 歜衛 っ衙濠 滲熱 翕瞳 й渡

	m_SellerList.ResetList();
	while (count < m_SellerList.GetLength()) // っ衙濠 葬蝶お 牖��
	{
		m_SellerList.GetNextItem(Dummy);
		if (Dummy->getCompany() == Temp.getCompany()) // っ衙濠 鼻�ㄟ� 橾纂й 唳辦
		{
			if (Dummy->getRegistrationNumber() == Temp.getRegistrationNumber()) // 蛔煙脹 廓�� 傳и 橾纂ж朝雖 �挫恉�
			{
				cout << "撩奢瞳戲煎 煎斜檣 ж艘蝗棲棻." << endl;
				cout << "式式式式式式式式式式式式式式式式式式式" << endl;
				LoginedSeller = Dummy; // ⑷營 Dummy高擊 煎斜檣脹 っ衙濠 滲熱縑 盪濰
				getSellerCommand();
				return LoginedSeller;
			}
			cout << "餌機濠 蛔煙 廓�ㄟ� 橾纂ж雖 彊蝗棲棻." << endl; // 餌機濠 蛔煙廓�ㄟ� 橾纂ж雖 彊擊 唳辦
			cout << "式式式式式式式式式式式式式式式式式式式" << endl;
			return NULL;
		}
		count++;
	}
	cout << "橾纂ж朝 鼻�ㄟ� 橈蝗棲棻." << endl; //っ衙濠 鼻�ㄟ� 橾纂ж雖 彊朝 唳辦
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	return NULL;
}
void Application::sellerLogOut()
{
	LoginedSeller = NULL; // 煎斜檣脹 嶸盪蒂 NULL煎 
}

void Application::printCustomerInfo()
{
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "嬴檜蛤   :" << setw(10) << LoginedCustomer->getId() << endl; // 煎斜檣 脹 嶸盪曖 嬴檜蛤 轎溘
	cout << "檜葷     :" << setw(10) << LoginedCustomer->getName() << endl; //煎斜檣脹 嶸盪曖 檜葷 轎溘
	cout << "ん檣お   :" << setw(10) << LoginedCustomer->getPoint(); // ん檣お 轎溘
	cout << "\n式式式式式式式式式式式式式式式式式式式" << endl;
}

void Application::printSellerInfo()
{
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "鼻��     : " << setw(10) << LoginedSeller->getCompany() << endl; // 煎斜檣脹 っ衙濠曖 鼻�� 轎溘
	cout << "蛔煙廓�� : " << setw(10) << LoginedSeller->getRegistrationNumber() << endl; // 煎斜檣脹 っ衙濠曖 餌機濠蛔煙廓�� 轎溘
	cout << "檜葷     : " << setw(10) << LoginedSeller->getName() << endl;// 煎斜檣脹 っ衙濠曖 檜葷 轎溘
	cout << "翱塊籀   : " << setw(10) << LoginedSeller->getPhoneNumber() << endl;// 煎斜檣脹 っ衙濠曖 翱塊籀 轎溘
	cout << "っ衙蛔晝 : " << setw(10) << LoginedSeller->getGrade();// 煎斜檣脹 っ衙濠曖 っ衙蛔晝
	cout << "\n式式式式式式式式式式式式式式式式式式式" << endl;
}

void Application::choiceLargeCategory()
{
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "蘋纔堅葬蒂 摹鷗п 輿撮蹂." << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	int choice;
	for (int i = 0; i < 3; i++) // 渠碟盟 蘋纔堅葬 撲薑
	{
		cout << i+1 << ". " << Larges[i].LargeCategory << endl;
	}
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> choice;
	if (choice < 1 || choice>3) // 澀跤脹 殮溘 蕨諼籀葬
	{
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "澀跤脹 殮溘殮棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		return;
	}
	choice--;
	choiceMiddleCategory(choice); // 醞碟盟 蘋纔堅葬 撲薑戲煎 檜翕
}
void Application::choiceMiddleCategory(int choice)
{
	int choice2;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	for (int i = 0; i < 3; i++) // 醞碟盟 蘋纔堅葬 撲薑
	{
		cout << i+1 << ". " << Larges[choice].Middles[i].MiddleCategory << endl;
	}
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> choice2;
	if (choice2 < 1 || choice2>3) // 澀跤脹 殮溘 蕨諼籀葬
	{
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "澀跤脹 殮溘殮棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		return;
	}
	choice2--;
	choiceSmallCategory(choice, choice2); // 模碟盟 蘋纔堅葬 撲薑戲煎 檜翕
}

void Application::choiceSmallCategory(int choice, int choice2)
{
	int choice3;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	for (int i = 0; i < 3; i++)		// 模碟盟 蘋纔堅葬 撲薑
	{
		cout << i+1 << ". " << Larges[choice].Middles[choice2].Smalls[i].SmallCategory << endl;
	}
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> choice3;
	if (choice3 < 1 || choice3>3) // 澀跤脹 殮溘 蕨諼籀葬
	{
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "澀跤脹 殮溘殮棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		return;
	}
	choice3--;

	while (1)
	{
		Product *Dummy = new Product(); // 歜衛 僭ヶ 滲熱 翕瞳 й渡
		Larges[choice].Middles[choice2].Smalls[choice3].productList.ResetList(); // 摹鷗и 蘋纔堅葬曖 僭ヶ 葬蝶お
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << " 鼻ヶ貲        陛問   營堅 " << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		for (int j = 0; j < Larges[choice].Middles[choice2].Smalls[choice3].productList.GetLength(); j++) // 葬蝶お 望檜虜躑 奩犒
		{
			Larges[choice].Middles[choice2].Smalls[choice3].productList.GetNextItem(Dummy);  //摹鷗и 廓��曖 僭勒擊 碳楝螃晦 嬪п GetNextItem 衛ч
			cout << j+1; Dummy->printProductDisplay(); // 薑爾 轎溘
		}
		
		if (Larges[choice].Middles[choice2].Smalls[choice3].productList.GetLength() == 0) // 虜擒 僭ヶ檜 襄營ж雖 彊擊 唳辦 縑諼 籀葬
		{
			cout << "鼻ヶ檜 襄營ж雖 彊蝗棲棻." << endl;
			cout << "式式式式式式式式式式式式式式式式式式式" << endl;
			getCustomerCommand();
		}

		int command; 
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "鼻ヶ 廓�ㄧ� 摹鷗ж罹 薑爾蒂 �挫恉桭炴�.\n0 殮溘 衛 檜瞪 詭景煎 給嬴骨棲棻. " << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cin >> command;
		if (command == 0) // 0 殮溘衛 詭景 ��轎
		{
			getCustomerCommand();
			break;
		}

		Larges[choice].Middles[choice2].Smalls[choice3].productList.ResetList(); // 摹鷗и 蘋纔堅葬曖 僭ヶ 葬蝶お
		for (int k = 0; k < command; k++)
		{
			Larges[choice].Middles[choice2].Smalls[choice3].productList.GetNextItem(Dummy); // 摹鷗и 廓��曖 僭勒擊 碳楝螃晦 嬪п GetNextItem 衛ч
		}
		Dummy->printProductInfo(); // ⑷營 摹鷗и 僭ヶ曖 薑爾 轎溘
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		Buy(*Dummy); // 掘衙 л熱 衛ч
	}
}

int Application::Buy(Product& Dummy)
{
	int choice;
	cout << "1. 闊衛 掘衙ж晦" << endl;
	cout << "2. 濰夥掘棲縑 氬晦" << endl;
	cout << "3. 檜瞪 詭景煎" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> choice;
	Seller *New; // 歜衛 っ衙濠 ん檣攪 滲熱
	switch (choice)
	{
	case 1: // 僭勒 闊衛 掘衙ж晦
		if (Dummy.getStock() <= 0) // 虜擒 摹鷗и 僭勒曖 營堅陛 0橾 唳辦 蕨諼 籀葬
		{
			cout << "賅萇 僭榆檜 っ衙腎歷蝗棲棻." << endl;
			break;
		}
		LoginedCustomer->setMyShoppingList(&Dummy); // 煎斜檣 脹 嶸盪曖 澗ё 葬蝶お縑 蹺陛
		
		LoginedCustomer->setPoint(LoginedCustomer->getPoint() + Dummy.getPrice() / 10);
		New = new Seller(); // 歜衛 っ衙濠 滲熱 摹樹
		m_SellerList.ResetList();
		for (int i = 0; i < m_SellerList.GetLength(); i++)  // っ衙濠 葬蝶お虜躑 奩犒
		{
			m_SellerList.GetNextItem(New);
			if (Dummy.getSeller() == New->getCompany()) // 僭勒曖 鼻�ㄟ� 偽擎 っ衙濠 嫦唯 衛
			{
				New->setTotalCost(Dummy.getPrice()); // っ衙濠曖 っ衙 旎擋 蹺陛
				break;
			}
		}
		break;
	case 2: // 僭勒 濰夥掘棲縑 氬晦
		LoginedCustomer->setShoppingBasket(Dummy);
		cout << "濰夥掘棲縑 氬啣蝗棲棻." << endl;
		break;
	case 3: // 詭景 轎溘
		getCustomerCommand();
		break;
	default: // 澀跤脹 殮溘 蕨諼 籀葬
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "澀跤脹 殮溘殮棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		break;
	}
	return 0;
}

int Application::SearchProduct()
{
	string name;
	Product* temp = new Product(); // 歜衛 僭勒 滲熱 摹樹
	Product* Dummy; // 渦嘐 撲薑
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "瓊戲衛朝 僭勒 檜葷擊 殮溘ж撮蹂." << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> name;
	temp->setName(name);
	for (int i = 0; i < 3; i++) // 渠碟盟 蘋纔堅葬
	{
		for (int j = 0; j < 3; j++) // 醞碟盟 蘋纔堅葬
		{
			for (int k = 0; k < 3; k++) // 模碟盟 蘋纔堅葬
			{
				Larges[i].Middles[j].Smalls[k].productList.ResetList(); // 葬蝶お ん檣攪 蟾晦��
				for (int l = 0; l < Larges[i].Middles[j].Smalls[k].productList.GetLength(); l++) // 葬蝶お 望檜虜躑 奩犒
				{
					Larges[i].Middles[j].Smalls[k].productList.GetNextItem(Dummy); // 棻擠 葬蝶お蒂 陛葬霽
					if (Dummy->getName() == temp->getName()) // 瓊堅濠 ж朝  檜葷檜 橾纂й 唳辦
					{
						cout << "式式式式式式式式式式式式式式式式式式式" << endl;
						Dummy->printProductInfo(); // ⑷營 薑爾 轎溘
						Buy(*Dummy); // 掘衙 л熱 轎溘
						return 1;
						break;
					}
				}
			}
		}
	}
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "瓊戲衛朝 僭勒檜 橈蝗棲棻." << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	return 0;
}

int Application::AddProduct()
{
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "鼻ヶ 蛔煙擊 嬪и 薑爾蒂 殮溘м棲棻." << endl;
	cout << "鼻ヶ 蘋纔堅葬蒂 摹鷗п 輿撮蹂." << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	int choice;
	for (int i = 0; i < 3; i++) // 渠碟盟 蘋纔堅葬 蹺陛
	{
		cout << i + 1 << ". " << Larges[i].LargeCategory << endl;
	}
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> choice;
	if (choice < 1 || choice>3) //澀跤脹 殮溘 衛 蕨諼 籀葬
	{
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "澀跤脹 殮溘殮棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		return 0;
	}
	choice--;
	int choice2;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	for (int i = 0; i < 3; i++) // 醞碟盟 蘋纔堅葬 蹺陛
	{
		cout << i + 1 << ". " << Larges[choice].Middles[i].MiddleCategory << endl;
	}
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> choice2;
	if (choice2 < 1 || choice2>3) // 澀跤脹 殮溘衛 蕨諼 籀葬
	{
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "澀跤脹 殮溘殮棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		return 0;
	}
	choice2--;
	int choice3;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	for (int i = 0; i < 3; i++) // 模碟盟 蘋纔堅葬 蹺陛
	{
		cout << i + 1 << ". " << Larges[choice].Middles[choice2].Smalls[i].SmallCategory << endl;
	}
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> choice3;
	if (choice3 < 1 || choice3>3) // 澀跤脹 殮溘 衛 蕨諼 籀葬
	{
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "澀跤脹 殮溘殮棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		return 0;
	}
	choice3--;

	Product* New = new Product(); // 億煎 蹺陛й 僭ヶ 滲熱 蹺陛
	string _Name; 
	int _Price;
	int _Stock;
	string _Image;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "鼻ヶ貲      : "; cin >> _Name; //鼻ヶ貲 蹺陛
	cout << "鼻ヶ 陛問   : "; cin >> _Price;//鼻ヶ 陛問 蹺陛
	cout << "鼻ヶ 營堅   : "; cin >> _Stock;//鼻ヶ 營堅 蹺陛
	cout << "鼻ヶ 檜嘐雖 : "; cin >> _Image;//檜嘐雖 蹺陛
	New->setProduct(Larges[choice].LargeCategory, Larges[choice].Middles[choice2].MiddleCategory, 
		Larges[choice].Middles[choice2].Smalls[choice3].SmallCategory,_Name,LoginedSeller->getCompany(),
		_Price,_Stock,_Image); // 殮溘嫡擎 薑爾蒂 夥鰻戲煎 僭ヶ 撲薑
	Larges[choice].Middles[choice2].Smalls[choice3].productList.Add(New); // 僭ヶ 葬蝶お縑 蹺陛
	m_ProductList.Add(New);
	LoginedSeller->setSellerProducts(New); //煎斜檣脹 っ衙濠曖 っ衙醞檣 僭勒縑 蹺陛
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "鼻ヶ檜 蹺陛腎歷蝗棲棻." << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	return 0;
}

int Application::UpdateProduct()
{
	string name;
	Product* temp = new Product(); // 歜衛 僭ヶ 滲熱 翕瞳 й渡
	Product* Dummy;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "熱薑ж褒 僭勒 檜葷擊 殮溘ж撮蹂." << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	LoginedSeller->printProductList(); // ⑷營 っ衙醞檣 僭勒 葬蝶お 轎溘
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> name;
	temp->setName(name);
	for (int i = 0; i < 3; i++) // 渠碟盟 蘋纔堅葬
	{
		for (int j = 0; j < 3; j++) // 醞碟盟 蘋纔堅葬
		{
			for (int k = 0; k < 3; k++) // 模碟盟 蘋纔堅葬
			{
				Larges[i].Middles[j].Smalls[k].productList.ResetList();
				for (int l = 0; l < Larges[i].Middles[j].Smalls[k].productList.GetLength(); l++) // 葬蝶お 望檜虜躑 奩犒
				{
					Larges[i].Middles[j].Smalls[k].productList.GetNextItem(Dummy); // 棻擠 葬蝶お蒂 陛葬霽
					if (Dummy->getName() == temp->getName()) // 橾纂ж朝 僭勒 嫦唯 衛
					{
						if (Dummy->getSeller() != LoginedSeller->getCompany()) // っ衙ж朝 �蜓蝩� 僭ヶ檜 嬴棍 唳辦
						{
							cout << "煎斜檣 脹 �蜓蝩� 鼻ヶ檜 嬴椎棲棻." << endl;
							cout << "式式式式式式式式式式式式式式式式式式式" << endl;
							return 0;
						}
						cout << "式式式式式式式式式式式式式式式式式式式" << endl;
						string _Name;
						string _Image;
						int _Price;
						Dummy->printProductInfo(); // ⑷營 薑爾 轎溘
						cout << "式式式式式式式式式式式式式式式式式式式" << endl;
						cout << "橫雯 薑爾蒂 熱薑ж衛啊蝗棲梱?" << endl;
						cout << "式式式式式式式式式式式式式式式式式式式" << endl;
						cout << "1. 鼻ヶ貲" << endl;
						cout << "2. 鼻ヶ 陛問" << endl;
						cout << "3. 鼻ヶ 檜嘐雖" << endl;
						cout << "式式式式式式式式式式式式式式式式式式式" << endl;
						int choice4;
						cin >> choice4;
						cout << "式式式式式式式式式式式式式式式式式式式" << endl;
						cout << "熱薑й 薑爾蒂 殮溘ж撮蹂." << endl;
						cout << "式式式式式式式式式式式式式式式式式式式" << endl;

						switch (choice4)
						{
						case 1: // 檜葷 熱薑
							cin >> _Name;
							Larges[i].Middles[j].Smalls[k].productList.Update(Dummy, 1, _Name);
							break;
						case 2: // 陛問 熱薑
							cin >> _Price;
							Larges[i].Middles[j].Smalls[k].productList.Update(Dummy, 2, _Price);
							break;
						case 3: // 檜嘐雖 熱薑
							cin >> _Image;
							Larges[i].Middles[j].Smalls[k].productList.Update(Dummy, 3, _Name);
							break;
						default: // 澀跤脹 殮溘 衛 蕨諼 籀葬
							cout << "式式式式式式式式式式式式式式式式式式式" << endl;
							cout << "澀跤脹 殮溘殮棲棻." << endl;
							cout << "式式式式式式式式式式式式式式式式式式式" << endl;
							break;
						} 
						cout << "式式式式式式式式式式式式式式式式式式式" << endl;
						cout << "撩奢瞳戲煎 諫猿腎歷蝗棲棻." << endl;
						cout << "式式式式式式式式式式式式式式式式式式式" << endl;
						return 1;
						break;
					}
				}
			}
		}
	}
	cout << "鼻ヶ 熱薑縑 褒ぬж艘蝗棲棻." << endl; // 蘋纔堅葬縑憮 嫦唯 褒ぬ 衛
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	return 0; 
	
}
int Application::DeleteProduct()
{
	string name;
	Product* temp = new Product(); // 歜衛 僭ヶ 滲熱 翕瞳 й渡
	Product* Dummy;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "餉薯ж褒 僭勒 檜葷擊 殮溘ж撮蹂." << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	LoginedSeller->printProductList(); // っ衙醞檣 僭勒 葬蝶お 轎溘
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> name;
	temp->setName(name);
	for (int i = 0; i < 3; i++) // 渠碟盟 蘋纔堅葬
	{
		for (int j = 0; j < 3; j++) // 醞碟盟 蘋纔堅葬
		{
			for (int k = 0; k < 3; k++) // 模碟盟 蘋纔堅葬
			{
				Larges[i].Middles[j].Smalls[k].productList.ResetList();
				for (int l = 0; l < Larges[i].Middles[j].Smalls[k].productList.GetLength(); l++) // 葬蝶お 望檜虜躑 奩犒
				{
					Larges[i].Middles[j].Smalls[k].productList.GetNextItem(Dummy); // 棻擠 葬蝶お蒂 陛葬霽
					if (Dummy->getName() == temp->getName()) // 檜葷檜 橾纂й 唳辦
					{
						if (Dummy->getSeller() != LoginedSeller->getCompany())//煎斜檣и �蜓蝩� 鼻ヶ檜 嬴棍 唳辦
						{
							cout << "煎斜檣 脹 �蜓蝩� 鼻ヶ檜 嬴椎棲棻." << endl;
							cout << "式式式式式式式式式式式式式式式式式式式" << endl;
							return 0;
						}
						Larges[i].Middles[j].Smalls[k].productList.Delete(Dummy); // 鼻ヶ 餉薯
						m_ProductList.Delete(Dummy);
						cout << "式式式式式式式式式式式式式式式式式式式" << endl;
						cout << "撩奢瞳戲煎 諫猿腎歷蝗棲棻." << endl;
						cout << "式式式式式式式式式式式式式式式式式式式" << endl;
						return 1;
						break;
					}
				}
			}
		}
	} 
	cout << "式式式式式式式式式式式式式式式式式式式" << endl; // 嫦唯 褒ぬ 衛
	cout << "鼻ヶ 餉薯縑 褒ぬж艘蝗棲棻." << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;

	return 0;
}
int Application::SellProduct()
{
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "⑷營 っ衙醞檣 鼻ヶ 葬蝶お" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	LoginedSeller->printProductList(); // ⑷營 っ衙醞檣 鼻ヶ 葬蝶お 轎溘
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "識 っ衙旎 : " << LoginedSeller->getTotalCost() << endl; // ⑷營梱雖 っ衙脹 旎擋擊 轎溘
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	return 1;
}
int Application::StorageProduct()
{
	string name;
	Product* temp = new Product(); // 歜衛 僭ヶ 滲熱 翕瞳 й渡
	Product* Dummy; 
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "營堅蒂 蹺陛й 僭勒 檜葷擊 殮溘ж撮蹂." << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	LoginedSeller->printProductList(); // ⑷營 っ衙醞檣 鼻ヶ 葬蝶お 轎溘
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> name;
	temp->setName(name);
	for (int i = 0; i < 3; i++) // 渠碟盟 蘋纔堅葬
	{
		for (int j = 0; j < 3; j++) // 醞碟盟 蘋纔堅葬
		{
			for (int k = 0; k < 3; k++) // 模碟盟 蘋纔堅葬
			{
				Larges[i].Middles[j].Smalls[k].productList.ResetList(); // 葬蝶お ん檣攪 蟾晦��
				for (int l = 0; l < Larges[i].Middles[j].Smalls[k].productList.GetLength(); l++) // 葬蝶お 望檜虜躑 奩犒
				{
					Larges[i].Middles[j].Smalls[k].productList.GetNextItem(Dummy); // 棻擠 葬蝶お蒂 陛葬霽
					if (Dummy->getName() == temp->getName())
					{
						if (Dummy->getSeller() != LoginedSeller->getCompany()) // 煎斜檣脹 �蜓蝩� 鼻ヶ檜 嬴棍 唳辦
						{
							cout << "煎斜檣 脹 �蜓蝩� 鼻ヶ檜 嬴椎棲棻." << endl;
							cout << "式式式式式式式式式式式式式式式式式式式" << endl;
							return 0;
						}
						cout << "式式式式式式式式式式式式式式式式式式式" << endl;
						Dummy->printProductInfo(); // ⑷營 陛葬酈朝 僭勒曖 薑爾 轎溘
						cout << "式式式式式式式式式式式式式式式式式式式" << endl;
						cout << "蹺陛й 偃熱蒂 殮溘п 輿撮蹂." << endl;
						cout << "式式式式式式式式式式式式式式式式式式式" << endl;
						int choice4;
						cin >> choice4;
						if (choice4 <= 0) // 蹺陛ж堅濠 ж朝 偃熱陛 0爾棻 偽剪釭 濛擊 唳辦
						{
							cout << "式式式式式式式式式式式式式式式式式式式" << endl;
							cout << "澀跤脹 殮溘殮棲棻." << endl;
							cout << "式式式式式式式式式式式式式式式式式式式" << endl;
							return 0;
						}
						Larges[i].Middles[j].Smalls[k].productList.Update(Dummy, 4, choice4); // 營堅 蹺陛
						cout << "式式式式式式式式式式式式式式式式式式式" << endl;
						cout << "撩奢瞳戲煎 諫猿腎歷蝗棲棻." << endl;
						cout << "式式式式式式式式式式式式式式式式式式式" << endl;
						return 1;
						break;
					}
				}
			}
		}
	}
	cout << "鼻ヶ 熱薑縑 褒ぬж艘蝗棲棻." << endl; // 鼻ヶ擊 嫦唯ж雖 跤ц擊 陽
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	return 0;
}


void Application::printShoppingBasket()
{
	Product* Temp = new Product(); // 歜衛 僭ヶ 滲熱 翕瞳 й渡
	Product* Real;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	LoginedCustomer->printShoppingBasket(); // ⑷營 煎斜檣 и 堅偌曖 濰夥掘棲 轎溘
	int command;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "鼻ヶ 廓�ㄧ� 摹鷗ж罹 薑爾蒂 �挫恉桭炴�.\n0 殮溘 衛 檜瞪 詭景煎 給嬴骨棲棻. " << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> command;
	if (command == 0) // 0 殮溘衛 ⑷營 л熱 謙猿
	{
		return;
	}
	Temp = LoginedCustomer->PassDummy(command); //摹鷗и 廓��曖 鼻ヶ 薑爾 轎溘

	for (int i = 0; i < 3; i++) // 渠碟盟 蘋纔堅葬
	{
		for (int j = 0; j < 3; j++) // 醞碟盟 蘋纔堅葬
		{
			for (int k = 0; k < 3; k++) // 模碟盟 蘋纔堅葬
			{
				Larges[i].Middles[j].Smalls[k].productList.ResetList(); // 葬蝶お ん檣攪 蟾晦��
				for (int l = 0; l < Larges[i].Middles[j].Smalls[k].productList.GetLength(); l++) // 葬蝶お 望檜虜躑 奩犒
				{
					Larges[i].Middles[j].Smalls[k].productList.GetNextItem(Real); // 棻擠 嬴檜蠱擊 陛葬霽
					if (Real->getName() == Temp->getName()) // 濰夥掘棲 頂曖 僭ヶ 檜葷婁 葬蝶お 頂 僭ヶ曖 檜葷檜 偽擊 唳辦
					{
						BuyinBasket(*Real); // 葬蝶お 頂 僭ヶ擊 掘衙
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
	cout << "1. 闊衛 掘衙ж晦" << endl;
	cout << "2. 檜瞪 詭景煎" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> choice;
	Product* Temp = new Product; // 歜衛 僭ヶ 滲熱 翕瞳 й渡
	Seller *New;
	switch (choice)
	{
	case 1: // 闊衛 掘衙ж晦
		if (Dummy.getStock() <= 0) // Dummy曖 營堅陛 0爾棻 濛剪釭 偽擊 唳辦 蕨諼 籀葬
		{
			cout << "賅萇 僭榆檜 っ衙腎歷蝗棲棻." << endl;
			break;
		}
		LoginedCustomer->setMyShoppingList(&Dummy); // 煎斜檣и 餌辨濠曖 澗ё 葬蝶お縑 蹺陛
		New = new Seller();
		m_SellerList.ResetList();
		for (int i = 0; i < m_SellerList.GetLength(); i++) // っ衙濠 葬蝶お 望檜虜躑 奩犒
		{
			m_SellerList.GetNextItem(New);
			if (Dummy.getSeller() == New->getCompany()) // Dummy曖 っ衙濠陛 Seller曖 鼻�ˋ� 橾纂й 陽
			{
				New->setTotalCost(Dummy.getPrice()); //っ衙濠曖 っ衙 旎擋 蹺陛
				break;
			}
		}
		break;
	case 2: // 詭景 ��轎
		getCustomerCommand();
		break;
	default: // 澀跤脹 殮溘 蕨諼 籀葬
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "澀跤脹 殮溘殮棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
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
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "鼻ヶ 廓�ㄧ� 摹鷗ж罹 薑爾蒂 �挫恉桭炴�.\n0 殮溘 衛 檜瞪 詭景煎 給嬴骨棲棻. " << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> command;
	if (command == 0) // 0 殮溘衛 詭景 ��轎
	{
		getCustomerCommand();
		return;
	}
	Dummy = m_ProductList.at(size - 6 + command);
	Dummy->printProductInfo(); // ⑷營 摹鷗и 僭ヶ曖 薑爾 轎溘
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	Buy(*Dummy);
}

void Application::EventShop()
{
	Product *Dummy = new Product();
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "援瞳 ん檣お : " << LoginedCustomer->getPoint() << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "霞ч醞檣 檜漸お " << endl;
	if (m_EventList.GetLength() == 0)
	{
		cout << "霞ч醞檣 檜漸お陛 橈蝗棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		return;
	}
	for (int i = 0; i < m_EventList.GetLength(); i++)
	{
		cout << i + 1 << ". " << m_EventList.at(i)->getName() << "蹺繩 檜漸お" << endl;
	}
	int command; cin >> command;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << m_EventList.at(--command)->getName() << " 蹺繩 檜漸お 殮棲棻." << endl;
	cout << "唳ヶ貲      : "; cout << m_EventList.at(command)->getName() << endl;
	cout << "霤陛 陛棟 熱: "; cout << m_EventList.at(command)->getStock() << endl;
	cout << "⑷ 霤罹 檣錳: "; cout << m_EventList.at(command)->getPrice() << endl;
	cout << "鼻ヶ 檜嘐雖 : "; cout << m_EventList.at(command)->getImage() << endl;	
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "霤罹ж衛啊蝗棲梱? \n1. 蕨 \n2. 嬴棲螃" << endl;
	int choice; cin >> choice;
	if (choice == 1)
	{
		if (LoginedCustomer->getPoint() < 100) // ん檣お 賅濠塋
		{
			cout << "ん檣お陛 睡褶м棲棻." << endl;
			cout << "式式式式式式式式式式式式式式式式式式式" << endl;
			return;
		}
		LoginedCustomer->setPoint(LoginedCustomer->getPoint() - 100); // ん檣お 梗擠
		m_EventList.at(command)->setPrice(m_EventList.at(command)->getPrice() + 1);
		cout << "霤罹陛 諫猿腎歷蝗棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		if (m_EventList.at(command)->getPrice() == m_EventList.at(command)->getStock())
		{
			srand((unsigned)time(NULL));
			cout << rand() % m_EventList.at(command)->getPrice() << "廓 簞 擬賅濠陛 渡繩腎歷蝗棲棻." << endl;
			cout << "式式式式式式式式式式式式式式式式式式式" << endl;
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
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "唳ヶ擊 蛔煙м棲棻." << endl;
	cout << "唳ヶ 蘋纔堅葬蒂 摹鷗п 輿撮蹂." << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	int choice;
	for (int i = 0; i < 3; i++) // 渠碟盟 蘋纔堅葬 蹺陛
	{
		cout << i + 1 << ". " << Larges[i].LargeCategory << endl;
	}
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> choice;
	if (choice < 1 || choice>3) //澀跤脹 殮溘 衛 蕨諼 籀葬
	{
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "澀跤脹 殮溘殮棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		return;
	}
	choice--;
	int choice2;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	for (int i = 0; i < 3; i++) // 醞碟盟 蘋纔堅葬 蹺陛
	{
		cout << i + 1 << ". " << Larges[choice].Middles[i].MiddleCategory << endl;
	}
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> choice2;
	if (choice2 < 1 || choice2>3) // 澀跤脹 殮溘衛 蕨諼 籀葬
	{
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "澀跤脹 殮溘殮棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		return;
	}
	choice2--;
	int choice3;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	for (int i = 0; i < 3; i++) // 模碟盟 蘋纔堅葬 蹺陛
	{
		cout << i + 1 << ". " << Larges[choice].Middles[choice2].Smalls[i].SmallCategory << endl;
	}
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cin >> choice3;
	if (choice3 < 1 || choice3>3) // 澀跤脹 殮溘 衛 蕨諼 籀葬
	{
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "澀跤脹 殮溘殮棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式式式" << endl;
		return;
	}
	choice3--;
	Product* New = new Product(); // 億煎 蹺陛й 僭ヶ 滲熱 蹺陛
	string _Name;
	int _Stock;
	string _Image;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "唳ヶ貲      : "; cin >> _Name;		//鼻ヶ貲 蹺陛
												//鼻ヶ 陛問擊 ⑷營 檜漸お縑 霤罹醞檣 檣錳戲煎 餌辨
	cout << "霤罹 檣錳   : "; cin >> _Stock;	//營堅蒂 霤罹 陛棟и 譆渠 檣錳戲煎 餌辨л
	cout << "鼻ヶ 檜嘐雖 : "; cin >> _Image;	//檜嘐雖 蹺陛
	New->setProduct(Larges[choice].LargeCategory, Larges[choice].Middles[choice2].MiddleCategory,
		Larges[choice].Middles[choice2].Smalls[choice3].SmallCategory, _Name, LoginedSeller->getCompany(),
		0, _Stock, _Image); // 殮溘嫡擎 薑爾蒂 夥鰻戲煎 僭ヶ 撲薑
	m_EventList.Add(New); // 檜漸お 葬蝶お縑 蹺陛
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "唳ヶ檜 蹺陛腎歷蝗棲棻." << endl;
	cout << "式式式式式式式式式式式式式式式式式式式" << endl;
	return;
}

