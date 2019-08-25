#include "../../../include/headers.h"
void TestKColoring(int K = 3)
{
    int n[] = { 5, 9, 6 };
    vector<vector<vector<int>>> w = {
        {
            //Prim's Minimum Spanning Tree (MST) | Greedy Algo-5
            //https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
            {       0,      2,INT_MAX,      6,INT_MAX },
            {       2,      0,      3,      8,      5 },
            { INT_MAX,      3,      0,INT_MAX,      7 },
            {       6,      8,INT_MAX,      0,      9 },
            { INT_MAX,      5,      7,      9,      0 }
        },
        {
            //Prim's MST for Adjacency List Representation | Greedy Algo-6
            //https://www.geeksforgeeks.org/prims-mst-for-adjacency-list-representation-greedy-algo-6/
            {       0,      4,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,      8,INT_MAX },
            {       4,      0,      8,INT_MAX,INT_MAX,INT_MAX,INT_MAX,     11,INT_MAX },
            { INT_MAX,      8,      0,      7,INT_MAX,      4,INT_MAX,INT_MAX,      2 },
            { INT_MAX,INT_MAX,      7,      0,      9,     14,INT_MAX,INT_MAX,INT_MAX },
            { INT_MAX,INT_MAX,INT_MAX,      9,      0,     10,INT_MAX,INT_MAX,INT_MAX },
            { INT_MAX,INT_MAX,      4,     14,     10,      0,      2,INT_MAX,INT_MAX },
            { INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,      2,      0,      1,      6 },
            {       8,     11,INT_MAX,INT_MAX,INT_MAX,INT_MAX,      1,      0,      7 },
            { INT_MAX,INT_MAX,      2,INT_MAX,INT_MAX,INT_MAX,      6,      7,      0 },
        },
        //06U-01: Dijkstra's algorithm on Wikipedia
        {
            { 0, 1, 1, 0, 0, 1 },
            { 1, 0, 1, 1, 0, 0 },
            { 1, 1, 0, 1, 0, 2 },
            { 0, 1, 1, 0, 1, 0 },
            { 0, 0, 0, 1, 0, 1 },
            { 1, 0, 1, 0, 1, 0 },
        },
    };
    for (int i = 2; i < 3; i++)
        BTKColoringCaller(n[i], w[i], K);
}