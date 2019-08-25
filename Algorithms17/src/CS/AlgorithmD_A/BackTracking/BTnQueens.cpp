#include <vector>
using namespace std;
static void BTnQueens(int row);
static bool CheckPlacing(int row, int col);
static void Output();
static vector<int> Col;
static int N;
static bool Done;
void BTnQueensCaller(int n)
{
    N = n;
    Col.resize(N);
    Done = false;
    BTnQueens(0);
    Output();
}
static void BTnQueens(int row)
{
    for (int col = 0; !Done && col < N; col++)
    {
        if (CheckPlacing(row, col))
        {
            Col[row] = col;
            if (row == N - 1)
                Done = true;
            else
                BTnQueens(row + 1);
        }
    }
}
static bool CheckPlacing(int row, int col)
{
    for (int r = 0; r < row; r++)
        if (Col[r] == col || 
            abs(Col[r] - col) == abs(r - row))
            return false;
    return true;
}
static void Output()
{
    printf("Placement for %d-Queens: \n", N);
    for (int row = 0; row < N; row++)
        printf("(%d,%d)\n", row + 1, Col[row] + 1);
}

