#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int RegNo;
    char Name[50];
    struct Student *next;
};

struct Student *head = NULL;

void addStudent()
{
    struct Student *newnode, *temp;

    newnode = (struct Student *)malloc(sizeof(struct Student));

    printf("Enter Registration Number: ");
    scanf("%d", &newnode->RegNo);

    printf("Enter Name: ");
    scanf(" %49[^\n]", newnode->Name);

    newnode->next = NULL;

    if (head == NULL)
        head = newnode;
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    printf("Student added successfully!\n");
}

void removeStudent()
{
    struct Student *temp = head, *prev = NULL;
    int reg;

    printf("Enter Registration Number to remove: ");
    scanf("%d", &reg);

    while (temp != NULL && temp->RegNo != reg)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        printf("Student not found!\n");
    else
    {
        if (prev == NULL)
            head = temp->next;
        else
            prev->next = temp->next;

        free(temp);
        printf("Student removed successfully!\n");
    }
}

void displayList()
{
    struct Student *temp = head;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("\nRegNo\tName\n");

    while (temp != NULL)
    {
        printf("%d\t%s\n", temp->RegNo, temp->Name);
        temp = temp->next;
    }
}

void countStudents()
{
    struct Student *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Total Participants: %d\n", count);
}

void sortList()
{
    struct Student *i, *j;
    int reg;
    char name[50];

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->RegNo > j->RegNo)
            {
                reg = i->RegNo;
                i->RegNo = j->RegNo;
                j->RegNo = reg;

                strcpy(name, i->Name);
                strcpy(i->Name, j->Name);
                strcpy(j->Name, name);
            }
        }
    }

    printf("List sorted successfully!\n");
}

void reverseList()
{
    struct Student *prev = NULL, *current = head, *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    printf("List reversed successfully!\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Workshop Enrollment System ---\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Display List\n");
        printf("4. Count Participants\n");
        printf("5. Sort List\n");
        printf("6. Reverse List\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                removeStudent();
                break;

            case 3:
                displayList();
                break;

            case 4:
                countStudents();
                break;

            case 5:
                sortList();
                break;

            case 6:
                reverseList();
                break;

            case 7:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}

