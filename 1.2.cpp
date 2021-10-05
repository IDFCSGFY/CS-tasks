#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//2
	/*«адан массив, определить есть ли такое значение k, при котором произведени€ (A(1)*A(2)*ЕA(k)) и (A(k+1)*Е*A(N)) равны.*/
	const int N = 10;
	int A[N], k = -1;
	cout << "¬ведите массив из " << N << " чисел дл€ определени€ k, при котором A(1)*A(2)*ЕA(k) = A(k+1)*Е*A(N) равны\n";
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
	if (k == -1) { cout << "«начение не существует\n"; }
	else { cout << "k = " << k << "\n"; }

	system("pause");
	return 0;
}