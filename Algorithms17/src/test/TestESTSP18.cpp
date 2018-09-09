#include "../../include/headers.h"
void TestESTSP18()
{
    vector<int> n = { 5, 5 };
    vector<vector<vector<int>>> D = { 
        {
            { 0, 3, 4, 2, 7 },
            { 3, 0, 4, 6, 3 },
            { 4, 4, 0, 5, 8 },
            { 2, 6, 5, 0, 6 },
            { 7, 3, 8, 6, 0 },
        },
        {
            {       0, 10,INT_MAX,  4, 12 },
            {      10,  0,     15,  8,  5 },
            { INT_MAX, 15,      0,  7, 30 },
            {       4,  8,      7,  0,  6 },
            {      12,  5,     30,  6,  0 },
        },
    };
    for (int i = 0; i < n.size(); i++)
        ESTSP18Caller(n[i], D[i]);
}