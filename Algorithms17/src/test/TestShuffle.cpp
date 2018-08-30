#include "../../include/headers.h"
void TestShuffle(int n)
{
    int *a = new int[n];
    printf("Testing shuffle algorithm: n = %d\n", n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    printf("Before shuffle:\n");
    Print1DArr(a, n, false);
    Shuffle(a, n);
    printf("After shuffle:\n");
    Print1DArr(a, n, false);
    delete a;
}
