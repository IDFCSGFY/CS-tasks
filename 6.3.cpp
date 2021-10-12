#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	//6-3
	/*Сортировка выбором. Выбирается максимальный элемент в массиве и запоминается. Затем удаляется, а все последующие за ним элементы сдвигаются на один влево.
	Сам элемент заносится на освободившуюся последнюю позицию.*/
	const int N = 10;
	int A[N], maxiter;
	cout << "Введите массив из " << N << " чисел для сортировки\n";
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
		cout << "Максимальное число: " << A[N-1] << "\nМассив: ";
		for (int j = 0; j < N; j++)
		{
			cout << A[j] << " ";
		}
		cout << "\n";
	}

	system("pause");
	return 0;
}
