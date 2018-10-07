#include "../../include/headers.h"
void SelectionSortTest(int n)
{
	int *a = new int[n];
	printf("����ѡ�������㷨��n = %d\n", n);
    int high = n <= 20 ? 99 : n * 10 - 1;
	RandRangeArr(n, 0, high, a);
    printf("����ǰ����:\n");
    Print1DArr(a, n, false);
    if (n > 20 ) {
        printf("......\n");
    }
	SelectionSort(a, n);
    printf("���������:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    }
    delete a;
}
void BubbleSortTest(int n)
{
    int *a = new int[n];
    printf("����ð�������㷨��n = %d\n", n);
    int high = n <= 20 ? 99 : n * 10 - 1;
    RandRangeArr(n, 0, high, a);
    printf("����ǰ����:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    }
    BubbleSort(a, n);
    printf("���������:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    }
    delete a;
}
void InsertionSortTest(int n)
{
	int *a = new int[n];
	printf("���Բ��������㷨��n = %d\n", n);
    int high = n <= 20 ? 99 : n * 10 - 1;
    RandRangeArr(n, 0, high, a);
	printf("����ǰ����:\n");
    Print1DArr(a, n, false);
    if (n > 20 ) {
        printf("......\n");
    }
	InsertionSort(a, n);
	printf("���������:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    }
    delete a;
}
void QuickSortTest(int n)
{
	int *a = new int[n];
	printf("���Կ��������㷨��n = %d\n", n);
    int high = n <= 20 ? 99 : n * 10 - 1;
    RandRangeArr(n, 0, high, a);
    printf("����ǰ����:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    };
	QuickSort(a, 0, n - 1);
	printf("���������:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    }
    delete a;
}
void Merge2SortedSubArrTest(int m, int n)
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
    Merge2SortedSubArr(a, 0, m - 1, k - 1);
    printf("�ϲ���\n");
    Print1DArr(a, k);
    delete a;
}
void MergeSortTest(int n)
{
    int *a = new int[n];
    printf("���Ժϲ������㷨(�ݹ�ʵ��)��n = %d\n", n);
    int high = n <= 20 ? 99 : n * 10 - 1;
    RandRangeArr(n, 0, high, a);
    printf("����ǰ����:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    };
    MergeSort(a, 0, n - 1);
    printf("���������:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    }
    delete a;
}
void MaxHeapifyTest(int n)
{
    int *a = new int[n];
    printf("���Խ����㷨��\n");
    RandRangeArr(n, 0, 100, a);
    printf("����ǰ����:\n");
    Print1DArr(a, n);
	MaxHeapify(a, n);
    printf("���Ѻ�����:\n");
    Print1DArr(a, n);
    delete a;
}
void HeapSortTest(int n)
{
    int *a = new int[n];
    printf("���Զ������㷨��n = %d\n", n);
    int high = n <= 20 ? 99 : n * 10 - 1;
    RandRangeArr(n, 0, high, a);
    printf("����ǰ����:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    };
    HeapSort(a, n);
    printf("���������:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    }
    delete a;
}

