#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//6-1
	/*Дан массив целых чисел, лежащих в диапазоне [15-40], размерность массива – 10. Найти в массиве элемент, наиболее близкий к среднему арифметическому суммы его элементов кратных 7.*/
	int mass[10], aver = 0, counter = 0, min, miniter = 0;
	cout << "Введите массив из 10 чисел для нахождение элемента наиболее близкого к среднему суммы элементов, кратных трём\n";
	for (int i = 0; i < 10;)
	{
		cin >> mass[i];
		if (mass[i] <= 40 && mass[i] >= 15)
		{
			if (mass[i] % 7 == 0)
			{
				aver += mass[i];
				counter++;
			}
			i++;
		}
		else
		{
			cout << "Число не входит в диапазон [1; 20], поробуйте ещё раз\n";
		}
	}
	aver /= counter;
	min = abs(mass[0] - aver);
	for (int i = 1; i < 10; i++)
	{
		if (abs(mass[i] - aver) < min) { min = abs(mass[i] - aver); miniter = i; }
	}
	cout << "Наиболее близкий к ср. ар. суммы кратных трём членов массива элемент: " << mass[miniter] << "\n";

	system("pause");
	return 0;
}