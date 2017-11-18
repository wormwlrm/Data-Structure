#include "Application.h"


Application::Application()
{
	system("title 2015104220 ������ - ���θ� ���� �ý���");
	load_customer_file();	// �� ������ �ҷ���
	load_seller_file();		// �Ǹ��� ������ �ҷ���
	load_product_file();	// ��ǰ ������ �ҷ���
}


Application::~Application()
{
}

void Application::run()
{
	cout << "��������������������������������������" << endl;
	cout << "��������������������������������������" << endl;
	cout << "������   ���θ� ���� ���α׷�   ����" << endl;
	cout << "��������������������������������������" << endl;
	cout << "��������������������������������������" << endl;
	getMainCommand(); // ���� �޴� ȣ��
}

void Application::load_customer_file()
{
	ifstream loadCustomer("Customers.txt"); // Customers.txt ���� ȣ��
	string _Id;
	string _Password;
	string _Name;
	int _Point;

	while (loadCustomer >> _Id >> _Password >> _Name >> _Point)  // ���� �Է��� ���� �� ���� �����͸� �ҷ���
	{
		Customer* temp = new Customer(); // �ӽ� �� ���� ���� �Ҵ�
		temp->setCustomer(_Id, _Password, _Name, _Point); // ���� ������ ����
		m_CustomerList.Add(temp); // �� ����Ʈ�� �߰�
	}	
}

void Application::load_seller_file()
{
	ifstream loadSeller("Sellers.txt"); // Customers.txt ���� ȣ��
	string _Company;
	string _RegistrationNumber;
	string _Name;
	string _PhoneNumber;
	int _Grade;	

	while (loadSeller >> _Company >> _RegistrationNumber >> _Name >> _PhoneNumber >> _Grade) // ���� �Է��� ���� �� ���� �����͸� �ҷ���
	{
		Seller *temp = new Seller();// �ӽ� �Ǹ��� ���� ���� �Ҵ�
		temp->setSeller(_Company, _RegistrationNumber, _Name, _PhoneNumber, _Grade); // ���� ������ ����
		m_SellerList.Add(temp);// �Ǹ��� ����Ʈ�� �߰�
	}
}

