#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

struct Node *createNode(int coeff, int exp)
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = newnode;

    return newnode;
}

void insertTerm(struct Node **head, int coeff, int exp)
{
    struct Node *newnode, *temp;

    if (coeff == 0)
        return;

    newnode = createNode(coeff, exp);

    if (*head == NULL)
    {
        *head = newnode;
        return;
    }

    temp = *head;

    do
    {
        if (temp->exp == exp)
        {
            temp->coeff = temp->coeff + coeff;
            free(newnode);

            if (temp->coeff == 0)
            {
                struct Node *prev = temp;

                if (temp->next == temp)
                {
                    free(temp);
                    *head = NULL;
                    return;
                }

                while (prev->next != temp)
                    prev = prev->next;

                prev->next = temp->next;

                if (*head == temp)
                    *head = temp->next;

                free(temp);
            }

            return;
        }

        temp = temp->next;

    } while (temp != *head);

    newnode = createNode(coeff, exp);

    if (exp > (*head)->exp)
    {
        temp = *head;

        while (temp->next != *head)
            temp = temp->next;

        newnode->next = *head;
        temp->next = newnode;
        *head = newnode;

        return;
    }

    temp = *head;

    while (temp->next != *head &&
           temp->next->exp > exp)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

struct Node *createPolynomial()
{
    struct Node *head = NULL;
    int n, coeff, exp, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Number of terms cannot be negative.\n");
        return NULL;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);

        if (exp < 0)
        {
            printf("Exponent must be non-negative. Try again.\n");
            i--;
            continue;
        }

        insertTerm(&head, coeff, exp);
    }

    return head;
}

void displayPolynomial(struct Node *head)
{
    struct Node *temp;
    int first = 1;

    if (head == NULL)
    {
        printf("0");
        return;
    }

    temp = head;

    do
    {
        if (temp->coeff != 0)
        {
            if (!first)
            {
                if (temp->coeff > 0)
                    printf(" + ");
                else
                    printf(" - ");
            }
            else if (temp->coeff < 0)
            {
                printf("-");
            }

            int c = abs(temp->coeff);

            if (temp->exp == 0)
            {
                printf("%d", c);
            }
            else if (temp->exp == 1)
            {
                if (c != 1)
                    printf("%d", c);

                printf("x");
            }
            else
            {
                if (c != 1)
                    printf("%d", c);

                printf("x^%d", temp->exp);
            }

            first = 0;
        }

        temp = temp->next;

    } while (temp != head);

    if (first)
        printf("0");
}

struct Node *addPolynomial(struct Node *p1, struct Node *p2)
{
    struct Node *result = NULL;
    struct Node *temp;

    if (p1 != NULL)
    {
        temp = p1;

        do
        {
            insertTerm(&result, temp->coeff, temp->exp);
            temp = temp->next;
        } while (temp != p1);
    }

    if (p2 != NULL)
    {
        temp = p2;

        do
        {
            insertTerm(&result, temp->coeff, temp->exp);
            temp = temp->next;
        } while (temp != p2);
    }

    return result;
}

void freePolynomial(struct Node *head)
{
    struct Node *temp, *nextnode;

    if (head == NULL)
        return;

    temp = head->next;

    while (temp != head)
    {
        nextnode = temp->next;
        free(temp);
        temp = nextnode;
    }

    free(head);
}

int main()
{
    struct Node *p1 = NULL;
    struct Node *p2 = NULL;
    struct Node *sum = NULL;

    printf("\nEnter First Polynomial:\n");
    p1 = createPolynomial();

    printf("\nEnter Second Polynomial:\n");
    p2 = createPolynomial();

    printf("\nFirst Polynomial: ");
    displayPolynomial(p1);

    printf("\nSecond Polynomial: ");
    displayPolynomial(p2);

    sum = addPolynomial(p1, p2);

    printf("\n\nResultant Polynomial: ");
    displayPolynomial(sum);

    printf("\n");

    freePolynomial(p1);
    freePolynomial(p2);
    freePolynomial(sum);

    return 0;
}