#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//9
	/*���� ����������� �����. �������� ���������, ������� ������� ��� ����� � ������� � �������� �������.*/
	
	cout << "������� ����� ��� ������ ��� ���� � �������� �������\n";
	int a;
	cin >> a;
	while (a != 0)
	{
		cout << a % 10 << "\n";
		a /= 10;
	}

	system("pause");
	return 0;
}