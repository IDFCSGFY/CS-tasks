#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	//2-1
/*��� ������ ����� �����, ������� � ��������� [15-30], ����������� ������� � 10. ����� � ������� �������, �������� ������� � �������� ��������������� ����� ��� �������� ���������.*/
	int mass[10], aver = 0, counter = 0, min, miniter;
	cout << "������� ������ �� 10 ����� ��� ���������� �������� �������� �������� � �������� ����� ������\n";
	for (int i = 0; i < 10; i++)
	{
		cin >> mass[i];
		if (mass[i] % 2 == 1)
		{
			aver += mass[i];
			counter++;
		}
	}
	aver /= counter;
	min = abs(mass[0] - aver);
	miniter = 0;
	for (int i = 1; i < 10; i++)
	{
		if (abs(mass[i] - aver) < min) { min = abs(mass[i] - aver); miniter = i; }
	}
	cout << "�������� ������� � ��. ��. ����� ������ ������ ������� �������: " << mass[miniter] << "\n";

	system("pause");
	return 0;
}