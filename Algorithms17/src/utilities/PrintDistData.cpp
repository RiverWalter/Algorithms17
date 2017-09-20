#include "../../include/headers.h"
//��ӡ2D�������
void PrintDistData(int a[], int n)
{
    printf("�������\n");
    printf("  ");
    for (int i = 0; i < n; i++)
        printf("%3c", i + 65);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%2c", i + 65);
        for (int j = 0; j < n; j++)
            printf("%3d", a[i * n + j]);
        printf("\n");
    }
}

//��ӡ2D�������(������)
void PrintDistData_UT(int a[], int n)
{
    int p;
    printf("�������\n");
    printf("  ");
    for (int i = 0; i < n; i++)
        printf("%3c", i + 65);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%2c", i + 65);
        for (int j = 0; j <= i; j++)
            printf("%3c", ' ');
        for (int j = i + 1; j < n; j++)
        {
            p = i * n - (i + 1) * (i + 2) / 2 + j;
            printf("%3d", a[p]);
        }
        printf("\n");
    }
}

