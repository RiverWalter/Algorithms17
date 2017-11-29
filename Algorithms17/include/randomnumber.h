//randomnumber.h
#pragma once
#include <set>
using namespace std;
//high-low<RAND_MAX in the following
//Generate one random integer in the range [low, high],
int RandRange(int low, int high);
//Generate one random real number in the range [0, 1) 
double RandDbl();
//Generate random integers to array in the range [low, high]
void RandRangeArr(int n, int low, int high, int a[]);
//Generate random integers to set<int> in the range [low, high]
void RandRangeSet(int n, int low, int high, set<int> &randSet);
//Set seed for rand()
void SetRandSeed(int seed = -1);