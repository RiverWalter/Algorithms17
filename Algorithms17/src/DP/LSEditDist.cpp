#include <string>
#include <vector>
#include <algorithm>
using namespace std;
static void Initialize(const string &x, const string &y);
static int LSEditDist(const string &x, const string &y);
static void LSGetEdits(const string &x, const string &y);
static void Output(const string &x, const string &y, int d);
static void OutputE(const string &x, const string &y);
static void OutputP(const string &x, const string &y);
static int m, n;
static vector<vector<int>> E, P;
static string xe, ye;
int LSEditDistCaller(const string &x, const string &y)
{
	Initialize(x, y);
	int d = LSEditDist(x, y);
	LSGetEdits(x, y);
	Output(x, y, d);
	return d;
}
static int LSEditDist(const string &x, const string &y)
{
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			E[i][j] = min(E[i - 1][j] + 1,
				min(E[i][j - 1] + 1,
					E[i - 1][j - 1] + (x[i - 1] != y[j - 1])));
			if (E[i][j] == E[i - 1][j] + 1)
				P[i][j] = -1;
			else if (E[i][j] == E[i][j - 1] + 1)
				P[i][j] = 1;
		}
	return E[m][n];
}
static void LSGetEdits(const string &x, const string &y)
{
	int i = m, j = n;
	while (i > 0 && j > 0)
	{
		if (P[i][j] == 0)
		{
			xe.insert(0, 1, x[i - 1]);
			ye.insert(0, 1, y[j - 1]);
			i--; j--;
		}
		else if (P[i][j] == -1)
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
	while (i > 0)
	{
		xe.insert(xe.begin(), x[i - 1]);
		ye.insert(ye.begin(), '-');
		i--;
	}
	while (j > 0)
	{
		xe.insert(xe.begin(), '-');
		ye.insert(ye.begin(), y[j - 1]);
		j--;
	}
}
static void Initialize(const string &x, const string &y)
{
	m = x.length();
	n = y.length();
	E.clear();
	E.resize(m + 1, vector<int>(n + 1, 0));
	P.clear();
	P.resize(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; i++)
		E[i][0] = i;
	for (int j = 1; j <= n; j++)
		E[0][j] = j;
	xe.clear();
	ye.clear();
}
static void Output(const string &x, const string &y, int d)
{
	printf("Levenshtein distance: \n", x.c_str(), y.c_str());
	printf("Strings: %s, %s\n\n", x.c_str(), y.c_str());
	OutputE(x, y);
	OutputP(x, y);
	printf("Distance: %d\n", d);
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
			printf("%2d", P[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
