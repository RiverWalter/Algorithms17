#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int LSEditDist(const string &x, const string &y)
{
	int m = x.length();
	int n = y.length();
	vector<vector<int>> E;
	E.resize(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			E[i][j] = min(E[i - 1][j] + 1, 
				min(E[i][j - 1] + 1,
				E[i - 1][j - 1] + (x[i - 1] != y[j - 1])));
	return E[m][n];
}