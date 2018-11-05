#include <vector>
using namespace std;
static void BKnQueens(int row);
static void BKnQueensOne(int row);
static bool CanPlace(int row, int col);
static void Output();
static vector<int> x;
static int N;
static bool Done;
static int No;
void BKnQueensCaller(int n)
{
    N = n;
    x.resize(N + 1);
    No = 0;
    BKnQueens(1);
    //No = -1;
    //Done = false;
    //BKnQueensOne(1);
    //Output();
}
static void BKnQueens(int row)
{
    for (int col = 1; col <= N; col++)
        if (CanPlace(row, col))
        {
            x[row] = col;
            if (row == N)
                Output();
            else
                BKnQueens(row + 1);
        }
}
static void BKnQueensOne(int row)
{
    for (int col = 1; !Done && col <= N; col++)
        if (CanPlace(row, col))
        {
            x[row] = col;
            if (row == N)
                Done = true;
            else
                BKnQueensOne(row + 1);
        }
}
static bool CanPlace(int row, int col)
{
    for (int rowi = 1; rowi < row; rowi++)
        if (x[rowi] == col || 
            abs(x[rowi] - col) == abs(rowi - row))
            return false;
    return true;
}
static void Output()
{
    printf("Placement for %d-Queens: \n", N);
    if (No >= 0)
        printf("No: %d\n", ++No);
    for (int row = 1; row <= N; row++)
        printf("(%d,%d)\n", row, x[row]);
}

