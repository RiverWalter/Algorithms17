#pragma once
#include "headers.h"

//Test random number utilities functions
void RandRangeTest(int n, int low, int high);
void RandRangeSetTest(int n);
void RandDblTest(int n);
void RandTest(int n);

//sorting tests
void SelectionSortTest(int n);
void BubbleSortTest(int n);
void InsertionSortTest(int n);
void QuickSortTest(int n);
void TwoWayMergeTest(int m, int n);
void MergeSortTest(int n);
void MaxHeapifyTest(int n);
void HeapSortTest(int n);

//classical
void LinearSearchTest(int n);
void BinarySearchTest(int n);
void BinarySearchRTest(int n);
void TestShuffle(int n);

//EuclidGCD
void TestEuclidGCDR(int a, int b);
void TestEuclidGCDStepsR(int a, int b);
void TestEuclidGCDTypicalCasesR(bool showSteps = false);

void TestEuclidGCD(int a, int b);
void TestEuclidGCDSteps(int a, int b);
void TestEuclidGCDTypicalCases(bool showSteps = false);

//Primality test
void TestPrimalTestTrialDiv(int n);
void TestPrimalTestTrialDivDetail(int n);
void TestPrimalTestTrialDivRange(int m, bool detail = false);

//Exhaustive search
void TestESTSP18SD(int n);
void TestESTSP18();
//t: D for DFS, B for BFS
void TestES0_1KnapsackA();
void TestES0_1KnapsackR(int n = 6, int wRange = 20, int vRange = 20);
void ESPermutationTreeI(int n);
void ESPermutationTreeJ(int n);
void ESPermutationTreeT(int n);
void TestESTSPA();
void TestESTSP_UTA();
void TestESTSP_UT_FA();
void TestESTSP_UT_SD(int low, int high);
void TestESTSP_UT_SD_P(int low, int high);
void TestESTSP_UT_SD_TH(int low, int high);

//Dynamic programming
void TestDP0_1Knapsack();
void TestLSEditDist();
void TestTSP_BHK_DPvA();
void TestTSP_BHK_DPA();
void TestTSP_BHK_DP_N_SD(int N);

//RSA
void TestExtEucGCD();

//Graph
void TestKruskalMST(int v0 = 0);
void TestPrimMST(int v0 = 0);
void TestDijkstraSSSP(int v0 = 0);
void TestDFS_BFS(char t);
void TestDFSM_BFSM(char t);

//Branch and Bound
void TestBB0_1Knapsack();

//Backtracking
void TestKColoring(int K = 3);