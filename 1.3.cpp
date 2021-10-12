#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	//1-3
/*Дана матрица размером М х N. Удалить строки содержащие нечетное количество элементов, у которых сумма делителей является нечетным числом*/
	
	const int N = 5, M = 4;
	int A[N][M];
	bool to_delete[N];

	cout << "Введите массив из " << N << " строк и " << M << " столбцов\n";
	for (int i = 0; i < N; i++)
	{
		to_delete[i] = false;
		int elementcounter = 0;
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
			int sumofdivs = 0;
			for (int l = 1; l <= A[i][j]; l++)
			{
				if (A[i][j] % l == 0)
				{
					sumofdivs += l;
				}
			}
			if (sumofdivs % 2 == 1)
			{
				elementcounter++;
			}
		}
		if (elementcounter % 2 == 1)
		{
			to_delete[i] = true;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (!to_delete[i])
		{
			for (int j = 0; j < M; j++)
			{
				cout << A[i][j] << " ";
			}
			cout << "\n";
		}
	}
	
	system("pause");
	return 0;
}