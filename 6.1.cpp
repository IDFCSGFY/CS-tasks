#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//6-1
	/*��� ������ ����� �����, ������� � ��������� [15-40], ����������� ������� � 10. ����� � ������� �������, �������� ������� � �������� ��������������� ����� ��� ��������� ������� 7.*/
	int mass[10], aver = 0, counter = 0, min, miniter = 0;
	cout << "������� ������ �� 10 ����� ��� ���������� �������� �������� �������� � �������� ����� ���������, ������� ���\n";
	for (int i = 0; i < 10;)
	{
		cin >> mass[i];
		if (mass[i] <= 40 && mass[i] >= 15)
		{
			if (mass[i] % 7 == 0)
			{
				aver += mass[i];
				counter++;
			}
			i++;
		}
		else
		{
			cout << "����� �� ������ � �������� [1; 20], ��������� ��� ���\n";
		}
	}
	aver /= counter;
	min = abs(mass[0] - aver);
	for (int i = 1; i < 10; i++)
	{
		if (abs(mass[i] - aver) < min) { min = abs(mass[i] - aver); miniter = i; }
	}
	cout << "�������� ������� � ��. ��. ����� ������� ��� ������ ������� �������: " << mass[miniter] << "\n";

	system("pause");
	return 0;
}