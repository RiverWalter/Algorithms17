#include "../../include/headers.h"
void BubbleSortTest(int n)
{
	int *a = new int[n];
	printf("����ð�������㷨��\n");
	RandRangeArr(n, 0, 99, a);
	printf("����ǰ����:\n");
	Print1DArr(a, n);
	BubbleSort(a, n);
	printf("���������:\n");
	Print1DArr(a, n);
	delete a;
}
void InsertionSortTest(int n)
{
	int *a = new int[n];
	printf("���Բ��������㷨��\n");
	RandRangeArr(n, 0, 99, a);
	printf("����ǰ����:\n");
	Print1DArr(a, n);
	InsertionSort(a, n);
	printf("���������:\n");
	Print1DArr(a, n);
	delete a;
}
void QuickSortTest(int n)
{
	int *a = new int[n];
	printf("���Կ��������㷨��\n");
	RandRangeArr(n, 0, 99, a);
	printf("����ǰ����:\n");
	Print1DArr(a, n);
	QuickSort(a, 0, n - 1);
	printf("���������:\n");
	Print1DArr(a, n);
	delete a;
}
void Merge2SortedSubArrATest(int m, int n)
{
    int k = m + n;
    int *a = new int[k];
    RandRangeArr(k, 0, 99, a);
    printf("�Գ���Ϊ%d��%d������������кϲ���\n", m, n);
    printf("ԭʼ���飺\n");
    Print1DArr(a, k);
    BubbleSort(a, m);
    BubbleSort(a + m, n);
    printf("����������\n");
    Print1DArr(a, k);
    Merge2SortedSubArrA(a, 0, m - 1, k - 1);
    printf("�ϲ���\n");
    Print1DArr(a, k);
    delete a;
}
void MergeSortTest(int n)
{
    int *a = new int[n];
    printf("���Ժϲ������㷨(�ݹ�ʵ��)��\n");
    RandRangeArr(n, 0, 500, a);
    printf("����ǰ����:\n");
    Print1DArr(a, n);
    MergeSort(a, 0, n - 1);
    printf("���������:\n");
    Print1DArr(a, n);
    delete a;
}
void MakeHeapATest(int n)
{
    int *a = new int[n];
    printf("���Խ����㷨��\n");
    RandRangeArr(n, 0, 100, a);
    printf("����ǰ����:\n");
    Print1DArr(a, n);
    MakeHeapA(a, n);
    printf("���Ѻ�����:\n");
    Print1DArr(a, n);
    delete a;
}
void HeapSortTest(int n)
{
    int *a = new int[n];
    printf("���Զ������㷨��\n");
    RandRangeArr(n, 0, 100, a);
    printf("����ǰ����:\n");
    Print1DArr(a, n);
    HeapSort(a, n);
    printf("���������:\n");
    Print1DArr(a, n);
    delete a;
}

