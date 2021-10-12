#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	//2-3
/*���� ������� �������� � � N. ������� ������� ���������� �������� ���������� ���������, ��������� ������ �� ������ ����.*/
	
	const int N = 5, M = 4;
	int A[N][M];
	bool to_delete[M];

	cout << "������� ������ �� " << N << " ����� � " << M << " ��������\n";
	for (int i = 0; i < N; i++)
	{
		//to_delete[i] = false;
		//int elementcounter = 0;
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int j = 0; j < M; j++)
	{
		to_delete[j] = false;
		int elementcounter = 0;
		for (int i = 0; i < N; i++)
		{
			int temp = A[i][j];
			while (temp != 0)
			{
				if (temp % 10 % 2 == 1)
				{
					elementcounter -= 1;
					break;
				}
				temp /= 10;
			}
			elementcounter++;
		}
		if (elementcounter % 2 == 1)
		{
			to_delete[j] = true;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!to_delete[j])
			{
				cout << A[i][j] << " ";
			}
		}
		cout << "\n";
	}
	
	system("pause");
	return 0;
}