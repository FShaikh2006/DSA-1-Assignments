#include <stdio.h>
#include <string.h>

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
   if((rear + 1) % SIZE == front){
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
        printf("Queue full\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;

    printf("Enter job ID: ");
    scanf("%d", &queue[rear].job_id);

    printf("Enter job title: ");
    scanf(" %s", queue[rear].job_title);

    printf("Job added.\n");
}

void dequeue()
{
    if (isEmpty() == 1)
    {
        printf("Queue is mpty\n");
        return;
    }

    printf("Deleted Job ID: %d\n", queue[front].job_id);
    printf("Deleted Job Title: %s\n", queue[front].job_title);

    front = (front + 1) % SIZE;
}

void display()
{
    if (isEmpty() == 1)
    {
        printf("Queue emty\n");
        return;
    }

    int i = front;

    while (1)
    {
        printf("\nJob ID: %d", queue[i].job_id);
        printf("\nJob Title: %s\n", queue[i].job_title);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Add Job\n2. Remove Job\n3. Display Queue\n4. Exit\n");
        printf("Enter choice: ");
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
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}

