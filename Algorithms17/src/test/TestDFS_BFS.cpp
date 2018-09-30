#include "../../include/headers.h"
#include <vector>
//t: D for DFS, B for BFS
void TestDFS_BFS(char t)
{
    int n[] = { 6, 9, 8 };
    vector<vector<vector<int>>> g = { 
        // Dijkstra's algorithm on Wikipedia
        {
            { 1, 2, 5 },
            { 0, 2, 3 },
            { 0, 1, 3, 5 },
            { 1, 2, 4 },
            { 3, 5 },
            { 0, 2, 4 },
        },
        //ZH-Zheng's graph traversal demo
        {
            { 1, 2, 3 },
            { 0, 4, 5 },
            { 0, 3 },
            { 0, 2, 4 },
            { 1, 3, 5, 7 },
            { 1, 4, 8 },
            { 7, 8 },
            { 4, 6, 8 },
            { 5, 6, 7 },
        },
        //XJ-Shen's exercise-2
        {
            { 1, 2, 4 },
            { 0, 5, 7 },
            { 0, 3, 5 },
            { 2, 4, 7 },
            { 0, 3, 6 },
            { 1, 2, 6 },
            { 4, 5, 7 },
            { 1, 3, 6 },
        },
    };
    for (int i = 0; i < 3; i++)
        if (t == 'D')
            DFSCaller(n[i], g[i], 3);
        else
            BFSCaller(n[i], g[i], 3);
}