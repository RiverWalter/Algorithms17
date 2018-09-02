#include <stdio.h>
#include <vector>
using namespace std;

void Check0_1KSOptimal();
static vector<int> x;
static vector<int> w;
static vector<int> v;
static vector<int> xo;
static int N, W, Vo;

void ES0_1Knapsack(int n)
{
    if (n > 0) {
        x.push_back(0);
        ES0_1Knapsack(n - 1);
        x.pop_back();
        x.push_back(1);
        ES0_1Knapsack(n - 1);
        x.pop_back();
    }
    else
        Check0_1KSOptimal();
}
void Check0_1KSOptimal()
{
    static int cnt = 0;
    printf("%4d: ", cnt++);
    int wt = 0, vt = 0;
    for (int i = 0; i < N; i++)
    {
        printf("%3d", x[i]);
        wt += x[i] * w[i];
        vt += x[i] * v[i];
    }
    if (wt <= W && vt > Vo)
    {
        Vo = vt;
        xo = x;
    }
    printf(" %4d %4d %5d\n", wt, vt, Vo);
}
void TestES0_1Knapsack(int aN, int aW, 
    int *wa, int *va)
{
    N = aN;
    W = aW;
    Vo = 0;
    x.clear();
    w.clear();
    v.clear();
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

    printf("The exhaustive search process:\n");
    printf("  No  ");
    for (int i = 0; i < N; i++)
        printf("%3d", i);
    printf("   Wt   Vt  OptV\n");
    ES0_1Knapsack(N);

    printf("The optimal solution:\n");
    printf("i");
    for (int i = 0; i < N; i++)
        printf("%3d", i);
    printf("\n");
    printf("x");
    int Wo = 0;
    for (int i = 0; i < N; i++)
    {
        Wo += xo[i] * w[i];
        printf("%3d", xo[i]);
    }
    printf("\n");
    printf("Optimal Weight: %d\n", Wo);
    printf("Optimal Value: %d\n\n", Vo);
}