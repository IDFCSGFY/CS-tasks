#include <iostream>

using namespace std;

void filler(int** mass, int iter, int jter)
{
	for (int i = 0; i < iter; i++)
	{
		for (int j = 0; j < jter; j++)
		{
			mass[i][j] = rand();
			cout << mass[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}

void organiser(int** mass, int iter, int jter, int* order)
{
	int* element_counter = new int[jter];
	for (int j = 0; j < jter; j++)
	{
		element_counter[j] = 0;
		for (int i = 0; i < iter; i++)
		{
			int a = mass[i][j];
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
	}
	for (int i = 0; i < jter; i++)
	{
		int miniter = 0;
		for (int j = 0; j < jter; j++)
		{
			if (element_counter[j] < element_counter[miniter])
			{
				miniter = j;
			}
		}
		order[i] = miniter;
		element_counter[miniter] = iter+1;
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
}

int main()
{
	setlocale(LC_ALL, "Russian");

		//3-1
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

	organiser(mass, *iter, *jter, order);
	printer(mass, *iter, *jter, order);

	system("pause");
	return 0;
}