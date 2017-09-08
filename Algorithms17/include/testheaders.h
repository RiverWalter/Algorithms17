#pragma once
#include "headers.h"

//Test random number utilities functions
void RandRangeTest(int n, int low, int high);
void RandRangeSetTest(int n);
void RandDblTest(int n);
void RandTest(int n);

//sorting tests
void BubbleSortTest(int n);
void InsertionSortTest(int n);
void QuickSortTest(int n);
void Merge2SortedSubArrATest(int m, int n);
void MergeSortTest(int n);
void MakeHeapATest(int n);
void HeapSortTest(int n);

//classical
void LinearSearchTest(int n);
void BinarySearchTest(int n);

//EuclidGCD
void TestEuclidGCD(int a, int b);
void TestEuclidGCDSteps(int a, int b);
void TestEuclidGCDTypicalCases(bool showSteps = false);

//Primality test
void TestPrimalTestTrialDiv(int n);
void TestPrimalTestTrialDivDetail(int n);
void TestPrimalTestTrialDivRange(int m, bool detail = false);
