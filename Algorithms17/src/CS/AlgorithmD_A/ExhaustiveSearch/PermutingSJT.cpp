#include <utility>
using namespace std;

int GetBiggestMobile(int n);
void Reverse(int m, int n);
void Initialize(int n);
void OutputOnePerm(int n);

int a[10], d[10], cnt = 0;

void PermutingSJT(int n)
{
    Initialize(n);
    OutputOnePerm(n);
    while (int p = GetBiggestMobile(n)) {
        //printf(" p = %d\n", p);
        int m = a[p];
        swap(a[p], a[p + d[p]]);
        swap(d[p], d[p + d[p]]);
        Reverse(m, n);
        OutputOnePerm(n);
    }
}

static int GetBiggestMobile(int n)
{
    int p = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] > a[i + d[i]])
            p = (p && a[i] < a[p]) ? p : i;
    return p;
}

static void Reverse(int m, int n)
{
    for (int i = 1; i <= n; i++)
        if (a[i] > m)
            d[i] *= -1;
}

static void Initialize(int n)
{
    for (int i = 1; i <= n; i++) {
        a[i] = i;
        d[i] = -1;
    }
    a[0] = n + 1;
    a[n + 1] = n + 1;
}
static void OutputOnePerm(int n)
{
    printf("%3d:", ++cnt);
    for (int i = 1; i <= n; i++)
        printf("%2d", a[i]);
    printf("\n");
    printf("\n%4c", ' ');
    for (int i = 1; i <= n; i++)
        printf("%+2d", d[i]);
    printf("\n");
}