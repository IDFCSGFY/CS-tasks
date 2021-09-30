#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//8
	/*Найти максимальный и минимальный элементы последовательности чисел, которые вводятся с клавиатуры пользователем. Вычислить их разность.*/
	
	int a, min, max;
	cout << "Введите последовательность чисел для определения минимального и максимального элементов. Для окончания последовательности введите '0'\n";
	cin >> a;
	min = a;
	max = a;
	while (true)
	{
		cin >> a;
		if (a == 0) { break; }
		if (a < min) { min = a; }
		else if (a > max) { max = a; }
	}
	cout << "Минимальный элемент: " << min << "\nМаксимальный элемент: " << max << "\n";

	system("pause");
	return 0;
}