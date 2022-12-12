#include <iostream>
#include <string>
using namespace std;

struct Stack
{
	char data;
	Stack* next = NULL;
};

int get_prio(char x);
char top(Stack* S);
char pop(Stack** S);
void push(char x, Stack** S);

int main()
{
	setlocale(LC_ALL, "Russian");

	string infix, postfix;
	Stack* S = NULL;

	cout << "Введите выражение." << endl;
	cin >> infix;
	
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

	cout << postfix << endl;

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
