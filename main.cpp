#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

bool isOperator(char arithm)
{
    return (arithm == '+' ||
            arithm == '-'||
            arithm == '*' ||
            arithm == '/' ||
            arithm == '^');
}

void onp(char* expression)
{
    char a,c;
    char *onpex = new char[200];
    int onpex_ind = 0;
    char operators[150];
    int op_ind = 0;

    size_t len = strlen(expression);

    for (int i = 0; i < len; i++)
    {
        c = expression[i];
        if (c == '(')
        {
            continue;
        }
        else if (c== ')')
        {
            onpex[onpex_ind++] = operators[--op_ind];
        }
        else if (isOperator(c))
        {
            operators[op_ind++] = c;
        }
        else
        {
            onpex[onpex_ind++] = c;
        }

    }
    while(op_ind-->0)
    {
        onpex[onpex_ind++] = operators[op_ind];
    }
    onpex[onpex_ind] = '\0';
    cout << onpex << endl;
    delete onpex;
}

int main(int argc, char *argv[])
{
    char infix[400];
    int number;
    cin >> number;
    while (number-- > 0)
    {
        cin >> infix;
        onp(infix);
    }
    return 0;
}
