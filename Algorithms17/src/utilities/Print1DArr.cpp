#include "../../include/headers.h"
//��ӡ1D��������
void Print1DArr(int a[], int n)
{
	for (int i = 0; i<n; i++)
		printf("%4d", a[i]);
	printf("\n");
}

//��ӡ1D�ַ�������
void Print1DArr(char a[], int n)
{
	for (int i = 0; i<n; i++)
		printf("%2c", a[i]);
	printf("\n");
}