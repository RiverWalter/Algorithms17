#include <vector>
#include <utility>
using namespace std;
void PermutingHeapWorker(int n);
static vector<int> s;
static int cnt, cnt1;
void PermutingHeapCaller(int n)
{
    for (int i = 0; i < n; ++i)
        s.push_back(i + 1);
    PermutingHeapWorker(n);
    printf("cnt1: %3d\n", cnt1);
}
void PermutingHeapWorker(int n)
{
    if (n > 1) {
        for (int i = 0; i < n; i++) {
            PermutingHeapWorker(n - 1);
            int j = (n % 2 == 0) ? i : 0;
            swap(s[j], s[n - 1]);
            cnt1++;
        }
    }
    else {
        printf("%3d: ", ++cnt);
        for (auto x : s)
            printf("%d", x);
        printf("\n");
    }
}
