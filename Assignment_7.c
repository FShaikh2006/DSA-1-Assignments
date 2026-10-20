#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack empty\n");
        return -1;
    }
    return stack[top--];
}

int evalPost(char exp[])
{
    int i, op1, op2, result;

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch (exp[i])
            {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                case '%':
                    result = op1 % op2;
                    break;
                default:
                    printf("Invalid Operator\n");
                    return -1;
            }

            push(result);
        }
    }

    return pop();
}

int main()
{
    char exp[MAX];

    printf("Enter Postfix Expression: ");
    scanf("%s", exp);

    printf("Result = %d\n", evalPost(exp));

    return 0;
}