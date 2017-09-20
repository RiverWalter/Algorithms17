#include "../include/testheaders.h"
#include "../include/test.h"

int main()
{
	SetRandSeed();
    ConfigConsole();
    //SetLogFile();

    //***Exhaustive search
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
    //TestTimeb();
    //Testfprintf();
    //test1Dto2D();
    //basicOutputTest();

    fprintf(logFP, "What's in your hand, is intelligence.\n");
    if (logFP != stdout)
        fclose(logFP);
    printf("Execution ended, press ENTER to return.\n");
	getchar();
	return 0;
}
