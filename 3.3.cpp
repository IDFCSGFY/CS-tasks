#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//3-3
	/*���������� �������. ���������� ����������� ������� � �������, ����������� � �������� ������ �� ��������� ������� � ���������� �� ������� �� " ����� ������� ��������" ( MAXINT).*/
	int mass[10], outmass[10];
	cout << "������� ������ �� 10 ����� ��� ����������\n";
	for (int i = 0; i < 10; i++)
	{
		cin >> mass[i];
	}
	for (int i = 0; i < 10; i++)
	{
		int miniter = 0;
		for (int j = 0; j < 10; j++)
		{
			if (mass[j] < mass[miniter])
			{
				miniter = j;
			}
		}
		outmass[i] = mass[miniter];
		mass[miniter] = INT_MAX;
		cout << outmass[i] << " ";
	}
	cout << "\n";
	
	system("pause");
	return 0;
}