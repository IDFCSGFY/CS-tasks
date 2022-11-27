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
		cout << "1)создание односвязного списка\n2)добавление одного элемента в список\n3)удаление элемента из списка\n4)вывод на экран всех элементов списка\n5)закончить работу со списком" << endl;
		cin >> vcase;
		
		if (vcase == 1)
		{
			if (head != NULL)
			{
				cout << "Список уже был создан. Воспользуйтесь функцией добавления элемента." << endl;
			}
			else
			{
				cout << "Пожалуйста, введите элементы для создания списка: " << endl;
				p = (lelement*)malloc(sizeof(lelement));
				cin >> tempdata;
				p->data = tempdata;
				p->next = NULL;
				head = p;
				//ввод всех чисел при создании списка:
				while (true)
				{
					cin >> tempdata;
					if (!tempdata)
						break;
					p = (lelement*)malloc(sizeof(lelement));
					p->data = tempdata;
					//расположение нового элемента в начале списка при обнаружении нового минимального значения
					if (p->data < head->data)
					{
						p->next = head;
						head = p;
					}
					//проверка на равенство нынешнему наименьшему
					else if (p->data == head->data)
					{
						cout << "Значение уже присутствует в списке." << endl;
					}
					else
					{
						//поиск места для нового элемента списка:
						bool is_duplicate = false;
						t = head;
						while (t->next != NULL && t->next->data <= p->data)
						{
							if (t->next->data == p->data)
							{
								cout << "Значение уже присутствует в списке." << endl;
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
			cout << "Пожалуйста, введите элемент для добавления в список: ";
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
				//расположение нового элемента в начале списка при обнаружении нового минимального значения
				if (p->data < head->data)
				{
					p->next = head;
					head = p;
				}
				//проверка на равенство нынешнему наименьшему
				else if (p->data == head->data)
				{
					cout << "Значение уже присутствует в списке." << endl;
				}
				else
				{
					//поиск места для нового элемента списка:
					bool is_duplicate = false;
					t = head;
					while (t->next->data <= p->data)
					{
						if (t->next->data == p->data)
						{
							cout << "Значение уже присутствует в списке." << endl;
							is_duplicate = true;
							break;
						}
						t = t->next;
						if (t->next == NULL)//если проверка дошла до самого конца списка (из-за того что добавляемое значение больше всех остальных в списке), то .next последнего элемента меняется на ссылку на добавляемый элемент
						{					//и переменная  is_duplicate ставится на true
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
				cout<<"Список пуст."<<endl;
			}
			else
			{
				cout << "Удаление элемента из списка. Пожалуйста, впишите значение для удаления: ";
				cin >> tempdata;
				if (head->data == tempdata) //если нужно удалить голову списка
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
						cout << "Элемент для удаления отсутствует." << endl;
						is_in_list = false;
						break;
					}
					while (t->next->data != tempdata)
					{
						t = t->next;
						if (t->next == NULL)
						{
							cout << "Элемент для удаления отсутствует." << endl;
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
				cout << "Список пуст." << endl;
			}
			else
			{
				cout << "Вывод списка на экран." << endl;
				p = head;
				cout << p->data;
				while (p->next != NULL)
				{
					p = p->next;
					cout << " " << p->data;
				}
				cout << ".\n\tВывод завершён." << endl;
			}
		}
		else if (vcase == 5)
		{
			cout << "Работа со списками завершена." << endl;
			break;
		}
		else
		{
			cout << "Пожалуйста, повторите ввод варианта." << endl;
		}
	}

	//освобождение памяти
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