#include <iostream>

using namespace std;

void filler(int** mass, int iter, int jter)
{
	cout << "\n������������ �������, ����������� ���������� �������:\n";
	for (int i = 0; i < iter; i++)
	{
		for (int j = 0; j < jter; j++)
		{
			mass[i][j] = rand();
			//�������� �� ��, ������� �� ��������� ������� � ������� ����������� ��������������
			/*if (j == 0||j==3||j==8||j==9)
			{
				mass[i][j] = 1;
			}*/
			cout << mass[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}

void organiser(int** mass, int iter, int* jter, int* order)
{
	cout << "���������� ����� � �������, ����� ��������� ������� ������ ���:\n";
	int* element_counter = new int[*jter];
	for (int j = 0; j < *jter; j++)
	{
		element_counter[j] = 0;
		for (int i = 0; i < iter; i++)
		{
			int sum = 0;
			for (int l = 1; l <= mass[i][j]; l++)
			{
				if (mass[i][j] % l == 0)
				{
					sum += l;
				}
			}
			if (sum % 3 == 0)
			{
				element_counter[j]++;
			}
		}
		cout << element_counter[j] << "\t";
	}
	cout << "\n\n\n�� �� �������, �� ������� ����������� �� ���������� ���������, ����� ��������� ������� ������ ���, � ����� ������� ������� � ������� ���������������:\n";
	int tempjter = *jter;
	for (int i = 0, order_counter = 0; i < tempjter; i++)
	{
		int min = 0;
		int minjter = -1;
		for (int j = 0; j < tempjter; j++)
		{
			if (element_counter[j] != 0)
			{
				if (j == 0)
				{
					minjter = j;
				}
				else if (element_counter[j] < element_counter[minjter])
				{
					minjter = j;
				}
			}
			else
			{
				element_counter[j] = iter + 1;
				(*jter)--;
			}
		}
		if (minjter != -1)
		{
			order[order_counter] = minjter;
			order_counter++;
			element_counter[minjter] = iter + 1;
		}
	}
}

void printer(int** mass, int iter, int jter, int* order)
{
	for (int i = 0; i < iter; i++)
	{
		for (int j = 0; j < jter; j++)
		{
			cout << mass[i][order[j]] << "\t";
		}
		cout << "\n";
	}
	cout << "\n���������� ����� ������� � ������������ �������:\n";
	for (int i = 0; i < jter; i++)
	{
		cout << order[i]+1 << "\t";
	}
	cout << "\n\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");

		//3-2
	/*�������� ������� ��������� � �������. � ������� ��������� �������������� ���� �������� ������, ��������� � �������� � ����� �����������. � ������� ������� ����������� �������
	������� �� ����������� ��������������. �������������� ������� � ���������� ����� � �������, � ������� ����� ��������� ������ 3. ���������� ����� ��������� �������������� � �������. �������
	������� �������� � ����������, ������� ����������� ������ ������� ��������� �������. ���������� � ����� ������� ����������� ���������. ��� ������� ������ � ���������� ���������� � ������� ����� 
	������ ����������, ���������� ���������� � ��� ������������ ������.*/

	int* iter = new int;
	int* jter = new int;

	cout << "���������� ����� �������: ";
	cin >> *iter;
	cout << "���������� �������� �������: ";
	cin >> *jter;

	int** mass = new int* [*iter];
	for (int i = 0; i < *iter; i++)
	{
		mass[i] = new int[*jter];
	}

	filler(mass, *iter, *jter);

	int* order = new int[*jter];

	organiser(mass, *iter, jter, order);
	printer(mass, *iter, *jter, order);

	system("pause");
	return 0;
}