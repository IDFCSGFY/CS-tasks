#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//1-1
	/*����� �����p��� ������ � �� N ��p�� � � ��������. ����� � �������������� ������ � ���������� ������ ���������.*/
	/*const int N = 5, M = 4;
	int A[N][M];
	cout << "������� ������ �� " << N << " ����� � " << M << " ��������\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
		}
	}*/
	//6-3
/*���������� �������. ���������� ������������ ������� � ������� � ������������. ����� ���������, � ��� ����������� �� ��� �������� ���������� �� ���� �����.
��� ������� ��������� �� �������������� ��������� �������.*/
	const int N = 10;
	int A[N], maxiter;
	cout << "������� ������ �� " << N << " ����� ��� ����������\n";
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		int maxnum = A[0];
		maxiter = 0;
		for (int j = 0; j < N - i; j++)
		{
			if (A[j] > maxnum)
			{
				maxnum = A[j]; maxiter = j;
			}
		}
		for (int j = maxiter + 1; j < N; j++)
		{
			A[j - 1] = A[j];
		}
		A[N - 1] = maxnum;
		cout << "������������ �����: " << A[N-1] << "\n������: ";
		for (int j = 0; j < N; j++)
		{
			cout << A[j] << " ";
		}
		cout << "\n";
	}

	system("pause");
	return 0;
}