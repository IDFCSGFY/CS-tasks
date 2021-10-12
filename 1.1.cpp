#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//1-1
	/*Задан двумеpный массив А из N стpок и М столбцов. Найти и продублировать строку с наименьшей суммой элементов.*/
	const int N = 5, M = 4;
	int A[N][M], minsum = INT_MAX, miniter;
	cout << "Введите массив из " << N << " строк и " << M << " столбцов\n";
	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
			sum += A[i][j];
		}
		if(sum < minsum)
		{
			minsum = sum;
			miniter = i;
		}
	}
	cout << "Строка с наименьшей суммой элементов: ";
	for (int j = 0; j < M; j++)
	{
		cout << A[miniter][j] << " ";
	}
	cout << "\n";
}