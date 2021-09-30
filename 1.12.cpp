#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//12
	/*Написать программу, которая предлагает отгадать целое число, которое "загадал" компьютер в определенном диапазоне.*/
	
	int n, min, max, guess, counter = 0;
	cout << "Введите диапазон, в котором будет лежать загаданное компьютером число\nMin = ";
	cin >> min;
	cout << "Max = ";
	cin >> max;
	n = min + rand() % (max - min);
	guess = n + 1;
	cout << "Число было загадано. Угадывайте\n";
	do
	{
		cin >> guess;
		counter++;
		guess > n ? cout << "Меньше\n" : cout << "Больше\n";
	} while (guess != n);
	cout << "Вы угадали число " << n << ", лежавшее в промежутке от " << min << " до " << max << " (" << (max - min) << " чисел) за " << counter << " попыток\n";

	system("pause");
	return 0;
}