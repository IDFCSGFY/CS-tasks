#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//8
	/*����� ������������ � ����������� �������� ������������������ �����, ������� �������� � ���������� �������������. ��������� �� ��������.*/
	
	int a, min, max;
	cout << "������� ������������������ ����� ��� ����������� ������������ � ������������� ���������. ��� ��������� ������������������ ������� '0'\n";
	cin >> a;
	min = a;
	max = a;
	while (true)
	{
		cin >> a;
		if (a == 0) { break; }
		if (a < min) { min = a; }
		else if (a > max) { max = a; }
	}
	cout << "����������� �������: " << min << "\n������������ �������: " << max << "\n";

	system("pause");
	return 0;
}