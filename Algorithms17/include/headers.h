#pragma once
//system headers
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//#define Inf SHRT_MAX
#define Inf INT_MAX

#include <list>
#include <set>

//time_t time(time_t * _Time)
/*
�˺����᷵�شӹ�Ԫ1970��1��1�յ�UTCʱ��,����0ʱ0��0������������������������
���_TimeΪ�ǿ�ָ�룬�˺���������ֵ�浽_Timeָ����ָ���ڴ档
����ֵ���ɹ��򷵻�������ʧ���򷵻�((time_t)-1)ֵ������ԭ�����errno�С�
*/
#include <time.h>
#include <sys\timeb.h>

//��ʼ������������������������ӣ�
//void srand(unsigned int _Seed);
//����0��RAND_MAX (32767)֮����������
//int rand(void);
#include <stdlib.h>

#include "randomnumber.h"

//handling log
extern FILE *logFP;
void SetLogFile(const char *tag);

//utilities
void Print1DArr(int a[], int n, bool printAll = true);
void Print1DArr(char a[], int n);
//��ӡ2D�������
void PrintDistData(int a[], int n);
//��ӡ2D��������ļ�
void PrintDistData_F(int a[], int n);
//��ӡ2D�������(������)
void PrintDistData_UT(int a[], int n);
//��ӡ2D��������ļ�(������)
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
void EnumSubsets(int n);
void EnumSubsetsT(int n);
void TestES0_1Knapsack(int aN, int aW, int *wa, int *va);
void TestESTSP(int n, int *aMat);
void TestESTSP_UT(int n, int *aMat);
void TestESTSP_UT_F(int n, int *aMat);
void TestESTSP_UT_N(int n, char *cityNames[], int *aMat);
void TestESTSP_UT_NP(int n, char *cityNames[], int *aMat);
void TestESTSP_UT_TH(int n, char *cityNames[], int *aMat);
void ESTSP18Caller(int n, vector<vector<int>> aMat);
void Permuting(int n);
void PermutingCallerA(int n);
void PermutingHeapCaller(int n);
void PermutingSJT(int n);
void DFSMCaller(int n, vector<vector<int>> &g);
void BFSMCaller(int n, vector<vector<int>> &g);
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
void BKnQueensCaller(int n);

//Error Control
void TestParityCheck(int r, int c, int even);
