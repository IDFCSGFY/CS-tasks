#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//9
	/*Дано натуральное число. Напишите программу, которая выводит его цифры в столбик в обратном порядке.*/
	
	cout << "Введите число для вывода его цифр в обратном порядке\n";
	int a;
	cin >> a;
	while (a != 0)
	{
		cout << a % 10 << "\n";
		a /= 10;
	}

	system("pause");
	return 0;
}