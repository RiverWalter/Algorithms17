#include <string>
#include <vector>
#include <algorithm>
using namespace std;
static void Initialization(const string &x, const string &y);
static int GetLSEditDist(const string &x, const string &y);
static void GetLSEdits(const string &x, const string &y);
static void Output(const string &x, const string &y, int OptD);
static void OutputE(const string &x, const string &y);
static void OutputP(const string &x, const string &y);
static int m, n;
static vector<vector<int>> E;
static vector<vector<char>> P;
static string xe, ye;
void LSEditDistCaller(const string &x, const string &y)
{
    Initialization(x, y);
    int OptD = GetLSEditDist(x, y);
    GetLSEdits(x, y);
    Output(x, y, OptD);
}
static int GetLSEditDist(const string &x, const string &y)
{
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            E[i][j] = min(E[i - 1][j] + 1,
                min(E[i][j - 1] + 1,
                    E[i - 1][j - 1] + (x[i - 1] != y[j - 1])));
            if (E[i][j] == E[i - 1][j] + 1)
                P[i][j] = 'U';
            else if (E[i][j] == E[i][j - 1] + 1)
                P[i][j] = 'L';
            else if (x[i - 1] != y[j - 1])
                P[i][j] = '1';
        }
    return E[m][n];
}
static void GetLSEdits(const string &x, const string &y)
{
    int i = m, j = n;
    while (i > 0 || j > 0)
    {
        if (P[i][j] == '0' || P[i][j] == '1')
        {
            xe.insert(0, 1, x[i - 1]);
            ye.insert(0, 1, y[j - 1]);
            i--; j--;
        }
        else if (P[i][j] == 'U')
        {
            xe.insert(xe.begin(), x[i - 1]);
            ye.insert(ye.begin(), '-');
            i--;
        }
        else
        {
            xe.insert(xe.begin(), '-');
            ye.insert(ye.begin(), y[j - 1]);
            j--;
        }
    }
}
static void Initialization(const string &x, const string &y)
{
    m = x.length();
    n = y.length();
    E.clear();
    E.resize(m + 1, vector<int>(n + 1, 0));
    P.clear();
    P.resize(m + 1, vector<char>(n + 1, '0'));
    for (int j = 1; j <= n; j++)
    {
        E[0][j] = j;
        P[0][j] = 'L';
    }
    for (int i = 1; i <= m; i++)
    {
        E[i][0] = i;
        P[i][0] = 'U';
    }
    xe.clear();
    ye.clear();
}
static void Output(const string &x, const string &y, int OptD)
{
    printf("Levenshtein distance: \n");
    printf("Strings: %s, %s\n\n", x.c_str(), y.c_str());
    OutputE(x, y);
    OutputP(x, y);
    printf("Distance: %d\n", OptD);
    printf("Edited strings:\n");
    for (auto c : xe)
        printf("%2c", c);
    printf("\n");
    for (auto c : ye)
        printf("%2c", c);
    printf("\n\n");
}
static void OutputE(const string &x, const string &y)
{
    printf(" E  ");
    for (int j = 0; j < n; j++)
        printf("%2c", y[j]);
    printf("\n");
    for (int i = 0; i <= m; i++)
    {
        if (i == 0)
            printf("  ");
        else
            printf("%2c", x[i - 1]);
        for (int j = 0; j <= n; j++)
        {
            printf("%2d", E[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
static void OutputP(const string &x, const string &y)
{
    printf(" P  ");
    for (int j = 0; j < n; j++)
        printf("%2c", y[j]);
    printf("\n");
    for (int i = 0; i <= m; i++)
    {
        if (i == 0)
            printf("  ");
        else
            printf("%2c", x[i - 1]);
        for (int j = 0; j <= n; j++)
        {
            printf("%2c", P[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
