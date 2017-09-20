//data.cpp
//例子数据
#include "headers.h"
//p141
int **Ex5_2Matrix(int &n)
{
	int adjMat[][5] = {
		{0, 3, 3, 2, 6},
		{3, 0, 7, 3, 2},
		{3, 7, 0, 2, 5},
		{2, 3, 2, 0, 3},
		{6, 2, 5, 3, 0}};
	n = 5;
	int **M = new2DArr(n, n);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			M[i][j] = adjMat[i][j];
	return M;
}
int **Ex5_2aMatrix(int &n)
{
	int adjMat[][4] = {
		{0, 2, 5, 7},
		{2, 0, 8, 3},
		{5, 8, 0, 1},
		{7, 3, 1, 0}};
	n = 4;
	int **M = new2DArr(n, n);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			M[i][j] = adjMat[i][j];
	return M;
}
//p146
int **Ex5_3Matrix(int &n)
{
	int adjMat[][8] = {
		{  0,  1,  4,  4,Inf,Inf,Inf,Inf},
		{Inf,  0,  2,Inf,  9,Inf,Inf,Inf},
		{Inf,Inf,  0,  3,  6,  3,  4,Inf},
		{Inf,Inf,Inf,  0,Inf,Inf,  7,Inf},
		{Inf,Inf,Inf,Inf,  0,Inf,Inf,  1},
		{Inf,Inf,Inf,Inf,  2,  0,Inf,  5},
		{Inf,Inf,Inf,Inf,Inf,  1,  0,  3},
		{Inf,Inf,Inf,Inf,Inf,Inf,Inf,  0}};
	n = 8;
	int **M = new2DArr(n, n);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			M[i][j] = adjMat[i][j];
	return M;
}
//p152
int **Ex5_4Matrix(int &n)
{
	int adjMat[][6] = {
		{  0,  1,  3,  7,Inf,Inf},
		{  1,  0,  2,Inf,  9,  8},
		{  3,  2,  0,  5,Inf,  6},
		{  7,Inf,  5,  0,Inf,  4},
		{Inf,  9,Inf,Inf,  0, 10},
		{Inf,  8,  6,  4, 10,  0}};
	n = 6;
	int **M = new2DArr(n, n);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			M[i][j] = adjMat[i][j];
	return M;
}
//p170
int **Ex6_1Matrix(int &n)
{
	int adjMat[][4] = {
		{  0,  3,  6,  7},
		{  5,  0,  2,  3},
		{  6,  4,  0,  2},
		{  3,  7,  5,  0}};
	n = 4;
	int **M = new2DArr(n, n);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			M[i][j] = adjMat[i][j];
	return M;
}
//p170, 改变次序B<>D
int **Ex6_1aMatrix(int &n)
{
	int adjMat[][4] = {
		{  0,  7,  6,  3},
		{  3,  0,  5,  7},
		{  6,  2,  0,  4},
		{  5,  3,  2,  0}};
	n = 4;
	int **M = new2DArr(n, n);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			M[i][j] = adjMat[i][j];
	return M;
}
