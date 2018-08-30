#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
static vector<int> s;

static vector <int> w;
static vector <int> v;
static vector <int> x;
static int N, W, V, cnt;

void ES0_1Knapsack(int n)
{
    if (n > 0) {
        s.push_back(0);
        ES0_1Knapsack(n - 1);
        s.pop_back();
        s.push_back(1);
        ES0_1Knapsack(n - 1);
        s.pop_back();
    }
    else {
        printf("%4d: ", cnt++);
        int wt = 0, vt = 0;
        for (int i = 0; i < N; i++)
        {
            printf("%3d", s[i]);
            wt += s[i] * w[i];
            vt += s[i] * v[i];
        }
        if (wt <= W && vt > V)
        {
            V = vt;
            x = s;
        }
        printf(" %4d %4d %5d\n", wt, vt, V);
    }
}

void TestES0_1Knapsack(int aN, int aW, int *wa, int *va)
{
    N = aN;
    W = aW;
    V = 0;
    cnt = 0;
    s.clear();
    w.clear();
    v.clear();
    x.clear();
    for (int i = 0; i < N; i++)
    {
        w.push_back(wa[i]);
        v.push_back(va[i]);
    }
    printf("A 0-1 knapsack problem: \n");
    printf("N = %d W = %d\n", N, W);
    printf("i");
    for (int i = 0; i < N; i++)
        printf("%3d", i);
    printf("\n");
    printf("w");
    for (int i = 0; i < N; i++)
        printf("%3d", w[i]);
    printf("\n");
    printf("v");
    for (int i = 0; i < N; i++)
        printf("%3d", v[i]);
    printf("\n\n");

    printf("The process of exhaustive search:\n");
    printf("  No  ");
    for (int i = 0; i < N; i++)
        printf("%3d", i);
    printf("   Wt   Vt BestV\n");
    ES0_1Knapsack(N);

    printf("The optimal solution:\n");
    printf("i");
    for (int i = 0; i < N; i++)
        printf("%3d", i);
    printf("\n");
    printf("x");
    int bestW = 0;
    for (int i = 0; i < N; i++)
    {
        bestW += x[i] * w[i];
        printf("%3d", x[i]);
    }
    printf("\n");
    printf("Best Weight = %d, Best Value = %d\n\n", bestW, V);
}