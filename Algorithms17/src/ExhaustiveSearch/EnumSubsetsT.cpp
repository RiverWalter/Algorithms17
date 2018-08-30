#include <iostream>
#include <vector>
using namespace std;
void OutputOneSubsetBinaryT();
void OutputOneSubsetT();
void OutputT(int mark, int n);
static vector<int> s;
void EnumSubsetsT(int n) 
{
    if (n > 0) {
        s.push_back(0);
        OutputT(11, n);
        EnumSubsetsT(n - 1);
        OutputT(21, n);
        s.pop_back();
        s.push_back(1);
        OutputT(31, n);
        EnumSubsetsT(n - 1);
        OutputT(41, n);
        s.pop_back();
        OutputT(51, n);
    } else {
        OutputOneSubsetBinaryT();
        OutputOneSubsetT();
        printf("\n");
    }
}
void OutputOneSubsetBinaryT()
{
    static int cnt = 0;
    printf("%4d: ", cnt++);
    for (int i = s.size() - 1; i >= 0; i--)
        printf("%d", s[i]);
}
void OutputOneSubsetT()
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
void OutputT(int mark, int n)
{
    printf("%d:%d;", mark, n);
    for (int i = 0; i < s.size(); i++)
        printf("%d", s[i]);
    printf("\n");
}