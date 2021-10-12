#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	//2-1
/*Дан массив целых чисел, лежащих в диапазоне [15-30], размерность массива – 10. Найти в массиве элемент, наиболее близкий к среднему арифметическому суммы его нечетных элементов.*/
	int mass[10], aver = 0, counter = 0, min, miniter;
	cout << "Введите массив из 10 чисел для нахождение элемента наиболее близкого к среднему суммы чётных\n";
	for (int i = 0; i < 10;)
	{
		cin >> mass[i];
		if (mass[i] <= 30 && mass[i] >= 15)
		{
			if (mass[i] % 2 == 1)
			{
				aver += mass[i];
				counter++;
			}
			i++;
		}
		else
		{
			cout << "Число не входит в диапазон [15; 30], поробуйте ещё раз\n";
		}
	}
	aver /= counter;
	min = abs(mass[0] - aver);
	miniter = 0;
	for (int i = 1; i < 10; i++)
	{
		if (abs(mass[i] - aver) < min) { min = abs(mass[i] - aver); miniter = i; }
	}
	cout << "Наиболее близкий к ср. ар. суммы чётных членов массива элемент: " << mass[miniter] << "\n";

	system("pause");
	return 0;
}
