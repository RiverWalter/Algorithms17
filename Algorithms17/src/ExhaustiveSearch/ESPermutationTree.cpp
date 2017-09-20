#pragma warning(disable:4996)
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <time.h>
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
        printf("%7d: ", cnt++);
        for (auto x : s)
            printf("%c", x + 65);
        printf("\n");
        return;
    }
}

void ESPermutationTreeI(int n)
{
    for (int i = 0; i < n; ++i)
        s.push_back(i);
    ESPermutationTree(0, n);
}

void ESPermutationTreeJ(int n)
{
    clock_t begin = clock();
    for (int i = 0; i < n; ++i)
        s.push_back(i);
    ESPermutationTree(0, n);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent: %.3lf seconds.\n", time_spent);
}

void ESPermutationTreeT(int n)
{
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char timeStr[256];
    strftime(timeStr, 255, "%Y.%m.%d %H:%M:%S", timeinfo);
    printf("Begin time: %s\n", timeStr);

    clock_t begin = clock();
    for (int i = 0; i < n; ++i)
        s.push_back(i);
    ESPermutationTree(0, n);
    clock_t end = clock();

    printf("Begin time: %s\n", timeStr);
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timeStr, 255, "%Y.%m.%d %H:%M:%S", timeinfo);
    printf("End time: %s\n", timeStr);

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent: %.3lf seconds.\n", time_spent);
}