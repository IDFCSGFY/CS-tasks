#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	//2-2
/*���� ������� �������� � � N. ����������� �� ������ � �������, �������� ����, ����� ���������� ������� (���� �� ���) �������� � ������ ������ ����*/
	
	const int N = 5, M = 4;
	int A[N][M], miniter = 0, minjter = 0;

	cout << "��������� ������� " << M << " x " << N << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
			if (A[i][j] < A[miniter][minjter])
			{
				miniter = i; minjter = j;
			}
		}
	}
	cout << "�� �� �������, �� ���������� ������� � ������ ������ ����:\n";
	for (int i = miniter + 1, icounter = 0; icounter < N; i++, icounter++)
	{
		if (i == N)
		{
			i = 0;
		}
		for (int j = minjter + 1, jcounter = 0; jcounter < M; j++, jcounter++)
		{
			if (j == M)
			{
				j = 0;
			}
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
	
	system("pause");
	return 0;
}