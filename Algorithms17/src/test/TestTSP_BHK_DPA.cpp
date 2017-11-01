#include "../../include/headers.h"
void TestTSP_BHK_DPA()
{
    int N0 = 4;
    int distMat0[] = {
        0, 3, 5, 2,
        3, 0, 9,10,
        5, 9, 0, 1,
        2,10, 1, 0 };

    int N1 = 5;
    int distMat1[] = {
        0, 3, 4, 2, 7,
        3, 0, 4, 6, 3,
        4, 4, 0, 5, 8,
        2, 6, 5, 0, 6,
        7, 3, 8, 6, 0 };

    //zh.scribd.com: Solving Traveling Salesman Problem by DP 
    //https://zh.scribd.com/doc/50049931/Final-Report-Solving-Traveling-Salesman-Problem-by-Dynamic-Programming-Approach-in-Java-Program-Aditya-Nugroho-Ht083276e
    int N2 = 4;
    int distMat2[] = {
        0,12,11, 9,
       15, 0,14,11,
        8,15, 0,18,
       16,10,17, 0 };

    int N3 = 5;
    int distMat3[] = {
        0, 10,Inf,  4, 12,
        10,  0, 15,  8,  5,
        Inf, 15,  0,  7, 30,
        4,  8,  7,  0,  6,
        12,  5, 30,  6,  0 };

    for (int i = 0; i < 1; i++)
    {
        switch (i)
        {
        case 0:
            TestTSP_BHK_DP(N0, distMat0);
            break;
        case 1:
            TestTSP_BHK_DP(N1, distMat1);
            break;
        case 2:
            TestTSP_BHK_DP(N2, distMat2);
            break;
        }
    }
}