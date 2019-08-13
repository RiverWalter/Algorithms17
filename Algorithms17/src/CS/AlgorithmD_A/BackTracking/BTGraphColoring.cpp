#include <vector>
using namespace std;
static void GraphColoring(int row);
static bool CheckPlacing(int row, int col);
static void Output();
static vector<int> p;
static int N;
static bool Done;
void BTGraphColoringCaller(int n)
{
    N = n;
    p.resize(N + 1);
    Done = false;
    GraphColoring(1);
    Output();
}
static void GraphColoring(int row)
{
    for (int col = 1; !Done && col <= N; col++)
        if (CheckPlacing(row, col))
        {
            p[row] = col;
            if (row == N)
                Done = true;
            else
                GraphColoring(row + 1);
        }
}
static bool CheckPlacing(int row, int col)
{
    for (int r = 1; r < row; r++)
        if (p[r] == col || 
            abs(p[r] - col) == abs(r - row))
            return false;
    return true;
}
static void Output()
{
    printf("Placement for %d-Queens: \n", N);
    for (int row = 0; row < N; row++)
        printf("(%d,%d)\n", row, p[row]);
}

