#include "../../include/headers.h"
//��ӡ2D�������
void PrintDistData(int a[], int n)
{
    printf("�������\n");
    printf("  ");
    for (int i = 0; i < n; i++)
        printf("%4c", i + 65);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%2c", i + 65);
        for (int j = 0; j < n; j++)
            if (a[i * n + j] == Inf)
                printf(" Inf");
            else
                printf("%4d", a[i * n + j]);
        printf("\n");
    }
}

//��ӡ2D��������ļ�
void PrintDistData_F(int a[], int n)
{
    fprintf(logFP, "�������\n");
    fprintf(logFP, "  ");
    for (int i = 0; i < n; i++)
        fprintf(logFP, "%5c", i + 65);
    fprintf(logFP, "\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(logFP, "%2c", i + 65);
        for (int j = 0; j < n; j++)
            if (a[i * n + j] == Inf)
                fprintf(logFP, " Inf");
            else
                fprintf(logFP, "%5d", a[i * n + j]);
        fprintf(logFP, "\n");
    }
}

//��ӡ2D�������(������)
void PrintDistData_UT(int a[], int n)
{
    int p;
    printf("�������\n");
    printf("  ");
    for (int i = 0; i < n; i++)
        printf("%4c", i + 65);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%2c", i + 65);
        for (int j = 0; j <= i; j++)
            printf("%4c", ' ');
        for (int j = i + 1; j < n; j++)
        {
            p = i * n - (i + 1) * (i + 2) / 2 + j;
            if (a[p] == Inf)
                printf(" Inf");
            else
                printf("%4d", a[p]);
        }
        printf("\n");
    }
}
//��ӡ2D��������ļ�(������)
void PrintDistData_UT_F(int a[], int n, int *cities)
{
    int p;
    fprintf(logFP, "�������\n");
    fprintf(logFP, "  ");
    if (cities == NULL)
        for (int i = 0; i < n; i++)
            fprintf(logFP, "%5c", i + 65);
    else
        for (int i = 0; i < n; i++)
            fprintf(logFP, "%5c", cities[i] + 65);
    fprintf(logFP, "\n");
    for (int i = 0; i < n; i++)
    {
        if (cities == NULL)
            fprintf(logFP, "%2c", i + 65);
        else
            fprintf(logFP, "%2c", cities[i] + 65);
        for (int j = 0; j <= i; j++)
            fprintf(logFP, "%5c", ' ');
        for (int j = i + 1; j < n; j++)
        {
            p = i * n - (i + 1) * (i + 2) / 2 + j;
            if (a[p] == Inf)
                fprintf(logFP, " Inf");
            else
                fprintf(logFP, "%5d", a[p]);
        }
        fprintf(logFP, "\n");
    }
}


