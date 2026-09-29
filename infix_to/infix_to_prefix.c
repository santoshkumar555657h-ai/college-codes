#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct stack
{
    char data[20];
    int top;
};

typedef struct stack STACK;

void push(STACK *s, char item)
{
    s->data[++(s->top)] = item;
}

char pop(STACK *s)
{
    return s->data[(s->top)--];
}

int precedence(char symbol)
{
    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

int main()
{
    char infix[20], prefix[20];
    STACK s;

    int i, j = 0;
    char symbol, temp;

    s.top = -1;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    /* Reverse the infix expression and swap brackets */
    i = strlen(infix) - 1;

    while (i >= 0)
    {
        symbol = infix[i];

        if (symbol == '(')
            symbol = ')';
        else if (symbol == ')')
            symbol = '(';

        if (isalnum(symbol))
        {
            prefix[j] = symbol;
            j++;
        }
        else
        {
            while (s.top >= 0 &&
                   precedence(s.data[s.top]) > precedence(symbol))
            {
                prefix[j] = pop(&s);
                j++;
            }

            push(&s, symbol);
        }

        i--;
    }

    /* Pop remaining operators */
    while (s.top >= 0)
    {
        prefix[j] = pop(&s);
        j++;
    }

    prefix[j] = '\0';

    /* Reverse the result */
    i = 0;

    while (i < j / 2)
    {
        temp = prefix[i];
        prefix[i] = prefix[j - i - 1];
        prefix[j - i - 1] = temp;

        i++;
    }

    printf("Prefix expression: %s", prefix);

    return 0;
}
