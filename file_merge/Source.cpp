#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <fstream>
using namespace std;

void f_couter(FILE* file, string message);
void sort(FILE* to_sort);
int splitter(FILE* to_split, FILE* tf1, FILE* tf2);
void merger(FILE* tf1, FILE* tf2, FILE* to_merge_to);

int main()
{
	setlocale(LC_ALL, "Russian");

	FILE* original = fopen("original.txt", "r+t");
	if (original == NULL)
	{
		cout << "Ошибка открытия файла." << endl;
		return 0;
	}

	f_couter(original, "Несортированый файл: ");

	sort(original);

	f_couter(original, "Отсортированный файл: ");

	fclose(original);

	system("pause");
	return 0;
}

void sort(FILE* to_sort)
{
	FILE *tf1 = tmpfile(), *tf2 = tmpfile();

	cout << "Происходит деление файла на два временных." << endl;
	int splt_result = splitter(to_sort, tf1, tf2);
	//функция сплиттер возвращает значение, обозначающее количество элементов во временных файлах после последнего деления: 2, если в обоих больше одного числа; 1, если только в первом файле больше одного числа

	if (splt_result == 2)
	{
		cout << "Оба файла подлежат дальнейшему делению." << endl;
		sort(tf1);
		sort(tf2);
	}
	else if (splt_result == 1)
	{
		cout << "Первый файл подлежит финальному делению." << endl;
		sort(tf1);
	}
	else
		cout << "Деление было завершено." << endl;

	merger(tf1, tf2, to_sort);
	fclose(tf1);
	fclose(tf2);
}

int splitter(FILE* to_split, FILE* tf1, FILE* tf2)
{
	int nums_in_f1 = 0, nums_in_f2 = 0;
	int temp;
	rewind(tf1);
	rewind(tf2);
	rewind(to_split);
	while (true)
	{
		if (fscanf(to_split, "%d", &temp) == 1)
		{
			fprintf(tf1, " %d", temp);
			nums_in_f1++;
			cout << "Запись в первый файл: " << temp << "(" << nums_in_f1 << ")" << endl;
		}
		else
			break;
		if (fscanf(to_split, "%d", &temp) == 1)
		{
			fprintf(tf2, " %d", temp);
			nums_in_f2++;
			cout << "Запись во второй файл: " << temp << "(" << nums_in_f1 << ")" << endl;
		}
		else
			break;
	}
	if (nums_in_f2 > 1)
		return 2;
	else if (nums_in_f1 > 1)
		return 1;
	else
		return 0;
}

void merger(FILE* tf1, FILE* tf2, FILE* to_merge_to)
{
	bool is_feof1 = false, is_feof2 = false, is_printed1 = true, is_printed2 = true;
	int temp1, temp2;
	rewind(tf1);
	rewind(tf2);
	rewind(to_merge_to);
	while (true)
	{
		//есть ли числа в первом файле 
		if (is_printed1 && fscanf(tf1, "%d", &temp1) == -1)
			is_feof1 = true;
		else
			is_printed1 = false;
		//есть ли числа во втором файле
		if (is_printed2 && fscanf(tf2, "%d", &temp2) == -1)
			is_feof2 = true;
		else
			is_printed2 = false;
		//если на этом цикле обе переменные не получили данных с файлов, то завершить цикл
		if (is_feof1 && is_feof2)
			break;
		else
		{
			if (!is_printed1 && !is_printed2)
			{
				if (temp1 <= temp2)
				{
					fprintf(to_merge_to, " %d", temp1);
					is_printed1 = true;
				}
				else
				{
					fprintf(to_merge_to, " %d", temp2);
					is_printed2 = true;
				}
			}
			else if (!is_printed1)
			{
				fprintf(to_merge_to, " %d", temp1);
				is_printed1 = true;
			}
			else
			{
				fprintf(to_merge_to, " %d", temp2);
				is_printed2 = true;
			}
		}
	}
	cout << "Слияние двух файлов." << endl;
}

void f_couter(FILE* to_cout, string message)
{
	int temp;
	rewind(to_cout);
	if (fscanf(to_cout, "%d", &temp) != 1)
	{
		cout << "Файл пуст." << endl;
	}
	else
	{
		cout << message << temp;
		while (fscanf(to_cout, "%d", &temp) == 1)
		{
			cout << " " << temp;
		}
		cout << "." << endl;
	}
}