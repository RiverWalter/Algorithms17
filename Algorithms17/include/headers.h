#pragma once
//system headers
#include <stdio.h>
#include <iostream>
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
void BubbleSort(int a[], int n);
void InsertionSort(int a[], int n);
void QuickSort(int a[], int low, int high);
void Merge2SortedSubArrA(int a[], int p, int q, int r);
void MergeSort(int a[], int low, int high);
void MakeHeapA(int H[], int n);
void HeapSort(int H[], int n);

//classical
int LinearSearch(int a[], int n, int x);
int BinarySearch(int a[], int n, int x);
int EuclidGCD(int a, int b);

//Exhaustive search
bool PrimalTestTrialDiv(int n);
void ESSubsetTree(int n);
void TestES0_1Knapsack(int aN, int aW, int *wa, int *va);
void TestESTSP(int n, int *aMat);
void TestESTSP_UT(int n, int *aMat);
void TestESTSP_UT_F(int n, int *aMat);
void TestESTSP_UT_N(int n, char *cityNames[], int *aMat);
void TestESTSP_UT_NP(int n, char *cityNames[], int *aMat);
void TestESTSP_UT_TH(int n, char *cityNames[], int *aMat);

//Dynamic programming
void TestTSP_BHK_DPv(int n, int *aMat);
void TestTSP_BHK_DP(int n, int *aMat);
void TestTSP_BHK_DP_N(int n, char *cityNames[], int *aMat);