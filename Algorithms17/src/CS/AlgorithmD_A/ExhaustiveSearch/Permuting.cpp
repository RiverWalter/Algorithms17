#include <vector>
#include <utility>
using namespace std;
void Permuting(int i);
void OutputOnePermutation();
static vector<int> x;
static int N;
void PermutingCaller(int n)
{
    N = n;
    for (int i = 0; i < n; ++i)
        x.push_back(i + 1);
    Permuting(0);
}
static void Permuting(int i)
{
    if (i < N - 1) {
        for (int j = i; j < N; ++j) {
            swap(x[i], x[j]);
            Permuting(i + 1);
            swap(x[i], x[j]);
        }
    }
    else
        OutputOnePermutation();
}
static void OutputOnePermutation()
{
    static int cnt = 0;
    printf("%03d: ", ++cnt);
    for (auto x : x)
        printf("%d", x);
    printf("\n");
}
