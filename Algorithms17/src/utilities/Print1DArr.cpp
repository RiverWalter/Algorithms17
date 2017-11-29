#include "../../include/headers.h"
//打印1D整型数组
void Print1DArr(int a[], int n, bool printAll)
{
    int m = printAll ? n : ((n <= 20) ? n : 20);
    for (int i = 0; i < m; i++) {
        printf("%d ", a[i]);
        if (i > 0 && i % 10 == 0 && i != m - 1)
            printf("\n");
    }
	printf("\n");
}

//打印1D字符型数组
void Print1DArr(char a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%2c", a[i]);
	printf("\n");
}