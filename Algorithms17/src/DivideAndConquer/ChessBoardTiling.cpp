#include <vector>
using namespace std;
int RandIntN(int m);
void ChessBoardTilingCaller(int n, int p0, int q0);
void ChessboardTiling(int r, int c, int p, int q, int s);
void OutputChessboard(int n);
static vector<vector<int>> Chessboard;
static int TileNo = 0;
void ChessBoardTilingTest(int n)
{
    int m = 1 << n;
    int p0 = RandIntN(m);
    int q0 = RandIntN(m);
    ChessBoardTilingCaller(n, p0, q0);
}
static void ChessBoardTilingCaller(int n, int p0, int q0)
{
    int m = 1 << n;
    Chessboard.resize(m);
    for (auto &v: Chessboard)
        v.resize(m);
    Chessboard[p0][q0] = -1;
    ChessboardTiling(0, 0, p0, q0, m);
    OutputChessboard(m);
}
static void ChessboardTiling(int r, int c, int p, int q, int s)
{
    if (s == 1)
        return;
    s /= 2;
    int no = ++TileNo;
    if (p < r + s && q < c + s)
        ChessboardTiling(r, c, p, q, s);
    else {
        Chessboard[r + s - 1][c + s - 1] = no;
        ChessboardTiling(r, c, r + s - 1, c + s - 1, s);
    }
    if (p < r + s && q >= c + s)
        ChessboardTiling(r, c + s, p, q, s);
    else {
        Chessboard[r + s - 1][c + s] = no;
        ChessboardTiling(r, c + s, r + s - 1, c + s, s);
    }
    if (p >= r + s && q >= c + s)
        ChessboardTiling(r + s, c + s, p, q, s);
    else {
        Chessboard[r + s][c + s] = no;
        ChessboardTiling(r + s, c + s, r + s, c + s, s);
    }
    if (p >= r + s && q < c + s)
        ChessboardTiling(r + s, c, p, q, s);
    else {
        Chessboard[r + s][c + s - 1] = no;
        ChessboardTiling(r + s, c, r + s, c + s - 1, s);
    }
}
static void OutputChessboard(int m)
{
    printf("%3c", ' ');
    for (int i = 0; i < m; i++)
        printf("%3c", i + 65);
    printf("\n");
    for (int i = 0; i < m; i++) {
        printf("%3c", i + 65);
        for (int j = 0; j < m; j++)
            printf("%3d", Chessboard[i][j]);
        printf("\n");
    }
}
//Generate one random integer in the range [0, m)
static int RandIntN(int n)
{
    return rand() % (n);
}
