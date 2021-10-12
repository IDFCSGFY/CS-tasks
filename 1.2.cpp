#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	//1-2
	/*Дана матрица размером М х N. Переставляя ее строки и столбцы, добиться того, чтобы наибольший элемент (один из них) оказался в верхнем левом углу*/

	const int N = 5, M = 4;
	int A[N][M], maxiter = 0, maxjter = 0;

	cout << "Заполните матрицу " << M << " x " << N << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
			if (A[i][j] > A[maxiter][maxjter])
			{
				maxiter = i; maxjter = j;
			}
		}
	}
	cout << "Та же матрица, но наибольший элемент в верхнем левом углу:\n";
	for (int i = maxiter, icounter = 0; icounter < N; i++, icounter++)
	{
		if (i == N)
		{
			i = 0;
		}
		for (int j = maxjter, jcounter = 0; jcounter < M; j++, jcounter++)
		{
			if (j == M)
			{
				j = 0;
			}
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
}
