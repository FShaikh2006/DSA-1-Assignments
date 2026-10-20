#include <stdio.h>

void accept_MAT(int MAT[20][20], int r, int c);
void display_MAT(int MAT[20][20], int r, int c);
void addition_MAT(int MAT1[20][20], int MAT2[20][20], int SUM[20][20], int r, int c);
void subtraction_MAT(int MAT1[20][20], int MAT2[20][20], int SUB[20][20], int r, int c);
void multiplication_MAT(int MAT1[20][20], int MAT2[20][20], int MUL[20][20], int r1, int r2, int c1, int c2);
void transpose_MAT(int MAT[20][20], int TR[20][20], int r, int c);

int main()
{
    int MAT1[20][20], MAT2[20][20];
    int SUM[20][20], SUB[20][20], MUL[20][20], TR[20][20];
    int r1, c1, r2, c2;

    printf("Enter Rows and Columns of Matrix 1: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter elements of Matrix 1: ");
    accept_MAT(MAT1, r1, c1);

    printf("\nMatrix 1:\n");
    display_MAT(MAT1, r1, c1);

    printf("\nEnter Rows and Columns of Matrix 2: ");
    scanf("%d%d", &r2, &c2);

    printf("Enter elements of Matrix 2: ");
    accept_MAT(MAT2, r2, c2);

    printf("\nMatrix 2:\n");
    display_MAT(MAT2, r2, c2);

    if (r1 == r2 && c1 == c2)
    {
        addition_MAT(MAT1, MAT2, SUM, r1, c1);
        subtraction_MAT(MAT1, MAT2, SUB, r1, c1);
    }
    else
    {
        printf("\nAdd and Sub not possible\n");
    }

    if (c1 == r2)
    {
        multiplication_MAT(MAT1, MAT2, MUL, r1, r2, c1, c2);
    }
    else
    {
        printf("\nMultiplication not possible. ");
    }

    transpose_MAT(MAT1, TR, r1, c1);

    return 0;
}

void accept_MAT(int MAT[20][20], int r, int c)
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &MAT[i][j]);
        }
    }
}

void display_MAT(int MAT[20][20], int r, int c)
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%d\t", MAT[i][j]);
        }
        printf("\n");
    }
}

void addition_MAT(int MAT1[20][20], int MAT2[20][20], int SUM[20][20], int r, int c)
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            SUM[i][j] = MAT1[i][j] + MAT2[i][j];
        }
    }

    printf("\nAddition of Matrices:\n");
    display_MAT(SUM, r, c);
}

void subtraction_MAT(int MAT1[20][20], int MAT2[20][20], int SUB[20][20], int r, int c)
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            SUB[i][j] = MAT1[i][j] - MAT2[i][j];
        }
    }

    printf("\nSubtraction of Matrices:\n");
    display_MAT(SUB, r, c);
}

void multiplication_MAT(int MAT1[20][20], int MAT2[20][20], int MUL[20][20], int r1, int r2, int c1, int c2)
{
    int i, j, k;

    for(i = 0; i < r2; i++)
    {
        for(j = 0; j < c2; j++)
        {
            MUL[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                MUL[i][j] += MAT1[i][k] * MAT2[k][j];
            }
        }
    }

    printf("\nMultiplication of Matrix :\n");
    display_MAT(MUL, r1, c2);
}

void transpose_MAT(int MAT[20][20], int TR[20][20], int r, int c)
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            TR[j][i] = MAT[i][j];
        }
    }

    printf("\nTranspose of Matrix 1:\n");
    display_MAT(TR, c, r);
}