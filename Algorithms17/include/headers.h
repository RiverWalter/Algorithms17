#pragma once
//system headers
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

//#define Inf SHRT_MAX
#define Inf INT_MAX

#include <list>
#include <set>

//time_t time(time_t * _Time)
/*
此函数会返回从公元1970年1月1日的UTC时间,即从0时0分0秒算起到现在所经过的秒数。
如果_Time为非空指针，此函数将返回值存到_Time指针所指的内存。
返回值：成功则返回秒数，失败则返回((time_t)-1)值，错误原因存于errno中。
*/
#include <time.h>
#include <sys\timeb.h>

//初始化随机数发生器，即设置种子：
//void srand(unsigned int _Seed);
//返回0到RAND_MAX (32767)之间的随机数：
//int rand(void);
#include <stdlib.h>

#include "randomnumber.h"

//handling log
extern FILE *logFP;
void SetLogFile(const char *tag);

//utilities
void Print1DArr(int a[], int n, bool printAll = true);
void Print1DArr(char a[], int n);
//打印2D距离矩阵
void PrintDistData(int a[], int n);
//打印2D距离矩阵到文件
void PrintDistData_F(int a[], int n);
//打印2D距离矩阵(上三角)
void PrintDistData_UT(int a[], int n);
//打印2D距离矩阵到文件(上三角)
void PrintDistData_UT_F(int a[], int n, int *cities = NULL);
void ConfigConsole();
void GetDateTime(char *str);

//sorting
void SelectionSort(int a[], int n);
void BubbleSort(int a[], int n);
void InsertionSort(int a[], int n);
void QuickSort(int a[], int low, int high);
void TwoWayMerge(int a[], int p, int q, int r);
void MergeSort(int a[], int low, int high);
void MaxHeapify(int H[], int n);
void HeapSort(int H[], int n);

//classical
int LinearSearch(int a[], int n, int x);
int BinarySearch(int a[], int n, int x);
int BinarySearchR(int a[], int low, int high, int x);
int EuclidGCD(int a, int b);
int EuclidGCDR(int a, int b);
void Shuffle(int a[], int n);

//Exhaustive search
bool PrimalTestTrialDiv(int n);
void ESSubsetTree(int n);
void Subsetting(int n);
void EnumSubsetsT(int n);
void TestES0_1Knapsack(int aN, int aW, int *wa, int *va);
void TestESTSP(int n, int *aMat);
void TestESTSP_UT(int n, int *aMat);
void TestESTSP_UT_F(int n, int *aMat);
void TestESTSP_UT_N(int n, char *cityNames[], int *aMat);
void TestESTSP_UT_NP(int n, char *cityNames[], int *aMat);
void TestESTSP_UT_TH(int n, char *cityNames[], int *aMat);
void ESTSP18Caller(int n, vector<vector<int>> aMat);
void PermutingCaller(int n);
void PermutingCallerA(int n);
void PermutingHeapCaller(int n);
void PermutingSJT(int n);
void DFSMCaller(int n, vector<vector<int>> &g);
void BFSMCaller(int n, vector<vector<int>> &g);

//Graph
void KruskalMSTCaller(int n, vector<vector<int>> &w, int v0);
void PrimMSTCaller(int n, vector<vector<int>> &w, int v0);
void DijkstraSSSPCaller(int n, vector<vector<int>> &w, int v0);
void DFSCaller(int n, vector<vector<int>> &g, int v0);
void BFSCaller(int n, vector<vector<int>> &g, int v0);

//Divide and conquer
void ChessBoardTilingTest(int n);

//Dynamic programming
void DP0_1KnapsackCaller(int n, int W, int *w, int *v);
void LSEditDistCaller(const string &x, const string &y);
void TestTSP_BHK_DPv(int n, int *aMat);
void TestTSP_BHK_DP(int n, int *aMat);
void TestTSP_BHK_DP_N(int n, char *cityNames[], int *aMat);

//Backtracking
void BTnQueensCaller(int n);
void BKnQueensCaller(int n);
void BTKColoringCaller(int n, vector<vector<int>> &adjM, int k);

//Error Control
void TestParityCheck(int r, int c, int even);

//RSA
tuple<int, int, int>ExtEucGCD(int a, int b);

//Branch and Bound
void BB0_1KnapsackCaller(int n, int pW, int *w, int *v);
