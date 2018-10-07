#include <utility>
using namespace std;
void SelectionSort(int a[], int n)
{
    for (int i = n; i >= 1; i--) {
        int p = 0;
        for (int j = 1; j < i; j++)
            if (a[p] < a[j])
                p = j;
        if (p != i - 1)
            swap(a[p], a[i - 1]);
    }
}