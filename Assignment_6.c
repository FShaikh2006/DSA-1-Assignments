#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char elem[]) {
    if (top == MAX - 1) {
        printf("Stack full\n");
        return;
    }
    top++;
    strcpy(stack[top], elem);
}

void pop_str(char result[]) {
    if (top == -1) {
        printf("Stack empty\n");
        result[0] = '\0';
        return;
    }
    strcpy(result, stack[top]);
    top--;
}

int isEmpty() {
    return (top == -1);
}

int isFull() {
    return (top == MAX - 1);
}

int icp_infixPost(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 4;
    if (ch == '(')
        return 5;
    else
        return 0;
}

int isp_infixPost(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    else
        return 0;
}

void infixToPostfix() {
    char inexp[MAX], postexp[MAX];
    int k = 0, i = 0;
    char tkn, temp[2];

    printf("Enter infix expression: ");
    scanf("%s", inexp);

    while (inexp[i] != '\0') {
        tkn = inexp[i];

        if (isalnum(tkn)) {
            postexp[k] = tkn;
            k++;
        } else if (tkn == '(') {
            temp[0] = '(';
            temp[1] = '\0';
            push(temp);
        } else if (tkn == ')') {
            while (!isEmpty() && stack[top][0] != '(') {
                postexp[k] = stack[top][0];
                k++;
                pop_str(temp);
            }
            if (!isEmpty()) {
                pop_str(temp);
            }
        } else {
            while (!isEmpty() && isp_infixPost(stack[top][0]) >= icp_infixPost(tkn)) {
                postexp[k] = stack[top][0];
                k++;
                pop_str(temp);
            }
            temp[0] = tkn;
            temp[1] = '\0';
            push(temp);
        }
        i++;
    }

    while (!isEmpty()) {
        postexp[k] = stack[top][0];
        k++;
        pop_str(temp);
    }
    postexp[k] = '\0';

    printf("Postfix expression: %s\n", postexp);
}

void postfixToInfix() {
    char postexp[MAX], token;
    int i = 0;
    char op1[MAX], op2[MAX], expr[MAX];

    printf("Enter postfix expression : ");
    scanf("%s", postexp); 

    int len = strlen(postexp);
    for (i = 0; i < len; i++) {
        token = postexp[i];

        if (isalnum(token)) {
            char single[2];
            single[0] = token;
            single[1] = '\0';
            push(single);
        } else {
            pop_str(op2);
            pop_str(op1);

            strcpy(expr, "(");
            strcat(expr, op1);
            char op_str[2];
            op_str[0] = token;
            op_str[1] = '\0';
            strcat(expr, op_str);
            strcat(expr, op2);
            strcat(expr, ")");

            push(expr);
        }
    }

    char result[MAX];
    pop_str(result);
    printf("Infix expression: %s\n", result);
}

void prefixToPostfix() {
    char preexp[MAX], token;
    int i, len;
    char op1[MAX], op2[MAX], expr[MAX];

    printf("Enter prefix expression : ");
    scanf("%s", preexp);

    len = strlen(preexp);
    for (i = len - 1; i >= 0; i--) {
        token = preexp[i];

        if (isalnum(token)) {
            char single[2];
            single[0] = token;
            single[1] = '\0';
            push(single);
        } else {
            pop_str(op1);
            pop_str(op2);

            strcpy(expr, op1);
            strcat(expr, op2);
            char op_str[2];
            op_str[0] = token;
            op_str[1] = '\0';
            strcat(expr, op_str);

            push(expr);
        }
    }

    char result[MAX];
    pop_str(result);
    printf("Postfix expression: %s\n", result);
}

int main() {
    int choice;

    do {
        printf("1. Infix to Postfix\n");
        printf("2. Postfix to Infix\n");
        printf("3. Prefix to Postfix\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                top = -1;
                infixToPostfix();
                break;
            case 2:
                top = -1;
                postfixToInfix();
                break;
            case 3:
                top = -1;
                prefixToPostfix();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}


