#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//5-1
	/*��� ������ ����� �����, ������� � ��������� [1-20], ����������� ������� � 10. ��������� ������ �� ��� �����, �������� � ������ ��������, 
	������� �������� ��������������� ����� ��� ���������, � �� ������ - ������� (����� �� �����������).*/
	int mass[10];
	float aver = 0;
	cout << "������� ������ �� 10 ����� ��� ���������� ��� �� ��� �����: ������ ��. ��. ����� ��������� � ������\n";
	for (int i = 0; i < 10; i++)
	{
		cin >> mass[i];
		aver += mass[i];
	}
	aver /= 10;
	cout << "������ ������: ";
	for (int i = 0; i < 10; i++)
	{
		if (mass[i] > aver)
		{
			cout << mass[i] << " ";
		}
	}
	cout << "\n������ ������: ";
	for (int i = 0; i < 10; i++)
	{
		if (mass[i] < aver)
		{
			cout << mass[i] << " ";
		}
	}
	cout << "\n";

	system("pause");
	return 0;
}