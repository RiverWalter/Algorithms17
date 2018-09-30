#include "../../include/headers.h"
//Linear Search Test
void LinearSearchTest(int n)
{
    int *a = new int[n];
    int m = 3 * n / 2;
    RandRangeArr(n, 1, m, a);
    int x = RandRange(1, m);
    int p = LinearSearch(a, n, x);
    printf("线性查找测试:\n");
    printf("数组：\n");
    Print1DArr(a, n);
    printf("待查元素: %d\n", x);
    if (p != -1)
        printf("位置: %d\n", p);
    else
        printf("未找到！\n");
    delete a;
}
//Binary Search Test
void BinarySearchTest(int n)
{
    int *a = new int[n];
    int m = 3 * n / 2;
    RandRangeArr(n, 1, m, a);
    InsertionSort(a, n);
    int x = RandRange(1, m);
    int p = BinarySearch(a, n, x);
    printf("二分搜索算法测试:\n");
    printf("数组：\n");
    Print1DArr(a, n);
    printf("待查元素: %d\n", x);
    if (p != -1)
        printf("位置: %d\n", p);
    else
        printf("未找到！\n");
    delete a;
}
//Binary Search Test - Recursion
void BinarySearchRTest(int n)
{
    int *a = new int[n];
    int m = 3 * n / 2;
    RandRangeArr(n, 1, m, a);
    InsertionSort(a, n);
    int x = RandRange(1, m);
    int p = BinarySearchR(a, 0, n - 1, x);
    printf("二分搜索算法测试(递归):\n");
    printf("数组：\n");
    Print1DArr(a, n);
    printf("待查元素: %d\n", x);
    if (p != -1)
        printf("位置: %d\n", p);
    else
        printf("未找到！\n");
    delete a;
}

