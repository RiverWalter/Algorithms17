#pragma once
//system headers
#include <stdio.h>
#include <iostream>
using namespace std;

#define Inf SHRT_MAX

#include <list>
#include <set>

//time_t time(time_t * _Time)
/*
�˺����᷵�شӹ�Ԫ1970��1��1�յ�UTCʱ��,����0ʱ0��0������������������������
���_TimeΪ�ǿ�ָ�룬�˺���������ֵ�浽_Timeָ����ָ���ڴ档
����ֵ���ɹ��򷵻�������ʧ���򷵻�((time_t)-1)ֵ������ԭ�����errno�С�
*/
#include <time.h>

//��ʼ������������������������ӣ�
//void srand(unsigned int _Seed);
//����0��RAND_MAX (32767)֮����������
//int rand(void);
#include <stdlib.h>

#include "randomnumber.h"

//utilities
void Print1DArr(int a[], int n);
void Print1DArr(char a[], int n);

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
bool PrimalTestTrialDiv(int n);
