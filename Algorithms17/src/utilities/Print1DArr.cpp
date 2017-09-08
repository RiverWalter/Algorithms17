#include "../../include/headers.h"
//打印1D整型数组
void Print1DArr(int a[], int n)
{
	for (int i = 0; i<n; i++)
		printf("%4d", a[i]);
	printf("\n");
}

//打印1D字符型数组
void Print1DArr(char a[], int n)
{
	for (int i = 0; i<n; i++)
		printf("%2c", a[i]);
	printf("\n");
}