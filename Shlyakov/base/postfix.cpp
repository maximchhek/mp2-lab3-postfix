#include "postfix.h"
#include "stack.h"
using namespace std;


int TPostfix::Priority(char operation)
{
	switch (operation)
	{
	case ')':
	case '(':
		return 0;
		break;
	
	case '+':
	case '-':
		return 1;
		break;

	case '*':
	case'/':
		return 2;
		break;

	case '^':
		return 3;
		break;
	}
}

int TPostfix::TypeOfArg(char sy)
{
    if (sy >= '0' && sy <= '9')
        return 1;
    else if (sy == '+' || sy == '-' || sy == '*' || sy == '/' || sy == '^')
        return 2;
    else if (sy == '(')
        return 3;
    else if (sy == ')')
        return 4;
    else
        throw ("Error: lexem");
}

bool TPostfix::isCorrect()
{
    if (!this->isCorrectStaples())
        throw ("Error: no correct staples");

    //типа конечный автомат для проверки синтаксиса, но он сразу проверяет и лексемы
    int tabl[6][6] = { {0, 1, 5, 4, 5, 5}, {0, 1, 2, 5, 3, 5}, {0, 1, 5, 4, 5, 5}, {0, 5, 2, 5, 3, 5}, {0, 1, 5, 4, 3, 5}, {5, 5, 5, 5, 5, 5} };
    int arg1 = 0, arg2;
    for (int i = 0; i < infix.length(); i++)
    {
        arg2 = TypeOfArg(infix[i]);
        arg1 = tabl[arg1][arg2];
        if (arg1 == 5) throw("Error: sintaxis");
    }
    return 1;
}

bool TPostfix::isCorrectStaples() {
    //проверка корректности расставленных скобок
    int res = 0;
    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(')
            res += 1;

        else if (infix[i] == ')')
            res -= 1;
    }
    if (res == 0)
        return 1;
    return 0;
}

int TPostfix::Calculate()
{
    for (int i = 0; i < postfix.length(); i++) 
    {
        if (TypeOfArg(postfix[i]) == 1)
            d.Push(postfix[i] - '0');
        else
        {
            int x2 = d.Pop();
            int x1 = d.Pop();
            int r = 0;

            switch (postfix[i])
            {
            case '+': r = x1 + x2; break;
            case '-': r = x1 - x2; break;
            case '*': r = x1 * x2; break;
            case '/':
                if (x2 == 0) throw "Del na 0";
                r = x1 / x2; 
                break;
            case '^': r = pow(x1, x2); break;
            }
            d.Push(r);
        }
    }
    return d.Pop();
}

string TPostfix::ToPostfix()
{
    if (!c.IsEmpty())
    {
        c.Clear();
    }
    for (int i = 0; i < infix.size(); i++)
    {
        switch (TypeOfArg(infix[i]))
        {
        case 1:
            postfix += infix[i];
            break;
        case 2:
            while (!c.IsEmpty())
            {
                char op = c.Pop();
                if (Priority(infix[i]) <= Priority(op))
                    postfix += op;
                else
                {
                    c.Push(op);
                    break;
                }
            }
            c.Push(infix[i]);
            break;
        case 3:
            c.Push(infix[i]);
            break;
        case 4:
            while (c.Check() != '(')
                postfix += c.Pop();
            c.Pop();
        }
    }
    
    while (!c.IsEmpty())
        postfix += c.Pop();
    return postfix;
}


