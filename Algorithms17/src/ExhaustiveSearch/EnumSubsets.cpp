#include <iostream>
#include <vector>
using namespace std;
void OutputOneSubsetBinary();
void OutputOneSubset();
static vector<int> s;
void EnumSubsets(int n) 
{
    if (n > 0) {
        s.push_back(0);
        EnumSubsets(n - 1);
        s.pop_back();
        s.push_back(1);
        EnumSubsets(n - 1);
        s.pop_back();
    } else {
        OutputOneSubsetBinary();
        OutputOneSubset();
        printf("\n");
    }
}
void OutputOneSubsetBinary()
{
    static int cnt = 0;
    printf("%03d: ", ++cnt);
    for (int i = s.size() - 1; i >= 0; i--)
        printf("%d", s[i]);
}
void OutputOneSubset()
{
    printf("; {");
    int k = 0;
    for (int i = s.size() - 1; i >=0; i--) {
        if (s[i] == 1) {
            if (k > 0)
                printf(",");
            printf("%d", s.size() - i);
            k++;
        }
    }
    printf("}");
}