#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//12
	/*�������� ���������, ������� ���������� �������� ����� �����, ������� "�������" ��������� � ������������ ���������.*/
	
	int n, min, max, guess, counter = 0;
	cout << "������� ��������, � ������� ����� ������ ���������� ����������� �����\nMin = ";
	cin >> min;
	cout << "Max = ";
	cin >> max;
	n = min + rand() % (max - min);
	guess = n + 1;
	cout << "����� ���� ��������. ����������\n";
	do
	{
		cin >> guess;
		counter++;
		guess > n ? cout << "������\n" : cout << "������\n";
	} while (guess != n);
	cout << "�� ������� ����� " << n << ", �������� � ���������� �� " << min << " �� " << max << " (" << (max - min) << " �����) �� " << counter << " �������\n";

	system("pause");
	return 0;
}