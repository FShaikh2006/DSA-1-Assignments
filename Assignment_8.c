#include <stdio.h>
#define SIZE 20

struct Job
{
    int job_id;
    char job_title[20];
};

struct Job queue[SIZE];
int front = -1, rear = -1;

int isFull()
{
    if(rear == SIZE -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty()
{
    if(front == rear){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue()
{
    if (isFull() == 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    rear++;

    printf("Enter job ID: ");
    scanf("%d", &queue[rear].job_id);

    printf("Enter job title: ");
    scanf(" %19[^\n]", queue[rear].job_title);

    printf("Job added successfully\n");
}

void dequeue()
{
    if (isEmpty() == 1)
    {
        printf("Queue Underflow\n");
        return;
    }

    front++;

    printf("Deleted Job ID: %d\n", queue[front].job_id);
    printf("Deleted Job Title: %s\n", queue[front].job_title);
}

void display()
{
    if (front == rear)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("\nJobs in Queue:\n");

    for (int i = front + 1; i <= rear; i++)
    {
        printf("Job ID: %d\n", queue[i].job_id);
        printf("Job Title: %s\n", queue[i].job_title);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}

