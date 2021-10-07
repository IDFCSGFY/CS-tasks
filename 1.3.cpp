#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//2
	/*Сортировка выбором. Выбирается минимальный элемент в массиве и запоминается. Затем удаляется, а все последующие за ним элементы сдвигаются на один влево. Сам элемент заносится на освободившуюся последнюю позицию.*/
	const int N = 10;
	int A[N], miniter;
	cout << "Введите массив из " << N << " чисел для сортировки\n";
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) 
	{
		int minnum = A[0];
		miniter = 0;
		for (int j = 0; j < N - i; j++)
		{
			if (A[j] < minnum) 
			{ minnum = A[j]; miniter = j; } 
		}
		for (int j = miniter + 1; j < N; j++) 
		{
			A[j - 1] = A[j];
		}
		A[N-1] = minnum;
		cout << "Минимальное число: " << A[miniter] <<"\nМассив: ";
		for (int j = 0; j < N; j++)
		{
			cout << A[j] << " ";
		}
		cout << "\n";
	}

	system("pause");
	return 0;
}
