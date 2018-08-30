#include <vector>
#include <utility>
using namespace std;
void PermutingWorker(int i);
void OutputOnePermutation();
static vector<int> s;
static int N;
void Permuting(int n)
{
    N = n;
    for (int i = 0; i < n; ++i)
        s.push_back(i + 1);
    PermutingWorker(0);
}
void PermutingWorker(int i)
{
    if (i < N - 1) {
        for (int j = i; j < N; ++j) {
            swap(s[i], s[j]);
            PermutingWorker(i + 1);
            swap(s[i], s[j]);
        }
    }
    else
        OutputOnePermutation();
}
void OutputOnePermutation()
{
    static int cnt = 0;
    printf("%03d: ", ++cnt);
    for (auto x : s)
        printf("%d", x);
    printf("\n");
}
