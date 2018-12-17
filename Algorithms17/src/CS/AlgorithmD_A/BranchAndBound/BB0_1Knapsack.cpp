#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
static void BB0_1Knapsack();
static void Initialization(int *v, int *w);
struct stItem {
    int w; int v;
    stItem(int pw, int pv) : w(pw), v(pv) {}
};
struct stNode {
    int d; int w; int v; vector<int>items; double boundV;
    stNode() : d(0), w(0), v(0) {}
    stNode(int pd, int pw, int pv) : d(pd), w(pw), v(pv) {}
};
static stNode ExtractMax();
static void SiftDown(int i);
static void SiftUp(int i);
static void InsertQ(stNode &r);
static double BoundV(const stNode& node);
static void ShowInput(int *w, int *v);
static void ShowSortedInput();
static void Output();
static int N, W, OptV;
static vector<int> OptItems;
static vector<stItem> Items;
static vector<stNode> Q;
void BB0_1KnapsackCaller(int n, int pW, int *w, int *v)
{
    N = n; W = pW;
    Initialization(w, v);
    OptV = 0;
    OptItems.clear();
    BB0_1Knapsack();
    Output();
}
static void BB0_1Knapsack()
{
    stNode q, r;
    while (!Q.empty())
    {
        q = ExtractMax();
        if (q.boundV > OptV)
        {
            r = q;
            r.d++;
            r.w += Items[r.d - 1].w;
            r.v += Items[r.d - 1].v;
            r.items.push_back(1);
            if (r.w <= W && r.v > OptV)
            {
                OptV = r.v;
                OptItems = vector<int>(r.items);
            }
            r.boundV = BoundV(r);
            if (r.boundV > OptV)
                InsertQ(stNode(r));
            r = q;
            r.d++;
            r.items.push_back(0);
            r.boundV = BoundV(r);
            if (r.boundV > OptV)
                InsertQ(stNode(r));
        }
    }
}
static stNode ExtractMax()
{
    swap(Q.front(), Q.back());
    stNode q = Q.back();
    Q.pop_back();
    if (!Q.empty())
        SiftDown(0);
    return q;
}
static void SiftDown(int i)
{
    bool done = false;
    while (!done && (i = (i << 1) + 1) < Q.size()) {
        if (i + 1 < Q.size() && Q[i + 1].boundV > Q[i].boundV)
            i++;
        int p = i - 1 >> 1;
        if (Q[p].boundV < Q[i].boundV)
            swap(Q[p], Q[i]);
        else done = true;
    }
}
static void InsertQ(stNode &r)
{
    Q.push_back(r);
    SiftUp(Q.size() - 1);
}
static void SiftUp(int i)
{
    int p;
    while (i > 0 && Q[i].boundV > Q[p = i - 1 >> 1].boundV) {
        swap(Q[i], Q[p]);
        i = p;
    }
}
static double BoundV(const stNode& node)
{
    double bv;
    if (node.w > W)
        bv = 0;
    else
    {
        bv = node.v;
        int bw = node.w;
        int i = node.d + 1;
        while (i <= N && bw + Items[i - 1].w < W)
        {
            bw += Items[i - 1].w;
            bv += Items[i - 1].v;
            i++;
        }
        if (i <= N)
            bv += (double)(W - bw) * Items[i - 1].v / Items[i - 1].w;
    }
    return bv;
}
static void Initialization(int *w, int *v)
{
    ShowInput(w, v);
    Items.clear();
    for (int i = 0; i < N; i++)
        Items.push_back(stItem(w[i], v[i]));
    sort(Items.begin(), Items.end(),
        [](stItem a, stItem b)
    { return (double)a.v / a.w > (double)b.v / b.w; });
    Q.clear();
    Q.push_back(stNode(0, 0, 0));
    Q[0].boundV = BoundV(Q[0]);
    ShowSortedInput();
}
static void ShowInput(int *w, int *v)
{
    printf("Branch bound to solve 0-1 knapsack:\n");
    printf("N: %d, W: %d\n", N, W);
    printf("Items:\n");
    printf("%3c", 'i');
    for (int i = 0; i < N; i++)
        printf("%3d", i + 1);
    printf("\n%3c", 'v');
    for (int i = 0; i < N; i++)
        printf("%3d", v[i]);
    printf("\n%3c", 'w');
    for (int i = 0; i < N; i++)
        printf("%3d", w[i]);
    printf("\n");
}
static void ShowSortedInput()
{
    printf("Sorted items:\n");
    printf("%3c", 'i');
    for (int i = 0; i < N; i++)
        printf("%3d", i + 1);
    printf("\n%3c", 'v');
    for (int i = 0; i < N; i++)
        printf("%3d", Items[i].v);
    printf("\n%3c", 'w');
    for (int i = 0; i < N; i++)
        printf("%3d", Items[i].w);
    printf("\n");
}
static void Output()
{
    printf("\nThe optimal value: %d\n", OptV);
    for (int i = OptItems.size(); i < N; i++)
        OptItems.push_back(0);
    printf("The optimal solution:\n");
    for (int i = 0; i < N; i++)
        printf("%3d", OptItems[i]);
    printf("\n\n");
}