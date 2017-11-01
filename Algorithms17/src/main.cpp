#include "../include/testheaders.h"
#include "../include/test.h"

int main()
{
	SetRandSeed();
    ConfigConsole();
    //SetLogFile("SD_TSP_TH_15");
    SetLogFile("BHK_DP_N_SD(17)");

    char beginTimeStr[100];
    GetDateTime(beginTimeStr);
    printf("Begin time: %s\n", beginTimeStr);
    if (logFP != stdout)
        fprintf(logFP, "Begin time: %s\n", beginTimeStr);
    clock_t begin = clock();
    //***Dynamic programming
    TestTSP_BHK_DP_N_SD(17);
    //TestTSP_BHK_DPA();
    //TestTSP_BHK_DPvA();

    //***Threading
    //TestESTSP_UT_SD_TH(7, 7);

    //***Exhaustive search
    //TestESTSP_UT_SD_P(7, 7);
    //TestESTSP_UT_SD(5, 5);
    //TestESTSP_UT_FA();
    //TestESTSP_UTA();
    //TestESTSPA();
    //TestES0_1KnapsackR(10, 16, 26);
    //TestES0_1KnapsackR();
    //TestES0_1KnapsackA();
    //ESPermutationTreeT(7);
    //ESPermutationTreeJ(7);
    //ESPermutationTreeI(7);
    //ESSubsetTree(7);
    //TestPrimalTestTrialDivRange(100, true);

    //***Classical
    //BinarySearchTest(8);
    //LinearSearchTest(8);
    //TestEuclidGCDTypicalCases(true);
    //TestEuclidGCDTypicalCases();
    //TestEuclidGCDSteps(168, 180);
    //TestEuclidGCDSteps(252, 105);
    //TestEuclidGCD(252, 105);

    //***Sorting
    //HeapSortTest(8);
    //MakeHeapATest(8);
    //MergeSortTest(8);
    //Merge2SortedSubArrATest(3, 4);
	//QuickSortTest(8);
	//InsertionSortTest(8);
	//BubbleSortTest(8);

    //***Pseudo random number
    //RandRangeTest(10, 0, 100);
    //RandRangeSetTest(10);
    //RandDblTest(10);
    //RandTest(10);

    //***Pure language test
    //threading
    //TestThread2();
    //TestThread1();
    //TestHash();
    //TestTimeb();
    //Testfprintf();
    //test1Dto2D();
    //basicOutputTest();

    clock_t end = clock();

    printf("\nBegin time: %s\n", beginTimeStr);
    char endTimeStr[100];
    GetDateTime(endTimeStr);
    printf("End time: %s\n", endTimeStr);
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime spent: %.3lf seconds.\n", time_spent);

    //fprintf(logFP, "What's in your hand, is intelligence.\n");
    if (logFP != stdout)
    {
        fprintf(logFP, "\nBegin time: %s\n", beginTimeStr);
        fprintf(logFP, "End time: %s\n", endTimeStr);
        fprintf(logFP, "\nTime spent: %.3lf seconds.\n", time_spent);
        fclose(logFP);
    }

    printf("\nExecution ended, press ENTER to return.\n");
	getchar();
	return 0;
}
