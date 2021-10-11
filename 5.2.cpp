#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//5-2
	/*Определить индекс элемента с наибольшим количеством делителей.*/
	int mass[10], maxdivcounter=0, maxdiviter;
	cout << "Введите массив из 10 чисел для определения индекса элемента с наибольшим количеством делителей\n";
	for (int i = 0; i < 10; i++)
	{
		cin >> mass[i];
		int divcounter = 0;
		for (int j = 2; j < mass[i]; j++)
		{
			if(mass[i]%j==0)
			{
				divcounter++;
			}
		}
		if (divcounter > maxdivcounter) 
		{
			maxdivcounter = divcounter;
			maxdiviter = i;
		}
	}
	cout << "Индекс: " << maxdiviter << "\n";
	
	system("pause");
	return 0;
}
