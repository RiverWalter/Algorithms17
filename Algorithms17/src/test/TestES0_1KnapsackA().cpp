#include "../../include/headers.h"
void TestES0_1KnapsackA()
{
    //http://www.es.ele.tue.nl/education/5MC10/Solutions/knapsack.pdf
    int N0 = 4;
    int W0 = 10;
    int w0[] = { 5, 4, 6, 3 };
    int v0[] = { 10, 40, 30, 50 };
    
    //ÍõÏş¶«£¬P78£»ÍõÇï·Ò£¬P101
    int N1 = 5;
    int W1 = 10;
    int w1[] = { 2, 2, 6, 5, 4 };
    int v1[] = { 6, 3, 5, 4, 6 };

    //https://en.wikipedia.org/wiki/Knapsack_problem
    int N2 = 5;
    int W2 = 15;
    int w2[] = { 12, 2, 1, 4, 1 };
    int v2[] = { 4, 2, 1, 10, 2 };

    //ÍõÏş¶«£¬P133
    int N3 = 4;
    int W3 = 7;
    int w3[] = { 3, 5, 2, 1 };
    int v3[] = { 9, 10, 7, 4 };

    //ÉòĞ¢¾û£¬P268
    int N4 = 4;
    int W4 = 8;
    int w4[] = { 5, 4, 3, 2 };
    int v4[] = { 15, 10, 6, 2 };

    //Ö£×Úºº£¬P164
    int N5 = 7;
    int W5 = 15;
    int w5[] = { 2, 3, 5, 7, 1, 4, 1 };
    int v5[] = { 10, 5, 15, 7, 6, 18, 3 };

    for (int i = 0; i < 6; i++)
    {
        switch (i)
        {
            case 0: 
                TestES0_1Knapsack(N0, W0, w0, v0);
                break;
            case 1:
                TestES0_1Knapsack(N1, W1, w1, v1);
                break;
            case 2:
                TestES0_1Knapsack(N2, W2, w2, v2);
                break;
            case 3:
                TestES0_1Knapsack(N3, W3, w3, v3);
                break;
            case 4:
                TestES0_1Knapsack(N4, W4, w4, v4);
                break;
            case 5:
                TestES0_1Knapsack(N5, W5, w5, v5);
                break;
        }
    }
}