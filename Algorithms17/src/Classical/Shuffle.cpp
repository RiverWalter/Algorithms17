#include <utility>  //swap
#include <stdlib.h> //rand
using namespace std;
int RandIntRange(int low, int high);
void Shuffle(int a[], int n)
{
    int p;
    for (int i = n - 1; i >= 1; i--)
    {
        p = RandIntRange(0, i);
        if (p != i)
            swap(a[p], a[i]);
    }
}
//Generate one random integer in the range [low, high]
int RandIntRange(int low, int high)
{
    return rand() % (high - low + 1) + low;
}