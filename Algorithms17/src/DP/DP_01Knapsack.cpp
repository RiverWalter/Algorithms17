static int C[10][10], x[10];
int DP_01Knapsack(int n, int W, int w[], int v[])
{
	for (int j = 0; j <= W; j++)
		C[0][j] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= W; j++)
			if (j < w[i])
				C[i][j] = C[i - 1][j];
			else if (C[i - 1][j] > C[i - 1][j - w[i]] + v[i])
				C[i][j] = C[i - 1][j];
			else
				C[i][j] = C[i - 1][j - w[i]] + v[i];
	int j = W;
	for (int i = n; i > 0; i--)
		if (C[i][j] > C[i - 1][j])
		{	x[i] = 1;j -= w[i];	}
		else
			x[i] = 0;
	return C[n][W];
}

