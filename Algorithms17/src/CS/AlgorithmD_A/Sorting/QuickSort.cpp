#include <utility>
using namespace std;
int partition(int a[], int low, int high);

void QuickSort(int a[], int low, int high)
{
    if (low < high) {
        int p = partition(a, low, high);
        QuickSort(a, low, p - 1);
        QuickSort(a, p + 1, high);
    }
}
/* N. Lomuto Scheme */
static int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivot) {
            i = i + 1;
            if (i < j)
                swap(a[i], a[j]);
        }
    }
    if (a[high] < a[i + 1])
        swap(a[i + 1], a[high]);
    return i + 1;
}
