#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//5
	/*����� ��� ������� ����� �� ������������ ���� ����� � ��������� �� 2 �� N.*/
	
	int N;
	cout << "������� N ��� ������ ���� ������� ����� � ���������� [2; N]\n";
	cin >> N;
	cout << "2";
	for (int i = 3; i <= N; i++)
	{
		bool simp = true;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0) { simp = false; }
		}
		if (simp) { cout << ", " << i; }
	}
	cout << "\n";

	system("pause");
	return 0;
}