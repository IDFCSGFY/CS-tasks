#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//5-1
	/*Дан массив целых чисел, лежащих в диапазоне [1-20], размерность массива – 10. Разделить массив на две части, поместив в первую элементы, 
	большие среднего арифметического суммы его элементов, а во вторую - меньшие (части не сортировать).*/
	int mass[10];
	float aver = 0;
	cout << "Введите массив из 10 чисел для разделения его на две части: больше ср. ар. суммы элементов и меньше\n";
	for (int i = 0; i < 10; i++)
	{
		cin >> mass[i];
		aver += mass[i];
	}
	aver /= 10;
	cout << "Первая группа: ";
	for (int i = 0; i < 10; i++)
	{
		if (mass[i] > aver)
		{
			cout << mass[i] << " ";
		}
	}
	cout << "\nВторая группа: ";
	for (int i = 0; i < 10; i++)
	{
		if (mass[i] < aver)
		{
			cout << mass[i] << " ";
		}
	}
	cout << "\n";

	system("pause");
	return 0;
}