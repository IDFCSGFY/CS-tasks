#include <iostream>
using namespace std;

struct Stack
{
	string data;
	Stack* next;
};

int getprio(string x);
string top(Stack* S);
string pop(Stack** S);
void push(string x, Stack** S);

int main()
{
	setlocale(LC_ALL, "Russian");

	string instr, outstr = "";
	Stack* S = NULL;
	Stack* new_element = (Stack*)malloc(sizeof(Stack));
	new_element->data = "=";
	new_element->next = NULL;
	S = new_element;

	cout << "¬ведите выражение." << endl;
	cin >> instr;

	for (int i = 0; i < instr.size() - 1; i++)
	{
		string x = instr.substr(i, 1);
		int prio = getprio(x);
		if (prio == 0)
			outstr.append(x + " ");
		else if (prio == 1) //x == "("
		{
			push(x, &S);
		}
		else if (prio == 2) //x == ")"
		{
			string tempx = pop(&S);
			while (tempx != "(")
			{
				outstr.append(tempx);
			}
		}
		else if (prio >= 3 || prio <= 5) //"=" "+" "-" "*" "/"
		{
			while (S != NULL && getprio(top(S)) >= prio)
			{
				string tempx = pop(&S);
				outstr.append(tempx);
			}
			push(x, &S);
		}
	}

	cout << outstr << endl;

	if (S != NULL);
	{
		Stack* tempptr = S;
		while (tempptr->next != NULL)
		{
			tempptr = tempptr->next;
			free(S);
			S = tempptr;
		}
		free(S);
	}

	system("pause");
	return 0;
}

int getprio(string x)
{
	if (x == "(")
		return 1;
	else if (x == ")")
		return 2;
	else if (x == "=")
		return 3;
	else if (x == "+" || x == "-")
		return 4;
	else if (x == "*" || x == "/")
		return 5;
	else if (x != " ")
		return 0;
	else
		return -1;
}

string top(Stack* S)
{
	return S->data;
}

string pop(Stack** S)
{
	string tempstr = (*S)->data;
	Stack* tempptr = *S;
	*S = (*S)->next;
	free(tempptr);
	return tempstr;
}

void push(string x, Stack** S)
{
	Stack* new_element = (Stack*)malloc(sizeof(Stack));
	new_element->data = x;
	Stack* temp = *S;
	new_element->next = temp;
	*S = new_element;
}