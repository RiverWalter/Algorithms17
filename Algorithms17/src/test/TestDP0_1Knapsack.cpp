#include "../../include/headers.h"
void TestDP0_1Knapsack()
{
    //http://www.es.ele.tue.nl/education/5MC10/Solutions/knapsack.pdf
    //ÍõÏþ¶«£¬P78£»ÍõÇï·Ò£¬P101
    //https://en.wikipedia.org/wiki/Knapsack_problem
    //ÍõÏþ¶«£¬P133
    //ÉòÐ¢¾û£¬P268
    //Ö£×Úºº£¬P164
    vector<int> N = { 4, 5, 5, 4, 4, 7 };
    vector<int> W = { 10, 10, 15, 7, 8, 15 };
    vector<vector<int>> w = {
        { 5, 4, 6, 3 },
        { 2, 2, 6, 5, 4 },
        { 12, 2, 1, 4, 1 },
        { 3, 5, 2, 1 },
        { 5, 4, 3, 2 },
        { 2, 3, 5, 7, 1, 4, 1 }
    };
    vector<vector<int>> v = {
        { 10, 40, 30, 50 },
        { 6, 3, 5, 4, 6 },
        { 4, 2, 1, 10, 2 },
        { 9, 10, 7, 4 },
        { 15, 10, 6, 2 },
        { 10, 5, 15, 7, 6, 18, 3 }
    };

    for (int i = 0; i < 6; i++)
    {
        DP0_1KnapsackCaller(N[i], W[i], &w[i][0], &v[i][0]);
    }
}