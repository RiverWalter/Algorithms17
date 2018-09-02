#include <vector>
using namespace std;
void OutputOneSubsetBinary();
void OutputOneSubset();
static vector<int> x;
void EnumSubsets(int n) 
{
    if (n > 0) {
        x.push_back(0);
        EnumSubsets(n - 1);
        x.pop_back();
        x.push_back(1);
        EnumSubsets(n - 1);
        x.pop_back();
    } 
    else {
        OutputOneSubsetBinary();
        OutputOneSubset();
        printf("\n");
    }
}
void OutputOneSubsetBinary()
{
    static int cnt = 0;
    printf("%03d: ", ++cnt);
    for (int i = x.size() - 1; i >= 0; i--)
        printf("%d", x[i]);
}
void OutputOneSubset()
{
    printf("; {");
    int k = 0;
    for (int i = x.size() - 1; i >=0; i--) {
        if (x[i] == 1) {
            if (k > 0)
                printf(",");
            printf("%d", x.size() - i);
            k++;
        }
    }
    printf("}");
}