void Application::load_product_file()
{
	Larges[0].LargeCategory = "�Ƿ�"; // ī�װ� ����
	Larges[1].LargeCategory = "��ǰ";
	Larges[2].LargeCategory = "������";

	Larges[0].Middles[0].MiddleCategory = "�����Ƿ�";
	Larges[0].Middles[1].MiddleCategory = "�����Ƿ�";
	Larges[0].Middles[2].MiddleCategory = "�����Ƿ�";

	Larges[0].Middles[0].Smalls[0].SmallCategory = "��������";
	Larges[0].Middles[0].Smalls[1].SmallCategory = "��������";
	Larges[0].Middles[0].Smalls[2].SmallCategory = "�����ƿ���";
	Larges[0].Middles[1].Smalls[0].SmallCategory = "��������";
	Larges[0].Middles[1].Smalls[1].SmallCategory = "��������";
	Larges[0].Middles[1].Smalls[2].SmallCategory = "�����ƿ���";
	Larges[0].Middles[2].Smalls[0].SmallCategory = "���ƻ���";
	Larges[0].Middles[2].Smalls[1].SmallCategory = "��������";
	Larges[0].Middles[2].Smalls[2].SmallCategory = "���ƾƿ���";

	Larges[1].Middles[0].MiddleCategory = "�ż���ǰ";
	Larges[1].Middles[1].MiddleCategory = "������ǰ";
	Larges[1].Middles[2].MiddleCategory = "�ǰ���ǰ";

	Larges[1].Middles[0].Smalls[0].SmallCategory = "����ä��";
	Larges[1].Middles[0].Smalls[1].SmallCategory = "���깰";
	Larges[1].Middles[0].Smalls[2].SmallCategory = "��깰";
	Larges[1].Middles[1].Smalls[0].SmallCategory = "���ڰ���";
	Larges[1].Middles[1].Smalls[1].SmallCategory = "�Ｎ��ǰ";
	Larges[1].Middles[1].Smalls[2].SmallCategory = "������";
	Larges[1].Middles[2].Smalls[0].SmallCategory = "ȫ��";
	Larges[1].Middles[2].Smalls[1].SmallCategory = "������";
	Larges[1].Middles[2].Smalls[2].SmallCategory = "���̾�Ʈ";

	Larges[2].Middles[0].MiddleCategory = "�޴���";
	Larges[2].Middles[1].MiddleCategory = "��ǻ��";
	Larges[2].Middles[2].MiddleCategory = "ī�޶�";

	Larges[2].Middles[0].Smalls[0].SmallCategory = "SKT";
	Larges[2].Middles[0].Smalls[1].SmallCategory = "KT";
	Larges[2].Middles[0].Smalls[2].SmallCategory = "LG";
	Larges[2].Middles[1].Smalls[0].SmallCategory = "��Ʈ��";
	Larges[2].Middles[1].Smalls[1].SmallCategory = "����ũž";
	Larges[2].Middles[1].Smalls[2].SmallCategory = "����PC";
	Larges[2].Middles[2].Smalls[0].SmallCategory = "ī�޶�";
	Larges[2].Middles[2].Smalls[1].SmallCategory = "����";
	Larges[2].Middles[2].Smalls[2].SmallCategory = "�׼�����";

	ifstream loadProduct("Products.txt"); // Product.txt ���Ͽ��� ������ �ҷ���
	string _Category_Large;
	string _Category_Middle;
	string _Category_Small;
	string _Name;
	string _Seller;
	int _Price;
	int _Stock;
	string _Image;

	while (loadProduct >> _Category_Large >> _Category_Middle >> _Category_Small >> _Name >> _Seller >> _Price >> _Stock >> _Image) // ���� �Է��� ���� �� ���� �����͸� �ҷ���
	{
		Product* temp = new Product();
		Seller* Dummy2;
		temp->setProduct(_Category_Large, _Category_Middle, _Category_Small, _Name, _Seller, _Price, _Stock, _Image); // ���� ������ ����
		for (int i = 0; i < 3; i++) // ��з� ī�װ� ����
		{
			if (Larges[i].LargeCategory == temp->getCategoryLarge())  // ��ġ�� ���
			{
				for (int j = 0; j < 3; j++) // �ߺз� ī�װ� ����
				{
					if (Larges[i].Middles[j].MiddleCategory == temp->getCategoryMiddle()) // ��ġ�� ���
					{
						for (int k = 0; k < 3; k++) // �Һз� ī�װ� ����
						{
							if (Larges[i].Middles[j].Smalls[k].SmallCategory == temp->getCategorySmall()) // ��ġ�� ���
							{
								m_ProductList.Add(temp); // ��ü ���� �迭�� �߰�
								Larges[i].Middles[j].Smalls[k].productList.Add(temp);	 // �Һз� ī�װ� �ȿ� ������	 						
								m_SellerList.ResetList();
								for (int l = 0; l < m_SellerList.GetLength(); l++) // ����Ʈ ���� ��ŭ �ݺ�
								{
									m_SellerList.GetNextItem(Dummy2); 
									if (temp->getSeller() == Dummy2->getCompany())// �Ǹ��ڰ� ����� ������ ���
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
		cout << "��������������������������������������" << endl;
		cout << "1. �� ���\n2. �Ǹ��� ���\n0. ����" << endl;
		cout << "��������������������������������������" << endl;
		int choice; //�޴� ����
		string tempId, tempPw;
		cin >> choice; 
		switch (choice)
		{
		case 1: // �����
			cout << "��������������������������������������" << endl;
			cout << "1. ���� ȸ������ �α���\n2. ȸ�� ����\n0. ���� �޴���" << endl;
			cout << "��������������������������������������" << endl;
			cin >> choice;
			switch (choice) // ���� ȸ������ �α��� �� ���
			{
			case 1:
				cout << "ID : "; cin >> tempId;
				cout << "Password : "; cin >> tempPw;
				customerlogIn(tempId, tempPw); // �� �α��� �Լ� ����
				break;
			case 2: // ����� �߰�
				Add_Customer();
				break;
			case 0: //���� �޴� ȣ��
				getMainCommand();
				break;
			default: // �߸��� �Է� ���� ó��
				cout << "��������������������������������������" << endl;
				cout << "�߸��� �Է��Դϴ�." << endl;
				cout << "��������������������������������������" << endl;
				break;
			}
			break;
		case 2: // �Ǹ��� ���
			cout << "��ȣ�� : "; cin >> tempId;
			cout << "����� ��Ϲ�ȣ : "; cin >> tempPw;
			sellerlogin(tempId,tempPw);	 // �Ǹ��� �α��� �Լ� ����		
			break;
		case 0: // ����
			exit(100);
		default: // �߸��� �Է� ����ó��
			cout << "��������������������������������������" << endl;
			cout << "�߸��� �Է��Դϴ�." << endl;
			cout << "��������������������������������������" << endl;
			break;
		}
	}
	return 0;
}
int Application::getCustomerCommand()
{
	while (1)
	{
		printCustomerInfo();  // ���� �� ������ ������
		cout << "1. ���� �����ϱ�\n2. �̸����� �˻��ϱ�\n3. ���� ����Ʈ Ȯ��\n4. ��ٱ��� Ȯ��\n5. �ֱ� ��ϵ� ��ǰ \n6. ��ǰ ��÷\n7. ȸ������ ����\n8. ȸ�� Ż��\n0. �α׾ƿ�" << endl;
		cout << "��������������������������������������" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: // ī�װ� �����Ͽ� ����
			choiceLargeCategory();
			break;
		case 2: // �̸����� �˻��Ͽ� ����
			SearchProduct();
			break;
		case 3: // ���� ����Ʈ ���
			LoginedCustomer->PrintMyShoppingList();
			break;
		case 4: // ��ٱ��� ���
			printShoppingBasket();
			break; 
		case 5: // �ֱ� ��� ����Ʈ ���
			printRecentlyAdded();
			break;
		case 6: // ��ǰ ��÷
			EventShop();
			break;
		case 7: // �� ���� ����
			Update_Customer();
			break;
		case 8: // �� Ż��
			Delete_Customer();
			break;			
		case 0: // �α׾ƿ�
			customerLogOut();
			getMainCommand();
			break;
		default: // �߸��� �Է� ����ó��
			cout << "��������������������������������������" << endl;
			cout << "�߸��� �Է��Դϴ�." << endl;
			cout << "��������������������������������������" << endl;
			break;
		}
	}
	return 0;	
}
int Application::getSellerCommand()
{
	while (1)
	{
		printSellerInfo(); // ���� �Ǹ��� ���� ���
		cout << "1. ��ǰ ���\n2. ��ǰ ����\n3. ��ǰ ����\n4. ��ǰ �Ǹ� ��Ȳ\n5. ��ǰ �԰�\n6. ��ǰ ���\n0. �α׾ƿ�" << endl;
		cout << "��������������������������������������" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: // ��ǰ ���
			AddProduct();
			break;
		case 2: // ��ǰ ����
			UpdateProduct();
			break;
		case 3: // ��ǰ ����
			DeleteProduct();
			break;
		case 4: // ��ǰ �Ǹ�
			SellProduct();
			break;
		case 5: // ��ǰ �԰�
			StorageProduct();
			break;
		case 6: // ��ǰ ���
			AddEvent();
			break;
		case 0: // �α׾ƿ�
			sellerLogOut();
			getMainCommand();
			break;
		default: // �߸��� �Է� ����ó��
			cout << "��������������������������������������" << endl;
			cout << "�߸��� �Է��Դϴ�." << endl;
			cout << "��������������������������������������" << endl;
			break;
		}
	}
	return 0;
}
void Application::Add_Customer()
{
	Customer *Temp = new Customer(); // �ű� �� ���� ����
	string _Id, _PW, _N;
	cout << "������ �����մϴ�." << endl;
	cout << "���̵�   : "; cin >> _Id;
	cout << "��й�ȣ : "; cin >> _PW;
	cout << "�̸�     : "; cin >> _N;
	Temp->setCustomer(_Id, _PW, _N, 0); // ���� �Է�
	m_CustomerList.Add(Temp); // ����Ʈ�� �߰�
	cout << "����� �Ϸ�Ǿ����ϴ�." << endl;
}

void Application::Delete_Customer()
{
	string tempPW;
	cout << "��������������������������������������" << endl; 
	cout << "���� Ȯ���� ���� ��й�ȣ�� �ٽ� �Է����ּ���." << endl;
	cout << "��������������������������������������" << endl;
	cin >> tempPW;
	if (LoginedCustomer->getPassword() != tempPW) // ��й�ȣ�� ���� ��Ȯ��
	{
		cout << "��������������������������������������" << endl;
		cout << "��� ��ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
		cout << "��������������������������������������" << endl;
		return;
	}
	cout << "��������������������������������������" << endl;
	cout << "���� Ż���Ͻðڽ��ϱ�?" << endl; 
	cout << "1. ��\n2. �ƴϿ�" << endl;
	cout << "��������������������������������������" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1: // 1 ���ý�
		m_CustomerList.Delete(LoginedCustomer); // ȸ�� ����
		cout << "Ż�� �Ϸ�Ǿ����ϴ�." << endl;
		cout << "��������������������������������������" << endl;
		getMainCommand();
		break;
	case 2: // 2 ���ý�
		return;
		break;
	default: //�߸��� �Է� ����ó��
		cout << "��������������������������������������" << endl;
		cout << "�߸��� �Է��Դϴ�." << endl;
		cout << "��������������������������������������" << endl;
		break;
	}
}
void Application::Update_Customer()
{
	string tempPW;
	cout << "��������������������������������������" << endl;
	cout << "���� Ȯ���� ���� ��й�ȣ�� �ٽ� �Է����ּ���." << endl;
	cout << "��������������������������������������" << endl;
	cin >> tempPW;
	if (LoginedCustomer->getPassword() != tempPW) // ��й�ȣ�� ���� ��Ȯ��
	{
		cout << "��������������������������������������" << endl;
		cout << "��� ��ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
		cout << "��������������������������������������" << endl;
		return;
	}
	int choice;
	string temp;
	cout << "��������������������������������������" << endl;
	cout << "������ ������ �������ּ���." << endl;
	cout << "1. �̸�\n2. ��й�ȣ" << endl;
	cout << "��������������������������������������" << endl;
	cin >> choice;
	switch (choice) // ������ ���� ����
	{
	case 1: // 1 ���ý�
		cout << "��������������������������������������" << endl;
		cout << "�� �̸��� �Է����ּ���." << endl;
		cout << "��������������������������������������" << endl;
		cin >> temp;
		LoginedCustomer->setName(temp);
		m_CustomerList.Replace((LoginedCustomer),1,temp); // �̸� ����
		cout << "��������������������������������������" << endl;
		cout << "����Ǿ����ϴ�." << endl;
		cout << "��������������������������������������" << endl;
		break;
	case 2: // 2���ý�
		cout << "��������������������������������������" << endl;
		cout << "�� ��й�ȣ�� �Է����ּ���." << endl;
		cout << "��������������������������������������" << endl;
		cin >> temp;
		LoginedCustomer->setPassword(temp);
		m_CustomerList.Replace((LoginedCustomer), 2, temp); // ��й�ȣ ����
		cout << "��������������������������������������" << endl;
		cout << "����Ǿ����ϴ�." << endl;
		cout << "��������������������������������������" << endl;
		break;
	default: // �߸��� �Է� ����ó��
		cout << "��������������������������������������" << endl;
		cout << "�߸��� �Է��Դϴ�." << endl;
		cout << "��������������������������������������" << endl;
		break;
	}	
}

Customer* Application::customerlogIn(string _Id, string _Password)
{
	Customer Temp; //�ӽ� �� ���� ����
	Temp.setId(_Id); // ���̵� ����
	Temp.setPassword(_Password); // ��й�ȣ ����
	int count = 0;
	Customer *Dummy = new Customer(); // ���� Ž������ ��带 ����Ű�� ���� ����
		
	m_CustomerList.ResetList(); 
	while (count < m_CustomerList.GetLength()) // �� ����Ʈ ���� ��ȯ
	{
		m_CustomerList.GetNextItem(Dummy); 
		if (Dummy->getId() == Temp.getId()) // ��ġ�ϴ� ���̵� ã���� ���
		{
			if (Dummy->getPassword() == Temp.getPassword()) // ���̵�� ��й�ȣ ��� ��ġ�ϴ� ���
				{
					cout << "���������� �α��� �Ͽ����ϴ�." << endl;
					cout << "��������������������������������������" << endl;
					LoginedCustomer = (Dummy); // ���� �α��� �� ���� Dummy�� ����
					getCustomerCommand();
					return LoginedCustomer;
				}
			cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl; // ��й�ȣ�� ��ġ���� �ʴ� ���
			cout << "��������������������������������������" << endl;
			return NULL;

		}
		count++;
	}

	cout << "��ġ�ϴ� ID�� �����ϴ�." << endl; // ��ġ�ϴ� ���̵� ã�� ���� ���
	cout << "��������������������������������������" << endl;
	return NULL;
}

void Application::customerLogOut()
{
	Customer* Dummy = new Customer(); // �ӽ� �� ���� ���� �Ҵ�
	m_CustomerList.ResetList();
	int count = 0;
	while (count < m_CustomerList.GetLength()) // �� ����Ʈ�� Ž��
	{
		m_CustomerList.GetNextItem(Dummy);
		if (Dummy->getId()==LoginedCustomer->getId()) // ��ġ�ϴ� ���̵� ���� ���
		{
			break; // �ݺ��� ����
		}
		count++;
	}
	Dummy = LoginedCustomer; // ��������� ������ ���� ���� ����
	LoginedCustomer = NULL; // �α��ε� ������ NULL��
}

Seller* Application::sellerlogin(string _Id, string _Password)
{
	Seller Temp; // �Ǹ��� ���� ����
	Temp.setCompany(_Id); // ���̵� ����
	Temp.setRegistrationNumber(_Password); // ��й�ȣ ����
	int count = 0;
	Seller* Dummy = new Seller(); // �ӽ� �Ǹ��� ���� ���� �Ҵ�

	m_SellerList.ResetList();
	while (count < m_SellerList.GetLength()) // �Ǹ��� ����Ʈ ��ȯ
	{
		m_SellerList.GetNextItem(Dummy);
		if (Dummy->getCompany() == Temp.getCompany()) // �Ǹ��� ��ȣ�� ��ġ�� ���
		{
			if (Dummy->getRegistrationNumber() == Temp.getRegistrationNumber()) // ��ϵ� ��ȣ ���� ��ġ�ϴ��� Ȯ����
			{
				cout << "���������� �α��� �Ͽ����ϴ�." << endl;
				cout << "��������������������������������������" << endl;
				LoginedSeller = Dummy; // ���� Dummy���� �α��ε� �Ǹ��� ������ ����
				getSellerCommand();
				return LoginedSeller;
			}
			cout << "����� ��� ��ȣ�� ��ġ���� �ʽ��ϴ�." << endl; // ����� ��Ϲ�ȣ�� ��ġ���� ���� ���
			cout << "��������������������������������������" << endl;
			return NULL;
		}
		count++;
	}
	cout << "��ġ�ϴ� ��ȣ�� �����ϴ�." << endl; //�Ǹ��� ��ȣ�� ��ġ���� �ʴ� ���
	cout << "��������������������������������������" << endl;
	return NULL;
}
void Application::sellerLogOut()
{
	LoginedSeller = NULL; // �α��ε� ������ NULL�� 
}

void Application::printCustomerInfo()
{
	cout << "��������������������������������������" << endl;
	cout << "���̵�   :" << setw(10) << LoginedCustomer->getId() << endl; // �α��� �� ������ ���̵� ���
	cout << "�̸�     :" << setw(10) << LoginedCustomer->getName() << endl; //�α��ε� ������ �̸� ���
	cout << "����Ʈ   :" << setw(10) << LoginedCustomer->getPoint(); // ����Ʈ ���
	cout << "\n��������������������������������������" << endl;
}

void Application::printSellerInfo()
{
	cout << "��������������������������������������" << endl;
	cout << "��ȣ     : " << setw(10) << LoginedSeller->getCompany() << endl; // �α��ε� �Ǹ����� ��ȣ ���
	cout << "��Ϲ�ȣ : " << setw(10) << LoginedSeller->getRegistrationNumber() << endl; // �α��ε� �Ǹ����� ����ڵ�Ϲ�ȣ ���
	cout << "�̸�     : " << setw(10) << LoginedSeller->getName() << endl;// �α��ε� �Ǹ����� �̸� ���
	cout << "����ó   : " << setw(10) << LoginedSeller->getPhoneNumber() << endl;// �α��ε� �Ǹ����� ����ó ���
	cout << "�Ǹŵ�� : " << setw(10) << LoginedSeller->getGrade();// �α��ε� �Ǹ����� �Ǹŵ��
	cout << "\n��������������������������������������" << endl;
}

void Application::choiceLargeCategory()
{
	cout << "��������������������������������������" << endl;
	cout << "ī�װ��� ������ �ּ���." << endl;
	cout << "��������������������������������������" << endl;
	int choice;
	for (int i = 0; i < 3; i++) // ��з� ī�װ� ����
	{
		cout << i+1 << ". " << Larges[i].LargeCategory << endl;
	}
	cout << "��������������������������������������" << endl;
	cin >> choice;
	if (choice < 1 || choice>3) // �߸��� �Է� ����ó��
	{
		cout << "��������������������������������������" << endl;
		cout << "�߸��� �Է��Դϴ�." << endl;
		cout << "��������������������������������������" << endl;
		return;
	}
	choice--;
	choiceMiddleCategory(choice); // �ߺз� ī�װ� �������� �̵�
}
void Application::choiceMiddleCategory(int choice)
{
	int choice2;
	cout << "��������������������������������������" << endl;
	for (int i = 0; i < 3; i++) // �ߺз� ī�װ� ����
	{
		cout << i+1 << ". " << Larges[choice].Middles[i].MiddleCategory << endl;
	}
	cout << "��������������������������������������" << endl;
	cin >> choice2;
	if (choice2 < 1 || choice2>3) // �߸��� �Է� ����ó��
	{
		cout << "��������������������������������������" << endl;
		cout << "�߸��� �Է��Դϴ�." << endl;
		cout << "��������������������������������������" << endl;
		return;
	}
	choice2--;
	choiceSmallCategory(choice, choice2); // �Һз� ī�װ� �������� �̵�
}

void Application::choiceSmallCategory(int choice, int choice2)
{
	int choice3;
	cout << "��������������������������������������" << endl;
	for (int i = 0; i < 3; i++)		// �Һз� ī�װ� ����
	{
		cout << i+1 << ". " << Larges[choice].Middles[choice2].Smalls[i].SmallCategory << endl;
	}
	cout << "��������������������������������������" << endl;
	cin >> choice3;
	if (choice3 < 1 || choice3>3) // �߸��� �Է� ����ó��
	{
		cout << "��������������������������������������" << endl;
		cout << "�߸��� �Է��Դϴ�." << endl;
		cout << "��������������������������������������" << endl;
		return;
	}
	choice3--;

	while (1)
	{
		Product *Dummy = new Product(); // �ӽ� ��ǰ ���� ���� �Ҵ�
		Larges[choice].Middles[choice2].Smalls[choice3].productList.ResetList(); // ������ ī�װ��� ��ǰ ����Ʈ
		cout << "��������������������������������������" << endl;
		cout << " ��ǰ��        ����   ��� " << endl;
		cout << "��������������������������������������" << endl;
		for (int j = 0; j < Larges[choice].Middles[choice2].Smalls[choice3].productList.GetLength(); j++) // ����Ʈ ���̸�ŭ �ݺ�
		{
			Larges[choice].Middles[choice2].Smalls[choice3].productList.GetNextItem(Dummy);  //������ ��ȣ�� ������ �ҷ����� ���� GetNextItem ����
			cout << j+1; Dummy->printProductDisplay(); // ���� ���
		}
		
		if (Larges[choice].Middles[choice2].Smalls[choice3].productList.GetLength() == 0) // ���� ��ǰ�� �������� ���� ��� ���� ó��
		{
			cout << "��ǰ�� �������� �ʽ��ϴ�." << endl;
			cout << "��������������������������������������" << endl;
			getCustomerCommand();
		}

		int command; 
		cout << "��������������������������������������" << endl;
		cout << "��ǰ ��ȣ�� �����Ͽ� ������ Ȯ���մϴ�.\n0 �Է� �� ���� �޴��� ���ư��ϴ�. " << endl;
		cout << "��������������������������������������" << endl;
		cin >> command;
		if (command == 0) // 0 �Է½� �޴� ȣ��
		{
			getCustomerCommand();
			break;
		}

		Larges[choice].Middles[choice2].Smalls[choice3].productList.ResetList(); // ������ ī�װ��� ��ǰ ����Ʈ
		for (int k = 0; k < command; k++)
		{
			Larges[choice].Middles[choice2].Smalls[choice3].productList.GetNextItem(Dummy); // ������ ��ȣ�� ������ �ҷ����� ���� GetNextItem ����
		}
		Dummy->printProductInfo(); // ���� ������ ��ǰ�� ���� ���
		cout << "��������������������������������������" << endl;
		Buy(*Dummy); // ���� �Լ� ����
	}
}

int Application::Buy(Product& Dummy)
{
	int choice;
	cout << "1. ��� �����ϱ�" << endl;
	cout << "2. ��ٱ��Ͽ� ���" << endl;
	cout << "3. ���� �޴���" << endl;
	cout << "��������������������������������������" << endl;
	cin >> choice;
	Seller *New; // �ӽ� �Ǹ��� ������ ����
	switch (choice)
	{
	case 1: // ���� ��� �����ϱ�
		if (Dummy.getStock() <= 0) // ���� ������ ������ ��� 0�� ��� ���� ó��
		{
			cout << "��� ������ �ǸŵǾ����ϴ�." << endl;
			break;
		}
		LoginedCustomer->setMyShoppingList(&Dummy); // �α��� �� ������ ���� ����Ʈ�� �߰�
		
		LoginedCustomer->setPoint(LoginedCustomer->getPoint() + Dummy.getPrice() / 10);
		New = new Seller(); // �ӽ� �Ǹ��� ���� ����
		m_SellerList.ResetList();
		for (int i = 0; i < m_SellerList.GetLength(); i++)  // �Ǹ��� ����Ʈ��ŭ �ݺ�
		{
			m_SellerList.GetNextItem(New);
			if (Dummy.getSeller() == New->getCompany()) // ������ ��ȣ�� ���� �Ǹ��� �߰� ��
			{
				New->setTotalCost(Dummy.getPrice()); // �Ǹ����� �Ǹ� �ݾ� �߰�
				break;
			}
		}
		break;
	case 2: // ���� ��ٱ��Ͽ� ���
		LoginedCustomer->setShoppingBasket(Dummy);
		cout << "��ٱ��Ͽ� �����ϴ�." << endl;
		break;
	case 3: // �޴� ���
		getCustomerCommand();
		break;
	default: // �߸��� �Է� ���� ó��
		cout << "��������������������������������������" << endl;
		cout << "�߸��� �Է��Դϴ�." << endl;
		cout << "��������������������������������������" << endl;
		break;
	}
	return 0;
}

int Application::SearchProduct()
{
	string name;
	Product* temp = new Product(); // �ӽ� ���� ���� ����
	Product* Dummy; // ���� ����
	cout << "��������������������������������������" << endl;
	cout << "ã���ô� ���� �̸��� �Է��ϼ���." << endl;
	cout << "��������������������������������������" << endl;
	cin >> name;
	temp->setName(name);
	for (int i = 0; i < 3; i++) // ��з� ī�װ�
	{
		for (int j = 0; j < 3; j++) // �ߺз� ī�װ�
		{
			for (int k = 0; k < 3; k++) // �Һз� ī�װ�
			{
				Larges[i].Middles[j].Smalls[k].productList.ResetList(); // ����Ʈ ������ �ʱ�ȭ
				for (int l = 0; l < Larges[i].Middles[j].Smalls[k].productList.GetLength(); l++) // ����Ʈ ���̸�ŭ �ݺ�
				{
					Larges[i].Middles[j].Smalls[k].productList.GetNextItem(Dummy); // ���� ����Ʈ�� ����Ŵ
					if (Dummy->getName() == temp->getName()) // ã���� �ϴ�  �̸��� ��ġ�� ���
					{
						cout << "��������������������������������������" << endl;
						Dummy->printProductInfo(); // ���� ���� ���
						Buy(*Dummy); // ���� �Լ� ���
						return 1;
						break;
					}
				}
			}
		}
	}
	cout << "��������������������������������������" << endl;
	cout << "ã���ô� ������ �����ϴ�." << endl;
	cout << "��������������������������������������" << endl;
	return 0;
}

int Application::AddProduct()
{
	cout << "��������������������������������������" << endl;
	cout << "��ǰ ����� ���� ������ �Է��մϴ�." << endl;
	cout << "��ǰ ī�װ��� ������ �ּ���." << endl;
	cout << "��������������������������������������" << endl;
	int choice;
	for (int i = 0; i < 3; i++) // ��з� ī�װ� �߰�
	{
		cout << i + 1 << ". " << Larges[i].LargeCategory << endl;
	}
	cout << "��������������������������������������" << endl;
	cin >> choice;
	if (choice < 1 || choice>3) //�߸��� �Է� �� ���� ó��
	{
		cout << "��������������������������������������" << endl;
		cout << "�߸��� �Է��Դϴ�." << endl;
		cout << "��������������������������������������" << endl;
		return 0;
	}
	choice--;
	int choice2;
	cout << "��������������������������������������" << endl;
	for (int i = 0; i < 3; i++) // �ߺз� ī�װ� �߰�
	{
		cout << i + 1 << ". " << Larges[choice].Middles[i].MiddleCategory << endl;
	}
	cout << "��������������������������������������" << endl;
	cin >> choice2;
	if (choice2 < 1 || choice2>3) // �߸��� �Է½� ���� ó��
	{
		cout << "��������������������������������������" << endl;
		cout << "�߸��� �Է��Դϴ�." << endl;
		cout << "��������������������������������������" << endl;
		return 0;
	}
	choice2--;
	int choice3;
	cout << "��������������������������������������" << endl;
	for (int i = 0; i < 3; i++) // �Һз� ī�װ� �߰�
	{
		cout << i + 1 << ". " << Larges[choice].Middles[choice2].Smalls[i].SmallCategory << endl;
	}
	cout << "��������������������������������������" << endl;
	cin >> choice3;
	if (choice3 < 1 || choice3>3) // �߸��� �Է� �� ���� ó��
	{
		cout << "��������������������������������������" << endl;
		cout << "�߸��� �Է��Դϴ�." << endl;
		cout << "��������������������������������������" << endl;
		return 0;
	}
	choice3--;

	Product* New = new Product(); // ���� �߰��� ��ǰ ���� �߰�
	string _Name; 
	int _Price;
	int _Stock;
	string _Image;
	cout << "��������������������������������������" << endl;
	cout << "��ǰ��      : "; cin >> _Name; //��ǰ�� �߰�
	cout << "��ǰ ����   : "; cin >> _Price;//��ǰ ���� �߰�
	cout << "��ǰ ���   : "; cin >> _Stock;//��ǰ ��� �߰�
	cout << "��ǰ �̹��� : "; cin >> _Image;//�̹��� �߰�
	New->setProduct(Larges[choice].LargeCategory, Larges[choice].Middles[choice2].MiddleCategory, 
		Larges[choice].Middles[choice2].Smalls[choice3].SmallCategory,_Name,LoginedSeller->getCompany(),
		_Price,_Stock,_Image); // �Է¹��� ������ �������� ��ǰ ����
	Larges[choice].Middles[choice2].Smalls[choice3].productList.Add(New); // ��ǰ ����Ʈ�� �߰�
	m_ProductList.Add(New);
	LoginedSeller->setSellerProducts(New); //�α��ε� �Ǹ����� �Ǹ����� ���ǿ� �߰�
	cout << "��������������������������������������" << endl;
	cout << "��ǰ�� �߰��Ǿ����ϴ�." << endl;
	cout << "��������������������������������������" << endl;
	return 0;
}

int Application::UpdateProduct()
{
	string name;
	Product* temp = new Product(); // �ӽ� ��ǰ ���� ���� �Ҵ�
	Product* Dummy;
	cout << "��������������������������������������" << endl;
	cout << "�����Ͻ� ���� �̸��� �Է��ϼ���." << endl;
	cout << "��������������������������������������" << endl;
	LoginedSeller->printProductList(); // ���� �Ǹ����� ���� ����Ʈ ���
	cout << "��������������������������������������" << endl;
	cin >> name;
	temp->setName(name);
	for (int i = 0; i < 3; i++) // ��з� ī�װ�
	{
		for (int j = 0; j < 3; j++) // �ߺз� ī�װ�
		{
			for (int k = 0; k < 3; k++) // �Һз� ī�װ�
			{
				Larges[i].Middles[j].Smalls[k].productList.ResetList();
				for (int l = 0; l < Larges[i].Middles[j].Smalls[k].productList.GetLength(); l++) // ����Ʈ ���̸�ŭ �ݺ�
				{
					Larges[i].Middles[j].Smalls[k].productList.GetNextItem(Dummy); // ���� ����Ʈ�� ����Ŵ
					if (Dummy->getName() == temp->getName()) // ��ġ�ϴ� ���� �߰� ��
					{
						if (Dummy->getSeller() != LoginedSeller->getCompany()) // �Ǹ��ϴ� ȸ���� ��ǰ�� �ƴ� ���
						{
							cout << "�α��� �� ȸ���� ��ǰ�� �ƴմϴ�." << endl;
							cout << "��������������������������������������" << endl;
							return 0;
						}
						cout << "��������������������������������������" << endl;
						string _Name;
						string _Image;
						int _Price;
						Dummy->printProductInfo(); // ���� ���� ���
						cout << "��������������������������������������" << endl;
						cout << "� ������ �����Ͻðڽ��ϱ�?" << endl;
						cout << "��������������������������������������" << endl;
						cout << "1. ��ǰ��" << endl;
						cout << "2. ��ǰ ����" << endl;
						cout << "3. ��ǰ �̹���" << endl;
						cout << "��������������������������������������" << endl;
						int choice4;
						cin >> choice4;
						cout << "��������������������������������������" << endl;
						cout << "������ ������ �Է��ϼ���." << endl;
						cout << "��������������������������������������" << endl;

						switch (choice4)
						{
						case 1: // �̸� ����
							cin >> _Name;
							Larges[i].Middles[j].Smalls[k].productList.Update(Dummy, 1, _Name);
							break;
						case 2: // ���� ����
							cin >> _Price;
							Larges[i].Middles[j].Smalls[k].productList.Update(Dummy, 2, _Price);
							break;
						case 3: // �̹��� ����
							cin >> _Image;
							Larges[i].Middles[j].Smalls[k].productList.Update(Dummy, 3, _Name);
							break;
						default: // �߸��� �Է� �� ���� ó��
							cout << "��������������������������������������" << endl;
							cout << "�߸��� �Է��Դϴ�." << endl;
							cout << "��������������������������������������" << endl;
							break;
						} 
						cout << "��������������������������������������" << endl;
						cout << "���������� �Ϸ�Ǿ����ϴ�." << endl;
						cout << "��������������������������������������" << endl;
						return 1;
						break;
					}
				}
			}
		}
	}
	cout << "��ǰ ������ �����Ͽ����ϴ�." << endl; // ī�װ����� �߰� ���� ��
	cout << "��������������������������������������" << endl;
	return 0; 
	
}
int Application::DeleteProduct()
{
	string name;
	Product* temp = new Product(); // �ӽ� ��ǰ ���� ���� �Ҵ�
	Product* Dummy;
	cout << "��������������������������������������" << endl;
	cout << "�����Ͻ� ���� �̸��� �Է��ϼ���." << endl;
	cout << "��������������������������������������" << endl;
	LoginedSeller->printProductList(); // �Ǹ����� ���� ����Ʈ ���
	cout << "��������������������������������������" << endl;
	cin >> name;
	temp->setName(name);
	for (int i = 0; i < 3; i++) // ��з� ī�װ�
	{
		for (int j = 0; j < 3; j++) // �ߺз� ī�װ�
		{
			for (int k = 0; k < 3; k++) // �Һз� ī�װ�
			{
				Larges[i].Middles[j].Smalls[k].productList.ResetList();
				for (int l = 0; l < Larges[i].Middles[j].Smalls[k].productList.GetLength(); l++) // ����Ʈ ���̸�ŭ �ݺ�
				{
					Larges[i].Middles[j].Smalls[k].productList.GetNextItem(Dummy); // ���� ����Ʈ�� ����Ŵ
					if (Dummy->getName() == temp->getName()) // �̸��� ��ġ�� ���
					{
						if (Dummy->getSeller() != LoginedSeller->getCompany())//�α����� ȸ���� ��ǰ�� �ƴ� ���
						{
							cout << "�α��� �� ȸ���� ��ǰ�� �ƴմϴ�." << endl;
							cout << "��������������������������������������" << endl;
							return 0;
						}
						Larges[i].Middles[j].Smalls[k].productList.Delete(Dummy); // ��ǰ ����
						m_ProductList.Delete(Dummy);
						cout << "��������������������������������������" << endl;
						cout << "���������� �Ϸ�Ǿ����ϴ�." << endl;
						cout << "��������������������������������������" << endl;
						return 1;
						break;
					}
				}
			}
		}
	} 
	cout << "��������������������������������������" << endl; // �߰� ���� ��
	cout << "��ǰ ������ �����Ͽ����ϴ�." << endl;
	cout << "��������������������������������������" << endl;

	return 0;
}
int Application::SellProduct()
{
	cout << "��������������������������������������" << endl;
	cout << "���� �Ǹ����� ��ǰ ����Ʈ" << endl;
	cout << "��������������������������������������" << endl;
	LoginedSeller->printProductList(); // ���� �Ǹ����� ��ǰ ����Ʈ ���
	cout << "��������������������������������������" << endl;
	cout << "�� �Ǹű� : " << LoginedSeller->getTotalCost() << endl; // ������� �Ǹŵ� �ݾ��� ���
	cout << "��������������������������������������" << endl;
	return 1;
}
int Application::StorageProduct()
{
	string name;
	Product* temp = new Product(); // �ӽ� ��ǰ ���� ���� �Ҵ�
	Product* Dummy; 
	cout << "��������������������������������������" << endl;
	cout << "��� �߰��� ���� �̸��� �Է��ϼ���." << endl;
	cout << "��������������������������������������" << endl;
	LoginedSeller->printProductList(); // ���� �Ǹ����� ��ǰ ����Ʈ ���
	cout << "��������������������������������������" << endl;
	cin >> name;
	temp->setName(name);
	for (int i = 0; i < 3; i++) // ��з� ī�װ�
	{
		for (int j = 0; j < 3; j++) // �ߺз� ī�װ�
		{
			for (int k = 0; k < 3; k++) // �Һз� ī�װ�
			{
				Larges[i].Middles[j].Smalls[k].productList.ResetList(); // ����Ʈ ������ �ʱ�ȭ
				for (int l = 0; l < Larges[i].Middles[j].Smalls[k].productList.GetLength(); l++) // ����Ʈ ���̸�ŭ �ݺ�
				{
					Larges[i].Middles[j].Smalls[k].productList.GetNextItem(Dummy); // ���� ����Ʈ�� ����Ŵ
					if (Dummy->getName() == temp->getName())
					{
						if (Dummy->getSeller() != LoginedSeller->getCompany()) // �α��ε� ȸ���� ��ǰ�� �ƴ� ���
						{
							cout << "�α��� �� ȸ���� ��ǰ�� �ƴմϴ�." << endl;
							cout << "��������������������������������������" << endl;
							return 0;
						}
						cout << "��������������������������������������" << endl;
						Dummy->printProductInfo(); // ���� ����Ű�� ������ ���� ���
						cout << "��������������������������������������" << endl;
						cout << "�߰��� ������ �Է��� �ּ���." << endl;
						cout << "��������������������������������������" << endl;
						int choice4;
						cin >> choice4;
						if (choice4 <= 0) // �߰��ϰ��� �ϴ� ������ 0���� ���ų� ���� ���
						{
							cout << "��������������������������������������" << endl;
							cout << "�߸��� �Է��Դϴ�." << endl;
							cout << "��������������������������������������" << endl;
							return 0;
						}
						Larges[i].Middles[j].Smalls[k].productList.Update(Dummy, 4, choice4); // ��� �߰�
						cout << "��������������������������������������" << endl;
						cout << "���������� �Ϸ�Ǿ����ϴ�." << endl;
						cout << "��������������������������������������" << endl;
						return 1;
						break;
					}
				}
			}
		}
	}
	cout << "��ǰ ������ �����Ͽ����ϴ�." << endl; // ��ǰ�� �߰����� ������ ��
	cout << "��������������������������������������" << endl;
	return 0;
}


void Application::printShoppingBasket()
{
	Product* Temp = new Product(); // �ӽ� ��ǰ ���� ���� �Ҵ�
	Product* Real;
	cout << "��������������������������������������" << endl;
	LoginedCustomer->printShoppingBasket(); // ���� �α��� �� ���� ��ٱ��� ���
	int command;
	cout << "��������������������������������������" << endl;
	cout << "��ǰ ��ȣ�� �����Ͽ� ������ Ȯ���մϴ�.\n0 �Է� �� ���� �޴��� ���ư��ϴ�. " << endl;
	cout << "��������������������������������������" << endl;
	cin >> command;
	if (command == 0) // 0 �Է½� ���� �Լ� ����
	{
		return;
	}
	Temp = LoginedCustomer->PassDummy(command); //������ ��ȣ�� ��ǰ ���� ���

	for (int i = 0; i < 3; i++) // ��з� ī�װ�
	{
		for (int j = 0; j < 3; j++) // �ߺз� ī�װ�
		{
			for (int k = 0; k < 3; k++) // �Һз� ī�װ�
			{
				Larges[i].Middles[j].Smalls[k].productList.ResetList(); // ����Ʈ ������ �ʱ�ȭ
				for (int l = 0; l < Larges[i].Middles[j].Smalls[k].productList.GetLength(); l++) // ����Ʈ ���̸�ŭ �ݺ�
				{
					Larges[i].Middles[j].Smalls[k].productList.GetNextItem(Real); // ���� �������� ����Ŵ
					if (Real->getName() == Temp->getName()) // ��ٱ��� ���� ��ǰ �̸��� ����Ʈ �� ��ǰ�� �̸��� ���� ���
					{
						BuyinBasket(*Real); // ����Ʈ �� ��ǰ�� ����
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
	cout << "1. ��� �����ϱ�" << endl;
	cout << "2. ���� �޴���" << endl;
	cout << "��������������������������������������" << endl;
	cin >> choice;
	Product* Temp = new Product; // �ӽ� ��ǰ ���� ���� �Ҵ�
	Seller *New;
	switch (choice)
	{
	case 1: // ��� �����ϱ�
		if (Dummy.getStock() <= 0) // Dummy�� ��� 0���� �۰ų� ���� ��� ���� ó��
		{
			cout << "��� ������ �ǸŵǾ����ϴ�." << endl;
			break;
		}
		LoginedCustomer->setMyShoppingList(&Dummy); // �α����� ������� ���� ����Ʈ�� �߰�
		New = new Seller();
		m_SellerList.ResetList();
		for (int i = 0; i < m_SellerList.GetLength(); i++) // �Ǹ��� ����Ʈ ���̸�ŭ �ݺ�
		{
			m_SellerList.GetNextItem(New);
			if (Dummy.getSeller() == New->getCompany()) // Dummy�� �Ǹ��ڰ� Seller�� ��ȣ�� ��ġ�� ��
			{
				New->setTotalCost(Dummy.getPrice()); //�Ǹ����� �Ǹ� �ݾ� �߰�
				break;
			}
		}
		break;
	case 2: // �޴� ȣ��
		getCustomerCommand();
		break;
	default: // �߸��� �Է� ���� ó��
		cout << "��������������������������������������" << endl;
		cout << "�߸��� �Է��Դϴ�." << endl;
		cout << "��������������������������������������" << endl;
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
	cout << "��������������������������������������" << endl;
	cout << "��ǰ ��ȣ�� �����Ͽ� ������ Ȯ���մϴ�.\n0 �Է� �� ���� �޴��� ���ư��ϴ�. " << endl;
	cout << "��������������������������������������" << endl;
	cin >> command;
	if (command == 0) // 0 �Է½� �޴� ȣ��
	{
		getCustomerCommand();
		return;
	}
	Dummy = m_ProductList.at(size - 6 + command);
	Dummy->printProductInfo(); // ���� ������ ��ǰ�� ���� ���
	cout << "��������������������������������������" << endl;
	Buy(*Dummy);
}

void Application::EventShop()
{
	Product *Dummy = new Product();
	cout << "��������������������������������������" << endl;
	cout << "���� ����Ʈ : " << LoginedCustomer->getPoint() << endl;
	cout << "��������������������������������������" << endl;
	cout << "�������� �̺�Ʈ " << endl;
	if (m_EventList.GetLength() == 0)
	{
		cout << "�������� �̺�Ʈ�� �����ϴ�." << endl;
		cout << "��������������������������������������" << endl;
		return;
	}
	for (int i = 0; i < m_EventList.GetLength(); i++)
	{
		cout << i + 1 << ". " << m_EventList.at(i)->getName() << "��÷ �̺�Ʈ" << endl;
	}
	int command; cin >> command;
	cout << "��������������������������������������" << endl;
	cout << m_EventList.at(--command)->getName() << " ��÷ �̺�Ʈ �Դϴ�." << endl;
	cout << "��ǰ��      : "; cout << m_EventList.at(command)->getName() << endl;
	cout << "���� ���� ��: "; cout << m_EventList.at(command)->getStock() << endl;
	cout << "�� ���� �ο�: "; cout << m_EventList.at(command)->getPrice() << endl;
	cout << "��ǰ �̹��� : "; cout << m_EventList.at(command)->getImage() << endl;	
	cout << "��������������������������������������" << endl;
	cout << "�����Ͻðڽ��ϱ�? \n1. �� \n2. �ƴϿ�" << endl;
	int choice; cin >> choice;
	if (choice == 1)
	{
		if (LoginedCustomer->getPoint() < 100) // ����Ʈ ���ڶ�
		{
			cout << "����Ʈ�� �����մϴ�." << endl;
			cout << "��������������������������������������" << endl;
			return;
		}
		LoginedCustomer->setPoint(LoginedCustomer->getPoint() - 100); // ����Ʈ ����
		m_EventList.at(command)->setPrice(m_EventList.at(command)->getPrice() + 1);
		cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
		cout << "��������������������������������������" << endl;
		if (m_EventList.at(command)->getPrice() == m_EventList.at(command)->getStock())
		{
			srand((unsigned)time(NULL));
			cout << rand() % m_EventList.at(command)->getPrice() << "�� ° �����ڰ� ��÷�Ǿ����ϴ�." << endl;
			cout << "��������������������������������������" << endl;
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
	cout << "��������������������������������������" << endl;
	cout << "��ǰ�� ����մϴ�." << endl;
	cout << "��ǰ ī�װ��� ������ �ּ���." << endl;
	cout << "��������������������������������������" << endl;
	int choice;
	for (int i = 0; i < 3; i++) // ��з� ī�װ� �߰�
	{
		cout << i + 1 << ". " << Larges[i].LargeCategory << endl;
	}
	cout << "��������������������������������������" << endl;
	cin >> choice;
	if (choice < 1 || choice>3) //�߸��� �Է� �� ���� ó��
	{
		cout << "��������������������������������������" << endl;
		cout << "�߸��� �Է��Դϴ�." << endl;
		cout << "��������������������������������������" << endl;
		return;
	}
	choice--;
	int choice2;
	cout << "��������������������������������������" << endl;
	for (int i = 0; i < 3; i++) // �ߺз� ī�װ� �߰�
	{
		cout << i + 1 << ". " << Larges[choice].Middles[i].MiddleCategory << endl;
	}
	cout << "��������������������������������������" << endl;
	cin >> choice2;
	if (choice2 < 1 || choice2>3) // �߸��� �Է½� ���� ó��
	{
		cout << "��������������������������������������" << endl;
		cout << "�߸��� �Է��Դϴ�." << endl;
		cout << "��������������������������������������" << endl;
		return;
	}
	choice2--;
	int choice3;
	cout << "��������������������������������������" << endl;
	for (int i = 0; i < 3; i++) // �Һз� ī�װ� �߰�
	{
		cout << i + 1 << ". " << Larges[choice].Middles[choice2].Smalls[i].SmallCategory << endl;
	}
	cout << "��������������������������������������" << endl;
	cin >> choice3;
	if (choice3 < 1 || choice3>3) // �߸��� �Է� �� ���� ó��
	{
		cout << "��������������������������������������" << endl;
		cout << "�߸��� �Է��Դϴ�." << endl;
		cout << "��������������������������������������" << endl;
		return;
	}
	choice3--;
	Product* New = new Product(); // ���� �߰��� ��ǰ ���� �߰�
	string _Name;
	int _Stock;
	string _Image;
	cout << "��������������������������������������" << endl;
	cout << "��ǰ��      : "; cin >> _Name;		//��ǰ�� �߰�
												//��ǰ ������ ���� �̺�Ʈ�� �������� �ο����� ���
	cout << "���� �ο�   : "; cin >> _Stock;	//��� ���� ������ �ִ� �ο����� �����
	cout << "��ǰ �̹��� : "; cin >> _Image;	//�̹��� �߰�
	New->setProduct(Larges[choice].LargeCategory, Larges[choice].Middles[choice2].MiddleCategory,
		Larges[choice].Middles[choice2].Smalls[choice3].SmallCategory, _Name, LoginedSeller->getCompany(),
		0, _Stock, _Image); // �Է¹��� ������ �������� ��ǰ ����
	m_EventList.Add(New); // �̺�Ʈ ����Ʈ�� �߰�
	cout << "��������������������������������������" << endl;
	cout << "��ǰ�� �߰��Ǿ����ϴ�." << endl;
	cout << "��������������������������������������" << endl;
	return;
}

