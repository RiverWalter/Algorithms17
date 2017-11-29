//RandomNumber.cpp
#include "../../include/headers.h"

//high-low<RAND_MAX in the following
//Generate random integers to array in the range [low, high]
void RandRangeArr(int n, int low, int high, int a[])
{
	for (int i=0; i<n; i++)
		a[i] = RandRange(low, high);
}
//Generate random integers to set<int> in the range [low, high]
void RandRangeSet(int n, int low, int high, set<int> &randSet)
{
	while (randSet.size() != n)
		randSet.insert(RandRange(low, high));
}
//Generate one random integer in the range [low, high],
int RandRange(int low, int high)
{
	return rand() % (high - low + 1) + low;
}
//Generate one random real in the range [0, 1) 
double RandDbl()
{
	return (double)rand()/(RAND_MAX+1);
}
//Set seed for rand()
void SetRandSeed(int seed)
{
    if (seed != -1)
        srand(seed);
    else {
        time_t t;
        srand((unsigned)time(&t));
    }
}
