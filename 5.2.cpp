#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

		//5-2
	/*���������� ������ �������� � ���������� ����������� ���������.*/
	int mass[10], maxdivcounter=0, maxdiviter;
	cout << "������� ������ �� 10 ����� ��� ����������� ������� �������� � ���������� ����������� ���������\n";
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
	cout << "������: " << maxdiviter << "\n";
	
	system("pause");
	return 0;
}