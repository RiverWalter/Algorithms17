//Pure language tests
#pragma warning(disable:4996)
#include "../../include/headers.h"
#include <sys\timeb.h>
#include <iostream>

void TestTimeb()
{
    struct timeb t_start; // , t_current;
    char timeStr[256];
    struct tm * timeinfo;
    //int t_diff;     
    for (int i = 0; i < 300; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int j = 0; j < 120; j++)
            {
                printf(".");
            }
            printf("\n");
        }
        ftime(&t_start);
        timeinfo = localtime(&t_start.time);
        strftime(timeStr, 255, "%Y.%m.%d %H:%M:%S", timeinfo);
        printf("Current time: %s.%d\n", timeStr, t_start.millitm);
    }
}
void Testfprintf()
{
    fprintf(stdout, "Hello world to stdout device!\n");
}
void test1Dto2D()
{
    int a[] = {
        11,22,
        33,44 };
    //int **b = (int **)a;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            printf("%3d", a[i * 2 + j]);
        printf("\n");
    }
}
void basicOutputTest()
{
    printf("Hello world!\n");
    auto n = 33;
    printf("n=%d\n", n);
    int a[] = { 22, 33, 44 };
    for (auto i : a)
        printf("%d\n", i);
    std::cout << "abc";
}