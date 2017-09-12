#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
static vector<int> s;

void ESSubsetTree(int n) 
{
    static int cnt = 0;
    if (n > 0) {
        s.push_back(0);
        ESSubsetTree(n - 1);
        s.pop_back();
        s.push_back(1);
        ESSubsetTree(n - 1);
        s.pop_back();
    } else {
        printf("%4d: ", cnt++);
        for (auto x : s)
            printf("%d", x);
        printf("\n");
        return;
    }
}