#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//5-3
	/*—ортировка выбором. ¬ыбираетс€ максимальный элемент в массиве, переноситс€ в выходной массив на очередную позицию и замен€етс€ во входном на "очень маленькое значение" ( MININT).*/
	int mass[10], outmass[10];
	cout << "¬ведите массив из 10 чисел дл€ сортировки\n";
	for (int i = 0; i < 10; i++)
	{
		cin >> mass[i];
	}
	for (int i = 0; i < 10; i++)
	{
		int max = 0;
		for (int j = 0; j < 10; j++)
		{
			if (mass[j] > mass[max])
			{
				max = j;
			}
		}
		outmass[i] = mass[max];
		mass[max] = INT_MIN;
		cout << outmass[i] << " ";
	}
	cout << "\n";
	
	system("pause");
	return 0;
}