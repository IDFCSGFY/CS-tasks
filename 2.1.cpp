#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	//2-1
/*����� �����p��� ������ � �� N ��p�� � � ��������. ����� � �������������� ������� � ���������� ������ ���������*/
	
	const int N = 5, M = 4;
	int A[N][M], minsum = INT_MAX, minjter;
	cout << "������� ������ �� " << N << " ����� � " << M << " ��������\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int j = 0; j < M; j++)
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			sum += A[i][j];
		}
		if (sum < minsum)
		{
			minsum = sum;
			minjter = j;
		}
	}
	cout << "������� � ���������� ������ ���������:\n";
	for (int i = 0; i < N; i++)
	{
		cout << A[i][minjter] << "\n";
	}
	
	system("pause");
	return 0;
}