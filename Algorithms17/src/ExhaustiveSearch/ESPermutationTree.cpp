#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
using namespace std; 
static vector<int> s;

void ESPermutationTree(int i, int n)
{
    static int cnt = 0;
    if (i < n - 1) {
        for (int j = i; j < n; ++j) {
            swap(s[i], s[j]);
            ESPermutationTree(i + 1, n);
            swap(s[i], s[j]);
        }
    } else {
        printf("%4d: ", cnt++);
        for (auto x : s)
            printf("%d", x);
        printf("\n");
        return;
    }
}

void ESPermutationTreeI(int n)
{
    for (int i = 0; i < n; ++i)
        s.push_back(i + 1);
    ESPermutationTree(0, n);
}