#include "../../include/headers.h"
void TestBB0_1Knapsack()
{
    //http://www.es.ele.tue.nl/education/5MC10/Solutions/knapsack.pdf
    //��������P78������ң�P101
    //https://en.wikipedia.org/wiki/Knapsack_problem
    //��������P133
    //��Т����P268
    //֣�ں���P164
    vector<int> N = { 4, 4, 4, 4, 5, 5, 4, 7 };
    vector<int> W = { 11, 16, 7, 10, 10, 15, 8, 15 };
    vector<vector<int>> w = {
        { 1, 3, 3, 8 },
        { 2, 5, 10, 5 }, //Neapolitan
        { 3, 5, 2, 1 },  //�����
        { 5, 4, 6, 3 },
        { 2, 2, 6, 5, 4 },
        { 12, 2, 1, 4, 1 },
        { 3, 5, 2, 4 },
        { 2, 3, 5, 7, 1, 4, 1 }
    };
    vector<vector<int>> v = {
        { 3, 5, 4, 10 },
        { 40, 10, 50, 30 },
        { 9, 10, 7, 4 },
        { 10, 40, 30, 50 },
        { 6, 3, 5, 4, 6 },
        { 4, 2, 1, 10, 2 },
        { 6, 15, 2, 10 },
        { 10, 5, 15, 7, 6, 18, 3 }
    };
    int m = N.size();
    for (int i = 0; i < m; i++)
    {
        BB0_1KnapsackCaller(N[i], W[i], &w[i][0], &v[i][0]);
    }
}