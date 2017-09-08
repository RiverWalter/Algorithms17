#include "../../include/headers.h"
//Linear Search Test
void LinearSearchTest(int n)
{
    int *a = new int[n];
    int m = 3 * n / 2;
    RandRangeArr(n, 1, m, a);
    int x = RandRange(1, m);
    int p = LinearSearch(a, n, x);
    printf("���Բ��Ҳ���:\n");
    printf("���飺\n");
    Print1DArr(a, n);
    printf("����Ԫ��: %d\n", x);
    if (p != -1)
        printf("λ��: %d\n", p);
    else
        printf("δ�ҵ���\n");
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
    printf("���������㷨����:\n");
    printf("���飺\n");
    Print1DArr(a, n);
    printf("����Ԫ��: %d\n", x);
    if (p != -1)
        printf("λ��: %d\n", p);
    else
        printf("δ�ҵ���\n");
    delete a;
}

