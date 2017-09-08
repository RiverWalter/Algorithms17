#include <utility>
using namespace std; 
void SiftDownA(int H[], int n, int i);
void MakeHeapA(int H[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) {
        SiftDownA(H, n, i);
    }
}

void SiftDownA(int H[], int n, int i)
{
    bool done = false;
    while (!done && ((i = 2 * i + 1) < n)) {
        if ((i + 1 < n) && (H[i + 1] > H[i]))
            i = i + 1;
        if (H[(i - 1) / 2] < H[i])
            swap(H[(i - 1) / 2], H[i]);
        else done = true;
    }
}