#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//2
	/*Задан массив, определить есть ли такое значение k, при котором произведения (A(1)*A(2)*…A(k)) и (A(k+1)*…*A(N)) равны.*/
	const int N = 10;
	int A[N], k = -1;
	cout << "Введите массив из " << N << " чисел для определения k, при котором A(1)*A(2)*…A(k) = A(k+1)*…*A(N) равны\n";
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N - 1; i++)
	{
		int mult1 = 1, mult2 = 1;
		for (int j = 0; j <= i; j++)
		{
			mult1 *= A[j];
		}
		for (int j = i + 1; j < N; j++)
		{
			mult2 *= A[j];
		}
		if (mult1 == mult2) 
		{ k = i; break; }
	}
	if (k == -1) { cout << "Значение не существует\n"; }
	else { cout << "k = " << k << "\n"; }

	system("pause");
	return 0;
}
