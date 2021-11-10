#include <iostream>

using namespace std;

void filler(int** mass, int inum, int jnum)
{
	cout << "\n���������� �������:\n";
	for (int i = 0; i < inum; i++)
	{
		for (int j = 0; j < jnum; j++)
		{
			mass[i][j] = rand() % 10 + 1;
			cout << mass[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << endl;
}

void orderer(int** mass, int inum, int jnum, int* order)
{
	cout << "\n������������� ��������...\n";
	int* elcounter = new int[jnum];
	for (int j = 0; j < jnum; j++)
	{
		elcounter[j] = 0;
		int maxnum;
		for (int i = 0; i < inum-j; i++)
		{
			if (i == 0)
			{
				maxnum = mass[i][j];
			}
			else if (mass[i][j] > maxnum)
			{
				maxnum = mass[i][j];
			}
		}
		for (int i = 0; i < inum; i++)
		{
			if (mass[i][j] == maxnum)
			{
				elcounter[j]++;
			}
		}
	}
	for (int j = 0; j < jnum; j++)
	{
		int minjter;
		for (int l = 0; l < jnum; l++)
		{
			if (l == 0)
			{
				minjter = l;
			}
			else if (elcounter[l] < elcounter[minjter])
			{
				minjter = l;
			}
		}
		order[j] = minjter;
		elcounter[minjter] = elcounter[jnum - j - 1];
	}
	cout << endl;
}

void outer(int** mass, int inum, int jnum, int* order)
{
	cout << "\n�������, �� � �������������� ���������:\n";
	for (int i = 0; i < inum; i++)
	{
		for (int j = 0; j < jnum; j++)
		{
			cout << mass[i][order[j]] << "\t";
		}
		cout << "\n";
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	//4-1
	/*1.	�������� ������� ��������� � �������. 
� ������� ��������� �������������� ���� �������� ������, ��������� � �������� � ����� �����������. � ������� ������� ����������� ������� ������� �� ����������� ��������������. 
�������������� ������� � ���������� ������������ ��������� ������� � �������. ���������� ����� ��������� �������������� � �������. ������� ������� �������� � ����������, 
������� ����������� ������ ������� ��������� �������. ���������� � ����� ������� ����������� ���������. ��� ������� ������ � ���������� ���������� � ������� ����� ������ ����������, 
���������� ���������� � ��� ������������ ������.*/

	int inum, jnum;
	
	cout << "���������� ����� � �������: ";
	cin >> inum;
	cout << "���������� �������� � �������: ";
	cin >> jnum;

	int** mass = new int* [inum];
	for (int i = 0; i < inum; i++)
	{
		mass[i] = new int [jnum];
	}

	filler(mass, inum, jnum);
	int* order = new int;
	orderer(mass, inum, jnum, order);
	outer(mass, inum, jnum, order);

	system("pause");
	return 0;
}