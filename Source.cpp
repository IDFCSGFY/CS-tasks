//1+(2-3*4/(5-6)+7)/(1*8-9)
#include <iostream>
#include <string>
using namespace std;

struct Stack
{
	char data;
	Stack* next;
};
struct IntStack
{
	double data;
	IntStack* next;
};

int get_prio(char x);
char top(Stack* S);
char pop(Stack** S);
void push(char x, Stack** S);
int topi(IntStack* S);
int popi(IntStack** S);
void pushi(double x, IntStack** S);

int main()
{
	setlocale(LC_ALL, "Russian");

	string infix, postfix;
	Stack* S = NULL;

	cout << "Введите выражение." << endl;
	getline(cin, infix);
	
	for (int i = 0; i < infix.length(); i++)
	{
		char x = infix[i];
		if (x >= 48 && x <= 57)
		{
			postfix.append(1, x);
			while (i < infix.length() - 1 && (infix[i + 1] >= 48 && infix[i + 1] <= 57))
			{
				i++;
				x = infix[i];
				postfix.append(1, x);
			}
			postfix.append(1, ' ');
		}
		else
		{
			int xprio = get_prio(x);
			if (xprio == 1) //"("
				push(x, &S);
			else if (xprio == 2) //")"
			{
				x = pop(&S);
				while (x != '(')
				{
					postfix.append(1, x);
					if (S == NULL)
						break;
					x = pop(&S);
				}
			}
			else if (xprio >= 3) //"=" "+" "-" "*" "/"
			{
				if (S != NULL)
				{
					while (get_prio(top(S)) >= xprio)
					{
						char tx = pop(&S);
						postfix.append(1, tx);
						if (S == NULL)
							break;
					}
				}
				push(x, &S);
			}
		}
	}

	if (S != NULL)
	{
		while (S->next != NULL)
		{
			char tx = pop(&S);
			postfix.append(1, tx);
		}
		char tx = pop(&S);
		postfix.append(1, tx);
	}

	cout << "Постфикс: " << postfix << endl;

	IntStack* IS = NULL;

	for (int i = 0; i < postfix.length(); i++)
	{
		string temp;
		if (postfix[i] >= 48 && postfix[i] <= 57) //если начал считывать число
		{
			while (postfix[i] != ' ') //записывает число до конца в temp
			{
				temp += postfix[i];
				i++;
			}
			pushi(stoi(temp), &IS);
		}
		int prio = get_prio(postfix[i]);
		if (prio)
		{
			if (postfix[i] == '+')
			{
				double res = popi(&IS) + popi(&IS);
				pushi(res, &IS);
			}
			else if (postfix[i] == '-')
			{
				double tempi = popi(&IS);
				pushi((popi(&IS)-tempi), &IS);
			}
			else if (postfix[i] == '/')
			{
				double tempi = popi(&IS);
				pushi((popi(&IS) / tempi), &IS);
			}
			else if (postfix[i] == '*')
			{
				double res = popi(&IS) * popi(&IS);
				pushi(res, &IS);
			}
			else
				cout << "Какая-то рандомная штука, бро, я хз." << endl;
		}
	}

	double res = popi(&IS);
	cout << "Вывод: " << res << endl;

	system("pause");
	return 0;
}

int get_prio(char x)
{
	if (x == '(')
		return 1;
	else if (x == ')')
		return 2;
	else if (x == '=')
		return 3;
	else if (x == '+' || x == '-')
		return 4;
	else if (x == '*' || x == '/')
		return 5;
	else
		return 0;
}

char top(Stack* S)
{
	return S->data;
}

char pop(Stack** S)
{
	char tempdata = (*S)->data;
	Stack* tempptr = (*S);
	*S = (*S)->next;
	free(tempptr);
	return tempdata;
}

void push(char x, Stack** S)
{
	Stack* element = (Stack*)malloc(sizeof(Stack));
	element->next = *S;
	element->data = x;
	*S = element;
}

int topi(IntStack* S)
{
	return S->data;
}

int popi(IntStack** S)
{
	int tempdata = (*S)->data;
	IntStack* tempptr = (*S);
	*S = (*S)->next;
	free(tempptr);
	return tempdata;
}

void pushi(double x, IntStack** S)
{
	IntStack* element = (IntStack*)malloc(sizeof(IntStack));
	element->next = *S;
	element->data = x;
	*S = element;
}
