#include <stdio.h>

void accept_MAT(int MAT[20][20], int r, int c);
void display_MAT(int MAT[20][20], int r, int c);
int Compact(int MAT[20][20], int r, int c, int compact[50][3]);
void displayCompact(int compact[50][3], int count);
int Simple_T(int compact[50][3], int simple[50][3]);
int Fast_T(int compact[50][3], int fast[50][3]);
void displayTranspose(int t[50][3], int count);

int main()
{
    int MAT[20][20];
    int compact[50][3];
    int simple[50][3];
    int fast[50][3];
    int r, c;
    int count = 0;
    int choice;

    printf("Enter number of rows and columns: ");
    scanf("%d%d", &r, &c);

    accept_MAT(MAT, r, c);

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Sparse Matrix\n");
        printf("2. Compact Form\n");
        printf("3. Simple Transpose\n");
        printf("4. Fast Transpose\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nSparse Matrix:\n");
                display_MAT(MAT, r, c);
                break;

            case 2:
                count = Compact(MAT, r, c, compact);
                printf("\nCompact Form:\n");
                displayCompact(compact, count);
                break;

            case 3:
                if(count == 0)
                    count = Compact(MAT, r, c, compact);

                Simple_T(compact, simple);
                printf("\nSimple Transpose:\n");
                displayTranspose(simple, count);
                break;

            case 4:
                if(count == 0)
                    count = Compact(MAT, r, c, compact);

                Fast_T(compact, fast);
                printf("\nFast Transpose:\n");
                displayTranspose(fast, count);
                break;

            case 5:
                printf("\nClosed\n");
                break;

            default:
                printf("\nInvalid Choice\n");
        }

    } while(choice != 5);

    return 0;
}

void accept_MAT(int MAT[20][20], int r, int c)
{
    int i, j;
    printf("Enter matrix elements:\n");

    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            scanf("%d", &MAT[i][j]);
        }
    }
}

void display_MAT(int MAT[20][20], int r, int c)
{
    int i, j;
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            printf("%d\t", MAT[i][j]);
        }
        printf("\n");
    }
}

int Compact(int MAT[20][20], int r, int c, int compact[50][3])
{
    int i, j;
    int count = 0;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(MAT[i][j] != 0)
                count++;
        }
    }

    compact[0][0] = r;
    compact[0][1] = c;
    compact[0][2] = count;

    int k = 1;
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            if(MAT[i][j] != 0){
                compact[k][0] = i;
                compact[k][1] = j;
                compact[k][2] = MAT[i][j];
                k++;
            }
        }
    }

    return count;
}

void displayCompact(int compact[50][3], int count)
{
    int i;
    printf("Row\tCol\tValue\n");
    for(i = 0; i <= count; i++){
        printf("%d\t%d\t%d\n",
               compact[i][0],
               compact[i][1],
               compact[i][2]);
    }
}

int Simple_T(int compact[50][3], int simple[50][3])
{
    int i, j, k = 1;
    int n = compact[0][2];

    simple[0][0] = compact[0][1];
    simple[0][1] = compact[0][0];
    simple[0][2] = n;

    for(i = 0; i < compact[0][1]; i++){
        for(j = 1; j <= n; j++){
            if(compact[j][1] == i){
                simple[k][0] = compact[j][1];
                simple[k][1] = compact[j][0];
                simple[k][2] = compact[j][2];
                k++;
            }
        }
    }

    return n;
}

int Fast_T(int compact[50][3], int fast[50][3])
{
    int rterms[50] = {0};
    int rpos[50];

    int r = compact[0][0];
    int c = compact[0][1];
    int num = compact[0][2];
    int i;

    fast[0][0] = c;
    fast[0][1] = r;
    fast[0][2] = num;

    for(i = 1; i <= num; i++){
        rterms[compact[i][1]]++;
    }
    rpos[0] = 1;

    for(i = 1; i < c; i++){
        rpos[i] = rpos[i - 1] + rterms[i - 1];
    }
    for(i = 1; i <= num; i++){
        int pos = rpos[compact[i][1]];

        fast[pos][0] = compact[i][1];
        fast[pos][1] = compact[i][0];
        fast[pos][2] = compact[i][2];

        rpos[compact[i][1]]++;
    }

    return num;
}

void displayTranspose(int t[50][3], int count)
{
    int i;
    printf("Row\tCol\tValue\n");
    for(i = 0; i <= count; i++){
        printf("%d\t%d\t%d\n",t[i][0],t[i][1],t[i][2]);
    }
}