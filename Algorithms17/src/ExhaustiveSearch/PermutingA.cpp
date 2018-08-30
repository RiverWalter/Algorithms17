#include <vector>
#include <utility>
using namespace std;
void PermutingWorkerA(int i, int n);
static vector<int> s;
static int cnt1 = 0, cnt2 = 0, cnt3 = 0;
static int cnta[5], cntb[5];
void PermutingCallerA(int n)
{
    cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < n; ++i) {
        cnta[i] = 0;
        cntb[i] = 0;
    }
    for (int i = 0; i < n; ++i)
        s.push_back(i + 1);
    PermutingWorkerA(0, n);
    printf("n: %d\n", n);
    printf("cnt1: %d, cnt2: %d, cnt3: %d\n", cnt1, cnt2, cnt3);
    printf("cnta: \n");
    for (int i = 0; i < n; i++)
        printf("i=%d, cnt=%d; ", i, cnta[i]);
    printf("\n");
    printf("cntb: \n");
    for (int i = 0; i < n; i++)
        printf("i=%d, cnt=%d; ", i, cntb[i]);
    printf("\n");
    printf("\n");
}
void PermutingWorkerA(int i, int n)
{
    if (i < n - 1) {
        cnta[i]++;
        for (int j = i; j < n; ++j) {
            swap(s[i], s[j]);
            cnt1++;
            PermutingWorkerA(i + 1, n);
            swap(s[i], s[j]);
            cnt2++;
        }
    }
    else {
        cntb[i]++;
        cnt3++;
        /*
        for (auto x : s)
            printf("%d", x);
        printf("\n");
        cnt3++;
        return;
        */
    }
}
