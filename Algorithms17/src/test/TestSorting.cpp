#include "../../include/headers.h"
void SelectionSortTest(int n)
{
	int *a = new int[n];
	printf("测试选择排序算法：n = %d\n", n);
    int high = n <= 20 ? 99 : n * 10 - 1;
	RandRangeArr(n, 0, high, a);
    printf("排序前数组:\n");
    Print1DArr(a, n, false);
    if (n > 20 ) {
        printf("......\n");
    }
	SelectionSort(a, n);
    printf("排序后数组:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    }
    delete a;
}
void BubbleSortTest(int n)
{
    int *a = new int[n];
    printf("测试冒泡排序算法：n = %d\n", n);
    int high = n <= 20 ? 99 : n * 10 - 1;
    RandRangeArr(n, 0, high, a);
    printf("排序前数组:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    }
    BubbleSort(a, n);
    printf("排序后数组:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    }
    delete a;
}
void InsertionSortTest(int n)
{
	int *a = new int[n];
	printf("测试插入排序算法：n = %d\n", n);
    int high = n <= 20 ? 99 : n * 10 - 1;
    RandRangeArr(n, 0, high, a);
	printf("排序前数组:\n");
    Print1DArr(a, n, false);
    if (n > 20 ) {
        printf("......\n");
    }
	InsertionSort(a, n);
	printf("排序后数组:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    }
    delete a;
}
void QuickSortTest(int n)
{
	int *a = new int[n];
	printf("测试快速排序算法：n = %d\n", n);
    int high = n <= 20 ? 99 : n * 10 - 1;
    RandRangeArr(n, 0, high, a);
    printf("排序前数组:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    };
	QuickSort(a, 0, n - 1);
	printf("排序后数组:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    }
    delete a;
}
void TwoWayMergeTest(int m, int n)
{
    int k = m + n;
    int *a = new int[k];
    RandRangeArr(k, 0, 99, a);
    printf("对长度为%d和%d的有序数组进行合并。\n", m, n);
    printf("原始数组：\n");
    Print1DArr(a, k);
    BubbleSort(a, m);
    BubbleSort(a + m, n);
    printf("子数组排序：\n");
    Print1DArr(a, k);
	TwoWayMerge(a, 0, m - 1, k - 1);
    printf("合并后：\n");
    Print1DArr(a, k);
    delete a;
}
void MergeSortTest(int n)
{
    int *a = new int[n];
    printf("测试合并排序算法(递归实现)：n = %d\n", n);
    int high = n <= 20 ? 99 : n * 10 - 1;
    RandRangeArr(n, 0, high, a);
    printf("排序前数组:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    };
    MergeSort(a, 0, n - 1);
    printf("排序后数组:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    }
    delete a;
}
void MaxHeapifyTest(int n)
{
    int *a = new int[n];
    printf("测试建堆算法：\n");
    RandRangeArr(n, 0, 100, a);
    printf("建堆前数组:\n");
    Print1DArr(a, n);
	MaxHeapify(a, n);
    printf("建堆后数组:\n");
    Print1DArr(a, n);
    delete a;
}
void HeapSortTest(int n)
{
    int *a = new int[n];
    printf("测试堆排序算法：n = %d\n", n);
    int high = n <= 20 ? 99 : n * 10 - 1;
    RandRangeArr(n, 0, high, a);
    printf("排序前数组:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    };
    HeapSort(a, n);
    printf("排序后数组:\n");
    Print1DArr(a, n, false);
    if (n > 20) {
        printf("......\n");
    }
    delete a;
}

