#include <utility>
using namespace std;
void MakeHeap(int H[], int n);
void SiftDown(int H[], int n, int i); 

void HeapSort(int H[], int n)
{
    MakeHeap(H, n);
    for (int i = n - 1; i > 0; i--) {
        swap(H[0], H[i]);
        SiftDown(H, i, 0);
    }
}


static void MakeHeap(int H[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) {
        SiftDown(H, n, i);
    }
}

static void SiftDown(int H[], int n, int i)
{
    bool done = false;
    while (!done && (i = 2 * i + 1) < n) {
        if (i + 1 < n && H[i + 1] > H[i])
            i = i + 1;
        if (H[(i - 1) / 2] < H[i])
            swap(H[(i - 1) / 2], H[i]);
        else done = true;
    }
}