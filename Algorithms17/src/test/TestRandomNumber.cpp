//RandomNumberTest.cpp
#include "../../include/headers.h"

void RandRangeTest(int n, int low, int high)
{
	printf("%d��%d���%d�������\n", low, high, n);
	for (int i=0; i<n; i++)
		printf("%3d:%d\n",i+1, RandRange(low, high));
}
void RandRangeSetTest(int n)
{
	set<int> randSet;
	set<int>::iterator it, it1;
	RandRangeSet(n, 1, 10, randSet);
	printf("����[1,10]���%d�����������ڼ����У�\n", n);
	for (it = randSet.begin(); it != randSet.end(); it++)
		printf("%d ", *it);
	printf("\n");
	it = randSet.begin();
	it1 = randSet.find(*it);
	printf("%d in set: %d\n", *it, it1 != randSet.end());
	it1 = randSet.find(100);
	printf("%d in set: %d\n", 100, it1 != randSet.end());
}
void RandDblTest(int n)
{
	printf("��Χ��[0,1)���%d�������\n", n);
	for (int i=0; i<n; i++)
		printf("%3d:%lf\n",i+1, RandDbl());
}
void RandTest(int n)
{
	printf("��Χ��[0,%d]���%d�������\n", RAND_MAX, n);
	for (int i=0; i<n; i++)
		printf("%3d:%d\n",i+1, rand());
}