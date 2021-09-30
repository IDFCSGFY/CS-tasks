#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//11
	/*Написать программу, которая угадывает число, которое загадал пользователь.*/
	
	int n, guess, min = -1, max = -1;
	cout << "Загадайте число, чтобы программа его отгадала\n";
	cin >> n;
	while (min == -1 || max == -1)
	{
		guess = rand();
		cout << guess;
		if (guess > n) { max = guess; }
		else if (guess < n) { min = guess; }
	}
	while (guess != n)
	{
		guess = min + rand() % (max - min);
		cout << guess << "\n";
		if (guess > n) { max = guess; }
		else if (guess < n) { min = guess; }
	}
	
	system("pause");
	return 0;
}