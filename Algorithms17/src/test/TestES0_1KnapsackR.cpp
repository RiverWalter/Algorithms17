#include "../../include/headers.h"
void TestES0_1KnapsackR(int n, int wRange, int vRange)
{
    int *w = new int[n];
    int *v = new int[n];
    RandRangeArr(n, 1, wRange, w);
    RandRangeArr(n, 1, vRange, v);
    int Wt = 0;
    for (int i = 0; i < n; i++)
        Wt += w[i];
    int Wlow = Wt / 4;
    if (Wlow == 0)
        Wlow = 1;
    int Whigh = Wt * 4 / 5;
    if (Whigh < Wlow)
        Whigh = Wlow;
    int W = RandRange(Wlow, Whigh);
    TestES0_1Knapsack(n, W, w, v);
    delete w;
    delete v;
}