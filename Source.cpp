#include <iostream>
using namespace std;

struct lelement
{
	int data;
	lelement* next;
};

int main()
{
	setlocale(LC_ALL, "Russian");

	lelement* head = NULL;
	lelement* t = head;

	while (true)
	{
		int vcase, tempdata;
		lelement* p = NULL;
		cout << "1)�������� ������������ ������\n2)���������� ������ �������� � ������\n3)�������� �������� �� ������\n4)����� �� ����� ���� ��������� ������\n5)��������� ������ �� �������" << endl;
		cin >> vcase;
		
		if (vcase == 1)
		{
			if (head != NULL)
			{
				cout << "������ ��� ��� ������. �������������� �������� ���������� ��������." << endl;
			}
			else
			{
				cout << "����������, ������� �������� ��� �������� ������: " << endl;
				p = (lelement*)malloc(sizeof(lelement));
				cin >> tempdata;
				p->data = tempdata;
				p->next = NULL;
				head = p;
				//���� ���� ����� ��� �������� ������:
				while (true)
				{
					cin >> tempdata;
					if (!tempdata)
						break;
					p = (lelement*)malloc(sizeof(lelement));
					p->data = tempdata;
					//������������ ������ �������� � ������ ������ ��� ����������� ������ ������������ ��������
					if (p->data < head->data)
					{
						p->next = head;
						head = p;
					}
					//�������� �� ��������� ��������� �����������
					else if (p->data == head->data)
					{
						cout << "�������� ��� ������������ � ������." << endl;
					}
					else
					{
						//����� ����� ��� ������ �������� ������:
						bool is_duplicate = false;
						t = head;
						while (t->next != NULL && t->next->data <= p->data)
						{
							if (t->next->data == p->data)
							{
								cout << "�������� ��� ������������ � ������." << endl;
								is_duplicate = true;
								break;
							}
							t = t->next;
						}
						if (!is_duplicate)
						{
							p->next = t->next;
							t->next = p;
						}
					}
				}
			}
		}
		else if (vcase == 2)
		{
			cout << "����������, ������� ������� ��� ���������� � ������: ";
			cin >> tempdata;
			p = (lelement*)malloc(sizeof(lelement));
			p->data = tempdata;
			if (head == NULL)
			{
				head = p;
				p->next = NULL;
			}
			else
			{
				//������������ ������ �������� � ������ ������ ��� ����������� ������ ������������ ��������
				if (p->data < head->data)
				{
					p->next = head;
					head = p;
				}
				//�������� �� ��������� ��������� �����������
				else if (p->data == head->data)
				{
					cout << "�������� ��� ������������ � ������." << endl;
				}
				else
				{
					//����� ����� ��� ������ �������� ������:
					bool is_duplicate = false;
					t = head;
					while (t->next->data <= p->data)
					{
						if (t->next->data == p->data)
						{
							cout << "�������� ��� ������������ � ������." << endl;
							is_duplicate = true;
							break;
						}
						t = t->next;
						if (t->next == NULL)//���� �������� ����� �� ������ ����� ������ (��-�� ���� ��� ����������� �������� ������ ���� ��������� � ������), �� .next ���������� �������� �������� �� ������ �� ����������� �������
						{					//� ����������  is_duplicate �������� �� true
							t->next = p;
							p->next = NULL;
							is_duplicate = true;
							break;
						}
					}
					if (!is_duplicate)
					{
						p->next = t->next;
						t->next = p;
					}
				}
			}
		}
		else if (vcase == 3)
		{
			if (head == NULL)
			{
				cout<<"������ ����."<<endl;
			}
			else
			{
				cout << "�������� �������� �� ������. ����������, ������� �������� ��� ��������: ";
				cin >> tempdata;
				if (head->data == tempdata) //���� ����� ������� ������ ������
				{
					t = head->next;
					free(head);
					head = t;
				}
				else
				{
					bool is_in_list = true;
					t = head;
					if (t->next == NULL)
					{
						cout << "������� ��� �������� �����������." << endl;
						is_in_list = false;
						break;
					}
					while (t->next->data != tempdata)
					{
						t = t->next;
						if (t->next == NULL)
						{
							cout << "������� ��� �������� �����������." << endl;
							is_in_list = false;
							break;
						}
					}
					if (is_in_list)
					{
						p = t->next->next;
						free(t->next);
						t->next = p;
					}
				}
			}
		}
		else if (vcase == 4)
		{
			if (head == NULL)
			{
				cout << "������ ����." << endl;
			}
			else
			{
				cout << "����� ������ �� �����." << endl;
				p = head;
				cout << p->data;
				while (p->next != NULL)
				{
					p = p->next;
					cout << " " << p->data;
				}
				cout << ".\n\t����� ��������." << endl;
			}
		}
		else if (vcase == 5)
		{
			cout << "������ �� �������� ���������." << endl;
			break;
		}
		else
		{
			cout << "����������, ��������� ���� ��������." << endl;
		}
	}

	//������������ ������
	if (head != NULL)
	{
		if (head->next == NULL)
		{
			free(head);
		}
		else
		{
			t = head;
			lelement* tnext = t->next;
			free(t);
			while (tnext->next != NULL)
			{
				t = tnext;
				tnext = tnext->next;
				free(t);
			}
			free(tnext);
		}
	}

	system("pause");
	return 0;
}