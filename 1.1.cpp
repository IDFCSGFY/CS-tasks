#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//1
	/*Даны два целых числа m и n. Напишите программу, которая выводит все числа от m до n включительно в порядке возрастания, если m<n, или в порядке убывания в противном случае.*/
	
	int m, n;
	cout << "Введите числа m и n для вывода всех целых чисел от m до n\nm: ";
	cin >> m;
	cout << "n: ";
	cin >> n;
	for (int i = m; i != n; m < n ? i++ : i--) 
	{
		cout << i << "\n"; 
	}
	cout << n << "\n";

	system("pause");
	return 0;
}
