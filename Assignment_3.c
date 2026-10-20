#include <stdio.h>

struct Student
{
    int roll;
    char name[30];
    float marks;
};

void accept(struct Student s[], int n);
void display(struct Student s[], int n);

void linearSearch(struct Student s[], int n, int key);
void sentinelSearch(struct Student s[], int n, int key);
void binarySearch(struct Student s[], int n, int key);

void bubbleSort(struct Student s[], int n);
void selectionSort(struct Student s[], int n);
void insertionSort(struct Student s[], int n);
void shellSort(struct Student s[], int n);

int main()
{
    struct Student s[50];
    int n, choice, key;

    printf("Enter number of students (Max 50): ");
    scanf("%d", &n);

    accept(s, n);

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Display Records\n");
        printf("2. Linear Search\n");
        printf("3. Sentinel Search\n");
        printf("4. Binary Search\n");
        printf("5. Bubble Sort\n");
        printf("6. Selection Sort\n");
        printf("7. Insertion Sort\n");
        printf("8. Shell Sort\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                display(s, n);
                break;

            case 2:
                printf("Enter Roll Number to search: ");
                scanf("%d", &key);
                linearSearch(s, n, key);
                break;

            case 3:
                printf("Enter Roll Number to search: ");
                scanf("%d", &key);
                sentinelSearch(s, n, key);
                break;

            case 4:
                printf("Enter Roll Number to search: ");
                scanf("%d", &key);
                binarySearch(s, n, key);
                break;

            case 5:
                bubbleSort(s, n);
                printf("\nRecords sorted using Bubble Sort.\n");
                break;

            case 6:
                selectionSort(s, n);
                printf("\nRecords sorted using Selection Sort.\n");
                break;

            case 7:
                insertionSort(s, n);
                printf("\nRecords sorted using Insertion Sort.\n");
                break;

            case 8:
                shellSort(s, n);
                printf("\nRecords sorted using Shell Sort.\n");
                break;

            case 9:
                printf("\nProgram Ended.\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while(choice != 9);

    return 0;
}

void accept(struct Student s[], int n)
{
    int i;

    printf("\nEnter Student Details\n");

    for(i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Roll No : ");
        scanf("%d", &s[i].roll);

        printf("Name : ");
        scanf("%29s", s[i].name);

        printf("Marks : ");
        scanf("%f", &s[i].marks);
    }
}

void display(struct Student s[], int n)
{
    int i;

    printf("\n-----------------------------------------\n");
    printf("Roll\tName\t\tMarks\n");
    printf("-----------------------------------------\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t%.2f\n",
               s[i].roll, s[i].name, s[i].marks);
    }
}

void linearSearch(struct Student s[], int n, int key)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(s[i].roll == key)
        {
            printf("\nRecord Found\n");
            printf("Roll : %d\n", s[i].roll);
            printf("Name : %s\n", s[i].name);
            printf("Marks : %.2f\n", s[i].marks);
            return;
        }
    }

    printf("\nRecord Not Found.\n");
}

void sentinelSearch(struct Student s[], int n, int key)
{
    int i = 0;
    int last = s[n - 1].roll;

    s[n - 1].roll = key;

    while(s[i].roll != key)
    {
        i++;
    }

    s[n - 1].roll = last;

    if(i < n - 1 || last == key)
    {
        printf("\nRecord Found\n");
        printf("Roll : %d\n", s[i].roll);
        printf("Name : %s\n", s[i].name);
        printf("Marks : %.2f\n", s[i].marks);
    }
    else
    {
        printf("\nRecord Not Found.\n");
    }
}

void binarySearch(struct Student s[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(s[mid].roll == key)
        {
            printf("\nRecord Found\n");
            printf("Roll : %d\n", s[mid].roll);
            printf("Name : %s\n", s[mid].name);
            printf("Marks : %.2f\n", s[mid].marks);
            return;
        }

        if(key < s[mid].roll)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("\nRecord Not Found.\n");
}

void bubbleSort(struct Student s[], int n)
{
    int i, j;
    struct Student temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(s[j].roll > s[j + 1].roll)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void selectionSort(struct Student s[], int n)
{
    int i, j, min;
    struct Student temp;

    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(s[j].roll < s[min].roll)
            {
                min = j;
            }
        }

        temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }
}

void insertionSort(struct Student s[], int n)
{
    int i, j;
    struct Student key;

    for(i = 1; i < n; i++)
    {
        key = s[i];
        j = i - 1;

        while(j >= 0 && s[j].roll > key.roll)
        {
            s[j + 1] = s[j];
            j--;
        }

        s[j + 1] = key;
    }
}

void shellSort(struct Student s[], int n)
{
    int gap, i, j;
    struct Student temp;

    for(gap = n / 2; gap > 0; gap = gap / 2)
    {
        for(i = gap; i < n; i++)
        {
            temp = s[i];

            for(j = i; j >= gap && s[j - gap].roll > temp.roll;
                j = j - gap)
            {
                s[j] = s[j - gap];
            }

            s[j] = temp;
        }
    }
}