#include "../../../include/headers.h"
void TestDijkstraSSSP(int v0 = 0)
{
    int n[] = { 6, 9, 8 };
    vector<vector<vector<int>>> w = {
        // Dijkstra's algorithm on Wikipedia
        {
            { 0, 7, 9, INT_MAX, INT_MAX, 14 },
            { 7, 0, 10, 15, INT_MAX, INT_MAX },
            { 9, 10, 0, 11, INT_MAX, 2 },
            { INT_MAX, 15, 11, 0, 6, INT_MAX },
            { INT_MAX, INT_MAX, INT_MAX, 6, 0, 9 },
            { 14, INT_MAX, 2, INT_MAX, 9, 0 },
        },
    };
    for (int i = 0; i < 1; i++)
        DijkstraSSSPCaller(n[i], w[i], v0);
}